#include "Bullet.h"

BULLET* CreateBullet(int uX){
	BULLET* NewBullet = (BULLET *)malloc(sizeof(BULLET));
	
	NewBullet->type = 'b';
	NewBullet->x = uX;
	NewBullet->y = 22;
	NewBullet->shape = "��";
	NewBullet->NextBullet = NULL;

	return NewBullet;
}