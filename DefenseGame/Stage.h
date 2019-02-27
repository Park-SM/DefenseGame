#ifndef _STAGE_H_
#define _STAGE_H_

#define LEFT 75
#define RIGHT 77
#define SPACE 32

#include <stdio.h>
#include <Windows.h>
#include "List.h"

typedef struct tagCursor {
	int x;
	int y;
	char *shape;
}CURSOR;

void HideCursors();
void gotoxy(int x, int y);
void PrintCharator(void *Node, int exist, const char type);

#endif