#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


void printMatrix(int m, int n, int arr[m][n]){
	if (m*n > n){
		printf("\n⎡");
		for (int j = 0; j < n; j++){
			printf("%6d ", arr[0][j]);
		}
		printf("⎤\n");
		printf("⎢");
		for (int k = 0; k < n; k++){
			printf("       ");
		}
		printf("⎥\n");
		for (int i = 1; i < m-1; i++){
			if (i != 1){
				printf("⎢");
				for (int k = 0; k < n; k++){
					printf("       ");
				}
				printf("⎥\n");
			}
			printf("⎢");
			for (int j = 0; j < n; j++){
				printf("%6d ", arr[i][j]);
			}
			printf("⎥\n");
		}
		printf("⎢");
		for (int k = 0; k < n; k++){
			printf("       ");
		}
		printf("⎥\n");
		printf("⎣");
		for (int j = 0; j < n; j++){
			printf("%6d ", arr[m-1][j]);
		}
		printf("⎦\n\n");
	} else if (m == 1) {
		printf("\n[");
		for (int i = 0; i < n; i++){
			printf("%6d ", arr[0][i]);
		}
		printf("]\n\n");
	} else {
		printf("\n[]\n\n");
	}
}

void printMatrixC(int m, int n, char arr[m][n]){
	if (m*n > n){
		printf("\n⎡");
		for (int j = 0; j < n; j++){
			printf("%6c ", arr[0][j]);
		}
		printf("⎤\n");
		printf("⎢");
		for (int k = 0; k < n; k++){
			printf("       ");
		}
		printf("⎥\n");
		for (int i = 1; i < m-1; i++){
			if (i != 1){
				printf("⎢");
				for (int k = 0; k < n; k++){
					printf("       ");
				}
				printf("⎥\n");
			}
			printf("⎢");
			for (int j = 0; j < n; j++){
				printf("%6c ", arr[i][j]);
			}
			printf("⎥\n");
		}
		printf("⎢");
		for (int k = 0; k < n; k++){
			printf("       ");
		}
		printf("⎥\n");
		printf("⎣");
		for (int j = 0; j < n; j++){
			printf("%6c ", arr[m-1][j]);
		}
		printf("⎦\n\n");
	} else if (m == 1) {
		printf("\n[");
		for (int i = 0; i < n; i++){
			printf("%6c ", arr[0][i]);
		}
		printf("]\n\n");
	} else {
		printf("\n[]\n\n");
	}
}

void printMatrixF(int m, int n, float arr[m][n]){
	if (m*n > n){
		printf("\n⎡");
		for (int j = 0; j < n; j++){
			printf("%6.2f ", arr[0][j]);
		}
		printf("⎤\n");
		printf("⎢");
		for (int k = 0; k < n; k++){
			printf("       ");
		}
		printf("⎥\n");
		for (int i = 1; i < m-1; i++){
			if (i != 1){
				printf("⎢");
				for (int k = 0; k < n; k++){
					printf("       ");
				}
				printf("⎥\n");
			}
			printf("⎢");
			for (int j = 0; j < n; j++){
				printf("%6.2f ", arr[i][j]);
			}
			printf("⎥\n");
		}
		printf("⎢");
		for (int k = 0; k < n; k++){
			printf("       ");
		}
		printf("⎥\n");
		printf("⎣");
		for (int j = 0; j < n; j++){
			printf("%6.2f ", arr[m-1][j]);
		}
		printf("⎦\n\n");
	} else if (m == 1) {
		printf("\n[");
		for (int i = 0; i < n; i++){
			printf("%6.2f ", arr[0][i]);
		}
		printf("]\n\n");
	} else {
		printf("\n[]\n\n");
	}
}

void ex1(){
	system("clear");
	int m = 8, n = 8;
	float a[m][n];
	for (int k = 0; k<m; k++){
		for (int j = 0; j<n; j++){
			printf("Digite o termo [%d][%d]: ", k + 1, j + 1);
			scanf("%f", &a[k][j]);
		}
	}
	float maior = a[0][0];
	for (int k = 1; k<m; k++){
		if (a[k][k] > maior) maior = a[k][k];
        }
	system("clear");
	printf("\n\t\tMaior = %f\n\n", maior);
	for (int k = 0; k<m; k++){
                for (int j = 0; j<n; j++){
			a[k][j] /= maior;
                }
        }
	printMatrixF(m, n, a);
}

void ex2(){
	system("clear");
	int m = 10, n = 10, a[m][n], menu, exit = 1, quadrada = 1;
	if (m!=n) quadrada = 0;
	for (int k = 0; k<m; k++){
		for (int j = 0; j<n; j++){
			printf("Digite o elemento [%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	system("clear");
	do{
		printMatrix(m, n, a);
		printf("\tEscolha uma opcao: ");
		printf("\n\t\t1.Trocar uma linha com outra");
		printf("\n\t\t2.Trocar uma coluna com outra");
		printf("\n\t\t3.Trocar diagonal principal com secundaria");
		printf("\n\t\t4.Trocar linha com coluna");
		printf("\n\t\t0.Sair");
		printf("\n\tOpcao: ");
		scanf("%d", &menu);
		switch(menu){
			case 1:{
				system("clear");
				int line1 = -1, line2 = -1, aux;
				while (line1 > m || line1 <= 0){
					printf("Digite o indice da primeira linha: ");
					scanf("%d", &line1);
				}
				line1--; // Usuario digita linha diferente da maquina
				while (line2 > m || line2 <= 0){
					printf("Digite o indice da segunda linha: ");
					scanf("%d", &line2);
				}
				line2--; // Usuario digita linha diferente da maquina
				system("clear");
				for (int k = 0; k<m; k++){
					aux = a[line1][k];
					a[line1][k] = a[line2][k];
					a[line2][k] = aux;
				}
				break;
			}
			case 2:{
				system("clear");
				int col1 = -1, col2 = -1, aux;
				while (col1 > m || col1 <= 0){
					printf("Digite o indice da primeira coluna: ");
					scanf("%d", &col1);
				}
				col1--; // Usuario digita coluna diferente da maquina
				while (col2 > m || col2 <= 0){
					printf("Digite o indice da segunda coluna: ");
					scanf("%d", &col2);
				}
				col2--; // Usuario digita coluna diferente da maquina
				system("clear");
				for (int k = 0; k<n; k++){
					aux = a[k][col1];
					a[k][col1] = a[k][col2];
					a[k][col2] = aux;
				}
				break;
			}
			case 3:{
				system("clear");
				if (quadrada){
					int aux;
					for (int k = 0; k<m; k++){
						aux = a[k][k];
						a[k][k] = a[k][m-k-1];
						a[k][m-k-1] = aux;
					}
				} else {
					printf("Esta opcao so pode ser usada em matrizes quadradas. \n\n");
				}
				break;
			}
			case 4:{
				system("clear");
				if (quadrada){
					int line = -1, col = -1, aux;
					while (line > m || line <= 0){
						printf("Digite a linha que deseja trocar: ");
						scanf("%d", &line);
					}
					line--; //Usuario entra numero diferente maquina
					while (col > m || col <= 0){
						printf("Digite a coluna que deseja trocar com a linha %d: ", line);
						scanf("%d", &col);
					}
					col--; //Usuario entra numero diferente maquina
					system("clear");
					for (int k = 0; k<m; k++){
						aux = a[line][k];
						a[line][k] = a[k][col];
						a[k][col] = aux;
					}
				} else {
					printf("Esta opcao so pode ser usada em matrizes quadradas. \n\n");
				}
				break;
			}
			case 0:{
				system("clear");
				exit = 0;
				break;
			}
			default:{
				system("clear");
				printf("\t\tOpcao invalida. Entre com uma das seguintes: \n");
				break;
			}
		}
	} while(exit);
}

void ex3(){
	system("clear");
	int m = 5, a[m][m], count = 0, sum = 0;
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			printf("Digite o elemento [%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	for (int k = 0; k<m; k++){
		for (int j = k - 1; j>=0; j--){
			sum += a[k][j];
			count += 1;
		}
	}
	system("clear");
	printMatrix(m, m, a);
	printf("Media: %.2f.\n", ((float)sum/count));
	

}

void ex4(){
	system("clear");
	int m = 3, n = 3, a[m][n];
	for (int k = 0; k<m; k++){
		for (int j = 0; j<n; j++){
			printf("Digite o elemento [%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	system("clear");
	printMatrix(m, n, a);
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			if ((j+k)%2 != 0) printf("[%d][%d] = %d.\n", k+1, j+1, a[k][j]);
		}
	}
}

void ex5(){
	system("clear");
	int m = 3, n = 3, a[m][n], b[m][n], trans = 1;
	for (int k = 0; k<m; k++){
		for (int j = 0; j<n; j++){
			printf("Digite o elemento a[%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	system("clear");
	printMatrix(m, n, a);
	for (int k = 0; k<m; k++){
		for (int j = 0; j<n; j++){
			printf("Digite o elemento b[%d][%d]: ", k+1, j+1);
			scanf("%d", &b[k][j]);
		}
	}
	system("clear");
	printMatrix(m, n, a);
	printMatrix(m, n, b);
	for (int k = 0; k<m; k++){
		for (int j = 0; j<n; j++){
			if (a[k][j] != b[j][k])	trans = 0;
		}
	}
	printf("\nA matriz [A] %s a transposta da matriz [B].", trans == 1 ? "e" : "nao e");
}

void ex6(){
	system("clear");
	int m, sim = 1;
	printf("Digite a ordem da matriz: ");
	scanf("%d", &m);
	int a[m][m];
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			printf("Digite o elemento [%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	system("clear");
	printMatrix(m, m, a);
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			if (a[k][j] != a[j][k])	sim = 0;
		}
	}
	printf("\nA matriz [A] %s simetrica.", sim == 1 ? "e" : "nao e");
}	

void ex7(){
	system("clear");
	int n = -1;
	while (n < 1 || n > 9){
		printf("Digite a ordem da matriz (entre 1 e 9): ");
		scanf("%d", &n);
		if (n < 1 || n > 9) printf("Valor invalido por favor entre com um numero entre 1 e 9.\n\n");
	}
	int a[n][n];
	for (int k = 0; k<n; k++){
		for (int j = k, l = 0; j<n; j++, l++){
			a[k][j] = n - l;
			a[j][k] = n - l;
		}
	}
	printMatrix(n, n, a);
}

void ex8(){
	system("clear");
	int m = 5, n = 5, a[m][n];
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			printf("Digite o elemento [%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	system("clear");
	printMatrix(m, n, a);
	int maior[2] = {a[0][0], 0};
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			if (a[k][j] > maior[0]){
				maior[0] = a[k][j];
				maior[1] = k;
			}
		}
	}
	int menor = a[maior[1]][0];
	for (int k = 0; k<m; k++){
		if (a[maior[1]][k] < menor) menor = a[maior[1]][k];
	}
	printf("O elemento minimax e %d.", menor);
}

void ex9(){
	system("clear");
	int m = 4, hor = 1, vert = 1, countH = 0, countV = 0;
	char a[m][m], s[m];
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			printf("Digite o caracter [%d][%d]: ", k+1, j+1);
			scanf(" %c", &a[k][j]);
		}
	}
	system("clear");
	printMatrixC(m, m, a);
	printf("Digite a string que deseja procurar: ");
	scanf("%s", s);
	for (int k = 0; k<m; k++){
		for (int j = 0; j<m; j++){
			if (a[k][j] != s[j]) hor = 0;
			if (a[j][k] != s[j]) vert = 0;
		}
		if(hor) countH++;
		if(vert) countV++;
	}
	system("clear");
	printf("A string %s verticalmente.\n", countH != 0 ? "ocorre" : "nao ocorre");
	printf("A string %s horizontalmente.\n", countV != 0 ? "ocorre" : "nao ocorre");
}

void ex10(){
	system("clear");
	int n, count = 0, inca = 1;
	printf("Digite a ordem da matriz: ");
	scanf("%d", &n);
	int a[n][n];
	for(int k = 0; k<n; k++){
		for(int j = 0; j<n; j++){
			printf("\nDigite o numero [%d][%d]: ", k+1, j+1);
			scanf("%d", &a[k][j]);
		}
	}
	system("clear");
	printMatrix(n, n, a);
	int k = 0, j = 0, aux1 = 0, aux2 = n;
	while (aux1 < aux2){
		for(k = aux1, j++; j < aux2; j++){
			if (a[k][j] != a[k][j-1]+1) inca = 0;
			count++;
		}
		for(k++, j = aux2-1; k < aux2; k++){
			if (a[k][j] != a[k-1][j]+1) inca = 0;
			count++;
		}
		for(k = aux2-1, j--; j >= aux1; j--){
			if (a[k][j] != a[k][j+1]+1) inca = 0;
			count++;
		}
		for(k = aux2-2, j = aux1; k > aux1; k--){
			if (a[k][j] != a[k+1][j]+1) inca = 0;
			count++;
		}
		aux1++; aux2--;
	}
	if(inca) printf("\t\tA matriz e inca.\n\n\n");
	else printf("\t\tA matriz nao e inca.\n\n\n");
}
	

	
int main (){
	int menu, exit = 0;
	setlocale(LC_ALL, "");
	while(!exit){
		printf("\t \n \n Escolha um exercicio:");
		printf("\t \t \n 1.Calcula maior elemento da matriz e divide os elementos por ele");
		printf("\t \t \n 2.Realiza trocas com a matriz 10x10");
		printf("\t \t \n 3.Retorna media aritimetica dos elementos abaixo da diagonal principal");
		printf("\t \t \n 4.Recebe matriz e mostra elementos cujo a soma da linha com coluna e impar");
		printf("\t \t \n 5.Verifica se uma matriz A e a transposta de uma matriz B");
		printf("\t \t \n 6.Verifica se uma matriz e simetrica");
		printf("\t \t \n 7.Gera matrizes simetricas");
		printf("\t \t \n 8.Encontrar elemento minimax de matriz");
		printf("\t \t \n 9.Recebe matriz de caracteres e procura por string");
		printf("\t \t \n 10.Verifica se a matriz e inca");
		printf("\t \t \n0.Sair");
		printf("\n \t Opcao >> ");
		scanf("%d", &menu);
		switch(menu){
			case 1:{
				ex1();
				break;
			}
			case 2:{
				ex2();
				break;
			}
			case 3:{
				ex3();
				break;
			}
			case 4:{
				ex4();
				break;
			}
			case 5:{
				ex5();
				break;
			}
			case 6:{
				ex6();
				break;
			}
			case 7:{
				ex7();
				break;
			}
			case 8:{
				ex8();
				break;
			}
			case 9:{
				ex9();
				break;
			}
			case 10:{
				ex10();
				break;
			}
			case 0:{
				exit = 1;
				break;
			}
			default:{
				printf("\t\t\t\nOpcao Invalida.\n\n\n");
				break;
			}
		}
	}
}










