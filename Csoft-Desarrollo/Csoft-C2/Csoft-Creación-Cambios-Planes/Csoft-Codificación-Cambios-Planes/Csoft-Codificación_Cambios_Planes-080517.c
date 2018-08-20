/*==========================================================================*/
/*Autor: Brenda Robles Antonio	                           	   				*/
/*Componente:  Cambios Planes                           					*/
/*Fecha: 08/05/17	                                           				*/
/*Descripción: Codificación que muestra los cambios para planes				*/
/*Versión: 0.1                                             	   				*/
/*==========================================================================*/

/*==========================================================================*/
/* El programa contiene lo siguiente:                          				*/
/* void query_planes(sqlite3 *db,char* id_plan)      	   					*/
/* void update_plan(sqlite3 *db,char* type,char* value,char* id_plan)		*/
/* void cambios_planes(sqlite3 *db)  										*/
/* int main()  																*/
/*==========================================================================*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
using namespace std;
/***Esta función se encarga de buscar los valores del plan en la base de datos***/
void query_planes(sqlite3 *db,char* id_plan)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM Planes WHERE ID LIKE @Id_P ;";                     /* Selecciona a los planes con un id específico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es vílida la instrucción sql que se solicita*/
    if(rc!=SQLITE_OK){
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t Los Valores del Plan\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_plan,45,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del plan*/

        printf("\t\t    1)Nombre: %s\n", sqlite3_column_text(res, 1));
        printf("\t\t    2)N%cmero de semestres: %s\n",163, sqlite3_column_text(res, 2));
        printf("\t\t    3)Fecha: %s\n", sqlite3_column_text(res, 3));
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
        printf("\t\t QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else{
        printf("\t\t    Actualizando!!!\n");                       /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en qué lugar está el identificador a cambiar id*/
        int idv = sqlite3_bind_parameter_index(res, "@Value");           /* Se busca en qué lugar está el identificador a cambiar value*/
        sqlite3_bind_text(res, idx, id_planes,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado id*/
        sqlite3_bind_text(res, idv, value,40,SQLITE_STATIC);       /* Se cambia el identificador por un valor determinado value*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del plan*/
         printf("\t\t    Actualizado!!!\n");                       /* Se aprueba la sentencia sql ya hecha*/
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
         printf("\t\to-----------------------------------------------------------o\n");      /* Menú de cambios planes*/
         printf("\t\t| =================   Cambios Planes  ====================  |\n");
         printf("\t\to-----------------------------------------------------------o\n");
         printf("\t\to-----------------------------------------------------------o\n");
         printf("\t\t|   ¿Qu%c desea hacer?                                      |\n",130);
         printf("\t\t|   1)Buscar Plan                                           |\n");
         printf("\t\t|   2)Regresar Men%c Planes                                 |\n",163);
         printf("\t\t|   Ingresa la opci%cn que decea:                           |\n",162);
         printf("\t\to-----------------------------------------------------------o\n\t\t");
         scanf("%c",&opcion);
         switch(opcion){
            case '1':{
                    printf("\t\t    Ingresa el ID.-");                                      /* Busca a un plan para hacer cambios*/
                    fflush( stdin );
                    scanf("%[^\n]",id);
                    system("cls");
                    printf("\t\to----------------------------------------------------------o\n");
                    query_planes(db,id);                                                     /* Imprime datos del plan*/
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
    cambios_planes(db);                                                                      /*A cambios Planes*/
    return 0;
}
