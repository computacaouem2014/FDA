#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ex1(){
	char str[2][100];
	puts("Informe uma string:");
	fflush(stdin);
	gets(str[0]);
	puts("Informe outra string:");
	fflush(stdin);
	gets(str[1]);
	int x=strcmp(str[0],str[1]);//0-iguais 1- primeira é maior (-1)-segunda é maior
	printf("As strings sao %s\n",x==0?"iguais":x>0?"diferentes e a primeira é a maior":"diferentes e a segunda é a maior");
	strcat(str[0],str[1]);
	printf("%s\n",str[0]);
}

void ex2(){
	char str[100];
	int palavras=0;
	puts("Informe uma string:");
	fflush(stdin);
	gets(str);
	if(strlen(str)!=0){
		palavras++;
	}
	for(int x=strlen(str);x>=0;x--){
		if(str[x]==32&&str[x-1]!=32){
			palavras++;
		}
	}
	if(str[strlen(str)-1]==32){
		palavras--;
	}
	if(str[0]==32){
		palavras--;
	}
	printf("%d palavras\n",palavras);
	
}
void ex3(){
	
	/*windows
	char str[65],stri[65];
	puts("Informe uma palavra");
	fflush(stdin);
	gets(str);
	strcpy(stri,str);
	strrev(stri);
	if(strcmpi(str,stri)!=0){
		printf("nao ");
	}
	puts("e palindromo");
	*/
	
	//alternativa linux
	
	char str[65],stri[65];
	puts("Informe uma palavra");
	fflush(stdin);
	gets(str);
	for(int x=0;x<strlen(str);x++){
		if(str[x]>=97&&str[x]<=122){
			str[x]-=32;
		}	
	}
	
	
	strcpy(stri,str);
	for(int x=0;x<strlen(str);x++){
		stri[strlen(str)-1-x]=str[x];
	}
	if(strcmp(str,stri)!=0){
		printf("nao ");
	}
	puts("e palindromo");
	
}




int main(void){
	int pick;
	do{
		puts("escolha exercicio 1 a 3");
		scanf("%d",&pick);
	}while(pick<1||pick>3);
	switch(pick){
		case 1:
			puts("\n\n");
			ex1();
			break;
		case 2:
			puts("\n\n");
			ex2();
			break;
		case 3:
			puts("\n\n");
			ex3();
			break;
	}
	
	system("pause");
	return 0;
}
