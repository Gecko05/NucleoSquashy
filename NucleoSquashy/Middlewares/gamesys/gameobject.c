#include "gameobject.h"

bodyNode vCreateObj(spriteArray_t *spriteArray){
	bodyNode newObj = malloc(sizeof(*newObj));
	newObj->sprite = spriteArray;
	newObj->x = newObj->y = 0;
	return newObj;
}
