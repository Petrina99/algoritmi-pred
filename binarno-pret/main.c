#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

	int* niz;

	int n, i, j;

	srand((unsigned)time(NULL));

	printf("Unesite broj elemenata: ");
	scanf("%d", &n);

	niz = (int*)malloc(n * sizeof(int));

	// ovo za testiranje koristimo
	//int niz[] = { 50, 25, 66, 13, 56, 26, 99 };

	if (niz == NULL) {
		printf("Memroija nije alocirana\n");
		exit(0);
	}

	for (i = 0; i < n; i++) {
		niz[i] = rand() % 1000;
	}

	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			temp = 0;
			if (niz[i] > niz[j]) {
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

	int trazeniBroj;

	printf("Unesite broj koji trazite: ");
	scanf("%d", &trazeniBroj);

	int dg = 0, gg = n - 1, sredina;

	while (gg >= dg) {
		sredina = (gg + dg) / 2;

		if (niz[sredina] == trazeniBroj) {
			printf("Pronaden broj na %d. mjestu.", sredina + 1);
			break;
		}

		if (trazeniBroj > niz[sredina]) {
			dg = sredina + 1;
		}

		if (trazeniBroj < niz[sredina]) {
			gg = sredina - 1;
		}

		if (dg > gg) {
			printf("Trazeni broj ne postoji u nizu.");
			break;
		}
	}

	return 0;
}
