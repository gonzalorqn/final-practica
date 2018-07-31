
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "numero.h"

eNumero* numero_new()
{
    eNumero* retorno;
    retorno=(eNumero*)malloc(sizeof(eNumero));
    return retorno;
}

int setNumero(eNumero* this,int numero)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->numero=numero;
        retorno=1;
    }
    return retorno;
}

int setNombre(eNumero* this,char* nombre)
{
    int retorno =0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}

int setPar(eNumero* this,int par)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->par=par;
        retorno=1;
    }
    return retorno;
}
int setImpar(eNumero* this,int impar)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->impar=impar;
        retorno=1;
    }
    return retorno;
}

int setPrimo(eNumero* this,int primo)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->primo=primo;
        retorno=1;
    }
    return retorno;
}

int setIndice(eNumero* this,int indice)
{
    int retorno=0;
    if(this!=NULL)
    {
        this->indice=indice;
        retorno=1;
    }
    return retorno;
}


int getNumero(eNumero* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        retorno=this->numero;
    }
    return retorno;
}
char* getNombre(eNumero* this)
{
    char* retorno=NULL;
    if(this!=NULL)
    {
        retorno=this->nombre;
    }
    return retorno;
}
int getPar(eNumero* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        retorno=this->par;
    }
    return retorno;
}

int getImpar(eNumero* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        retorno=this->impar;
    }
    return retorno;
}
int getPrimo(eNumero* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        retorno=this->primo;
    }
    return retorno;
}

int getIndice(eNumero* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        retorno=this->indice;
    }
    return retorno;
}




int mostrarNumero(eNumero* this)
{

    int retorno=0;
    if(this!=NULL)
    {
       //  printf("%3d %6d   %19s %5d %5d %5d\n",getIndice(this),getNumero(this),getNombre(this),getPar(this),getImpar(this),getPrimo(this));
        printf("%3d%10d%20s%5d%5d%8d\n",getIndice(this),getNumero(this),getNombre(this),getPar(this),getImpar(this),getPrimo(this));
    }
    return retorno;
}
int mostrarListaNumero(ArrayList* this)
{
    int retorno=0;
    int len;
    int i;
    eNumero* numero;

    if(this!=NULL)
    {
        len=this->len(this);

        for(i=0;i<len;i++)
        {
            numero=(eNumero*)this->get(this,i);
            mostrarNumero(numero);
           // contador++;
            //if(contador==10)
           // {
             //   system("pause");
           // }
        }
        retorno=1;
    }
    return retorno;
}

int mostrarListaNumero100(ArrayList* this)
{
    int retorno=0;
    int len;
    int i;

    eNumero* numero;

    if(this!=NULL)
    {
        len=this->len(this);

        for(i=0;i<len;i++)
        {
            numero=(eNumero*)this->get(this,i);
            if(numero->numero==100)
            {
                 mostrarNumero(numero);
            }
        }
        retorno=1;
    }
    return retorno;
}









void getString(char* mensaje,char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esNumerico(char* dato)
{
    int tam;
    int retorno=0;
    int i=0;
    tam=strlen(dato);
    for(i=0;i<tam;i++)
   {

    if(*(dato+i)>=0&&(isdigit(*(dato+i))!=0))
    {
        retorno=1;
    }
    else{
        retorno=0;
        break;
    }
   }
   return retorno;
}

int esSoloLetras(char* dato)
{
    int tam;
    int retorno=0;
    int i=0;
    tam=strlen(dato);
    for(i=0;i<tam;i++)
   {

    if((isalpha(*(dato+i))!=0))
    {
        retorno=1;
    }
    else{
        retorno=0;
        break;
    }
   }
   return retorno;
}


int getValidInt(char* mensaje,char* mensajeError,char* input)
{
    int retorno=-1;

    char AUX[100];

    getString(mensaje,AUX);
    while(retorno==-1)
    {
    if(esNumerico(AUX))
    {

        strcpy(input,AUX);

        retorno=atoi(input);
        break;
    }
    else{
       getString(mensajeError,AUX);

      }
    }

    return retorno;
}

char* getValidChar(char* mensaje,char* mensajeError,char* input)
{

    char AUX[100];
    int flag=-1;

    getString(mensaje,AUX);
    while(flag==-1)
    {
        if(esSoloLetras(AUX))
        {
            strcpy(input,AUX);
            flag=0;
            break;
        }
        else{
            getString(mensajeError,AUX);

            }
    }

    return input;
}




int parserNumero( ArrayList* pArrayList)
{

FILE* pFile;
int r;
int auxNumero;
int auxPar;
int auxImpar;
int auxPrimo;
int i=0;


char numeroo[50],nombre[50],par[50],impar[50],primo[50];
eNumero* numero;


  pFile=fopen("datos.csv","r");

    if(pFile==NULL)
    {
        printf("Archivo vacio!!");
        return -1;
    }
    do{

        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numeroo,nombre,par,impar,primo);
        if(r==5)
        {
              numero=numero_new();
              if(numero!=NULL)
              {
               i++;
               setIndice(numero,i);
               auxNumero=atoi(numeroo);
               setNumero(numero,auxNumero);

               setNombre(numero,nombre);

               auxPar=atoi(par);
               setPar(numero,auxPar);

               auxImpar=atoi(impar);
               setImpar(numero,auxImpar);

               auxPrimo=atoi(primo);
               setPrimo(numero,auxPrimo);
               pArrayList->add(pArrayList,numero) ;


              }
        }
    }while(!feof(pFile));

    printf("Archivo cargado!!\n");

    fclose(pFile);
    return 0;
}


int  isParImpPrimo(ArrayList* this)
{
    int i;
    int j=0;
    int len;
    int a=0;
    int primo;
    int retorno=0;

    eNumero* numero;

    if(this!=NULL)
    {
      len=this->len(this);
      for(i=0;i<len;i++)
      {
         numero=(eNumero*) this->get(this,i);
         if(numero->numero%2==0)
         {
            setPar(numero,1);
            setImpar(numero,0);
         }
         else
         {
             setImpar(numero,1);
             setPar(numero,0);
         }
          primo=getNumero(numero);
         for(j=1;j<=primo;j++)
         {
          if(primo%j==0)
          {
              a++;
          }
          }

          if(a==2)
           {
             setPrimo(numero,1);

           }
           else
           {
               setPrimo(numero,0);
           }
           a=0;

      }
     retorno=1;
    }
    return retorno;
}


 int ordenarNumero(void* num1 ,void* num2)
 {
    int retorno;
    eNumero* uno;
    eNumero* dos;

    uno=(eNumero*)num1;
    dos=(eNumero*)num2;
    if(uno->numero>dos->numero)
    {
        retorno=1;
    }
    else if(uno->numero<dos->numero)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
  return retorno;
 }

int listarRepetidos(ArrayList* lista,ArrayList* repetidos)
{
    int i,j;
    int retorno=0;
    int len;
    eNumero* numaux;
    eNumero* numaux2;

    if(lista!=NULL && repetidos!=NULL)
    {
        retorno=1;
        len=lista->len(lista);
        for(i=0;i<len-1;i++)
        {
            numaux=lista->get(lista,i);

            if(comprobarRepetidos(repetidos,numaux)==1)
            {
             for(j=i+1;j<len;j++)
              {
                numaux2=lista->get(lista,j);

                if(numaux->numero==numaux2->numero)
                {
                    repetidos->add(repetidos,numaux);
                }
              }
            }
        }
    }
    al_sort(repetidos,ordenarNumero,0);
    return retorno;
}

int comprobarRepetidos(ArrayList* repetidos,eNumero* numero)
{
    int i;
    int len;
    int retorno=1;
    eNumero* auxiliar;

    if(repetidos!=NULL && numero!=NULL)
    {
        len=repetidos->len(repetidos);
        for(i=0;i<len;i++)
        {
            auxiliar=repetidos->get(repetidos,i);
            if(auxiliar->numero==numero->numero)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}




int listarnoRepetidos(ArrayList* lista,ArrayList* depurar,ArrayList* listanorepe)
{
    int i,j;
    int retorno=0;

    int len;
    int flag=0;
    eNumero* numaux;
    eNumero* numaux2;

    len=lista->len(lista);

    for(i=0;i<len;i++)
    {
        flag=0;
        numaux=(eNumero*) lista->get(lista,i);
       if(comprobarRepetidos(depurar,numaux)==1)
       {
        for(j=i+1;j<len;j++)
        {
            numaux2=(eNumero*) lista->get(lista,j);

            if(numaux->numero==numaux2->numero)
            {
                al_add(depurar,numaux);
                flag=1;
            }
        }
        if(flag==0)
        {
            al_add(listanorepe,numaux);
        }
       }

    }

al_sort(listanorepe,ordenarNumero,1);


return retorno;
}



int crearArchivos(ArrayList* listaRepe,ArrayList* listaNorepe)
{
    FILE* f;
    int i;
    int len;
    int retorno=0;
    eNumero* auxnum;

    f=fopen("depurado.csv","w");
    if(f!=NULL && listaRepe!=NULL && listaNorepe!=NULL)
    {
        retorno=1;
        len=listaRepe->len(listaRepe);

        for(i=0;i<len;i++)
        {
            auxnum=(eNumero*)listaRepe->get(listaRepe,i);
            fprintf(f,"%d,%s,%d,%d,%d\n",auxnum->numero,auxnum->nombre,auxnum->par,auxnum->impar,auxnum->primo);
        }
        printf("Archivo creado\n");
        fclose(f);
    }
    else{
        printf("Archivo vacio\n");
    }

    f=fopen("norepetidos.csv","w");
      if(f!=NULL && listaRepe!=NULL && listaNorepe!=NULL)
    {
        retorno=1;
        len=listaNorepe->len(listaNorepe);

        for(i=0;i<len;i++)
        {
            auxnum=(eNumero*)listaNorepe->get(listaNorepe,i);
            fprintf(f,"%d,%s,%d,%d,%d\n",auxnum->numero,auxnum->nombre,auxnum->par,auxnum->impar,auxnum->primo);
        }
        printf("Archivo creado\n");
        fclose(f);
    }
    else{
        printf("Archivo vacio\n");
    }
    return retorno;

}
