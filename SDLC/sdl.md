# In the Beginning
## Including SDL
+ `.c` main file should
```c
	#include <SDL2/SDL.h>
```

+ Creating your make file to avoid messy compilation
```makefile
	OBJS = <.c files here>
	CC = gcc
	CFLAGS = -w  # No Warnings
	LFLAGS = -lSDL2 # Linker Flags

	BIN = <executable name>
	
	all: $(OBJS)
		$(CC) $(CFLAGS) -o $(BIN) $(OBJS) $(LFLAGS)
```
+ **NB** Always keep `LFLAGS` at the end of the compilation line

## Creating a Window
```c
	#include <SDL.h>
	#include <stdio.h>

	const int SCR_WIDTH = 640;
	const int SCR_HEIGHT = 480;

	int main(int argc, char **argv)
	{
		//The window you render to
		SDL_Window *window = NULL;

		//Surface contained by the window
		SDL_Surface *scr_surface = NULL;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize\n");
			printf("SDL_Error: %s\n", SDL_GetError());
		} else {
			//Create the window if no error occurs
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

				//Fill the surface white
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
		
		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();

		return 0;
	}
```

+ SDL surfaces are just 2D images
+ 2D image can be loaded from a file or it can be an image inside of a window
+ In this case it will be the image inside the window.
+ You cannot call any SDL functions without initializing SDL first
+ `SDL_init` return -1 if there is an error
+ `SDL_GetError()` will return any error that may occur
+ `SDL_CreateWindow()` arguments in order
	+ Caption
	+ x position the window is created in
	+ y position the window is created in
		+ Since we don't care where the window is created
	+ Window Width
	+ Window Height
	+ Creation Flag
		+ Ensures the window is shown when created
+ `SDL_CreateWindow()` return `NULL` when a window cannot be created

+ If the window was createdd successfully
	+ Get the window surface, so we can draw on it
	+ Fill the window surface
	+ You need to update the window surface to reflect any drawing changes
	+ To keep the window from disappearing we use delay
	+ When SDL is delaying, it is blocking and accepts no input

+ **NB** Remember to use `strcpy` when writing strings to `malloc'd` `char*`
