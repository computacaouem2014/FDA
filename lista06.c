#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_PEOPLE 15
#define MIN_GRAUS 40
#define MAX_GRAUS 70

void ex1(){
	int x, y, soma=0, i;
	printf("Informe o primeiro numero: ");
	scanf("%d", &x);
	printf("Informe o segundo numero: ");
	scanf("%d", &y);
	if(x>y){
		// decrescente
		for(i=y; i<=x; i++){
			if(i%2==0) soma+=i;
		}
		printf("[Descrescente] Quantidade de numeros pares de %d ate %d: %d\n", x, y, soma);
	} else if(x<y) {
		// crescente
		for(i=x; i<=y; i++){
			soma+=i;
		}
		printf("[Crescente] Media do intervalo de %d ate %d: %.2f\n", x, y, (float)soma/(i-1));
	} else {
		printf("[Iguais] Os numeros inforados sao iguais.\n");
	}
}

void ex2(){
	int x, y, primo=1, d=2;
	do{
		primo=1, d=2;
		printf("Informe um numero: ");
		scanf("%d", &x);
		
		for(d=2; d<=x/2; d++){
			if (x % d  == 0){
	    		primo = 0;
	    		break;
			}
		}
		if(primo!=0||x<=2) 
			printf("O numero %d e primo\n", x); 
		else 
			printf("O numero %d nao e primo\n", x);
	}while(x<1);
}

void ex3(){
	int pessoa[MAX_PEOPLE], sexo[MAX_PEOPLE], c, d, temp_s, temp_p, nsexo[2];
	float altura[MAX_PEOPLE], temp_a, med_altura=0;
	
	srand((unsigned int)time(NULL));

    for (int i=0;i<MAX_PEOPLE;i++){
    	altura[i] = ((float)rand()/(float)(RAND_MAX)) * 2.;
    	sexo[i] = ((float)rand()/(float)(RAND_MAX)) * 4.<2 ? 0 : 1;
    	if(sexo[i] == 1) nsexo[1]++;
    	else {
    		med_altura += altura[i];
    		nsexo[0]++;
    	}
    	pessoa[i] = i;
    }
    
    med_altura /= nsexo[0];
    
    for (c = 0 ; c < ( MAX_PEOPLE - 1 ); c++) {
		for (d = 0 ; d < MAX_PEOPLE - c - 1; d++){
	    	if (altura[d] > altura[d+1]){
		    	temp_a       = altura[d];
		    	temp_s       = sexo[d];
		    	temp_p       = pessoa[d];
		        altura[d]   = altura[d+1];
		        sexo[d]   = sexo[d+1];
		        pessoa[d]   = pessoa[d+1];
		        altura[d+1] = temp_a;
		        sexo[d+1] = temp_s;
		        pessoa[d+1] = temp_p;
	    	}
		}
	}
	printf("| %-10s || %-10s || %10s |\n", "PESSOA", "ALTURA", "SEXO");
	printf(" --------------------------------------- \n");
	for(int i=0; i<MAX_PEOPLE; i++){
		printf("| %-10d || %-10f || %10d |\n", pessoa[i], altura[i], sexo[i]);
	}
	printf(" --------------------------------------- \n");
	printf("1)\t Maior do grupo: %d [%.2f]\n", pessoa[MAX_PEOPLE-1], altura[MAX_PEOPLE-1]);
	printf("2)\t Menor do grupo: %d [%.2f]\n", pessoa[0], altura[0]);
	printf("3)\t Média de altura das mulheres: %.2f\n", med_altura);
	printf("4)\t Número de homens: %d\n", nsexo[1]);
	printf("5)\t Sexo da pessoa %d, a mais alta: %s\n", pessoa[MAX_PEOPLE-1], sexo[MAX_PEOPLE-1]==1 ? "Masculino" : "Feminino");
	
		
}

void ex4(){
	printf("| %-10s || %-10s |\n", "Fahrenheit", "Celsius");
	printf(" ------------------------- \n");
	for(int i=MIN_GRAUS; i<=MAX_GRAUS; i++){
		printf("| %-10d || %-10.2f |\n", i, 5/9.*(i-32));
	}
	printf(" ------------------------- \n");
	
}

void ex5(){
	int ncriancas=MAX_PEOPLE, i=0;
	float psexo[2], ptempo[2], nfem=0, nbebe=0;
	
	int tempo[ncriancas], sexo[ncriancas];
	
	do{
		printf("Informe a quantidade de cirancas nascidas no periodo: ");
		scanf("%d", &ncriancas);
	}while(ncriancas==0);
	while(i<ncriancas){
		do{
			printf("Informe o periodo de vida em meses da crianca %d: ", i);
			scanf("%d", &tempo[i]);
		}while(tempo[i]<1);
		do{
			printf("Informe o sexo da crianca %d: [0 para mulher e 1 para homem] ", i);
			scanf("%d", &sexo[i]);
		}while(sexo[i] != 0 && sexo[i] != 1);	
		if(tempo[i] < 25) nbebe++;
		if(sexo[i] == 0) nfem++;
		i++;
	}

	psexo[0] =  nfem/ncriancas;
	psexo[1] =  1-psexo[0];
	
	ptempo[0] =  nbebe/ncriancas;
	ptempo[1] =  1-ptempo[0];
	
	printf(" -------------------------------------------------------------------------- \n");
	printf("| %-34s || %-34s |\n", "CRIANCAS MORTAS (%)", "CRIANCAS MORTAS (MESES)");
	printf(" -------------------------------------------------------------------------- \n");
	printf("| %-15s || %15s || %15s || %15s |\n", "FEMININO", "MESCULINO", "24-", "24+");
	printf(" -------------------------------------------------------------------------- \n");
	printf("| %14.0f%% || %14.0f%% || %14.0f%% || %14.0f%% |\n", psexo[0]*100, psexo[1]*100, ptempo[0]*100, ptempo[1]*100);
	printf(" -------------------------------------------------------------------------- \n");	
}

int main() {
	printf("LISTA DE EXERCICIOS DE FDA - 06\n");
	int o=0;
	do{
		printf("Qual exercicio voce quer ver? [1-5; 0 pra sair]\n");
		scanf("%d", &o);
	
		switch(o){
			case 1: ex1(); break;
			case 2: ex2(); break;
			case 3: ex3(); break;
			case 4: ex4(); break;
			case 5: ex5(); break;
			default: break;
		}
	}while(o!=0);
	return 0;
}
