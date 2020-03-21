#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROWS 32
#define COLUMNS 6

int vuelo [6][32];
int getchar (void);
int table [33][6] = {0};
int i, j;
char asiento[3];
int contador=0;
int x;
int columna;
int fila;
int n;
int choice;

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
}

void menu (){
    clearscreen();
    red();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
    reset();
    cyan();
    printf("1. Reserve a seat \n");
    printf("2. See seat availability\n");
    printf("3. Salir \n");
    reset();
    printf("Enter a number of the menu\n");
}

void disponibilidad (){
    clearscreen();
  
    yellow();
    printf(" | A | B | C | D | E | F |\n---------------------------\n");
    reset();
    for(int i = 1; i < 33; ++i)
    {
      yellow();
      printf("%d|",i);
      reset();
      for(int j = 0; j < 6; ++j){
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

void show (){
  clearscreen();
  
    yellow();
    printf(" | A | B | C | D | E | F |\n---------------------------\n");
    reset();
    for(int i = 1; i < 33; ++i)
    {
      yellow();
      printf("%d|",i);
      reset();
      for(int j = 0; j < 6; ++j){
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
}

void home_reservation(){
  clearscreen();
    yellow();
    printf("##########################SEAT RESERVATION#########################\n\n");
    reset();
    printf("In here you can reserve as many seats as you want. When you are done reserving your seats press 5 to finish. If you want to abort the reservation and return to menu type 'menu'\n\nPress enter to continue"); 
    getchar();
}

void reservacion (){
  while (1){
    clearscreen();
    show();
    printf("Enter the letter and number of your seat.\nSeat Number:");
    scanf("%s", asiento);
    char letter_asiento = asiento[0];
    if (letter_asiento == 'A'){
      columna = 0;
    }
    if (letter_asiento == 'B'){
      columna = 1;
    }
    if (letter_asiento == 'C'){
      columna = 2;
    }
    if (letter_asiento == 'D'){
      columna = 3;
    }
    if (letter_asiento == 'E'){
      columna = 4;
    }
    if (letter_asiento == 'F'){
      columna = 5;
    }

    char number_asiento[2] = {asiento[1],asiento[2]};
    int numero_asiento = atoi(number_asiento);
  
    if (numero_asiento < 33) {
      fila = numero_asiento;
      n = 1;
    } else {
      printf("Seat number does not exist. Try again\n");
    }
    if (n==1){
      if (table[fila][columna]==0){
        table[fila][columna] = 1;
        contador++;
        show();
      } else{
        printf("Seat is taken. Try entering another seat\n"); 
      }
    }
    if (choice == 5){
    clearscreen();

    }
  }
}

void quit (){
  clearscreen();
  exit (-1);
}


int main (void){
    airplane();
    getchar();
    menu();
    scanf("%d", &choice);
      if (choice==1){
        home_reservation();
        getchar();
        reservacion();
      }
      if (choice==2){
        disponibilidad();
      }
      if (choice==3){
        quit();
      }
    
}