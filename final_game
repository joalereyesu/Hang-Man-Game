#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//funciones
int regresar = 8;
int opcion;
char name[25];



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

void pagina_inicio () {
  int ingreso;
  clearscreen();
  cyan ();
  printf ("HHHHHH    HHHHHH         AAA          NNNN       NNNN    GGGGGGGGGGGGG\n");
  printf ("HHHHHH    HHHHHH        AAAAA         NNNNN      NNNN    GGGG      GGG\n");
  printf ("HHHHHH    HHHHHH       AAAAAAA        NNNNNN     NNNN    GGGG        \n");
  printf ("HHHHHHHHHHHHHHHH      AAAA AAAA       NNNN NNN   NNNN    GGGG        \n");
  printf ("HHHHHHHHHHHHHHHH     AAAA   AAAA      NNNN  NNN  NNNN    GGGG    GGGGGG  \n");
  printf ("HHHHHH    HHHHHH    AAAAAAAAAAAAA     NNNN   NNN NNNN    GGGG      GGGG  \n");
  printf ("HHHHHH    HHHHHH   AAAAA     AAAAA    NNNN    NNNNNNN    GGGGGGGGGGGGGG    \n");
  printf ("HHHHHH    HHHHHH  AAAAAA     AAAAAA   NNNN      NNNNN    GGGGGGGGGGGGGG\n\n\n");

  printf ("MMMM             MMMM           AAA          NNNN       NNNN  \n ");
  printf ("MMMMM           MMMMM          AAAAA         NNNNN      NNNN   \n");
  printf ("MMMMMM         MMMMMM         AAAAAAA        NNNNNN     NNNN  \n");
  printf ("MMMM MMM     MMM MMMM        AAAA AAAA       NNNN NNN   NNNN   \n");
  printf ("MMMM  MMM   MMM  MMMM       AAAA   AAAA      NNNN  NNN  NNNN   \n");
  printf ("MMMM   MMM MMM   MMMM      AAAAAAAAAAAAA     NNNN   NNN NNNN   \n");
  printf ("MMMM    MMMM     MMMM     AAAAA     AAAAA    NNNN    NNNNNNN   \n");
  printf ("MMMM             MMMM    AAAAAA     AAAAAA   NNNN      NNNNN  \n");
  reset ();
  printf("                  Presione 7 para iniciar:");
  scanf ("%d", &ingreso);
}

void menu (){
  red ();
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n \n");
  reset();
  cyan();
  printf("1. EMPEZAR EL JUEGO! \n");
  printf("2. Ver instrucciones\n");
  printf("3. About \n");
  printf("4. SALIR \n\n");
  reset();
  printf("Ingrese un numero del menu\n");
}

void back (){
  green();
  printf("\nSi quiere regresar a Menu, presione 8\n");
  reset();
  scanf("%d",&regresar);
  clearscreen();
  menu();
}

void username (){
  red();
  printf("Ingrese su nombre o usuario:");
  reset();
  scanf("%s", &name);
  clearscreen();
  cyan();
  printf("HOLA %s! Bienvenido al juego\n", name);
}

void facil (){
  red ();
  printf("NIVEL INTERMEDIO\n\n\n");
  reset ();
  yellow();
  printf ("                     HANG MAN GAME\n\n\n");
  reset();
}

void dificil (){
  red ();
  printf("NIVEL DIFICIL\n\n\n");
  reset ();
  yellow();
  printf ("                     HANG MAN GAME\n\n\n");
  reset();
}

void easy_game (){
  facil ();
  srand (time(NULL));
  char word_collectionEasy[][14] = {
    "navidad","sorpresa", "patatas", "arroz", "corazon"};
  int random_word = rand() % 5;
  int lives = 10; 
  int correct = 0;
  int oldcorrect = 0;
  int quit = 0;
  int length_word = strlen(word_collectionEasy[random_word]);
  int guessedLetter [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int loopwords = 0;
  char guess[14];
  char choice;



  while (correct < length_word){
 
  for (loopwords = 0; loopwords < length_word; loopwords++) {
    if (guessedLetter[loopwords] == 1){
      printf("%c", word_collectionEasy[random_word][loopwords]);
    } else {
      printf(" _");
    }
  }
  printf ("\n\n");
  cyan();
  printf ("Usuario: %s\n", name);
  printf("Aciertos: %d\n", correct);
  printf ("Vidas: %d/10\n", lives);
  printf ("\n");
  reset();
  printf("Ingrese una letra: ");
  printf ("\n");
  fgets(guess, 14, stdin);
  printf("\n");

  if (strncmp(guess, "quit",4)==0){
   quit = 1;
   break;
  }

  choice = guess [0];
  printf ("Palabra ingresada: %c", choice);
  printf ("\n");
  oldcorrect = correct;
  
  for(loopwords = 0; loopwords < length_word; loopwords++){
    if (guessedLetter[loopwords] == 1){
      continue;
    }
    if (choice == word_collectionEasy[random_word][loopwords]){
      guessedLetter[loopwords] = 1;
      correct++;
    }
  }
  
  if (oldcorrect == correct){
    lives--;
    red();
    printf("Letra no es parte de la palabra. Intentalo de nuevo\n");
    reset();
      if (lives==0){
        yellow();
        printf("\nGAME OVER\n");
        break;
      }
  } 
  else {
    cyan();
    printf("ADIVINASTE!\n");
    reset();
  }

}

  if (quit==1){
  clearscreen();
  red();
  printf ("Te has salido del juego\n");
  reset();
  } else if (lives==0){
  clearscreen();
  red();
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~GAME OVER~~~~~~~~~~~~~~~~~~~~~\n");
  reset();
  printf ("Usuario: %s\n", name);
  printf("Aciertos: %d\n", correct);
  printf ("Vidas: %d/10\n", lives);
  printf("Lo sentimos! La palabra era %s", word_collectionEasy[random_word]);
  } else {
  clearscreen();
  cyan();
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~GANASTE!~~~~~~~~~~~~~~~~~~~~~\n");
  reset();
  printf ("Usuario: %s\n", name);
  printf("Aciertos: %d\n", correct);
  printf ("Vidas: %d/10\n", lives);
  }
  }

void hard_game (){
    srand(time(NULL));

  char guess_words[][17]= {"occipucio", "higiene", "pantorrilla", "coronavirus","equitacion"};

  int randomindex = rand() % 5;
  int loopindex = 0;
  int fullrand = 0;
  int numerovidas = 9;
  int numerobuenas = 0;
  int buenasanteriores = 0;
  int contador = 0;
  char fullword;

  int lengthword = strlen(guess_words[randomindex]);




   int letterguessed[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int quit = 0;
  char guess [17];
  char letterentered;


//gameloop
while(numerobuenas < lengthword){


  printf("\n");
  cyan();
  printf ("Usuario: %s\n", name);
  printf("\nAciertos: %d\n", numerobuenas);

  printf("Intentos: %d \n", contador);
  contador = contador + 1;
  reset();
  printf("\npalabra:\n");

  for (loopindex = 0; loopindex < lengthword; loopindex++){
    if(letterguessed[loopindex] == 1){
        printf("%c", guess_words [randomindex][loopindex]);
    } else{
        printf(" _ ");
    }
    
  }

  printf("\n\ningrese letra:\n");
  fgets(guess,17, stdin);

  if (strncmp(guess, "quit", 4) == 0){
    quit = 1;
    break;
  }

  letterentered = guess[0];
  printf("letra ingresada: %c\n",letterentered);

  buenasanteriores = numerobuenas;

for(loopindex = 0; loopindex < lengthword; loopindex++){
  if(letterguessed[loopindex] == 1){
    continue;
  }
  if(letterentered == guess_words[randomindex][loopindex]){
    letterguessed[loopindex] = 1;
  numerobuenas++;
}

} //while loop

if (buenasanteriores == numerobuenas){
  numerovidas--;
  red();
  printf("oops! esta letra no se encuentra en la palabra.\n");
  reset();
  if (numerovidas == 0){
    break;
  }
} else {
  cyan();
  printf("Adivinaste! \n");
}

}

if(quit == 1) {
  red();
  printf("\n ^^^^^^^^^ has salido de la jugada. ^^^^^^^^\n");
  reset();
} else if (numerovidas == 0){
  clearscreen();
  red();
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~GAME OVER~~~~~~~~~~~~~~~~~~~~~\n");
  reset();
  printf ("Usuario: %s\n", name);
  printf("Aciertos: %d\n", numerobuenas);
  printf ("Vidas: %d/10\n", numerovidas);
  printf("Lo sentimos! La palabra era %s", guess_words[randomindex]);
} else {
  clearscreen();
  cyan();
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~GANASTE!~~~~~~~~~~~~~~~~~~~~~\n");
  reset();
  printf ("Usuario: %s\n", name);
  printf("Aciertos: %d\n", numerobuenas);
  printf ("Vidas: %d/10\n", numerovidas);
}
}


void Easy_or_hard (){
  int nivel;
  clearscreen();
  printf("Ingrese 5 si quiere que sea nivel intermedio o ingrese 6 si quiere que sea nivel dificil: ");
  scanf("%d", &nivel);
  if (nivel == 5){
    clearscreen();
    easy_game();
  }
  if (nivel == 6){
    dificil();
    hard_game();
  }
}

void instrucciones () {
  yellow ();
  printf ("\n######################## BIENVENIDO ########################\n \n" );
  reset ();
  cyan ();
  printf ("Bienvenido al juego de Ahorcado. El juego consiste en adivinar la palabra seleccionada aleatoriamente por el ordenador. Usted tendra 10 intentos para adivinar la palabra correspondiente. Si usted pasa de los 10 intentos sera un Game Over. Si la adivina antes de que se acaben sus intenros ganara el juego. En caso quiera salirse del juego escribir quit y darle enter. Espero que le guste. \n SUERTE! \n");
  reset ();
}

void about (){
  red();
  printf ("\n--------------------------- ABOUT ---------------------------\n");
  reset();
  cyan();
  printf("\nHANGMAN o ahorcado es un juego entretenido pues se tiene que adivinar una palabra CUALQUIERA, que cool ¿o no? Como primer proyecto de programacion nos toco crear un juego por medio de programacion en c, y este fue el resultado final. Esperamos que disfruten jugar asi como nosotros nos disfrutamos programandolo\n");
  printf("\nEste juego de HANGMAN fue creado por:\n\n Jose Alejandro Reyes\n correo: alejandroreyes@ufm.edu.gt\n Marcela Melgar\n correo: marcelamelgar@ufm.edu.gt\n ");
  reset();
  
}

void final_game (){
  int opcion;
  clearscreen();
  menu();
  while (1){
  scanf("%d", &opcion);
  if (opcion == 1){
    clearscreen();
    username();
    Easy_or_hard();
    break;
  }
if (opcion == 2){
    clearscreen();
    instrucciones();
    back();
  }
if (opcion == 3){
    clearscreen();
    about();
    back ();
  }
if (opcion == 4){
    salir();
  }
  }
back();
}

//CODIGO
int main (void){
  pagina_inicio();
  while (1){
    final_game();
  }
  return 1;
}