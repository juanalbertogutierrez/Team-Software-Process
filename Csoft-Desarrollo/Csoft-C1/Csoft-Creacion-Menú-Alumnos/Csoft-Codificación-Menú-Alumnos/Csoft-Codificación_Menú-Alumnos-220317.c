#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*=========================================================*/
/*Autor: Jesus Alberto Goiz Barrales                       */
/*Componente: Menú-Alumnos                                  */
/*Fecha: 20/03/2017                                        */
/*Descripci󮺠Men򠰡ra alumnos                 */
/*Versi󮺠0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void ABC_Alumnos()                                       */
/*==========================================================*/


/*Cascar󮠤e las opciones que tendra el men򠤥 Alta de
Alumnos.                                                    */

void Menu_Alumnos()
{
     int opcion;

     printf("\to---------------------------------------------------------o\n");
     printf("\t|=================   Alta De Alumnos  ====================|\n");
     printf("\to---------------------------------------------------------o\n");
     printf("\to---------------------------------------------------------o\n");
     printf("\t|    1)Nuevo alumno               2)Modicar Alumno        |  \n");
     printf("\t|    3)Borrar alumno              4)Men%c principal       |  \n",163);
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
            printf("Sustituir por F%cncion Alta-Alumnos",163);
            break;

        case 2:
            system("cls");
            printf("Sustituir por F%cncion Modifcar-Alumnos",163);
            break;

        case 3:
            system("cls");
            printf("Sustituir por F%cncion Baja-Alumnos",163);
            break;

        case 4:
            system("cls");
            printf("Sustituir por F%cncion Men%c principal",163);
            break;
    }
}//39 lineas

//6 lineas
int main()
{
    Menu_Alumnos();
    system("PAUSE");
    return 0;
}
