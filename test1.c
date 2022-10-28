#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

#pragma warning(disable:4996)

#define MAXH 22
#define MAXW 45

int map[MAXH][MAXW];
int locH = 15;
int locW = 15;
int item = 2;

void move(key) {
	if (locH != 1 && key == 119 && map[locH - 1][locW] == 0) {
		locH--;
		map[locH +1][locW] = 0;
		return;
	}
	else if (locH != MAXH && key == 115 && map[locH + 1][locW] == 0) {
		locH++;
		map[locH - 1][locW] = 0;
		return;
	}
	else if (locW != 1 && key == 97 && map[locH][locW - 1] == 0) {
		locW--;
		map[locH][locW + 1] = 0;
		return;
	}
	else if (locW != MAXW && key == 100 && map[locH][locW + 1] == 0) {
		locW++;
		map[locH][locW - 1] = 0;
		return;
	}
}

void placeBlock(key) {
	
	if (key == 105) {
		if (map[locH - 1][locW] != 0) {
			map[locH - 1][locW] = 0;
		}
		else {
			if(item == 2) map[locH - 1][locW] = 2;
			else if (item == 3) map[locH - 1][locW] = 3;
			else if (item == 4) map[locH - 1][locW] = 4;
		}
		return;
	}
	else if (key == 107) {
		if (map[locH + 1][locW] != 0) {
			map[locH + 1][locW] = 0;
		}
		else {
			if (item == 2) map[locH + 1][locW] = 2;
			else if (item == 3) map[locH + 1][locW] = 3;
			else if (item == 4) map[locH + 1][locW] = 4;
		}
		return;
	}
	else if (key == 106) {
		if (map[locH][locW - 1] != 0) {
			map[locH][locW - 1] = 0;
		}
		else {
			if (item == 2) map[locH][locW - 1] = 2;
			else if (item == 3) map[locH][locW - 1] = 3;
			else if (item == 4) map[locH][locW - 1] = 4;
		}
		return;
	}
	else if (key == 108) {
		if (map[locH][locW + 1] != 0) {
			map[locH][locW + 1] = 0;
		}
		else {
			if (item == 2) map[locH][locW + 1] = 2;
			else if (item == 3) map[locH][locW + 1] = 3;
			else if (item == 4) map[locH][locW + 1] = 4;
		}
		return;
	}
}

void prtScreen() {
	system("cls");
	printf("(%d/%d, %d/%d)\n", locH, MAXH, locW, MAXW);
	for (int a = 0; a < MAXH; a++) {
		for (int b = 0; b < MAXW; b++) {
			if (map[a][b] == 1) {
				printf("¡Ü");
			}
			else if (map[a][b] == 2) {
				printf("¢Ì");
			}
			else if (map[a][b] == 3) {
				printf("¢Ã");
			}
			else if (map[a][b] == 4) {
				printf("¢À");
			}
			else if (map[a][b] == 0){
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("Current Item : ");
	if (item == 2) printf("¢Ì(Stone)\n");
	else if (item == 3) printf("¢Ã(Iron)\n");
	else if (item == 4) printf("¢À(tree)\n");
	printf("Press E to change Item");
	return;
}

int main(void) {
	int key;

	printf("Move : W, A, S, D\n");
	printf("Place Blocks : I, J, K, L\n");
	printf("Change Block : E\n");
	printf("Press Any Key to Start.");

	_getch();

	for (int a = 0; a < MAXH; a++) {
		for (int b = 0; b < MAXW; b++) {
			map[a][b] = 0;
		}
	}
	
	while(1){
		map[locH][locW] = 1;
		prtScreen();
		key = _getch();
		if (key == 101) {
			item++;
			if (item > 4) {
				item = 2;
			}
		}
		else if(key == 97 || key == 100 || key == 115 || key == 119) move(key);
		else if(key == 105 || key == 106 || key == 107 || key == 108) placeBlock(key);
	}
	
	

	return 0;
}