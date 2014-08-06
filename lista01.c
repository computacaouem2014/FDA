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
	
	print("1. E valido codificarmos um comando de atribuicao conforme abaixo?\n");
	
	print("Desconsiderando a falta de \";\"");
	print("I = I + 1\t\tValido!");
	print("X = -X\t\t\tValido!");
	print("-X = X\t\t\tInvalido!");
	print("A = B + A\t\tValido!");
	print("B + A = A\t\tInvalido!");
	print("RAIZ1 = -B / 2*A\tValido!");
	print("RAIZ1 = -B / (2*A)\tValido!");
	
	print("\n------------------------------\n");
	
}

void ex2(){
	
	print("\n------------------------------\n");
	
	print("2. Os dois ultimos comandos de atribuicao do exercicio anterior (letras f e g) tem o mesmo significado?\nExplicar por que.\n");
	
	int a = rand() % 10 + 2, b = rand() % 10 + 1;
	
	// Letra F:
	int raiz1 = -b / 2 * a;
	
	// Letra G:
	int raiz2 = -b / (2 * a);
	
	// Se possuirem o mesmo significado, sua comparacao sera verdadeira:
	bool igual = (raiz1 == raiz2);
	
	printf("\tValores:\n\t\ta=%d\n\t\tb=%d\n", a, b);
	printf("\t%d (0 = false, 1 = true)\n\n", igual);
	
	print("Nao possuem o mesmo significado. Embora a equacao tenha o mesmo resultado se a = 1.");
	print("Os operadores '*', '%' e '/' possuem a mesma precedencia e associatividade da esquerda para a direita.");
	print("Por conta disso, na primeira implementacao a divisao sera executada antes da multiplicacao pois esta mais a esquerda.");
	print("Enquanto que na segunda, o que estiver dentro dos parenteses, que possuem maior precedencia, sera executado primeiro, neste caso, a multiplicacao.");
	
	print("\n------------------------------\n");
	
}

void ex3(){
		
	print("\n------------------------------\n");

	print("3. Escrever as seguintes expressoes algebricas como expressoes aritmeticas na Linguagem C.\nTeste no computador se suas expressoes estao escritas corretamente, fornecendo os valores das variaveis usadas na expressao.\nConfira o resultado do computador com aquele calculado usando a calculadora.");
	
	// Letra A:
	float x = rand() % 5 + 1, i = rand() % 5 + 1, j = rand() % 5 + 1;
	float resultA = pow(x, i + j);
	
	print("\nLetra A:");
	printf("\tValores:\n\t\tx=%.2f\n\t\ti=%.2f\n\t\tj=%.2f\n", x, i , j);
	print("\tOperacao A: x ^ (i + j)");
	printf("\tResultado: %.2f\n", resultA);
		
	// Letra B:
	float a = rand() % 5 + 1, b = rand() % 5 + 1, c = rand() % 5 + 1;
	float resultB = (a + b) * (2 - ((pow(c, 2) / (1 - (pow(c, 3)))))); //
	
	print("\nLetra B:");
	printf("\tValores:\n\t\ta=%.2f\n\t\tb=%.2f\n\t\tc=%.2f\n", a, b , c);
	print("\tOperacao B: (a + b) * [ 2 - ( c^2 / [1 - c^3] ) ]");
	printf("\tResultado: %.6f\n", resultB);

	// Letra C:
	float y = rand() % 5 + 1;
	float resultC =  2 / (2 - (5 * y));
	
	print("\nLetra C:");
	printf("\tValores:\n\t\ty=%.2f\n", y);
	print("\tOperacao C: 2 / (2 - (5 * y))");
	printf("\tResultado: %.6f\n", resultC);

	// Letra D:
	float A = rand() % 5 + 1, B = rand() % 5 + 1, C = rand() % 5 + 1, D = rand() % 5 + 1;
	float resultD = A + (B / (C + D));
	
	print("\nLetra D:");
	printf("\tValores:\n\t\tA=%.2f\n\t\tB=%.2f\n\t\tC=%.2f\n\t\tD=%.2f\n", A, B , C, D);
	print("\tOperacao D: A + (B / (C + D))");
	printf("\tResultado: %.6f\n", resultD);
	
	// Letra E:
	float r = rand() % 5 + 1, s = rand() % 5 + 1, t = rand() % 5 + 1;
	float resultE = 1 / ((1/r) + (1/s) + (1/t));
	
	print("\nLetra E:");
	printf("\tValores:\n\t\tr=%.2f\n\t\ts=%.2f\n\t\tt=%.2f\n", r, s , t);
	print("\tOperacao E: 1 / ((1/r) + (1/s) + (1/t))");
	printf("\tResultado: %.6f\n", resultE);

	// Letra F:
	float m = rand() % 5 + 1, n = rand() % 5 + 1;
	float resultF = 20 / (m + n);
	
	print("\nLetra F:");
	printf("\tValores:\n\t\tm=%.2f\n\t\tn=%.2f\n", m, n);
	print("\tOperacao A: 20 / (m + n)");
	printf("\tResultado: %.4f\n", resultF);
	
	// Letra G (igual a letra B):
	print("\nLetra G: Repetida (letra B)");
	
	// Letra H:
	float p = rand() % 5 + 1, w = rand() % 5 + 1, u = rand() % 5 + 1, v = rand() % 5 + 1;
	while(v == u) {
		v = rand() % 5 + 1; // se v = u, teremos divisao por zero
	}
	float resultH = (p + (w / (u + v))) / (p - (w / (u - v)));
	
	print("\nLetra H:");
	printf("\tValores:\n\t\tp=%.2f\n\t\tw=%.2f\n\t\tu=%.2f\n\t\tv=%.2f\n", p, w, u, v);
	print("\tOperacao H: (p + (w / (u + v))) / (p - (w / (u - v)))");
	printf("\tResultado: %.4f\n", resultH);
	
	// Letra I:
	float _a = rand() % 5 + 1, _b = rand() % 5 + 1, _c = rand() % 5 + 1, _d = rand() % 5 + 1;
	float resultI = _a / (_b + (_c / _d));
	
	print("\nLetra I:");
	printf("\tValores:\n\t\t_a=%.2f\n\t\t_b=%.2f\n\t\t_c=%.2f\n\t\t_d=%.2f\n", _a, _b, _c, _d);
	print("\tOperacao I: _a / (_b + (_c / _d))");
	printf("\tResultado: %.6f\n", resultI);
	
	// Letra J:
	float N = rand() % 5 + 1;
	float resultJ = pow(1 + (1 / N), N) ;
	
	print("\nLetra J:");
	printf("\tValores:\n\t\tN=%.2f\n", N);
	print("\tOperacao J: (1 + (1 / N)) ^ N");
	printf("\tResultado: %.6f\n", resultJ);
	
	// Letra K:
	float X = rand() % 5 + 1, Y = rand() % 5 + 1;
	float resultK = 0.5 * (sqrt(pow(X, 2) + pow(Y, 2)));
	
	print("\nLetra K:");
	printf("\tValores:\n\t\tX=%.2f\n\t\tY=%.2f\n", X, Y);
	print("\tOperacao K: 0.5 * (sqrt(X^2 + Y^2))");
	printf("\tResultado: %.6f\n", resultK);
	
	// Letra L:
	float _A = rand() % 5 + 1, _B = rand() % 5 + 1, _C = rand() % 5 + 1;
	float resultL = sqrt(_A + _B) / (pow(_C, 2) - (2 * _A));
	
	print("\nLetra L:");
	printf("\tValores:\n\t\t_A=%.2f\n\t\t_B=%.2f\n\t\t_C=%.2f\n", _A, _B, _C);
	print("\tOperacao L: sqrt(_A + _B) / (_C^2 - (2 * _A))");
	printf("\tResultado: %.6f\n", resultL);
	
	// Letra M:
	float _x = rand() % 5 + 1, _y = rand() % 5 + 1, g = rand() % 5 + 1;
	float resultM = pow(_x / _y, g - 1);
	
	print("\nLetra M:");
	printf("\tValores:\n\t\t_x=%.2f\n\t\t_y=%.2f\n\t\tg=%.2f\n", _x, _y , g);
	print("\tOperacao M: (_x / _y) ^ (g - 1)");
	printf("\tResultado: %.6f\n", resultM);

	print("\n------------------------------\n");

}

void ex4(){
	
	print("\n------------------------------\n");

	print("4. Complete as seguintes tabelas da verdade.");

	int a, b;

	print("\nLetra A: [A != B]");
	
	print("\nA\tB\t[A != B]");
	
	a = 1; b = 1;
	printf("%d\t%d\t%d\n", a, b, a != b);
	
	a = 1; b = 0;
	printf("%d\t%d\t%d\n", a, b, a != b);
	
	a = 0; b = 1;
	printf("%d\t%d\t%d\n", a, b, a != b);
	
	a = 0; b = 0;
	printf("%d\t%d\t%d\n", a, b, a != b);
	
	print("\nLetra B: [!(A == !B)]");
	
	print("\nA\tB\t[!(A == !B)]");
	
	a = 1; b = 1;
	printf("%d\t%d\t%d\n", a, b, !(a == !b));
	
	a = 1; b = 0;
	printf("%d\t%d\t%d\n", a, b, !(a == !b));
	
	a = 0; b = 1;
	printf("%d\t%d\t%d\n", a, b, !(a == !b));
	
	a = 0; b = 0;
	printf("%d\t%d\t%d\n", a, b, !(a == !b));
	
	
	print("\nLetra C: [!A && !B]");
	
	print("\nA\tB\t[A != B]");
	
	a = 1; b = 1;
	printf("%d\t%d\t%d\n", a, b, !a && !b);
	
	a = 1; b = 0;
	printf("%d\t%d\t%d\n", a, b, !a && !b);
	
	a = 0; b = 1;
	printf("%d\t%d\t%d\n", a, b, !a && !b);
	
	a = 0; b = 0;
	printf("%d\t%d\t%d\n", a, b, !a && !b);

	print("\n------------------------------\n");

}

void ex5(){
	
	print("\n------------------------------\n");
	
	print("5. Seguindo atraves dos trechos de algoritmos abaixo, determine o valor final de X e de Y.");
	print("Em ambos os casos, considere os valores iniciais: X = 1.0 e Y = 1.0");
	
	float x = 1, y = 1, a, b;
	
	print("\nPrimeiro algoritmo:");
	print("\tA = X + 5.0\n\tB = Y + 3.0\n\tX = A + B\n\tY = X + A\n\tB = Y / 4.0 + X\n\tA = B / 2. + Y\n\tX = X + A + B - Y\n\tY = Y + B");
	
	// Primeiro algoritmo:
	a = x + 5;
	b = y + 3;
	x = a + b;
	y = x + a;
	b = y / 4.0 + x;
	a = b / 2. + y;
	x = x + a + b - y;
	y = y + b;
	
	printf("Valores finais:\n\tx:%.2f\n\ty:%.2f\n", x, y);
	
	x = 1, y = 1, a = 0, b = 0;
	
	print("\nSegundo algoritmo:");
	print("\tX = X + Y\n\tX = X*2\n\tA = X + Y\n\tB = A - 5.0\n\tY = A\n\tB = B / Y + 2.0\n\tX = (Y + A) / B\n\tY = Y / A + X /B");

	// Segundo algoritmo:
	x = x + y;
	x = x * 2;
	a = x + y;
	b = a - 5.0;
	y = a;
	b = b / y + 2.0;
	x = (y + a) / b;
	y = y / a + x / b;
	
	printf("Valores finais:\n\tx:%.2f\n\ty:%.2f\n", x, y);
	
	print("\n------------------------------\n");
	
}

void ex6(){
	
	print("\n------------------------------\n");
	
	print("6. Elaborar um algoritmo para ler a base e a altura de um triangulo e imprimir sua area dada por: area = 1/2 * base * altura");
	
	int base, altura;
	float area;
	
	print("Digite o valor da base do triangulo:");
	scanf("%d", &base);
	
	print("Digite o valor da altura do triangulo:");
	scanf("%d", &altura);
	
	area = (base * altura) / 2;
	
	printf("Base: %d\nAltura: %d\nArea: (%d * %d) / 2 = %d / 2 = %.2f", base, altura, base, altura, base * altura, area);
	
	print("\n------------------------------\n");
	
}

int main(int argc, char **argv) {

	// Inicializar o gerador aleatorio
	srand(time(NULL));
	
	/**
	 * Como usar o rand() para gerar números aleatórios pra teste dos algoritmos:
	 * Incluir a biblioteca padrão: "#include <stdlib.h>"
	 * Incluir a biblioteca time: "#include <time.h>"
	 * Inicializar a "seed" do gerador com essa função: "srand(time(NULL));"
	 * OBS.: Não é necessário realizar a inicialização mais que uma vez.
	 * Formato para uso: "rand() % num_max + inc_num_min;"
	 * Que resulta em um número aleatório entre '0 + inc_num_min' inclusivo e 'num_max + inc_num_min' exclusivo.
	 * Exemplo: "rand() % 10 + 1;"
	 * Gera um número entre [1, 11), ou seja, um destes: { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
	 * */
	
	// Titulo
	print("LISTA DE EXERCICIOS DE FDA - 01");
	
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	
	getchar();

	return 0;
}
