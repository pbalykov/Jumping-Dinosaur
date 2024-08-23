#include "roadModel.h"

struct RoadModel initRoadModel() {
    struct RoadModel mthis = {
        xFirst : 0,
        xSecond : ROAD_WIDTH,
        yMain : ROAD_LOCATION,
    };
    return mthis;
}

void updateRoadModel(struct RoadModel* mthis) {
    mthis->xFirst -= ROAD_STEP;
    mthis->xSecond -= ROAD_STEP;
    if ( mthis->xFirst<= -ROAD_WIDTH ) {
        mthis->xFirst = mthis->xSecond;
        mthis->xSecond = ROAD_WIDTH;
    }
}
