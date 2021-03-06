#ifndef _BULLET_H_
#define _BULLET_H_

#include <stdio.h>
#include <stdlib.h>

#define FREQ_B_PB 5

typedef struct tagBullet {
	char type;
	int x;
	int y;
	char *shape;
	struct tagBullet *NextBullet;
}BULLET;

BULLET* CreateBullet(int gate);

#endif