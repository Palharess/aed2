#include "pessoa.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pessoa{
    char Matricula[20];
    char Nome[30];
    char Curso[30];
    double Nota1;
    double Nota2; 
};



Pessoa cria_pessoa(char * Matricula, char * Nome, char * Curso, double Nota1, double Nota2){
    Pessoa nova = NULL;
    nova = (Pessoa) malloc(sizeof(struct pessoa));
    strcpy(nova->Matricula, Matricula);
    strcpy(nova->Nome, Nome);
    strcpy(nova->Curso, Curso);
    nova->Nota1 = Nota1;
    nova->Nota2 = Nota2;
    return nova;
}


char * pega_nome(Pessoa pessoa){
    return pessoa->Nome;
}

void muda_dados(Pessoa pessoa){
    char Matricula[20],Nome[30],Curso[30];
    double Nota1,Nota2; 
    printf("Digite os novos dados:\n");
    printf("Matricula: ");
    scanf("%s", Matricula);
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
    strcpy(pessoa->Matricula, Matricula);
    strcpy(pessoa->Nome, Nome);
    strcpy(pessoa->Curso, Curso);
    pessoa->Nota1 = Nota1;
    pessoa->Nota2 = Nota2;
}

char * pega_matricula(Pessoa pessoa){
    return pessoa->Matricula;
}

double media(Pessoa pessoa){
    return (pessoa->Nota1 + pessoa->Nota2)/2.0;
}

double pega_n1(Pessoa pessoa){
    return pessoa->Nota1;
}
double pega_n2(Pessoa pessoa){
    return pessoa->Nota2;
}

char * pega_curso(Pessoa pessoa){
    return pessoa->Curso;
}