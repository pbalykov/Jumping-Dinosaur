#ifndef CLOUD_VIEW_H
#define CLOUD_VIEW_H

#include "../model/cloudModel.h" //заментмть потом на <

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


struct CloudView {
    const struct CloudModel* cloud;
    SDL_Texture* textur;
    SDL_Renderer* render; 
};

struct CloudView initCloudView(const struct CloudModel* tmpCloud, SDL_Renderer* tmpRender);
void drawCloudView(struct CloudView* mthis);
void freeCloudView(struct CloudView* mthis);

#endif
