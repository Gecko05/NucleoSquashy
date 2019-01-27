#ifndef SPRITES_H
#define SPRITES_H

#include "ssd1306.h"

typedef const uint16_t* spriteArray;

typedef struct sprite{
	int8_t width;
	int8_t height;
	spriteArray spriteContent;
} Sprite;

extern const spriteArray playerBarSprite;

extern Sprite playerBar;

void draw_sprite(uint8_t x, uint8_t y, Sprite spriteToDraw);

#endif // SPRITES_H
