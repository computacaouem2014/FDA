#include <stdlib.h>
#include <stdio.h>
#define lin 10
#define col 3

void ex1(){
    int n;
    do{
        puts("Informe um numero de 1 a 9:");
        scanf("%d",&n);
    }while(n<1||n>9);
    int m[n][n];

    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            m[x][y]=y>x?0:(x+1)*(y+1);
            printf("%4d",m[x][y]);
        }
        puts("");
    }
}

void ex2(){
    float notas[lin][col];
    int menorn[lin],menores[col];
    for(int y=0;y<col;y++)menores[y]=0;
    for(int x=0;x<lin;x++){
        menorn[x]=0;
        for(int y=0;y<col;y++){
            do{
                printf("Informe a %d nota do %d aluno(entre 0 e 10):\n",y+1,x+1);
                scanf("%f",&notas[x][y]);
            }while(notas[x][y]<0||notas[x][y]>10);
            if(notas[x][y]<notas[x][menorn[x]]){
                menorn[x]=y;
            }
        }
        menores[menorn[x]]++;
        puts("");
    }
    for(int x=0;x<lin;x++){
        printf("Menor nota do aluno %d foi %.2f na prova %d\n",x+1,notas[x][menorn[x]],menorn[x]+1);
    }
    puts("\n");
    for(int y=0;y<col;y++){
        printf("%d alunos tiveram a menor nota na prova %d\n",menores[y],y+1);
    }


}

int main(){
    int pick;
    do{
        puts("Informe o numero do exercicio:");
        scanf("%d",&pick);
    }while(pick<1||pick>2);

    switch(pick){
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;

    }
}
