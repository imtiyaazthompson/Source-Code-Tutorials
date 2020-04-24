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

## Images
```c
	SDL_Surface *surface = NULL;
```
+ An `SDL_Surface` is just an image datatype that contains the pixels of an image and all the data used to render it
+ SDL surfaces are software rendered as in it is rendered by the CPU (low performance)
+ Require another Library called `SDL_Image`
```
	$ sudo apt-get install libsdl2-image-dev
```
+ Include `-lSDL2_image` in your make `LFLAGS`
+ Include headers: `<SDL2/SDL_image.h>`
+ Similar for `$sudo apt-get install libsdl2-mixer-dev`
+ And `libsdl2-ttf-dev`

## Event Handling
```
	SDL_Event e;
	int quit = FALSE;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			}
		}
	}
```
+ Game Loop
	+ Event Loop
		+ Keep processing the **event queue** until it is empty
		> When you press a key, move the mouse, or touch a touch screen you put events onto the event queue.

		+ Event queue stores events in the order they occured waiting for you to process them
		+ You poll the event queue to get the most recent event that occured
		+ Take the most recent event and save it in `e`

>I wouldn't think of function pointers as switch alternatives. Switch tests an expression and then executes code based on the value of the expression. Function pointers don't test anything. They just allow you to store and pass references to functions when you don't know what function you're going to call at compile time. The example I used was simply to demonstrate how they work. I was not recommending that you write functions to add and multiply integers. Common uses for function pointers are callback functions, thread functions, and occasionally incarnations of finite state machines. Also, when you are trying to replace switch statements, you can often use function pointers to create simpler code that's easier to extend.

## Callbacks
+ Function pointers passed as arguments to functions
+ Used when the function to be used is not known at compile time 
