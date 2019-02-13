#ifndef _BULLET_H_
#define _BULLET_H_

typedef struct tagBullet {
	char type;
	int x;
	int y;
	char *shape;
	struct tagBullet *NextBullet;
}BULLET;

typedef struct tagBulletList {
	BULLET *HeadBullet;
	BULLET *TailBullet;
}BLIST;

#endif