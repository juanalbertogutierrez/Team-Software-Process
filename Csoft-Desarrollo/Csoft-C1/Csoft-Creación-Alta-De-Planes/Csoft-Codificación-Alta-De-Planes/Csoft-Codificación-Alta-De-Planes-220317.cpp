/*=======================================================================================*/
/*Autor: Guillermo Vivaldo Vazquez                                                       */
/*Nombre del Programa: Alta De Planes                                                    */
/*Fecha: 22/Marzo/2017                                                                   */
/*Descripción: Este programa realiza el alta de planes y de materias que tendra cada plan*/
/*Version: 1.0                                                                           */
/*=======================================================================================*/

/*=====================================*/
/*Contenido                            */
/*static int callback()                */
/*void query_planes()                  */
/*void insert_mtr_plan()               */
/*void insert_materias()               */
/*void insert_planes()                 */
/*static int print_archivo()           */
/*void alta_materias()                 */
/*void alta_planes()                   */
/*int_main()                   */
/*=====================================*/

/*====================================================================*/
/*Instrucciones De Reuso                                              */
/*No se utilizó reuso                                                 */
/*====================================================================*/

/*Declaración De Librerias*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "sqlite3.h"

/*Interacción base de datos*/

using namespace std;
FILE *pfile;

/***Esta función se encarga de imprimir los datos encontrados en la base de datos***/
static int callback (void *data,int argc, char **argv,char **az_col_Name)
{
    int i;
    printf( "%s:\n ", (const char*)data);
    for(i=0;i<argc;i++)
    {
         printf("%s = %s\n", az_col_Name[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


/****Esta función busca los valores del plan en la base de datos****/
void query_planes(sqlite3 *db,char* id_plan)
{
    char *sql;           /*Para la sentencia sql */
    char *err=0;         /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM PLANES where ID LIKE @Id_P;";                     /* Selecciona los planes con un id especifico sentencia sql*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Verifica si es valida la instruccion sql que se solicita*/
    if(rc!=SQLITE_OK)
    {
        printf("         QUERY-SQL error %s\n",err);                    /* Imprime el error de la base de datos*/
    }
    else
    {
        printf("         Valores del plan\n");                          /* Se aprueba la sentencia sql*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");           /* Se busca en que lugar esta el identificador a cambiar*/
        sqlite3_bind_text(res, idx, id_plan,40,SQLITE_STATIC);          /* Se cambia el identificador por un valor determinado*/
    }
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW)                                             /* indica el resultado de la instruccion sql, valores del plan*/
    {

        printf("         Nombre:\t%s\n", sqlite3_column_text(res, 1));
        printf("         Numero De Semestre:\t%d\n", sqlite3_column_int(res, 2));
        printf("         Fecha:\t%s\n", sqlite3_column_text(res, 3));
    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
    sql="SELECT ID_Materia,ID_Plan,Semestre FROM POSEE where ID_Plan=@Id_P;";  /* Instruccion sql para la seleccion de materias de cada plan en tabla POSEE*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);
    printf("\n");                          /* Verifica si es correcta la instruccion sql*/
    if(rc!=SQLITE_OK)
    {
        printf("SQL error %s\n",err);                                   /* Imprime el error de la consulta*/
    }
    else
    {
        printf("         Materias del Plan\n");                      /* Cambia los valores para el identificador en especifico*/
        int idx = sqlite3_bind_parameter_index(res, "@Id_P");
        sqlite3_bind_text(res, idx, id_plan,40,SQLITE_STATIC);
    }
    step = sqlite3_step(res);
    while(step == SQLITE_ROW)                                         /* imprime los valores de la consulta de diferentes registros*/
    {
        printf("         %s\t%s\t\%d\n", sqlite3_column_text(res, 0),sqlite3_column_text(res, 1),sqlite3_column_int(res,2));
        step=sqlite3_step(res);
    }
    sqlite3_finalize(res);                                              /* Libera el espacio del objeto*/
}

/***Esta función se encarga de insertar los valores de la materia y el plan en la base de datos***/
void insert_mtr_plan(sqlite3 *db,char* id_materia, char* id_plan, int semestre)
{
    char *sql;
    char *err=0;
    int rc;
    sqlite3_stmt *res;
    sql="INSERT INTO POSEE (ID_Materia, ID_Plan, Semestre) VALUES (@Id_M,@Id_P,@semestre);";/* Inserta los maestros en la tabla imparte los tres valores de esta tabla*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Prepara la sentencia sql*/
    if(rc!=SQLITE_OK)
    {
        printf("         POSEE-SQL error %s\n",err);                  /* Imprime el error de la sentencia*/
    }
    else{
        printf("         Valores ingresados correctamente.\n");         /* Cambia los identificades por valores en la sentencia*/
        int idm = sqlite3_bind_parameter_index(res, "@Id_M");           /* busca en donde esta el identificador*/
        int idt = sqlite3_bind_parameter_index(res, "@Id_P");
        int idsemestre = sqlite3_bind_parameter_index(res, "@semestre");
        sqlite3_bind_text(res, idm, id_materia,40,SQLITE_STATIC);       /* Cambia el identificador por un valor text*/
        sqlite3_bind_text(res, idt, id_plan,40,SQLITE_STATIC);          /* Cambia el identificador por un valor text*/
        sqlite3_bind_int(res, idsemestre, semestre);                         /* Cambia el identificador por un valor int*/
    }
    int step = sqlite3_step(res);                                       /* Realiza la consulta sql*/
    if (step == SQLITE_ROW)
    {
        printf("         %s\n", sqlite3_column_text(res, 0));           /* Imprime datos devueltos de la consulta*/
    }
}

/***Esta función se encarga de insertar los valores de la materia en la base de datos***/
void insert_materias(sqlite3 *db,char* id_materia, char* nombre)
{
    char *sql;
    char *err=0;
    int rc;
    sqlite3_stmt *res;                                                  /* Inserta todos los valores de maestro sentncia sql*/
    sql="INSERT INTO MATERIAS (Id_M, Nombre) VALUES (@Id_M,@nom);";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Prepara la sentencia sql*/
    if(rc!=SQLITE_OK){
        printf("SQL error %s\n",err);                                   /* Imprime el mensaje de error*/
    }
    else{
        printf("         Valores de materias guardados correctamente.\n");/* Cambia los identificador por los valores*/
        int idm = sqlite3_bind_parameter_index(res, "@Id_M");           /* Busca el lugar del identificador*/
        int nom = sqlite3_bind_parameter_index(res, "@nom");
        sqlite3_bind_text(res, idm, id_materia,40,SQLITE_STATIC);       /* cambia el valor por elidenitficador */
        sqlite3_bind_text(res, nom, nombre,40,SQLITE_STATIC);
    }
    int step = sqlite3_step(res);/* */
    if (step == SQLITE_ROW)
    {
        printf("         Correcto %s\n", sqlite3_column_text(res, 0));  /* Imprime el resultado de la consulta*/
    }
}

/****Esta función realiza un insert de los valores de las materias en la base de datos****/
void insert_planes(sqlite3 *db,char* id_plan, char* nombre, int num_semestres, char* fecha)
{
    char *sql;
    char *err=0;
    int rc;
    sqlite3_stmt *res;
    sql="INSERT INTO PLANES (ID, Nombre, Num_Semestres, Fecha) VALUES (@Id_P,@nom,@sem,@dat);";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Prepara la sentencia sql*/
    if(rc!=SQLITE_OK)
    {
        printf("SQL error %s\n",err);
    }
    else
    {
        printf("Valores de los planes guardados correctamente.\n");
        int idm = sqlite3_bind_parameter_index(res, "@Id_P");           /* Busca el lugar del identificador*/
        int nom = sqlite3_bind_parameter_index(res, "@nom");
        int semes = sqlite3_bind_parameter_index(res, "@sem");
        int fch = sqlite3_bind_parameter_index(res, "@dat");
        sqlite3_bind_text(res, idm, id_plan,40,SQLITE_STATIC);       /* cambia el valor por elidenitficador */
        sqlite3_bind_text(res, nom, nombre,40,SQLITE_STATIC);
        sqlite3_bind_int(res, semes, num_semestres);
        sqlite3_bind_text(res, fch, fecha,40,SQLITE_STATIC);
    }
    int step = sqlite3_step(res);/* */
    if (step == SQLITE_ROW)
    {
        printf("         Correcto %s\n", sqlite3_column_text(res, 0));  /* Imprime el resultado de la consulta*/
    }
}

/***Esta función se encarga de imprimir los datos encontrados en la base de datos a un archivo de txt***/
static int print_archivo(void *data,int argc, char **argv,char **az_col_name)
{
    int i;
    for(i=0;i<argc;i++)
    {
        fprintf(pfile,"%s\t",argv[i]);                                  /* Imprime en el archivo txt las materias disponibles en la bd*/
    }
    fprintf(pfile,"\n");
    return 0;
}

/***Esta función se encarga de presentar alta de materias***/
/***Contiene todo el proceso y redirecciona hacia las funciones de inserción y select con la base de datos***/
void alta_materias(sqlite3 *db)
{
    char id_materia[40];
    char nombre[40];
    bool correcto=false;
    int status=2;
    while(status != 1){                                                                     /* Pide datos haste que esten correctos aprobados por el usuario*/
        system("cls");
        printf("         °----------------------------------------------------------°\n");  /*Menu Alta maestros*/
        printf("         | ==============       Alta Materias       =============== |\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce los siguientes datos:                       !\n\n");
        printf("         !    1) ID                 2) Nombre                       !\n\n");
        printf("         °----------------------------------------------------------°\n");
        fflush( stdin );                                                                    /* Limpiar buffer*/
        printf("         1)");                                                              /* ID*/
        gets(id_materia);
        printf("         2)");                                                              /* Nombre*/
        fflush( stdin );
        gets(nombre);
        system("cls");
        printf("         °----------------------------------------------------------°\n");      /*Muestra datos*/
        printf("         | ==============       Alta Materias       =============== |\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    ¿Son correctos los datos?  1)si 2)no:                 !\n\n");
        printf("         °----------------------------------------------------------°\n");
        printf("           ID:\t%s\n",&id_materia);
        printf("\n         Nombre:\t%s\n",&nombre);
        printf("\n         Opci%cn .-",162);
        cin>>status;
    }
    system("cls");
    insert_materias(db,id_materia,nombre);/* Mqndamos a guardar datos a la bd*/
    system("pause");
}

/***Esta función se encarga de presentar alta de planes***/
/***Contiene todo el proceso y redirecciona hacia las funciones de inserción y select con la base de datos***/
void alta_planes(sqlite3 *db)
{
    char id_plan[40];
    char nombre[40];
    int num_semestres=0;
    int num_materias;
    char fecha[40];
    char id_materia[40];
    int i=0,j=0;
    bool correcto=false;
    int status=2;
    while(status != 1)
    {                                                                     /* Pide datos haste que esten correctos aprobados por el usuario*/
        system("cls");
        printf("         °----------------------------------------------------------°\n");  /*Menu Alta maestros*/
        printf("         | ==============       Alta Planes       =============== |\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce los siguientes datos:                       !\n\n");
        printf("         !    1) ID                 2) Nombre                       !\n\n");
        printf("         !    3) Numero_Semestres   4) Fecha DD/MM/YY               !\n\n");
        printf("         °----------------------------------------------------------°\n");
        fflush( stdin );                                                                    /* Limpiar buffer*/
        printf("         1)");                                                              /* ID*/
        gets(id_plan);
        printf("         2)");                                                              /* Nombre*/
        fflush( stdin );
        gets(nombre);
        printf("         3)");                                                              /* Numero de semetre*/
        fflush( stdin );
        scanf("%d",&num_semestres);
        correcto=true;
        do{                                                                                 /* Validacion fecha*/
            printf("         4)");
            fflush( stdin );
            scanf("%s",fecha);
            if(fecha[6]>='0' && fecha[6]<='9' && fecha[7]>='0' && fecha[7]<='9'){       /*año validacion numeros*/
                if(fecha[3]>='0' && fecha[3]<'2' && fecha[4]>='0' && fecha[4]<='9'){    /*mes validacion numeros*/
                    if(fecha[3]=='1'){
                        if(!(fecha[4]>='0' && fecha[4]<='2')){                      /*mes validacion 12*/
                            printf("         mes incorrecto\n");
                        }
                    }
                    if(fecha[0]>='0' && fecha[0]<'4' && fecha[1]>='0' && fecha[1]<='9'){ /*dia validacion numero*/
                        if(fecha[0]=='3'){
                            if(!(fecha[1]>='0' && fecha[1]<='1')){                  /*dia validacion 31*/
                                printf("         dia incorrecto\n");                        /*dia incorrecto*/
                                continue;
                            }
                        }
                        correcto=false;                                                     /*validado correctamente*/
                    }
                    else{
                        printf("         dia incorrecto\n");                                /*dia incorrecto*/
                    }
                }
                else{
                    printf("         mes incorrecto\n");                                    /*mes incorrecto numero */
                }
            }
            else{
                printf("         anio incorrecto\n");                                       /*año incorrecto numero*/
            }
        }while(correcto);
        system("cls");
        printf("         °----------------------------------------------------------°\n");      /*Muestra datos*/
        printf("         | ==============       Alta Planes       =============== |\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    ¿Son correctos los datos?  1)si 2)no:                 !\n\n");
        printf("         °----------------------------------------------------------°\n");
        printf("           ID PLAN:\t%s\n",&id_plan);
        printf("\n         Nombre:\t%s\n",&nombre);
        printf("\n         Numero De Semestres:\t%d\n",num_semestres);
        printf("\n         Fecha:\t%s\n",&fecha);
        printf("\n         Opci%cn .-",162);
        cin>>status;
    }
    system("cls");
    insert_planes(db,id_plan,nombre,num_semestres,fecha);/* Mandamos a guardar datos a la bd*/
    printf("         °----------------------------------------------------------°\n");      /*Actualizacion lista*/
    printf("         | ==============       Alta Planes         =============== |\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         !    Para dar de alta las materias del plan                !\n\n");
    printf("         !    es necesario conocer el ID de la materia.             !\n\n");
    printf("         °----------------------------------------------------------°\n");
    //printf("         Ingrese el numero de semestres del plan.-\n         ");                  /* Numero de semestres del plan*/
    //scanf("%d",&num_semestres);
    while(i<num_semestres)
    {
        printf("         Ingrese el numero de materias del semestre %d.-\n         ",i+1);                                                                                       /* para cada semestre*/
        scanf("%d",&num_materias);
        while(j<num_materias)
        {
          printf("         ID materia.-\n         ");                                             /* id de cada materia*/
          scanf("%s",&id_materia);
          insert_mtr_plan(db,id_materia,id_plan,num_semestres);                                          /* guarda las materias del plan en la db*/
          j++;
        }
        i++;
    }
    system("cls");
    printf("         °----------------------------------------------------------°\n");      /*Datos ya guardados del plan*/
    printf("         | ==============       Alta Planes       =============== |\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         !    Los datos del plan son:                            !\n\n");
    printf("         °----------------------------------------------------------°\n");
    query_planes(db,id_plan);                                                          /* selecciona los datos del plan y los imprime de la db*/
    printf("         Ingresa un 1 para continuar\n");
    scanf("%d",&status);
    system("cls");
}

int main()
{
    sqlite3 *db;                                                                            /* Base de datos en sqlite3*/
    int res;
    res=sqlite3_open("test3.db", &db);                                                       /* Se abre la db*/
    alta_materias(db);                                                                    /*Invoca alta de planes*/
    alta_planes(db);                                                                      /*Invoca alta de planes*/
    return 0;
}
