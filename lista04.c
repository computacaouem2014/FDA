#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print(char * str) {
	printf("%s\n", str);
}

void ex1() {

	print("\n------------------------------\n");

	int a, b, x;

	print("Informe o valor de x: ");
	scanf("%d", & x);

	print("Informe o valor de a: ");
	scanf("%d", & a);

	print("Informe o valor de b: ");
	scanf("%d", & b);

	while (a + b == 0) {
		print("Informe outros valores para a e b, pois a + b = 0");

		print("Informe o novo valor de a: ");
		scanf("%d", & a);

		print("Informe o novo valor de b: ");
		scanf("%d", & b);
	}

	/*
	if (a + b == 0){
	    print("Divisao por zero.");
	}
	 */

	float resultado = x / (a + b);

	printf("Resultado: %.2f\n", resultado);

	print("\n------------------------------\n");

}

void ex2() {

	print("\n------------------------------\n");

	int num;

	print("Informe um numero: ");
	scanf("%d", & num);

	while (!(num > 0)) {
		print("Entrada invalida, tente novamente.");
		print("Informe um numero: ");
		scanf("%d", & num);
	}

	float resultado = sqrt(num);

	printf("Resultado: %.2f\n", resultado);

	print("\n------------------------------\n");

}

void ex3() {

	print("\n------------------------------\n");

	int ano, leap;

	print("Informe um ano: ");
	scanf("%d", & ano);

	// Creditos: Wikipedia.

	if (!(ano % 4 == 0)) {
		leap = 0;
	} else if (!(ano % 100 == 0)) {
		leap = 1;
	} else if (!(ano % 400 == 0)) {
		leap = 0;
	} else {
		leap = 1;
	}

	// Creditos: Wikipedia.
	// Ja dizia alguem muito inteligente: "pra que reinventar a roda?"

	printf("O ano %04d %se bissexto.\n", ano, leap == 1 ? "" : "nao ");

	print("\n------------------------------\n");

}

void ex4() {

	print("\n------------------------------\n");

	int salario;

	print("Informe seu salario atual: ");
	scanf("%d", & salario);

	if (salario > 2000)
		print("Voce nao recebera aumento.\n");
	else
		printf("Seu novo salario e: R$%.2f\n", salario * 1.3);

	print("\n------------------------------\n");

}

void ex5() {

	print("\n------------------------------\n");

	int a, b, c;

	print("Informe a medida do lado a:");
	scanf("%d", & a);

	while (!(a > 0)) {
		print("Valor invalido, tente novamente:");
		scanf("%d", & a);
	}

	print("Informe a medida do lado b:");
	scanf("%d", & b);


	while (!(b > 0)) {
		print("Valor invalido, tente novamente:");
		scanf("%d", & b);
	}

	print("Informe a medida do lado c:");
	scanf("%d", & c);

	while (!(c > 0)) {
		print("Valor invalido, tente novamente:");
		scanf("%d", & c);
	}

	float s = (a + b + c) / 2.;

	float area = sqrt(s * (s - a) * (s - b) * (s - c));

	printf("A area do triangulo e: %.2f u.a.\n", area);

	print("\n------------------------------\n");

}

void ex6() {

	print("\n------------------------------\n");

	int opcao;

	while (1) {

		print("\nDigite:");
		print("\t[1] Para calcular o volume de uma esfera.");
		print("\t[2] Para calcular o volume de um paralelepipedo.");
		print("\t[0] Para sair.");
		print("Informe a opcao desejada:");
		scanf("%d", & opcao);

		if (opcao == 0) {
			break;
		} else if (opcao == 1) {
			int raio;

			print("Informe o raio da esfera:");
			scanf("%d", & raio);

			while (!(raio > 0)) {
				print("Valor invalido, tente novamente:");
				scanf("%d", & raio);
			}

			float volume = (4 * 3.14 * pow(raio, 3)) / 3.;

			printf("O volume da esfera de raio = %d e: %.2f u.v.\n", raio, volume);
		} else if (opcao == 2) {
			int base, largura, altura;

			print("Informe a base do paralelepipedo:");
			scanf("%d", & base);

			while (!(base > 0)) {
				print("Valor invalido, tente novamente:");
				scanf("%d", & base);
			}

			print("Informe a largura do paralelepipedo:");
			scanf("%d", & largura);

			while (!(largura > 0)) {
				print("Valor invalido, tente novamente:");
				scanf("%d", & largura);
			}

			print("Informe a largura do paralelepipedo:");
			scanf("%d", & altura);

			while (!(altura > 0)) {
				print("Valor invalido, tente novamente:");
				scanf("%d", & altura);
			}

			int area = base * altura * largura;

			printf("O volume do paralelepipedo (%dx%dx%d) e: %d\n u.v.", base, largura, altura, area);
		} else {
			print("Opcao invalida!");
		}

	}
	print("\n------------------------------\n");

}

int main() {

	print("LISTA DE EXERCICIOS DE FDA - 04");

	ex6();

	getchar();
	getchar();

	return 0;
}