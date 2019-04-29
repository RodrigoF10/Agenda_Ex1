#include "funcoes.h"

p_dia add_dia (p_mes lista, int dia)
{
    p_mes mes = (p_mes) malloc(sizeof(Meses));
    mes = lista;

    p_dia novo = (p_dia) malloc(sizeof(Dias));
    novo->id=dia;
    if (mes->lista_dia==NULL)
      mes->lista_dia = novo;
    else 
    {
      novo->prox = mes->lista_dia;
      mes->lista_dia = novo;
    }
    return novo;
}

p_dia buscar_dia(p_mes lista, int dia){
	p_mes mes = (p_mes) malloc(sizeof(Meses));
    mes = lista;
    while(mes->lista_dia != NULL){
    	if(mes->lista_dia->id == dia)
    		return mes->lista_dia;
    	mes->lista_dia=mes->lista_dia->prox;
    }
}

void print_dia(p_mes mes, int id_mes){   
    p_dia lista = mes->lista_dia;
    while(lista != NULL)
    {
        print_comp(lista, id_mes, lista->id);
        lista = lista->prox;
    }
}

/*void salva_dia(p_mes mes, int id_mes){   
    p_dia lista = mes->lista_dia;
    while(lista != NULL)
    {
        //printf("SALVANDO DIA: %d\n",lista->id);
        salva_comp(lista, id_mes, lista->id);
        lista = lista->prox;
    }
}*/