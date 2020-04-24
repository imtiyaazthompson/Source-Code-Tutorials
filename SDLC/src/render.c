#include <SDL2/SDL.h>
#include "media.h"
#include "display.h"
#include "render.h"

void render_image(Display **d,Image **media) {
	SDL_BlitSurface((*media)->surface,NULL,(*d)->scr_surface,NULL);
}
