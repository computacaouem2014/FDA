#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void perfeitos(int n,int v[]){
	int soma,perfcount=0,num=1;
	while(perfcount<n){
		soma=0;
		for(int x=1;x<(num/2)+1;x++){
			if(num%x==0){
				soma+=x;
			}
		}
		if(num==soma){
			v[perfcount]=num;
			perfcount++;
		}
		num++;
	}
}


void ex1(){
	int n=4,v[n];
	perfeitos(n,v);
	for(int x=0;x<n;x++){
		printf("%d\n",v[x]);
	}
}


void ex2(){
	int array[5]={7,9,5,3,1},tmp;
	for(int x=0;x<(4);x++){
		for(int y=x+1;y<5;y++){
			if(array[x]>array[y]){
				tmp=array[y];
				array[y]=array[x];
				array[x]=tmp;
			}	
		}
	}
	for(int x=0;x<5;x++){
		printf("%d\n",array[x]);
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
