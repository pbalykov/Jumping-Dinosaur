#include "dinoView.h"

struct DinoView initDinoView(const struct DinoModel* tmpDino, SDL_Renderer* tmpRender) {
       printf("Create modul Dino View\n");
       struct DinoView mthis = {
                               dino : tmpDino,
                               textur : IMG_LoadTexture(tmpRender, "image/dino.png"),
                               render : tmpRender,
       };
       return mthis;
   }    

void drawDinoView(struct DinoView* mthis) {
    SDL_Rect sprite = {0, 0, mthis->dino->rect.width, mthis->dino->rect.height};
    if ( !mthis->dino->isJamp ) {
        sprite.x = mthis->dino->scoreSprite * mthis->dino->rect.width + 2 * (mthis->dino->scoreSprite + 1);
    }
    else {
        sprite.x = 2 * mthis->dino->rect.width + 2 * 3;
    }
    SDL_Rect square = {mthis->dino->rect.x, mthis->dino->rect.y, 
                      mthis->dino->rect.width, mthis->dino->rect.height};
    SDL_RenderCopy(mthis->render, mthis->textur, &sprite, &square); 
}

void freeDinoView(struct DinoView* mthis) {
    printf("Free modul DinoView\n");
    SDL_DestroyTexture(mthis->textur);
    mthis->dino = NULL;
    mthis->textur = NULL;
    mthis->render = NULL;
}
