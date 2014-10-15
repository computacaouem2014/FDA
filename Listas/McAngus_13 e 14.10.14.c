#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct produto{
	int code;
	char size;
	float price;
};

struct person{
	int age;
	char hair, eyes, sex;
};

struct research{
	int age;
	char eyes, hair, sex;
};

struct client{
	int cod_cli, active;
	char *phone, *name, *adress;
};

struct date{
	int day, month, year;
};

struct docs{
	int num_doc, cod_cli, active;
	struct date venc;
};

void scanC(struct client x[], int size){
	for (int k = 0; k<size; k++){
		if (!x[k].active){
			do {
				int check = 0;
				printf("\nDigite o codigo do cliente: ");
				scanf("%d", &x[k].cod_cli);
					for (int j = 0; j<size; j++)
							if (x[k].cod_cli == x[j].cod_cli) check = 1;
                	if (check)
                        	printf("O codigo digitado ja esta em uso.\n");
    	    } while (!check);
			printf("Digite o fone do cliente: ");
            fgets(x[k].phone, 32, stdin);
            strtok(x[k].phone, "\n");
	        printf("Digite o nome do cliente: ");
        	fgets(x[k].name, 32, stdin);
        	strtok(x[k].name, "\n");
            printf("Digite o endereco do cliente: ");
	        fgets(x[k].adress, 32, stdin);
	        strtok(x[k].adress, "\n");
    	} else continue;
	}
}

void scanDoc(struct docs x[], int size){
	for (int k = 0; k<size; k++){
		if (!x[k].active){
   	        printf("Digite o numero do documento: ");
	       	scanf("%d", &x[k].num_doc);
			int check = 1;
			while (check){
    		        printf("Digite o codigo do cliente: ");
        	        scanf("%d", &x[k].cod_cli);
				for (int k = 0; k<size; k++){
					if (x[k].cod_cli == x[k].cod_cli) check = 0;
				}
				if (!check){
					printf("Por favor entre com o codigo de um cliente ja cadastrado.\n");
				}
			}
        	printf("Digite o dia de vencimento do documento: ");
        	scanf("%d", &x[k].venc.day);
	        printf("Digite o mes de vencimento do documento: ");
   			scanf("%d", &x[k].venc.month);
			printf("Digite o ano de vencimento do documento: ");
			scanf("%d", &x[k].venc.year);
			x[k].active = 1;
		} else continue;
	}
}


void scanR(struct research x[], int n){
    for (int k = 0; k<n; k++){
        printf("Digite a idade da pessoa: ");
        scanf("%d", &x[k].age);
        printf("Digite a cor do cabelo: ");
        scanf(" %c", &x[k].hair);
        printf("Digite a cor dos olhos: ");
        scanf(" %c", &x[k].eyes);
        printf("Digite o sexo: ");
        scanf(" %c", &x[k].sex);
    }
}


void scan(struct person x[], int n){
	for (int k = 0; k<n; k++){
		printf("Digite a idade da pessoa: ");
		scanf("%d", &x[k].age);
		printf("Digite a cor do cabelo: ");
		scanf(" %c", &x[k].hair);
        printf("Digite a cor dos olhos: ");
        scanf(" %c", &x[k].eyes);
        printf("Digite o sexo: ");
        scanf(" %c", &x[k].sex);
	}
}

int media(struct person x[], int size){
	int countAC = 0, countA = 0;
	for (int k = 0; k<size; k++){
		if ((x[k].hair == 'C' || x[k].hair == 'c') && (x[k].eyes == 'A' || x[k].eyes == 'a')){
			countAC++;
			countA += x[k].age;
		}
	}
	if (countAC > 0)
		return (float)countA/countAC;
	return 0;
}

void showArrayP(struct research arr[], int size){
    for (int k = 0; k<size; k++){
        printf("\n%d", arr[k].age);
        printf("\n%d", arr[k].hair);
        printf("\n%d", arr[k].eyes);
        printf("\n%d", arr[k].sex);
    }
}

void showArray(struct person arr[], int size){
	for (int k = 0; k<size; k++){
		printf("\n%d", arr[k].age);
        printf("\n%d", arr[k].hair);
        printf("\n%d", arr[k].eyes);
        printf("\n%d", arr[k].sex);
	}
}

int oldder(struct research arr[], int size){
	int old = -1;
	for (int k = 0; k<size; k++)
		if (arr[k].age < old) old = arr[k].age;
	return old;
}

void fieldShow(struct produto x){
	printf("\n%d", x.code);
	printf("\n%c", x.size);
	printf("\n%f", x.price);
}

//Mulher 18 && 35 / LOIRA / AZUIS

int female(struct research arr[], int size){
	int count = 0;
	for (int k = 0; k<size; k++)
		if ((arr[k].sex == 'F' || arr[k].sex == 'f') && arr[k].age >= 18 && arr[k].age <= 35 && (arr[k].hair == 'L' || arr[k].hair == 'l') && (arr[k].eyes == 'A' || arr[k].eyes == 'a')) count++;
	return count;
}

void ex1(){
	struct produto copo;
	printf("Digite o codigo do produto: ");
	scanf("%d", &copo.code);
	getchar();
	printf("Digite o tamanho do produto: ");
    scanf("%c", &copo.size);
	getchar();
	printf("Digite o preco do produto: ");
    scanf("%f", &copo.price);
	getchar();
	fieldShow(copo);
}

void ex2(){
	struct person x[2];
	scan(x, 2);
	showArray(x, 2);
	printf("%d", media(x, 2));
}

void ex3(){
	struct client cli[30];
	struct docs doc[100];
	int menu;
	for (int k = 0; k<30; k++) cli[k].active = 0;
	for (int k = 0; k<100; k++) doc[k].active = 0;
	C:;
	printf("\n\n\tEscolha uma opcao:\n\n");
	printf("\t\t1.Cadastrar cliente.\n\t\t2.Cadastrar documentos.\n\t\t0.Sair do programa\n\tOpcao: ");
	scanf("%d", &menu);
	switch (menu){
		case 1:{
			scanC(cli, 30);
			break;
		}
		case 2:{
			scanDoc(doc, 100);
			break;
		}
		case 0:{
			printf("Saindo...");
			break;
		}
		default:{
			printf("\n\n\t\tOpcao invalida.\n\n");
			goto C;
		}
	}
}
			
int main(){
	ex3();
	return 0;
}
