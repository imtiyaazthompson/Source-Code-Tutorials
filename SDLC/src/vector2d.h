#ifndef VECTOR2D_H
#define VECTOR2D_H

//Every entity in a game will have a position int the xy-plane
//Every entity will save its last position
typedef struct position {
	double x;
	double y;
	pos prev;
} pos;

//When an entity chages positions it does so at a certain speed
//and direction -> velocity
typedef struct velocity {
	double dx;
	double dy;
	vel prev;
} vel;

//When an entity does not move at a constant velocity
//It is accelarating in a certain direction
typedef struct accel {
	double dv;
	acc prev;
} acc;

/*
 * Understanding the physics
 * 
 * If we move a rigid body we are changing its current position in the world (xy-axes)
 * We can make that change in position in varying degrees by changing the body's velocity
 * That is if we want to move a player to the left by doing a sprint, we can apply 
 * a greater velocity then modify the position by that velocity over time. So, if the player 
 * at pos.x = 10, pos.y = 10 wants to move left, that is change its position
 * (i.e. apply some velocity), then if we apply vel.dx=-1, vel.dy=0 then the player will move
 * to the left by 1 coordinate point over time
 *
 * If we are changing a body's velocity we are infact applying an acceleration in a given direction
 * So we apply an accelaration when we want to transition between different speeds to indicate speedup
 * or slow down, like the slow down from a sprint 
*/

#endif
