#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
}

int main (void){
    int choice = 1;
    scanf("%d", &choice);
    airplane();
    getchar(;
    menu();
}