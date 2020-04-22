#include <SDL2/SDL.h>
#include <stdio.h>

const int SCR_WIDTH = 640;
const int SCR_HEIGHT = 480;

int main(int argc,char **argv)
{
	//The Window to render to
	SDL_Window *window = NULL;
	
	//Surface contained by the window
	SDL_Surface *scr_surface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize\n");
		printf("SDL_Error: %s\n", SDL_GetError());
	} else {
		//Create the window if A-OK
		window = SDL_CreateWindow(
				"SDL Tutorial",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SCR_WIDTH,
				SCR_HEIGHT,
				SDL_WINDOW_SHOWN
			);

		if (window == NULL) {
			printf("Window could not be created\n");
			printf("SDL_Error: %s\n", SDL_GetError());
		} else {
			//Get window surface
			scr_surface = SDL_GetWindowSurface(window);
			//Fill surface white
			SDL_FillRect(
				scr_surface,
				NULL,
				SDL_MapRGB(
					scr_surface->format,
					0xFF,
					0xFF,
					0xFF
				)
			);

			//update the surface
			SDL_UpdateWindowSurface(window);

			//wait
			SDL_Delay(2000);
		}
	}

	//Destroy Window
	SDL_DestroyWindow(window);
	
	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
