#ifndef HARVESTINGVIEW_H
#define HARVESTINGVIEW_H

#include <QGroupBox>
#include <QLabel>
#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

using namespace QtCharts;

//========================
//= Forward Declarations =
//========================

class Map;

//===========
//= Classes =
//===========

class HarvestingView : public QWidget
{
    Q_OBJECT
public:
    explicit HarvestingView(Map &mapData, QWidget *parent = nullptr);


signals:

public slots:
    void mapDataLoaded();

private:
    QGroupBox *makeGalaxyBox();

private:
    Map &mapData;

    QLabel *systemCount;
    QPieSeries *minableSystemsSeries;
    QChartView *minableSystemsChartView;
};

#endif // HARVESTINGVIEW_H
