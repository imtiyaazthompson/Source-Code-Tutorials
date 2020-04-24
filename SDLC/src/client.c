#include <stdio.h>
#include "display.h"
#include "bool.h"
#include "status.h"
#include "load_media.h"
#include "media.h"
#include "render.h"

int main(int argc, char **argv) {
	//Nifty trick to getting pointers to structs w/o malloc
	Display display,*dp;
	dp = &display;
	Image i,j,*i_p,*j_p;
	i_p = &i;
	j_p = &j;

	hollow_display(&dp);
	init_display("Display Wrapper",800,600,&dp,TRUE);
	load_image(&dp,&i_p,"./load.png");
	load_image(&dp,&j_p,"./quit.png");

	int quit = FALSE;
	SDL_Event e;
	while (quit == FALSE) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			}
		}
		
		render_image(&dp,&i_p);
		update_display(&dp);
	}

	close(&dp);
	return 0;
}
