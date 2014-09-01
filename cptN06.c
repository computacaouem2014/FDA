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
		int count = (num1 - num2) / 2;
		if (num1 % 2 == 0 || num2 % == 0) count++;
		printf("Quantidade de numeros pares entre %d e %d = %d", num2, num1, count);
	} else {
		printf("Voce informou dois numeros iguais.");
	}
}

void ex2() {
	int prime(int n) {
		if (n < 3) return n > 1;
		if (n % 2 == 0 || n % 3 == 0) return 1;
		for (int i = 5, l = sqrt(n); i < l; i += 6){
			if (n % i == 0 || n % (i + 2) == 0) return 0;
		}
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
	for (int i = 0; i < 15; i++) {
		if (altura[i] > altura[maior]) maior = i;
		if (altura[menor] > altura[i]) menor = i;
		if (sexo[i] == 0) homens++;
		else {
			soma += altura[i];
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
	float ctof(float c) return (c + 32) * (9. / 5);
	float ftoc(float f) return (f - 32) * (5. / 9);
	printf("|%12s\t|\t%-12s|", "CELSIUS", "FAHRENHEIT");
	for (int i = 40; i < 70; i++) {
		printf("|%10d\t|\t%-10.2f|", i, ctof(i));
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
