#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double fact(int n) {
	return n < 2 ? 1 : n * fact(n - 1);
}

void printDArray(double * arr, int size) {
	if (size > 0) {
		printf("\n[");
		for (int i = 0; i < size - 1; i++)
			printf("%.0f, ", arr[i]);
		printf("%.0f]\n", arr[size - 1]);
	} else printf("\n[]\n");
}

void printFArray(float * arr, int size, char * title) {
	if (size > 0) {
		printf("\n%s\n[", title);
		for (int i = 0; i < size - 1; i++)
			printf("%4.0f, ", arr[i]);
		printf("%4.0f]\n", arr[size - 1]);
	} else printf("\n[]\n");
}

void printIArray(int * arr, int size, char * title) {
	if (size > 0) {
		printf("\n%s\n[", title);
		for (int i = 0; i < size - 1; i++)
			printf("%d, ", arr[i]);
		printf("%d]\n", arr[size - 1]);
	} else printf("\n[]\n");
}

void ex1() {
	int v[10];
	double w[10];
	for (int i = 0; i < 10; i++) {
		printf("Informe um numero: ");
		scanf("%d", & v[i]);
		w[i] = fact(v[i]);
	}
	printDArray(w, 10);
}

void ex2() {
	float a[10], b[10], dif[10];
	for (int i = 0; i < 10; i++) {
		printf("Informe o elemento n%d do vetor A: ", i);
		scanf("%f", & a[i]);
		printf("Informe o elemento n%d do vetor B: ", i);
		scanf("%f", & b[i]);
		dif[i] = a[i] - b[i];
	}
	printFArray(a, 10, "Vetor A:");
	printFArray(b, 10, "Vetor B:");
	printFArray(dif, 10, "Vetor Diferenca:");
}

void swap(int * arr, int ia, int ib) {
	int aux = arr[ib];
	arr[ib] = arr[ia];
	arr[ia] = aux;
}

void insertionSort(int * arr, int size) {
	for (int i = 0; i < size; i++)
		for (int k = i; k > 0; k--)
			if (arr[k] < arr[k - 1])
				swap(arr, k, k - 1);
}

void ex3() {
	int a[10] = {1, 2, 3, 9, 5, 6, 7, 8, 0, 4};
	int b[20] = {0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
	int out[10];/*
    for (int i = 0; i < 10; i++){
        printf("Informe o elemento n%d do vetor A: ", i);
        scanf("%d", a[10]);
    }
    for (int i = 0; i < 20; i++){
        printf("Informe o elemento n%d do vetor B: ", i);
        scanf("%d", a[10]);
    }*/
	int j = 0;
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 20; k++) {
			if (a[i] == b[k]) {
				int test = 0;
				for (int l = 0; l < j; l++) {
					if (out[l] == a[i]) test = 1;
				}
				if (!test) {
					out[j++] = a[i];
					break;
				}
			}
		}
	}
	insertionSort(out, j);
	printIArray(out, j, "Conjunto Semelhanca: ");
}

void ex4() {
	int tm[12], menor = 0, maior = 0, f = 0;
	for (int i = 0; i < 12; i++) {
		printf("Informe a temperatura do mes n%d: ", i + 1);
		scanf("%d", & tm[i]);
		if (tm[i] > tm[maior]) maior = i;
		if (!f++ || tm[i] < tm[menor]) menor = i;
	}
	for (int i = 0; i < 12; i++) printf("Temperatura mes n%d=%d\n", i + 1, tm[i]);
	printf("Maior temperatura:\n\tmes=%d\n\ttemp=%d\n", maior + 1, tm[maior]);
	printf("Menor temperatura:\n\tmes=%d\n\ttemp=%d\n", menor + 1, tm[menor]);
}

void ex5() {
	int n = 10, num[n], menor, maior = 0, first = 0, even = 0, odd = 0, media = 0;
	for (int i = 0; i < n; i++) {
		printf("Informe o %do numero: ", i + 1);
		scanf("%d", & num[i]);
		if (num[i] > maior) maior = num[i];
		if (num[i] < menor || !first++) menor = num[i];
		if (num[i] % 2 == 0) even++;
		else odd++;
		media += num[i];
	}
	printf("Menor numero: %d\n", menor);
	printf("Maior numero: %d\n", maior);
	printf("Media dos numeros: %d\n", media / (odd + even));
	printf("Porcentagem de pares: %.2f%%\n", (float) even / (odd + even) * 100);
}

int findElem(int a[], int size, int elem) {
	for (int i = 0; i < size; i++)
		if (a[i] == elem) return i;
	return -1;
}

int findElemS(char * a[], int size, char * elem) {
	for (int i = 0; i < size; i++)
		if (strcmp(elem, a[i]) == 0) return i;
	return -1;
}

void ex6() {
	FILE * pFile;
	pFile = fopen ("voos.txt", "r+");
	if (pFile == NULL) {
		printf("O arquivo de voos nao foi encontrado.");
	} else {
		int n = 1;
		int * codigo = {0}, * vagas = {0}, * disp = {0};
		char * * origem = malloc(sizeof( * origem)), * * destino = malloc(sizeof( * destino));
		while (!feof(pFile)) {
			codigo = (int * ) realloc(codigo, sizeof(int) * n);
			vagas = (int * ) realloc(vagas, sizeof(int) * n);
			disp = (int * ) realloc(disp, sizeof(int) * n);
			origem = realloc(origem, sizeof( * origem) * n);
			origem[n - 1] = malloc(254 * sizeof(char * ));
			destino = realloc(destino, sizeof( * destino) * n);
			destino[n - 1] = malloc(254 * sizeof(char * ));
			fscanf(pFile, "%d %s %s %d %d\n", & codigo[n - 1], origem[n - 1], destino[n - 1], & vagas[n - 1], & disp[n - 1]);
			n++;
		}
		n--;
		int opcao, sair = 0;
		while (!sair) {
			system("cls");
			printf("\nMenu:\n\t1.Consultar\n\t2.Efetuar Reserva\n\t3.Sair\nOpcao: ");
			scanf("%d", & opcao);
			if (opcao == 1) {
				while (1) {
					system("cls");
					printf("\nConsultar:\n\t1.Por numero do voo\n\t2.Por Origem\n\t3.Por Destino\n\t4.Voltar\nOpcao: ");
					scanf("%d", & opcao);
					if (opcao == 1) {
						int voo;
						printf("\nInforme o numero do voo para consulta: ");
						getchar();
						scanf("%d", & voo);
						int t = 0;
						for (int i = 0; i < n; i++) {
							if (codigo[i] == voo) {
								t = 1;
								printf("\nVoo n%d:\n\tOrigem: %s\n\tDestino: %s\n\tVagas: %d/%d\n\n", codigo[i], origem[i], destino[i], disp[i], vagas[i]);
							} else if (i == 11 && !t) printf("Voo n%d nao cadastrado, por favor tente novamente.\n\n", voo);
						}
						system("pause");
						system("cls");
					} else if (opcao == 2) {
						char * origin = malloc(254 * sizeof(char * ));
						printf("\nInforme a origem do voo para consulta: ");
						getchar();
						fgets(origin, 254, stdin);
						if ((strlen(origin) > 0) && (origin[strlen (origin) - 1] == '\n'))
							origin[strlen (origin) - 1] = '\0';
						for (int i = 0; i < strlen(origin); i++)
							if (origin[i] == ' ') origin[i] = '_';
						int t = 0;
						for (int i = 0; i < n; i++) {
							if (strcmp(origin, origem[i]) == 0) {
								t = 1;
								printf("\nVoo n%d:\n\tOrigem: %s\n\tDestino: %s\n\tVagas: %d/%d\n\n", codigo[i], origem[i], destino[i], disp[i], vagas[i]);
							} else if (i == n - 1 && !t) printf("Voo com origem em %s nao cadastrado, por favor tente novamente.\n\n", origin);
						}
						system("pause");
						system("cls");
					} else if (opcao == 3) {
						char * destiny = malloc(254 * sizeof(char * ));
						printf("\nInforme o destino do voo para consulta: ");
						getchar();
						fgets(destiny, 254, stdin);
						if ((strlen(destiny) > 0) && (destiny[strlen (destiny) - 1] == '\n'))
							destiny[strlen (destiny) - 1] = '\0';
						for (int i = 0; i < strlen(destiny); i++)
							if (destiny[i] == ' ') destiny[i] = '_';
						int t = 0;
						for (int i = 0; i < n; i++) {
							if (strcmp(destiny, destino[i]) == 0) {
								t = 1;
								printf("\nVoo n%d:\n\tOrigem: %s\n\tDestino: %s\n\tVagas: %d/%d\n\n", codigo[i], origem[i], destino[i], disp[i], vagas[i]);
							} else if (i == n - 1 && !t) printf("Voo com destino para %s nao cadastrado, por favor tente novamente.\n\n", destiny);
						}
						system("pause");
						system("cls");
					} else if (opcao == 4) {
						break;
					} else {
						printf("\nVoce nao informou uma opcao valida, por favor tente novamente.\n");
					}
				}
			} else if (opcao == 2) {
				int voo;
				printf("Informe o numero do voo para reserva: ");
				getchar();
				scanf("%d", & voo);
				int i = findElem(codigo, n, voo);
				if (i != -1) {
					if (disp[i] > 0) {
						printf("RESERVA CONFIRMADA.\n");
						disp[i]--;
					} else {
						printf("VOO LOTADO.");
					}
				} else printf("VOO INEXISTENTE.");
				system("pause");
				system("cls");
			} else if (opcao == 3) {
				sair = 1;
			} else {
				printf("Voce nao informou uma opcao valida, por favor tente novamente.");
			}
		}
		freopen("voos.txt", "w", pFile);
		for (int i = 0; i < n; i++) {
			fprintf(pFile, "%d %s %s %d %d\n", codigo[i], origem[i], destino[i], vagas[i], disp[i]);
		}
	}
}

int main() {
	ex6();
	return 0;
}