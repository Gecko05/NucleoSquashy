#include "sprites.h"

const spriteArray playerBarSprite = {
		0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00, 0xFF00
};

Sprite playerBar;

void draw_sprite(uint8_t x, uint8_t y, Sprite spriteToDraw)
{
	for (int i = 0; i < spriteToDraw.height; i++){
		for (int j = 0; j < spriteToDraw.width; j++){
			if (spriteToDraw.spriteContent[i] << j & 0x8000){
				ssd1306_DrawPixel(x + i, y + j, White);
			}
			else{
				ssd1306_DrawPixel(x + i, y + j, Black);
			}
		}
	}
}

//example sprite
