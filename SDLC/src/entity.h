#ifndef ENTITY
#define ENTITY

#include "vector2d.h"

//Generic Blueprint for entities that inhabit a game world
typedef struct entity {
	pos position;
	vel velocity;
	acc accel;
} entity

#endif
