#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printArray(char * a[], int size) {
	/*
	TAGS: PRINT, ARRAY, VETOR
	COMO USAR:
	    - Mudar o tipo do vetor nos argumentos.
	    - Mudar os printfs para o tipo correto.
	    - Usar.
	EXEMPLOS:
	    - String:
	        -Arg = "printArray(char * a[], int size)"
	        -Printf = "....printf("%s"...."
	    - Int:
	        -Arg = "printArray(int a[], int size)"
	        -Printf = "....printf("%d"...."
	    - Float:
	        -Arg = "printArray(float a[], int size)"
	        -Printf = "....printf("%.2f"...."
	FORMATO DE OUTPUT:
	    - {0, 1, 2, 3, 4, 5, 6} -> [0, 1, 2, 3, 4, 5, 6]
	    - {"hello", "world", "this", "is", "your", "captain"} -> [hello, world, this, is, your, captain]
	    - {0.6, 0.9, 1.2, 1.5} -> [0.60, 0.90, 1.20, 1.50]
	EXTRA:
	    - Voce pode ainda customizar:
	        - {}, (), <>, ao inves de []
	        - Elementos aparecerem entre aspas: ..."%s"... -> ..."\"%s\""...
	 */
	if (size > 0) {
		printf("\n[");
		printf("%s", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %s", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void fact(int n) {
	/*
	TAGS: FATORIAL, RECURSAO
	COMO FUNCIONA:
	    - Se o n for menor que 2 (0 ou 1) o fatorial e 1.
	    - Se nao, o fatorial e n multiplicado por n-1.
	 */
	return n < 2 ? 1 : n * fact(n - 1);
}