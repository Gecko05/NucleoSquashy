#ifndef GAMESYS_H
#define GAMESYS_H
#include "gameobject.h"

typedef struct node* link;

struct node{
	bodyNode item;
	link next;
};

void vUpdate(void);

void vDraw(void);

void vInitSys(void);

#endif // GAMESYS_H
