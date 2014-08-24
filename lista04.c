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

	printf("Resultado: %.2f\n", pow(resultado,0.5);

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

	/*
	if (leap == 1)
	    printf("O ano %04d e bissexto.\n", ano);
	else
	    printf("O ano %04d nao e bissexto.\n", ano);
	 */

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

	int a, b, c, retangulo;

	while (!retangulo) {
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
		if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)) {
			retangulo = 1;
		} else {
			printf("Essas medidas nao formam um triangulo retangulo.");
			printf("Por favor tente novamente.");
		}
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

void ex7() {

	print("\n------------------------------\n");

	float ch, ph;

	print("Informe a concentracao de ions H+:");
	scanf("%f", & ch);

	while (!(ch > 0)) {
		print("Valor invalido, tente novamente:");
		scanf("%f", & ch);
	}

	ph = -1 * log10(ch);

	/*
	if (ph > 7)
	    printf("O pH e: %.2f (basico).", ph);
	else if (ph == 7)
	    printf("O pH e: %.2f (neutro).", ph);
	else
	    printf("O pH e: %.2f (acido).", ph);
	 */

	printf("O pH e: %.2f (%s).", ph, ph > 7 ? "basico" : (ph == 7 ? "neutro" : "acido"));

	print("\n------------------------------\n");

}

void ex8() {

	print("\n------------------------------\n");

	int hora_inicial, hora_final, minuto_inicial, minuto_final;

	print("Informe o horario de inicio do jogo:");

	printf("Horas: ");
	scanf("%d", & hora_inicial);
	while (!(hora_inicial >= 0 && hora_inicial < 24)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%d", & hora_inicial);
	}

	printf("Minutos: ");
	scanf("%d", & minuto_inicial);
	while (!(minuto_inicial >= 0 && minuto_inicial < 60)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%d", & minuto_inicial);
	}

	print("Informe o horario de termino do jogo:");

	printf("Horas: ");
	scanf("%d", & hora_final);
	while (!(hora_final >= 0 && hora_final < 24)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%d", & hora_final);
	}

	printf("Minutos: ");
	scanf("%d", & minuto_final);
	while (!(minuto_final >= 0 && minuto_final < 60)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%d", & minuto_final);
	}

	int duracao;

	duracao = (hora_final * 60 + minuto_final) - (hora_inicial * 60 + minuto_inicial);

	if (duracao < 0) {
		duracao += 1440;
	}

	printf("\nA duracao do jogo foi de: %02dh:%02dm\n", duracao / 60, duracao % 60);

	print("\n------------------------------\n");

}

void ex9() {

	print("\n------------------------------\n");

	int cargo;
	float salario_atual;

	printf("Informe o codigo de cargo do funcionario: ");
	scanf("%d", & cargo);
	while (!(cargo > 0 && cargo < 6)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%d", & cargo);
	}

	printf("Informe o salario atual do funcionario: ");
	scanf("%f", & salario_atual);
	while (!(salario_atual > 0)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%f", & salario_atual);
	}

	float aumento, salario_novo;

	if (cargo == 1) {
		aumento = .5 * salario_atual;
		salario_novo = salario_atual + aumento;
		printf("\nCargo: Escrituario\nAumento: R$%.2f\nNovo salario: R$%.2f\n", aumento, salario_novo);
	} else if (cargo == 2) {
		aumento = .35 * salario_atual;
		salario_novo = salario_atual + aumento;
		printf("\nCargo: Secretario\nAumento: R$%.2f\nNovo salario: R$%.2f\n", aumento, salario_novo);
	} else if (cargo == 3) {
		aumento = .2 * salario_atual;
		salario_novo = salario_atual + aumento;
		printf("\nCargo: Caixa\nAumento: R$%.2f\nNovo salario: R$%.2f\n", aumento, salario_novo);
	} else if (cargo == 4) {
		aumento = .1 * salario_atual;
		salario_novo = salario_atual + aumento;
		printf("\nCargo: Gerente\nAumento: R$%.2f\nNovo salario: R$%.2f\n", aumento, salario_novo);
	} else if (cargo == 5) {
		aumento = .0 * salario_atual;
		salario_novo = salario_atual + aumento;
		printf("\nCargo: Diretor\nAumento: R$%.2f\nNovo salario: R$%.2f\n", aumento, salario_novo);
	}

	print("\n------------------------------\n");

}

void ex10() {

	print("\n------------------------------\n");

	float peso, altura;

	printf("Informe o peso: ");
	scanf("%f", & peso);
	while (!(peso > 0)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%f", & peso);
	}

	printf("Informe a altura: ");
	scanf("%f", & altura);
	while (!(altura > 0)) {
		printf("Valor invalido, tente novamente: ");
		scanf("%f", & altura);
	}

	int grupo = 0;
	char grupos[10] = "ABCDEFGHI";

	if (peso > 90)
		grupo += 6;
	else if (peso > 60)
		grupo += 3;

	if (altura > 1.7)
		grupo += 2;
	else if (altura >= 1.2)
		grupo++;

	printf("Sua classificacao e: %c\n", grupos[grupo]);

	print("\n------------------------------\n");

}

int main() {

	print("LISTA DE EXERCICIOS DE FDA - 04");

	ex10();

	getchar();
	getchar();

	return 0;
}
