/*=========================================================*/
/*Autor: René Moratilla Montes                          */
/*Componente:  Menú Reporte Materias                                        */
/*Fecha: 25/04/2017                                     */
/*Descripción: Codificación que muestra el menú reporte materias*/
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void reporte_materias_semestres()                                              */
/* void menu_reporte_materias()                                 */
/* int main()                                               */
/*==========================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligio***/
void reporte_materias_semestres()
{
	printf("Selecci%cn Materias por Semestre\n",162);
    system("pause");
}
void menu_reporte_materias()
{
	char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============     Sistema Acad%cmico     =============== |\n",138);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Materias por Semeste                               !\n\n");
        printf("         !    2) Volver al men%c reportes                            !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                reporte_materias_semestres();
                break;
            }
            case '2':
			{
                printf("Regresando al men%c reportes...\n",163);
                system("pause");
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
int main()
{
	menu_reporte_materias();
	return 0;
}
