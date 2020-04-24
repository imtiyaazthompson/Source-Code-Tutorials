#ifndef HANDLER_H
#define HANDLER_H

#include <SDL2/SDL.h>

// Cs answer to generics -> function pointers
// Function pointers as args are referred to as callback functions
// And are the perfect solution to hadling general events
// SDL has general event types that can be acted upon, such as quit and keydown and key up

// Event Call Backs
// Typedef them to act like a variable type
// The type is a function pointer an expects to be declared like
// E.G.: handle_event_quit = &my_function_that_handles_quit();

// APPLICATION
typedef void (*handle_event_quit)();

// KEYBOARD
// enum constants {UP,DOWN,...} -> symbolic constants, default start from 0, can be set to something else
// event->type = {SDL_KEYDOWN,SDL_KEYUP}, handled by client
// event->keysym->sym = {virtual keycode of keyboard button pressed} argument of keyboard event handlers
// sym is the virtual keycode and represents a symbolic constant of an enum SDL_KeyCode
// E.G.: if sym = SDLK_UP it represents the up key that has a value that SDL uses.
typedef void (*handle_event_keydown)(SDL_KeyCode);
typedef void (*handle_event_keyup)(SDL_KeyCode);

//WINDOW
typedef void (*handle_event_window_change)();


//MOUSE
// event->type = SDL_MOUSE_MOTION
// event->x, event->y
// event-button = {SDL_BUTTON_LEFT,SDL_BUTTON_MIDDLE,SDL_BUTTON_RIGHT,SDL_BUTTON_X1,SDL_BUTTON_X2}
// event->state = {SDL_PRESSED,SDL_RELEASED}
// event->clicks, 1 for single click, 2 for double click etc
typedef void (*handle_event_mouse_moved)(signed int x,signed int y);
typedef void (*handle_event_mouse_btndown)(unsigned char button,unsigned char clicks);
typedef void (*handle_event_mouse_btnup)(unsigned char button);


//Struct
// The end-user writes their library of functions to respond to an event
// The end-user then populates the event manager with their functions in the client
// Then, if you were to react to quit, event_manager.quit() will then call the end-users function
// Contributed by stackoverflow user: 眠りネロク 
typedef struct event_handlers {
	handle_event_quit quit;
	handle_event_keydown keydown;
	handle_event_keyup keyup;
	handle_event_window_change windowchange;
	handle_event_mouse_moved mousemoved;
	handle_event_mouse_btndown mousepress;
	handle_event_mouse_btnup mouserelease;
} event_manager;

#endif
