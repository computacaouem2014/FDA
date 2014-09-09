#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

void print(char* str){
	printf("%s\n", str);
}

void ex1(){
	
	print("\n------------------------------\n");
	
	print("Dados tres valores a, b e c, correspondentes aos lados de um triangulo.\nFaca um programa C, que leia os lados e informe o tipo de triangulo.");
	
	int a, b, c;
	
	print("Informe os tres lados do triangulo:");
	scanf("%d%d%d", &a, &b, &c);
	
	int lado1, lado2, lado3;
	
	void setVal(n1, n2, n3){
		// #preguica
		lado1 = n1; lado2 = n2; lado3 = n3;
	}
	
	if (a > b){
		if (b < c){
			// a > b > c
			setVal(a, b, c);
		} else {
			if (a > c){
				// a > c > b
				setVal(a, c, b);
			} else {
				// c > a > b
				setVal(c, a, b);
			}
		}
	} else {
		if (a > c){
			// b > a > c
			setVal(b, a, c);
		} else {
			if (b > c){
				// b > c > a
				setVal(b, c, a);
			} else {
				// c > b > a
				setVal(c, b, a);
			}
		}
	}
	
	if (lado3 > lado1 + lado2){
		print("Esses valores nao correspondem ao lado de um triangulo.");
	} else {
		if (pow(lado3, 2) < pow(lado1, 2) + pow(lado2, 2)){
			print("Esse valores correspondem a um triangulo obtusangulo.");
		} else if(pow(lado3, 2) > pow(lado1, 2) + pow(lado2, 2)) {
			print("Esse valores correspondem a um triangulo acutangulo.");
		} else {
			print("Esse valores correspondem a um triangulo retangulo.");
		}
	}
	
	print("\n------------------------------\n");
	
}

void ex2(){
		
	print("\n------------------------------\n");
	
	print("Verifique se o algoritmo abaixo esta correto. Se nao, explique o(s) erro(s) e corrija-o(s).");
	
	/* Incorreto
	int a, b, c, menor;
	 * 
	printf("Digite o primeiro numero: ");
	scanf("%d", &a);
	 * 
	printf("Digite o segundo numero: ");
	scanf("%d", &b);
	 * 
	printf("Digite o terceiro numero: ");
	scanf("%d", &c);
	 * 
	if (a < b && b < c)
		// a < b < c
		menor = a;
	else {
		if (c < a && a < b)
			// c < a < b
			menor = c;
		else
			// quando (a < b) e falso, o algoritmo chega aqui e
			// teremos que (b <= a)
			// mas nao sabemos se ele e maior ou menor que o c
			// sendo portanto incorreto afirmar que ele e o menor
			// para testar essa condicao use um valor de b que
			// seja menor que a porem maior que c
			menor = b;
	}
	 * 
	printf("Menor: %d\n", menor);*/
	
	// Corrigido
	int a, b, c, menor;
	
	printf("Digite o primeiro numero: ");
	scanf("%d", &a);
	
	printf("Digite o segundo numero: ");
	scanf("%d", &b);
	
	printf("Digite o terceiro numero: ");
	scanf("%d", &c);
	
	if (a < b && b < c)
		menor = a;
	else {
		if (c < a && a < b)
			menor = c;
		else
			if (b < c)
				menor = b;
			else
				menor = c;
	}
	
	printf("Menor: %d\n", menor);
	
	print("\n------------------------------\n");
	
}

void ex3(){
	
	print("\n------------------------------\n");
	
	print("Indique, para cada expressao logica abaixo, se ela retornara um valor TRUE ou FALSE.");
	
	// a)
	if (1 > 3 || (! (5 <= 8)) && 6 == 7){
		
		print("[1 > 3 || (! (5 <= 8)) && 6 == 7] e TRUE.");
		
	} else {
		
		print("[1 > 3 || (! (5 <= 8)) && 6 == 7] e FALSE.");
		
	}
	
	// b)
	if (!((2 >= 5) && (5 <= 8) || ((4 + 3) > 7))){
		
		print("[!((2 >= 5) && (5 <= 8) || ((4 + 3) > 7))] e TRUE.");
		
	} else {
		
		print("[!((2 >= 5) && (5 <= 8) || ((4 + 3) > 7))] e FALSE.");
		
	}
	
	// c)
	if (7%4 == 3 && !(20/5 == 5)){
		
		print("[7%4 == 3 && !(20/5 == 5)] e TRUE.");
		
	} else {
		
		print("[7%4 == 3 && !(20/5 == 5)] e FALSE.");
		
	}
	
	// d)
	if ((23.1 >= 64/3) || ('b' == 'a')){
		
		print("[(23.1 >= 64/3) || ('b' == 'a')] e TRUE.");
		
	} else {
		
		print("[(23.1 >= 64/3) || ('b' == 'a')] e FALSE.");
		
	}
		
	print("\n------------------------------\n");
	
}

void ex4(){
		
	print("\n------------------------------\n");
	
	print("Leia, em um algoritmo, os coeficientes de uma equacao do segundo grau. Calcule suas raizes e informe-as.");
	
	print("Equacao do 2o grau: [ A x^2 + B x + C = 0 ]");
	
	int a, b, c;
	float raiz1, raiz2, delta;
	
	print("Informe o valor do coeficiente A:");
	scanf("%d", &a);
	
	print("Informe o valor do coeficiente B:");
	scanf("%d", &b);
	
	print("Informe o valor do coeficiente C:");
	scanf("%d", &c);
	
	delta = pow(b, 2) - (4 * a * c);
	
	if (delta < 0){
		
		printf("A equacao %dx^2 + %dx + %d nao possui raizes reais.\n", a, b, c);
		
	} else {
		
		raiz1 = (-b + sqrt(delta)) / (2 * a);
		raiz2 = (-b - sqrt(delta)) / (2 * a);
		
		if (raiz1 == raiz2){
			
			printf("A equacao %dx^2 + %dx + %d uma raiz real.\n\tx1 = x2 = %.2f.\n", a, b, c, raiz1);
			
		} else {
			
			printf("A equacao %dx^2 + %dx + %d possui duas raizes reais.\n\tx1 = %.2f\n\tx2 = %.2f\n", a, b, c, raiz1, raiz2);
			
		}
		
	}
	
	print("\n------------------------------\n");
	
}

void ex5(){
	
	print("\n------------------------------\n");
	int i;
	for (i = 0; i < 3; i++){
		float x, y, r1, r2;
		int z;
		// scanf("%f", x);
		// scanf("%f", y);

		char str[16];

		if (i == 0){
			x = 0;
			y = 2;
			strcpy(str, "x = 0; y = 2;");
		} else if (i == 1){
			x = -4;
			y = 2;
			strcpy(str, "x = -4; y = 2;");
		} else {
			x = 3;
			y = 0;
			strcpy(str, "x = 3; y = 0;");
		}
		
		// Cabecalho
		print("-------------------------------------------");
		printf("|%4s%-6s%4s|%6s%-14s%6s|\n", "", "Pontos", "", "", str, "");
		print("-------------------------------------------");
		
		//1
		printf("|%4s%-6s%4s|%8s|%8s|%8s|\n", "", "1", "", "--------","--------","--------");
		
		z = 0;
		
		//2
		printf("|%4s%-6s%4s|%8s|%8s|%8d|\n", "", "2", "", "--------","--------", z);
		
		r1 = x - 2 * y;
		
		//3
		printf("|%4s%-6s%4s|%8.2f|%8s|%8d|\n", "", "3", "", r1, "--------", z);
		
		r2 = -2 * x + 4 * y;
		
		if ((r1 + r2) < 0){
			if (x > 0){
				if (y >= 0)
					z = 10;
			}
		}
		
		//4
		printf("|%4s%-6s%4s|%8.2f|%8.2f|%8d|\n", "", "4", "", r1, r2, z);
		
		if ((x < 0) && (y > 0))
			z = 100;
		else {
			if (r1 > r2)
				z = 1234;
			else
				z = 1;
		}
		
		//5
		printf("|%4s%-6s%4s|%8.2f|%8.2f|%8d|\n", "", "5", "", r1, r2, z);
		print("-------------------------------------------");
	}

	//printf("z: %i\n", z);
	
	print("\n------------------------------\n");
	
}

void ex6(){
	
	print("\n------------------------------\n");
	
	int a, b, c;
	float m;
	
	// scanf("%i", &a); 1
	a = 1;
	// scanf("%i", &b); 13
	b = 13;
	// scanf("%i", &c); 15
	c = 15;

	print("Algoritmo 1: ");
		// 1
	{
		m = a + b + c / 3;

		if (m > 10){
			print("100");
		}
		
		print("programa encerrado");
	}
	
	print("\nAlgoritmo 2: ");
		// 2
	{
		m = a + b + c;
		m = m / 3; // m /= 3;

		if (m > 10){
			print("100");
		}
		
		print("programa encerrado");
	}
	
	print("\n------------------------------\n");
	
}

int main(int argc, char **argv) {

	print("LISTA DE EXERCICIOS DE FDA - 03");
	
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	
	return 0;
	
}