/*=========================================================*/
/*Autor: Csoft                  */
/*Componente: Proyecto                                 */
/*Fecha:05/05/17                                           */
/*Descripci�n:Programa Principal de Control Escolar.           */
/*Versi�n: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_principal();                                   */
/* void Menu_Alumnos();                                     */
/* void menu_maestros();                                    */
/* void menu_planes();                                      */
/* void menu_reportes();                                    */
/* void menu_reportes_alumnos();                            */
/* void menu_reportes_maestros();                           */
/* void menu_reporte_materias();                            */
/* void menu_reportes_planes();                             */
/* int main()                                               */
/*==========================================================*/
/*Librerias incluidas para funcionamiento*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sqlite3.h"
#include "Csoft-C�digo_Altas-080517.h"
#include "Csoft-C�digo_Bajas-100517.h"
#include "Csoft-C�digo_Cambios-090517.h"

using namespace std;
/*DECLARACIONES DE FUNCIONES A OCUPAR*/
void menu_principal();
void Menu_Alumnos();
void menu_maestros();
void menu_planes();
void menu_reportes();
void menu_reportes_alumnos();
void menu_reportes_maestros();
void menu_reporte_materias();
void menu_reportes_planes();
sqlite3 *db;
/*=========================================================*/
/*Autor: Juan Alberto Gutierrez Canto                         */
/*Componente:  Men� Principal                                        */
/*Fecha: 16/03/2017                                     */
/*Descripci�n: Codificaci�n que muestra el men� principal de opciones*/
/*Versi�n: 1.0                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_principal()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta funci�n se encarga de presentar el men� principal y redireccionar a la opcion que el usuario eligio***/

void menu_principal(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("\t�----------------------------------------------------------�\n");      /*Menu principal*/
        printf("\t| ==============     Sistema Acad%cmico     =============== |\n",138);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Men%c Alumnos                                       !\n\n",163);
        printf("\t!    2) Men%c Maestros                                      !\n\n",163);
        printf("\t!    3) Men%c Planes                                        !\n\n",163);
        printf("\t!    4) Men%c Reportes                                      !\n\n",163);
        printf("\t!    S) Salir                                              !\n\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);                                                             /*Seleccion del usuario*/
        switch(opcion)
        {                                                                         /*Direccion a submenus*/
            case '1':
            {                                                                           /*A Men� Alumnos*/
                printf("Seleccion men%c alumnos\n",163);
                system("pause");
                Menu_Alumnos();
                break;
            }
            case '2':
            {                                                                           /*A Men� Maestros*/
                printf("Seleccion men%c maestros\n",163);
                system("pause");
                menu_maestros();
                break;
            }
            case '3': {                                                                           /*A Men� Planes*/
                printf("Seleccion men%c planes\n",163);
                system("pause");
                menu_planes();
                break;
            }
            case '4':
            {                                                                           /*A Men� Reportes*/
                printf("Seleccion men%c reportes\n",163);
                system("pause");
                menu_reportes();
                break;
            }
            case 'S':
            {                                                                           /*Termino del programa*/
                printf("Saliendo del programa...\n");
                break;
            }
            default:
            {                                                                           /*Opcion incorrecta*/
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }while(opcion!='S');
}
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
    char opcion;
    do
	{
        system("cls");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t| ==============        Men%c Alumnos       =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Alta Alumnos                                       !\n\n");
        printf("\t!    2) Baja Alumnos                                       !\n\n");
        printf("\t!    3) Modificaciones Alumnos                             !\n\n");
        printf("\t!    4) Volver al men%c principal                           !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn alta de alumnos\n",162);
                system("pause");
                alta_alumnos(db);
                break;
            }
            case '2':
			{
                printf("Selecci%cn baja alumnos\n",162);
                system("pause");
                baja_alumnos(db);
                break;
            }
            case '3':
			{
                printf("Selecci%cn modificiaciones alumnos\n",162);
                system("pause");
                cambios_alumnos(db);
                break;
            }
            case '4':
			{
                printf("Seleccion men%c principal\n",163);
                system("pause");
                menu_principal();
                break;
            }
            default:
			{
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }
	while(opcion!='4');
}
/*=========================================================*/
/*Autor: Brenda Robles Antonio                         */
/*Componente:  Men� Maestros                                        */
/*Fecha: 22/03/2017                                     */
/*Descripci�n: Codificaci�n que muestra el men� maestros*/
/*Versi�n: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_maestros()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta funci�n se encarga de presentar el men� principal y redireccionar a la opcion que el usuario eligio***/

void menu_maestros()
{
    char opcion;
    do
	{
        system("cls");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t| ==============       Men%c Maestros       =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Alta Maestros                                      !\n\n");
        printf("\t!    2) Baja Maestros                                      !\n\n");
        printf("\t!    3) Modificaciones Maestros                            !\n\n");
        printf("\t!    4) Volver al men%c principal                           !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn alta de maestros\n",162);
                system("pause");
                alta_maestros(db);
                break;
            }
            case '2':
			{
                printf("Selecci%cn baja maestros\n",162);
                system("pause");
                baja_maestros(db);
                break;
            }
            case '3':
			{
                printf("Selecci%cn modificiaciones maestros\n",162);
                system("pause");
                cambios_maestros(db);
                break;
            }
            case '4':
			{
                printf("Seleccion men%c principal\n",163);
                system("pause");
                menu_principal();
                break;
            }
            default:
			{
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }
	while(opcion!='4');
}
/*=========================================================*/
/*Autor: Ren� Moratilla Montes                          */
/*Componente:  Men� Planes                                        */
/*Fecha: 23/03/2017                                     */
/*Descripci�n: Codificaci�n que muestra el men� planes*/
/*Versi�n: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_planes()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta funci�n se encarga de presentar el men� principal y redireccionar a la opcion que el usuario eligio***/

void menu_planes()
{
    char opcion;
    do
	{
        system("cls");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t| ==============        Men%c Planes        =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Alta Planes                                        !\n\n");
        printf("\t!    2) Baja Planes                                        !\n\n");
        printf("\t!    3) Modificaciones Planes                              !\n\n");
        printf("\t!    4) Volver al men%c principal                           !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn alta de planes\n",162);
                system("pause");
                alta_planes(db);
                break;
            }
            case '2':
			{
                printf("Selecci%cn baja planes\n",162);
                system("pause");
                baja_planes(db);
                break;
            }
            case '3':
			{
                printf("Selecci%cn modificiaciones planes\n",162);
                system("pause");
                cambios_planes(db);
                break;
            }
            case '4':
			{
                printf("Seleccion men%c principal\n",163);
                system("pause");
                menu_principal();
                break;
            }
            default:
			{
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }
	while(opcion!='4');
}
/*=========================================================*/
/*Autor: Brenda Robles Antonio                        	   */
/*Componente:  Men� Reportes                               */
/*Fecha: 29/04/17                               	       */
/*Descripci�n: Codificaci�n que muestra el men� reportes   */
/*Versi�n: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_reportes()                                     */
/* int main()                                               */
/*==========================================================*/
/***Esta funci�n se encarga de presentar el men� principal y redireccionar a la opcion que el usuario eligi�***/

void menu_reportes()
{
    char opcion;
    do
	{
        system("cls");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t| ==============       Men%c Reportes       =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Reportes Alumnos                                   !\n\n");
        printf("\t!    2) Reportes Maestros                                  !\n\n");
        printf("\t!    3) Reportes Materias                                  !\n\n");
        printf("\t!    4) Reportes Planes                                    !\n\n");
        printf("\t!    5) Volver al men%c principal                           !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn reportes alumnos\n",162);
                system("pause");
                menu_reportes_alumnos();
                break;
            }
            case '2':
			{
                printf("Selecci%cn reportes maestros\n",162);
                system("pause");
                menu_reportes_maestros();
                break;
            }
            case '3':
			{
                printf("Selecci%cn reportes materias\n",162);
                system("pause");
                menu_reporte_materias();
                break;
            }
            case '4':
            {
            	printf("Selecci%cn reportes planes\n",162);
            	system("pause");
            	menu_reportes_planes();
            	break;
            }
            case '5':
			{
                printf("Selecci%cn men%c principal\n",162,163);
                system("pause");
                menu_principal();
                break;
            }
            default:
			{
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }
	while(opcion!='5');
}
/*=========================================================*/
/*Autor: JAGC                       */
/*Componente:  Menú Principal                                        */
/*Fecha: 26/04/17                                     */
/*Descripción: Codificación que muestra el menú reportes alumnos*/
/*Versión: 1.0                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_reportes_alumnos()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta función se encarga de presentar el menú reportes alumnos y redireccionar a la opcion que el usuario eligio***/
void menu_reportes_alumnos(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("\t�----------------------------------------------------------�\n");      /*Menu principal*/
        printf("\t| ==============   Men%c Reportes Alumnos   =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de Reportes:                   !\n\n");
        printf("\t!    1) N%cmero de Alumnos por Materia                      !\n\n",163);
        printf("\t!    2) N%cmero de Alumnos por Semestre                     !\n\n",163);
        printf("\t!    3) Kardex de Alumnos                                  !\n\n");
        printf("\t!    4) Calificaciones por Periodo                         !\n\n");
        printf("\t!    5) Volver a men%c reportes                             !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);    /*Seleccion del usuario*/
        switch(opcion)
        {                                                                         /*Direccion a submenus*/
            case '1':
            {                                                                           /*A Menú Alumnos*/
                printf("Selecci%cn n%cmero de alumnos por materia\n",162,163);
                system("pause");
                //menu_alumnos();
                break;
            }
            case '2':
            {                                                                           /*A Menú Maestros*/
                printf("Selecci%cn n%cmero de alumnos por semestre\n",162,163);
                system("pause");
                //menu_maestros();
                break;
            }
            case '3':
            {                                                                           /*A Menú Planes*/
                printf("Selecci%cn kardex de alumnos\n",162);
                system("pause");
                //menu_planes();
                break;
            }
            case '4':
            {                                                                           /*A Menú Reportes*/
                printf("Selecci%cn calificacion por periodo\n",162);
                system("pause");
                //menu_reportes();
                break;
            }
            case '5':
            {                                                                           /*Termino del programa*/
                printf("Selecci%cn men%c reportes\n",162,163);
                system("pause");
                menu_reportes();
                break;
            }
            default:
            {                                                                           /*Opcion incorrecta*/
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }while(opcion!='5');
}
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
/***Esta función se encarga de presentar el menú reportes alumnos y redireccionar a la opcion que el usuario eligio***/
void menu_reportes_maestros(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("\t�----------------------------------------------------------�\n");      /*Menu principal*/
        printf("\t| ==============   Men%c Reportes Maestros  =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de Reportes:                   !\n\n");
        printf("\t!    1) Materias impartidas                                !\n\n");
        printf("\t!    2) Materias Disponibles                               !\n\n");
        printf("\t!    3) Calificaci%cn de Materias                           !\n\n",162);
        printf("\t!    4) Volver a men%c reportes                             !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);                      /*Seleccion del usuario*/
        switch(opcion)
        {                                                                         /*Direccion a submenus*/
            case '1':
            {                                                                           /*A Menú Alumnos*/
                printf("Selecci%cn Reporte_Materias_Impartidas\n",162);
                system("pause");
                //menu_alumnos();
                break;
            }
            case '2':
            {                                                                           /*A Menú Maestros*/
                printf("Selecci%cn Reporte_Materias_Disponibles\n",162);
                system("pause");
                //menu_maestros();
                break;
            }
            case '3':
            {                                                                           /*A Menú Planes*/
                printf("Selecci%cn Reporte_Califaci%cn_Materias\n",162);
                system("pause");
                //menu_planes();
                break;
            }
            case '4':
            {                                                                           /*A Menú Reportes*/
                printf("Selecci%cn men%c reportes\n",162,163);
                system("pause");
                menu_reportes();
                break;
            }
            default:
            {                                                                           /*Opcion incorrecta*/
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }while(opcion!='4');
}
/*=========================================================*/
/*Autor: Ren� Moratilla Montes                          */
/*Componente:  Men� Reporte Materias                                        */
/*Fecha: 25/04/2017                                     */
/*Descripci�n: Codificaci�n que muestra el men� reporte materias*/
/*Versi�n: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void reporte_materias_semestres()                                              */
/* void menu_reporte_materias()                                 */
/* int main()                                               */
/*==========================================================*/
/***Esta funci�n se encarga de presentar el men� principal y redireccionar a la opcion que el usuario eligio***/
void menu_reporte_materias()
{
	char opcion;
    do
	{
        system("cls");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t| ==============   Men%c Reportes Materias  =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Materias por Semeste                               !\n\n");
        printf("\t!    2) Volver al men%c reportes                            !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
			    printf("Selecci%cn Reporte_Materias_Semestre\n",162);
                system("pause");
                break;
            }
            case '2':
			{
                printf("Selecci%cn men%c reportes\n",162,163);
                system("pause");
                menu_reportes();
                break;
            }
            default:
			{
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }
	while(opcion!='2');
}
/*==============================================================*/
/*Autor: Guillermo Vivaldo Vazquez                              */
/*Componente:  Men� Reportes Planes                             */
/*Fecha: 23/04/2017                                             */
/*Descripci�n: Codificaci�n que muestra el men� reportes planes */
/*Versi�n: 0.1                                                  */
/*==============================================================*/
void menu_reportes_planes()
{
    char opcion;
    do
	{
        system("cls");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t| ==============    Men%c Reportes Planes   =============== |\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("\t�----------------------------------------------------------�\n");
        printf("\t!    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("\t!    1) Reportes Planes                                    !\n\n");
        printf("\t!    2) Planes De Alumno                                   !\n\n");
        printf("\t!    3) Volver al men%c reportes                            !\n\n",163);
        printf("\t�----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        fflush( stdin );
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn reportes planes\n",162);
                system("pause");
                //planes_info();
                break;
            }
            case '2':
			{
                printf("Selecci%cn planes de alumno\n",162);
                system("pause");
                //alumnos_planes();
                break;
            }
            case '3':
			{
                printf("Selecci%cn men%c reportes\n",162,163);
                system("pause");
                menu_reportes();
                break;
            }
            default:
			{
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }
	while(opcion!='3');
}
int main()
{
    int res;
    res=sqlite3_open("test.db",&db);
    menu_principal();
    sqlite3_close(db);                                                                          /*Men� Principal*/
    return 0;
}
