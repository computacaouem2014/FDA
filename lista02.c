#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

void print(char* str){
	printf("%s\n", str);
}

void ex1(){

	print("\n------------------------------\n");
	
	print("X esta no intervalo aberto (0.,3).");
	print("X > 0 && X < 3\n");
	
	print("X esta no intervalo fechado [0.,3].");
	print("X >= 0 && X <= 3\n");
	
	print("P excede X, ou excede Y, ou excede Z.");
	print("P > X || P > Y || P > Z\n");
	
	print("0 <= x < 6");
	print("x >= 0 && x < 6\n");
	
	print("m > 50 ou m < 0");
	print("m > 50 || m < 0\n");
	
	print("x nao é menor que y.");
	print("!(x < y)\n");
	
	print("x nao é menor que y, nem menor que z.");
	print("!(x < y) && !(x < z)\n");
	
	print("a = b = c");
	print("a == b && b == c\n");
	print("a == b && a == c\n");
	
	print("A nao e igual a B, e C nao é igual a D, nem igual a E.");
	print("A != B && C != D && C != E\n");
	
	print("A e B estao entre 1 e 10, incluindo os extremos.");
	print("A >= 1 && A <= 10 && B >= 1 && B <= 10  \n");
	
	print("a e b sao maiores que c ou, entao, a e b sao menores ou iguais a 20.");
	print("(a > c && b > c) || (a <= 20 && b <=20)\n");
	
	print("Nem a nem b é maior que 10.");
	print("!(a > 10 && b > 10)\n");
	
	print("x não está entre a e b.");
	print("!(x > a && x < b)\n");

	print("\n------------------------------\n");
	
}

void ex2(){

	print("\n------------------------------\n");
	
	print("Tendo como dados de entrada dois pontos quaisquer no plano, P1(X1, Y1) e P2(X2, Y2), escreva a distancia entre eles.");
	
	float pa_x, pa_y, pb_x, pb_y;
	
	print("Informe as coordenadas do ponto A:");
	scanf("%f%f", &pa_x, &pa_y);
	
	print("Informe as coordenadas do ponto B:");
	scanf("%f%f", &pb_x, &pb_y);
	
	float distancia = sqrt(pow(pa_x - pb_x, 2) + pow(pa_y - pb_y, 2));
	
	printf("A distancia entre os pontos A(%.2f, %.2f) e B(%.2f, %.2f) e: %.2f\n", pa_x, pa_y, pb_x, pb_y, distancia);
	
	print("\n------------------------------\n");
	
}

void ex3(){

	print("\n------------------------------\n");
	
	print("Construir um algoritmo que calcule e escreva o fatorial de 6.");
	
	int fatorial(int index){
		return index == 1 ? 1 : fatorial(index - 1) * index;
	}
	
	//int f6 = fatorial(6);
	int f6 = 6 * 5 * 4 * 3 * 2 * 1;
	
	printf("Fatorial de 6 = %ld\n", f6);
	
	print("\n------------------------------\n");
	
}

void ex4(){

	print("\n------------------------------\n");
	
	print("Fazer um algoritmo para calcular o volume de uma esfera de raio R, em que R e um valor lido.");
	
	float raio;
	
	print("Informe o raio da esfera:");
	scanf("%f", &raio);
	
	float volume = (4 * M_PI * pow(raio, 3)) / 3;
	
	printf("O volume da esfera de raio = %.2f e: %.2f\n", raio, volume);
	
	print("\n------------------------------\n");
	
}

void ex5(){
	
	print("\n------------------------------\n");
	
	print("Fazer um algoritmo que leia o tempo de duracao de um evento em uma fabrica expresso em segundos e mostre-o expresso em horas, minutos e segundos.");
	
	int tempo_em_segundos;
	
	print("Informe o tempo em segundos:");
	scanf("%d", &tempo_em_segundos);

	int horas = tempo_em_segundos / 3600;
	int minutos = (tempo_em_segundos - (horas * 3600)) / 60;
	// int minutos = (tempo_em_segundos % 3600) / 3600;
	int segundos = tempo_em_segundos % 60;
	
	printf("%d segundos equivalem a %02dh:%02dm:%02ds\n", tempo_em_segundos, horas, minutos, segundos);
	
	print("\n------------------------------\n");
	
}

void ex6(){
	
	print("\n------------------------------\n");
	
	print("Fazer um algoritmo para: entrar com dois numeros inteiros e imprimir a seguinte saida: dividendo, divisor, quociente e resto.");
	
	int dividendo, divisor;
	
	print("Informe dois numeros:");
	scanf("%d%d", &dividendo, &divisor);
	
	float quociente = (float) dividendo / divisor;
	int resto = dividendo % divisor;
	
	printf("\nDividendo:\t%d\nDivisor:\t%d\nQuociente:\t%.2f\nResto:\t\t%d\n", dividendo, divisor, quociente, resto);

	print("\n------------------------------\n");
	
}

void ex7(){
	
	print("\n------------------------------\n");
	
	print("Faça um algoritmo que receba o salario-base de um funcionario, calcule e mostre o seu salario a receber, sabendo-se que esse funcionario tem gratificacao de R$ 500,00 e paga imposto de 10% sobre o salario-base.");
	
	float salario_base;
	
	print("Informe o salario base:");
	scanf("%f", &salario_base);
	
	float salario_receber = (salario_base * .9) + 500;
	
	printf("Salario base:\t\t%8.2f\nSalario a receber:\t%8.2f\n", salario_base, salario_receber);

	print("\n------------------------------\n");
	
}

void ex8(){
	
	print("\n------------------------------\n");
	
	print("Fazer um  algoritmo  para: entrar com um numero no formato CDU e  imprimir invertido: UDC (Exemplo: 123, saira 321).");
	
	int numero;
	
	print("Informe um numero de tres digitos:");
	scanf("%3d", &numero);
	
	int passo1 = (numero / 100);
	
	int passo2 = (numero / 10) - (passo1 * 10);
	
	int passo3 = numero - (passo1 * 100) - (passo2 * 10);
	
	int invertido = (passo1) + (passo2 * 10) + (passo3 * 100);
	
	printf("%d -> %d\n", numero, invertido);
	
	print("\n------------------------------\n");
	
}

void ex9(){
	
	print("\n------------------------------\n");
	
	print("Fazer um  algoritmo  para: entrar com a base e a altura de um retangulo e imprimir a seguinte saida: Perimetro, Area, Diagonal.");
	
	int base, altura;
	
	print("Informe a base do retangulo:");
	scanf("%d", &base);
	
	print("Informe a altura do retangulo:");
	scanf("%d", &altura);
	
	int perimetro = (2 * base) + (2 * altura);
	int area = base * altura;
	int diagonal = sqrt(pow(base, 2) + pow(altura, 2));
	
	printf("O retangulo de base = %d e altura = %d tem:\n\tPerimetro:\t%d\n\tArea:\t\t%d\n\tDiagonal:\t%d\n", base, altura, perimetro, area, diagonal);
	
	print("\n------------------------------\n");
	
}

void ex10(){
		
	print("\n------------------------------\n");
	
	print("O  custo  final  ao  consumidor  de  um  carro  novo  e  a  soma  do  custo  de  fabrica  com  a percentagem do distribuidor e dos impostos (aplicados ao custo de fabrica). Supondo que  a  percentagem do  distribuidor seja de 28%  e os  impostos  de  45%,  escrever um algoritmo para ler o custo de fabrica de um carro e escrever o custo final ao consumidor.");
	
	float preco_fabrica;
	
	print("Por favor informe o preco de fabrica do carro:");
	scanf("%f", &preco_fabrica);
	
	float imposto = .45 * preco_fabrica;
	float distribuidor = .28 * preco_fabrica;
	float preco_final = preco_fabrica + imposto + distribuidor;
	
	printf("\tPreco de fabrica:\tR$% 10.2f\n\tImposto:\t\tR$% 10.2f\n\tDistribuidor:\t\tR$% 10.2f\nO preco final do carro sera:\tR$% 10.2f\n", preco_fabrica, imposto, distribuidor, preco_final);
	
	print("\n------------------------------\n");
	
}

void ex11(){
		
	print("\n------------------------------\n");
	
	print("Fazer um algoritmo para entrar com o raio de um circulo e imprimir a seguinte saida: Perimetro, Area.");
	
	float raio;
	
	print("Por favor informe o raio do circulo:");
	scanf("%f", &raio);
	
	float perimetro = 2 * M_PI * raio;
	float area = M_PI * pow(raio, 2);
	
	printf("O circulo de raio = %.2f possui:\n\tPerimetro:\t% 8.2f\n\tArea:\t\t% 8.2f\n", raio, perimetro, area);
	
	print("\n------------------------------\n");
	
}

void ex12(){
	
	print("\n------------------------------\n");
	
	print("Escrever um algoritmo que leia:\n\tA percentagem do IPI a ser acrescida no valor das pecas;\n\tO codigo da peca 1, valor unitario da peca 1, quantidade de pecas 1;\n\tO codigo da peca 2, valor unitario da peca 2, quantidade de pecas 2.\nO algoritmo deve calcular o valor total a ser pago e apresentar o resultado.");
	
	float ipi;
	
	print("Por favor informe o IPI (em %):");
	scanf("%f", &ipi);
	
	ipi /= 100;
	
	char codigo1[17], codigo2[17];
	
	float valor_unitario1, valor_unitario2;
	
	int quant1, quant2;
	
	print("Por favor informe o codigo da peca 1:");
	scanf("%s", codigo1);
	print("Por favor informe o valor unitario da peca 1:");
	scanf("%f", &valor_unitario1);
	print("Por favor informe o quantidade de pecas 1:");
	scanf("%d", &quant1);
	
	print("Por favor informe o codigo da peca 2:");
	scanf("%s", codigo2);
	print("Por favor informe o valor unitario da peca 2:");
	scanf("%f", &valor_unitario2);
	print("Por favor informe a quantidade de pecas 2:");
	scanf("%d", &quant2);
	
	print("\n");
	
	printf(" |%-16s|%-16s|%-16s|%-16s|\n", "Codigo da peca", "Valor unit.", "Quantidade", "SubTotal");
	
	print(" ---------------------------------------------------------------------");
	
	float subtotal1 = valor_unitario1 * quant1, subtotal2 = valor_unitario2 * quant2;
	
	printf(" |%-16s|%-16.2f|%-16d|%-16.2f|\n", codigo1, valor_unitario1, quant1, subtotal1);
	printf(" |%-16s|%-16.2f|%-16d|%-16.2f|\n", codigo2, valor_unitario2, quant2, subtotal2);

	print(" ---------------------------------------------------------------------");
	
	float total = (subtotal1 + subtotal2) * (ipi + 1);
	
	printf(" |%-50s|%-16.2f|\n", "Total: (com IPI)", total);
	
	print(" ---------------------------------------------------------------------");

	print("\n------------------------------\n");
	
}

void ex13(){
		
	print("\n------------------------------\n");

	print("Escrever um algoritmo que calcule os sucessivos valores de E usando a serie abaixo e considerando os primeiros 3 termos, depois 4 termos e, por fim, 5 termos.");
	
	float e = 1 + (1. / 1) + (1. / (2 * 1)) + (1. / (3 * 2 * 1));
	
	printf("%f\n", e);

	e += (1. / (4 * 3 * 2 * 1));
	
	printf("%f\n", e);
	
	e += (1. / (5 * 4 * 3 * 2 * 1));
	
	printf("%f\n", e);
	
	print("\n------------------------------\n");
	
}

int main(int argc, char **argv) {
	
	print("LISTA DE EXERCICIOS DE FDA - 02");
	ex13();
	
	return 0;
}
