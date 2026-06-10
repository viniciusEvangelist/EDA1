#include "tipos.h.c"
#include <stdio.h>
#include <stdlib.h>

void reset(TTemperatura *t){
    if(t->medidas != NULL){
        free(t->medidas);
    }
    printf("%s", "quantidade de dias: ");
    scanf("%d", &t->qtde_dias);
    t->medidas = malloc(t->qtde_dias * sizeof(TMedidas));
    t->qtde_medidas = 0;
}

void inserirMedida(TTemperatura *t){
    if(t->qtde_medidas >= t->qtde_dias){
        printf("vetor cheio\n");
        return;
    }
    int pos = t->qtde_medidas;
    printf("Cidade: ");
    scanf("%s", t->medidas[pos].cidade);
    t->medidas[pos].temperatura = malloc(sizeof(float));
    if(t->medidas[pos].temperatura == NULL){
        printf("erro de alocacao\n");
        return;
    }
    printf("temperatura: ");
    scanf("%f", t->medidas[pos].temperatura);
    t->qtde_medidas++;
    printf("medidas cadastradas com sucesso\n");
}

void estatistica(TTemperatura *t){
    if(t->qtde_medidas == 0){
        printf("nenhuma medida cadastrada\n");
        return;
    }
    float soma = 0;
    int menor = 0;
    int maior = 0;
    for(int i = 0; i<t->qtde_medidas; i++){
        soma += *(t->medidas[i].temperatura);
        if(*(t->medidas[i].temperatura)< *(t->medidas[menor].temperatura)){
            menor = i;
        }
        if(*(t->medidas[i].temperatura)> *(t->medidas[maior].temperatura)){
            maior = i;
        }
    }
    float media = soma/t->qtde_medidas;
    printf("\n===== ESTATISTICAS =====\n");
    printf("media: %.2f\n", media);
    printf("menor temperatura\n");
    printf("cidade: %s\n", t->medidas[menor].cidade );
    printf("temperatura: %s\n", *(t->medidas[menor].temperatura));
    printf("\nmaior temperatura\n");
    printf("cidade: %s\n", t->medidas[maior].cidade);
    printf("temperatura: %.2f\n", *(t->medidas[maior].temperatura));
}

void liberarMemoria(TTemperatura *t){
    for(int i = 0; i<t->qtde_medidas; i++){
        free(t->medidas[i].temperatura);
    }
    free(t->medidas);
    t->medidas = NULL;
    t->qtde_dias = 0;
    t->qtde_medidas = 0;
}

int main(){
    TTemperatura sistema;
    sistema.medidas = NULL;
    sistema.qtde_dias = 0;
    sistema.qtde_medidas = 0;
    
    
    int opcao;
    do{
    
        printf("opcao 1: reset\n");
        printf("opcao 2: inserir medida\n");
        printf("opcao 3: estatistica\n");
        printf("sair\n");
        printf("digite a opcao\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1: 
            reset(&sistema);
            break;

            case 2:
            inserirMedida(&sistema);
            break;

            case 3:
            estatistica(&sistema);
            break;

            case 4: 
            liberarMemoria(&sistema);
            printf("encerrando programa\n");
            break;

        }
    }
    while (opcao != 4);
    return 0;
}