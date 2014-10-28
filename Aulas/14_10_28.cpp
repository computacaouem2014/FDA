#include <stdlib.h>
#include <stdio.h>

int mdc(int x, int y){
    return x == y ? x : x > y ? mdc(x - y, y) : mdc(y, x);
}

void ex1(){
    int nro[2];

    do{
        puts("Informe o primeiro numero (maior do que 0):");
        scanf("%d",&nro[0]);
        system("clear");
    }while(nro[0] < 1);

    do{
        puts("Informe o segundo numero (maior do que 0):");
        scanf("%d",&nro[1]);
        system("clear");
    }while(nro[1] < 1);

    printf("MDC(%d,%d)=%d", nro[0], nro[1], mdc(nro[0], nro[1]));
}

int checkint(char str[]){
    int check = 1;
    for(int x = 0; check && str[x] != '\0'; x++){
        check = (str[x] > 47 && str[x] < 58) || (str[x] == 45 && !x);
    }
    return check;
}

void ex2(){
    char nro[255];

    do{
        puts("Informe um numero inteiro");
        scanf("%s",nro);
        system("clear");
    }while(!checkint(nro));

    system("clear");

    for(int x = 0; nro[x] != '\0'; x++){
        printf("%c\n", nro[x]);
    }
}

float potencia(int x, int y){
    return y > 0 ? x * potencia(x, y-1) : !y ? 1 : (float)(1/potencia(x, -y));
}

void ex3(){

    int nro[2];

        puts("Informe a base:");
        scanf("%d",&nro[0]);
        system("clear");

        puts("Informe o expoente:");
        scanf("%d",&nro[1]);
        system("clear");

        printf("%d^%d = %f", nro[0], nro[1] ,potencia(nro[0], nro[1]));

}

int main(){
    int pick;
    do{
        puts("Informe o numero do exercicio ( entre 1 e 3 ):");
        scanf("%d",&pick);
        system("clear");
    }while(pick < 1 || pick > 3);

    system("clear");

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
}
