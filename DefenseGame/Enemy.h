#ifndef _ENEMY_H_
#define _ENEMY_H_

typedef struct tagEnemy {
	char type;
	int x;
	int y;
	char *shape;
	struct tagEnemy *NextEnemy;
}ENEMY;


#endif