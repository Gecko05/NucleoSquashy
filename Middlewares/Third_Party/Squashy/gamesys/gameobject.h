#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "sprite_rendering.h"
#include <stdint.h>
typedef int coordinate_t;

typedef struct body_t* BodyNode;

typedef struct body_t{
	coordinate_t x;
	coordinate_t y;
	uint8_t visible;
	Sprite sprite;
} Body;

BodyNode vCreateObj(spriteArray spriteArray);

#endif // GAMEOBJECT_H
