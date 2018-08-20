#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*=========================================================*/
/*Autor: Jesus Alberto Goiz Barrales                       */
/*Componente: Reporte_Maestros                            */
/*Fecha: 26/04/2017                                        */
/*Descripción: Menú para realizar los reportes             */
/*de los maestros                                          */
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void Reporte_Maestros()                                  */
/*==========================================================*/


/*Cascarón de las opciones que tendra el menú Reportes
   Maestros                                                  */

void reporte_maestros()
{
     int opcion;

     printf("\to---------------------------------------------------------o\n");
     printf("\t|=================  Reporte Maestros  ====================|\n");
     printf("\to---------------------------------------------------------o\n");
     printf("\to---------------------------------------------------------o\n");
     printf("\t|   1)Materias Impartidas       2)Materias disponibles    |\n");
     printf("\t|   3)Calificaci%cn de Materias  4)Men%c de reportes        |\n",162,163);
     printf("\to---------------------------------------------------------o\n");


     /*Parte del codigo que se utiliza para poder validar el valor de entrada que recibe
     hasta que este sea el correcto*/

     r:printf("\t  Ingrese una opci%Cn valida ---> ",162);
     scanf("%d",&opcion);

		if ((opcion) <= 0 || (opcion) >4)
		{
		    printf("\t ---------------------------------------------------------------\n");
            printf("\t|    **** ERROR: Ingrese un n%cmero valido para continuar    **** |\n",163);
            printf("\t ---------------------------------------------------------------\n\n");
			//Limpia el buffer(Evita el ciclo infinito)
		   	while (getchar() != '\n');   goto r;
		}

    switch(opcion)
    {
        case 1:
            system("cls");
            printf("\t Sustituir por Reporte_Materias_Impartidas\n");
            break;

        case 2:
            system("cls");
            printf("\t Sustituir por Reporte_Materias_Disponibles\n");
            break;

        case 3:
            system("cls");
            printf("\t Sustituir por Reporte_Califaci%cn_Materias\n",162);
            break;

        case 4:
            system("cls");
            printf("\t Sustituir por Men%c_Reportes\n",163);
            break;
    }
}//39 lineas

//6 lineas
int main()
{
    reporte_maestros();
    system("PAUSE");
    return 0;
}
