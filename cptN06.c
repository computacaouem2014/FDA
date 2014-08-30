#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void ex1() {
	int num1, num2;
	printf("Informe o primeiro numero: ");
	scanf("%d", & num1);
	printf("Informe o segundo numero: ");
	scanf("%d", & num2);
	if (num1 < num2) {
		float media = (num1 + num2) / 2.;
		printf("Media dos numeros entre %d e %d = %.2f", num1, num2, media);
	} else if (num1 > num2) {
		int count;
		for (int i = num2; num2 <= num1; i++)
			if (i % 2 == 0) count += 1;
		printf("Quantidade de numeros pares entre %d e %d = %d", num2, num1, count);
	} else {
		printf("Voce informou dois numeros iguais.");
	}
}

void ex2() {
	int prime(int n) {
		if (n == 2 || n == 3 || n == 5) return 1; // porque dois e tres sao primos
		if (!((n % 10 == 1) || (n % 10 == 3) || (n % 10 == 7) || (n % 10 == 9)) || n) return 0;
		/*
		evita cálculos a toa pois os números primos (exceto o 2) acabam em
		1, 3, 7 ou 9 pois, se acaba em 0, 2, 4, 6, 8 o número é
		divisível por 2 e se acaba em 5 e divisível por 5
		e ainda checamos se o numero é 1, pois 1 também não é primo.
		 */
		printf("\tCalculando...\n");
		for (int i = 3, l = sqrt(n); i <= l; i += 2)
			if (n % i == 0) return 0;
		// Se o número acaba em 1, 3, 7, 9 e não é o 1 então vamos calcular
		// seus divisores. No caso de encontrarmos ao menos 1 divisor, já
		// podemos retornar falso (0) e começaremos no 3 pois se chegamos
		// a essa parte, os números acabam ou em 1, 3, 7 ou 9 então não
		// temos múltiplos de 2, por não termos múltiplos de 2, então
		// podemos ignorar todos os pares na checagem de divisores, por
		// isso aumentaremos o i de 2 em 2. Se não houver divisores
		// retornaremos True (1) pois o número é primo.
		// De acordo com uma das aulas de MD2, os divisores de um número
		// estão entre 1 e a raiz quadrada de um número. Por isso o limite
		// do for loop será a raiz do número. Só a calcularemos uma vez
		// e colocaremos o resultado em l, pois a função de raiz custa
		// caro em termos de processamento, ou seja não seria bom chama-la
		// a cada loop do for.
		return 1;
	}
	int num;
	printf("Informe um numero: "); scanf("%d", & num);
	if (prime(num)) printf("\t\t%d e primo!\n", num);
	else printf("\t\t%d nao e primo!\n", num);
}

void ex3() {
	float altura[15];
	char sexo[15];
	for (int i = 0; i < 15; i++) {
		altura[i] = (rand() % 50 + 151) / 100.; // alturas entre 1.50 e 2.00
		sexo[i] = (rand() % 2); // 0 = M, 1 = F
	}
	int maior = 0, menor = 0, homens = 0, mulheres = 0;
	float soma = 0;
	for (int i = 1; i < 15; i++) {
		if (altura[i] > altura[maior]) {
			maior = i;
		}
		if (altura[menor] > altura[i]) {
			menor = i;
		}
		if (sexo[i] == 0) homens++;
		else {
			soma = altura[i];
			mulheres++;
		}
	}
	float mediaM = soma / mulheres;
	printf("Homens:\t\t%d", homens);
	printf("Mulheres:\t\t%d", mulheres);
	printf("Maior Altura:\t\t%d S=%c", altura[maior], sexo[maior]);
	printf("Menor Altura:\t\t%d S=%c", altura[menor], sexo[menor]);
	printf("Media Mulheres: %d", mediaM);
}

void ex4() {
	float ctof(float c) {
		return (c + 32) * (9. / 5);
	}
	float ftoc(float f) {
		return (f - 32) * (5. / 9);
	}
	printf("|%12s\t|\t%-12s|", "CELSIUS", "FAHRENHEIT");
	for (int i = 40; i < 70; i++) {
		printf("|%10d\t|\t%-10d|", i, ctof(i));
	}
}

void ex5() {
	// Vou reclamar com o professor por que essa questão não faz sentido pra mim.
}

int main() {
	print("LISTA DE EXERCICIOS DE FDA - 05");

	srand(time(NULL))

	ex1();
	ex2();
	ex3();
	ex4();
	ex5();

	getchar();
	getchar();

	return 0;
}
