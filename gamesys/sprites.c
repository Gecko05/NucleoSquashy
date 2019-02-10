#include "sprites.h"

const uint16_t playerBarSprite[] = {
		0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
};

Sprite playerBar;

void draw_sprite(uint8_t x, uint8_t y, Sprite spriteToDraw)
{
	for (int i = 0; i < spriteToDraw.height; i++){
		for (int j = 0; j < spriteToDraw.width; j++){
			int res = (spriteToDraw.spriteContent[i] << j) & 0x8000;
			if (res){
				ssd1306_DrawPixel(x + j, y + i, White);
			}
			else{
				ssd1306_DrawPixel(x + j, y + i, Black);
			}
		}
	}
}

void draw_filled_rectangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1)
{
	for (int i = x0; i < x1; i++){
		for (int j = y0; j < y1; j++){
			ssd1306_DrawPixel(i, j, White);
		}
	}
}

//example sprite
