#ifndef MEDIA_H
#define MEDIA_H

//Media structs
#include <SDL2/SDL.h>
#include "display.h"

typedef struct image {
	SDL_Surface *surface;
	int width;
	int height;
} Image;

#endif
