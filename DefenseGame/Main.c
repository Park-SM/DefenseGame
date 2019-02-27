#include <conio.h>
#include "Bullet.h"
#include "Enemy.h"
#include "List.h"
#include "Stage.h"

#define FREQ_F_PB 5

int main() {

	char key;
	int Frame_PrintBullet = FREQ_F_PB;
	CURSOR Cur = { 0, 23, "бу" };
	HASHLIST *hList = CreateHashList();

	HideCursors();
	PrintCharator(&Cur, 1, 'c');
	while (1) {

		if (--Frame_PrintBullet == 0) {
			PrintHashList(hList, 0, 'b');
			ShiftNode(hList, 'b');
			PrintHashList(hList, 1, 'b');
			Frame_PrintBullet = FREQ_F_PB;
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