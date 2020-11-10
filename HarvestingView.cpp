#include "HarvestingView.h"
#include "Map.h"

#include <QGraphicsLayout>
#include <QLabel>
#include <QTextStream>
#include <QVBoxLayout>

//===================
//= Private Methods =
//===================

QGroupBox *HarvestingView::makeGalaxyBox()
{
    // create the QGroupBox and its layout
    QGroupBox *galaxyBox = new QGroupBox("Galactic Summary");
    QGridLayout *galaxyBoxLayout = new QGridLayout(galaxyBox);

    // create the Minable Systems Pie Chart
    minableSystemsSeries = new QPieSeries();    // expose as private member
    minableSystemsSeries->append("Minable", 0);
    minableSystemsSeries->append("Non-Minable", 0);
    minableSystemsSeries->setLabelsVisible();
    minableSystemsSeries->setLabelsPosition(QPieSlice::LabelOutside);

    QChart *chart = new QChart();
    chart->layout()->setContentsMargins(0, 0, 0, 0);    // think margin outside chart area
    chart->setMargins(QMargins(0, 0, 0, 0));    // think padding inside chart area
    chart->setBackgroundRoundness(0);
    chart->legend()->setVisible(false);
    chart->addSeries(minableSystemsSeries);

    minableSystemsChartView = new QChartView(chart);
    minableSystemsChartView->setRenderHint(QPainter::Antialiasing);
    minableSystemsChartView->setMinimumSize(300, 200);
    minableSystemsChartView->setMaximumSize(300, 200);

    galaxyBoxLayout->addWidget(minableSystemsChartView,
                               0, 0,
                               Qt::AlignCenter);

    // apply the configured layout to the QGroupBox
    galaxyBox->setLayout(galaxyBoxLayout);

    // return the QGroupBox to the caller
    return galaxyBox;
}

//================
//= Constructors =
//================

HarvestingView::HarvestingView(Map &mapData, QWidget *parent) :
    QWidget(parent), mapData(mapData)
{
    // create control widgets and wire their signals to destination slots

    // create the root layout adding its widgets

    QGridLayout *layout = new QGridLayout(this);
    //QVBoxLayout *layout = new QVBoxLayout(this);
    //layout->addWidget(new QLabel("Coming Soon!", this));

    // create and sublayouts and add them the root layout or parent layouts

    QGroupBox *marketBox = new QGroupBox("Market Summary");
    QVBoxLayout *marketBoxLayout = new QVBoxLayout;
    marketBoxLayout->addWidget(new QLabel("Coming Soon!"));
    marketBox->setLayout(marketBoxLayout);
    layout->addWidget(marketBox, 0, 0);

    layout->addWidget(makeGalaxyBox(), 0, 2);

    QGroupBox *supplyBox = new QGroupBox("Estimated Supply");
    QVBoxLayout *supplyBoxLayout = new QVBoxLayout;
    supplyBoxLayout->addWidget(new QLabel("Coming Soon!"));
    supplyBox->setLayout(supplyBoxLayout);
    layout->addWidget(supplyBox, 2, 0);

    QGroupBox *prevalanceBox = new QGroupBox("System Prevalence");
    QVBoxLayout *prevalanceBoxlayout = new QVBoxLayout;
    prevalanceBoxlayout->addWidget(new QLabel("Coming Soon!"));
    prevalanceBox->setLayout(prevalanceBoxlayout);
    layout->addWidget(prevalanceBox, 2, 2);

    // set the root layout as the main widget's layout

    setLayout(layout);
}

//==================
//= Public Methods =
//==================

void HarvestingView::mapDataLoaded()
{
    QTextStream(stdout) << "Map data loaded." << endl;

    // analyze Systems for minables
    size_t minableSystems = 0;
    size_t nonMinableSystems = 0;
    for (auto const &system : mapData.Systems())
    {
        size_t minableSize = system.second.Minables().size();
        if (minableSize > 0)
            minableSystems++;
        else
            nonMinableSystems++;
        QTextStream(stdout) << system.first
                            << ':'
                            << system.second.Minables().size()
                            << endl;
    }
    QTextStream(stdout) << minableSystems
                        << " of "
                        << (minableSystems + nonMinableSystems)
                        << " having some mining resources."
                        << endl;


    // update widgets with map data

    minableSystemsSeries->clear();
    minableSystemsSeries->setPieSize(0.9);
    minableSystemsSeries->append(
                QString("Minable (%1)").arg(minableSystems),
                minableSystems
                );
    minableSystemsSeries->append(
                QString("Non-Minable (%1)").arg(nonMinableSystems),
                nonMinableSystems
                );
    for (QPieSlice *slice : minableSystemsSeries->slices())
    {
        QFont sliceFont = slice->labelFont();
        sliceFont.setPointSize(7);
        slice->setLabelFont(sliceFont);
    }
    minableSystemsSeries->setLabelsPosition(QPieSlice::LabelOutside);
    minableSystemsSeries->setLabelsVisible();

    minableSystemsChartView->chart()->setTitle(
                QString("Known Systems (%1)").arg(minableSystems + nonMinableSystems)
                );
    QFont titleFont = minableSystemsChartView->chart()->titleFont();
    titleFont.setBold(true);
    minableSystemsChartView->chart()->setTitleFont(titleFont);
}
