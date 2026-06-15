#include <stdio.h>
#include "structEDA.c"
#include <stdlib.h>

void inserirIndustria(TNoI **lista, TCadastro cadastro){
    TNoI *novo = malloc(sizeof(TNoI));
    (*novo).dados = malloc(sizeof(TCadastro));
    (*(*novo).dados) = cadastro;
    (*novo).prox = NULL;
    if (*lista == NULL){
        *lista = novo;
        return;
    }

    TNoI *aux = *lista;
    while((*aux).prox != NULL){
        aux = (*aux).prox;
    }
    (*aux).prox = novo;
}

void carregarIndustria(TNoI **lista){
    FILE *arq = fopen("industria.txt", "r");
    if(arq == NULL){
        printf("erro ao abrir o arquivo");
        return;
    }

    TCadastro cad;

    while (fscanf(arq, "%s %s %s %s", cad.CNPJ, cad.razaoSocial, cad.cidade, cad.fone) == 4){
        inserirIndustria(lista, cad);
    }
    fclose(arq);
    
}

void relatorioIndustria(TNoI *lista){
    while(lista != NULL){
        printf("\n");
        printf("CNPJ: %s\n", (*(*lista).dados).CNPJ);
        printf("Razao Social: %s\n", (*(*lista).dados).razaoSocial);
        printf("Cidade: %s\n", (*(*lista).dados).cidade);
        printf("Telefone: %s\n", (*(*lista).dados).fone);
        lista = (*lista).prox;
    }
}

void inserirComercio(TNoC **lista, TCadastro cadastro){
    TNoC *novo = malloc(sizeof(TNoC));
    (*novo).dados = malloc(sizeof(TCadastro));
    (*(*novo).dados) = cadastro;
    (*novo).prox = NULL;
    (*novo).ante = NULL;
    if(*lista == NULL){
        *lista = novo;
        return;
    }
    TNoC *aux = *lista;
    while((*aux).prox != NULL){
        aux = (*aux).prox;
    }
    (*aux).prox = novo;
    (*novo).ante = aux;
}
void carregarComercio(TNoC **lista){
    FILE *arq = fopen("comercio.txt", "r");
    if(arq == NULL){
        printf("erro ao abrir o arquivo");
        return;
    }
    TCadastro cad;
    while(fscanf(arq, "%s %s %s %s", cad.CNPJ, cad.razaoSocial, cad.cidade, cad.fone) == 4){
        inserirComercio(lista, cad);
    }
    fclose(arq);
}

void relatorioComercio(TNoC *lista){
    while(lista != NULL){
        printf("\n");
        printf("CNPJ: %s\n", (*(*lista).dados).CNPJ);
        printf("Razao Social: %s\n", (*(*lista).dados).razaoSocial);
        printf("Cidade: %s\n", (*(*lista).dados).cidade);
        printf("Telefone: %s\n", (*(*lista).dados).fone);
        lista = (*lista).prox;
    }
}

void relatorioComercioInvertido(TNoC *lista){
    if(lista == NULL){
        return;
    }
    TNoC *aux = lista;
    while((*aux).prox != NULL){
        aux = (*aux).prox;
    }
    while(aux != NULL){
        printf("\n");
        printf("CNPJ: %s\n", (*(*lista).dados).CNPJ);
        printf("Razao Social: %s\n", (*(*lista).dados).razaoSocial);
        printf("Cidade: %s\n", (*(*lista).dados).cidade);
        printf("Telefone: %s\n", (*(*lista).dados).fone);
        aux = (*aux).ante;
    }
}

void inserirServicos(TDescritorS *lista, TCadastro cadastro){
    TNoS *novo = malloc(sizeof(TNoS));
    (*novo).dados = malloc(sizeof(TCadastro));
    (*(*novo).dados) = cadastro;
    (*novo).ante = NULL;
    (*novo).prox = NULL;
    if((*lista).inicio == NULL){
        (*lista).inicio = novo;
        (*lista).fim = novo;
    }
    else{
        (*novo).ante = (*lista).fim;
        (*(*lista).fim).prox = novo;
        (*lista).fim = novo;
    }
    (*lista).tamanho++;
}

void carregarArquivo(TDescritorS *lista){
    FILE *arq = fopen("servico.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    TCadastro cad;
    while(fscanf(arq, "%s %s %s %s", cad.CNPJ, cad.razaoSocial, cad.cidade, cad.fone) == 4){
        inserirServicos(lista, cad);
    }
    fclose(arq);
}
void relatorioServico(TDescritorS *lista)
{
    TNoS *aux = (*lista).inicio;

    while(aux != NULL)
    {
        printf("\n");
        printf("CNPJ: %s\n", aux->dados->CNPJ);
        printf("Razao Social: %s\n", aux->dados->razaoSocial);
        printf("Cidade: %s\n", aux->dados->cidade);
        printf("Fone: %s\n", aux->dados->fone);
        aux = aux->prox;
    }
}