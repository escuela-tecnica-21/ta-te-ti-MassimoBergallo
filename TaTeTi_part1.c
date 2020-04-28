#include <stdio.h>
#include <stdlib.h>
char Matriz[3][3][2],aux[15];
int x,y,Fin=0,empatar=0,lugar=0,auxn=0;
int main()
{
    char Respuesta[15];
    srand(time(NULL));
    int fila=0,bot=0;
        while(1)//while principal
    {
        system("cls");
        llenar();


       while(1)
    {
       mostrarMatriz();

   while(1)//while del jugador
   {
       printf("Ingrese donde desea colocar las X\n");
       //for (x=0;x<2;x++)//funcion a futuro el bot va a responder a esto todavia falta colocar la funcion de la ia
       //{
       do{
       scanf("%s",&aux);
       convertir(aux);

       }while(validarlugar(lugar));//verifica que el valor ingresado no este ocupado
                if (lugar>=4 && lugar<7)//pone el valor donde corresponde en la matriz
            {
                strcpy(Matriz[1][lugar-4],"X");
                                                    }
                if (lugar>=7)
            {
                strcpy(Matriz[2][lugar-7],"X");
                                                    }
                    if(lugar<4)
            {
                    strcpy(Matriz[0][lugar-1],"X");
                                                    }
        //}
       empate();//si hay un empate termina el partido
       system("cls");
       mostrarMatriz();
       GanoX();//si el jugador gano termina el partido
        break;
    }//cierre del jugador
    if(Fin==1)
    {
        break;
    }

    while(1)//while del bot
    {

        do
        {
            bot=rand()% (9-1+1)+1;//el vot crea un numero
            convertirBot(bot);//este numero se compara y se crea una nueva variable char
       convertir(aux);// transforma la variable char en otra int
        }while(validarlugar(lugar));//verifica que el valor dado no este ocupado

                if (lugar>=4 && lugar<7)//coloca el valor en el lugar correspondiente en la matriz
        {
            strcpy(Matriz[1][lugar-4],"O");
                                                }
                    if  (lugar>=7)
       {
           strcpy(Matriz[2][lugar-7],"O");
                                                }
                    if(lugar<4)

       {
           strcpy(Matriz[0][lugar-1],"O");
                                                }

       empate();
       system("cls");
       mostrarMatriz();
       GanoO();
       break;


    }//cierre del Bot

    if(Fin==1)
    {
        break;
    }
    }//cierre total
    }//cierre while principal


}//cierra int
int llenar()//funcion llenado de la matriz
{

    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            strcpy(Matriz[x][y]," ");
        }
    }
}
int mostrarMatriz()//funcion para mostrar la matriz
{   system("cls");
    if (strcmp(Matriz[0][0],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
        printf("  %s",Matriz[0][0]);
        textcolor(7);
        printf("   %c",179);
        if (strcmp(Matriz[0][1],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
    printf("   %s",Matriz[0][1]);
    textcolor(7);
    printf("   %c",179);
    if (strcmp(Matriz[0][2],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
    printf("   %s\n",Matriz[0][2]);
    textcolor(7);

   printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
   if (strcmp(Matriz[1][0],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
        printf("  %s",Matriz[1][0]);
        textcolor(7);
        printf("   %c",179);
        if (strcmp(Matriz[1][1],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
    printf("   %s",Matriz[1][1]);
    textcolor(7);
    printf("   %c",179);
    if (strcmp(Matriz[1][2],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
    printf("   %s\n",Matriz[1][2]);
    textcolor(7);
   printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
   if (strcmp(Matriz[2][0],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
        printf("  %s",Matriz[2][0]);
        textcolor(7);
        printf("   %c",179);
        if (strcmp(Matriz[2][1],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
    printf("   %s",Matriz[2][1]);
    textcolor(7);
    printf("   %c",179);
    if (strcmp(Matriz[2][2],"X")==0)
    {
        textcolor(1);
    }
    else
    {
        textcolor(4);
    }
    printf("   %s\n",Matriz[2][2]);
    textcolor(7);
}
int convertir(aux2)//funcion convertir el valor char en otra nueva variable como int
{
    if(strcmp(aux2,"1")==0)
    {
        lugar=1;
        return 0;
    }
    if(strcmp(aux2,"2")==0)
    {
        lugar=2;
        return 0;
    }
    if(strcmp(aux2,"3")==0)
    {
        lugar=3;
        return 0;
    }
    if(strcmp(aux2,"4")==0)
    {
        lugar=4;
        return 0;
    }
    if(strcmp(aux2,"5")==0)
    {
        lugar=5;
        return 0;
    }
    if(strcmp(aux2,"6")==0)
    {
        lugar=6;
        return 0;
    }
    if(strcmp(aux2,"7")==0)
    {
        lugar=7;
        return 0;
    }
    if(strcmp(aux2,"8")==0)
    {
        lugar=8;
        return 0;
    }
    if(strcmp(aux2,"9")==0)
    {
        lugar=9
        ;
        return 0;
    }

    return 1;
}
int validarlugar(int lugar2)//funcion validar que el lugar no este ocupado
{
    int fila=0;
    lugar2=lugar2-1;
        if(lugar2<=2 && lugar2>=0)
       {
           lugar2=lugar2;fila=0;
       }
       if (lugar2>=3 && lugar2<6)
       {
           lugar2=lugar2-3;fila=1;
       }
       if  (lugar2>=6 && lugar2<=8)
       {
           lugar2=lugar2-6;fila=2;
       }
       if(lugar2<0 || lugar2>=9)
       {
           printf("El lugar ingresado esta fuera de los terminos,vuelva a intentarlo\n");
           return 1;

       }
       if(strcmp(Matriz[fila][lugar2],"X")==0 || strcmp(Matriz[fila][lugar2],"O")==0)
       {
           printf("Este lugar ha sido ocupado\n");
           return 1;
       }
       return 0;
}

int GanoX()//funcion de victoria del jugador
{
    if(strcmp(Matriz[0][0],Matriz[0][1])==0 && strcmp(Matriz[0][1],Matriz[0][2])==0)
          {
              if(strcmp(Matriz[0][0],"X")==0 && strcmp(Matriz[0][1],"X")==0 && strcmp(Matriz[0][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[1][0],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[1][2])==0)
          {
              if(strcmp(Matriz[1][0],"X")==0 && strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[1][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[2][0],Matriz[2][1])==0 && strcmp(Matriz[2][1],Matriz[2][2])==0)
          {
              if(strcmp(Matriz[2][0],"X")==0 && strcmp(Matriz[2][1],"X")==0 && strcmp(Matriz[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][0],Matriz[1][0])==0 && strcmp(Matriz[1][0],Matriz[2][0])==0)
          {
              if(strcmp(Matriz[0][0],"X")==0 && strcmp(Matriz[1][0],"X")==0 && strcmp(Matriz[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;
              }
          }
          if(strcmp(Matriz[0][1],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][1])==0)
          {
              if(strcmp(Matriz[0][1],"X")==0 && strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[2][1],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][2],Matriz[1][2])==0 && strcmp(Matriz[1][2],Matriz[2][2])==0)
          {
              if(strcmp(Matriz[0][2],"X")==0 && strcmp(Matriz[1][2],"X")==0 && strcmp(Matriz[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][0],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][2])==0)
          {
              if(strcmp(Matriz[0][0],"X")==0 && strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][2],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][0])==0)
          {
              if(strcmp(Matriz[0][2],"X")==0 && strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Jugador Wins\n");
                  Fin=1;

              }
          }
          return 0;
}

int GanoO()//funcion de victoria del bot
{
    if(strcmp(Matriz[0][0],Matriz[0][1])==0 && strcmp(Matriz[0][1],Matriz[0][2])==0)
          {
              if(strcmp(Matriz[0][0],"O")==0 && strcmp(Matriz[0][1],"O")==0 && strcmp(Matriz[0][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[1][0],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[1][2])==0)
          {
              if(strcmp(Matriz[1][0],"O")==0 && strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[1][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[2][0],Matriz[2][1])==0 && strcmp(Matriz[2][1],Matriz[2][2])==0)
          {
              if(strcmp(Matriz[2][0],"O")==0 && strcmp(Matriz[2][1],"O")==0 && strcmp(Matriz[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][0],Matriz[1][0])==0 && strcmp(Matriz[1][0],Matriz[2][0])==0)
          {
              if(strcmp(Matriz[0][0],"O")==0 && strcmp(Matriz[1][0],"O")==0 && strcmp(Matriz[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][1],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][1])==0)
          {
              if(strcmp(Matriz[0][1],"O")==0 && strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[2][1],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][2],Matriz[1][2])==0 && strcmp(Matriz[1][2],Matriz[2][2])==0)
          {
              if(strcmp(Matriz[0][2],"O")==0 && strcmp(Matriz[1][2],"O")==0 && strcmp(Matriz[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][0],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][2])==0)
          {
              if(strcmp(Matriz[0][0],"O")==0 && strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          if(strcmp(Matriz[0][2],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][0])==0)
          {
              if(strcmp(Matriz[0][2],"O")==0 && strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Bot Wins\n");
                  Fin=1;

              }
          }
          return 0;
}

int empate()//funcion que verifica que el partido termino en empate
{
    int x,y;
    empatar=0;
       for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            if(strcmp(Matriz[x][y],"X")==0 || strcmp(Matriz[x][y],"O")==0)
            {
                empatar=empatar+1;
            }
        }
    }
    if(empatar==9)
    {
        empatar=1;
    }
    return 0;
}

int convertirBot(int aux2)//transforma el numero que dio el bot y la tranforma de char a otra variable
{
    int x=0;
    if (aux2==1)
    {
        strcpy(aux,"1");
    }
    if (aux2==1)
    {
        strcpy(aux,"2");
    }
    if (aux2==3)
    {
        strcpy(aux,"3");
    }
    if (aux2==4)
    {
        strcpy(aux,"4");
    }
    if (aux2==5)
    {
        strcpy(aux,"5");
    }
    if (aux2==6)
    {
        strcpy(aux,"6");
    }
    if (aux2==7)
    {
        strcpy(aux,"7");
    }
    if (aux2==8)
    {
        strcpy(aux,"8");
    }
    if (aux2==9)
    {
        strcpy(aux,"9");
    }
}
