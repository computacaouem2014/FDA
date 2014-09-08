#include <stdlib.h>
#include <stdio.h>

void ex1(){
	int n;
	do{
		puts("Informe o numero de valores:");
		scanf("%d",&n);
	}while(n<=0);
	float array[n];
	for(int x=0;x<n;x++){
		printf("Informe o %d valor:\n",x+1);
		scanf("%f",&array[x]);
	}
	for(int x=0;x<n;x++){
		printf("%f\n",array[x]);
	}
}

void ex2(){
	int n,pick,verify=0,tmp,x;
	do{
		puts("Informe o numero de valores:");
		scanf("%d",&n);
	}while(n<=0);
	int array[n];
	for(x=0;x<n;x++){
		printf("Informe o %d valor:\n",x+1);
		scanf("%d",&array[x]);
	}	
	puts("Informe o valor desejado:");
	scanf("%d",&pick);
	for(x=0;x<n;x++){
		if(array[x]==pick){
			verify=1;
			break;
		}
	}
	if(verify==1){
		printf("o numero %d esta na posicao %d do vetor e foi o %d numero a ser informado\n",pick,x,x+1);
	}else{
		printf("o numero %d nao esta no vetor\n",pick);
	}
}

void ex3(){
	int n,tmp,at;
	do{
		puts("Informe o numero de valores:");
		scanf("%d",&n);
	}while(n<=0);
	int array[n];
	for(int x=0;x<n;x++){
		printf("Informe o %d valor:\n",x+1);
		scanf("%d",&array[x]);
		for(int y=0;y<x;y++){
			if(array[y]>array[x]){
				tmp=array[x];
				for(int z=x;z>=y;z--){
					array[z]=array[z-1];
				}
				array[y]=tmp;
				break;
			}
		}
	}	
	/*
	para ordenar fora se for o caso
	for(int x=0;x<(n-1);x++){
		for(int y=x+1;y<n;y++){
			if(array[x]>array[y]){
				tmp=array[y];
				array[y]=array[x];
				array[x]=tmp;
			}	
		}
	}
	*/
	puts("\n");
	for(int x=0;x<n;x++){
		printf("%d\n",array[x]);
	}
}

int main(void){
	int pick;
	do{
		puts("escolha exercicio 1 a 3");
		scanf("%d",&pick);
	}while(pick<1||pick>3);
	switch(pick){
		case 1:
			ex1();
			break;
		case 2:
			ex2();
			break;
		case 3:
			ex3();
			break;
	}
	
	system("pause");
	return 0;
}
