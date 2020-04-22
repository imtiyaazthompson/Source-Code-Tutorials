#ifndef DISPLAY
#define DISPLAY

#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0

typedef struct display {
	SDL_Window *window;
	SDL_Surface *scr_surface;
	
	int width;
	int height;
	char *caption;
} Display;


//Use more precise function names
void hollow_display(Display **d);
int init_display(char *caption,int width,int height,Display **d,int fill);
void get_window_surface(Display **d);
void fill_surface(Display **d, int *hex_vector);
void update_display(Display **d);
void delay_display(int ms);
void close_display(Display **d);
void raise_error(char *type);
int get_width(Display **d);
int get_height(Display **d);
char* get_caption(Display **d);
 
#endif
