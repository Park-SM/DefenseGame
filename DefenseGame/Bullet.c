#include "Bullet.h"

BULLET* CreateBullet(int gate){
	BULLET* NewBullet = (BULLET*)malloc(sizeof(BULLET));
	
	NewBullet->type = 'b';
	NewBullet->x = gate;
	NewBullet->y = 22;
	NewBullet->shape = "��";
	NewBullet->NextBullet = NULL;

	return NewBullet;
}