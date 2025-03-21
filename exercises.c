#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for (int iteration = 1; iteration <= 10; iteration++) {
      int* element = (int*)malloc(sizeof(int));
      if (element == NULL) exit(1);
      *element = iteration;
      pushBack(L , element);
   }
return L;
}


/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

   int sumList =  0;
   void *element = first(L);

   while (element != NULL) {
      sumList += *(int*)element;
      element = next(L);
   }   

   return sumList;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){

   void *element = first(L);
   while (element != NULL) {
      if (*(int*)element == elem) {
         popCurrent(L);
      }
      element = next(L);
   }

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* stackAux = create_stack();

   while (top(P1) != NULL) {
      push(stackAux, top(P1));
      pop(P1);
   }

   while (top(stackAux) != NULL) {
      void* element = top(stackAux);
      push(P1, element);
      push(P2, element);
      pop(stackAux);
   }

   free(stackAux);
}





/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/


int parentesisBalanceados(char *cadena) {
   Stack* stack = create_Stack();
   int i = 0;
   while (cadena[i] != '\0') {
      if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
         char *caracter = malloc(sizeof(char));
         *caracter = cadena[i];
         push(stack, caracter);
      } else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
         if (top(stack) == NULL) {
            break;
         }
         char *topElement = (char *)top(stack);
         if ((cadena[i] == ')' && *topElement == '(') ||
             (cadena[i] == ']' && *topElement == '[') ||
             (cadena[i] == '}' && *topElement == '{')) {
            free(topElement);
            pop(stack);
         } else {
            break;
         }
      }
      i++;
   }
   int resultado = (top(stack) == NULL && cadena[i] == '\0') ? 1 : 0;
   while (top(stack) != NULL) {
      free(top(stack));
      pop(stack);
   }
   return resultado;
}









