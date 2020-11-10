#include "DataFile.h"
#include "Harvesting.h"



void Harvesting::Load(const QString &mapFilePath)
{
    // reconstruct object
    *this = Harvesting();

    // locate and load the Harvesting file
    QString dataDirectory = mapFilePath.left(mapFilePath.lastIndexOf('/'));
    QString harvestingFilePath = dataDirectory + "/harvesting.txt";
    DataFile harvestingData(harvestingFilePath);

    // process the nodes from the Harvesting file
    for (const DataNode &node : harvestingData)
    {
        if (node.Token(0) == "minable" && node.Size() >= 2)
            // catalog minable
            minables[node.Token(1)].Load(node);
        else if (node.Token(0) == "outfit" && node.Size() >= 2)
            // catalog outfit
            ;
    }
}
