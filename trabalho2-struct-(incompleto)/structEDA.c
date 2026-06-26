typedef struct Cadastro {
    char CNPJ[15];
    char razaoSocial[50];
    char cidade[30];
    char fone[12];
} TCadastro;

typedef struct NoI{
    TCadastro *dados;
    struct NoI *prox;
} TNoI;

typedef struct NoC{
    TCadastro *dados;
    struct NoC *ante;
    struct NoC *prox;
} TNoC;

typedef struct NoS{
    TCadastro *dados;
    struct NoS *ante;
    struct NoS *prox;
} TNoS;

typedef struct DescritorS{
    TNoS *inicio;
    int tamanho;
    TNoS *fim;
} TDescritorS;

typedef struct CadastroU{
    char CNPJ[15];
    char razaoSocial[50];
    char cidade[30];
    char fone[12];
    char tipo;
} TCadastroU;

typedef struct NoU{
    TCadastroU *dados;
    struct NoU *ante;
    struct NoU *prox;
} TNoU;

typedef struct DescritorU{
    TNoU *inicio;
    int tamanho;
    TNoU *fim;
} TDescritorU;