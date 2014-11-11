#include <stdlib.h>
#include <stdio.h>
#define tam 100

int main (){
    FILE *f1, *f2, *f3;
    f1=fopen("linhas1.txt","r");
    f2=fopen("linhas2.txt","w");
    f3=fopen("linhas3.txt","w");
    char txt1[tam],txt2[tam],txt3[tam];
    while(fgets(txt1,tam,f1)){
        int x;
        for(x=0;txt1[x]!='\0'&&txt1[x]!='#';x++)txt2[x]=txt1[x];
        if(txt1[x]=='#'){
            txt2[x]='\n';
            x++;
        }
        txt2[x]='\0';
        fputs(txt2,f2);
    }
    txt3[0]=0x42;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x52;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x55;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x4e;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x4f;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x0a;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x56;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x49;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x41;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x44;
    txt3[1]=0x0a;
    fputs(txt3,f3);
    txt3[0]=0x4f;
    txt3[1]=0x0a;
    fputs(txt3,f3);
}
