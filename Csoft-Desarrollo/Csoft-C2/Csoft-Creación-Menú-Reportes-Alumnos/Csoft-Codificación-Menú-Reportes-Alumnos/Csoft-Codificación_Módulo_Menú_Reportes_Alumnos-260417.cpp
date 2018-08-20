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
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/***Esta función se encarga de presentar el menú reportes alumnos y redireccionar a la opcion que el usuario eligio***/
void menu_reportes_alumnos(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("         °----------------------------------------------------------°\n");      /*Menu principal*/
        printf("         | ==============     Men%c Reportes Alumnos     =============== |\n",163);
        printf("         °--------------------------------------------------------------°\n");
        printf("         °--------------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de Reportes:                       !\n\n");
        printf("         !    1) N%cmero de Alumnos por Materia                        !\n\n",163);
        printf("         !    2) N%cmero de Alumnos por Semestre                       !\n\n",163);
        printf("         !    3) Kardex de Alumnos                                      !\n\n");
        printf("         !    4) Calificaciones por Periodo                             !\n\n");
        printf("         !    5) Salir                                                  !\n\n");
        printf("         °--------------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        cin>>opcion;                                                                   /*Seleccion del usuario*/
        switch(opcion){                                                                         /*Direccion a submenus*/
            case '1': {                                                                           /*A Menú Alumnos*/
                printf("Selecci%cn n%cmero de alumnos por materia\n",162,163);
                system("pause");
                //menu_alumnos();
                break;
            }
            case '2': {                                                                           /*A Menú Maestros*/
                printf("Selecci%cn n%cmero de alumnos por semestre\n",162,163);
                system("pause");
                //menu_maestros();
                break;
            }
            case '3': {                                                                           /*A Menú Planes*/
                printf("Selecci%cn kardex de alumnos\n",162);
                system("pause");
                //menu_planes();
                break;
            }
            case '4': {                                                                           /*A Menú Reportes*/
                printf("Selecci%cn calificacion por periodo\n",162);
                system("pause");
                //menu_reportes();
                break;
            }
            case '5': {                                                                           /*Termino del programa*/
                printf("Regresando a el men%c reportes...\n",163);
                break;
            }
            default: {                                                                           /*Opcion incorrecta*/
                printf("Opci%cn incorrecta...\n",162);
                system("pause");
                break;
            }
        }
    }while(opcion!='5');
}

int main()
{
    menu_reportes_alumnos();
    return 0;
}
