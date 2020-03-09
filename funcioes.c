//funciones proyecto
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