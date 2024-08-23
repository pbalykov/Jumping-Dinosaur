#ifndef DINO_VIEW_H
#define DINO_VIEW_H

#include "../model/dinoModel.h" //заментмть потом на <

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct DinoView {
    const struct DinoModel* dino;
    SDL_Texture* textur;
    SDL_Renderer* render; 
};

struct DinoView initDinoView(const struct DinoModel* tmpDino, SDL_Renderer* tmpRender);
void drawDinoView(struct DinoView* mthis);
void freeDinoView(struct DinoView* mthis);

#endif
