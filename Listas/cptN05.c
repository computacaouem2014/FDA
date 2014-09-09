#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void ex1() {
	float compra;
	printf("Informe o valor da compra: ");
	scanf("%f", & compra);
	float total;
	if (compra > 200) total = 0.8 * compra;
	else if (compra > 100) total = 0.9 * compra;
	else total = 0.95 * compra;
	printf("Valor total: R$%.2f\n", total);
}

void ex2() {
	float phora, horas;
	printf("Informe o valor recebido por hora de trabalho: ");
	scanf("%f", & phora);
	printf("Informe a quantidade de horas trabalhadas da semana: ");
	scanf("%f", & horas);
	float snormal = phora * horas, sextra = 0;
	if (horas > 40) sextra = phora * (horas - 40) * 0.5;
	float sbruto = snormal + sextra;
	printf("Salario:\n\tNormal: R$%.2f\n\tExtra: R$%.2f\n\tBruto: R$%.2f\n", snormal, sextra, sbruto);
}

void ex3() {
	float phora, horas;
	printf("Informe o valor recebido por hora de trabalho: ");
	scanf("%f", & phora);
	printf("Informe a quantidade de horas trabalhadas da semana: ");
	scanf("%f", & horas);
	float snormal = phora * horas, sextra = 0;
	if (horas > 40) sextra = phora * (horas - 40) * 0.5;
	float sbruto = snormal + sextra;
	float inss = 0.11 * sbruto;
	float is = 0.008 * sbruto;
	float aliquota = 0;
	if (sbruto > 1787.77) aliquota += 7.5;
	if (sbruto > 2679.29) aliquota += 7.5;
	if (sbruto > 3572.43) aliquota += 7.5;
	if (sbruto > 4463.81) aliquota += 5;
	float ir = aliquota * sbruto;
	float sliq = sbruto - inss - is - ir;
	printf("Salario:\n");
	printf("\tNormal:\t\tR$%.2f\n", snormal);
	printf("\tExtra:\t\tR$%.2f\n", sextra);
	printf("\tBruto:\t\tR$%.2f\n", sbruto);
	printf("\tINSS:\t\t-R$%.2f\n", inss);
	printf("\tImposto Sindical:\t-R$%.2f\n", is);
	printf("\tImposto de Renda:\t-R$%.2f\n", ir);
	printf("\tLiquido:\t\tR$%.2f\n", sliq);
}

void ex4() {
	int a, b, c;
	printf("Informe a: ");
	scanf("%d", & a);
	printf("Informe b: ");
	scanf("%d", & b);
	printf("Informe c: ");
	scanf("%d", & c);
	int maior = a, menor = a;
	if (b > maior) maior = b;
	if (c > maior) maior = c;
	if (menor > b) menor = b;
	if (menor > c) menor = c;
	printf("Maior: %d\nMenor: %d\n", maior, menor);
}

void ex5() {
	float sfixo, comissao = 0;
	int quant42p, quant42, quant42m;
	printf("Informe o salario fixo mensal: ");
	scanf("%f", & sfixo);
	printf("Informe a quantidade de televisores > 42\": ");
	scanf("%f", & quant42p);
	printf("Informe a quantidade de televisores == 42\": ");
	scanf("%f", & quant42);
	printf("Informe a quantidade de televisores < 42\": ");
	scanf("%f", & quant42m);
	comissao += quant42p * 170;
	comissao += quant42 * 100;
	if (quant42 > 10) comissao += quant42 * 50;
	comissao += quant42m * 50;
	if (quant42 > 20) comissao += quant42m * 70;
	float sbruto = sfixo + comissao;
	float aliquota = 0;
	float inss = 0.1 * sbruto;
	if (sbruto > 1787.77) aliquota += 7.5;
	if (sbruto > 2679.29) aliquota += 7.5;
	if (sbruto > 3572.43) aliquota += 7.5;
	if (sbruto > 4463.81) aliquota += 5;
	float ir = aliquota * sbruto;
	float sliq = sbruto - inss - ir;
	printf("Salario:\n");
	printf("\tComissao:\t\tR$%.2f", comissao);
	printf("\tBruto:\t\tR$%.2f", sbruto);
	printf("\tINSS:\t\t-R$%.2f", inss);
	printf("\tImposto de Renda:\t-R$%.2f", ir);
	printf("\tLiquido:\t\t-R$%.2f\n", ir);
}

void ex6() {
	float smin = 730;
	int pecas;
	printf("Informe a quantidade de pecas montadas no mes: ");
	scanf("%d", & pecas);
	float comissao = 0, sbruto;
	if (pecas > 35) comissao += (pecas - 30) * 0.5 * smin;
	else if (pecas > 30) comissao += (pecas - 30) * 0.3 * smin;
	sbruto = smin + comissao;
	printf("Salario:\n");
	printf("\tMinimo:\tR$%.2f", smin);
	printf("\tComissao:\tR$%.2f", comissao);
	printf("\tBruto:\tR$%.2f", sbruto);
}

void ex7() {
	float salario;
	printf("Informe o salario: ");
	scanf("%f", & salario);
	float auxesc = 250, extra;
	if (salario > 1500) extra = 0;
	else if (salario > 1000) extra = 0.1 * salario;
	else extra = 0.15 * salario;
	if (salario > 800) auxesc -= 50;
	float total = salario + extra + auxesc;
	printf("Salario:\n");
	printf("\tInicial:\tR$%.2f", salario);
	printf("\tBonificacao:\tR$%.2f", extra);
	printf("\tAux.Escola:\tR$%.2f", auxesc);
	printf("\tTotal:\t\tR$%.2f", total);
}

int main() {
	print("LISTA DE EXERCICIOS DE FDA - 05");

	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	ex7();

	getchar();
	getchar();

	return 0;
}