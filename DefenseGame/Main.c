#include "Bullet.h"
#include "Enemy.h"
#include "List.h"
#include "Stage.h"

int main() {

	char key;
	int Frame_PrintBullet = FREQ_B_PB;
	int Frame_PrintEnemy = FREQ_E_PE;
	int Frame_AppearEnemy = FREQ_E_AS;
	CURSOR Cur = { 4, 23, "бу" };
	HASHLIST *hList = CreateHashList();

	srand((unsigned int)time(NULL));
	HideCursors();
	PrintGameDisplay();
	PrintGameInfo(All);
	PrintCharator(&Cur, 1, 'c');

	while (1) {

		if (--Frame_PrintBullet == 0) {
			PrintHashList(hList, 0, 'b');
			if (ShiftNode(hList, 'b') == 2) {
				LevelUp();
				DeleteAllList(hList, 15);
				FREQ_E_PE -= 10;
				FREQ_E_AS -= 10;
			}
			PrintHashList(hList, 1, 'b');
			Frame_PrintBullet = FREQ_B_PB;
		}

		if (--Frame_PrintEnemy == 0) {
			PrintHashList(hList, 0, 'e');
			if (ShiftNode(hList, 'e')) {
				if (TheEnd() == 1) {
					FREQ_E_PE = 50;
					FREQ_E_AS = 60;
					DeleteAllList(hList, 15);
				} else return 0;
			}
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
				if (Cur.x > 4) {
					PrintCharator(&Cur, 0, 'c');
					Cur.x -= 4;
					PrintCharator(&Cur, 1, 'c');
				}
				break;

			case RIGHT:
				if (Cur.x < 58) {
					PrintCharator(&Cur, 0, 'c');
					Cur.x += 4;
					PrintCharator(&Cur, 1, 'c');
				}
				break;

			case SPACE:
				AppendNode(hList, (Cur.x / 4) - 1, CreateBullet((Cur.x / 4) - 1));
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