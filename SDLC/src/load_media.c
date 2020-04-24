#include <SDL2/SDL_image.h>
#include "display.h"
#include "load_media.h"

void load_image(Display **d,Image **img,char *path) {
	(*img)->surface = NULL;
	SDL_Surface *loaded_surface = IMG_Load(path);
	
	(*img)->width = loaded_surface->w;
	(*img)->height = loaded_surface->h;

	if (loaded_surface == NULL) {
		raise_error("Loading Image from file",MEDIA);
	} else {
		//Convert surface to screen surface
		(*img)->surface = SDL_ConvertSurface(loaded_surface,(*d)->scr_surface->format,0);
		if ((*img)->surface == NULL) {
			raise_error("Optimizing Surface",MEDIA);
		}

		//Free Old Surface
		SDL_FreeSurface(loaded_surface);
	}
}
