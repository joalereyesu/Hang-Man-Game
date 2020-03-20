#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROWS 32
#define COLUMNS 6

int vuelo [6][32];
int getchar (void);


void clearscreen (){
  system("@cls||clear");
}

void salir (){
  exit (-1);
}

void cyan (){
  printf("\033[1;36m");
}

void green (){
  printf("\033[0;32m");
}

void yellow (){
  printf ("\033[1;33m");
}

void red (){
  printf("\033[1;31m");
}

void reset () {
  printf ("\033[0m");
}


void airplane (){
    int start = 4;
    clearscreen();
    cyan ();
    printf("                            * \n");
    printf("                           *** \n");
    printf("                          ***** \n");
    printf("                         ******* \n");
    printf("                         ******* \n");
    printf("                         ******* \n");
    printf("                         ******* \n");
    printf("                    **************** \n");
    printf("                  ******************** \n");
    printf("                 ***     *******     *** \n");
    printf("                **       *******       ** \n");
    printf("               *         *******         * \n");
    printf("                         ******* \n");
    printf("                         ******* \n");
    printf("                         ******* \n");
    printf("                        ********* \n");
    printf("                       ****   **** \n");
    printf("                      **         ** \n");
    printf("                     *             * \n\n\n");
    reset();
    red();
    printf("                   WELCOME TO AIRTRAVEL\n");
    reset();
    printf("                   Press enter to start");
    getchar();
}

void menu (){
    clearscreen();
    red();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
    reset();
    cyan();
    printf("1. Reservar Asiento \n");
    printf("2. Ver disponibilidad de asientos\n");
    printf("3. Salir \n");
    reset();
    printf("Ingrese un numero del menu\n");
}

void back_to_menu (){
  int choice;
  char m[4]={"menu"};

  if (choice=="menu"){
    menu();
  }
}

void disponibilidad (){
    clearscreen();
    int table[33][6] =
  {
    {0, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1},
    {1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1},
    {0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 1},
    {0, 0, 1, 1, 1, 0},
    {1, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0},
    {1, 0, 0, 1, 1, 1},
    {1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
  };
  yellow();
  printf(" | A | B | C | D | E | F |\n---------------------------\n");
  reset();
  for(int i = 1; i < 33; ++i)
  {
     yellow();
     printf("%d|",i);
     reset();
     for(int j = 0; j < 6; ++j)
     {
        if(table[i][j] > 9)
        {
          printf(" %d |", table[i][j]);
        } else {
          printf(" %d |", table[i][j]);
        }
     }
     yellow();
     printf("\n---------------------------\n");
     reset();
  }
  printf("Press enter to return to menu");
  getchar();
}

void salir (){
  exit (-1);
}


char asiento[6][32];
int x;
int i;
int j;
int butaca;
char a; 
int fila;

void todoreserva(){
void iniciar(){
	clearscreen ();
  x=0;
	for(i=0;i<7;i++){
		for (j=0;j<32;j++){
			asiento [i][j]='0';
		}
	}	
}
void reserva(){
	do{
		printf("Ingrese la Letra de la fila: (por favor usar mayusculas)\n");
		scanf("%c",&fila);
		
	while(getchar() != '\n');
	} while(fila < 'A' || fila > 'F' );
	
	do{
		printf("Ingrese numero asiento:\n");
		scanf("%d",&butaca);
	while(getchar() != '\n');
	}while(butaca < 1 || butaca > 32) ;
	if(fila =='A')
		x=0;
	if(fila =='B')
		x=1;
	if(fila =='C')
		x=2;
	if(fila =='D')
		x=3;
  if(fila == 'E')
    x=4;
  if(fila == 'F')
    x= 5;
		system("clear");
	if(asiento[x][butaca-1]=='X'){ 
		printf("el asiento %c%d Ya esta reservado\n porfavor, vuelva a ingresar un asiento que desee reservar\n",fila,butaca);
		reserva();
	}else{
		printf("Usted eligio el asiento %c%d\n", fila, butaca);
		asiento [x][butaca-1]= 'X'; 
	}
	
}
void cancelar (void){
	do{
		printf("Ingrese la Letra de la fila: (por favor utilizar letras mayusculas");
		scanf("%c",&fila);
	while(getchar() != '\n');
	} while(fila < 'A' || fila > 'F' );
	
	do{
		printf("Ingrese numero asiento :");
		scanf("%d",&butaca);
	while(getchar() != '\n');	
	}while(butaca < 1 || butaca > 32) ;
	if(fila =='A')
		x=0;
	if(fila =='B')
		x=1;
	if(fila =='C')
		x=2;
	if(fila =='D')
		x=3;
  if(fila == 'E')
    x=4;
  if(fila =='F')
    x=5;
		system("clear");
	if(asiento[x][butaca-1]!='X'){
		printf("el asiento %c%d NO esta reservado por lo tanto, ingrese el asiento el cual quisiera cancelar su reservacion.\n ",fila,butaca);
	
	}else{
		printf("Usted ha cancelado su reservacion del asiento %c%d\n", fila, butaca);
		asiento [x][butaca-1]= '0';
	
	}

}

void mostrar (void){
	a='A';
	printf("\t");
	for (j=1;j<33;j++){
			printf("[%d]\n ",j);
		}
		printf("\n");
    for(i=0;i<6;i++){
		printf("%c\t", a);
		a= a+1;
		for (j=0;j<33;j++){
			if (j<10)
				printf("%c ",asiento[i][j]);
			else
				printf(" %c ",asiento[i][j]);
		}
	printf("\n");
	}
}
int main (void) {
	int op1;
	iniciar ();
	while(1){
		mostrar();
	printf("ingrese el numero de la opcion que quiere seleccionar:\n");
	printf("1- reservar asiento\n");
	printf("2- cancelar reservacion previa\n");
	printf("3- salir\n");
	scanf("%d",&op1);
	switch (op1){
		case 1:
			reserva();
			break;
		case 2:
			cancelar();
			break;
		case 3:
			exit(1);
			break;
      default:break;
	}
}
}
}

int main (void){
    int choice;
    airplane();
    getchar();
    menu();
    scanf("%d", &choice);
      if (choice==1){
        //reservacion
      }
      if (choice==2){
        disponibilidad();
      }
      if (choice==3){
        salir();
      }
    
}