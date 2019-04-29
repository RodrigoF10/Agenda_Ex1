#include "funcoes.h"

p_mes inicio = NULL;

void inicializa(){
    int i, j, cont, hora, id_dia, id_mes;
    char descricao[30];
    p_mes novo = (p_mes) malloc(sizeof(Meses));
    for (i=12;i>=1;i--){
        novo = add_mes(i);
        for(j=31;j>=1;j--){
            if((i == 4|| i == 6|| i == 9|| i == 11)&&(j<31))
                novo->lista_dia = add_dia(novo, j);
            else{
                if((i == 2)&&(j<29))
                    novo->lista_dia = add_dia(novo, j);
                else{ 
                    if( i == 1|| i == 3|| i == 5|| i == 7|| i == 8|| i == 10|| i == 12)
                        novo->lista_dia = add_dia(novo, j);
                }
            }    
        }
    }
    FILE * file;
    p_mes agenda = NULL;
    file = fopen("save", "r");
    if(file != NULL){
        fscanf(file, "%d", &cont);
        for(i=0;i<cont+1;i++){
            fscanf(file, "%d", &id_mes);
            fscanf(file, "%d", &id_dia);
            fscanf(file, "%d", &hora);
            fgets(descricao, 30, file);
            if(file != NULL){
                agenda = buscar_mes(id_mes);
                agenda->lista_dia = buscar_dia(agenda, id_dia);
                add_comp(agenda->lista_dia, hora, descricao);
                agenda = buscar_mes(1);
                agenda->lista_dia = buscar_dia(agenda, 1);
            }
        }
    }
    fclose(file);
}

p_mes add_mes (int mes)
{
    p_mes novo = (p_mes) malloc(sizeof(Meses));
    novo->id = mes;
    if (inicio==NULL)
      inicio = novo;
    else 
    {
      novo->prox = inicio;
      inicio  = novo;
    }
    return inicio;
}

p_mes buscar_mes(int mes){
	p_mes agenda = (p_mes) malloc(sizeof(Meses));
    agenda = inicio;
    while(agenda != NULL){
    	if(agenda->id == mes)
    		return agenda;
    	agenda = agenda->prox;
    }
}

void print()
{   
    p_mes lista = inicio;
    while(lista != NULL)
    {   
        print_dia(lista, lista->id);
        lista = lista->prox;
    }
}
/*
void salva_agenda()
{   
    p_mes lista = inicio;
    while(lista != NULL)
    {   
        salva_dia(lista, lista->id);
        lista = lista->prox;
    }
}

int contagem()
{   
    p_mes lista = inicio;
    int cont = 0;
    while(lista != NULL)
    {   
        while(lista->lista_dia != NULL)
        {
            while(lista->lista_dia->lista_comp != NULL){
                if(lista->lista_dia->lista_comp->hora > -1){
                    printf("%d\n", lista->lista_dia->lista_comp->hora);
                    cont++;
                }
                lista->lista_dia->lista_comp = lista->lista_dia->lista_comp->prox;
            }   
            lista->lista_dia = lista->lista_dia->prox;
        }
        lista = lista->prox;
    }
    return cont;
}*/