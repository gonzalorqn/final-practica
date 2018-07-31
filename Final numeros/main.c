#include <stdio.h>
#include <stdlib.h>
#include "numero.h"
int main()
{

    int opcion;

    char auxopcion[20];

    ArrayList* listaNueva;
    ArrayList* listaRepetidos;
    ArrayList* listaNorepetidos;
    ArrayList* listaDepurar;

    listaNueva=al_newArrayList();
    listaRepetidos=al_newArrayList();
    listaDepurar=al_newArrayList();
    listaNorepetidos=al_newArrayList();


    do{
        printf("1-Alta archivo\n2-Completar\n3-Listar\n4-Crear archivo \n5-Mostrar Listas\n6-\n7-Salir\n");
        opcion=getValidInt("Ingrese una opcion: ","Error, ingrese un valor numerico",auxopcion);
        switch(opcion)
        {
        case 1:
          parserNumero(listaNueva);
            break;
        case 2:
               isParImpPrimo(listaNueva);
               printf("Indice  Numero       Nombre        Par   Impar  Primo\n");
              mostrarListaNumero(listaNueva);
            break;

        case 3:
            printf("1-Array descendente numeros repetidos\n2-Array ascendente, no repetidos\n");
              opcion=getValidInt("Ingrese una opcion: ","Error, ingrese un valor numerico",auxopcion);


            if(opcion == 1)
            {
               listarRepetidos(listaNueva,listaRepetidos);
                mostrarListaNumero(listaRepetidos);
            }
            else if(opcion==2)
            {
                 listarnoRepetidos(listaNueva,listaDepurar,listaNorepetidos);
                 mostrarListaNumero(listaNorepetidos);
                 printf("\n\n\n");
            }

            break;
        case 4:
            crearArchivos(listaRepetidos,listaNorepetidos);

            break;
        case 5:

            printf("Indice  Numero       Nombre        Par   Impar  Primo\n\n\n");
            printf("\n\n\nLISTA COMUN : \n\n\n");
            mostrarListaNumero(listaNueva);
            printf("\n\n\nIndice  Numero       Nombre        Par   Impar  Primo\n\n\n");
            printf("\n\n\nLISTA REPETIDOS : \n\n\n");
            mostrarListaNumero(listaRepetidos);
            printf("\n\n\nIndice  Numero       Nombre        Par   Impar  Primo\n\n\n");
            printf("\n\n\nLISTA NO REPETIDOS : \n\n\n");
            mostrarListaNumero(listaNorepetidos);



            break;
        case 6:

            break;
        case 7:
            printf("\nPrograma Finalizado\n");
            break;
        default:
            printf("ERROR:Ingrese una de las opciones indicadas!\n");
            break;
        }

        system("pause");
        system("cls");
    }while(opcion!=7);

    return 0;
}


