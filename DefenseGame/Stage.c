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

void PrintCharator(void *Node, int exist, const char type) {
	switch (type) {
	case 'b':
		gotoxy(((BULLET*)Node)->x * 2, ((BULLET*)Node)->y);
		if (exist != 0) printf("%s", ((BULLET*)Node)->shape);
		else printf("  ");
		break;
	case 'e':
		gotoxy(((ENEMY*)Node)->x * 2, ((ENEMY*)Node)->y);
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


