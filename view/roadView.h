#ifndef ROAD_VIEW_H
#define ROAD_VIEW_H

#include "../model/roadModel.h" //заментмть потом на <

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct RoadView {
    struct RoadModel* road;
    SDL_Texture* textur;
    SDL_Renderer* render; //может быть убрать 
};

struct RoadView initRoadView(struct RoadModel* tmpRoad, SDL_Renderer* tmpRender);
void drawRoadView(struct RoadView* mthis);
void freeRoadView(struct RoadView* mthis);

#endif
