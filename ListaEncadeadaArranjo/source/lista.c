#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista() {
    Lista *li;
    li = malloc(sizeof(struct lista));
    if(li != NULL) {
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista *li) {
    free(li);
}

int tamanho_lista(Lista *li) {
    if(li == NULL) {
        return -1;
    } else {
        return li->qtd;
    }
}

int lista_cheia(Lista *li) {
    if(li == NULL)
        return -1;
    else
        return (li->qtd == MAX);
}

int lista_vazia(Lista *li) {
    if(li == NULL)
        return -1;
    else
        return (li->qtd == 0);

}

int insere_lista_inicio(Lista *li, struct aluno al) {
    if(li == NULL)
        return 0; // lista não alocada
    if (li->qtd == MAX)
            return 0; // lista cheia

    // abre espaço jogando os elementos para traz
    for(int i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];

    // insere elemento no
    li->dados[0] = al;
    li->qtd++;
    return 1; // sucesso na inserção
}

int insere_lista_final(Lista *li, struct aluno al) {
    if(li == NULL)
        return 0; // lista não alocada
    if(li->qtd == MAX)
        return 0; // lista cheia

    //inseção no final
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1; // sucesso na inserção
}

// pre requisito: Não misturar com outras inserções
int insere_lista_ordenada(Lista *li, struct aluno al) {
    if(li == NULL)
        return 0;
    if(li->qtd == MAX) // lista cheia
        return 0;

    // encontrar a posição para inserir
    int i=0;
    while(i < li->qtd && li->dados[i].matricula <al.matricula)
        i++;

    // abre espaco para inserção
    for(int k=li->qtd-1 ; k>= i ; k--)
        li->dados[k+1] = li->dados[k];

    // insere o elemento na posicao i
    li->dados[i] = al;
    li->qtd++;
    return 1; // sucesso na inserção
}

int remove_lista_inicio(Lista *li) {
    if(li == NULL)
        return 0;
    if(li->qtd == 0) // lista vazia
        return 0;

    for(int i=0 ; i<li->qtd-1 ; i++)
        li->dados[i] = li->dados[i+1];

    li->qtd--;
    return 1; // sucesso na remoção do primeiro elemento
}

int remove_final(Lista *li) {
    if(li == NULL)
        return 0;
    if(li->qtd == 0) // lista vazia
        return 0;
    li->qtd--;
    return 1; // sucesso na remoção
}

int remove_lista(Lista *li, int mat) {
    if(li == NULL)
        return 0;
    if(li->qtd == 0) // lista vazia
        return 0;

    // procurar pelo elemento
    int i=0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd) // elemento não encontrado
        return 0;

    // move os elementos para tampar o elemento retirado
    for(int k=i ; k < li->qtd-1 ; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1; // sucesso na remoção
}

int busca_lista_pos(Lista *li, int pos, struct aluno *al) {
    if(li == NULL || pos <= 0 || pos > li->qtd)
            return 0;

    *al = li->dados[pos-1];
    return 1; // elemento encontrado
}

int busca_lista_mat(Lista *li, int mat, struct aluno *al) {
    if(li == NULL)
        return 0; // lista não alocada

    // procura pela matricula
    int i=0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;

    if(i == li->qtd) // elemento não encontrado
        return 0;

    *al = li->dados[i];
    return 1;
}

void imprime_lista(Lista *li) {
    if(li != NULL) {
        for(int i=0; i<li->qtd ; i++) {
            printf("[mat: %5d | nome: %-10s | n1: %4.2f, n2: %4.2f, n3: %4.2f]\n", li->dados[i].matricula, li->dados[i].nome, li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
        }
    }
}














































