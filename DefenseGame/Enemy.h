#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int FREQ_E_PE = 50;
static int FREQ_E_AS = 60;

typedef struct tagEnemy {
	char type;
	int x;
	int y;
	char *shape;
	struct tagEnemy *NextEnemy;
}ENEMY;

ENEMY* CreateEnemy(int gate);

#endif