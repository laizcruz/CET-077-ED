#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FALSE 0
#define TRUE 1

typedef struct{
	char numMatricula[10];
	char nome[100];
	char email[100];
}tAluno;

int ListAlunoBuscaEst(tAluno lista[], int tam, char chave[10]){
	int i=0;
	while(i<tam){
		if((strcmp(lista[i].numMatricula,chave) ==0)){
			return i;
			i++;
		}
    }
	return tam;
}

int tListAlunoBuscaRec(tAluno lista[], int tam,char chave[]){
	if(tam==0){
		return 1;
	}

		if(!strcmp(lista[0].numMatricula,chave)){
			return 0;
		}

	else{
		return 1+tListAlunoBuscaRec(&lista[1],tam-1,chave);
	}
}

int tListAlunoBuscaOrd(tAluno lista[], int tam,char chave[],int *achou){
    int i=0;
    *achou = FALSE;
    strcpy(lista[tam].numMatricula,chave);
    while(strcmp(lista[i].numMatricula,chave)<0){
        i++;
    }
    if((strcmp(lista[i].numMatricula,chave)==0)&&(i<tam)){
        *achou=TRUE;
        return i;
    }
}

int tListAlunoBin(tAluno lista[], int tam, char chave[], int* achou)
{
	int i;
	int min = 0;
	int max = tam;
	*achou = FALSE;

	while (min!=max){
		i=(max+min)/2;
		int com= strcmp(lista[i].numMatricula, chave);
		if (com<0){
			min=++i;
		}else{
			if(com>0){
				max = i;
			}else{
				if(i<tam)
					*achou = TRUE;
				return i;
			}
		}
}
	return i;
}
int tListAlunoBuscaBinRec(tAluno lista[],int tam,char chave[],int*achou){
    int i;
    int con;
    if(tam==0){
        *achou=FALSE;
        return 0;
    }
    else{
        i = tam/2;
        con = strcmp(lista[i].numMatricula,chave);
    }
        if(con<0){
            return i+tListAlunoBuscaBinRec(&lista[i],tam-(tam/2),chave,achou);
        }

            if(con>0){
                return tListAlunoBuscaBinRec(lista,tam/2,chave,achou);
            }

        else{
            achou=TRUE;
            return i;
        }
}
int inc_tListBuscaOrd(tAluno aluno,tAluno lista[],int tam){
    int achou;
    int i=tListBuscaAlunoBin(lista,tam,aluno.numMatricula,&achou);
	if (i == tam){
		strcpy(lista[tam].numMatricula, aluno.numMatricula);
		strcpy(lista[tam].nome, aluno.nome);
		strcpy(lista[tam].email,aluno.email);
		return 0;
    }
    else if(!achou){
        tAluno troca;
		for(int j = i; j < tam; j++){
			strcpy(troca.numMatricula, lista[j].numMatricula);
			strcpy(troca.nome, lista[j].nome);
			strcpy(troca.email, lista[j].email);

			strcpy(lista[j].numMatricula, aluno.numMatricula);
			strcpy(lista[j].nome, aluno.nome);
			strcpy(lista[j].email, aluno.email);

			strcpy(aluno.numMatricula, troca.numMatricula);
			strcpy(aluno.nome, troca.nome);
			strcpy(aluno.email, troca.email);
		}
		strcpy(lista[tam].numMatricula, aluno.numMatricula);
		strcpy(lista[tam].nome, aluno.nome);
		strcpy(lista[tam].email, aluno.email);
		return 0;
	}
	return 1;
}
int rem_tListAlunoBusca(tAluno lista[],int tam){
    int i,j;
    char chave;
    if(tListAlunoBuscaEst(lista,tam,chave)==tam){
    return FALSE;
    }
    else{
    for(i=j;j<tam;j++){
        strcpy(lista[j].numMatricula,lista[j+1].numMatricula);
        strcpy(lista[j].nome,lista[j+1].nome);
        strcpy(lista[j].email,lista[j+1].email);
    }
    tam--;
    return TRUE;
    }

}

int main(){
    tAluno *lista;
    int i;
    lista=malloc(sizeof(tAluno));
    FILE *ptr;
    char arquivo[20]="alunos.txt";
    ptr=fopen(arquivo,"r+");
    if(ptr==NULL){
        printf("Erro na abertura do arquivo!");
        exit(-1);
    }
    else{
        while(ptr!=EOF){
            fscanf((ptr,"%s %s %s",lista->aluno[i].numMatricula,lista->arquivo[i].nome,lista->aluno[i].email);
        }
    }
    int opc;
    printf("Se deseja adicionar um aluno na lista, digite 1\n Se deseja excluir um aluno da lista, digite 2\n");
    scanf("%d",&opc);
    if(opc==1){
        printf("Digite o numero de matricula:\n");
        scanf("%s",&aluno.numMatricula);
        printf("Digite o nome do aluno:\n");
        gets(aluno.nome);
        printf("Digite o email:\n");
        scanf("%s",aluno.email);
        inc_tListBuscaOrd(aluno,lista,tam);
        printf("Aluno adicionado com sucesso!\n");
        }
    else{
        printf("Digite o numero de matricula:\n");
        scanf("%s",&aluno.numMatricula);
        printf("Digite o nome do aluno:\n");
        gets(aluno.nome);
        printf("Digite o email:\n");
        scanf("%s",aluno.email);
        rem_tListAlunoBusca(aluno,tam);
        printf("Aluno adicionado com sucesso!\n");
        }
    system("PAUSE");
    return(0);
 }

