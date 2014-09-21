#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100

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
        if (a[i] == elem)
		return i;
        return -1;
}

int countWord(char a[]){
	int count = 1;
	for (int i = 0; i < strlen(a) - 1; i++){
		if (a[i] == ' '){
			count++;
			if (a[i + 1] > 64 && a[i + 1] < 91 || a[i + 1] > 96 && a[i + 1] < 123 && a[i + 1] == 46)
				continue;
			else
				i++;
		}
	}
	return count;
}

void randNum(int arr[], int size, int max, int min){
	srand(time(NULL));
	max -= min;
	for (int k = size - 1; k>=0; k--)
		arr[k] = rand() % max + min;
}

void charIn(char *arr, int arrSize){
	fgets(arr, arrSize, stdin);
	if ((strlen(arr)>0) && (arr[strlen (arr) - 1] == '\n'))
        arr[strlen (arr) - 1] = '\0';
}

void palindrome(char *str){
	for (int k = strlen(str) - 1, j = 0; j < k / 2; j++){
		if (str[j] != str[k - j]){
			printf("A palavra %s nao e palindroma.", str);
			return;
		}
	}
	printf("A palavra %s e palindroma.", str);
}

void ex1(){
	char *name = malloc(MAX/2), *lastname = malloc(MAX/2);
	printf("Digite seu nome: ");	charIn(name, MAX/2);
	name[strlen(name)] = ' ';
	name[strlen(name) + 1] = '\0';
	printf("Digite seu sobrenome: ");	charIn(lastname, MAX/2);
	strcat(name, lastname);
	printf("%s", name);
}

void ex2(){
	char *str1 = malloc(MAX), *str2 = malloc(MAX);
	printf("Frase 1: ");
	charIn(str1, MAX);
	printf("Frase 2: ");
	charIn(str2, MAX);
	if (strcmp(str1, str2) != 0)
		printf("%s e diferente de %s.", str1, str2);
	else
		printf("%s e igual a %s.", str1, str2);

}

void ex3(){
	char *str1 = malloc(MAX);
	printf("Digite uma frase terminada com ponto final: ");
	charIn(str1, MAX);
	printf("A frase possui %d palavras.", countWord(str1));
}

void ex4(){
	char *word = malloc(MAX);
	printf("Digite uma palavra: ");
	charIn(word, MAX);
	palindrome(word);
}

int main(){
	ex4();
}
