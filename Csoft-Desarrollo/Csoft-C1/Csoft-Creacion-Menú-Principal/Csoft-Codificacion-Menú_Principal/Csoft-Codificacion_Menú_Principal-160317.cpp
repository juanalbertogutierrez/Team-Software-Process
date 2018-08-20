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

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/***Esta funci�n se encarga de presentar el men� principal y redireccionar a la opcion que el usuario eligio***/

void menu_principal(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("         �----------------------------------------------------------�\n");      /*Menu principal*/
        printf("         | ==============     Sistema Acad%cmico     =============== |\n",138);
        printf("         �----------------------------------------------------------�\n");
        printf("         �----------------------------------------------------------�\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Men%c Alumnos                                       !\n\n",163);
        printf("         !    2) Men%c Maestros                                      !\n\n",163);
        printf("         !    3) Men%c Planes                                        !\n\n",163);
        printf("         !    4) Men%c Reportes                                      !\n\n",163);
        printf("         !    5) Salir                                              !\n\n");
        printf("         �----------------------------------------------------------�\n");
        printf("              Opci%cn .-",162);
        cin>>opcion;                                                                   /*Seleccion del usuario*/
        switch(opcion){                                                                         /*Direccion a submenus*/
            case '1': {                                                                           /*A Men� Alumnos*/
                printf("Seleccion men%c alumnos\n",163);
                system("pause");
                //menu_alumnos();
                break;
            }
            case '2': {                                                                           /*A Men� Maestros*/
                printf("Seleccion men%c maestros\n",163);
                system("pause");
                //menu_maestros();
                break;
            }
            case '3': {                                                                           /*A Men� Planes*/
                printf("Seleccion men%c planes\n",163);
                system("pause");
                //menu_planes();
                break;
            }
            case '4': {                                                                           /*A Men� Reportes*/
                printf("Seleccion men%c reportes\n",163);
                system("pause");
                //menu_reportes();
                break;
            }
            case '5': {                                                                           /*Termino del programa*/
                printf("Saliendo del programa...\n");
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
    menu_principal();                                                                           /*A Men� Principal*/
    return 0;
}
