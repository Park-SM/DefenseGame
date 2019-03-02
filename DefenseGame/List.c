#include "List.h"

HASHLIST* CreateHashList() {
	HASHLIST *nHashList = (HASHLIST*)calloc(1, sizeof(HASHLIST));
	return nHashList;
}

int AppendNode(HASHLIST *hList, int index, void *NewNode) {		// If successful, the return value is 1.
	if (*((char*)NewNode) == 'b') {
		if (hList->BulletGate[index] == NULL) hList->BulletGate[index] = (BULLET*)NewNode;
		else hList->TailBullet[index]->NextBullet = (BULLET*)NewNode;
		hList->TailBullet[index] = (BULLET*)NewNode;		// Updates the address of the tail node.

	} else if (*((char*)NewNode) == 'e') {
		if (hList->EnemyGate[((ENEMY*)NewNode)->x] == NULL) hList->EnemyGate[((ENEMY*)NewNode)->x] = (ENEMY*)NewNode;
		else hList->TailEnemy[((ENEMY*)NewNode)->x]->NextEnemy = (ENEMY*)NewNode;
		hList->TailEnemy[((ENEMY*)NewNode)->x] = (ENEMY*)NewNode;		// Updates the address of the tail node.

	} else return 0;

	return 1;
}

int ShiftNode(HASHLIST *hList, const char type) {
	if (type == 'b') {
		int i;
		for (i = 0; i < 15; i++) {
			if (hList->BulletGate[i] != NULL) {
				BULLET *Current = hList->BulletGate[i];
				while (Current != NULL) {
					if (CollisionCheck(hList, i) != 0) {
						Current = hList->BulletGate[i];
					} else if (--(Current->y) < 2) {
						DeleteHeadNode(hList, i, 'b');
						Current = hList->BulletGate[i];
					} else Current = Current->NextBullet;
				}
			}
		}

	} else if (type == 'e') {
		int i;
		for (i = 0; i < 15; i++) {
			if (hList->EnemyGate[i] != NULL) {
				ENEMY *Current = hList->EnemyGate[i];
				while (Current != NULL) {
					if (++(Current->y) > 23) {
						DeleteHeadNode(hList, i, 'e');
						if (UpdateScoreOrHeart(Current->y, Heart)) return 1;
						Current = hList->EnemyGate[i];
					} else Current = Current->NextEnemy;
				}
			}
		}
	}
	return 0;
}

void DeleteAllNode(void *Node) {
	if (Node != NULL && *((char*)Node) == 'b') {
		if (((BULLET*)Node)->NextBullet != NULL) DeleteAllNode(((BULLET*)Node)->NextBullet);
		free((BULLET*)Node);
	} else if (Node != NULL && *((char*)Node) == 'e') {
		if (((ENEMY*)Node)->NextEnemy != NULL) DeleteAllNode(((ENEMY*)Node)->NextEnemy);
		free((ENEMY*)Node);
	}
}

void DeleteAllList(HASHLIST *hList, int capacity) {
	int i;
	for (i = 0; i < capacity; i++) {
		DeleteAllNode(hList->BulletGate[i]);
		hList->BulletGate[i] = NULL;
	}
	for (i = 0; i < capacity; i++) {
		DeleteAllNode(hList->EnemyGate[i]);
		hList->EnemyGate[i] = NULL;
	}
}

void DeleteHeadNode(HASHLIST *hList, int index, const char type) {
	if (type == 'b') {
		if (hList->BulletGate[index] != NULL) {
			BULLET *Temp = hList->BulletGate[index];
			hList->BulletGate[index] = hList->BulletGate[index]->NextBullet;
			free(Temp);
			if (hList->BulletGate[index] == NULL) hList->TailBullet[index] = NULL;
		}

	} else if (type == 'e') {
		if (hList->EnemyGate[index] != NULL) {
			ENEMY *Temp = hList->EnemyGate[index];
			hList->EnemyGate[index] = hList->EnemyGate[index]->NextEnemy;
			free(Temp);
			if (hList->EnemyGate[index] == NULL) hList->TailEnemy[index] = NULL;
		}
	}
}

void PrintHashList(HASHLIST *hList, int exist, const char type) {
	if (type == 'b') {
		int i;
		for (i = 0; i < 15; i++) {
			if (hList->BulletGate[i] != NULL) {
				BULLET *Current = hList->BulletGate[i];
				while (Current != NULL) {
					PrintCharator(Current, exist, 'b');
					Current = Current->NextBullet;
				}
				
			}
		}
	} else if (type == 'e') {
		int i;
		for (i = 0; i < 15; i++) {
			if (hList->EnemyGate[i] != NULL) {
				ENEMY *Current = hList->EnemyGate[i];
				while (Current != NULL) {
					PrintCharator(Current, exist, 'e');
					Current = Current->NextEnemy;
				}
			}
		}
	}
}

int CollisionCheck(HASHLIST *hList, int index) {
	if (hList->BulletGate[index] != NULL && hList->EnemyGate[index] != NULL) {
		if (hList->BulletGate[index]->y < hList->EnemyGate[index]->y) {
			UpdateScoreOrHeart(hList->BulletGate[index]->y, Score);
			PrintCharator(hList->BulletGate[index], 0, 'b');
			DeleteHeadNode(hList, index, 'b');
			PrintCharator(hList->EnemyGate[index], 0, 'e');
			DeleteHeadNode(hList, index, 'e');
			return 1;
		}
	}
	return 0;
}