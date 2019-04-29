#include "funcoes.h"

void add_comp (p_dia lista, int hora, char descricao[30])
{   
    p_dia dia = (p_dia) malloc(sizeof(Dias));
    dia = lista;

    p_comp novo = (p_comp) malloc(sizeof(Compromissos));
    novo->hora = hora;
    strcpy(novo->descricao, descricao);

    if (dia->lista_comp==NULL)
      dia->lista_comp = novo;
    else 
    {
      novo->prox = dia->lista_comp;
      dia->lista_comp  = novo;
    }
}

void remover(p_dia dia, int hora)
{
    p_comp atual = dia->lista_comp;
    p_comp antes = dia->lista_comp;
    int primeiro=0;
    while(atual != NULL)
    {
        if(atual->hora == hora)
        {
            if(primeiro == 0)
            {
                p_comp aux = atual;
                atual = atual->prox;
                primeiro--;
                aux->hora = -1;
                //free(aux);
            }
            else
            {
            antes->prox = atual->prox;
            atual->hora-1;
            //free(atual);
            }
        }
        else
        {
            antes=atual;
            atual=atual->prox;
        }
        primeiro++;
    }
}

void print_comp(p_dia dia, int id_mes, int id_dia){
    p_comp lista = dia->lista_comp;
    while(lista != NULL)
    {
        if(lista->hora > -1)
            printf("MES: %d DIA: %d HORA: %d DESCRICAO: %s\n", id_mes, id_dia, lista->hora, lista->descricao);
        lista = lista->prox;
    }
}

/*void salva_comp(p_dia dia, int id_mes, int id_dia){
    p_comp lista = dia->lista_comp;
    FILE * file;
    file = fopen("save", "w");
    if(file != NULL){
        //fprintf(file, "%d\n", contagem()); 
        for(lista; lista != NULL; lista=lista->prox){
            if(lista->hora > -1){
                //printf("MES: %d DIA: %d HORA: %d DESCRICAO: %s\n", id_mes, id_dia, lista->hora, lista->descricao);
                //fprintf(file,"MES: %d DIA: %d HORA: %d DESCRICAO: %s", id_mes, id_dia, lista->hora, lista->descricao);
            }
        }
    }
    else
        printf("ERRO\n");
    fclose(file);
}*/

int existe(p_dia dia, int hora)
{
    p_comp atual = dia->lista_comp;
    while(atual != NULL)
    {
        if(atual->hora == hora)
        {
            return 11;        
        }
        atual = atual->prox;
    }
    return 10;
}