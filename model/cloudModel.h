#ifndef CLOUD_MODEL_H
#define CLOUD_MODEL_H

#include "rect.h"

#define LEN 3
#define X 1200 // потом в консту в фаил с ним

#define SIZE_CLOUD_W 30
#define SIZE_CLOUD_H 90

#define STEP_CLOUD 1

struct CloudModel {
    struct Rect arrCloud[LEN];
    int lenArrCloud;
    int distancesCloud;
};

struct CloudModel initCloudModel();
void updateCloudModel(struct CloudModel* mthis);


#endif
