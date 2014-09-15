#include <stdlib.h>
#include <stdio.h>


void ex1(){
	
	int n;
	do{
		puts("Informe o tamanho dos vetores:");
		scanf("%d",&n);
	}while(n<=0);
	
	
	int veta[n],vetb[n],vetc[n],vetd[n],vete[n],vetf[n],verifyf,vetg[2*n],counte=0,countg=n,countf=0,verify=0;
	
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
		vetg[x]=veta[x];
	}
	for(int x=0;x<n;x++){
		verifyf=1;
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
		vetc[x]=vetb[x]+veta[x];
		vetd[x]=vetb[x]*veta[x];
		
		
		for(int y=n;y>=0;y--){
			if(veta[y]==vetb[x]){
				vete[counte]=vetb[x];
				counte++;
			}
		}
		
		
		
		
		for(int y=x;y>=0;y--){
			if(veta[x]==vetb[y]){
				verifyf=0;
				break;
			}
		}
		if(verifyf==1){
			vetf[countf]=veta[x];
			countf++;	
		}
	}
	for(int x=0;x<n;x++){
		verify=0;
		for(int y=n;y>=0;y--){
			if(vetb[x]==veta[y]){
				verify=1;
			}
		}
		if(verify==0){
			vetg[countg]=vetb[x];
			countg++;
		}
		
	}
	
	puts("\nVetor A:\n");
	for(int x=0;x<n;x++){
		printf("%d\n",veta[x]);
	}
	puts("\nVetor B:\n");
	for(int x=0;x<n;x++){
		printf("%d\n",vetb[x]);
	}
	puts("\nSoma de A e B:\n");
	for(int x=0;x<n;x++){
		printf("%d\n",vetc[x]);
	}
	puts("\nO produto de A e B:\n");
	for(int x=0;x<n;x++){
		printf("%d\n",vetd[x]);
	}
	puts("\nIntersecao de A e B:\n");
	for(int x=0;x<counte;x++){
			printf("%d\n",vete[x]);
	}
	puts("\nValores do vetor A que nao estao em B:\n");
	for(int x=0;x<countf;x++){
		printf("%d\n",vetf[x]);
	}
	puts("\nUniao de A e B:\n");
	for(int x=0;x<countg;x++){
		printf("%d\n",vetg[x]);
	}
	puts("\n\n");
	
}



int main(void){
	ex1();
	system("pause");
	return 0;
}
