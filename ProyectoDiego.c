#define Tam 100
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

typedef char TipoDato;
typedef struct Nodo{
    TipoDato nom[30];
    struct Nodo* sig;
          }Nodo;

        typedef struct Lista{
        Nodo pelicula[Tam];
        int cont;
        }Lista;

typedef Nodo peliculas;
        void inicializa(Lista *L){
        int i;
        for(i=0; i<Tam; i++)
        L->pelicula[i].sig=NULL;
        L->cont=-1;
    }
        int vacia(Lista L){
        if(L.cont<0)
        return -1;
     }


void insertapeli(Lista *L, char nombre[30]){
            int i,j;
            char aux[15];
            L->cont++;
            strcpy(L->pelicula[L->cont].nom,nombre);
            for (i=L->cont-1;i>=0;i--){
            strcpy(aux,L->pelicula[i].nom);
            j=i+1;
            while(j>=0&&strcmpi(aux,L->pelicula[i].nom)==1);{
            L->pelicula[j-1]=L->pelicula[j];
            j++;
            }
            strcpy(L->pelicula[j-1].nom,aux);
            }
}

Nodo *buscar( Lista *L, char nombre[30]){
         int i, b=0;
         for(i=0; i<=L->cont;i++)
         if(strcmpi(L->pelicula[i].nom,nombre)==0)
         b=1;
         if(b==0){
         printf ("\nPeliculas no encontradas...\n");
         }
         if(b==1){
         printf("\nLa pelicula - %s  , Se encuentra en %d\n\n",nombre,i);
         }
}

void insertaPeli(Lista *L, char nom[], int pos){
        peliculas *aux, *aux2=L->pelicula[pos].sig;
        aux=(Nodo*)malloc(sizeof(Nodo));
        if(aux==NULL)
        printf("No hay Memoria disponible...");
        else{
        strcpy(aux->nom,nom);
        if(L->pelicula[pos].sig==NULL){
        L->pelicula[pos].sig=aux;
        L->pelicula[pos].sig->sig=NULL;
        }
        else{
          while(aux2->sig!=NULL)
            aux2=aux2->sig;
            aux2->sig=aux;
            aux2->sig->sig=NULL;
        }
    }

}

void mostrarpelicula(Lista *L){
    int i;
    for(i=0; i<=L->cont;i++)
    printf("\n%d  %s",i+1, L->pelicula[i].nom, L->pelicula[i].sig);
}

void imprimirpelicula(Lista *L, int pel)
{
    peliculas *aux= L->pelicula[pel-1].sig;
    int i=1;
    if (aux==NULL)
    {

       printf("\n No se agregaron peliculas\n");
    }
    while(aux!=NULL){
        printf("\n %i - %s   ", i, aux->nom);
        aux=aux->sig;
        i++;
    }
}

void elimpeli(Lista *L, char nombre[], char peli[])
{
     int i, b=0;
     for (i=0; i<=L->cont; i++)
     if(strcmp(L->pelicula[i].nom, nombre)==0){
          b=1;
          L->pelicula[i].sig=NULL;
          printf("\n Pelicula borrada \n");
          system("pause");
      }

          if(b==0){
          printf("\nPelicula no encontrada\n");
              }
}

void eliminartodos(Lista *L)
{
      int i;
      for (i=0; i<=L->cont; i++)
      L->pelicula[i].sig=NULL;
      printf("\n Se han eliminado todas las peliculas!!\n");
      system("pause");
}

void eliminarpelicula(Lista *L, char nombre[]){
    int i,b=0;
    for(i=0;i<=L->cont;i++){
    if (strcmp(L->pelicula[i].nom, nombre)==0){
    L->pelicula[i].sig=NULL;
    b=1;
    while(i<=L->cont){
         L->pelicula[i]=L->pelicula[i+1];
         i++;
    }
    L->cont--;
    printf("\nLa pelicula se ha borrado");
    system("pause");
    }
}
    if(b==0){
    printf("\nPelicula no encontrada...\n");
             }
}

    main(){
    Lista L;
    Nodo p;
    inicializa(&L);
    int opc, opc2, pos;
    char nombre[25];
    do{
    printf("                       ---------Video Centro--------- \n                           Selecciona Una Opcion:  \n\n");
    system ("color a");
    printf("\t\n\n1.-Agregar Pelicula \n\n2.-Eliminar Pelicula \n\n3.-Buscar Pelicula \n\n4.-Mostrar Pelicula\n\n5.-Salir De El Programa\n\n");
    scanf("%i", &opc);
    switch (opc){
         case 1:
            do{
             printf(" \n Agregar \n");
             printf("\n1.-Agregar Pelicula\n2.-Regresar\n\n");
             scanf("%d", &opc2);
             switch(opc2){
                    case 1:
                        printf("\nNombre de la pelicula:  \n");
                        fflush(stdin);
                        gets(nombre);
                        insertapeli(&L, nombre);
                        printf("\n\nLa pelicula a sido agregada...\n");
                        system("pause");
                        break;

                            case 2:
                            break;
                            default:
                                     printf("\nOpcion Incorrecta!!!...\n\n");
                                      system("pause");
                            break;

                }
                }while(opc2!=2);
        break;
        case 2:

             if(vacia(L)==-1){
               printf("\nNo hay Peliculas...\n\n");
               system("pause");
             }
             else{
             char peli[30];
             printf("\n    ---- Menu Eliminar ---- \n");
             printf("\n1.-Eliminar Pelicula\n2.-Eliminar Todas las Peliculas\n\n");
             scanf("%d", &opc2);
             switch(opc2){
                    case 1:
                        printf("\nPelicula...\n");
                            fflush(stdin);
                            gets(nombre);
                            eliminarpelicula(&L,nombre);
                            break;
                                case 2:
                                eliminartodos(&L);
                                break;
                                default:
                                break;
                                    case 3:
                                    printf("Opcion Incorrecta!!\n\n");
                                    system("pause");
                                    break;
                }
                }
break;
             case 3:
             printf(" \n   -----Buscador---- \n");
             printf("Pelicula a Buscar...");
             fflush(stdin);
             gets(nombre);
             *buscar(&L, nombre);
             system("pause");
             break;
             case 4:
             if(vacia(L)==-1){
             printf("\n No hay peliculas!!\n\n");
             system("pause");
             }
             else
             {
             int opc3;
             printf("\n         ----Mostrar Peliculas----\n" );
             mostrarpelicula(&L);
             do{
             printf("\n\nPresiona 2 Para Regresar...");
             scanf("%d", &opc3);
             }while(opc3!=2);
             }
        break;
        case 5:
             printf("Fin de el Programa...\n\n");
             system("pause");
             break;
            default:
                printf("Opcion incorrecta intenta de nuevo!!!\n\n");
                system("pause");
                break;
    }
} while(opc!=5);
getch();
return 0;
}









