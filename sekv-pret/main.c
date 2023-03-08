#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sekvencijalno(int, int[], int);

int main(void) {

	int* niz;

	int n, i;

	srand((unsigned)time(NULL));

	printf("Unesite broj elemenata: ");
	scanf("%d", &n);

	niz = (int*)malloc(n * sizeof(int));

	if (niz == NULL) {
		printf("Memroija nije alocirana\n");
		exit(0);
	}

	for (i = 0; i < n; i++) {
		niz[i] = rand() % 1000;
	}

	int trazeniBroj;

	printf("Unesite broj koji trazite: ");
	scanf("%d", &trazeniBroj);

	// int test[5] = { 5, 15, 25, 35, 54 };
	sekvencijalno(trazeniBroj, niz, n);

	return 0;
}

// x = trazeni broj, niz, velicina niza
void sekvencijalno(int x, int niz[], int n) {
	int pronaden = 0;

	for (int i = 0; i < n; i++) {
		if (niz[i] == x) {
			printf("Trazeni broj nalazi se na %d. mjestu.", i + 1);
			pronaden = 1;
			break;
		}
	}

	if (pronaden == 0) { printf("Nije pronaden trazeni broj"); }
	
}