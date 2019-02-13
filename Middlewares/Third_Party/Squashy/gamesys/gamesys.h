#ifndef GAMESYS_H
#define GAMESYS_H
#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_gpio.h"
#include "ssd1306.h"
#include "gameobject.h"
#include "stdlib.h"

typedef struct node_t* Link;

struct node_t{
	BodyNode item;
	Link next;
};

BodyNode player1;

BodyNode ball1;

void vDraw(void);

void vUpdate(void);

void vInitSys(void);

#endif // GAMESYS_H
