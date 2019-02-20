#include "List.h"

HASHLIST* CreateHashList() {
	HASHLIST *nHashList = (HASHLIST*)calloc(1, sizeof(HASHLIST));

	return nHashList;
}

int AppendNode(HASHLIST *hList, void* NewNode) {		// If successful, the return value is 1.
	if (*((char*)NewNode) == 'b') {
		if (hList->BulletGate[((BULLET*)NewNode)->x] == NULL) {
			hList->BulletGate[((BULLET*)NewNode)->x] = (BULLET*)NewNode;
		} else
			hList->TailBullet[((BULLET*)NewNode)->x]->NextBullet = (BULLET*)NewNode;

		hList->TailBullet[((BULLET*)NewNode)->x] = NewNode;		// Updates the address of the tail node.

	} else if (*((char*)NewNode) == 'e') {
		if (hList->EnemyGate[((ENEMY*)NewNode)->x] == NULL) {
			hList->EnemyGate[((ENEMY*)NewNode)->x] = (ENEMY*)NewNode;
		} else 
			hList->TailBullet[((ENEMY*)NewNode)->x]->NextBullet = (ENEMY*)NewNode;
		
		hList->TailBullet[((ENEMY*)NewNode)->x] = NewNode;		// Updates the address of the tail node.

	} else return 0;

	return 1;
}