#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Pessoa {
    int matricula;
    char name[50];
    char curso[50];
    float nota1;
    float nota2;
};

struct Pessoa pessoas[50];
int qtd = 0;

void cria_pessoa() {
    if (qtd >= 50) {
        printf("Maximo de estudantes atingido\n");
        return;
    }

    struct Pessoa novo;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &novo.matricula);

    for (int i = 0; i < qtd; i++) {
        if (pessoas[i].matricula == novo.matricula) {
            printf("A matrícula ja existe.\n");
            return;
        }
    }
    printf("Digite o nome do aluno: ");
    scanf("%s", novo.name);
    printf("Digite o curso do aluno: ");
    scanf("%s", novo.curso);
    while(1){
    printf("Digite a nota 1 do aluno: ");

    scanf("%f", &novo.nota1);
    if(novo.nota1 >= 0 && novo.nota1 <= 10){
        break;
    }
    printf("Nota invalida!\n");
    }
    while(1){
    printf("Digite a nota 2 do aluno: ");

    scanf("%f", &novo.nota2);
    if(novo.nota2 >= 0 && novo.nota2 <= 10){
        break;
    }
    printf("Nota invalida!\n");
    }
    

    pessoas[qtd++] = novo;
}

void mostra_pessoas() {
    if (qtd == 0) {
        printf("Nao ha alunos registrados.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        struct Pessoa atual = pessoas[i];
        float media = (atual.nota1 + atual.nota2) / 2.0;
        printf("\nMatricula: %d\nNome: %s\nCurso: %s\nNota1: %.2f\nNota2: %.2f\nMedia:%.2f\n", atual.matricula, atual.name, atual.curso, atual.nota1, atual.nota2, media);
    }
}

void delete(int matricula) {
    for (int i = 0; i < qtd; i++) {
        if (pessoas[i].matricula == matricula) {
            printf("Deseja excluir %s? (S/N): ", pessoas[i].name);
            char resposta;
            scanf(" %c", &resposta);
            if (resposta == 'S' || resposta == 's') {
                for (int j = i; j < qtd - 1; j++) {
                    pessoas[j] = pessoas[j + 1];
                }
                qtd--;
                printf("Excluido\n");
            }
            return;
        }
    }
    printf("Aluno não existe\n");
}

int main() {
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1)Criar aluno\n");
        printf("2)Ler alunos\n");
        printf("3)Excluir aluno\n");
        printf("4)Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                cria_pessoa();
                break;
            case 2:
                mostra_pessoas();
                break;
            case 3: {
                if(qtd == 0){
                    printf("Sem alunos\n");
                    break;
                }
                int matricula;
                printf("Digite a matricula do aluno a ser excluido: ");
                scanf("%d", &matricula);
                delete(matricula);
                break;
            }
            case 4:
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (escolha != 4);

    return 0;
}
