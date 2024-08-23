#include "cactusModel.h"

#include <stdlib.h>

struct CactusModel initCactusModel() {
    struct CactusModel mthis = {
        arrCactus: {0},
        sizeArrCactus : 0,
        distancesCactus : 300,
    };
    return mthis;
}


void updateCactusModel(struct CactusModel* mthis) {
    mthis->distancesCactus -= 5;
    for ( int i = 0; i < mthis->sizeArrCactus; i++) {
        mthis->arrCactus[i].x -= STEP_CACTI;
    }
    if (mthis->sizeArrCactus && 
            mthis->arrCactus[0].x + 46 <= 0 ) {
        
        for (int i = 1; i < mthis->sizeArrCactus; i++) {
            mthis->arrCactus[i - 1] = mthis->arrCactus[i];
        }
        mthis->sizeArrCactus--;
    }
    else if ( mthis->sizeArrCactus < MAX_SIZE_CACTI &&
           mthis->distancesCactus <= 0 ) {
       mthis->arrCactus[mthis->sizeArrCactus] = initRect(1200, 213, 46, 96) ; 
       mthis->distancesCactus = rand() % (1000 - 500 + 1) + 500;
       mthis->sizeArrCactus++;
    }
}
