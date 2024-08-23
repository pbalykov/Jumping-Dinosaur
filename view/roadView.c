#include "roadView.h"

#include <unistd.h>

struct RoadView initRoadView(struct RoadModel* tmpRoad, SDL_Renderer* tmpRender) {
       printf("Create modul RoadView\n");
       struct RoadView mthis = {
                               road : tmpRoad,
                               textur : IMG_LoadTexture(tmpRender, "image/road.png"),
                               render : tmpRender,
       };
       if (mthis.textur == NULL) {
           SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Не удалось загрузить текстуру: %s", SDL_GetError());
           exit(0);
       }

       return mthis;
   }    

void drawRoadView(struct RoadView* mthis) {
    SDL_Rect dstrect = {mthis->road->xFirst, mthis->road->yMain,
                         2400, 30}; 
    SDL_RenderCopy(mthis->render, mthis->textur, NULL, &dstrect); 
    dstrect.x = mthis->road->xSecond;
    SDL_RenderCopy(mthis->render, mthis->textur, NULL, &dstrect); 
}

void freeRoadView(struct RoadView* mthis) {
    printf("Free modul RoadView\n");
    SDL_DestroyTexture(mthis->textur);
    mthis->road = NULL;
    mthis->textur = NULL;
    mthis->render = NULL;
}
