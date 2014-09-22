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
int fact(int n){
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
TAGS: MERGE, SORT
COMO FUNCIONA:
	- Divide a array em arrays menores ate chegar em arrays unitarias depois junta todas de maneira ordenada
	
COMO USAR:
	- Somente implantar no algoritimo.
	- Para ordenar basta usar a funcao mergeSort(arr[], arrSize[]).

OBS:
	- Este algoritimo realiza a mesma coisa que bubbleSorte e selectionSort, a diferenca e que algo que o bubbleSorte demoraria cerca de 30 segundos para realizar por este algoritimo demora 4, ou seja, e muito mais veloz.
*/
void merge(int vec[], int vecSize) {
  int mid;
  int i, j, k;
  int* tmp;
 
  tmp = (int*) malloc(vecSize * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = vecSize / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    if (vec[i] <= vec[j]) {
      tmp[k] = vec[i++];
    }
    else {
      tmp[k] = vec[j++];
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < vecSize) {
      tmp[k++] = vec[j++];
    }
  }
  else {
    while (i < mid) {
      tmp[k++] = vec[i++];
 
    }
  }
 
  for (i = 0; i < vecSize; ++i) {
    vec[i] = tmp[i];
  }
 
  free(tmp);
}
 
void mergeSort(int vec[], int vecSize) {
  int mid;
 
  if (vecSize > 1) {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }
}

/*
TAGS: ARRAYS, COPIAR
COMO FUNCIONA:
	- Copia os valores de uma arrA[], para uma arrB[].
	
COMO USAR:
	- Traducao das entradas:
		- int in[] // Array de entrada (De onde sera copiada os dados).
		- int inSize // Tamanho da array de entrada. 
		- int out[] // Array de saida (Para onde os dados serao copiados)

OBS:
	- Este algoritimo so copia dados de arrays de mesmo tamanho.
*/
void copyArray(int in[], int inSize, int out[]){
		for(int k = 0; k < inSize; k++)
			out[k] = in[k];
}
