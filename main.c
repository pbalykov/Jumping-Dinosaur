#include "model/model.h"
#include "view/view.h"

//#include "controller/controller.h"

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdbool.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Не удалось инициализировать SDL_image: %s", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    
    struct Model model = initModel(); 
    struct View view = initView(&model);
 
    //struct Controller controller = initController(&view, &model);

    bool endApp = true;
    while ( endApp ) {
        SDL_Event event;
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                endApp = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_SPACE:
                        jamp(&model.dino);
                        break;
                }
            }
        }
        drawView(&view);
        if ( updateModel(&model) ) {
            break;
        }
        SDL_Delay(15);
    }
    freeView(&view);
}
