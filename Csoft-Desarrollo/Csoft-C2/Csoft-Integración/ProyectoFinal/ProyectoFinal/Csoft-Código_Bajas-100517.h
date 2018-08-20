/*=========================================================*/
/*Autor: Csoft                  */
/*Componente: Libreria cambios                                 */
/*Fecha:08/05/17                                           */
/*Descripción:librerias de cambios.           */
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void query_alumnos(sqlite3 *db,char* id_alumno)      */
/* void borrar_alumnos(sqlite3 *db,char* type,char* value,char* id_alumno)                              */
/* void borrar_cursa(sqlite3 *db,char* id_alumno)                 */
/* void baja_alumnos(sqlite3 *db)                 */
/* void query_maestros(sqlite3 *db,char* id_alumno)      */
/* void delate_maestros(sqlite3 *db,char* type,char* value,char* id_alumno)                              */
/* void borrar_maestros(sqlite3 *db)  */
/* void query_planes(sqlite3 *db,char* id_plan)      */
/* void borrar_planes(sqlite3 *db,char* type,char* value,char* id_plan) */
/* void borrar_posee(sqlite3 *db,char* type,char* value,char* id_plan)                              */
/* void baja_planes(sqlite3 *db)                              */
#include "sqlite3.h"                                  /*Interaccion base de datos*/
using namespace std;

void query_alumnos_b(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Alumnos where Id_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t Los Valores del Alumno \n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del alumno*/

        printf("\t    1)Nombre: %s\n", sqlite3_column_text(res, 1));
        printf("\t    2)Apellido paterno: %s\n", sqlite3_column_text(res, 2));
        printf("\t    3)Apellido materno: %s\n", sqlite3_column_text(res, 3));
        printf("\t    4)Fecha: %s\n", sqlite3_column_text(res, 4));
        printf("\t    5)Direccion: %s\n", sqlite3_column_text(res, 5));
        printf("\t    6)Telefono: %s\n", sqlite3_column_text(res, 6));
        printf("\t    7)Email: %s\n", sqlite3_column_text(res, 7));
        printf("\t    8)Plan: %s\n", sqlite3_column_text(res, 8));
        printf("\t    9)Semestre:\%s\n", sqlite3_column_text(res, 9));
    }
       sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
       sql="SELECT ID_Alumno,ID_Materia FROM Cursa where ID_Alumno LIKE @Id_A;";/* Instruccion sql para la seleccion de materias en tabla imparte*/
       rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es correcta la instruccion sql*/
       if(rc!=SQLITE_OK){
       printf("SQL error %s\n",err);                                   /* Imprime el error de la consulta*/
       }
       else{
       printf("\t Materias del alumno\n");                      /* Cambia los valores para el identificador en especifico*/
       int idx = sqlite3_bind_parameter_index(res, "@Id_A");
       sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);
    }
       step = sqlite3_step(res);
       while(step == SQLITE_ROW){                                          /* imprime los valores de la consulta de diferentes registros*/
       printf("\t %s\t%s\n", sqlite3_column_text(res, 0),sqlite3_column_text(res, 1));
       step=sqlite3_step(res);
       }
    sqlite3_finalize(res);                                              /* Libera el espacio del objeto*/
}//45

/***Esta función se encarga de actualizar al alumno en la base de datos***/
void borrar_alumnos(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Alumnos where Id_Al LIKE @Id_A;"; /* Selecciona a los maestros con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del alumno*/
         printf("\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}//20

void borrar_cursa(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Cursa where ID_Alumno LIKE @Id_A;";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del alumno*/
         printf("\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta función es la funcion principal de borrado alumnos***/
void baja_alumnos(sqlite3 *db)
{
    char opcion;
    char id[40];
    do{
         system("cls");
         printf("\to----------------------------------------------------------o\n");      /* Menú de borrar alumno*/
         printf("\t| ================   Borrar Alumnos  ===================  |\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\t|   ¿Que desea hacer?                                      |\n");
         printf("\t|   1)Buscar Alumno                                        |\n");
         printf("\t|   2)Regresar Men%c Alumnos                                |\n",163);
         printf("\t|   Ingresa la opci%cn que desea:                           |\n",162);
         printf("\to----------------------------------------------------------o\n\t");
         cin>>opcion;
         switch(opcion){
            case '1':{
                do{
                    printf("\t    Ingresa el ID.-");                                      /* Busca a un alumno para hacer borrar*/
                    scanf("%s",id);
                    system("cls");
                    printf("\to----------------------------------------------------------o\n");
                    query_alumnos_b(db,id);
                    printf("\to----------------------------------------------------------o\n");                                              /* Imprime datos del alumno*/
                    printf("\t|   0)Salir                                                |\n");
                    printf("\t|   Desea borrar a este Alumno (Y/N)):                    |\n");
                    printf("\to----------------------------------------------------------o\n\t");
                    cin>>opcion;
                    switch(opcion){
                        case 'Y':{
                        	borrar_alumnos(db,id);
                        	borrar_cursa(db,id);
                            break;
                        }
                        case 'N':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        case '0':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        default:{
                            printf("\t    Valor incorrecto!!! intenta otro \n");
                            break;
                        }
                    }
                }while(opcion!='0');
                break;
            }
            case '2':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
            default:{
                printf("\t    Valor incorrecto!!! intenta otro \n");
                break;
            }
         }
    }while(opcion !='2');
}//61

/***Esta función se encarga de buscar los valores del maestro en la base de datos***/
void query_maestros_b(sqlite3 *db,char* id_maestro)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM MAESTROS where Id_Ma LIKE @Id_M;";                     /* Selecciona a los maestros con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("         QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("         Valores del maestro\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instruccion sql, valores del maestro*/

        printf("         Nombre:\t%s %s %s\n", sqlite3_column_text(res, 1),sqlite3_column_text(res, 2),sqlite3_column_text(res, 3));
        printf("         Fecha:\t%s\n", sqlite3_column_text(res, 4));
        printf("         Direccion:\t%s\n", sqlite3_column_text(res, 5));
        printf("         Telefono:\t%s\n", sqlite3_column_text(res, 6));
        printf("         Email:\t%s\n", sqlite3_column_text(res, 7));
        printf("         RFC:\t%s\n", sqlite3_column_text(res, 0));

    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
    sql="SELECT ID_Materia,Status FROM IMPARTE where ID_Maestro LIKE @Id_M;";/* Instruccion sql para la seleccion de materias en tabla imparte*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es correcta la instruccion sql*/
    if(rc!=SQLITE_OK){
        printf("SQL error %s\n",err);                                   /* Imprime el error de la consulta*/
    }
    else{
        printf("         Materias del maestro\n");                      /* Cambia los valores para el identificador en especifico*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);
    }
    step = sqlite3_step(res);
    while(step == SQLITE_ROW){                                          /* imprime los valores de la consulta de diferentes registros*/
        printf("         %s\t%s\n", sqlite3_column_text(res, 0),sqlite3_column_text(res, 1));
        step=sqlite3_step(res);
    }
    sqlite3_finalize(res);                                              /* Libera el espacio del objeto*/

}//45

/***Esta función se encarga de borrar al maestro en la base de datos***/
void delate_maestros(sqlite3 *db,char* id_maestro)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Maestros where Id_Ma LIKE @Id_M;"; /* Selecciona a los maestros con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}//20

void delate_imparte(sqlite3 *db,char* id_maestro)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Imparte where ID_Maestro LIKE @Id_M;";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}//20

/***Esta función es la funcion principal de borrado maestros***/
void baja_maestros(sqlite3 *db){
    char opcion;
    char valor[40];
    char id[40];
    do{
         system("cls");
         printf("\to----------------------------------------------------------o\n");      /* Menú de borrar maestro*/
         printf("\t| ================   Borrar Maestros  ===================  |\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\t|   ¿Que desea hacer?                                      |\n");
         printf("\t|   1)Buscar Maestro                                        |\n");
         printf("\t|   2)Regresar Men%c Maestros                                |\n",163);
         printf("\t|   Ingresa la opci%cn que decea:                            |\n",162);
         printf("\to----------------------------------------------------------o\n\t");
         cin>>opcion;
         switch(opcion){
            case '1':{
                do{
                    printf("\t    Ingresa el ID.-");                                      /* Busca a un maestro para hacer borrar*/
                    scanf("%s",id);
                    system("cls");
                    printf("\to----------------------------------------------------------o\n");
                    query_maestros_b(db,id);                                                     /* Imprime datos del maestro*/
                    printf("\t|   0)Salir                                                |\n");
                    printf("\t|   Desea borrar a este maestro (Y/N)):                   |\n");
                    printf("\to----------------------------------------------------------o\n\t");
                    cin>>opcion;
                    //printf("\t    Ingresa la respuesta.- ");                                /*Opción de borrado*/
                    //scanf("%[^\n]",valor);
                    switch(opcion){
                        case 'Y':{
                        	delate_maestros(db,id);
                        	delate_imparte(db,id);
                            break;
                        }
                        case 'N':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        case '0':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        default:{
                            printf("\t    Valor incorrecto!!! intenta otro \n");
                            break;
                        }
                    }
                }while(opcion!='0');
                break;
            }
            case '2':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
            default:{
                printf("\t    Valor incorrecto!!! intenta otro \n");
                break;
            }
         }
    }while(opcion !='2');
}//61

/***Esta funciÃ³n se encarga de borrar el plan en la base de datos***/
void borrar_planes(sqlite3 *db,char* id_plan)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Planes where ID LIKE @Id_P;"; /* Selecciona a los planes con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_plan,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucciÃ³n sql, valores del plan*/
         printf("\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}//20

void borrar_posee(sqlite3 *db,char* id_plan)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Posee where ID_Plan LIKE @Id_P;";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_plan,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucciÃ³n sql, valores del plan*/
         printf("\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta funciÃ³n es la funcion principal de borrado planes***/
void baja_planes(sqlite3 *db)
{
    char opcion;
    char id[40];
    do{
         system("cls");
         printf("\to----------------------------------------------------------o\n");      /* MenÃº de borrar alumno*/
         printf("\t| ================   Borrar Planes  ===================  |\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\t|   Â¿Que desea hacer?                                      |\n");
         printf("\t|   1)Buscar Plane                                         |\n");
         printf("\t|   2)Regresar Men%c Planes                                |\n",163);
         printf("\t|   Ingresa la opci%cn que desea:                           |\n",162);
         printf("\to----------------------------------------------------------o\n\t");
         cin>>opcion;
         switch(opcion){
            case '1':{
                do{
                    printf("\t    Ingresa el ID.-");                                      /* Busca a un alumno para hacer borrar*/
                    scanf("%s",id);
                    system("cls");
                    printf("\to----------------------------------------------------------o\n");
                    query_planes(db,id);
                    printf("\to----------------------------------------------------------o\n");                                              /* Imprime datos del alumno*/
                    printf("\t|   0)Salir                                                |\n");
                    printf("\t|   Desea borrar a este Plan     (Y/N)):                    |\n");
                    printf("\to----------------------------------------------------------o\n\t");
                    cin>>opcion;
                    switch(opcion){
                        case 'Y':
                        {
                            borrar_planes(db,id);
                            borrar_posee(db,id);
                            break;
                        }
                        case 'N':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        case '0':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        default:{
                            printf("\t    Valor incorrecto!!! intenta otro \n");
                            break;
                        }
                    }
                }while(opcion!='0');
                break;
            }
            case '2':{
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
            default:{
                printf("\t    Valor incorrecto!!! intenta otro \n");
                break;
            }
         }
    }while(opcion !='2');
}//61
