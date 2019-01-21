#include "stm32l1xx_hal.h"
#include "ssd1306.h"
#include "gamesys.h"

typedef struct Body{
	int x;
	int y;
	void* draw;
} body;

typedef struct node* link;

struct node{
	body* item;
	link next;
};

void vDrawItem(link gameItem){
	gameItem->item->draw();
}

link lHead;

void vInitList(void){
	lHead->item = NULL;
	lHead->next = NULL;
}

void vInitSys(void){
	vInitList();

}
void vUpdate(void){

}

void vDraw(void){
	/* Traverse the list to draw all items in the list */
	link gameItem = lHead;
	while(gameItem->item != NULL){
		vDrawItem(gameItem);
		gameItem = gameItem->next;
	}
	ssd1306_UpdateScreen();
}
