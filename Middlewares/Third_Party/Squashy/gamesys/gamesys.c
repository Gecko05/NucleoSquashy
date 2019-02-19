#include "gamesys.h"

Link lHead;
int gameover = 0;
int score = 0;
int beep = 0;
int ballSpeed = 1;
extern TIM_HandleTypeDef htim3;

void displayScore(void){
	ssd1306_SetCursor(1,1);
	char scoreString[4];
	itoa(score, scoreString, 10);
	ssd1306_WriteString(scoreString, Font_11x18, White);
}

void displayGameOverScreen(void){
	ssd1306_Fill(Black);
	ssd1306_SetCursor(2,23);
	ssd1306_WriteString(" Game Over", Font_11x18, White);
}

void vOutputAudio(void){
	static int countBeep = 0;
	if (beep){
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
		countBeep++;
		if(countBeep >= 2){
			beep = 0;
			countBeep = 0;
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
		}
	}
}

void drawItem(Link gameItem){
	draw_sprite(gameItem->item->x, gameItem->item->y, gameItem->item->sprite);
}

void vInitList(void){
	lHead = NULL;
}

void appendToGameList(BodyNode newNode){
	Link t = malloc(sizeof(*t));
	t->next = lHead;
	t->item = newNode;
	lHead = t;
}

void vInitSys(void){
	vInitList();
	playerBar.width = 16;
	playerBar.height = 4;
	playerBar.spriteContent = playerBarSprite;
	player1 = malloc(sizeof(*player1));
	player1->sprite = playerBar;
	player1->x = 56;
	player1->y = 55;
	appendToGameList(player1);

	ball.width = 4;
	ball.height = 4;
	ball.spriteContent = playerBarSprite;
	ball1 = malloc(sizeof(*ball1));
	ball1->sprite = ball;
	ball1->x = 58;
	ball1->y = 30;
	appendToGameList(ball1);

	//bodyNode player = vCreateObj();
}

void vUpdate(void){
	static int ballx = 0;
	static int bally = 0;

	if (gameover){
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_SET &&
				HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_SET){
			  gameover = 0;
			  ball1->x = 60;
			  ball1->y = 10;
			  score = 0;
		}
		return;
	}
	if (((ball1->x - player1->x) <= player1->sprite.width) && ((ball1->x - player1->x) > -ball1->sprite.width) && !bally){
		if (abs(ball1->y - player1->y) <= player1->sprite.height){
			bally = 1;
			score++;
			beep = 1;
		}
	}

	if (!ballx && (ball1->x <= (128 - ball1->sprite.width - ballSpeed))){
		ball1->x += ballSpeed;
	}
	else{
		ballx = 1;
	}
	if (ballx && (ball1->x >= ballSpeed)){
			ball1->x -= ballSpeed;
	}
	else{
		ballx = 0;
	}

	if (!bally && (ball1->y <= 60 - ballSpeed)){
		ball1->y += ballSpeed;
	}
	else if (ball1->y >= 60){
		gameover = 1;
	}
	if (bally && (ball1->y >= ballSpeed)){
			ball1->y -= ballSpeed;
	}
	else{
			bally = 0;
	}
	//handleEvents
	if ((HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_SET) && (player1->x < (128 - (player1->sprite.width)))){
		(player1->x)++;
	}
	if ((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_SET) && (player1->x > 0)){
		(player1->x)--;
	}
}

void vDraw(void){
	if (gameover){
		displayGameOverScreen();
	}
	else{
		/* Traverse the list to draw all items in the list */
		ssd1306_Fill(Black);
		displayScore();
		Link gameItem = lHead;
		while(gameItem->item != NULL){
			drawItem(gameItem);
			if(gameItem->next == NULL){
				break;
			}
			gameItem = gameItem->next;
		}
	}
  // Update screen with draw changes
	ssd1306_UpdateScreen();

}
