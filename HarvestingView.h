#ifndef HARVESTINGVIEW_H
#define HARVESTINGVIEW_H

#include <QWidget>

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
    explicit HarvestingView(const Map &mapData, QWidget *parent = nullptr);

public slots:

signals:

private:
    const Map &mapData;
};

#endif // HARVESTINGVIEW_H
