#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "string.h"
#include <cmath>
#include <queue>

using namespace std;



int** createG(int size) {
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = ((int*)malloc(size * sizeof(int)));
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			G[i][j] = rand() % 2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void** printG(int** G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	return 0;
}


int** G = NULL, size = 5, vis[5] = { 0 };
void BFS(int **G, int size, int *vis, int s) {
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		s = q.front();
		printf("%d", s);
		q.pop();
		for (int i = 0; i < size; i++) {
			if (G[s][i] == 1 && vis[i] == 0) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}


int main() {
	int size = 0, s = 0, * vis;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("¬ведите начальную вершину: ");
	scanf("%d", &s);
	printf("¬ведите размер массива: ");
	scanf("%d", &size);

	vis = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) vis[i] = 0;
	G = createG(size);
	printG(G, size);
	BFS(G, size, vis, s);

	return 0;
}