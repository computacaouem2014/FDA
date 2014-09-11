#include <stdlib.h>
#include <stdio.h>

void ex1(){
	int n,tmp;
	do{
		puts("Informe o tamanho dos vetores:");
		scanf("%d",&n);
	}while(n<=0);
	
	
	int veta[n],vetb[n],vetc[2*n];
	
	for(int x=0;x<n;x++){
		printf("Informe o numero %d do primeiro vetor:\n",x+1);
		scanf("%d",&veta[x]);
		vetc[(x*2)]=veta[x];
	}
	for(int x=0;x<n;x++){
		printf("Informe o numero %d do segundo vetor:\n",x+1);
		scanf("%d",&vetb[x]);
		vetc[(x*2)+1]=vetb[x];
	}
	puts("\n\nvetor C nao ordenado:\n");
	for(int x=0;x<(2*n);x++){
		printf("%d\n",vetc[x]);
	}
	for(int x=0;x<((2*n)-1);x++){
		for(int y=x+1;y<(2*n);y++){
			if(vetc[x]>vetc[y]){
				tmp=vetc[y];
				vetc[y]=vetc[x];
				vetc[x]=tmp;
			}	
		}
	}
	puts("\n\nvetor ordenado:\n");
	for(int x=0;x<(2*n);x++){
		printf("%d\n",vetc[x]);
	}
	
}

void ex2(){
	
	int n;
	do{
		puts("Informe o tamanho dos vetores:");
		scanf("%d",&n);
	}while(n<=0);
	
	
	int veta[n],vetb[n],verify=0;
	
	for(int x=0;x<n;x++){
		do{
			printf("Informe o numero %d do primeiro vetor(nao repitir valores):\n",x+1);
			scanf("%d",&veta[x]);
			verify=0;
			for(int y=x-1;y>=0;y--){
				if(veta[x]==veta[y]){
					verify=1;
				}
			}
		}while(verify==1);
	}
	for(int x=0;x<n;x++){
		do{
			printf("Informe o numero %d do segundo vetor(nao repitir valores):\n",x+1);
			scanf("%d",&vetb[x]);
			verify=0;
			for(int y=x-1;y>=0;y--){
				if(vetb[x]==vetb[y]){
					verify=1;
				}
			}
		}while(verify==1);
	}
	puts("\nvetor a:\n");
	for(int x=0;x<n;x++){
		printf("%d\n",veta[x]);
	}
	puts("\nvetor b:\n");
	for(int x=0;x<n;x++){
		printf("%d\n",vetb[x]);
	}
}



int main(void){
	int pick;
	do{
		puts("escolha exercicio 1 a 2");
		scanf("%d",&pick);
	}while(pick<1||pick>2);
	switch(pick){
		case 1:
			puts("\n\n");
			ex1();
			break;
		case 2:
			puts("\n\n");
			ex2();
			break;
	}
	
	system("pause");
	return 0;
}
