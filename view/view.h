#ifndef VIEW_H
#define VIEW_H

#include "dinoView.h"
#include "cloudView.h"
#include "roadView.h"
#include "cactusView.h"

#include "../model/model.h" // заментть потом на <

#include <stdbool.h>

#include <SDL2/SDL.h>

struct View {
    SDL_Window* win;
    SDL_Renderer* render;
    struct RoadView road;
    struct CloudView cloud;
    struct DinoView dino;
    struct CactusView cactus;
};

struct View initView(struct Model* model);

void drawView(struct View* mthis);

void freeView(struct View* mthis);

#endif 
