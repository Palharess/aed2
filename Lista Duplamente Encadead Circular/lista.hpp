#ifndef __LISTA_H__
#define __LISTA_H__
#include "pessoa.hpp"

typedef struct l_node * L_NODE;
typedef struct l_list * L_LIST;

L_LIST cria_lista();
L_NODE cria_node(Pessoa pessoa, L_NODE head);
void insere_lista(Pessoa pessoa, L_LIST lista);
void mostra_lista(L_LIST lista);
void mostra_node(L_NODE node, L_NODE last);
Pessoa achar_pessoa(L_LIST lista, char * nome);
L_NODE achar_pessoa_node(L_LIST lista, char * nome);
void remove_elemento(int chave, L_LIST lista);
int pega_chave(L_NODE node);
int verificar(char * matricula, L_LIST lista);
int pega_qtd(L_LIST lista);


#endif