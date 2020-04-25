#include <SDL2/SDL.h>
#include <stdio.h>
#include "display.h"
#include "media.h"
#include "load_media.h"
#include "handler.h"
#include "bool.h"

void key_pressed(SDL_KeyCode key);

void init_eventmanager(void);

int main(int argc, char **argv) {
	Images images[2],(*ip)[2];
	for (int i = 0; i < 2; i++) {
		ip[i] = &images[i];	
	}
	Display display,*dp;

	//Init Display
	hollow(&dp);
	init_display("Demo Event Manager",640,480,&dp,TRUE);
	event_manager evman = init_eventmanager();
	load_image(&dp,&ip[0]);
	load_image(&dp,&ip[1]);

	int quit = FALSE;
	SDL_Event e;
	while (!quit) {
		while (SDL_EventPoll(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			} else if (e.type == SDL_KEYDOWN) {
				evman.keydown(e.keysym.sym);
			}
		}
	}
}

event_manager init_eventmanger() {
	event_manager eman;
	eman.keydown = key_pressed;
}
