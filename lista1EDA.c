#include <stdio.h> //inicialização do arquivo de cabeçalho para entrada e saída padrão

/* int main() {
    int a = 10;
    float b = 3.14;
    int *p1;
    float *p2;
    p1 = &a;
    p2 = &b;
    printf("o valor de a eh: %d\n", *p1);
    printf("o valor de b eh: %.2f\n", *p2);
    return 0;
}*/

/* int main() {
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
} */
/*
int main(){
    int a = 10;
    int *p;
    p = &a;
    *p += 5;
    *p *= 2;
    printf("o valor de a depois de somar 5 e multiplicar por 2 eh %d",*p);
}*/

/*int main(){
    int a = 10, b = 5;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;
    printf("valor de a eh: %d\nvalor de b eh: %d\n", *p1, *p2);
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
    printf("o valor de a eh: %d\no valor de b eh: %d", *p2, *p1);
} */

/*int main(){ 
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
   
}*/

/*void dobra(int *x){
    *x *= 2;
}

int main(){
    int a = 10;
    dobra(&a);
    printf("o novo valor de a eh: %d\n", a);
}*/

int maior(int *v, int tamanho){
    int max = v;
}