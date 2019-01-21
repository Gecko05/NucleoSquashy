#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <stdint.h>
typedef static const uint16_t* spriteArray_t;
typedef uint8_t coordinate_t;

typedef struct Body* bodyNode;

typedef struct Body{
	coordinate_t x;
	coordinate_t y;
	spriteArray_t sprite;
};

/*
 *	#######################################################
 */

bodyNode vCreateObj(void);

#endif
