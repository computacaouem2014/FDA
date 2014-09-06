#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


void ex1(){
	int qtdp[1][30], qtdv[1][30];
	char name[30][30], alph[5] = {'a', 'b', 'c', 'd', 'e'};

	srand(time(NULL));

	for (int i=0; i<30; i++){
		for(int k=0; k<30; k++){
			qtdp[1][k] = rand() % 100 + 30;
			qtdv[1][k] = rand() % 40 + 1;
			for (int j=0; j<30; j++){
				name[j][i] = alph[(unsigned int)rand() % 5];
			}

			printf("%c", name[k][i]);

		}
		printf("\n%s ||  %s ||  %d\n\n", "Quantidade estoque", qtdp[1][i]-qtdv[1][i] < 50 ? "Estoque abaixo de 50" : "\b\b\b\b\b",qtdp[1][i]-qtdv[1][i] >= 0 ? qtdp[1][i]-qtdv[1][i] : 0);
	}
}

void ex2(){
	int idade[3] = {1,0,0};
	while(idade[0]>0){
		printf("Digite a idade da pessoa, para sair digite 0: ");
		scanf("%d", &idade[0]);
		if (idade[0] < 21 && idade[0] > 0) 	idade[1]++;
		if (idade[0] >50)	idade[2]++;
	}
	printf("Menos de 21: %d.\nMais de 50: %d.", idade[1], idade[2]);
}

void ex3(){
	int pa = 5000000,pb = 7000000,  year = 0;
	while (pa<pb){
		pa += (pa*3)/100.;
		pb += (pb*2)/100.;
		year++;
	}
	printf("Vai demorar %d anos.", year);
}

void ex4(){
	int code, type;
	float kwh, total[3];
	while (code!=0){
		printf("Digite o numero do consumidor: ");
		scanf("%d", &code);
		printf("Digite quantidade de KWh consumidos: ");
		scanf("%f", &kwh);
		printf("Digite o tipo do consumidor: ");
		scanf("%d", &type);
		if (type == 1)	{
			 total[0] += kwh*.5;
			 printf("O custo total para o consumidor %d e %.2f\n", code, kwh*.5);
		}
		if (type == 2)	{
			total[1] += kwh*.7;
			printf("O custo total para o consumidor %d e %.2f\n", code, kwh*.7);
		}
		if (type == 3){
			total[2] += kwh*1.2;
			printf("O custo total para o consumidor %d e %.2f\n", code, kwh*1.2);
		}
	}
	printf("O total para os 3 tipos de consumidores e %.2f.\n", total[0]+total[1]+total[2]);
	printf("A media do consumido dos tipos 1 e 2 e %.2f.\n", (float)(total[0]+total[1])/2.);
}

void ex5(){
	float sum = 0;
	int n = 1;
	while (n <101){
		sum += pow(-1, n+1)*1/n;
		n++;
	}
	printf("%f", sum);
}

void ex6(){
	int terms, temp;
	float fibo1 = 1, fibo2 = 2, div = 0;

	printf("Digite ate quantos termos deseja calcular: ");
	scanf("%d", &terms);
	while (terms > 0){
		div += fibo2/fibo1;
		temp = fibo2;
		fibo2 += fibo1;
		fibo1 = temp;
		terms--;
	}
	printf("%f", div);
}

void ex7(){
	int num, x = 1, y = 2, z = 3;
	printf("Digite um numero para verificar se ele e um numero triangular: ");
	scanf("%d", &num);

	while (x*y*z <= num){
		if (x*y*z == num)
			printf("E triangular.");
		x++; y++; z++;
	}

	if (x*y*z < num)
		printf("Nao e triangular.");
}

void ex8(){
	int n, maior = 0;
	while (n != -9999){
		printf("Digite um numero: ");
		scanf("%d", &n);
		maior == 0 ? maior = n : n > maior && n!= -9999 ? maior = n : maior;
	}
	printf("Maior = %d", maior);
}

void ex9(){
	int i, total, perc[2] = {0,0};

	printf("Digite um numero de contas que ira digitar: ");
	scanf("%d", &i);
	total = i;
	float count[i][3];

	while (i > 0){
		printf("Digite a conta: ");	scanf("%f", &count[i][0]);
		printf("Digite o saldo da conta: ");	scanf("%f", &count[i][1]);
		if (count[i][1] >= 0){
			count[i][2] = 1;
			perc[0]++;
		}
		else{
			count[i][2];
			perc[1]++;
		}
		system("clear");
		i--;
	}

	for (int k = total; k > 0; k--){
		printf("A conta %.f possui saldo de %.2f, que esta %s.\n", count[k][0], count[k][1], count[k][2] == 0 ? "positivo" : "negativo");
	}

	printf("O percentual de contas com saldo negativo e de %.2f\%\n", ((float)perc[1]/(float)total)*100);
	printf("O percentual de contas com saldo positivo e de %.2f\%\n", ((float)perc[0]/(float)total)*100);
}

void ex10(){
	int i = 0, num[10000], tot[3] = {0,0,0};
	char name[10000][50];
	float bank[10000][2], banksald = 0;
	while (i < 10000){

		printf("%s", "Digite o número da conta do cliente: ");
		scanf("%d", &num[i]);
		getchar();

		if (num[i] == -999)
			break;

		printf("Digite o nome do cliente: ");
		fgets(name[i], 50, stdin);

		name[i][ strlen (name[i]) - 1] = '\0';



		printf("Digite o saldo do cliente: ");
		scanf("%f", &bank[i][0]);

		if (bank[i][0] >= 0){
			bank[i][1] = 1;
			tot[0]++;
		}
		if (bank[i][0] < 0){
			bank[i][1] = 0;
			tot[1]++;
		}
		banksald += bank[i][0];
		i++;
		tot[2]++;
		system("clear");
	}
	system("clear");
	for (int k = 0; k<i; k++)
		printf("|| %-4d || %-30s || R$%-12.2f || %s ||\n", num[k], name[k], bank[k][0], bank[k][1] == 1 ? "Positivo" : "Negativo");
	printf("Total de clientes com saldo positivo: %d.\n", tot[0]);
	printf("Total de clientes com saldo negativo: %d.\n", tot[1]);
	printf("Total de clientes do banco: %d.\n", tot[2]);
	printf("Saldo total do banco: R$%.2f. %s\n", banksald, banksald >= 0 ? "" : "Atenção o saldo do banco está negativo.");
}

int main(){
	int menu;
	while (menu != 0){
		printf("%s", "Escolha um exercício de 1 - 10, digite 0 para sair: ");
		scanf("%d", &menu);
		switch (menu){
			case 1: ex1(); break;
			case 2: ex2(); break;
			case 3: ex3(); break;
			case 4: ex4(); break;
			case 5: ex5(); break;
			case 6: ex6(); break;
			case 7: ex7(); break;
			case 8: ex8(); break;
			case 9: ex9(); break;
			case 10: ex10(); break;
			default : break;

		}
	}
}
