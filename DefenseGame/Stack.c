#include "Stack.h"

HASHSTACK* CreateHashStack() {
	HASHSTACK *nHashStack = (HASHSTACK*)calloc(1, sizeof(HASHSTACK));
	return nHashStack;
}

int AppendNode(HASHSTACK *hStack, void* NewNode) {		// If successful, the return value is 1.

	if (*((char*)NewNode) == 'b') {
		if (hStack->BulletGate[((BULLET*)NewNode)->x] == NULL)
			hStack->BulletGate[((BULLET*)NewNode)->x] = (BULLET*)NewNode;
		else {
			((BULLET*)NewNode)->NextBullet = hStack->BulletGate[((BULLET*)NewNode)->x];
			hStack->BulletGate[((BULLET*)NewNode)->x] = (BULLET*)NewNode;
		}
	}
	else if (*((char*)NewNode) == 'e') {
		if (hStack->EnemyGate[((ENEMY*)NewNode)->x] == NULL)
			hStack->EnemyGate[((ENEMY*)NewNode)->x] = (ENEMY*)NewNode;
		else {
			((ENEMY*)NewNode)->NextEnemy = hStack->EnemyGate[((ENEMY*)NewNode)->x];
			hStack->EnemyGate[((ENEMY*)NewNode)->x] = (ENEMY*)NewNode;
		}
	}
	else return 0;

	return 1;
}