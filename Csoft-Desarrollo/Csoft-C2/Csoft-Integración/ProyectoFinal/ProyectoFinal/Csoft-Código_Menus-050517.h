/*Librerias incluidas para funcionamiento*/

/*DECLARACIONES DE FUNCIONES A OCUPAR EN ESTE LIBRERIA*/
void menu_principal();
void Menu_Alumnos();
void menu_maestros();
void menu_planes();
void menu_reportes();
void menu_reportes_alumnos();
void menu_reportes_maestros();
void menu_reporte_materias();
void menu_reportes_planes();
/*=========================================================*/
/*Autor: Juan Alberto Gutierrez Canto                         */
/*Componente:  Menú Principal                                        */
/*Fecha: 16/03/2017                                     */
/*Descripción: Codificación que muestra el menú principal de opciones*/
/*Versión: 1.0                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_principal()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligio***/

void menu_principal(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("         °----------------------------------------------------------°\n");      /*Menu principal*/
        printf("         | ==============     Sistema Acad%cmico     =============== |\n",138);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Men%c Alumnos                                       !\n\n",163);
        printf("         !    2) Men%c Maestros                                      !\n\n",163);
        printf("         !    3) Men%c Planes                                        !\n\n",163);
        printf("         !    4) Men%c Reportes                                      !\n\n",163);
        printf("         !    5) Salir                                              !\n\n");
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();                                                                /*Seleccion del usuario*/
        switch(opcion){                                                                         /*Direccion a submenus*/
            case '1': {                                                                           /*A Menú Alumnos*/
                printf("Seleccion men%c alumnos\n",163);
                system("pause");
                Menu_Alumnos();
                break;
            }
            case '2': {                                                                           /*A Menú Maestros*/
                printf("Seleccion men%c maestros\n",163);
                system("pause");
                menu_maestros();
                break;
            }
            case '3': {                                                                           /*A Menú Planes*/
                printf("Seleccion men%c planes\n",163);
                system("pause");
                menu_planes();
                break;
            }
            case '4':
            {                                                                           /*A Menú Reportes*/
                printf("Seleccion men%c reportes\n",163);
                system("pause");
                menu_reportes();
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
/*=========================================================*/
/*Autor: Jesus Alberto Goiz Barrales                       */
/*Componente: MenÃº-Alumnos                                  */
/*Fecha: 20/03/2017                                        */
/*Descripció®º Menò °¡ra alumnos                 */
/*Versió®º 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void ABC_Alumnos()                                       */
/*==========================================================*/


/*Cascaró® ¤e las opciones que tendra el menò ¤¥ Alta de
Alumnos.                                                    */

void Menu_Alumnos()
{
    char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============        Men%c Alumnos       =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Alta Alumnos                                       !\n\n");
        printf("         !    2) Baja Alumnos                                       !\n\n");
        printf("         !    3) Modificaciones Alumnos                             !\n\n");
        printf("         !    4) Volver al men%c principal                           !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn alta de maestros\n",162);
                system("pause");
                //alta_maestros();
                break;
            }
            case '2':
			{
                printf("Selecci%cn baja maestros\n",162);
                system("pause");
                //baja_maestros();
                break;
            }
            case '3':
			{
                printf("Selecci%cn modificiaciones maestros\n",162);
                system("pause");
                //modificaciones_maestros();
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
/*Componente:  Menú Maestros                                        */
/*Fecha: 22/03/2017                                     */
/*Descripción: Codificación que muestra el menú maestros*/
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_maestros()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligio***/

void menu_maestros()
{
    char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============       Men%c Maestros       =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Alta Maestros                                      !\n\n");
        printf("         !    2) Baja Maestros                                      !\n\n");
        printf("         !    3) Modificaciones Maestros                            !\n\n");
        printf("         !    4) Volver al men%c principal                           !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();
        switch(opcion)
		{
            case '1':
			{
                printf("Selecci%cn alta de maestros\n",162);
                system("pause");
                //alta_maestros();
                break;
            }
            case '2':
			{
                printf("Selecci%cn baja maestros\n",162);
                system("pause");
                //baja_maestros();
                break;
            }
            case '3':
			{
                printf("Selecci%cn modificiaciones maestros\n",162);
                system("pause");
                //modificaciones_maestros();
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
/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligio***/

void menu_planes()
{
    char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============        Men%c Planes        =============== |\n",163);
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
        getchar();
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
/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligió***/

void menu_reportes()
{
    char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============       Men%c Reportes       =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Reportes Alumnos                                   !\n\n");
        printf("         !    2) Reportes Maestros                                  !\n\n");
        printf("         !    3) Reportes Materias                                  !\n\n");
        printf("         !    4) Reportes Planes                                    !\n\n");
        printf("         !    5) Volver al men%c principal                           !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();
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
	while(opcion!='5');
}
/*=========================================================*/
/*Autor: JAGC                       */
/*Componente:  MenÃº Principal                                        */
/*Fecha: 26/04/17                                     */
/*DescripciÃ³n: CodificaciÃ³n que muestra el menÃº reportes alumnos*/
/*VersiÃ³n: 1.0                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void menu_reportes_alumnos()                                              */
/* int main()                                               */
/*==========================================================*/
/***Esta funciÃ³n se encarga de presentar el menÃº reportes alumnos y redireccionar a la opcion que el usuario eligio***/
void menu_reportes_alumnos(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("         °----------------------------------------------------------°\n");      /*Menu principal*/
        printf("         | ==============   Men%c Reportes Alumnos   =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de Reportes:                   !\n\n");
        printf("         !    1) N%cmero de Alumnos por Materia                      !\n\n",163);
        printf("         !    2) N%cmero de Alumnos por Semestre                     !\n\n",163);
        printf("         !    3) Kardex de Alumnos                                  !\n\n");
        printf("         !    4) Calificaciones por Periodo                         !\n\n");
        printf("         !    5) Volver a men%c reportes                             !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();                                                                  /*Seleccion del usuario*/
        switch(opcion){                                                                         /*Direccion a submenus*/
            case '1': {                                                                           /*A MenÃº Alumnos*/
                printf("Selecci%cn n%cmero de alumnos por materia\n",162,163);
                system("pause");
                //menu_alumnos();
                break;
            }
            case '2': {                                                                           /*A MenÃº Maestros*/
                printf("Selecci%cn n%cmero de alumnos por semestre\n",162,163);
                system("pause");
                //menu_maestros();
                break;
            }
            case '3': {                                                                           /*A MenÃº Planes*/
                printf("Selecci%cn kardex de alumnos\n",162);
                system("pause");
                //menu_planes();
                break;
            }
            case '4': {                                                                           /*A MenÃº Reportes*/
                printf("Selecci%cn calificacion por periodo\n",162);
                system("pause");
                //menu_reportes();
                break;
            }
            case '5': {                                                                           /*Termino del programa*/
                printf("Selecci%cn men%c reportes\n",162,163);
                system("pause");
                menu_reportes();
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
/*=========================================================*/
/*Autor: Jesus Alberto Goiz Barrales                       */
/*Componente: Reporte_Maestros                            */
/*Fecha: 26/04/2017                                        */
/*DescripciÃ³n: MenÃº para realizar los reportes             */
/*de los maestros                                          */
/*VersiÃ³n: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void Reporte_Maestros()                                  */
/*==========================================================*/
/***Esta funciÃ³n se encarga de presentar el menÃº reportes alumnos y redireccionar a la opcion que el usuario eligio***/
void menu_reportes_maestros(){
    char opcion;
    do{
        system("cls");                                                                          /*Funcion para limpiar la pantalla*/
        printf("         °----------------------------------------------------------°\n");      /*Menu principal*/
        printf("         | ==============   Men%c Reportes Maestros  =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de Reportes:                   !\n\n");
        printf("         !    1) Materias impartidas                                !\n\n");
        printf("         !    2) Materias Disponibles                               !\n\n");
        printf("         !    3) Calificaci%cn de Materias                           !\n\n",162);
        printf("         !    4) Volver a men%c reportes                             !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();                                                                  /*Seleccion del usuario*/
        switch(opcion){                                                                         /*Direccion a submenus*/
            case '1': {                                                                           /*A MenÃº Alumnos*/
                printf("Selecci%cn Reporte_Materias_Impartidas\n",162);
                system("pause");
                //menu_alumnos();
                break;
            }
            case '2': {                                                                           /*A MenÃº Maestros*/
                printf("Selecci%cn Reporte_Materias_Disponibles\n",162);
                system("pause");
                //menu_maestros();
                break;
            }
            case '3': {                                                                           /*A MenÃº Planes*/
                printf("Selecci%cn Reporte_Califaci%cn_Materias\n",162);
                system("pause");
                //menu_planes();
                break;
            }
            case '4': {                                                                           /*A MenÃº Reportes*/
                printf("Selecci%cn men%c reportes\n",162,163);
                system("pause");
                menu_reportes();
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
/***Esta función se encarga de presentar el menú principal y redireccionar a la opcion que el usuario eligio***/
void menu_reporte_materias()
{
	char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============   Men%c Reportes Materias  =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Materias por Semeste                               !\n\n");
        printf("         !    2) Volver al men%c reportes                            !\n\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("              Opci%cn .-",162);
        scanf("%c",&opcion);
        getchar();
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
	while(opcion!='4');
}
/*==============================================================*/
/*Autor: Guillermo Vivaldo Vazquez                              */
/*Componente:  Menú Reportes Planes                             */
/*Fecha: 23/04/2017                                             */
/*Descripción: Codificación que muestra el menú reportes planes */
/*Versión: 0.1                                                  */
/*==============================================================*/
void menu_reportes_planes()
{
    char opcion;
    do
	{
        system("cls");
        printf("         °----------------------------------------------------------°\n");
        printf("         | ==============    Men%c Reportes Planes   =============== |\n",163);
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce la seleccion de men%c:                       !\n\n",163);
        printf("         !    1) Reportes Planes                                    !\n\n");
        printf("         !    2) Planes De Alumno                                   !\n\n");
        printf("         !    3) Volver al men%c reportes                            !\n\n",163);
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
