#ifndef _STAGE_H_
#define _STAGE_H_

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "List.h"

#define LEFT 75
#define RIGHT 77
#define SPACE 32

enum gInfoType { Kill, Score, Heart, Level, All };

typedef struct tagGameInformation {
	int kill;
	int Score;
	int Heart;
	int Level;
}GINFO;

static GINFO gInfo = { 0, 0, 3, 1 };

typedef struct tagCursor {
	int x;
	int y;
	char *shape;
}CURSOR;

void HideCursors();
void gotoxy(int x, int y);
void PrintGameDisplay();
void PrintCharator(void *Node, int exist, const char type);
void PrintGameInfo(enum gInfoType type);
int UpdateScoreOrHeart(int collision_y, enum gINfoType type);
int TheEnd();

#endif