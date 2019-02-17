#ifndef _BULLET_H_
#define _BULLET_H_

#include <stdio.h>

typedef struct tagBullet {
	char type;
	int x;
	int y;
	char *shape;
	struct tagBullet *NextBullet;
}BULLET;


#endif