#ifndef GAME_SYS_H
#define GAME_SYS_H
#include "gameobject.h"

typedef struct node* link;

struct node{
	bodyNode item;
	link next;
};

void vUpdate(void);

void vDraw(void);

#endif
