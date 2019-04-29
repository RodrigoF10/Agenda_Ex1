#include "funcoes.h"

int main(int argc, char* argv[])
{
    p_mes agenda = NULL;
    int p=0, escolha=-1, mes=-1, dia=-1, hora=-1;
    char d[30], e;
    while(escolha < 1){
      printf("\nDESEJA ABRIR A AGENDA [S para sim e N para nao]:\n");
      scanf("%c", &e);
      if(e == 'N' ||e == 'n')
        return 0;
      if(e == 'S' ||e == 's'){
        inicializa();
        escolha = 2;
      }
    }
    escolha = -1;
    while(escolha != 0){
        printf("\n2-inserir compromisso\n3- remove compromisso\n4- lista compromissos\n5- verifica se existe compromisso agendado\n0- fecha a agenda\n\n");
        scanf("%d", &escolha);
        switch (escolha)
        {           
          case 2:
            while(mes<1||mes>12){
              printf("DIGITE O MES QUEIRA INSERIR O COMPROMISSO: (entre 1 e 12)\n");
              scanf("%d", &mes);
            }
            agenda = buscar_mes(mes);
            if( mes == 1|| mes == 3|| mes == 5|| mes == 7|| mes == 8|| mes == 10|| mes == 12){
              while(dia<1||dia>31){  
                printf("DIGITE O DIA QUEIRA INSERIR O COMPROMISSO: (entre 1 e 31)\n");
                scanf("%d", &dia);
              }
            }
            if( mes == 4|| mes == 6|| mes == 9|| mes == 11){
              while(dia<1||dia>30){  
                printf("DIGITE O DIA QUEIRA INSERIR O COMPROMISSO: (entre 1 e 30)\n");
                scanf("%d", &dia);
              }
            }
            if( mes == 2){
              while(dia<1||dia>29){  
                printf("DIGITE O DIA QUEIRA INSERIR O COMPROMISSO: (entre 1 e 29)\n");
                scanf("%d", &dia);
              }
            }
            agenda->lista_dia = buscar_dia(agenda, dia);
            while(hora<0||hora>23){
              printf("DIGITE A HORARIO DO COMPROMISSO: (entre 0 e 23) E A DESCRICAO A FRENTE\n");
              scanf("%d", &hora);
            }
            //scanf("%s", d);
            //puts("DIGITE A DESCRICAO DO COMPROMISSO:");
            fgets(d, 30, stdin);
            //printf("DIGITE A DESCRICAO DO COMPROMISSO: (entre 0 e 23)");
            //gets(d);
            //gets(d);
            //printf("DIGITE A DESCRICAO DO COMPROMISSO:\n");
            //scanf("%s", d);
            p = existe(agenda->lista_dia, hora);
            if(p == 11)
              printf("\n\nEXISTE HORARIO NESSA DATA\n");
            else{
              add_comp(agenda->lista_dia, hora, d);
            }
            agenda = buscar_mes(1);
            agenda->lista_dia = buscar_dia(agenda, 1);
            mes=-1;
            dia=-1;
            hora=-1;
          break;
          case 3:
            while(mes<1||mes>12){
              printf("DIGITE O MES QUEIRA REMOVER O COMPROMISSO: (entre 1 e 12)\n");
              scanf("%d", &mes);
            }
            agenda = buscar_mes(mes);
            if( mes == 1|| mes == 3|| mes == 5|| mes == 7|| mes == 8|| mes == 10|| mes == 12){
              while(dia<1||dia>31){  
                printf("DIGITE O DIA QUEIRA REMOVER O COMPROMISSO: (entre 1 e 31)\n");
                scanf("%d", &dia);
              }
            }
            if( mes == 4|| mes == 6|| mes == 9|| mes == 11){
              while(dia<1||dia>30){  
                printf("DIGITE O DIA QUEIRA REMOVER O COMPROMISSO: (entre 1 e 30)\n");
                scanf("%d", &dia);
              }
            }
            if( mes == 2){
              while(dia<1||dia>29){  
                printf("DIGITE O DIA QUEIRA REMOVER O COMPROMISSO: (entre 1 e 29)\n");
                scanf("%d", &dia);
              }
            }
            agenda->lista_dia = buscar_dia(agenda, dia);
            while(hora<0||hora>23){
              printf("DIGITE O HORARIO DO COMPROMISSO: (entre 0 e 23)\n");
              scanf("%d", &hora);
            }
            p = existe(agenda->lista_dia, hora);
            if(p == 11)
              remover(agenda->lista_dia, hora);
            else{
              printf("\n\nNAO EXISTE HORARIO NESSA DATA\n");
            }
            
            agenda = buscar_mes(1);
            agenda->lista_dia = buscar_dia(agenda, 1);
            mes=-1;
            dia=-1;
            hora=-1;
          break;
          case 4:
            print();
          break;
          case 5:
            while(mes<1||mes>12){
              printf("DIGITE O MES QUEIRA BUSCAR O COMPROMISSO: (entre 1 e 12)\n");
              scanf("%d", &mes);
            }
            agenda = buscar_mes(mes);
            if( mes == 1|| mes == 3|| mes == 5|| mes == 7|| mes == 8|| mes == 10|| mes == 12){
              while(dia<1||dia>31){  
                printf("DIGITE O DIA QUEIRA BUSCAR O COMPROMISSO: (entre 1 e 31)\n");
                scanf("%d", &dia);
              }
            }
            if( mes == 4|| mes == 6|| mes == 9|| mes == 11){
              while(dia<1||dia>30){  
                printf("DIGITE O DIA QUEIRA BUSCAR O COMPROMISSO: (entre 1 e 30)\n");
                scanf("%d", &dia);
              }
            }
            if( mes == 2){
              while(dia<1||dia>29){  
                printf("DIGITE O DIA QUEIRA BUSCAR O COMPROMISSO: (entre 1 e 29)\n");
                scanf("%d", &dia);
              }
            }
            agenda->lista_dia = buscar_dia(agenda, dia);
            while(hora<0||hora>23){
              printf("DIGITE O HORARIO DO COMPROMISSO: (entre 0 e 23)\n");
              scanf("%d", &hora);
            }
            p = existe(agenda->lista_dia, hora);
            if(p == 11)
              printf("\n\nEXISTE HORARIO NESSA DATA\n");
            else
              printf("\n\nNAO EXISTE HORARIO NESSA DATA\n");
            agenda = buscar_mes(1);
            agenda->lista_dia = buscar_dia(agenda, 1);
            mes=-1;
            dia=-1;
            hora=-1;          
          break;
          case 0:
            //salva_agenda();
          break;
          default:
          printf("\nDIGITE UM NUMERO ENTRE 0 e 5 SOMENTE!\n");
        } 
    }
    return 0;
}