#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ex1(){
	
	for(int x=0;x<256;x++){
		printf("%3d || %c\n",x,x);
	}
}

void ex2(){
	char str1[20]="Hello World.",str2[20];
	
	int count;
	
	/*forma 1:

	for(count=0;str1[count]!='\0';count++){
		str2[count]=str1[count];
	}
	str2[count]='\0';

	*/
	
	/* forma 2:

	for(count=0;count<strlen(str1);count++){
		str2[count]=str1[count];
	}
	str2[count]='\0';

	*/
	
	//forma 3:

	strcpy(str2,str1);
	
	
	printf("%s\n",str2);
		
}

void ex3(){
	char str1[20]="Hello World.";
	for(int x=0;x<strlen(str1);x++){
		printf("%c||%2d%||%3d\n",str1[x],x,str1[x]);
	}
}

void ex4(){
	char str1[255],carac;
	int verify=0;
	
	puts("Informe uma frase:");
	fflush(stdin);
	gets(str1);
	puts("Informe um caracter:");
	scanf("%c",&carac);
	
	for(int x=0;x<strlen(str1);x++){
		if(str1[x]==carac){
			printf("caracter: %c encontrado na posicao: %d\n",carac,x);
			verify=1;
		}
	}
	
	if(verify==0){
		printf("caracter: %c nao encontrado na frase.\n",carac);
	}
	
}

int main(void){
	int pick;
	do{
		puts("escolha exercicio 1 a 4");
		scanf("%d",&pick);
	}while(pick<1||pick>4);
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
		case 4:
			puts("\n\n");
			ex4();
			break;
	}
	
	system("pause");
	return 0;
}
