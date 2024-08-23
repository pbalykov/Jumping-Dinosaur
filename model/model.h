#ifndef MODEL_H
#define MODEL_H

#include "dinoModel.h"
#include "cloudModel.h"
#include "roadModel.h"
#include "cactusModel.h"

struct Model {
    struct RoadModel road;
    struct CloudModel cloud;
    struct DinoModel dino;
    struct CactusModel cactus;
};

struct Model initModel();
bool updateModel(struct Model* mthis);

#endif
