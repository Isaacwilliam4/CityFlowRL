#ifndef CITYFLOW_ROADGRAPH_H
#define CITYFLOW_ROADGRAPH_H

#include "roadnet/trafficlight.h"
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
        std::vector<Intersection> intersections;
        std::map<std::string, Road *> roadMap;
        std::map<std::string, Intersection *> interMap;
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

        const std::vector<Intersection> &getIntersections() const { return this->intersections; }

        std::vector<Intersection> &getIntersections() { return this->intersections; }

        Road *getRoadById(const std::string &id) const {
            return roadMap.count(id) > 0 ? roadMap.at(id) : nullptr;
        }

        Intersection *getIntersectionById(const std::string &id) const {
            return interMap.count(id) > 0 ? interMap.at(id) : nullptr;
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
