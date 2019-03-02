#include "Enemy.h"

ENEMY* CreateEnemy(int gate) {
	ENEMY *NewEnemy = (ENEMY*)malloc(sizeof(ENEMY));

	NewEnemy->type = 'e';
	NewEnemy->x = gate;
	NewEnemy->y = 2;
	NewEnemy->shape = "¥ø";
	NewEnemy->NextEnemy = NULL;

	return NewEnemy;
}

void FreqDown() {
	FREQ_E_PE -= 10;
	FREQ_E_AS -= 10;
}

void FreqReset() {
	FREQ_E_PE = 50;
	FREQ_E_AS = 60;
}