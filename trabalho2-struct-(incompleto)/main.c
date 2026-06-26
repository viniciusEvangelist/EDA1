#include "funcoes.c"
int main(){
    TNoI *industria = NULL;
    TNoC *comercio = NULL;

    TDescritorS servico;
    servico.inicio = NULL;
    servico.fim = NULL;
    servico.tamanho = 0;

    int opcao;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1 - Carregar Dados\n");
        printf("2 - Relatorio Industria\n");
        printf("3 - Relatorio Comercio\n");
        printf("4 - Relatorio Comercio Invertido\n");
        printf("5 - Relatorio Servico\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                carregarIndustria(&industria);
                carregarComercio(&comercio);
                carregarArquivo(&servico);
                printf("Dados carregados!\n");
                break;

            case 2:
                relatorioIndustria(industria);
                break;

            case 3:
                relatorioComercio(comercio);
                break;

            case 4:
                relatorioComercioInvertido(comercio);
                break;

            case 5:
                relatorioServico(&servico);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}