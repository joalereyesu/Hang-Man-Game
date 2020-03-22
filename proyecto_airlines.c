//airlines proyecto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROWS 32
#define COLUMNS 6

int getchar (void);
int table [33][6] = {0};
int i, j;
char asiento[3];
int contador=0;
int regresar = 8;
int x;
int columna;
int fila;
int n;
int choice = 5;
int reservados;
int no_reservados;
float rese;
float libre;
int opcion;
char vuelo[5];


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

void flight (){
  clearscreen();
  red();
  printf("\n\n\n\n\n\n\n\n\n\n                      FLIGHTS AVAILABLE\n");
  reset();
  green();
  printf("                     AE413, AI505, AT312\n");
  reset();
  printf("                     Enter flight number: ");
  scanf("%s", vuelo);
  getchar();
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
    green();
    printf("               You are booking flight %s\n", vuelo);
    reset();
    printf("                   Press enter to start");
}


void menu (){
    clearscreen();
    green();
    printf("                                         Flight: %s\n\n",vuelo);
    reset();
    red();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
    reset();
    cyan();
    printf("1. Make a reservation \n");
    printf("2. See seat availability\n");
    printf("3. Summary of reservations\n");
    printf("4. Exit \n");
    reset();
    printf("Enter a number of the menu\n");
}

void back(){
  cyan();
  printf("\nIf you want to go back to menu press number 8\n");
  reset();
  scanf("%d",&regresar);
  clearscreen();
  menu();
}

void disponibilidad (){
  while(getchar()!= '\n')
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
  red();
  printf("Seats already taken are shown with a 1\nSeats that are available for reservation are shown with a 0\n");
  reset();
}

void taken(){
  clearscreen();
  red();
  printf("Seat is taken. Try entering another seat\n");
  reset();
  printf("Press enter to continue");
  getchar();
}

void noseat(){
  clearscreen();
  red();
  printf("Seat number does not exist. Try again\n");
  reset();
  printf("Press enter to continue");
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
    printf("In here you can book as many seats as you want. When you are done booking your seats type the word 'menu' to finish and go back to menu.\n\nPress enter to continue"); 
}

void reserved (){
  clearscreen();
  green();
  printf("Seat %s has been booked succesfully\n\n",asiento);
  reset();
  printf("Press enter to continue booking");
  getchar();
}

void reservacion (){
  while(getchar () != '\n');
  while (1){
    show();
    red();
    printf("Seats already taken are shown with a 1\nSeats that are available for reservation are shown with a 0\n\n");
    reset();
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
    if (letter_asiento == 'm'){
      menu();
      break;
    }

    char number_asiento[2] = {asiento[1],asiento[2]};
    int numero_asiento = atoi(number_asiento);
    if (numero_asiento < 33) {
      fila = numero_asiento;
      n = 1;
    } else {
      noseat();
      getchar();
    }
    if (n==1){
      if (table[fila][columna]==0){
        table[fila][columna] = 1;
        contador++;
        reserved();
        getchar();
      } else{
        taken();
        getchar(); 
      }
    }
  }
  }

void resumen(){
  while(getchar ()!= '\n')
   clearscreen();
   cyan();
   printf("~~~~~~~~~~ RESUMEN ~~~~~~~~~\n");
   yellow();
    printf("The summary of the seats that have been booked is shown below:\n");
    green();
    printf("Seats reserved: %d/192\t", contador);
    rese = (float)contador/192 * 100;
    printf("[%.2f percent]\n", rese);
    no_reservados = 192 - contador;
    printf("Emptie seats: %d/192\t",no_reservados);
    libre = (float)no_reservados/192 * 100;
    printf("[%.2f percent]\n",libre);
    reset();
    back ();
}

void quit (){
  clearscreen();
  exit (-1);
}


int main (void){
    flight();
    airplane();
    getchar();
    menu();
    while(1){
    scanf("%d", &choice);
      if (choice==1){
        home_reservation();
        getchar();
        reservacion();
      }
      if (choice==2){
        clearscreen();
        disponibilidad();
        back();
      }
      if (choice ==3){
        clearscreen();
        resumen();
      }
      if (choice==4){
        quit();
      }
    }
}