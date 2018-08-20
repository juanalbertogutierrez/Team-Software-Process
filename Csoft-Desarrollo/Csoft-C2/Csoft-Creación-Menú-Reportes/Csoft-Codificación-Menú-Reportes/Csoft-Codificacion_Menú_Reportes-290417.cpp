/*=========================================================*/
/*Autor: Brenda Robles Antonio                        	   */
/*Componente:  Menú Reportes                               */
/*Fecha: 29/04/17                               	       */
/*Descripción: Codificación que muestra el menú reportes   */
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_reportes()                                     */
/* int main()                                               */
/*==========================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligió***/

void menu_reportes()
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
        printf("         !    1) Reportes Alumnos                                    !\n\n");
        printf("         !    2) Reportes Maestros                                   !\n\n");
        printf("         !    3) Reportes Materias                                   !\n\n");
        printf("         !    4) Reportes Planes                                     !\n\n");
        printf("         !    5) Volver al men%c principal                           !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn reportes alumnos\n",162);
                system("pause");
                //menu_reportes_alumnos();
                break;
            }
            case '2':
			{
                printf("Selecci%cn reportes maestros\n",162);
                system("pause");
                //menu_reportes_maestros();
                break;
            }
            case '3':
			{
                printf("Selecci%cn reportes materias\n",162);
                system("pause");
                //menu_reportes_materias();
                break;
            }
            case '4':
            {
            	printf("Selecci%cn reportes planes\n",162);
            	system("pause");
            	//menu_reportes_planes();
            	break;
            }
            case '5':
			{
                printf("Regresando al men%c principal...\n",163);
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
	while(opcion!='5');

}

int main()
{
    menu_reportes();
    return 0;
}
