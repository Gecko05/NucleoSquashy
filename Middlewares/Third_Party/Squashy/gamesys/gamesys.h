#ifndef GAMESYS_H
#define GAMESYS_H
#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_gpio.h"
#include "ssd1306.h"
#include "gameobject.h"
#include "stdlib.h"

#define WIDTH(x) x->sprite.width
#define HEIGHT(x) x->sprite.height
#define MAX_SPEED 3
#define MAX_LIVES 3

typedef struct node_t* Link;

typedef enum edge{
	NO_EDGE,
	TOP_EDGE,
	BOTTOM_EDGE,
	LEFT_EDGE,
	RIGHT_EDGE
}Edge;

struct node_t{
	BodyNode item;
	Link next;
};

void vDraw(void);

void vUpdate(void);

void vOutputAudio(void);

void vInitSys(void);

#endif // GAMESYS_H
