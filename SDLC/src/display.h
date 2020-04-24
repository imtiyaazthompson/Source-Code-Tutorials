#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

#define DISPLAY 0
#define MEDIA 1

typedef struct display {
	SDL_Window *window;
	SDL_Surface *scr_surface;
	int width;
	int height;
	char *caption;
} Display;


/*
 * Setup Display Struct for further processing
 */
void hollow_display(Display **d);

/*
 * Initialize SDL and Display Struct
 */
int init_display(char *caption,int width,int height,Display **d,int fill);

/*
 * Initialize media access to PNG files, tweak to add more file types
 */
int init_media_access(void);

/*
 * Set the scr_surface of the display
 */
void get_window_surface(Display **d);

/*
 * Fill a screen surface with a RGB hex
 */
void fill_surface(Display **d, int *hex_vector);

/*
 * Update the window to reflect any changes
 */
void update_display(Display **d);

void delay_display(int ms);

/*
 * Perform cleanup and terminate display
 */
void close_display(Display **d);

/*
 * Raise an SDL error
 */
void raise_error(char *type, int mode);

int get_width(Display **d);

int get_height(Display **d);

char* get_caption(Display **d);
 
#endif
