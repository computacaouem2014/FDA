#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

const char str[8][16] = {};

void ex1() {
	char nome[20], nomemaior[20];
	int quantprod = 0, quantvend = 0, estoque = 0, flag = 1, maior = 0;
	while (flag) {
		printf("Informe o nome do produto: ");
		scanf("%20s", nome);
		printf("Informe a quantidade produzida: ");
		scanf("%d", & quantprod);
		printf("Informe a quantidade vendida: ");
		scanf("%d", & quantvend);
		estoque = quantprod - quantvend;
		printf("\nProduto: %s\n\tProduzido: %d\n\tVendidos: %d\n\tEstoque: %d\n", nome, quantprod, quantvend, estoque);
		if (estoque < 50) printf("O estoque e menor que 50.\n");
		if (estoque > maior) {
			strcpy(nomemaior, nome);
			maior = estoque;
		}
		printf("Digite 0 para sair ou 1 para continuar.\n");
		scanf("%d", & flag);
	}
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

void ex6() {
	int num = 2, denum = 1, n, i = 0;
	float termo;
	printf("Calcular os termos ate n=");
	scanf("%d", & n);
	while (i++ < n) {
		termo = (float) num / denum;
		printf("O termo n%d e: %.8f\n", i, termo);
		num += denum;
		denum = num - denum;
	}
}

void ex7() {
	int n, p, x = 1, y = 2, z = 3;
	printf("Informe um numero: ");
	scanf("%d", & n);
	while (1) {
		p = ++x * ++y * ++z;
		if (p == n) {
			printf("O numero %d e triangular (%d x %d x %d).\n", n, x, y , z);
			break;
		} else if (p > n) {
			printf("O numero %d nao e triangular.\n", n);
			break;
		}
	}
}

void ex8() {
	int n, maior = 0;
	while (n != -9999) {
		printf("Informe um numero [-9999 para encerrar]: ");
		scanf("%d", & n);
		if (n > maior) maior = n;
	}
	printf("O maior dentre os numeros informados e: %d", maior);
}

void ex9() {
	int conta, neg = 0, pos = 0;
	float saldo;
	while (1) {
		printf("Informe o numero da conta [negativo para encerrar]: ");
		scanf("%d", & conta);
		if (conta < 0) break;
		printf("Informe o saldo: ");
		scanf("%f", & saldo);
		if (saldo >= 0) {
			printf("Conta: %d\n\tSaldo: R$%.2f\n\tPositivo\n\n", conta, saldo);
			pos++;
		} else {
			printf("Conta: %d\n\tSaldo: R$%.2f\n\tNegativo\n\n", conta, saldo);
			neg++;
		}
	}
	printf("Percentual de saldos negativos: %.2f%%\n", (float)neg / (pos + neg) * 100);
}

void ex10() {
	int conta = 0, neg = 0, pos = 0;
	float saldo, agencia = 0;
	char nome[33];
	while (pos + neg < 10000) {
		printf("Informe o numero da conta [-999 para encerrar]: ");
		scanf("%d", & conta);
		if (conta == -999) break;
		printf("Informe o nome (32 caracteres): ");
		scanf("%32s", nome);
		printf("Informe o saldo: ");
		scanf("%f", & saldo);
		agencia += saldo;
		if (saldo >= 0) {
			printf("Conta: %d\n\tNome:%s\n\tSaldo: R$%.2f\n\tPositivo\n\n", conta, nome, saldo);
			pos++;
		} else {
			printf("Conta: %d\n\tNome:%s\n\tSaldo: R$%.2f\n\tNegativo\n\n", conta, nome, saldo);
			neg++;
		}
	}
	printf("Total de clientes com saldo negativo: %d\n", neg);
	printf("Total de clientes na agencia: %d\n", pos + neg);
	printf("Saldo da agencia: %.2f\n", agencia);
}

int main() {

	printf("LISTA DE FDA 07\n");

	srand(time(NULL));

	ex6();

	getchar();
	getchar();
	return 0;
}