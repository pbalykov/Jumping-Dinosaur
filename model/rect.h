#ifndef RECT_H
#define RECT_H

#include <stdbool.h>

struct Rect {
    int x;
    int y;
    int width;
    int height;
};


struct Rect initRect(int x, int y, int width, int height);
bool collision(const struct Rect* first, const struct Rect* second);

#endif
