#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


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

int main(){
	ex2();
	return 0;
}
