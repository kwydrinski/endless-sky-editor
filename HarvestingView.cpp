#include "HarvestingView.h"

#include <QLabel>
#include <QVBoxLayout>

HarvestingView::HarvestingView(const Map &mapData, QWidget *parent) :
    QWidget(parent), mapData(mapData)
{
    // create control widgets and wire their signals to destination slots

    // create the root layout adding its widgets

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Coming Soon!", this));

    // create and sublayouts and add them the root layout or parent layouts

    // set the root layout as the main widget's layout

    setLayout(layout);
}
