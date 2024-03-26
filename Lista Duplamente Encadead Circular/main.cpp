#include <stdio.h>
#include "lista.hpp"

int main(){
    L_LIST lista = cria_lista();
    char Matricula[20],Nome[30],Curso[30];
    double Nota1,Nota2; 
    
    while(1){
        int escolha;
        printf("1 para criar uma pessoa\n");
        printf("2 para ver a lista\n");
        printf("3 alterar as informações de uma pessoa\n");
        printf("4 para deletar uma pessoa\n");
        printf("5 Mostrar a media de alguem\n");
        printf("6 para sair\n");
        scanf("%d%*c", &escolha);
        if(escolha == 1){
            printf("Matricula: ");
            scanf("%s", Matricula);
            if(verificar(Matricula, lista) == 0){
                printf("Ja possui alguem com essa matricula!\n");
                break;
            }
            printf("Nome: ");
            scanf("%s", Nome);
            printf("Curso: ");
            scanf("%s", Curso);
            while(1){
                printf("Nota 1: ");

                scanf("%lf%*c", &Nota1);
                if(Nota1 >= 0 && Nota1 <= 10){
                    break;
                }
                printf("Nota invalida!\n");
            }
            
            while(1){
                printf("Nota 2: ");
                scanf("%lf%*c", &Nota2);
                if(Nota2 >= 0 && Nota2 <= 10){
                    break;
                }
                printf("Nota invalida!\n");
            }

            
            
            
            Pessoa pessoa = cria_pessoa(Matricula, Nome, Curso, Nota1, Nota2);
            
            insere_lista(pessoa, lista);
        }
        else if(escolha == 2){
            if(pega_qtd(lista) == 0){
                printf("Lista vazia!\n");
                break;
            }
            mostra_lista(lista);
        }
        else if(escolha == 3){
            if(pega_qtd(lista) == 0){
                printf("Lista vazia!\n");
                break;
            }
            printf("Digite o nome da pessoa que vc deseja alterar: ");
            scanf("%s", Nome);
            Pessoa p = achar_pessoa(lista,Nome);
            printf("Deseja alterar %s? (S/N): ", pega_nome(p));
            char resposta;
            scanf(" %c", &resposta);
            if (resposta != 'S') {
                break;
            }
            muda_dados(p);     

            
        }
        else if(escolha == 4){
            char resposta;
            if(pega_qtd(lista) == 0){
                printf("Lista vazia!\n");
                break;
            }
            printf("Digite o nome da pessoa que vc deseja remover: ");
            scanf("%s", Nome);
            L_NODE achou = achar_pessoa_node(lista, Nome);
            Pessoa p = achar_pessoa(lista,Nome);
            printf("Deseja excluir %s? (S/N): ", pega_nome(p));
            scanf(" %c", &resposta);
            if (resposta != 'S') {
                break;
            }
            remove_elemento(pega_chave(achou), lista);
        }
        else if(escolha == 5){
            if(pega_qtd(lista) == 0){
                printf("Nao ha ninguem na lista!\n");
                break;
            }
            printf("Digite o nome de quem quer mostrar a media: ");

            scanf("%s", Nome);
            Pessoa achou = achar_pessoa(lista, Nome);
            printf("A media de %s: %.2lf\n", pega_nome(achou), media(achou));

        }
        else if(escolha == 6){
            break;
        }

    }
    

    return 0;
}