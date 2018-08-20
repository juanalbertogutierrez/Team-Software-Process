/*=========================================================*/
/*Autor:Jesús Alberto Goiz Barrales                         */
/*Componente:  Baja Alumnos                                       */
/*Fecha: 06/05/17                                     */
/*Descripción: Codificación que muestra el borrado de los alumnos */
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void query_alumnos(sqlite3 *db,char* id_alumno)      */
/* void borrar_alumnos(sqlite3 *db,char* type,char* value,char* id_alumno)                              */
/*  */
/* int main()  */
/*==========================================================*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
using namespace std;

void query_alumnos(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Alumnos where Id_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t Los Valores del Alumno \n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del alumno*/

        printf("\t\t    1)Nombre: %s\n", sqlite3_column_text(res, 1));
        printf("\t\t    2)Apellido paterno: %s\n", sqlite3_column_text(res, 2));
        printf("\t\t    3)Apellido materno: %s\n", sqlite3_column_text(res, 3));
        printf("\t\t    4)Fecha: %s\n", sqlite3_column_text(res, 4));
        printf("\t\t    5)Direccion: %s\n", sqlite3_column_text(res, 5));
        printf("\t\t    6)Telefono: %s\n", sqlite3_column_text(res, 6));
        printf("\t\t    7)Email: %s\n", sqlite3_column_text(res, 7));
        printf("\t\t    8)Plan: %s\n", sqlite3_column_text(res, 8));
        printf("\t\t    9)Semestre:\%s\n", sqlite3_column_text(res, 9));
    }
       sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
       sql="SELECT ID_Alumno,ID_Materia FROM Cursa where ID_Alumno LIKE @Id_A;";/* Instruccion sql para la seleccion de materias en tabla imparte*/
       rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es correcta la instruccion sql*/
       if(rc!=SQLITE_OK){
       printf("SQL error %s\n",err);                                   /* Imprime el error de la consulta*/
       }
       else{
       printf("\t\t Materias del alumno\n");                      /* Cambia los valores para el identificador en especifico*/
       int idx = sqlite3_bind_parameter_index(res, "@Id_A");
       sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);
    }
       step = sqlite3_step(res);
       while(step == SQLITE_ROW){                                          /* imprime los valores de la consulta de diferentes registros*/
       printf("\t\t %s\t%s\n", sqlite3_column_text(res, 0),sqlite3_column_text(res, 1));
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
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del alumno*/
         printf("\t\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
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
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Borrado!!!\n");    /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar id*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del alumno*/
         printf("\t\t    Borrado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta función es la funcion principal de borrado alumnos***/
void baja_alumnos(sqlite3 *db){
    char opcion;
    char id[40];
    do{
         system("cls");
         printf("\t\to----------------------------------------------------------o\n");      /* Menú de borrar alumno*/
         printf("\t\t| ================   Borrar Alumnos  ===================  |\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\t|   ¿Que desea hacer?                                      |\n");
         printf("\t\t|   1)Buscar Alumno                                        |\n");
         printf("\t\t|   2)Regresar Men%c Alumnos                                |\n",163);
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
                    query_alumnos(db,id);
                    printf("\t\to----------------------------------------------------------o\n");                                              /* Imprime datos del alumno*/
                    printf("\t\t|   0)Salir                                                |\n");
                    printf("\t\t|   Desea borrar a este Alumno (Y/N)):                    |\n");
                    printf("\t\to----------------------------------------------------------o\n\t\t");
                    cin>>opcion;
                    switch(opcion){
                        case 'Y':{
                        	borrar_alumnos(db,id);
                        	borrar_cursa(db,id);
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
    res=sqlite3_open("testpm3f.db", &db);                                                       /* Se abre la db*/
    baja_alumnos(db);                                                                      /*A cambios alumnos*/
    return 0;
}
