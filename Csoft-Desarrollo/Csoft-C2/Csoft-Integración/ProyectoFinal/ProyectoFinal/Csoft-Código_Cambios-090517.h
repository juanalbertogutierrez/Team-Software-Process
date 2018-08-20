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
/* void update_alumnos(sqlite3 *db,char* type,char* value,char* id_alumno)                              */
/* void cambios_alumnos(sqlite3 *db)  */
/*static int callback (void *data,int argc, char **argv,char **az_col_name)*/
/*void query_maestros(sqlite3 *db,char* id_maestro)          */
/*void update_maestros(sqlite3 *db,char* type,char* value,char* id_maestro)*/
/*void update_imparte(sqlite3 *db,char* type,char* value,char* id_maestro)*/
/*void cambios_maestros(sqlite3 *db)*/
/* void query_planes(sqlite3 *db,char* id_plan)      	   					*/
/* void update_plan(sqlite3 *db,char* type,char* value,char* id_plan)		*/
/* void cambios_planes(sqlite3 *db)  										*/
#include "sqlite3.h"                                  /*Interaccion base de datos*/
using namespace std;

/***Esta funciÃ³n se encarga de buscar los valores del alumno en la base de datos***/
void query_alumnos_c(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Alumnos WHERE ID_Al LIKE @Id_A ;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t Los Valores del Alumno\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_alumno,45,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucciÃ³n sql, valores del maestro*/

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

}

/***Esta funciÃ³n se encarga de actualizar al alumno en la base de datos***/
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
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Actualizando!!!\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_A");           /* Se busca en que lugar esta el identificador a cambiar id*/
        int idv = sqlite3_bind_parameter_index(res, "@Value");           /* Se busca en que lugar esta el identificador a cambiar value*/
        sqlite3_bind_text(res, idx, id_alumno,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
        sqlite3_bind_text(res, idv, value,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado value*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucciÃ³n sql, valores del maestro*/
         printf("\t    Actualizado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta funciÃ³n es la funcion principal del cambio de alumnos***/
void cambios_alumnos(sqlite3 *db){
    char opcion;
    char valor[40];
    char id[40];
    do{
         system("cls");
         printf("\to----------------------------------------------------------o\n");      /* MenÃº de cambios alumnos*/
         printf("\t| ================   Cambios Alumnos  ===================  |\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\t|   Â¿Que desea hacer?                                      |\n");
         printf("\t|   1)Buscar Alumno                                        |\n");
         printf("\t|   2)Regresar Men%c Alumnos                                |\n",163);
         printf("\t|   Ingresa la opci%cn que decea:                            |\n",162);
         printf("\to----------------------------------------------------------o\n\t");
         scanf("%c",&opcion);
         switch(opcion){
            case '1':{
                    printf("\t    Ingresa el ID.-");                                      /* Busca a un alumno para hacer cambios*/
                    fflush( stdin );
                    scanf("%[^\n]",id);
                    system("cls");
                    printf("\to----------------------------------------------------------o\n");
                    query_alumnos_c(db,id);                                                     /* Imprime datos del alumno*/
                    printf("\t|   0)Salir                                                |\n");
                    printf("\t|   Ingresa la opci%cn que decea cambiar:                   |\n",162);
                    printf("\to----------------------------------------------------------o\n\t");
                    fflush( stdin );
                    scanf("%c",&opcion);
                    if(opcion !='0'){
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
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
                            printf("\t    Regresando a men%c\n",163);
                            break;
                        }
                        default:{
                            printf("\t    Valor incorrecto!!! intenta otro \n");
                            break;
                        }
                    }
                printf("\t    Ingresa 1 para continuar\n");
                fflush( stdin );
                scanf("%c",&opcion);
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
}

/***Esta función se encarga de buscar los valores del maestro en la base de datos***/
void query_maestros_c(sqlite3 *db,char* id_maestro){
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Maestros where ID_Ma LIKE @Id_M;";                     /* Selecciona a los maestros con un id especifico sentencia sql*/
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

        printf("\t    1)Nombre: %s\n", sqlite3_column_text(res, 1));
        printf("\t    2)Apellido paterno: %s\n", sqlite3_column_text(res, 2));
        printf("\t    3)Apellido materno: %s\n", sqlite3_column_text(res, 3));
        printf("\t    4)Fecha: %s\n", sqlite3_column_text(res, 4));
        printf("\t    5)Direccion: %s\n", sqlite3_column_text(res, 5));
        printf("\t    6)Telefono: %s\n", sqlite3_column_text(res, 6));
        printf("\t    7)Email: %s\n", sqlite3_column_text(res, 7));
        printf("\t    8)RFC: %s\n", sqlite3_column_text(res, 0));

    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
    sql="SELECT ID_Materia,Status FROM Imparte where ID_Maestro LIKE @Id_M;";/* Instruccion sql para la seleccion de materias en tabla imparte*/
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
        printf("         %s\t 9) %s\n", sqlite3_column_text(res, 0),sqlite3_column_text(res, 1));
        step=sqlite3_step(res);
    }
    sqlite3_finalize(res);                                              /* Libera el espacio del objeto*/
}

/***Esta función se encarga de actualizar al alumno en la base de datos***/
void update_maestros(sqlite3 *db,int type,char* value,char* id_maestro)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    switch(type){
        case 1:{
            sql="UPDATE Maestros SET Nombre = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 2:{
            sql="UPDATE Maestros SET ApPaterno = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 3:{
            sql="UPDATE Maestros SET ApMaterno = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 4:{
            sql="UPDATE Maestros SET FNacimiento = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 5:{
            sql="UPDATE Maestros SET Direccion = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 6:{
            sql="UPDATE Maestros SET Telefono = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 7:{
            sql="UPDATE Maestros SET Email = @Value where ID_Ma LIKE @Id_M;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
        case 8:{
            sql="UPDATE Maestros SET RFC = @Value where ID_Ma LIKE @Id_M;";
            break;
        }
    }
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Actualizando!!!\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");           /* Se busca en que lugar esta el identificador a cambiar id*/
        int idv = sqlite3_bind_parameter_index(res, "@Value");           /* Se busca en que lugar esta el identificador a cambiar value*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
        sqlite3_bind_text(res, idv, value,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado value*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t    Actualizado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta función se encarga de actualizar las materias que imparte el maestro en la base de datos***/
void update_imparte(sqlite3 *db,int type,char* value,char* id_maestro,char* id_materia)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    switch(type){
        case 9:{
            sql="UPDATE Imparte SET Status = @Value where ID_Maestro LIKE @Id_M and ID_Materia LIKE @Id_Mat;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
            break;
        }
    }
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Actualizando!!!\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_M");
        int idt = sqlite3_bind_parameter_index(res, "@Id_Mat");         /* Se busca en que lugar esta el identificador a cambiar id*/
        int idv = sqlite3_bind_parameter_index(res, "@Value");           /* Se busca en que lugar esta el identificador a cambiar value*/
        sqlite3_bind_text(res, idx, id_maestro,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
        sqlite3_bind_text(res, idt, id_materia,40,SQLITE_STATIC);
        sqlite3_bind_text(res, idv, value,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado value*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
         printf("\t    Actualizado!!!\n");                       /* Se aprueba la sentencia sql ya echa*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
}

/***Esta función es la funcion principal del cambio de maestros***/
void cambios_maestros(sqlite3 *db){
    char opcion;
    char valor[40];
    char id[40];
    char id_mat[40];
    char status[40];
    do{
         system("cls");
         printf("\to----------------------------------------------------------o\n");      /* Menú de cambios alumnos*/
         printf("\t| ================   Cambios Maestros  ===================  |\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\to----------------------------------------------------------o\n");
         printf("\t|   ¿Que desea hacer?                                      |\n");
         printf("\t|   1)Buscar Maestro                                        |\n");
         printf("\t|   2)Regresar Men%c Maestros                                |\n",163);
         printf("\t|   Ingresa la opci%cn que desea:                            |\n",162);
         printf("\to----------------------------------------------------------o\n\t");
         cin>>opcion;
         switch(opcion){
            case '1':{
                do{
                    printf("\t    Ingresa el ID.-");                                      /* Busca a un alumno para hacer cambios*/
                    scanf("%s",&id);
                    system("cls");
                    printf("\to----------------------------------------------------------o\n");
                    query_maestros_c(db,id);                                                   /* Imprime datos del alumno*/
                    printf("\n");
                    printf("\t|   0)Salir                                                |\n");
                    printf("\t|   Ingresa la opci%cn que desea cambiar:                   |\n",162);
                    printf("\to----------------------------------------------------------o\n\t");
                    cin>>opcion;
                    switch(opcion){
                        case '1':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            getchar();
                            gets(valor);
                            update_maestros(db,1,valor,id);                              /* Actualiza nombre*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '2':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            scanf("%s",valor);
                            update_maestros(db,2,valor,id);                            /* Actualiza ap paterno*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '3':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            scanf("%s",valor);
                            update_maestros(db,3,valor,id);                            /* Actualiza ap materno*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '4':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            scanf("%s",valor);
                            update_maestros(db,4,valor,id);                          /* Actualiza fecha nacimiento*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '5':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            fflush( stdin );
                            scanf("%[^\n]",valor);
                            update_maestros(db,5,valor,id);                            /* Actualiza direccion*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '6':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            scanf("%s",valor);
                            update_maestros(db,6,valor,id);                             /* Actualiza telefono*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '7':{
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            scanf("%s",valor);
                            update_maestros(db,7,valor,id);                                /* Actualiza email*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '8':{/* Actualiza nombre*/
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            scanf("%s",valor);
                            update_maestros(db,8,valor,id);                              /* Actualiza RFC*/
                            system("pause");
                            system("cls");
                            break;
                        }
                        case '9':{
                            getchar();
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            gets(valor);
                            printf("\t    Ingresa el ID De La Materia.-");
                            gets(id_mat);
                            update_imparte(db,9,valor,id,id_mat);                             /* Actualiza semestre*/
                            system("pause");
                            system("cls");
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
}

/***Esta función se encarga de buscar los valores del plan en la base de datos***/
void query_planes_c(sqlite3 *db,char* id_plan)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Planes WHERE ID LIKE @Id_P ;";                     /* Selecciona a los planes con un id específico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es vílida la instrucción sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t Los Valores del Plan\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_plan,45,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del plan*/

        printf("\t    1)Nombre: %s\n", sqlite3_column_text(res, 1));
        printf("\t    2)N%cmero de semestres: %s\n",163, sqlite3_column_text(res, 2));
        printf("\t    3)Fecha: %s\n", sqlite3_column_text(res, 3));
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta función se encarga de actualizar el plan en la base de datos***/
void update_planes(sqlite3 *db,int type,char* value,char* id_planes)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    switch(type){
        case 1:{
            sql="UPDATE Planes SET Nombre = @Value where ID LIKE @Id_P;";                     /* Selecciona a los planes con un id específico sentencia sql*/
            break;
        }
        case 2:{
            sql="UPDATE Planes SET Num_Semestre = @Value where ID LIKE @Id_P;";                     /* Selecciona a los planes con un id específico sentencia sql*/
            break;
        }
        case 3:{
            sql="UPDATE Planes SET Fecha = @Value where ID LIKE @Id_P;";                     /* Selecciona a los planes con un id específico sentencia sql*/
            break;
        }
    }
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es válida la instrucción sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t    Actualizando!!!\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en qué lugar está el identificador a cambiar id*/
        int idv = sqlite3_bind_parameter_index(res, "@Value");           /* Se busca en qué lugar está el identificador a cambiar value*/
        sqlite3_bind_text(res, idx, id_planes,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
        sqlite3_bind_text(res, idv, value,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado value*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del plan*/
         printf("\t    Actualizado!!!\n");                       /* Se aprueba la sentencia sql ya hecha*/
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/

}

/***Esta función es la funcion principal del cambio de planes***/
void cambios_planes(sqlite3 *db){
    char opcion;
    char valor[40];
    char id[40];
    do{
         system("cls");
         printf("\to-----------------------------------------------------------o\n");      /* Menú de cambios planes*/
         printf("\t| =================   Cambios Planes  ====================  |\n");
         printf("\to-----------------------------------------------------------o\n");
         printf("\to-----------------------------------------------------------o\n");
         printf("\t|   ¿Qu%c desea hacer?                                      |\n",130);
         printf("\t|   1)Buscar Plan                                           |\n");
         printf("\t|   2)Regresar Men%c Planes                                 |\n",163);
         printf("\t|   Ingresa la opci%cn que decea:                           |\n",162);
         printf("\to-----------------------------------------------------------o\n\t");
         scanf("%c",&opcion);
         switch(opcion){
            case '1':{
                    printf("\t    Ingresa el ID.-");                                      /* Busca a un plan para hacer cambios*/
                    fflush( stdin );
                    scanf("%[^\n]",id);
                    system("cls");
                    printf("\to----------------------------------------------------------o\n");
                    query_planes_c(db,id);                                                     /* Imprime datos del plan*/
                    printf("\t|   0)Salir                                                |\n");
                    printf("\t|   Ingresa la opci%cn que decea cambiar:                   |\n",162);
                    printf("\to----------------------------------------------------------o\n\t");
                    fflush( stdin );
                    scanf("%c",&opcion);
                    if(opcion !='0'){
                            printf("\t    Ingresa el nuevo valor.- ");                                /* Nuevo valor a actualizar en la base de datos*/
                            fflush( stdin );
                            scanf("%[^\n]",valor);
                    }
                    switch(opcion){
                        case '1':{
                            update_planes(db,1,valor,id);                              /* Actualiza nombre*/
                            break;
                        }
                        case '2':{
                            update_planes(db,2,valor,id);                            /* Actualiza num_semestres*/
                            break;
                        }
                        case '3':{
                            update_planes(db,3,valor,id);                            /* Actualiza fecha*/
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
                printf("\t    Ingresa 1 para continuar\n");
                fflush( stdin );
                scanf("%c",&opcion);
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
}
