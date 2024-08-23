#ifndef DINO_H
#define DINO_H

#include "rect.h"
#include "cactusModel.h"

#include <stdbool.h>

struct DinoModel {
    struct Rect rect;
    short scoreSprite;
    bool isJamp;
    int jamp;
};

struct DinoModel initDinoModel();
bool updateDinoModel(struct DinoModel* mthis, struct CactusModel* value);

void jamp(struct DinoModel* mthis);
void down(struct DinoModel* mthis);

#endif
