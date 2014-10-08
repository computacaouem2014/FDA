#include <stdlib.h>
#include <stdio.h>
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

void printArray(int size, int a[size]){
	if (size > 1){
        	printf("\n[%d,", a[0]);
	        for (int i = 1; i < size-1; i++) printf(" %d,", a[i]);
        	printf(" %d]\n", a[size-1]);
	} else if (size == 1){
		printf("\n[%d]\n", a[0]);
	} else printf("\n[]\n");
}

void ex1(){
    int n;
    printf("Informe a quantidade de numeros: ");
    scanf("%d", &n);
    int vec[3] = {0}, num;
    for (int i = 0; i < n; i++){
        printf("Informe o %io numero: ", i+1);
        scanf("%d", &num);
        if (num == 0) vec[0]++;
        else if (num % 2 == 0) vec[1]++;
        else vec[2]++;
    }
    printf("Quant. de nulos: %d\n", vec[0]);
    printf("Quant. de pares: %d\n", vec[1]);
    printf("Quant. de impares: %d\n", vec[2]);
    printArray(3, vec);
}

void ex2(){
    int n;
    printf("Informe a quantidade de numeros: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        printf("Informe o %io numero: ", i+1);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++){
        int menor = i;
        for (int j = i+1; j < n; j++){
            if(a[j] < a[menor]) menor = j;
        }
        int aux = a[i];
        a[i] = a[menor];
        a[menor] = aux;
    }
    printArray(n, a);
}

void ex3(){
    int n;
    printf("Informe a quantidade de numeros: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        printf("Informe o %io numero: ", i+1);
        scanf("%d", &a[i]);
    }
    int num, count = 0;
    printf("Informe um numero para busca: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++){
        if (a[i] == num){
            printf("Index: %d\n", i);
            count++;
        }
    }
    printf("Total: %d vezes.\n", count);
}

void ex4(){
    int y[50], h, n;
    do {
        printf("Informe o a quant. de Y [max=50]: ");
        scanf("%d", &n);
    } while (n > 50 || n < 0);
    for (int i = 0; i < n; i++){
        printf("Informe o %do Y: ", i+1);
        scanf("%d", &y[i]);
    }
    printf("Informe o valor de H: ");
    scanf("%d", &h);
    float area = 0;
    area += 0.5 * h * y[0];
    for (int i = 1; i < n-1; i++){
        area += h * y[i];
    }
    area += 0.5 * h * y[n-1];
    printf("Area: %.2f u.a.\n", area);
}

void ex5(){
	int n;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &n);
	int m = n, o = m + n;
	int *vec = (int*) malloc(n * sizeof(int)), *vec2, *vec3;
	for (int i = 0; i < n; i++){
		printf("Informe o %do numero: ", i+1);
		scanf("%d", &vec[i]);
	}
	int opcao, sair = 0, vetor2 = 0, vetor3 = 0;
	while (!sair){
		printf("\nVetor 1:");
		printArray(n, vec);
		if (vetor2){
			printf("Vetor 2:");
			printArray(m, vec2);
		}
		if (vetor3){
			printf("Vetor 3:");
			printArray(o, vec3);
		}
		printf("\nOpcoes:\n");
		printf("\t1.Verificar se o vetor 1 esta ordenado crescentemente;\n");
		printf("\t2.Copiar o vetor 1 para o vetor 2;\n");
		printf("\t3.Inverter o vetor 1 e colocar o resultado no vetor 2.\n");
		printf("\t4.Inverter o vetor 1 e colocar o resultado no proprio vetor 1.\n");
		printf("\t5.Unir o vetor 1 e o vetor 2 num vetor 3 (todos ordenados).\n");
		printf("\t6.Eliminar determinado elemento do vetor 1.\n");
		printf("\t7.Verificar quais elementos aparecem mais e menos vezes.\n");
		printf("\t8.Ordenar o vetor 1\n");
		printf("\t99.Reiniciar\n");
		printf("\t0.Sair\n");
		printf("Informe a opcao desejada: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				sair = 1;
				break;
			case 1:
				{
				int ord = 1;
				for (int i = 0; i < n-1; i++){
					if (vec[i] > vec[i+1]) ord = 0;
				}
				system("clear");
				printf("O vetor 1 %s ordenado.\n", ord ? "esta" : "nao esta");
				break;
				}
			case 2:
				m = n;
				vec2 = (int*) malloc(m * sizeof(int));
				for (int i = 0; i < n; i++){
					vec2[i] = vec[i];
				}
				vetor2 = 1;
				system("clear");
				break;
			case 3:
				m = n;
				vec2 = (int*) malloc(m * sizeof(int));
				for (int i = 0, j = n-1; i < n; i++, j--){
					vec2[j] = vec[i];
				}
				vetor2 = 1;
				system("clear");
				break;
			case 4:
				for (int i = 0; i < n/2; i++){
					int aux = vec[i];
					vec[i] = vec[n-i-1];
					vec[n-i-1] = aux;
				}
				system("clear");
				break;
			case 5:
				o = m + n;
				vec3 = (int*) malloc(o * sizeof(int));
				for (int k = 0, i = 0, j = 0; k < o; k++){
					if (vec[i] < vec2[j]){
						vec3[k] = vec[i];
						i++;
					} else if (j < m) {
						vec3[k] = vec2[j];
						j++;
					} else {
						vec3[k] = vec[i];
						i++;
					}
				}
				vetor3 = 1;
				system("clear");
				break;
			case 6:
				{
				int elim;
				printf("Informe o elemento a ser eliminado: ");
				scanf("%d", &elim);
				for(int i = 0; i < n;){
					if (vec[i] == elim){
						for (int m = i; m < n - 1; m++){
							vec[m] = vec[m + 1];
						}
						n--;
					} else {
						i++;
					}
				}
				vec = (int*) realloc(vec, n * sizeof(int));
				system("clear");
				break;
				}
			case 7:
				{
				int count[n];
				for (int i = 0; i < n; i++){
					count[i] = 0;
					for (int j = 0; j < n; j++){
						if (vec[j] == vec[i]) count[i]++;
					}
				}
				int maior = 0, menor = 0;
				for (int i = 0; i < n; i++){
					if (count[i] > count[maior]) maior = i;
					if (count[i] < count[menor]) menor = i;
				}
				system("clear");
				if (maior != menor){
					printf("Elemento com maior ocorrencia (%d): vec[%d]=%d\n", count[maior], maior, vec[maior]);
					printf("Elemento com menor ocorrencia (%d): vec[%d]=%d\n", count[menor], menor, vec[menor]);
				} else {
					printf("Todos os elemento tem a mesma ocorrencia (%d).", count[maior]);
				}
				}
				break;
			case 8:
				printf("Forma de ordenacao:\n\t1.Crescente\n\t2.Decrescente\nOpcao: ");
				scanf("%d", &opcao);
				system("clear");
				if (opcao == 1){
					for (int i = 1; i < n; i++){
						for (int k = i; k > 0; k--){
							if (vec[k] < vec[k-1]){
								int aux = vec[k];
								vec[k] = vec[k-1];
								vec[k-1] = aux;
							}
						}
					}
				} else if (opcao == 2){
					for (int i = 1; i < n; i++){
						for (int k = i; k > 0; k--){
							if (vec[k] > vec[k-1]){
								int aux = vec[k];
								vec[k] = vec[k-1];
								vec[k-1] = aux;
							}
						}
					}
				} else printf("Opcao invalida. Retornando ao menu principal.");
				break;
			case 99:
				printf("Informe o tamanho do vetor: ");
				scanf("%d", &n);
				vec = (int*) malloc(n * sizeof(int));
				for (int i = 0; i < n; i++){
					printf("Informe o %do numero: ", i+1);
					scanf("%d", &vec[i]);
				}
				break;
			default:
				system("clear");
				printf("Voce nao informou uma opcao valida. Tente novamente.\n");
				break;
		}
	}
}

void ex6(){
    int m, x;
    printf("Informe a ordem M da matriz: ");
    scanf("%d", &m);
    printf("Informe o X: ");
    scanf("%d", &x);
    int a[m][m], b[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    int d[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            d[i][j] = a[j][i] + x * b[i][j];
        }
    }
    printMatrix(m, m, d);
}

void ex7(){
    int m, sim = 1;
    printf("Informe o M: ");
    scanf("%d", &m);
    int a[m][m], b[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printMatrix(m, m, a);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    printMatrix(m, m, b);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] != b[j][i]) sim = 0;
        }
    }
    printf("As matrizes A e B %s simetricas e iguais.\n", sim ? "sao" : "nao sao");
}

void ex8(){
    int m, n;
    printf("Informe o M: ");
    scanf("%d", &m);
    printf("Informe o N: ");
    scanf("%d", &n);
    int a[m][n], at[n][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            at[j][i] = a[i][j];
        }
    }
    printMatrix(m, n, a);
    printMatrix(n, m, at);
}

void ex9(){
    int m = 5;
    int a[m][m], b[m][m], dif[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printMatrix(m, m, a);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    printMatrix(m, m, b);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            dif[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Matriz diferença (A-B):\n");
    printMatrix(m, m, dif);
}

void ex10(){
    int m = 2;
    int a[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printMatrix(m, m, a);
    int det = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
    printf("Determinate: %d\n", det);
}

void ex11(){
    int m = 5, mts = 1;
    int a[m][m];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            printf("Informe o elemento A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printMatrix(m, m, a);
    for (int i = 1; i < m; i++){
        for (int j = i - 1; j > -1; j--){
            if (a[i][j] != 0) mts = 0;
	}
	if (mts == 0) break;
    }
    printf("A matriz A %s triangular superior.\n", mts ? "e" : "nao e");
}

int main(){
	setlocale(LC_ALL, "");
	ex1();
	ex2();
	ex3();
	ex4();
	ex5();
	ex6();
	ex7();
	ex8();
	ex9();
	ex10();
	ex11();
	return 0;
}
