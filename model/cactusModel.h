#ifndef CACTUS_MODEL_H
#define CACTUS_MODEL_H

#include "rect.h"

#define MAX_SIZE_CACTI 3
#define STEP_CACTI 5

struct CactusModel {
    struct Rect arrCactus[MAX_SIZE_CACTI];
    int sizeArrCactus;
    int distancesCactus;
};

struct CactusModel initCactusModel();
void updateCactusModel(struct CactusModel* mthis);


#endif
