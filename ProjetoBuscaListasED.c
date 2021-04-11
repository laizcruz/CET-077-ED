#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Matricula[10];
    char nome[100];
    char email[100];
}tAluno;

int buscatLisAlunoEst(tAluno relacao[],int n,char key[]){
    int i=0;
    while(i<n){
        if(strcmp(relacao[i].Matricula,key)==0)
        return i;
        i++;
    }
    return n;
}
int tListAlunosBuscaNaoOrdenadaEst(tAluno relacao[], int n, char key[]){
        int i=0;
        if(strcmp(relacao[n].Matricula,key)!=0){
             i++;
        }
        return i;
}
int tListAlunosBuscaNaoOrdenadaRec(tAluno relacao[], int n, char key[]){
      if(!strcmp(relacao[0].Matricula,key)){
            return 0;
        }
        else{
            return 1+tListAlunosBuscaNaoOrdenadaRec(&relacao[1],n-1,key);
        }
    }

int tListAlunosBuscaOrdenada(tAluno relacao[],int n,char key[],int *achou){
    int i;
    *achou= 0;
    strcpy(relacao[n].Matricula,key);
    while(strcmp(relacao[i].Matricula,key)<0){
        i++;
    }
    if((strcmp(relacao[i].Matricula,key)==0)&&(i<n))
            *achou = 1;
    return i;
    }
int tListAlunosBuscaOrdenadaRec(tAluno relacao[], int n,char key[],int *achou){
    int i;
    int con;
    if(n==0){
        *achou = 0;
        return 0;
    }
    else{
        i=n;
        con = strcmp(relacao[i].Matricula,key);
    }
    if(con<0){
        return i+tListAlunosBuscaOrdenadaRec(&relacao,n,key,achou);
    }
    if(con>0){
        return i+tListAlunosBuscaOrdenadaRec(&relacao,n,key,achou);
    }
    else{
        *achou=1;
        return i;
        }
}

int tListAlunosBuscaOrdenadaBinRec(tAluno relacao[],int n,char key[],int *achou){
    int i;
    int con;
    if(n==0){
        *achou = 0;
        return 0;
    }
    else{
    i=n/2;
    con = strcmp(relacao[i].Matricula,key);
    }
    if(con<0){
        return i+tListAlunosBuscaOrdenadaRec(&relacao,(n-(n/2)),key,achou);
    }
    if(con>0){
        return i+tListAlunosBuscaOrdenadaRec(&relacao,n/2,key,achou);
    }
    else{
        *achou=1;
        return i;
        }
}

int main(){
    char relacao[]="alunos.txt";
    FILE *arq;
    int n;
    int key[]={201820061};
    int *achou;
    arq=fopen(relacao,"r");
    if(arq==NULL){
        printf("Erro na abertura do arquivo!");
        exit -1;
    }
    while(!feof(arq)){
        fscanf(arq,"%d %s %s",&relacao);
    }
    buscatLisAlunoEst(&relacao,n,key);
    tListAlunosBuscaNaoOrdenadaEst(&relacao,n,key);
    tListAlunosBuscaNaoOrdenadaRec(&relacao,n,key);
    tListAlunosBuscaOrdenada(&relacao,n,key,*achou);
    tListAlunosBuscaOrdenadaRec(&relacao,n,key,*achou);
    tListAlunosBuscaOrdenadaBinRec(&relacao,n,key,*achou);
    fclose(arq);
    getch();
    return(0);

}
