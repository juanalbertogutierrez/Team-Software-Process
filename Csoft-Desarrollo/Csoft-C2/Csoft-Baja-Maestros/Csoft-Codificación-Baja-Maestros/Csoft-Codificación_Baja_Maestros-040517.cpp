/*=========================================================*/
/*Autor: René Moratilla Montes                        */
/*Componente:  Baja Maestros                                      */
/*Fecha: 04/05/17                                     */
/*Descripción: Codificación que muestra las bajas para maestros*/
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void query_maestros(sqlite3 *db,char* id_alumno)      */
/* void delate_maestros(sqlite3 *db,char* type,char* value,char* id_alumno)                              */
/* void borrar_maestros(sqlite3 *db)  */
/* int main()  */
/*==========================================================*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
using namespace std;
/***Esta función se encarga de buscar los valores del maestro en la base de datos***/
void query_maestros(sqlite3 *db,char* id_maestro)
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
        printf("         Email:\t\t%s\n", sqlite3_column_text(res, 7));
        printf("         RFC:\t\t%s\n", sqlite3_column_text(res, 0));

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
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
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
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}//20

/***Esta función es la funcion principal de borrado maestros***/
void borrar_maestros(sqlite3 *db){
    char opcion;
    char valor[40];
    char id[40];
    do{
         system("cls");
         printf("\t\to----------------------------------------------------------o\n");      /* Menú de borrar maestro*/
         printf("\t\t| ================   Borrar Maestros  ===================  |\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\t|   ¿Que desea hacer?                                      |\n");
         printf("\t\t|   1)Buscar Maestro                                        |\n");
         printf("\t\t|   2)Regresar Men%c Maestros                                |\n",163);
         printf("\t\t|   Ingresa la opci%cn que decea:                            |\n",162);
         printf("\t\to----------------------------------------------------------o\n\t\t");
         cin>>opcion;
         switch(opcion){
            case '1':{
                do{
                    printf("\t\t    Ingresa el ID.-");                                      /* Busca a un maestro para hacer borrar*/
                    scanf("%s",id);
                    system("cls");
                    printf("\t\to----------------------------------------------------------o\n");
                    query_maestros(db,id);                                                     /* Imprime datos del maestro*/
                    printf("\t\t|   0)Salir                                                |\n");
                    printf("\t\t|   Desea borrar a este maestro (Y/N)):                   |\n");
                    printf("\t\to----------------------------------------------------------o\n\t\t");
                    cin>>opcion;
                    //printf("\t\t    Ingresa la respuesta.- ");                                /*Opción de borrado*/
                    //scanf("%[^\n]",valor);
                    switch(opcion){
                        case 'Y':{
                        	delate_maestros(db,id);
                        	delate_imparte(db,id);
                            break;
                        }
                        case 'N':{
                            printf("\t\t    Regresando a men%c\n",163);
                            break;
                        }
                        case '0':{
                            printf("\t\t    Regresando a men%c\n",163);
                            break;
                        }
                        default:{
                            printf("\t\t    Valor incorrecto!!! intenta otro \n");
                            break;
                        }
                    }
                }while(opcion!='0');
                break;
            }
            case '2':{
                            printf("\t\t    Regresando a men%c\n",163);
                            break;
                        }
            default:{
                printf("\t\t    Valor incorrecto!!! intenta otro \n");
                break;
            }
         }
    }while(opcion !='2');
}//61

int main()
{
    sqlite3 *db;                                                                            /* Base de datos en sqlite3*/
    int res;
    res=sqlite3_open("test.db", &db);                                                       /* Se abre la db*/
    borrar_maestros(db);                                                                      /*A borrar maestros*/
    return 0;
}
