#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int OS; //Eliminar problemas com clear entre linux e windows.

void printArray(int a[], int size) {
	if (size > 1) {
		printf("\n[");
		printf("%d", a[0]);
		for (int i = 1; i < size; i++)
			printf(", %d", a[i]);
		printf("]\n\n\n");
	} else if (size == 1){
		printf("\n[%d]\n\n\n", a[0]);
	}
	else printf("\n[]\n\n\n");
}

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
    } else if (m == 1){
        printf("\n[");
        for (int i = 0; i < n; i++){
                printf("%6d ", arr[0][i]);
        }
        printf("]\n\n");
    } else {
        printf("\n[]\n\n");
    }
}

void ex1(){
	int n;
	printf("Digite a quantidade de numeros que deseja dar entrada: "); scanf("%d", &n);
	int num[4] = {0};
	for (int k = 0; k<n; k++){
		printf("Digite o %d numero: ", k+1);
		scanf("%d", &num[0]);
		if (num[0] == 0) num[1]++;
		else if (num[0] %2 == 0) num[2]++;
		else num[3]++;
	}
	if (OS) system("clear");
	else system("cls");
	printf("%d numeros sao nulos.\n", num[1]);
	printf("%d numeros sao pares.\n", num[2]);
	printf("%d numeros sao impares.\n", num[3]);
}

void ex2(){
	int n;
	printf("Digite a quantidade de numeros que deseja dar entrada: "); scanf("%d", &n);
        int num[n];
	for (int k = 0; k<n; k++){
		printf("Digite o %d numero: ", k+1); scanf("%d", &num[k]);
	}
	if (OS) system("clear");
	else system("cls");
	printArray(num, n);
	for (int k = 0; k<n; k++){
		for (int j = k + 1; j<n; j++){
			if (num[k] > num[j]){
				int aux = num[k];
				num[k] = num[j];
				num[j] = aux;
			}
		}
	}
	printArray(num, n);
}

void ex3(){
    int n, count = 0, rept;
    printf("Digite a quantidade de numeros que deseja dar entrada: "); scanf("%d", &n);
	int num[n];
	for (int k = 0; k<n; k++){
		printf("Digite o %d numero: ", k+1); scanf("%d", &num[k]);		
	}
	if (OS) system("clear");
	else system("cls");
	printf("Digite qual valor deseja verificar o numero de repeticoes: "); scanf("%d", &rept);
	for (int k = 0; k<n; k++){
		if (num[k] == rept) {
			printf("Posicao: %d\n", k+1); 
			count++;
		}
	}
	printArray(num, n);
	count != 0 ? printf("O numero %d aparece %d vezes.\n\n", rept, count) : printf("Elemento nao encontrado.");
}

void ex4(){
	int n;
	float esp, area = 0;
	printf("Digite o numero de abscissas: "); scanf("%d", &n);
	float y[n];
	printf("Digite o espacamento entre as abscissas: "); scanf("%f", &esp);
	for (int k = 0; k<n; k++){
		printf("Digite Y%d: ", k+1); scanf("%f", &y[k]);
		if (k > 0 && k < n) area += y[k] * esp;
	}
	area += ((y[0] + y[n-1]) * esp) / 2;
	if (OS) system("clear");
	else system("cls");
	printf("A area e de %.2f.\n\n", area);
}

void ex5(){
	int menu, s1, s2, s3, check2 = 0, check3 = 0, exit = 1;
	printf("Digite quantos numeros o vetor 1 tera: "); scanf("%d", &s1);
	int *vec1 = (int*) malloc(s1 * sizeof(int)), *vec2, *vec3;
	for (int k = 0; k<s1; k++){
		printf("Digite o %d numero: ", k+1); scanf("%d", &vec1[k]);
	}
	do {
		if (OS) system("clear");
		else system("cls");
		printf("\n\nVetor 1:\n");
		printArray(vec1, s1);
		if (check2) {
			printf("Vetor 2:\n");
			printArray(vec2, s2);
		}
		if (check3){
			printf("Vetor 3:\n");
			printArray(vec3, s3);
		}
		printf("\tEscolha uma opcao: ");
		printf("\n\t\t1.Verificar se o vetor 1 esta em ordem crescente");
		printf("\n\t\t2.Copiar o vetor 1 em outro vetor");
		printf("\n\t\t3.Inverter o vetor 1 e colocar o resultado no segundo vetor");
		printf("\n\t\t4.Inverter o vetor 1 em si mesmo");
		printf("\n\t\t5.Unir o vetor 1 com vetor 2 gerando o vetor 3");
		printf("\n\t\t6.Eliminar do vetor 1 determinado elemento");
		printf("\n\t\t7.Fornecer os elementos que mais aparecem e que menos aparecem");
		printf("\n\t\t0.Sair\n\n\n\t\tOpcao: ");
		scanf("%d", &menu);
		switch (menu){
			case 1:{
				int check = 1;
				for (int k = 0; k<s1; k++){
					for (int j = k+1; j<s1; j++){
						if (vec1[k] > vec1[j]) check = 0;
					}
				}
				if (OS) system("clear");
				else system("cls");
				printf("\n\nO vetor %s ordenado.\n\n", check == 1 ? "esta" : "nao esta");
				break;			
			}	
			case 2:{
				s2 = s1;
				vec2 = (int*) malloc(s2 * sizeof(int));
				for (int k = 0; k<s1; k++){
					vec2[k] = vec1[k];
				}
				if (OS) system("clear");
				else system("cls");
				check2 = 1;
				break;
			}
			case 3:{
				if (!check2){
					printf("Voce ainda nao criou o vetor 2.\n\n");
					break;
				}
				s2 = s1;
				vec2 = (int*) malloc(s2 * sizeof(int));
				for (int k = 0, j = s1-1; k<s2; k++, j--){
					vec2[k] = vec1[j];
				}
				if (OS) system("clear");
				else system("cls");
       	        check2 = 1;
				break;
       	    }
			case 4:{
				for (int k = 0; k<s1/2; k++){
					int aux = vec1[k];
					vec1[k] = vec1[s1-1-k];
					vec1[s1-1-k] = aux;
				}
				if (OS) system("clear");
				else system("cls");
				break;
			}
			case 5:{
				if (!check2){
					printf("Voce ainda nao criou o vetor 2.\n\n");
					break;
				}
				s3 = s1 + s2;
				vec3 = (int*) malloc(s3 * sizeof(int));
				for (int k = 0, j = 0, i = 0; k < s3; k++){
					if (vec1[j] < vec2[i]){
						vec3[k] = vec1[j];
						j++;
					} else if (i < s2) {
						vec3[k] = vec2[i];
						i++;
					} else {
						vec3[k] = vec1[j];
					}
				}
				if (OS) system("clear");
				else system("cls");
				check3 = 1;
				break;
			}
			case 6:{
				if (OS) system("clear");
				else system("cls");
				int elim;
				printf("Digite qual elemento deseja eliminar do vetor 1: ");
				scanf("%d", &elim);
				for (int k = 0; k<s1;){
					if (vec1[k] == elim){
						for (int j = k; j < s1 - 1; j++){
							vec1[j] = vec1[j + 1];
						}
						s1--;
					} else {
						k++;
					}
				}
				vec1 = (int*) realloc(vec1, s1 * sizeof(int));
				if (OS) system("clear");
				else system("cls");
				break;
			}
			case 7:{
				int cont[s1];
				for (int k = 0; k < s1; k++){
					cont[k] = 0;
					for (int j = 0; j < s1; j++){
						if (vec1[k] == vec1[j]) cont[k]++;
					}
				}
				int maior = 0, menor = 0;
				for (int k = 0; k < s1; k++){
					if (cont[k] > cont[maior]) maior = k;
					if (cont[k] < cont[menor]) menor = k;
				}
				if (maior != menor){
					if (OS) system("clear");
					else system("cls");
					printf("\n\n\tO numero que mais repetiu-se foi %d, indice %d, %d vezes.\n", maior, vec1[maior], cont[maior]);
					printf("\n\n\tO numero que menos repetiu-se foi %d, indice %d, %d vezes.\n", menor, vec1[menor], cont[menor]);
				} else {
					if (OS) system("clear");
					else system("cls");
					printf("\n\n\tTodos elementos apareceram %d vezes.", cont[maior]);
				}
				break;
			}
			case 0:{
				if (OS) system("clear");
				else system("cls");
				exit = 0;
				break;
			}
			default:{
				if (OS) system("clear");
				else system("cls");
				printf("\t\t\n--Opcao invalida--\n\n");
				break;
			}
		}
	} while (exit);
}

void ex6(){
	int n, x;
	printf("Digite a ordem das matrizes A e B: ");
	scanf("%d", &n);
	int a[n][n], b[n][n], c[n][n];
	printf("Digite o valor de X: ");
	scanf("%d", &x);
	for (int k = 0; k<n; k++){
		for (int j = 0; j<n; j++){
			printf("Entre com o valor da posicao A[%d][%d]: ", k + 1, j + 1);
			scanf("%d", &a[k][j]);
		}
	}
	for (int k = 0; k<n; k++){
		for (int j = 0; j<n; j++){
			printf("Entre com o valor da posicao B[%d][%d]: ", k + 1, j + 1);
			scanf("%d", &b[k][j]);
		}
	}
	for (int k = 0; k<n; k++){
		for (int j = 0; j<n; j++){
			c[k][j] = a[j][k] + x * b[k][j];
		}
	}
	printMatrix(n, n, c);
}

void ex7(){
	int n, sim = 1, eq = 1;
    printf("Digite a ordem das matrizes A e B: ");
    scanf("%d", &n);
    int a[n][n], b[n][n];
    for (int k = 0; k<n; k++){
            for (int j = 0; j<n; j++){
                    printf("Entre com o valor da posicao A[%d][%d]: ", k + 1, j + 1);
                    scanf("%d", &a[k][j]);
            }
    }
    for (int k = 0; k<n; k++){
            for (int j = 0; j<n; j++){
                    printf("Entre com o valor da posicao B[%d][%d]: ", k + 1, j + 1);
                    scanf("%d", &b[k][j]);
            }
    }
	for (int k = 0; k<n; k++){
                for (int j = 0; j<n; j++){
                	if (a[k][j] != b[k][j]){
				eq = 0;
			}
			if (a[k][j] != b[j][k]){
				sim = 0;
			}
		}
    }
	if (OS) system("clear");
	else system("cls");
	printf("As matrizes A e B %s iguais e %s simetricas.\n\n", eq == 0 ? "nao sao" : "sao", sim == 0 ? "nao sao" : "sao");
}

void ex8(){
	int n, m;
    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &n);
	printf("Digite o numero de colunas da matriz A: ");
	scanf("%d", &m);
    int a[n][m], at[m][n];
	for (int k = 0; k<n; k++){
        for (int j = 0; j<m; j++){
            printf("Entre com o valor da posicao A[%d][%d]: ", k + 1, j + 1);
            scanf("%d", &a[k][j]);
        }
    }
	if (OS) system("clear");
	else system("cls");
    printf("Matriz A: \n\n");
	printMatrix(m, n, a);
    for (int k = 0; k<n; k++){
        for (int j = 0; j<m; j++){
			at[j][k] = a[k][j];
        }
    }
    printf("Transposta de A: \n\n");
	printMatrix(n, m, at);
}

void ex9(){
	int n;
    printf("Digite a ordem das matrizes A e B: ");
    scanf("%d", &n);
    int a[n][n], b[n][n], dif[n][n];
    for (int k = 0; k<n; k++){
        for (int j = 0; j<n; j++){
            printf("Entre com o valor da posicao A[%d][%d]: ", k + 1, j + 1);
            scanf("%d", &a[k][j]);
        }
    }
    for (int k = 0; k<n; k++){
        for (int j = 0; j<n; j++){
            printf("Entre com o valor da posicao B[%d][%d]: ", k + 1, j + 1);
            scanf("%d", &b[k][j]);
        }
    }
    for (int k = 0; k<n; k++){
        for (int j = 0; j<n; j++){
            dif[k][j] = a[k][j] - b[k][j];
        }
    }
	if (OS) system("clear");
	else system("cls");
    printf("Matriz diferenca: \n\n");
    printMatrix(n, n, dif);
}

void ex10(){
	int mat[2][2], det;
	for (int k = 0; k<2; k++){
        for (int j = 0; j<2; j++){
            printf("Entre com o valor da posicao MAT[%d][%d]: ", k + 1, j + 1);
            scanf("%d", &mat[k][j]);
        }
    }
	if (OS) system("clear");
	else system("cls");
	printMatrix(2, 2, mat);
	det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
	printf("\n\n\t\tA determinante da matriz e %d.\n\n", det);
}

void ex11(){
	int ord, check = 1;
	printf("Digite a ordem da matriz desejada: ");
	scanf("%d", &ord);
	int a[ord][ord];
	for (int k = 0; k < ord; k++){
		for (int j = 0; j < ord; j++){
			printf("Informe o elemento A[%d][%d]: ", k + 1, j + 1);
			scanf("%d", &a[k][j]);
		}
	}
	if (OS) system("clear");
	else system("cls");
	printMatrix(ord, ord, a);
	for (int k = 1; k < ord; k++){
		for (int j = k - 1; j > -1; j--){
			if (a[k][j] != 0) check = 0;
		}
    }
    printf("A matriz A %s triangular superior.\n\n", check == 1 ? "e" : "nao e");
}

int main(){
	setlocale(LC_ALL, "");
	int menu, Exit = 0;
	printf("Digite seu sistema operacional: \n\t\t0.Windows\n\t\t1.Linux\n\n\t\tOpcao: ");
	scanf("%d", &OS);
	if (OS) system("clear");
	else system("cls");
	do {
		printf("\n\tEscolha um exercicio: ");
		printf("\n\t\t1.Contar numeros pares, impares e nulos");
		printf("\n\t\t2.Imprimir numeros em ordem crescente");
		printf("\n\t\t3.Calcular numero de vezes e posicao que certo numero aparece");
		printf("\n\t\t4.Calcular area pela Regra dos Trapezios");
		printf("\n\t\t5.Operar determinado vetor");
		printf("\n\t\t6.Calcular A(transposta) + (X * B)");
		printf("\n\t\t7.Reconhecimento de matrizes simetricas ou iguais");
		printf("\n\t\t8.Calcular transposta de matrizes");
		printf("\n\t\t9.Gerar matriz diferenca de duas matrizes 5x5");
		printf("\n\t\t10.Calcular determinante matriz 2x2");
		printf("\n\t\t11.Verificar se matriz e triangular superior");
		printf("\n\t\t0.Sair");
		printf("\n\tOpcao: ");
		scanf("%d", &menu);
		switch (menu){
			case 1:{
				if (OS) system("clear");
				else system("cls");
				ex1();
				break;
			}
			case 2: {
				if (OS) system("clear");
				else system("cls");
				ex2();
				break;
			}
			case 3: {
				if (OS) system("clear");
				else system("cls");
				ex3();
				break;
			}
			case 4: {
				if (OS) system("clear");
				else system("cls");
				ex4();
				break;
			}
			case 5: {
				if (OS) system("clear");
				else system("cls");
				ex5();
				break;
			}
			case 6: {
				if (OS) system("clear");
				else system("cls");
				ex6();
				break;
			}
			case 7: {
				if (OS) system("clear");
				else system("cls");
				ex7();
				break;
			}
			case 8: {
				if (OS) system("clear");
				else system("cls");
				ex8();
				break;
			}
			case 9: {
				if (OS) system("clear");
				else system("cls");
				ex9();
				break;
			}
			case 10: {
				if (OS) system("clear");
				else system("cls");
				ex10();
				break;
			}
			case 11:{ if (OS) system("clear");
				else system("cls");
				ex11();
				break;
			}
			case 0: {
				if (OS) system("clear");
				else system("cls");
				printf("Saindo...");
				Exit = 1;
				break;
			}
			default: {
				if (OS) system("clear");
				else system("cls");
				printf("Opcao invalida. Por favor entre com uma das seguintes: \n");
			}
		}
	} while(!Exit);
}
