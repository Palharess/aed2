#ifndef __PESSOA_H__
#define __PESSOA_H__


typedef struct pessoa * Pessoa;
Pessoa cria_pessoa(char * Matricula, char * Nome, char * Curso, double Nota1, double Nota2);
char * pega_nome(Pessoa pessoa);
void muda_dados(Pessoa pessoa);
char * pega_matricula(Pessoa pessoa);
double media(Pessoa pessoa);
char * pega_curso(Pessoa pessoa);
double pega_n1(Pessoa pessoa);
double pega_n2(Pessoa pessoa);






#endif