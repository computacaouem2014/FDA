#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

const char str[8][16] = {};

void ex1() {
	char nome[20], nomemaior[20];
	int quantprod = 0, quantvend = 0, estoque = 0, flag = 1, maior = 0;
	do {
		printf("Informe o nome do produto: ");
		scanf("%20s", nome);
		printf("Informe a quantidade produzida: ");
		scanf("%d", & quantprod);
		printf("Informe a quantidade vendida: ");
		scanf("%d", & quantvend);
		estoque = quantprod - quantvend;
		printf("\nProduto: %s\n\tProduzido: %d\n\tVendidos: %d\n\tEstoque: %d\n", nome, quantprod, quantvend, estoque);
		if (estoque < 50)
			printf("O estoque e menor que 50.");
		printf("Digite 0 para sair ou 1 para continuar.\n");
		scanf("%d", & flag);
		if (estoque > maior) {
			strcpy(nomemaior, nome);
			maior = estoque;
		}
	} while (flag);
	printf("Produto com maior estoque: %s (Estoque:%d)\n", nomemaior, maior);
}

void ex2() {
	int idade, maior = 0, menor = 0;
	do {
		printf("Informe uma idade: [0 para sair]\n");
		scanf("%d", & idade);
		if (idade > 50) maior++;
		else if (idade < 21) menor++;
	} while (idade);
	printf("Total de pessoas com menos de 21: %d\n", menor);
	printf("Total de pessoas com mais de 50: %d\n", maior);
}

void ex3() {
	int popA = 5000000, popB = 7000000, anos = 0;
	float crescA = 0.03, crescB = 0.02;
	while (popA < popB) {
		popA += popA * crescA;
		popB += popB * crescB;
		anos++;
	}
	printf("A populacao A leva %d ano(s) para ultrapassar a populacao B.\n", anos);
}

void ex4() {
	int consumidor, codigo;
	float kwh[3] = {0.5, 0.7, 1.2}, consumo, custo, total[3] = {0, 0, 0}, count[3] = {0, 0, 0};
	while (1) {
		printf("Informe o numero do consumidor [0 para terminar]: ");
		scanf("%d", & consumidor);
		if (!consumidor) break;
		printf("Informe o consumo em kWh: ");
		scanf("%f", & consumo);
		printf("Informe o tipo do consumidor (codigo):\n");
		printf("\t0-Residencial\n\t1-Comercial\n\t2-Industrial\n");
		scanf("%d", & codigo);
		custo = kwh[codigo] * consumo;
		total[codigo] += custo;
		count[codigo]++;
		printf("Custo total: R$%.2f\n\n", custo);
	}
	printf("Media de consumo:\n");
	printf("\tResidencial:\t%.2f\n\tComercial:\t%.2f\n\tIndustrial:\t%.2f\n", total[0] / count[0], total[1] / count[1], total[2] / count[2]);
}

void ex5() {
	int i = 0;
	double seq = 0;
	while (++i < 101) {
		seq += (-1. / i) * pow(-1, i);
	}
	printf("Sequencia: %.8f", seq);
}

int main() {

	printf("LISTA DE FDA 07\n");

	srand(time(NULL));

	ex5();

	getchar();
	getchar();
	return 0;
}