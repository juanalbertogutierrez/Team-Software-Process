/*=========================================================*/
/*Autor: René Moratilla Montes                          */
/*Componente:  Menú Planes                                        */
/*Fecha: 23/03/2017                                     */
/*Descripción: Codificación que muestra el menú planes*/
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_planes()                                              */
/* int main()                                               */
/*==========================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligio***/

void menu_planes()
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
        printf("         !    1) Alta Planes                                        !\n\n");
        printf("         !    2) Baja Planes                                        !\n\n");
        printf("         !    3) Modificaciones Planes                              !\n\n");
        printf("         !    4) Volver al men%c principal                           !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn alta de planes\n",162);
                system("pause");
                //alta_maestros();
                break;
            }
            case '2':
			{
                printf("Selecci%cn baja planes\n",162);
                system("pause");
                //baja_maestros();
                break;
            }
            case '3':
			{
                printf("Selecci%cn modificiaciones planes\n",162);
                system("pause");
                //modificaciones_maestros();
                break;
            }
            case '4':
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
	while(opcion!='4');

}

int main()
{
    menu_planes();
    return 0;
}
