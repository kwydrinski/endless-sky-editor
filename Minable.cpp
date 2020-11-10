#include "Minable.h"

void Minable::Load(const DataNode &node)
{
    // make sure the minable appears to have enough fields
    if (node.Size() < 2)
        return;

    // get the minable properties
    type = node.Token(1);
    for (const DataNode &child : node)
    {
        if (child.Token(0) == "hull" && child.Size() >= 2)
            hull = child.Value(1);
        else if (child.Token(0) == "payload" && child.Size() >= 3)
            payload = Payload(child.Token(1), child.Value(2));
        else
            unparsed.push_back(child);
    }
}

const QString &Minable::Type() const
{
    return type;
}

const uint &Minable::Hull() const
{
    return hull;
}

const Minable::Payload &Minable::Pay() const
{
    return payload;
}
