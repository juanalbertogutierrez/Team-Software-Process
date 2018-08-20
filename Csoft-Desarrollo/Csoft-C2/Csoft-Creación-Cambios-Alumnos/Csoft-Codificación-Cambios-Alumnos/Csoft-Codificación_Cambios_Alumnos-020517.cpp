/*=========================================================*/
/*Autor: Juan Alberto Gutierrez Canto                         */
/*Componente:  Cambios Alumnos                                       */
/*Fecha: 02/05/17                                     */
/*Descripción: Codificación que muestra los cambios para alumnos*/
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/* void query_alumnos(sqlite3 *db,char* id_alumno)      */
/* void update_alumnos(sqlite3 *db,char* type,char* value,char* id_alumno)                              */
/* void cambios_alumnos(sqlite3 *db)  */
/* int main()  */
/*==========================================================*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
using namespace std;
/***Esta función se encarga de buscar los valores del alumno en la base de datos***/
void query_alumnos(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Alumnos WHERE ID_Al LIKE @Id_A ;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t Los Valores del Alumno\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_alumno,45,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/

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

}
/***Esta función se encarga de actualizar al alumno en la base de datos***/
void update_alumnos(sqlite3 *db,int type,char* value,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    switch(type){
        case 1:{
            sql="UPDATE Alumnos SET Nombre = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 2:{
            sql="UPDATE Alumnos SET ApPaterno = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 3:{
            sql="UPDATE Alumnos SET ApMaterno = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 4:{
            sql="UPDATE Alumnos SET FNacimiento = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 5:{
            sql="UPDATE Alumnos SET Direccion = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 6:{
            sql="UPDATE Alumnos SET Telefono = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 7:{
            sql="UPDATE Alumnos SET Email = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 8:{
            sql="UPDATE Alumnos SET ID_Plan = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 9:{
            sql="UPDATE Alumnos SET Semestre = @Value where ID_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
    }
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Actualizando!!!\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar id*/
        int idv = sqlite3_bind_parameter_index(res, "@Value");           /* Se busca en que lugar esta el identificador a cambiar value*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
        sqlite3_bind_text(res, idv, value,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado value*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t\t    Actualizado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}
/***Esta función es la funcion principal del cambio de alumnos***/
void cambios_alumnos(sqlite3 *db){
    char opcion;
    char valor[40];
    char id[40];
    do{
         system("cls");
         printf("\t\to----------------------------------------------------------o\n");      /* Menú de cambios alumnos*/
         printf("\t\t| ================   Cambios Alumnos  ===================  |\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\to----------------------------------------------------------o\n");
         printf("\t\t|   ¿Que desea hacer?                                      |\n");
         printf("\t\t|   1)Buscar Alumno                                        |\n");
         printf("\t\t|   2)Regresar Men%c Alumnos                                |\n",163);
         printf("\t\t|   Ingresa la opci%cn que decea:                            |\n",162);
         printf("\t\to----------------------------------------------------------o\n\t\t");
         scanf("%c",&opcion);
         switch(opcion){
            case '1':{
                    printf("\t\t    Ingresa el ID.-");                                      /* Busca a un alumno para hacer cambios*/
                    fflush( stdin );
                    scanf("%[^\n]",id);
                    system("cls");
                    printf("\t\to----------------------------------------------------------o\n");
                    query_alumnos(db,id);                                                     /* Imprime datos del alumno*/
                    printf("\t\t|   0)Salir                                                |\n");
                    printf("\t\t|   Ingresa la opci%cn que decea cambiar:                   |\n",162);
                    printf("\t\to----------------------------------------------------------o\n\t\t");
                    fflush( stdin );
                    scanf("%c",&opcion);
                    if(opcion !='0'){
                            printf("\t\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            fflush( stdin );
                            scanf("%[^\n]",valor);
                    }
                    switch(opcion){
                        case '1':{
                            update_alumnos(db,1,valor,id);                              /* Actualiza nombre*/
                            break;
                        }
                        case '2':{
                            update_alumnos(db,2,valor,id);                            /* Actualiza ap paterno*/
                            break;
                        }
                        case '3':{
                            update_alumnos(db,3,valor,id);                            /* Actualiza ap materno*/
                            break;
                        }
                        case '4':{
                            update_alumnos(db,4,valor,id);                          /* Actualiza fecha nacimiento*/
                            break;
                        }
                        case '5':{
                            update_alumnos(db,5,valor,id);                            /* Actualiza direccion*/
                            break;
                        }
                        case '6':{
                            update_alumnos(db,6,valor,id);                             /* Actualiza telefono*/
                            break;
                        }
                        case '7':{
                            update_alumnos(db,7,valor,id);                                /* Actualiza email*/
                            break;
                        }
                        case '8':{
                            update_alumnos(db,8,valor,id);                              /* Actualiza id_plan*/
                            break;
                        }
                        case '9':{
                            update_alumnos(db,9,valor,id);                             /* Actualiza semestre*/
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
                printf("\t\t    Ingresa 1 para continuar\n");
                fflush( stdin );
                scanf("%c",&opcion);
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
}

int main()
{
    sqlite3 *db;                                                                            /* Base de datos en sqlite3*/
    int res;
    res=sqlite3_open("test.db", &db);                                                       /* Se abre la db*/
    cambios_alumnos(db);                                                                      /*A cambios alumnos*/
    return 0;
}

