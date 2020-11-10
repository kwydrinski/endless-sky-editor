#ifndef MINABLE_H
#define MINABLE_H

#include "DataNode.h"



class Minable
{
public:
    struct Payload {
        QString name;
        uint max_flotsam;
        Payload(
            const QString name,
            const uint flotsam
        ) : name(name), max_flotsam(flotsam) {}
    };
public:
    void Load(const DataNode &node);

    const QString &Type() const;
    const uint &Hull() const;
    const Payload &Pay() const;
private:
    QString type;
    uint hull;
    Payload payload;

    std::list<DataNode> unparsed;
};

#endif // MINABLE_H
