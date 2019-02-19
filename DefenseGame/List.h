#ifndef _LIST_H_
#define _LIST_H_

#include "Bullet.h"
#include "Enemy.h"

typedef struct tagHashList {
	BULLET *BulletGate[15];
	ENEMY *EnemyGate[15];
	void *TailBullet[15];		// Maintains the address of the tail node.
	void *TailEnmey[15];			// Maintains the address of the tail node.
}HASHLIST;

HASHLIST* CreateHashList();
int AppendNode(HASHLIST *hList, void* NewNode);

#endif