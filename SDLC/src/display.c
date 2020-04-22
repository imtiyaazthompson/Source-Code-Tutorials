#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include "display.h"

void hollow_display(Display **d) {
	(*d)->window = NULL;
	(*d)->scr_surface = NULL;
	(*d)->width = -1;
	(*d)->height = -1;
	(*d)->caption = malloc(sizeof(char)*30);
}

int init_display(char *caption,int width,int height,Display **d,int fill) {
	int status = SDL_Init(SDL_INIT_VIDEO);

	if (status < 0) {
		raise_error("Initializing Display");
	} else {
		//Create window
		(*d)->width = width;
		(*d)->height = height;
		strncpy((*d)->caption,caption,sizeof(char)*30);
		(*d)->window = SDL_CreateWindow(
				caption,
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_SHOWN
			);

		if ((*d)->window == NULL) {
			raise_error("Creating Window");
		} else {
			get_window_surface(d);
			if (fill) {
				int hex_col[3] = {0xFF,0xFF,0xFF};
				fill_surface(d,hex_col);
			}
		}
	}
}

void get_window_surface(Display **d) {
	(*d)->scr_surface = SDL_GetWindowSurface((*d)->window);
}

void fill_surface(Display **d, int *hex_vector) {
	SDL_FillRect(
		(*d)->scr_surface,
		NULL,
		SDL_MapRGB(
			(*d)->scr_surface->format,
			hex_vector[0],
			hex_vector[1],
			hex_vector[2]
		)
	);
}

void update_display(Display **d) {
	SDL_UpdateWindowSurface((*d)->window);
}

void delay_display(int ms) {
	SDL_Delay(2000);
}

void close_display(Display **d) {
	SDL_DestroyWindow((*d)->window);
	SDL_Quit();
}

int get_width(Display **d) {
	return (*d)->width;
}

int get_height(Display **d) {
	return (*d)->height;
}

char* get_caption(Display **d) {
	return (*d)->caption;
}

void raise_error(char *type) {
	printf("Error: %s\n",type);
	printf("SDL_Error: %s\n",SDL_GetError());
}
