#ifndef HARVESTING_H
#define HARVESTING_H

#include "DataNode.h"
#include "Minable.h"

#include <QString>
#include <list>
#include <map>


class Harvesting
{
public:
   void Load(const QString &mapFilePath);

private:
   std::map<QString, Minable> minables;
   std::map<QString, QString> outfits;
   std::list<DataNode> unparsed;
};

#endif // HARVESTING_H
