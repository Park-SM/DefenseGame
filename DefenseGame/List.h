#ifndef _LIST_H_
#define _LIST_H_

#include "Bullet.h"
#include "Enemy.h"
#include "Stage.h"

typedef struct tagHashList {
	BULLET *BulletGate[15];
	ENEMY *EnemyGate[15];
	BULLET *TailBullet[15];		// Maintains the address of the tail node.
	ENEMY *TailEnemy[15];			// Maintains the address of the tail node.
}HASHLIST;

HASHLIST* CreateHashList();
int AppendNode(HASHLIST *hList, int index, void* NewNode);
void ShiftNode(HASHLIST *hList, const char type);
void DeleteHeadNode(HASHLIST *hList, int index, const char type);
void PrintHashList(HASHLIST *hList, int exist, const char type);

#endif