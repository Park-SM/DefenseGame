#include "Stage.h"

void HideCursors() {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 2;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
	COORD cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void PrintGameDisplay() {
	puts("");
	puts("  ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì     [Game Information]");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì      - Kill :           ");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì      - Score:           ");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì      - Heart: ¢¾  ¢¾  ¢¾ ");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì      - Level: ");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì     [Game Control Key]");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì      - SpaceBar : Fire");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì      - ¡ç    ¡æ : Shift Cursor");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¦¢   ¢Ì");
	puts("  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì");
	puts("  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì  ¢Ì");
	puts("  ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
	puts("  ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
	puts("  ¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì");
}

void PrintCharator(void *Node, int exist, const char type) {
	switch (type) {
	case 'b':
		gotoxy((((BULLET*)Node)->x + 1) * 4, ((BULLET*)Node)->y);
		if (exist != 0) printf("%s", ((BULLET*)Node)->shape);
		else printf("  ");
		break;
	case 'e':
		gotoxy((((ENEMY*)Node)->x + 1) * 4, ((ENEMY*)Node)->y);
		if (exist != 0) printf("%s", ((ENEMY*)Node)->shape);
		else printf("  ");
		break;
	case 'c':
		gotoxy(((CURSOR*)Node)->x, ((CURSOR*)Node)->y);
		if (exist != 0) printf("%s", ((CURSOR*)Node)->shape);
		else printf("  ");
		break;
	default:
		break;
	}
}

void PrintGameInfo(enum gInfoType type) {
	int i;
	switch (type) {
	case 0:
		gotoxy(79, 4); printf("%d", gInfo.kill);
		break;
	case 1:
		gotoxy(79, 5); printf("%d", gInfo.Score);
		break;
	case 2:
		gotoxy(79, 6); printf("          ");
		gotoxy(79, 6); for (i = 0; i < gInfo.Heart; i++) printf("¢¾ ");
		break;
	case 3:
		gotoxy(79, 7); printf("%d", gInfo.Level);
		break;
	case 4:
		gotoxy(79, 4); printf("%d", gInfo.kill);
		gotoxy(79, 5); printf("%d", gInfo.Score);
		gotoxy(79, 6); printf("          ");
		gotoxy(79, 6); for (i = 0; i < gInfo.Heart; i++) printf("¢¾ ");
		gotoxy(79, 7); printf("%d", gInfo.Level);
		break;
	default:
		break;
	}
}

int UpdateScoreOrHeart(int collision_y, enum gINfoType type) {
	
	if (type == Score) {
		int i;
		gInfo.kill++;
		gInfo.Score += (collision_y - 2) * 11;
		if (gInfo.kill == 25 || gInfo.kill == 50 || gInfo.kill == 100 || gInfo.kill == 150) {
			gInfo.Level++;
			return 2;
		} else {
			PrintGameInfo(Kill);
			PrintGameInfo(Score);
		}
	} else if (type == Heart) {
		gInfo.Heart--;
		PrintGameInfo(type);
		if (gInfo.Heart == 0) return 1;
	}
	return 0;
}

void LevelUp() {
	gotoxy(18, 11); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
	gotoxy(18, 12); printf("¦¢     L e v e l  U p !!     ¦¢");
	gotoxy(18, 13); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
	Sleep(2000);
	system("cls");
	PrintGameDisplay();
	PrintGameInfo(All);
}

int TheEnd() {
	char key;
	int i, j;
	for (i = 2; i < 24; i++) {
		gotoxy(4, i);
		for (j = 0; j < 30; j++) {
			printf("¢Ì");
			Sleep(3);
		}
	}
	Sleep(100);
	gotoxy(18, 11); printf("                             ");
	gotoxy(18, 12); printf("     G a m e  O v e r !!     ");
	gotoxy(18, 13); printf("     Restart: R  Exit: E     ");
	gotoxy(18, 14); printf("                             ");

	while (1) {
		key = _getch();
		if (key == 'r' || key == 'R') {
			gInfo.kill = 0;
			gInfo.Score = 0;
			gInfo.Heart = 3;
			gInfo.Level = 1;

			system("cls");
			PrintGameDisplay();
			PrintGameInfo(All);
			return 1;
		} else if (key == 'e' || key == 'E') return 2;
	}

	return 0;
}