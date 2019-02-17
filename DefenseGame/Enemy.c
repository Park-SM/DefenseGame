#include "Enemy.h"

ENEMY* CreateEnemy(int gate) {
	ENEMY *NewEnemy = (ENEMY*)malloc(sizeof(ENEMY));

	NewEnemy->type = 'e';
	NewEnemy->x = gate;
	NewEnemy->y = 2;
	NewEnemy->shape = "¥ø";
	NewEnemy->NextEnemy = NULL;

	return NewEnemy;
}