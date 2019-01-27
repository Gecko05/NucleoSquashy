#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <stdint.h>
#include "sprites.h"
typedef uint8_t coordinate_t;

typedef struct body* bodyNode;

typedef struct body{
	coordinate_t x;
	coordinate_t y;
	Sprite sprite;
} Body;

/*
 *	#######################################################
 */

bodyNode vCreateObj(spriteArray spriteArray);

#endif // GAMEOBJECT_H
