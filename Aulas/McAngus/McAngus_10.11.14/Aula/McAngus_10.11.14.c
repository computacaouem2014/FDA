#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void ex1(){
	srand(time(NULL));
	FILE *aula;
	aula = fopen("aula.txt", "w+");
	for(int k = 0; k<10; k++) fprintf(aula, "I like %d peannuts.\n", rand()%6000);
	rewind(aula);
	char teste[10][25];
	for(int k = 0; k<10; k++){
		fgets(teste[k], 25, aula);
		printf("%s\n", teste[k]);
	}
	rewind(aula);
	int a;
	while(fscanf(aula, "%*s %*s %d %*s\n", &a) != EOF) printf("%d\n", a);
	fclose(aula);
}

void ex2(){
	FILE *linhas, *linhas2;
	linhas = fopen("linhas.txt", "r");
	linhas2 = fopen("linhas2.txt", "w+");
	char linha[50];
	while(fgets(linha, 50, linhas) != NULL){
		if(linha[0] != '#'){
			fprintf(linhas2, "%s", linha);
			printf("%s", linha);
		}
	} 
	fclose(linhas);
	fclose(linhas2);
}

void ex3(){
	FILE *linhas, *linhas2;
	linhas = fopen("linhas.txt", "r");
	linhas2 = fopen("linhas2.txt", "w+");
	char linha[50];
	while(fgets(linha, 50, linhas) != NULL){
		strtok(linha, "#\n");
		if(linha[0] != '#') fprintf(linhas2, "%s\n", linha);
	}
	fclose(linhas);
	fclose(linhas2);
}

void ex4(char *in, char *out){
	FILE *teste, *new;
	teste = fopen(in, "r");
	new = fopen(out, "w+");
	char *buffer = malloc(1024 * sizeof(char));
	while(fgets(buffer, 1024, teste) != NULL) fprintf(new, buffer);
	while(strcmp(buffer, "exit") != 0){
		printf("Digite o RA: ");
		fgets(buffer, 1024, stdin);
		fprintf(new, buffer);
		printf("Digite o NOME: ");
		fgets(buffer, 1024, stdin);
		fprintf(new, buffer);
	}
}

int main(){
	char *in = malloc(128 * sizeof(char)), *out = malloc(128 * sizeof(char));
	printf("Digite o nome do arquivo de alunos antigo: ");
	fgets(in, 128, stdin);
	strtok(in, "\n");
	printf("Digite o nome do arquivo de alunos novo: ");
	fgets(out, 128, stdin);
	strtok(out, "\n");
	ex4(in, out);
	return 0;
}
