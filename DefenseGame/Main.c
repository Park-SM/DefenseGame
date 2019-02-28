#include <conio.h>
#include "Bullet.h"
#include "Enemy.h"
#include "List.h"
#include "Stage.h"

#define FREQ_B_PB 5

int main() {

	char key;
	int FREQ_E_PE = 100;
	int FREQ_E_AS = 120;
	int Frame_PrintBullet = FREQ_B_PB;
	int Frame_PrintEnemy = FREQ_E_PE;
	int Frame_AppearEnemy = FREQ_E_AS;
	CURSOR Cur = { 0, 23, "бу" };
	HASHLIST *hList = CreateHashList();

	srand((unsigned int)time(NULL));
	HideCursors();
	PrintCharator(&Cur, 1, 'c');

	while (1) {

		if (--Frame_PrintBullet == 0) {
			PrintHashList(hList, 0, 'b');
			ShiftNode(hList, 'b');
			PrintHashList(hList, 1, 'b');
			Frame_PrintBullet = FREQ_B_PB;
		}

		if (--Frame_PrintEnemy == 0) {
			PrintHashList(hList, 0, 'e');
			ShiftNode(hList, 'e');
			PrintHashList(hList, 1, 'e');
			Frame_PrintEnemy = FREQ_E_PE;
		}

		if (--Frame_AppearEnemy == 0) {
			AppendNode(hList, 0, CreateEnemy(rand() % 15));
			Frame_AppearEnemy = FREQ_E_AS;
		}

		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case LEFT:
				if (Cur.x > 1) {
					PrintCharator(&Cur, 0, 'c');
					Cur.x -= 2;
					PrintCharator(&Cur, 1, 'c');
				}
				break;

			case RIGHT:
				if (Cur.x < 27) {
					PrintCharator(&Cur, 0, 'c');
					Cur.x += 2;
					PrintCharator(&Cur, 1, 'c');
				}
				break;

			case SPACE:
				AppendNode(hList, Cur.x / 2, CreateBullet (Cur.x / 2));
				break;

			default:
				break;
			}
		}

		Sleep(10);
	}

	system("PAUSE");
	return 0;
}