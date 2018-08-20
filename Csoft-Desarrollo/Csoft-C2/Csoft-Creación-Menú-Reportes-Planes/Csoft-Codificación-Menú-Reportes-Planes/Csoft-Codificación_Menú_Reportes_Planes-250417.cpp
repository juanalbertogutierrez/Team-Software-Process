/*==============================================================*/
/*Autor: Guillermo Vivaldo Vazquez                              */
/*Componente:  Menú Reportes Planes                             */
/*Fecha: 23/04/2017                                             */
/*Descripción: Codificación que muestra el menú reportes planes */
/*Versión: 0.1                                                  */
/*==============================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void menu_rep_planes()
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
        printf("         !    1) Reportes Planes                                    !\n\n");
        printf("         !    2) Planes De Alumno                                   !\n\n");
      //printf("         !    3) Modificaciones Planes                              !\n\n");
        printf("         !    3) Volver al men%c reportes                           !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
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
        //case '3':
			//{
            //    printf("Selecci%cn modificiaciones planes\n",162);
            //    system("pause");
                //modificaciones_maestros();
            //    break;

            case '3':
			{
                printf("Regresando al men%c reportes...\n",163);
                system("pause");
                //menu_reportes
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
    menu_rep_planes();
    return 0;
}
