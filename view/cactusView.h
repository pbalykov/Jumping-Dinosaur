#ifndef CACTUS_VIEW_H
#define CACTUS_VIEW_H

#include "../model/cactusModel.h" //заментмть потом на <

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct CactusView {
    const struct CactusModel* cactus;
    SDL_Texture* textur;
    SDL_Renderer* render; 
};

struct CactusView initCactusView(const struct CactusModel* tmpCactus, 
                                  SDL_Renderer* tmpRender);
void drawCactusView(struct CactusView* mthis);
void freeCactusView(struct CactusView* mthis);

#endif
