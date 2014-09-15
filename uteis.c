#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
void printArray(char * a[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%s", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %s", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

/*
TAGS: FATORIAL, RECURSAO
COMO FUNCIONA:
    - Se o n for menor que 2 (0 ou 1) o fatorial e 1.
    - Se nao, o fatorial e n multiplicado por n-1.
 */
void fact(int n) {
	return n < 2 ? 1 : n * fact(n - 1);
}

/*
TAGS: ARRAYS, ORDENAR
COMO FUNCIONA:
    - Compara o proximo termo da sequencia com o anterior, se for maior troca colocando em ordem crescente.
    
COMO USAR:
    - Mudar o tipo do vetor no argumento principal.
    - Usar.
    
OBS:
    - Para ordenar em ordem decrescente o seu vetor basta trocar o sinal > na comparacao do if por <.
*/
void bubble(int arr[], int size){
	int temp;
	for (int k = size; k >  0; k--){
		for (int j = 0; j < k; j++){
			if (arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
/*
TAGS: ARRAYS, VETOR, ORDENAR
COMO FUNCIONA:
    - Compara o segundo termo da vetor com o primeiro e se for troca.
    
COMO USAR:
    - Apenas implantar no algoritimo.
*/
void selection(int arr[], int arrSize){
	for(int i=0; i<arrSize-1; i++){
		int min = i;
		for(int k=(i+1); k<arrSize; k++){
			if(arr[k]<arr[min])
				min=k;
		}
		if (min != i){
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

/*
TAGS: ARRAYS, VETOR,GERAR NUMEROS
COMO FUNCIONA:
    - Usa a funcao rand(), da biblioteca time.h, para gerar valores aleatorios para o vetor.

COMO USAR:
    - Somente implantar no algoritimo.
   
OBS:
    - Para utilizar este algoritimo voce precisa incluir a biblioteca time.h junto a outras bibliotecas (#include)
   
Exemplos:
    
    - Gerar numeros de 1000 a 10000: randNum(arr, arrSize, 1000, 10000);
*/
void randNum(int arr[], int size, int max, int min){
	srand(time(NULL));
	max -= min;
	for (int k = size - 1; k>=0; k--)
		arr[k] = rand() % max + min;
}

/*
TAGS: ARRAY, VETOR, SPLIT, DIVIDIR, CORTAR
COMO FUNCIONA:
    - Divide o vetor entrada <in> de tamanho <size> em dois outros <outa,outb> no ponto <pivot>.
    
COMO USAR:
    - Copiar, colar, usar.

Exemplos:
    - int in = {1, 2, 3, 4, 5, 6, 7}, outa, outb;
    - splitArray(in, 7, 3, outa, outb);
    - Output:
    	- outa = {1, 2, 3}
    	- outb = {4, 5, 6, 7}
*/
void splitArray(int *in, int size, int pivot, int *outa, int *outb){
	int i;
	outa = (int*) realloc(outa, pivot);
	outb = (int*) realloc(outb, size - pivot);
	for (i = 0; i < pivot; i++)
		outa[i] = in[i];
	for (i = 0; i < size - pivot; i++)
		outb[i] = in[i+pivot];
}

/*
TAGS: ARRAY, VETOR, TROCAR, SWAP
COMO FUNCIONA:
    - Troca dois elementos de lugar num vetor.
    
COMO USAR:
    - Copiar, colar, usar.

Exemplos:
    - int in = {1, 2, 3, 4, 5, 6, 7};
    - swap(in, 5, 3);
    - Output:
    	- in = {1, 2, 3, 6, 5, 4, 7}
*/
void swap(int *arr, int ia, int ib){
    int aux = arr[ib];
    arr[ib] = arr[ia];
    arr[ia] = aux;
}

/*
TAGS: ARRAY, VETOR, FIND, PROCURA
COMO FUNCIONA:
    - Procura um elemento no intervalo [0,size) do array. Retorna <index> do elemento se encontrar e -1 se nao.
    
COMO USAR:
    - Copiar, colar, usar.

Exemplos:
    - int in = {1, 2, 3, 4, 5, 6, 7};
    - findElem(in, 7, 5);
    - findElem(in, 3, 5);
    - Output:
    	- 4
    	- -1
*/
int findElem(int a[], int size, int elem){
    for (int i = 0; i < size; i++)
        if (a[i] == elem) return i;
    return -1;
}

/*
TAGS: ARRAY, VETOR, SORT, INSERTION, ORDENACAO
COMO FUNCIONA:
    - Ordena o vetor usando o metodo insertion.
    
COMO USAR:
    - Copiar, colar, usar.

Exemplos:
    - int in = {6, 3, 1, 4, 2, 9, 7};
    - insertionSort(in, 7);
    - Output:
    	- in = {1, 2, 3, 4, 6, 7, 9}
*/
void insertionSort(int *arr, int size){
    for (int i = 0; i < size; i++)
        for (int k = i; k > 0; k--)
            if (arr[k] < arr[k-1])
                swap(arr, k, k-1);
}

