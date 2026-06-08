#include <stdio.h> //inicialização do arquivo de cabeçalho para entrada e saída padrão

//exercicio 1
int main() {
    int a = 10;
    float b = 3.14;
    int *p1;
    float *p2;
    p1 = &a;
    p2 = &b;
    printf("o valor de a eh: %d\n", *p1);
    printf("o valor de b eh: %.2f\n", *p2);
    return 0;
}

//exercicio 2
int main() {
    int a = 10, b = 20;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    printf("valor de a eh: %d\nvalor de b eh: %d\n", *p1, *p2); 
    int *temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
    printf("valor de a eh: %d\nvalor de b eh: %d\n", *p2, *p1);
} 


//exercicio 3
int main(){
    int a = 10;
    int *p;
    p = &a;
    *p += 5;
    *p *= 2;
    printf("o valor de a depois de somar 5 e multiplicar por 2 eh %d",*p);
}

//exercicio 4
int main(){
    int a = 10, b = 5;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    printf("valor de a eh: %d\nvalor de b eh: %d\n", *p1, *p2);
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
    printf("o valor de a eh: %d\no valor de b eh: %d", *p2, *p1);
} 

//exercicio 5
int main(){ 
    int v[5] = {10, 20, 30, 40, 50};
    int *p;
    int soma;
    p = &v[0];
    while(p < &v[5]){
        printf("%d ", *p);
        soma += *p;
        p++;
    }
    printf("\nsoma igual a: %d", soma);
   
}

//exercicio 6
void dobra(int *x){
    *x *= 2;
}

int main(){
    int a = 10;
    dobra(&a);
    printf("o novo valor de a eh: %d\n", a);
}

//Execicio 7
int maior(int *v, int tamanho){
    int max = *v;
    for(int i = 1; i<tamanho; i++){
        if(*(v+i) > max){
            max = *(v+i);
        }
    }
    return max;
}

int main(){
    int v[5] = {10, 20, 5, 30, 15};
    int max = maior(v, 5);
    printf("o maior valor do vetor eh: %d\n", max);
}

//exercicio 8
int conta(char *str, char c){
    int count = 0;
    while(*str != '\0'){ //esse \0 indica o fim da string, ele não é visualizavel, fica na memoria
        if (*str == c){
            count += 1;
        }
        str++;
    }
    return count;
}
int main(){
    char nome[] = "programacao"; //aqui por exemplo ficaria "p r o g r a m a c a o \0" na memoria
    printf("existem %d letra(s) c na palavra %s \n", conta(nome, 'c'), nome);
    return 0;
}
//exercicio 9
void inverte(int *v, int tamanho){
    int *inicio = v;
    int *fim = v + tamanho - 1;
    int temp;
    while(inicio < fim){
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}
int main(){
    int v[] = {1, 2, 3, 4, 5, 6};
    inverte(v, 6);
    for(int i =0; i<6; i++){
        printf("%d ", v[i]);
    }
}
//exercicio 10

