#include "view.h"

#include <stdio.h>
#include <unistd.h>

struct View initView(struct Model* model) {
    struct View mthis = {NULL, NULL};
    mthis.win = SDL_CreateWindow("Jumping Dino",
                                     SDL_WINDOWPOS_UNDEFINED, // Позиция по горизонтали (неопределенная)
                                         SDL_WINDOWPOS_UNDEFINED, // Позиция по вертикали (неопределенная)
                                         1200,                     // Ширина окна (в пикселях)
                                         340,                     // Высота окна (в пикселях)
                                         SDL_WINDOW_SHOWN);
    mthis.render = SDL_CreateRenderer(mthis.win, -1, SDL_RENDERER_ACCELERATED);
    mthis.road = initRoadView(&model->road, mthis.render);
    mthis.cloud = initCloudView(&model->cloud, mthis.render);
    mthis.dino = initDinoView(&model->dino, mthis.render);
    mthis.cactus = initCactusView(&model->cactus, mthis.render);

    printf("Create modul View\n");
    return mthis;
}

void drawView(struct View* mthis) {
    SDL_SetRenderDrawColor(mthis->render, 255, 255, 255, 255);
    SDL_RenderClear(mthis->render);
    
    drawRoadView(&mthis->road);
    drawCloudView(&mthis->cloud);
    drawDinoView(&mthis->dino);
    drawCactusView(&mthis->cactus);
    
    SDL_RenderPresent(mthis->render);
}

void freeView(struct View* mthis) {
    printf("Free modul View\n");
    SDL_DestroyRenderer(mthis->render);
    SDL_DestroyWindow(mthis->win);

    freeRoadView(&mthis->road);
    freeCloudView(&mthis->cloud);
    freeDinoView(&mthis->dino);
    freeCactusView(&mthis->cactus);
    
    mthis->win = NULL;
    mthis->render = NULL;
}
