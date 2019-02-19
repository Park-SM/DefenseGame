#ifndef _STACK_H_
#define _STACK_H_

#include "Bullet.h"
#include "Enemy.h"

typedef struct tagHashStack {
	BULLET *BulletGate[15];
	ENEMY *EnemyGate[15];
}HASHSTACK;

HASHSTACK* CreateHashStack();
int AppendNode(HASHSTACK *hStack, void* NewNode);

#endif