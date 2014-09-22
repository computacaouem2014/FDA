#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ex1(int idade[], float peso[], int size) {
	int count[4] = {0};
	float soma[4] = {0};
	for (int i = 0; i < size; i++) {
		if (idade[i] > 30) {
			count[3]++;
			soma[3] += peso[i];
		} else if (idade[i] > 20) {
			count[2]++;
			soma[2] += peso[i];
		} else if (idade[i] > 10) {
			count[1]++;
			soma[1] += peso[i];
		} else if (idade[i] > 0) {
			count[0]++;
			soma[0] += peso[i];
		} else {
			printf("Idade n%d (%d) invalida.", i + 1, idade[i]);
		}
	}
	printf("Media de peso da faixa etaria de 1 a 10:\t%6.2f\n", count[0] == 0 ? 0 : soma[0] / count[0]);
	printf("Media de peso da faixa etaria de 11 a 20:\t%6.2f\n", count[1] == 0 ? 0 : soma[1] / count[1]);
	printf("Media de peso da faixa etaria de 21 a 30:\t%6.2f\n", count[2] == 0 ? 0 : soma[2] / count[2]);
	printf("Media de peso da faixa etaria maiores de 30:\t%6.2f\n", count[3] == 0 ? 0 : soma[3] / count[3]);
}

void ex2() {
	int codigo, haula, sexo;
	float desconto[2] = {0.9, 0.95}, salariob, salariol, m = 0, f = 0, mbruto = 0, mliq = 0;
	while (1) {
		printf("Informe o codigo do professor(a): ");
		scanf("%d", & codigo);
		if (codigo == 99999) break;
		printf("Informe o sexo (0 = M, 1 = F): ");
		scanf("%d", & sexo);
		printf("Informe a quantidade de horas-aula mensal: ");
		scanf("%d", & haula);
		salariob = haula * 38.5;
		salariol = salariob * desconto[sexo];
		printf("Codigo: %d\n\tSalario Bruto: %.2f\n\tSalario Liquido: %.2f\n", codigo, salariob, salariol);
		if (!sexo) {
			mliq += salariol;
			m++;
		} else {
			mbruto += salariob;
			f++;
		}
	}
	printf("Media de salario bruto de professores do sexo feminino: %.2f\n", mbruto / f);
	printf("Media de salario liquido de professores do sexo masculino: %.2f\n", mliq / m);
}

void ex3() {
	int idade, sexo, experiencia;
	int m = 0, f = 0;
	int me = 0, ime = 0;
	int fe = 0, menor = 0;
	int i45 = 0;
	while (1) {
		printf("\nInforme a idade do candidato (0 para sair): ");
		scanf("%d", & idade);
		if (!idade) break;
		printf("Informe o sexo (0 = M, 1 = F): ");
		scanf("%d", & sexo);
		printf("Informe a experiencia (0 = N, 1 = S): ");
		scanf("%d", & experiencia);
		if (!sexo) {
			m++;
			if (experiencia) {
				me++;
				ime += idade;
			}
			if (idade > 45) i45++;
		} else {
			if (experiencia) {
				if (idade < 35) fe++;
				if (idade < menor || !f) menor = idade;
			}
			f++;
		}
	}
	printf("\nCandidatos do sexo masculino: %d\n", m);
	printf("Candidatos do sexo feminino: %d\n", f);
	printf("Idade media dos homens com experiencia no servico: %.2f\n", (float) ime / me);
	printf("Percentagem de homens com mais de 45 anos: %.2f%%\n", (float) i45 / m * 100);
	printf("Numero de mulheres com menos de 35 anos e com experiencia no servico: %d\n", fe);
	printf("Menor idade entre as mulheres com experiencia no servico: %d\n", menor);
}

void ex4(int idade[], int opiniao[], int size) {
	int oidade = 0, otimo = 0, regular = 0, bom = 0;
	for (int i = 0; i < size; i++) {
		if (opiniao[i] == 3) {
			otimo++;
			oidade += idade[i];
		} else if (opiniao[i] == 2) bom++;
		else if (opiniao[i] == 1) regular++;
		else printf("Opiniao n%d (%d) invalida.\n", i + 1, idade[i]);
	}
	printf("Idade media das pessoas que responderam otimo:\t%.2f\n", (float) oidade / (otimo || 1));
	printf("Percentagem de pessoas que respondeu bom:\t%.2f%%\n", (float) bom / size * 100);
	printf("Quantidade de pessoas que respondeu regular:\t%d\n", regular);
}

void ex5() {
	int num, maior = 0, menor = 0, first = -1;
	while (1) {
		printf("Informe um numero [0 para encerrar]: ");
		scanf("%d", & num);
		if (!num) break;
		else if (num > 0) {
			if (num > maior) maior = num;
			if (menor > num || (!++first)) menor = num;
		} else printf("Voce digitou um numero negativo.\n");
	}
	printf("Maior numero positivo:\t%d\n", maior);
	printf("Menor numero positivo:\t%d\n", menor);
}

void ex6() {
	int num, c1 = 0, c2 = 0, c3 = 0, c4 = 0, b = 0, n = 0;
	printf("Eleicao:\n");
	printf("\t0 para encerrar a votacao;\n");
	printf("\t1 para o candidato 1;\n");
	printf("\t2 para o candidato 2;\n");
	printf("\t3 para o candidato 3;\n");
	printf("\t4 para o candidato 4;\n");
	printf("\t99 para votar em branco;\n");
	printf("\tQualquer outro valor para votar nulo.\n");
	while (1) {
		printf("Informe o voto:\n");
		scanf("%d", & num);
		if (!num) break;
		if (num == 1) c1++;
		else if (num == 2) c2++;
		else if (num == 3) c3++;
		else if (num == 4) c4++;
		else if (num == 99) b++;
		else n++;
	}
	int validos = c1 + c2 + c3 + c4;
	float p1 = (float) c1 / validos * 100;
	float p2 = (float) c2 / validos * 100;
	float p3 = (float) c3 / validos * 100;
	float p4 = (float) c4 / validos * 100;
	printf("\nVotos validos: %d\n", validos);
	printf("Primeiro Candidato:\n\tVotos:%d\n\tPercentual:%.2f%%\n", c1, p1);
	printf("Segundo Candidato:\n\tVotos:%d\n\tPercentual:%.2f%%\n", c2, p2);
	printf("Terceiro Candidato:\n\tVotos:%d\n\tPercentual:%.2f%%\n", c3, p3);
	printf("Quarto Candidato:\n\tVotos:%d\n\tPercentual:%.2f%%\n", c4, p4);
	printf("Votos brancos: %d\n", b);
	printf("Votos nulos: %d\n", n);
	if (p1 > 50) printf("\nVencedor: Primeiro Candidato.\n");
	else if (p2 > 50) printf("\nVencedor: Segundo Candidato.\n");
	else if (p3 > 50) printf("\nVencedor: Terceiro Candidato.\n");
	else if (p4 > 50) printf("\nVencedor: Quarto Candidato.\n");
	else printf("\nHavera segundo turno.\n");
}

void ex7() {
	char cpf[12];
	printf("Informe o CPF (somente numeros): ");
	scanf("%s", cpf);
	int valideCPF(char * cpf) {
		int digitos[11], soma = 0;
		if (strlen(cpf) != 11) return 0;
		for (int i = 0; i < 11; i++) {
			if (cpf[i] > 47 && cpf[i] < 58) digitos[i] = cpf[i] - 48;
			else return 0;
		}
		soma = 0;
		for (int i = 0; i < 9; i++)
			soma += digitos[i] * (10 - i);
		if (soma % 11 > 1) {
			if (11 - (soma % 11) != digitos[9]) return 0;
		} else if (digitos[9] != 0) return 0;
		soma = 0;
		for (int i = 0; i < 10; i++)
			soma += digitos[i] * (11 - i);
		if (soma % 11 > 1) {
			if (11 - (soma % 11) != digitos[10]) return 0;
		} else if (digitos[10] != 0) return 0;
		return 1;
	}
	if (valideCPF(cpf)) printf("O CPF informado e valido.\n");
	else printf("O CPF informado e invalido.\n");
}

void ex8() {
	int ano1, mes1, dia1, ano2, mes2, dia2;
	printf("Informe a primeira data: \n");
	do {
		printf("\tDia: ");
		scanf("%d", & dia1);
	} while (!(dia1 > 0 && dia1 < 32));
	do {
		printf("\tMes: ");
		scanf("%d", & mes1);
	} while (!(mes1 > 0 && mes1 < 13));
	do {
		printf("\tAno: ");
		scanf("%d", & ano1);
	} while (!(ano1 > 0));

	printf("Informe a segunda data: \n");
	do {
		printf("\tDia: ");
		scanf("%d", & dia2);
	} while (!(dia2 > 0 && dia2 < 32));
	do {
		printf("\tMes: ");
		scanf("%d", & mes2);
	} while (!(mes2 > 0 && mes2 < 13));
	do {
		printf("\tAno: ");
		scanf("%d", & ano2);
	} while (!(ano2 > 0));

	if (ano1 > ano2) printf("A primeira data e maior.\n");
	else if (ano2 > ano1) printf("A segunda data e maior.\n");
	else {
		if (mes1 > mes2) printf("A primeira data e maior.\n");
		else if (mes2 > mes1) printf("A segunda data e maior.\n");
		else {
			if (dia1 > dia2) printf("A primeira data e maior.\n");
			else if (dia2 > dia1) printf("A segunda data e maior.\n");
			else printf("As datas sao iguais.\n");
		}
	}
}

int main () {
	int a[10] = {11, 12, 13, 15, 21, 49, 11, 29, 39, 23};
	float b[10] = {55.5, 75.5, 60.5, 90.5, 120.5, 40.5, 50.5, 65.5, 70.5, 80.5};
	ex8();
	getchar();
	getchar();
	return 0;
}