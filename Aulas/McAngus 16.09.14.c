#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

void printString(char * a[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%s", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %s", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

void printArray(int a[], int size) {
	if (size > 0) {
		printf("\n[");
		printf("%d", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %d", a[i]);
		printf("]\n");
	} else printf("\n[]\n");
}

int findElem(char a[], int size, char elem){
	for (int i = 0; i < size; i++)
        if (a[i] == elem) return i;
        return -1;
}

void randNum(int arr[], int size, int max, int min){
	srand(time(NULL));
	max -= min;
	for (int k = size - 1; k>=0; k--)
		arr[k] = rand() % max + min;
}

void charIn(char * arr, int arrSize){
	fgets(arr, arrSize, stdin);
}

void ex1(){
	for(int k = 0; k<255; k++){
		printf("||  %-3c||   %-6d||\n", k, k);
	}
}

void ex2(){
	char test[100];
	printf("Digite uma frase: ");
	fgets(test, 100, stdin);
	test[strlen(test)-1] = '\0';
	printf("%s.", test);
}

void ex3(){
	char phrase[30];
	printf("Type a phrase: ");
	fgets(phrase, 30, stdin);
	phrase[strlen(phrase) - 1] = phrase[strlen(phrase)];
	system("clear");
	for (int k = 0; k<strlen(phrase); k++){
		printf("||  %c  ||  %d  ||  %d ||\n", phrase[k], k, (int)phrase[k]);
	}
}

void ex4(){
	int MAX_SIZE = 256;
	char *phrase = malloc(MAX_SIZE), alone;
	printf("Digita uma frase: ");
	charIn(phrase, MAX_SIZE);
	printf("O que deseja procurar: ");
	charIn(&alone, 1);
	findElem(phrase, MAX_SIZE, alone);

}

int main(){
	setlocale(LC_ALL, "");
	ex4();
}
