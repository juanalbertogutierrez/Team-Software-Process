/*=========================================================*/
/*Autor:Jesús Alberto Goiz Barrales                         */
/*Componente:  Baja Planes                                       */
/*Fecha: 09/05/17                                     */
/*Descripción: Codificación que muestra el borrado de los planes */
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void query_planes(sqlite3 *db,char* id_plan)      */
/* void borrar_planes(sqlite3 *db,char* type,char* value,char* id_plan) */
/* void borrar_posee(sqlite3 *db,char* type,char* value,char* id_plan)                              */
/*  */
/* int main()  */
/*==========================================================*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
#include "altas.h"

using namespace std;



/***Esta función se encarga de borrar el plan en la base de datos***/
void borrar_planes(sqlite3 *db,char* id_plan)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="DELETE from Planes where ID LIKE @Id_P;"; /* Selecciona a los planes con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_plan,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del plan*/
         printf("\t\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
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
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_plan,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del plan*/
         printf("\t\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta función es la funcion principal de borrado planes***/
void baja_planes(sqlite3 *db){
    char opcion;
    char id[40];
    do{
         system("cls");
         printf("\t\to----------------------------------------------------------o\n");      /* Menú de borrar alumno*/
         printf("\t\t| ================   Borrar Planes  ===================  |\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\t|   ¿Que desea hacer?                                      |\n");
         printf("\t\t|   1)Buscar Plane                                         |\n");
         printf("\t\t|   2)Regresar Men%c Planes                                |\n",163);
         printf("\t\t|   Ingresa la opci%cn que desea:                           |\n",162);
         printf("\t\to----------------------------------------------------------o\n\t\t");
         cin>>opcion;
         switch(opcion){
            case '1':{
                do{
                    printf("\t\t    Ingresa el ID.-");                                      /* Busca a un alumno para hacer borrar*/
                    scanf("%s",id);
                    system("cls");
                    printf("\t\to----------------------------------------------------------o\n");
                    query_planes(db,id);
                    printf("\t\to----------------------------------------------------------o\n");                                              /* Imprime datos del alumno*/
                    printf("\t\t|   0)Salir                                                |\n");
                    printf("\t\t|   Desea borrar a este Plan     (Y/N)):                    |\n");
                    printf("\t\to----------------------------------------------------------o\n\t\t");
                    cin>>opcion;
                    switch(opcion){
                        case 'Y':{
                        //	borrar_planes(db,id);
                        //	borrar_posee(db,id);

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
    res=sqlite3_open("testpm3f.db", &db); //query_planes(db,"ISW001");                                                      /* Se abre la db*/
    baja_planes(db);                                                                      /*A cambios Planes*/
    return 0;
}
