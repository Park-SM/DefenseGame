#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <stdio.h>

typedef struct tagEnemy {
	char type;
	int x;
	int y;
	char *shape;
	struct tagEnemy *NextEnemy;
}ENEMY;


#endif