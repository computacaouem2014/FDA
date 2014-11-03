#include <stdlib.h>
#include <stdio.h>

int increment(int i, int j, int k){
    if((i>=j&&k<=0)||(i<=j&&k>=0)){
        if(!k)return 0;
        increment(i+k, j, k);
    }
}

float somaSerie(float i, float j, float k){
    if((i>=j&&k<=0)||(i<=j&&k>=0)){
        if(!k)return i;
        return i+somaSerie(i+k, j, k);
    }else return 0;
}

float serie(int nro){
    return nro != 1 ? ( 1. + nro * nro) / nro + serie(nro - 1) : 2;
}

int fat(int nro){
    return nro > 1 ? nro * fat(nro - 1) : 1;
}

float seriex5(int nro){
    return nro != 1 ? 1. / fat(nro) + seriex5(nro - 1) : 2;
}

void ex1(){
    int nro;
    puts("insira um numero inteiro:");
    scanf("%d",&nro);
    if(nro>=0){
        printf("%d",nro*nro);
        ex1();
    }
}

void ex2(){
    int i, j, k;
    puts("insira um numero inteiro i:");
    scanf("%d",&i);
    puts("insira um numero inteiro j:");
    scanf("%d",&j);
    puts("insira um numero inteiro para ser incrementado:");
    scanf("%d",&k);
    puts("");
    increment(i, j, k);
}

void ex3(){
    float i, j, k;
    puts("insira um numero inteiro i:");
    scanf("%f",&i);
    puts("insira um numero inteiro j:");
    scanf("%f",&j);
    puts("insira um numero inteiro para ser incrementado:");
    scanf("%f",&k);
    printf("\nsoma da serie: %.2f\n",somaSerie(i, j, k));
}

void ex4(){
    int nro;
    do{
        puts("Informe o numero de elementos da serie para efetuar a soma:");
            scanf("%d",&nro);
    }while(nro<1);
    printf("%.2f",serie(nro));
}

void ex5(){
    int nro;
    do{
        puts("Informe o numero de elementos da serie para efetuar a soma:");
            scanf("%d",&nro);
    }while(nro<1);
    printf("%.2f",seriex5(nro));
}


int main(){
    int pick;
    do{
        puts("Informe o numero do exercicio entre 1 e 5:");
        scanf("%d",&pick);
    }while(pick<1||pick>5);
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
        case 4:
            ex4();
            break;
        case 5:
            ex5();
            break;
    }
}
