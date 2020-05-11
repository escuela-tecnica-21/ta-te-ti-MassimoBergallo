#include <stdio.h>
#include <stdlib.h>
char Matriz[3][3][2],aux[15];
int Fin=0;
int main()
{
    srand(time(NULL));
    Llenar_Matriz();
    Mostrar_Matriz();
    Bot_IA();
    Modo_Creativo();
    Victorias();
    Empate();

}
void Modo_Creativo()//funcion para ingresar un tablero inicial para que la maquina responda a el
{
    int lugar=0;
    while(1)
    {
        do
        {

            printf("Ingrese el numero en donde desea colocar la X\n");
            scanf("%d",&lugar);

        }while(Validar_Lugar(lugar))
        {
        Convertir_En_X(lugar);
        Mostrar_Matriz();
        }
    }
    Mostrar_Matriz();
    while(1)
    {
        do
        {

            printf("Ingrese el numero en donde desea colocar la O\n");
            scanf("%d",&lugar);

        }while(Validar_Lugar(aux))
        {
        Convertir_En_O(lugar);
        Mostrar_Matriz();
        }
    }
}
void Llenar_Matriz() //funcion que vacia los espacios que hay en la matriz
{
    int x,y;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            strcpy(Matriz[x][y]," ");//Cada casilla de la matriz se llena en blanco
        }
    }
}
void Mostrar_Matriz()//funcion mostrar la matriz
{
    system("cls");
    printf("  %s   %c   %s   %c   %s \n",Matriz[0][0],179,Matriz[0][1],179,Matriz[0][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Matriz[1][0],179,Matriz[1][1],179,Matriz[1][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s \n",Matriz[2][0],179,Matriz[2][1],179,Matriz[2][2]);
}
int Validar_Lugar(int lugar2)//funcion validar que el lugar no este ocupado
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
           printf("Este lugar ha sido ocupado anteriormente\n");
           return 1;
       }
       return 0;
}
void Convertir_En_X(int lugar)//coloca el numero ingresado por el usuario en el lugar correcto
{
            if(lugar<4)
            {strcpy(Matriz[0][lugar-1],"X");}
            if(lugar>=4 && lugar<7)
            {strcpy(Matriz[1][lugar-4],"X");}
            if(lugar>=7)
            {strcpy(Matriz[2][lugar-7],"X");}

}
void Convertir_En_O(lugar)//coloca el numero ingresado por el Bot en el lugar correcto
{
            if(lugar<4)//pone el valor donde corresponde en la matriz
            {strcpy(Matriz[0][lugar-1],"O");}
            if (lugar>=4 && lugar<7)
            {strcpy(Matriz[1][lugar-4],"O");}
            if  (lugar>=7)
            {strcpy(Matriz[2][lugar-7],"O");}
}
int Victorias()//Esta funcion verifica quien gano
{
int x=0;
for(x=0;x<3;x++)
    {
        if(strcmp(Matriz[x][0],Matriz[x][1])==0 && strcmp(Matriz[x][1],Matriz[x][2])==0)
          {
              if(strcmp(Matriz[x][0],"X")==0 && strcmp(Matriz[x][1],"X")==0 && strcmp(Matriz[x][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el Jugador\n");
                  Fin=1;
                  return 0;
              }
              if(strcmp(Matriz[x][0],"O")==0 && strcmp(Matriz[x][1],"O")==0 && strcmp(Matriz[x][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el BOT\n");
                  Fin=1;
                  return 0;
              }
          }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(Matriz[0][x],Matriz[1][x])==0 && strcmp(Matriz[1][x],Matriz[2][x])==0)//columnas
          {
              if(strcmp(Matriz[0][x],"X")==0 && strcmp(Matriz[1][x],"X")==0 && strcmp(Matriz[2][x],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el Jugador\n");
                  Fin=1;
                  return 0;
              }if(strcmp(Matriz[0][x],"O")==0 && strcmp(Matriz[1][x],"O")==0 && strcmp(Matriz[2][x],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el BOT\n");
                  Fin=1;
                  return 0;
              }
        }
    }
          if(strcmp(Matriz[0][0],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][2])==0)//diagonal
          {
              if(strcmp(Matriz[0][0],"X")==0 && strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el BOT\n");
                  Fin=1;
                  return 0;
              }
              if(strcmp(Matriz[0][0],"O")==0 && strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el BOT\n");
                  Fin=1;
                  return 0;
              }
          }
          if(strcmp(Matriz[0][2],Matriz[1][1])==0 && strcmp(Matriz[1][1],Matriz[2][0])==0)//diagonal
          {
              if(strcmp(Matriz[0][2],"X")==0 && strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Gano Jugador\n");
                  Fin=1;
                  return 0;
              }
              if(strcmp(Matriz[0][2],"O")==0 && strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Gano el BOT\n");
                  Fin=1;
                  return 0;;
              }
          }
          Fin=0;
          return 0;
}
int Empate(Fin)//funcion que verifica si el juego termino en empate
{
    int x,cempate=0,y;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            if(strcmp(Matriz[x][y],"X")==0 || strcmp(Matriz[x][y],"O")==0)
            {
                cempate=cempate+1;
            }
        }
    }
    if(cempate==9)
    {
        Fin=1;
        return ;
    }
    return 0;
}
void Bot_IA()//funciones del bot
{
    Atacar_Jugador();                         //si puede ganar que gane
    Defender_del_Jugador();                   //si no puede ganar que defienda
    Movimiento_Random();       //si no puede defender ni atacar posiciona aleatorio

}
void Movimiento_Random()//si el bot no puede atacar o defender se movera con un numero aleatorio
{
    int bot=0;
    do
        {
            bot=rand()%(9-1+1)+1;//se crea un numero aleatorio
        }while(validarlugar(bot));//verifica que el valor dado no este ocupado
        ConvertirO(bot);
}
int Atacar_Jugador() //el bot lee si puede ganar en cada movimiento del jugador
{
    int x;
    {//Ganar en filas
            for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[x][0],"O")==0 && strcmp(Matriz[x][1],"O")==0)
                {
                    if(strcmp(Matriz[x][2]," ")==0)
                    {
                        strcpy(Matriz[x][2],"O");
                        return 0;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[x][0],"O")==0 && strcmp(Matriz[x][2],"O")==0)
                {
                    if(strcmp(Matriz[x][1]," ")==0)
                    {
                        strcpy(Matriz[x][1],"O");
                        return 0;
                    }
                }
            }

           for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[x][1],"O")==0 && strcmp(Matriz[x][2],"O")==0)
                {
                    if(strcmp(Matriz[x][0]," ")==0)
                    {
                        strcpy(Matriz[x][0],"O");
                        return 0;
                    }
                }
            }

    }
    {//Ganar en columnas
            for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[0][x],"O")==0 && strcmp(Matriz[1][x],"O")==0)
                {
                    if(strcmp(Matriz[2][x]," ")==0)
                    {
                        strcpy(Matriz[2][x],"O");
                        return 0;
                    }
                }
            }
           for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[1][x],"O")==0 && strcmp(Matriz[2][x],"O")==0)
                {
                    if(strcmp(Matriz[0][x]," ")==0)
                    {
                        strcpy(Matriz[0][x],"O");
                        return 0;
                    }
                }
            }
          for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[0][x],"O")==0 && strcmp(Matriz[2][x],"O")==0)
                {
                    if(strcmp(Matriz[1][x]," ")==0)
                    {
                        strcpy(Matriz[1][x],"O");
                        return 0;
                    }
                }
            }
    }
    {//Ganar en diagonales

            if(strcmp(Matriz[0][0],"O")==0 && strcmp(Matriz[1][1],"O")==0)
            {
                if(strcmp(Matriz[2][2]," ")==0)
                {
                    strcpy(Matriz[2][2],"O");
                    return 0;
                }
            }

            if(strcmp(Matriz[1][1],"O")==0 && strcmp(Matriz[2][2],"O")==0)
            {
                if(strcmp(Matriz[0][0]," ")==0)
                {
                    strcpy(Matriz[0][0],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[0][0],"O")==0 && strcmp(Matriz[2][2],"O")==0)
            {
                if(strcmp(Matriz[1][1]," ")==0)
                {
                    strcpy(Matriz[1][1],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[0][2],"O")==0 && strcmp(Matriz[1][1],"O")==0)
            {
                if(strcmp(Matriz[2][0]," ")==0)
                {
                    strcpy(Matriz[2][0],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[2][0],"O")==0 && strcmp(Matriz[1][1],"O")==0)
            {
                if(strcmp(Matriz[0][2]," ")==0)
                {
                    strcpy(Matriz[0][2],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[2][0],"O")==0 && strcmp(Matriz[0][2],"O")==0)
            {
                if(strcmp(Matriz[1][1]," ")==0)
                {
                    strcpy(Matriz[1][1],"O");
                    return 0;
                }
            }
    }
}
int Defender_del_Jugador()//evita que el jugador gane
{
   int x;
    {// que no gane en las filas
            for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[x][0],"X")==0 && strcmp(Matriz[x][1],"X")==0)
                {
                    if(strcmp(Matriz[x][2]," ")==0)
                    {
                        strcpy(Matriz[x][2],"O");
                        return 0;
                    }
                }
            }
            for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[x][0],"X")==0 && strcmp(Matriz[x][2],"X")==0)
                {
                    if(strcmp(Matriz[x][1]," ")==0)
                    {
                        strcpy(Matriz[x][1],"O");
                        return 0;
                    }
                }
            }
           for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[x][1],"X")==0 && strcmp(Matriz[x][2],"X")==0)
                {
                    if(strcmp(Matriz[x][0]," ")==0)
                    {
                        strcpy(Matriz[x][0],"O");
                        return 0;
                    }
                }
            }
    }
    {//Que no gane en las columnas
            for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[0][x],"X")==0 && strcmp(Matriz[1][x],"X")==0)
                {
                    if(strcmp(Matriz[2][x]," ")==0)
                    {
                        strcpy(Matriz[2][x],"O");
                        return 0;
                    }
                }
            }
           for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[1][x],"X")==0 && strcmp(Matriz[2][x],"X")==0)
                {
                    if(strcmp(Matriz[0][x]," ")==0)
                    {
                        strcpy(Matriz[0][x],"O");
                        return 0;
                    }
                }
            }
          for(x=0;x<3;x++)
            {
                if(strcmp(Matriz[0][x],"X")==0 && strcmp(Matriz[2][x],"X")==0)
                {
                    if(strcmp(Matriz[1][x]," ")==0)
                    {
                        strcpy(Matriz[1][x],"O");
                        return 0;
                    }
                }
            }

    }
    {//que no gane en las diagonales
            if(strcmp(Matriz[0][0],"X")==0 && strcmp(Matriz[1][1],"X")==0)
            {
                if(strcmp(Matriz[2][2]," ")==0)
                {
                    strcpy(Matriz[2][2],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[1][1],"X")==0 && strcmp(Matriz[2][2],"X")==0)
            {
                if(strcmp(Matriz[0][0]," ")==0)
                {
                    strcpy(Matriz[0][0],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[0][0],"X")==0 && strcmp(Matriz[2][2],"X")==0)
            {
                if(strcmp(Matriz[1][1]," ")==0)
                {
                    strcpy(Matriz[1][1],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[0][2],"X")==0 && strcmp(Matriz[1][1],"X")==0)
            {
                if(strcmp(Matriz[2][0]," ")==0)
                {
                    strcpy(Matriz[2][0],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[2][0],"X")==0 && strcmp(Matriz[1][1],"X")==0)
            {
                if(strcmp(Matriz[0][2]," ")==0)
                {
                    strcpy(Matriz[0][2],"O");
                    return 0;
                }
            }
            if(strcmp(Matriz[2][0],"X")==0 && strcmp(Matriz[0][2],"X")==0)
            {
                if(strcmp(Matriz[1][1]," ")==0)
                {
                    strcpy(Matriz[1][1],"O");
                    return 0;
                }
            }
    }
}
