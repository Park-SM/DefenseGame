#ifndef _BULLET_H_
#define _BULLET_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tagBullet {
	char type;
	int x;
	int y;
	char *shape;
	struct tagBullet *NextBullet;
}BULLET;

BULLET* CreateBullet(int uX);

#endif