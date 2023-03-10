#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define M 5

/* formirati kvadratnu matricu popunjenu
brojevima tako da sume svih redaka i stupaca
i obiju dijagonala budu međusobno jednake*/

int main(void) {
	
	int i, j, n;

	int niz[2 * M - 1][2 * M - 1];

	if (niz == NULL) {
		printf("Memroija nije alocirana\n");
		exit(0);
	}
	
	for (i = 0; i < (2 * M - 1); i++) {
		for (j = 0; j < (2 * M - 1); j++) {
			niz[i][j] = 0;
		}
	}

	// pocni od srednjeg reda
	i = M - 1;
	//pocni od prvog stupca
	j = 0;
	n = 1;

	// popunjavanje
	while (n <= (M * M)) {
		niz[i][j] = n;
		i--;
		j++;
		n++;

		if ((n - 1) % M == 0) {
			i += M + 1;
			j -= M - 1;
		}
	}

	// dolje

	for (i = 0; i < (M / 2); i++) {
		for (j = 0; j < (M * 2 - 1); j++) {
			if (niz[i][j] != 0) {
				niz[i + M][j] = niz[i][j];
			}
		}
	}

	// lijevo

	for (i = 0; i < (M * 2 - 1); i++) {
		for (j = 0; j < (M / 2); j++) {
			if (niz[i][j] != 0) {
				niz[i][j + M] = niz[i][j];
			}
		}
	}

	// desno

	for (i = 0; i < (M * 2 - 1); i++) {
		for (j = (3 * M) / 2; j < (M * 2 - 1); j++) {
			if (niz[i][j] != 0) {
				niz[i][j - M] = niz[i][j];
			}
		}
	}

	// gore 

	for (i = (3 * M) / 2; i < (M * 2 - 1); i++) {
		for (j = 0; j < (M * 2 - 1); j++) {
			if (niz[i][j] != 0) {
				niz[i - M][j] = niz[i][j];
			}
		}
	}

	// printanje cijele matrice
	for (i = 0; i < (2 * M - 1); i++) {
		for (j = 0; j < (2 * M - 1); j++) {
			printf("%d ", niz[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	//printanje M * M matrice
	for (i = (M / 2); i < M + (M / 2); i++) {
		for (j = (M / 2); j < M + (M / 2); j++) {
			printf("%d ", niz[i][j]);
		}

		printf("\n");
	}

	return 0;
}