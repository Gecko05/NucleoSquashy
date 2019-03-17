#include "gamesys.h"

Link lHead;
int gameover = 0;
int score = 0;
int beep = 0;
int padSpeed = 0;
int prevCollision = 0;
// Ball Directions
int ballx = 0;
int bally = 0;
extern TIM_HandleTypeDef htim3;
//Edge CollisionEdge;

// Check if there's a collision on the edges of the screen
Edge checkEdgeCollision(BodyNode body){
	if (body->y <= 0){
		return TOP_EDGE;
	}
	else if (body->y >= 64 - HEIGHT(body)){
		return BOTTOM_EDGE;
	}
	if (body->x <= 0){
		return LEFT_EDGE;
	}
	else if (body->x >= 128 - WIDTH(body)){
		return RIGHT_EDGE;
	}
	return NO_EDGE;
}

// Check if there's a collision between body1 and body2, relative to body1
int checkCollision(BodyNode body1, BodyNode body2){
	int xDistance = body2->x - body1->x;
	int yDistance = body2->y - body1->y;
	if ((xDistance < 0 && abs(xDistance) < WIDTH(body2)) || (xDistance > 0 && xDistance < WIDTH(body1)) || (xDistance == 0)){
		if ((yDistance < 0 && abs(yDistance) < HEIGHT(body2)) || (yDistance > 0 && yDistance < HEIGHT(body1)) || (yDistance == 0)){
				return 1;
			}
	}
	return 0;
}

// Display score
void displayScore(void){
	ssd1306_SetCursor(1,1);
	char scoreString[4];
	itoa(score, scoreString, 10);
	ssd1306_WriteString(scoreString, Font_11x18, White);
}

// Display game over screen
void displayGameOverScreen(void){
	ssd1306_Fill(Black);
	ssd1306_SetCursor(2,23);
	ssd1306_WriteString(" Game Over", Font_11x18, White);
}

// Create the beep output
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

// Draw a game item
void drawItem(Link gameItem){
	draw_sprite(gameItem->item->x, gameItem->item->y, gameItem->item->sprite);
}

// Initiate the draw list
void initList(void){
	lHead = NULL;
}

// Append a new bodyNode to the draw list
void appendToGameList(BodyNode newNode){
	Link t = malloc(sizeof(*t));
	t->next = lHead;
	t->item = newNode;
	lHead = t;
}

// Initialize and allocate memory for a new game object
void initGameObject(Sprite *gameSprite, const uint16_t *spriteFile, BodyNode *gameBody, int width, int height, int xPos, int yPos){
	gameSprite->width = width;
	gameSprite->height = height;
	gameSprite->spriteContent = spriteFile;
	(*gameBody) = malloc(sizeof(**gameBody));
	(*gameBody)->sprite = *gameSprite;
	(*gameBody)->x = xPos;
	(*gameBody)->y = yPos;
	appendToGameList(*gameBody);
}

// Initiate the squashy game system
void vInitSys(void){
	initList();
	initGameObject(&playerBar, playerBarSprite, &player1, 16, 4, 56, 55);
	initGameObject(&ball, playerBarSprite, &ball1, 4, 4, 58, 30);
}

// Run game mechanics
void vUpdate(void){
  // Check if the game has finished
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
	// Check collision between the bar and the ball
	if (checkCollision(player1, ball1)){
		if(!prevCollision){
			bally = -1;
			score++;
			beep = 1;
			prevCollision = 1;
		}
	}
	else{
		prevCollision = 0;
	}
	// Check collision between the ball and the screen edges
	Edge Collision = checkEdgeCollision(ball1);
	switch(Collision){
		case TOP_EDGE:
			bally = 1;
			break;
		case BOTTOM_EDGE:
			gameover = 1;
			bally = -1;
			break;
		case LEFT_EDGE:
			ballx = 1;
			break;
		case RIGHT_EDGE:
			ballx = -1;
			break;
		default:
			break;
	}
	// Move the ball
	if (bally > 0){
		ball1->y++;
	}
	else{
		ball1->y--;
	}
	if (ballx > 0){
		ball1->x++;
	}
	else{
		ball1->x--;
	}
	// Handle Inputs to change the pad's speed
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) == GPIO_PIN_SET){
		if (padSpeed < MAX_SPEED){
			padSpeed++;
		}
	}
	else{
		if (padSpeed > 0){
			padSpeed--;
		}
	}
	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_SET){
		if (padSpeed > -MAX_SPEED){
			padSpeed--;
		}
	}
	else{
		if (padSpeed < 0){
			padSpeed++;
		}
	}
	// Check collision between the pad and the screen and move the pad
	if (!((checkEdgeCollision(player1) == LEFT_EDGE && padSpeed < 0) || (checkEdgeCollision(player1) == RIGHT_EDGE && padSpeed > 0))){
		player1->x += padSpeed;
	}
}

// Draw every element of the UI on the screen
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
