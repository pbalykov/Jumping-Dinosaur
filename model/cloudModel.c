#include "cloudModel.h"

#include <stdlib.h>

struct CloudModel initCloudModel() {
    struct CloudModel mthis = {
        arrCloud : {0},
        lenArrCloud : 0,
        distancesCloud : 0,
    };
    return mthis;
}


void updateCloudModel(struct CloudModel* mthis) {
    for ( int i = 0; i < mthis->lenArrCloud; i++) {
        mthis->arrCloud[i].x -= STEP_CLOUD;
    }
    if (mthis->lenArrCloud && mthis->arrCloud[0].x + SIZE_CLOUD_H <= 0 ) {
        for (int i = 1; i < mthis->lenArrCloud; i++) {
            mthis->arrCloud[i - 1] = mthis->arrCloud[i];
        }
        mthis->lenArrCloud--;
    }  
    else if ( mthis->lenArrCloud < LEN && 
         X - mthis->arrCloud[mthis->lenArrCloud - 1].x > mthis->distancesCloud ) {
        
        mthis->arrCloud[mthis->lenArrCloud].x = X;
        mthis->distancesCloud = rand() % (700 - 90 + 1) + 90;
        mthis->lenArrCloud++;
    } 
}
