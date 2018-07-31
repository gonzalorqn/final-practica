#include "Arraylist.h"
typedef struct{
  int indice;
  int numero;
  char nombre[50];
  int par;
  int impar;
  int primo;
}eNumero;

eNumero* numero_new();

int setNumero(eNumero*,int);
int setIndice(eNumero*,int);
int setNombre(eNumero*,char*);
int setPar(eNumero*,int);
int setImpar(eNumero*,int);
int setPrimo(eNumero*,int);

int getNumero(eNumero*);
int getIndice(eNumero*);
char* getNombre(eNumero*);
int getPar(eNumero*);
int getImpar(eNumero*);
int getPrimo(eNumero*);

int mostrarNumero(eNumero*);
int mostrarListaNumero(ArrayList*);
int mostrarListaNumero100(ArrayList*);

void getString(char* mensaje,char* input);
int esNumerico(char*);
int esSoloLetras(char*);
int getValidInt(char* mensaje,char* mensajeError,char* input);
char* getValidChar(char* mensaje,char* mensajeError,char* input);


int parserNumero( ArrayList* pArrayList);

int isParImpPrimo(ArrayList*);
int listarRepetidos(ArrayList*,ArrayList*);
int listarnoRepetidos(ArrayList*,ArrayList*,ArrayList*);
int comprobarRepetidos(ArrayList*,eNumero*);

int ordenarNumero(void*,void*);

int crearArchivos(ArrayList*,ArrayList*);



