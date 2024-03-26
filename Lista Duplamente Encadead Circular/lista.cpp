#include "lista.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct l_node
{
    Pessoa pessoa;
    L_NODE next;
    L_NODE previous;
    int chave;
};

struct l_list
{
    L_NODE head;
    int qtd;
    L_NODE last;
};

L_LIST cria_lista()
{
    L_LIST lista = NULL;
    lista = (L_LIST)malloc(sizeof(struct l_list));
    lista->head = NULL;
    lista->last = NULL;
    lista->qtd = 0;
    return lista;
}

L_NODE cria_node(Pessoa pessoa, L_NODE head)
{
    L_NODE nova = NULL;
    nova = (L_NODE)malloc(sizeof(struct l_node));
    nova->next = head;
    nova->previous = NULL;
    nova->pessoa = pessoa;
    return nova;
}

void insere_lista(Pessoa pessoa, L_LIST lista)
{
    L_NODE node = cria_node(pessoa, lista->head);
    if (lista->head == NULL)
    {
        lista->head = node;
        lista->last = node;
        lista->qtd++;
        node->chave = 0;
        node->next = lista->last;
        return;
    }
    node->chave = lista->last->chave + 1;
    lista->last->next = node;
    node->previous = lista->last;
    lista->last = node;
    lista->qtd++;
}

void mostra_node(L_NODE node, L_NODE head)
{
    printf("%s ", pega_nome(node->pessoa));
    if (node->next == head)
    {
        return;
    }
    mostra_node(node->next, head);
}

void mostra_lista(L_LIST lista)
{
    printf("[");
    if (lista->head != NULL)
        mostra_node(lista->head, lista->head);
    printf("]\n");
}

Pessoa achar_pessoa(L_LIST lista, char *nome)
{
    L_NODE atual = lista->head;
    L_NODE first = lista->head;
    int q = 0;
    while (1)
    {
        if (first == atual && q > 0)
        {
            break;
            printf("Nao existe nenhuma pessoa com esse nome\n");
        }
        if (strcmp(pega_nome(atual->pessoa), nome) == 0)
        {
            return atual->pessoa;
        }
        atual = atual->next;
        q++;
    }
}

L_NODE achar_pessoa_node(L_LIST lista, char *nome)
{
    L_NODE atual = lista->head;
    L_NODE first = lista->head;
    int q = 0;
    while (1)
    {
        if (first == atual && q > 0)
        {
            break;
            printf("Nao existe nenhuma pessoa com esse nome\n");
        }
        if (strcmp(pega_nome(atual->pessoa), nome) == 0)
        {
            return atual;
        }
        atual = atual->next;
        q++;
    }
}

int pega_chave(L_NODE node){
    return node->chave;
}

void remove_elemento(int chave, L_LIST lista) {
    if (lista->head == NULL) {
        printf("Sem elementos na lista\n");
        return;
    }

    L_NODE atual = lista->head;
    while (atual->chave != chave) {
        atual = atual->next;
        if (atual == lista->head) {
            return;
        }
    }

    if (atual == lista->head) {
        if (lista->qtd == 1) {
            lista->head = NULL;
            lista->last = NULL;
        } else {
            lista->head = atual->next;
            lista->last->next = lista->head;
            lista->head->previous = lista->last;
        }
    } else if (atual == lista->last) {
        lista->last = atual->previous;
        lista->last->next = lista->head;
        lista->head->previous = lista->last;
    } else {
        atual->previous->next = atual->next;
        atual->next->previous = atual->previous;
    }

    free(atual);
    lista->qtd--;
}


//0 para não pode 1 para pode

int verificar(char * matricula, L_LIST lista){

    if(lista->qtd == 0){
        return 1;
    }
    int contador = lista->qtd;
    L_NODE atual = lista->head;
    while(1){
        if(strcmp(pega_matricula(atual->pessoa), matricula) == 0){
            return 0;
        }
        if(atual->next == lista->head) return 1;
        atual = atual->next;
    }
    
}
    
int pega_qtd(L_LIST lista){
    return lista->qtd;
}