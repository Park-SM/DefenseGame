#include "Bullet.h"
#include "Enemy.h"
#include "List.h"

int main() {
	// Testing Code.. //
	HASHLIST *hList = CreateHashList();
	BULLET *NewNode = CreateBullet(5);
	BULLET *SecNode = CreateBullet(5);
	BULLET *ThiNode = CreateBullet(5);

	printf("%d.\n", AppendNode(hList, NewNode));
	printf("About NewNode: %p, %p\n", NewNode, hList->TailBullet[5]);

	printf("\n%d.\n", AppendNode(hList, SecNode));
	printf("About SecNode: %p, %p\n", SecNode, hList->BulletGate[5]->NextBullet);

	printf("\n%d.\n", AppendNode(hList, ThiNode));
	printf("About ThiNode: %p, %p\n", ThiNode, hList->TailBullet[5]);


	system("PAUSE");
	return 0;
}