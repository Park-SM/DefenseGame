#include "List.h"

HASHLIST* CreateHashList() {
	HASHLIST *nHashList = (HASHLIST*)calloc(1, sizeof(HASHLIST));
	return nHashList;
}

int AppendNode(HASHLIST *hList, int index, void* NewNode) {		// If successful, the return value is 1.
	if (*((char*)NewNode) == 'b') {
		if (hList->BulletGate[index] == NULL) hList->BulletGate[((BULLET*)NewNode)->x] = (BULLET*)NewNode;
		else hList->TailBullet[index]->NextBullet = (BULLET*)NewNode;
		hList->TailBullet[index] = (BULLET*)NewNode;		// Updates the address of the tail node.

	} else if (*((char*)NewNode) == 'e') {
		if (hList->EnemyGate[index] == NULL) hList->EnemyGate[((ENEMY*)NewNode)->x] = (ENEMY*)NewNode;
		else hList->TailEnemy[index]->NextEnemy = (ENEMY*)NewNode;
		hList->TailEnemy[index] = (ENEMY*)NewNode;		// Updates the address of the tail node.

	} else return 0;

	return 1;
}

void ShiftNode(HASHLIST *hList, const char type) {
	if (type == 'b') {
		int i;
		for (i = 0; i < 15; i++) {
			if (hList->BulletGate[i] != NULL) {
				BULLET *Current = hList->BulletGate[i];
				while (Current != NULL) {
					if (--(Current->y) < 1) {
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
						Current = hList->EnemyGate[i];
					} else Current = Current->NextEnemy;
				}
			}
		}
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