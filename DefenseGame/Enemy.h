#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tagEnemy {
	char type;
	int x;
	int y;
	char *shape;
	struct tagEnemy *NextEnemy;
}ENEMY;

ENEMY* CreateEnemy();

#endif