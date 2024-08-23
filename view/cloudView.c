#include "cloudView.h"

struct CloudView initCloudView(const struct CloudModel* tmpCloud, SDL_Renderer* tmpRender) {
       printf("Create modul cloud View\n");
       struct CloudView mthis = {
                               cloud : tmpCloud,
                               textur : IMG_LoadTexture(tmpRender, "image/cloud.png"),
                               render : tmpRender,
       };
       return mthis;
   }    

void drawCloudView(struct CloudView* mthis) {
    for (int i = 0; i < mthis->cloud->lenArrCloud; i++) {
        SDL_Rect square = {mthis->cloud->arrCloud[i].x, 100, 90, 20};
        SDL_RenderCopy(mthis->render, mthis->textur, NULL, &square); 
    }
}

void freeCloudView(struct CloudView* mthis) {
    printf("Free modul CloudView\n");
    SDL_DestroyTexture(mthis->textur);
    mthis->cloud = NULL;
    mthis->textur = NULL;
    mthis->render = NULL;
}
