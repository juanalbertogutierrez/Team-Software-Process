/*=====================================================================================*/
/*Autor: Guillermo Vivaldo Vazquez                                                     */
/*Numero De Programa: 2A                                                               */
/*Fecha: 09/Febrero/2016                                                               */
/*Descripcion: Este programa cuenta las l�neas l�gicas de codigo que hay en un programa*/
/*Versi�n: 1.0                                                                         */
/*=====================================================================================*/

/*=====================================*/
/* Contenido                           */
/* Funci�n "void bienvenida()"         */
/* Funci�n "int conteo_programa()"     */
/* Funci�n "void impresion_lineas()"   */
/* Funci�n "int main()                 */
/*=====================================*/

/*======================================*/
/*Instrucciones De Reuso                */
/*                                      */
/*No se utilizo reuso en este programa  */
/*======================================*/

/*Declaraci�n de las librerias que se utilizar�n en el programa*/ 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  /*Librer�a necesaria para poder realizar operaciones con caracteres, de aqu� se utilizara la funci�n isspace/*

/*Declaraci�n de variables con tama�o fijo "#define"*/

#define TAMANIO_1 1000
#define TAMANIO_2 300    

int contada = 0;  /*Variable que almacenara las l�neas de c�digo que vayan siendo contadas*/

/*Funci�n de impresi�n en pantalla que le dar� la bienvenida al usuario y le dar� una breve descripcion de como usarlo*/

void bienvenida()
{
     printf("\n=====================\n");
     printf("\n     Bienvenido      \n");
     printf("\n=====================\n");
     printf("\n");
     printf("Este programa cuenta las lineas de codigo que hay en un programa\n");
     printf("Deberas ingresar el nombre del archivo junto con su extensi�n para conocer cuantas LOCS tiene\n");
     printf("Ejemplo: hola.c\n"); 
}

/*Funci�n donde se ingresar� el nombre del archivo del programa que se desea contar, y realizar� el conteo de sus l�neas*/

void conteo_programa()
{
     FILE *archivo;   /*Es un apuntador que apuntar� a la informaci�n que contenga el archivo (necesaria para poder trabajar con archivos)*/
     char lineas[TAMANIO_1]; /*Es una cadena de caracteres en donde se almacenar� la informaci�n que se obtenga del archivo*/
     char nombre[TAMANIO_2]; /*Es una cadena de caracteres que se ocupara para leer el nombre del archivo que teclee el usuario*/
     printf("\nIngresa el nombre del archivo: ");
     gets(nombre); /*Permitir� leer el nombre del archivo que teclee el usuario*/
     archivo = fopen(nombre,"r");  /*Permitira abrir el archivo cuyo nombre tecleo el usuario, la "r" significa que el archivo sera solo de lectura y deber� existir*/
     while(feof(archivo)==0)  /*Ciclo que recorrera cada cadena del archivo si el archivo regresa un 0 el archivo no termina aun, si regresa otro valor el archivo llego a su fin*/
     {
         fgets(lineas,TAMANIO_1,archivo); /*Recibir� el contenido que hay en el archivo y lo ira almacenando en la cadena de caractere "lineas"*/
         if(lineas[0] != '/' && lineas[1] != '*')  /*Verifica si el primer es diferente a "/" y el segundo es diferente a  "*", si es asi ira sumando 1 al contador*/
            contada++;   
         if(isspace(lineas[0])) /*Funcion isspace obtenida de la libreria ctype.h sirve para ver si el primer caracter que se lea es un espacio*/
            contada--;  /*Si se encuentra un espacio se le resta 1 al contador*/
     }
     printf("\nEl total de l�neas de codigo es de %d \n",contada);
     /*return contada;*/   //Una vez que termina el ciclo se regresa el contador que ser� el total de lineas contadas
}

/*Funci�n que sirve para imprimir el total de l�neas de c�digo contadas*/

/*void impresion_lineas()
{
     int result;  /*Variable donde se almacenar� el parametro de conteo_programa()
     result = conteo_programa(); /*Se iguala la variable a la funci�n conteo_programa para que se pueda imprimir el resultado
     printf("\nEl total de l�neas de codigo es de %d \n",result); /*Imprime el total de l�neas de c�digo que hay en el programa
}*/

/*Funci�n principal, donde se ejecutar�n las funciones desarrolladas*/

int main()
{
    bienvenida();
    system("cls");
    conteo_programa();
    //impresion_lineas();
    system("pause");
    return 0;
}


