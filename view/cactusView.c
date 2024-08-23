#include "cactusView.h"

struct CactusView initCactusView(const struct CactusModel* tmpCactus, SDL_Renderer* tmpRender) {   
    printf("Create modul Cactus View\n");
    struct CactusView mthis = {
                           cactus : tmpCactus,
                           textur : IMG_LoadTexture(tmpRender, "image/cactus.png"),
                           render : tmpRender,
    };
    return mthis;
}    

void drawCactusView(struct CactusView* mthis) {
    for (int i = 0; i < mthis->cactus->sizeArrCactus; i++) {
        SDL_Rect square = {mthis->cactus->arrCactus[i].x, 
                           mthis->cactus->arrCactus[i].y, 
                           mthis->cactus->arrCactus[i].width, 
                           mthis->cactus->arrCactus[i].height};

        SDL_RenderCopy(mthis->render, mthis->textur, NULL, &square); 
    }
}

void freeCactusView(struct CactusView* mthis) {
    printf("Free modul Cactus View\n");
    SDL_DestroyTexture(mthis->textur);
    mthis->cactus = NULL;
    mthis->textur = NULL;
    mthis->render = NULL;
}
