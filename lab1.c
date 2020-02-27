//ROCK PAPER SCISSORS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main () {
  while(1){
  int R=1;
  int P=2;
  int S=3;
  int jugador;
  printf("Hoy jugaremos Piedra, Papel o Tijera! Elige 1 para piedra, 2 para papel y 3 para tijera\n");


  printf("Elija opcion\n");
  scanf("%d", &jugador);
  int computadora=rand()%3+1;
   if (jugador==1){
     if (computadora==1){
       printf("Empate\n");
     }
     if (computadora==2){
       printf("Computadora gana\n");
     }
     if(computadora==3){
       printf("Ganaste!\n");
     }
   }
    else if (jugador==2){
      if (computadora==2){
        printf("Empate\n");
      }
      if (computadora==3){
        printf("Computadora gana\n");
      }
      if (computadora==1){
        printf("Ganaste!\n");
      }
    }
    else if (jugador==3){
      if (computadora==3){
        printf("Empate\n");
      }
      if (computadora==1){
        printf("Ganaste!\n");
      }
      if(computadora==2){
        printf("Computadora gana\n");
      }
    }
}
return 0;
}

//VUELTO
#include <stdio.h>
#include <stdlib.h>

float precio;
float pago;
float cambio;
int centavos;
int b;

int main (void){

  printf ("Ingrese el precio del producto \n");
  scanf ("%f", &precio);
  printf("Ingrese el pago entregado por el cliente \n");
  scanf("%f", &pago);
  cambio = (pago - precio);
  int centavos = cambio * 100;
  int a = cambio/25;
  if (cambio == (a*25)) {
    printf("%d de 25 centavos\n", a);
  }
  else {
    int v = centavos - (a*25);
    b = v/10;
    if (v == (b*10)){
      printf("%d de 25 centavos y %d de 10 centavos \n", a, b);
    }
  else {
    int d = v - (b*10);
    int c = d/5;
    if (d == (c*5)) {
      printf("%d de 25 centavos, %d de 10 centavos y %d de 5 centavos\n", a, b, c);
    }
    else {
      int u = d - (c*1);
      int d = u/1;
      printf("%d de 25 centavos, %d de 10 centavos, %d de 5 centavos y %d de un centavo \n", a, b, c, d);
    }
  }
  }
 return 0;
}

//ASCII TRIANGLE
#include <stdio.h>
#include <stdlib.h>

int numero_usuario;

int main (){
  printf ("Ingrese cualquier numero mayor a 0 para generar un triangulo rectangulo de base y altura de 5\n");
  if (numero_usuario <= 0) {
    scanf("%d", &numero_usuario);
      printf("*\n");
      printf("**\n");
      printf("***\n");
      printf("****\n");
      printf("*****\n");
  }
return 0;
}

//RANDOM NUMBER
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int numero_compu = (rand()%100) + 1;
  int numero_user;
  int contador = 1;
  printf("Bienvenido. Este juego consiste en adivinar un numero entre 1 al 100. Suerte!\n");
  while(1){
    printf("Ingrese su numero\n");
    scanf("%d",&numero_user);
    if(numero_compu==numero_user){
      printf("Adivinaste!\n");
      break;
    } 
    else if (numero_compu > numero_user){
      printf("Intentalo de nuevo. Piensa en un numero mayor\n");
      contador=contador + 1;
    }
    else if (numero_compu < numero_user){
      printf("Intentalo de nuevo. Piensa en un numero menor\n");
      contador=contador +1;
    }
  }
printf ("Intentaste %d veces\n", contador);
  return 0;
}


//TABLA MULTIPLICAR
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int numero_tabla;
  int respuesta;
  printf("Ingrese un numero del 1 al 9 para mostrar su respectiva tabla de multiplicar \n");
  scanf ("%d", &numero_tabla);
  for (int i=1; i<10; i++){
    respuesta = numero_tabla * i;
    printf("%d * %d = %d \n", numero_tabla, i,respuesta);
  }
return 0;
}


//BINARIO
#include <stdio.h>
#include <stdlib.h>

int numero10;
int contador;
int k;

int main (void){
  printf ("Ingrese el numero que desee en decimal para convertirlo en binrio \n");
  scanf ("%d", &numero10);
  printf("\n");
  printf("Su numero %d en binario es: \n", numero10);
  for (contador=31; contador >= 0; contador--){
    //bitwise
    k = numero10 >> contador;
    if (k & 1){
      printf("1");
    }
    else
    printf("0");
  }
  return 0;
}
