/*=====================================================================================*/
/*Autor: Guillermo Vivaldo Vazquez                                                     */
/*Numero De Programa: 2A                                                               */
/*Fecha: 09/Febrero/2016                                                               */
/*Descripcion: Este programa cuenta las líneas lógicas de codigo que hay en un programa*/
/*Versión: 1.0                                                                         */
/*=====================================================================================*/

/*=====================================*/
/* Contenido                           */
/* Función "void bienvenida()"         */
/* Función "int conteo_programa()"     */
/* Función "void impresion_lineas()"   */
/* Función "int main()                 */
/*=====================================*/

/*======================================*/
/*Instrucciones De Reuso                */
/*                                      */
/*No se utilizo reuso en este programa  */
/*======================================*/

/*Declaración de las librerias que se utilizarán en el programa*/ 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  /*Librería necesaria para poder realizar operaciones con caracteres, de aquí se utilizara la función isspace/*

/*Declaración de variables con tamaño fijo "#define"*/

#define TAMANIO_1 1000
#define TAMANIO_2 300    

int contada = 0;  /*Variable que almacenara las líneas de código que vayan siendo contadas*/

/*Función de impresión en pantalla que le dará la bienvenida al usuario y le dará una breve descripcion de como usarlo*/

void bienvenida()
{
     printf("\n=====================\n");
     printf("\n     Bienvenido      \n");
     printf("\n=====================\n");
     printf("\n");
     printf("Este programa cuenta las lineas de codigo que hay en un programa\n");
     printf("Deberas ingresar el nombre del archivo junto con su extensión para conocer cuantas LOCS tiene\n");
     printf("Ejemplo: hola.c\n"); 
}

/*Función donde se ingresará el nombre del archivo del programa que se desea contar, y realizará el conteo de sus líneas*/

void conteo_programa()
{
     FILE *archivo;   /*Es un apuntador que apuntará a la información que contenga el archivo (necesaria para poder trabajar con archivos)*/
     char lineas[TAMANIO_1]; /*Es una cadena de caracteres en donde se almacenará la información que se obtenga del archivo*/
     char nombre[TAMANIO_2]; /*Es una cadena de caracteres que se ocupara para leer el nombre del archivo que teclee el usuario*/
     printf("\nIngresa el nombre del archivo: ");
     gets(nombre); /*Permitirá leer el nombre del archivo que teclee el usuario*/
     archivo = fopen(nombre,"r");  /*Permitira abrir el archivo cuyo nombre tecleo el usuario, la "r" significa que el archivo sera solo de lectura y deberá existir*/
     while(feof(archivo)==0)  /*Ciclo que recorrera cada cadena del archivo si el archivo regresa un 0 el archivo no termina aun, si regresa otro valor el archivo llego a su fin*/
     {
         fgets(lineas,TAMANIO_1,archivo); /*Recibirá el contenido que hay en el archivo y lo ira almacenando en la cadena de caractere "lineas"*/
         if(lineas[0] != '/' && lineas[1] != '*')  /*Verifica si el primer es diferente a "/" y el segundo es diferente a  "*", si es asi ira sumando 1 al contador*/
            contada++;   
         if(isspace(lineas[0])) /*Funcion isspace obtenida de la libreria ctype.h sirve para ver si el primer caracter que se lea es un espacio*/
            contada--;  /*Si se encuentra un espacio se le resta 1 al contador*/
     }
     printf("\nEl total de líneas de codigo es de %d \n",contada);
     /*return contada;*/   //Una vez que termina el ciclo se regresa el contador que será el total de lineas contadas
}

/*Función que sirve para imprimir el total de líneas de código contadas*/

/*void impresion_lineas()
{
     int result;  /*Variable donde se almacenará el parametro de conteo_programa()
     result = conteo_programa(); /*Se iguala la variable a la función conteo_programa para que se pueda imprimir el resultado
     printf("\nEl total de líneas de codigo es de %d \n",result); /*Imprime el total de líneas de código que hay en el programa
}*/

/*Función principal, donde se ejecutarán las funciones desarrolladas*/

int main()
{
    bienvenida();
    system("cls");
    conteo_programa();
    //impresion_lineas();
    system("pause");
    return 0;
}


