#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct produto{
    char name[65];
    int code;
    char size;
    float price;
};

struct pessoa{
    char cabelo;
    char olhos;
    char sexo;
    int idade;
};

int leitura(struct pessoa *o,int *maior,int *f1835){
    puts("Informe a cor do cabelo(C-castanho, L-louros, P-pretos):");
    scanf(" %c",&(*o).cabelo);
    puts("Informe a cor dos olhos(C-castanho,A=azuis):");
    scanf(" %c",&(*o).olhos);
    puts("Informe o sexo(M ou F):");
    scanf(" %c",&(*o).sexo);
    do{
        puts("Informe a idade:");
        scanf("%d",&(*o).idade);
    }while((*o).idade<=0);
    if(!*maior||*maior<(*o).idade)*maior=(*o).idade;
    if(((*o).sexo=='f'||(*o).sexo=='F')&&((*o).idade>17&&(*o).idade<36))*f1835+=1;//notação *int++ não é valida com ponteiros
    return (((*o).olhos=='c')||((*o).olhos=='C'))&&(((*o).cabelo=='P')||((*o).cabelo=='p'));
}

void mostrarCampos(struct produto o){
    printf("\n%s",o.name);
    printf("\n%i",o.code);
    printf("\n%c",o.size);
    printf("\n%.2f\n",o.price);
}
void mostrarCamposex2(struct pessoa o){
    printf("\n%c",o.cabelo);
    printf("\n%c",o.olhos);
    printf("\n%c",o.sexo);
    printf("\n%i\n",o.idade);
}

void ex1(){
    struct produto p[4];
    fflush(stdin);
    gets(p[0].name);
    p[0].code=1337;
    p[0].size='P';
    p[0].price=28.5;
    mostrarCampos(p[0]);
    fflush(stdin);
    gets(p[1].name);
    p[1].code=154;
    p[1].size='G';
    p[1].price=23.5;
    mostrarCampos(p[1]);
    fflush(stdin);
    gets(p[2].name);
    p[2].code=597;
    p[2].size='M';
    p[2].price=27;
    mostrarCampos(p[2]);
    fflush(stdin);
    gets(p[3].name);
    p[3].code=754;
    p[3].size='G';
    p[3].price=2;
    mostrarCampos(p[3]);
}

void ex2(){
    int n,count=0,maior,f1835=0;
    do{
        puts("Informe o numero de pessoas:");
        scanf("%d",&n);
    }while(n<=0);
    struct pessoa p[n];
    for(int x=0;x<n;x++){
        if(leitura(&p[x],&maior,&f1835))count++;
    }
    for(int x=0;x<n;x++){
        mostrarCamposex2(p[x]);
    }
    printf("\nmaior idade: %d\n",maior);
    printf("%d mulheres com idade entre 18 e 35\n",f1835);
    printf("%.2f %% das pessoas tem cabelo preto e olhos castanhos",!count?0:count/(float)n*100);
}

int main(){
    int pick;
    do{
        puts("Informe o numero do exercicio 1 ou 2:");
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
    return 0;
}
