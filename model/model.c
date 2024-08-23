#include "model.h"


struct Model initModel() {
    struct Model mthis = {
        road : initRoadModel(),
        cloud : initCloudModel(),
        dino : initDinoModel(),
        cactus : initCactusModel(),
    };
    return mthis;    
}

bool updateModel(struct Model* mthis) {
    updateRoadModel(&mthis->road);
    updateCloudModel(&mthis->cloud);
    updateCactusModel(&mthis->cactus);
    if ( updateDinoModel(&mthis->dino, &mthis->cactus) ) {
        return true;
    }
    return false;
}
