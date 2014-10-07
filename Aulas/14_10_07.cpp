#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lin 5
#define col 5
#define lin2 3
#define col2 4

void ex1(){
    int m[lin][col]={0},novo;

    for(int x=0;x<lin;x++){
        for(int y=0;y<col;y++){
            printf("Informe o valor da linha %d, coluna %d: \n",x+1,y+1);
            scanf("%d",&m[x][y]);
        }
        puts("");
    }

    puts("Informe o novo vaalor dos elementos acima da diagonal principal:");
    scanf("%d",&novo);



    for(int x=0;x<lin;x++){
        for(int y=0;y<col;y++){
            printf("%4d",m[x][y]);
        }
        puts("");
    }
    puts("");
    puts("");
    for(int x=0;x<lin;x++){
        for(int y=0;y<col;y++){
                printf("%4d",x<y?novo:m[x][y]);
        }
        puts("");
    }
}

void ex2(){
    int m[lin2][col2]={0};

    for(int x=0;x<lin2;x++){
        for(int y=0;y<col2;y++){
            printf("Informe o valor da linha %d, coluna %d: \n",x+1,y+1);
            scanf("%d",&m[x][y]);
        }
        puts("");
    }

    for(int x=0;x<lin2;x++){
        for(int y=0;y<col2;y++){
            printf("%4d",m[x][y]);
        }
        puts("");
    }
    puts("");
    puts("");
    for(int x=0;x<lin2;x++){
        for(int y=0;y<col2;y++){
                printf("%4d",m[x][y]%2?3*m[x][y]:2*m[x][y]);
        }
        puts("");
    }
}
void ex3(){
    int m[col2][col2]={0},soma=0;

    for(int x=0;x<col2;x++){
        for(int y=0;y<col2;y++){
            printf("Informe o valor da linha %d, coluna %d: \n",x+1,y+1);
            scanf("%d",&m[x][y]);
        }
        puts("");
    }

    for(int x=0;x<col2;x++){
        for(int y=0;y<col2;y++){
            printf("%4d",m[x][y]);
            if(x+y>=col2){
                soma+=pow(m[x][y],2);
            }
        }
        puts("");
    }
    printf("raiz da soma dos numeros abaixo da diagonal secundaria: %f\n",sqrt(soma));
    puts("");
    puts("");

    }

int main(void){
	int pick;
	do{
		puts("escolha exercicio 1 a 3");
		scanf("%d",&pick);
	}while(pick<1||pick>3);
	switch(pick){
		case 1:
			ex1();
			break;
		case 2:
			ex2();
			break;
        case 3:
			ex3();
			break;
	}
	return 0;
}
