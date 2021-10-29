#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "lista.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int mat;
    struct aluno a;
    Lista *li = cria_lista();

    for(int i=0;i<10;i++) {
        a.matricula = rand() % 100;
        strcpy(a.nome, "teste");
        a.n1 = rand() % 10;
        a.n2 = rand() % 10;
        a.n3 = rand() % 10;

        insere_lista_ordenada(li, a);
    }

    imprime_lista(li);

    printf("Digite uma matricula a ser buscada: ");
    scanf("%d", &mat);

    // busca por aluno na lista e exibe os seus dados
    if( busca_lista_mat(li,mat,&a) == 1) {
        printf("Matricula: %5d\n", a.matricula);
        printf("Nome: %-10s\n", a.nome);
        printf("Média das notas: %4.2f\n", (a.n1+a.n2+a.n3)/3 );
    }


    libera_lista(li);
    return 0;
}
