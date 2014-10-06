#include <stdlib.h>
#include <stdio.h>
#define lin 6
#define col 4
#define lin3 10
#define col3 20

void ex1(){
    int m[lin][col]={0},maior=0;

    for(int x=0;x<lin;x++){
        for(int y=0;y<col;y++){
            printf("Informe o valor da linha %d, coluna %d: \n",x+1,y+1);
            scanf("%d",&m[x][y]);
            if(!maior||maior<m[x][y]){
                maior=m[x][y];
            }
        }
        puts("");
    }
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
                printf("%4d",m[x][y]*maior);
        }
        puts("");
    }
}

void ex2(){
    int m[lin][col]={0},m2[lin][col]={0},maior30=0;

    for(int x=0;x<lin;x++){
        for(int y=0;y<col;y++){
            printf("Informe o valor da linha %d, coluna %d: \n",x+1,y+1);
            scanf("%d",&m[x][y]);
            if(m[x][y]!=30){
                m2[x][y]=m[x][y];
                if(m[x][y]>30){
                    maior30++;
                }
            }
        }
        puts("");
    }
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
                printf("%4d",m2[x][y]);
        }
        puts("");
    }
    printf("O numero de elementos maiores do que 30 e: %d\n",maior30);

}

void ex3(){
    int m[lin3][col3]={0},maior=0,soma[lin3]={0};

    for(int x=0;x<lin3;x++){
        for(int y=0;y<col3;y++){
            printf("Informe o valor da linha %d, coluna %d: \n",x+1,y+1);
            scanf("%d",&m[x][y]);
            soma[x]+=m[x][y];
        }
        puts("");
    }
    for(int x=0;x<lin3;x++){
        for(int y=0;y<col3;y++){
            printf("%5d",m[x][y]);
        }
        puts("");
    }
    puts("");
    puts("");
    for(int x=0;x<lin3;x++){
        for(int y=0;y<col3;y++){
                printf("%5d",m[x][y]*soma[x]);
        }
        puts("");
    }
    for(int x=0;x<lin;x++){
        printf("soma da linha %d\n",x+1,soma[x]);
    }
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
