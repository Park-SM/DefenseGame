#include "Bullet.h"

BULLET* CreateEnemy(int x)
{
	BULLET* NewBullet = (BULLET *)malloc(sizeof(BULLET));
	
	NewBullet->type = 'b';
	NewBullet->x = x;
	NewBullet->y = 22;
	NewBullet->shape = "��";
	NewBullet->NextBullet = NULL;

	return NewBullet;
}