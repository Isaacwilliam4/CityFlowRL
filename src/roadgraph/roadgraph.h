#ifndef CITYFLOW_ROADGRAPH_H
#define CITYFLOW_ROADGRAPH_H

#include "roadnet/trafficlight.h"
#include "roadnet/roadnet.h"
#include "utility/utility.h"

#include <list>
#include <map>
#include <queue>
#include <iostream>

namespace CityFlow {
    class RoadGraph;


    
    class RoadGraph {
    private:
        std::vector<Road> roads;
        std::vector<Node> nodes;
        std::map<std::string, Road *> roadMap;
        std::map<std::string, Node *> nodeMap;
        std::map<std::string, Drivable *> drivableMap;

        std::vector<Lane *> lanes;
        std::vector<LaneLink *> laneLinks;
        std::vector<Drivable *> drivables;
        Point getPoint(const Point &p1, const Point &p2, double a);

    public:
        bool loadFromJson(std::string jsonFileName);

        rapidjson::Value convertToJson(rapidjson::Document::AllocatorType &allocator);

        const std::vector<Road> &getRoads() const { return this->roads; }

        std::vector<Road> &getRoads() { return this->roads; }

        const std::vector<Node> &getNodes() const { return this->nodes; }

        std::vector<Node> &getNodes() { return this->nodes; }

        Road *getRoadById(const std::string &id) const {
            return roadMap.count(id) > 0 ? roadMap.at(id) : nullptr;
        }

        Node *getNodeById(const std::string &id) const {
            return nodeMap.count(id) > 0 ? nodeMap.at(id) : nullptr;
        }

        Drivable *getDrivableById(const std::string &id) const {
            return drivableMap.count(id) > 0 ? drivableMap.at(id) : nullptr;
        }

        const std::vector<Lane *> &getLanes() const {
            return lanes;
        }

        const std::vector<LaneLink *> &getLaneLinks() const {
            return laneLinks;
        }

        const std::vector<Drivable *> &getDrivables() const {
            return drivables;
        }

        void reset();
    };
}


#endif //CITYFLOW_ROADGRAPH_H
