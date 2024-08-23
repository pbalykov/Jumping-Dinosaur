#ifndef MODEL_ROAD_H
#define MODEL_ROAD_H

enum ROAD_CONST {
    ROAD_WIDTH = 2400,
    ROAD_HEIGHT = 30,
    ROAD_LOCATION = 280,
    ROAD_STEP = 5,
};

struct RoadModel {
    int xFirst;
    int xSecond;
    int yMain;
};


struct RoadModel initRoadModel();
void updateRoadModel(struct RoadModel* mthis);

#endif
