#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//codigo vai apresentar 3 estruturas
//os meses, os dias e os compromissos.
//os meses irão conter os dias e o nome do mes
//os dias irão conter os compromissos
//os compromissos irão conter uma descrição e uma hora.
//sendo estruturados em uma lista.

typedef struct Compromissos
{
    int hora;//id do compromisso
    char descricao[30];
    struct Compromissos *prox;
} Compromissos;

typedef struct Compromissos * p_comp;

typedef struct Dias
{	
	int id;
    struct Compromissos *lista_comp;
    struct Dias *prox;
} Dias;

typedef struct Dias * p_dia;

typedef struct Meses
{
	int id;
    struct Dias *lista_dia;
    struct Meses *prox;
} Meses;

typedef struct Meses * p_mes;

void inicializa();

void add_comp (p_dia lista, int hora, char descricao[256]);

p_dia add_dia (p_mes lista, int dia);

p_mes add_mes (int mes);

void print();

void print_dia(p_mes mes, int id_mes);

void print_comp(p_dia dia, int id_mes, int id_dia);

void remover(p_dia dia, int hora);

int existe(p_dia dia, int hora);

p_dia buscar_dia(p_mes lista, int dia);

p_mes buscar_mes(int mes);

//void salva_agenda();