#include "stm32l1xx_hal.h"
#include "ssd1306.h"
#include "gamesys.h"
#include "gameobject.h"

void vDrawItem(link gameItem){

}

link lHead;

void vInitList(void){
	lHead->item = NULL;
	lHead->next = NULL;
}

void vInitSys(void){
	vInitList();
	bodyNode player = vCreateObj();
}

void vUpdate(void){
	//handleEvents
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
