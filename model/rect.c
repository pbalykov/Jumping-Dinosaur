#include "rect.h"

struct Rect initRect(int x, int y, int width, int height) {
    struct Rect value = {x, y, width, height};
    return value;
}


bool collision(const struct Rect* first, const struct Rect* second) {
    if ( first->x < second->x + second->width && 
         first->x + first->width > second->x  &&
         first->y < second->y + second->height && 
         first->y + first->height > second->y ) {
        return true;
    }
    return false;
}
