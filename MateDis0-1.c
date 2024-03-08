#include<stdio.h>
#include<stdbool.h>
#define _USE_MATH_DEFINES
#include<math.h>

/*
============================

Andrea 
Arantxa Angulo Flores 751976

=============================

*/
char buffer[256];


int request(){
    
    int a;
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &a);
    return a;

}

int calculateTruth(int variables[], int numVariables) {
    int result = 1;

    for (int i = 0; i < numVariables; i++) {
        result = result && variables[i];
    }
    return result;
}

void PrintTruth(int n){
///Tablas de verdad siguen un patron binario por su naturaleza. Por lo que 2 elevado a N
///será el número posible de combinaciones posibles entre N variables dado 1 y 0  
    int numCombinations = pow(2, n);
    
    for (int i = 0; i < numCombinations; i++) { ///El for loop se encarga de que la accion sea iterada durante el valor de numCombinations
        int variables[n];
        for (int j = 0; j < n; j++) {
            variables[j] = (i >> j) & 1;
        }
        for (int j = 0; j < n; j++) {
            printf("  %d   ", variables[j]);
        }
        printf("|   %d\n", calculateTruth(variables, n));
    }
}

void PrintBarras(int n){
   for(int ok = 0; ok < n; ok++){
    printf("======");
   }
    
}

void PrintArray(char array[], int Longitud_Array){

    int n = Longitud_Array; //declarar N de nuevo para poder lanzarlo a la funcion PrintBarras
    PrintBarras(n);
    printf("\n");

    for(int index = 0; index < Longitud_Array; index++){
        printf(" ");
        printf(" ");
        printf("%c", array[index]);
        printf(" ");
        printf(" ");
        printf("|");
    }
    printf("\n");
    PrintBarras(n);
printf("\n");
}



int main(){
    char buffer[256];
    
    printf(" /\\_/\\  \n");
    printf("( o.o ) \n");
    printf(" > ^ <  BIENVENIDO AL PROGRAMA!\n");
    
///Entrada de datos
    int n, Return_Scanf ;
    printf("\n");
    printf("1) Introduce la cantidad de proposiciones: ");
    fgets(buffer, 256, stdin);
    Return_Scanf = sscanf(buffer, "%d", &n);

///Verificacion de entrada de datos
    if(Return_Scanf != 1){
        do{ 
            printf("\n");
            printf("Respuesta no valida. Ingresa un numero entero positivo.");
            printf("1) Introduce la cantidad de proposiciones: ");
            fgets(buffer, 256, stdin);
            Return_Scanf = sscanf(buffer, "%d", &n);
        }while(Return_Scanf != 1);

    }


///Guarda N cantidad de proposiciones (variables) en una lista (o array)
    char array[n];

    for(int contador = 0; contador < n; contador++){
        printf("Introduce tu proposicion #%d: " ,contador+1);
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%c", &array[contador]);
/*
verificacion de entrada aqui
*/
    }


////Impresion de variables
    int Longitud_Array = n;
    PrintArray(array, Longitud_Array);


////Impresion de tabla de verdad
    PrintTruth(n);

    
system("PAUSE");
return 0;
}


