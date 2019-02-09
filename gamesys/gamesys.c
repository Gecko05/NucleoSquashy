#include "stm32l1xx_hal.h"
#include "ssd1306.h"
#include "gamesys.h"
#include "gameobject.h"
#include "stdlib.h"

void vDrawItem(link gameItem){
	draw_sprite(10, 10, gameItem->item->sprite);
}

link lHead;

void vInitList(void){
	lHead = malloc(sizeof(*lHead));
	lHead->item = NULL;
	lHead->next = NULL;
}

void vInitSys(void){
	vInitList();
	playerBar.width = 7;
	playerBar.height = 4;
	playerBar.spriteContent = playerBarSprite;
	bodyNode player1 = malloc(sizeof(*player1));
	player1->sprite = playerBar;
	player1->x = 10;
	player1->y = 10;
	lHead->item = player1;
	lHead->next = NULL;
	//bodyNode player = vCreateObj();
}

void vUpdate(void){
	//handleEvents
}

void vDraw(void){
	/* Traverse the list to draw all items in the list */
	link gameItem = lHead;
	while(gameItem->item != NULL){
		vDrawItem(gameItem);
		if(gameItem->next == NULL){
			break;
		}
		gameItem = gameItem->next;
	}
	ssd1306_UpdateScreen();
}
