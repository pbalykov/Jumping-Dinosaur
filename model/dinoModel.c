#include "dinoModel.h"

static int x = 0;
static int score = 0;

struct DinoModel initDinoModel() {
    struct DinoModel mthis = {
        rect : { 20, 213, 80, 86},
        scoreSprite : 0,
        isJamp : false,
        jamp : -19,
    }; 
    return mthis;
}

bool updateDinoModel(struct DinoModel* mthis, struct CactusModel* value) {
    if ( mthis->isJamp ) {
        mthis->rect.y += mthis->jamp;
        mthis->jamp -= -1;
        if ( mthis->rect.y >= 213 ) {
            mthis->isJamp = false;
            mthis->rect.y = 213;
            mthis->jamp = -19; 
            mthis->scoreSprite = 0;
        }
    }
    else {
       if ( x > 4 ) {
            mthis->scoreSprite = (mthis->scoreSprite + 1) % 2;
            x = 0;
        }
        x = x + 1;        
    }
    for (int i = 0; i < value->sizeArrCactus; i++) {
        if ( collision(&mthis->rect, &value->arrCactus[i]) ) {
            printf("Score %d\n", score);
            return true;
        }
    }
    score += 1;
    return false;
}

void jamp(struct DinoModel* mthis) {
    mthis->isJamp = true;
    mthis->scoreSprite = 0;

}

void down(struct DinoModel* mthis) {
    mthis->isJamp = false;
}
