/*=========================================================*/
/*Autor: Csoft                  */
/*Componente: Libreria altas                                  */
/*Fecha:08/05/17                                           */
/*Descripción:librerias de altas.           */
/*Versión: 0.1                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/*static int callback (void *data,int argc, char **argv,char **az_col_name)
/*void query_alumnos(sqlite3 *db,char* id_alumno)                             */
/*void insert_alumnos(sqlite3 *db,char* id_alumno, char* nombre, char* ap_paterno, char* ap_materno, char* fecha_nac, char* direccion, char* telefono, char* email,char* semestre,char* id_plan)*/
/*static int print_archivo(void *data,int argc, char **argv,char *az_col_name)*/
/*void actualizar_planes(sqlite3 *db)*/
/*void alta_alumnos(sqlite3 *db)*/
/*static int callback()                */
/*void query_planes()                  */
/*void insert_mtr_plan()               */
/*void insert_materias()               */
/*void insert_planes()                 */
/*static int print_archivo()           */
/*void alta_materias()                 */
/*void alta_planes()                   */
/* void query_maestros(sqlite3 *db,char* id_maestro)                              */
/* void insert_mtr_mst(sqlite3 *db,int id_materia, char* id_maestro, int status)  */
/* void insert_maestros(sqlite3 *db,char* id_maestro, char* nombre, char* ap_paterno, char* ap_materno, char* fecha_nac, char* direccion, char* telefono, char* email)  */
/* void actualizar_materias(sqlite3 *db)  */
/* void alta_maestros(sqlite3 *db)  */
/*==========================================================*/
/*Funcion que tendra el menu de alumnos para poder ingresar
los datos de este mismo de una manera ordenada y
almacenarlos en la base de datos con el respctivo Id de
cada plan que se tenga previamente registrado           */
#include "sqlite3.h"                                  /*Interaccion base de datos*/
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

/***Esta función se encarga de buscar los valores del alumno en la base de datos***/
void query_alumnos(sqlite3 *db,char* id_alumno)
{
    char *sql;                                                          /*Para la sentencia sql */
    char *err=0;                                                        /*Para el mensaje de error de la sentencia sql */
    int rc;
    sqlite3_stmt *res;
    sql="SELECT * FROM ALUMNOS where Id_Al LIKE @Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
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
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/
        printf("\t Nombre: %s %s %s\n", sqlite3_column_text(res, 1),sqlite3_column_text(res, 2),sqlite3_column_text(res, 3));
        printf("\t Fecha: %s\n", sqlite3_column_text(res, 4));
        printf("\t Direccion: %s\n", sqlite3_column_text(res, 5));
        printf("\t Telefono: %s\n", sqlite3_column_text(res, 6));
        printf("\t Email: %s\n", sqlite3_column_text(res, 7));
        printf("\t ID Alumno: %s\n", sqlite3_column_text(res, 0));
        printf("\t Plan: %s\n", sqlite3_column_text(res, 8));
        printf("\t Semestre:\%s\n", sqlite3_column_text(res, 9));

    }
    sqlite3_finalize(res);                                              /* Finaliza el objeto creado*/
}

void insert_alumnos(sqlite3 *db,char* id_alumno, char* nombre, char* ap_paterno, char* ap_materno, char* fecha_nac, char* direccion, char* telefono, char* email,char* semestre,char* id_plan){
    char *sql;
    char *err=0;
    int rc;
    sqlite3_stmt *res;                                                  /* Inserta todos los valores del alumno sentncia sql*/
    sql="INSERT INTO ALUMNOS (Id_Al, Nombre, ApPaterno, ApMaterno, FNacimiento, Direccion, Telefono, Email,ID_Plan,Semestre) VALUES (@Id_A,@nom,@ap_p,@ap_m,@fec,@dir,@tel,@ema,@plan,@sem);";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Prepara la sentencia sql*/
    if(rc!=SQLITE_OK){
        printf("SQL error %s\n",err);                                   /* Imprime el mensaje de error*/
    }
    else{
        printf("\t Valores del alumno guardados correctamente.\n");/* Cambia los identificador por los valores*/
        int idm = sqlite3_bind_parameter_index(res, "@Id_A");           /* Busca el lugar del identificador*/
        int nom = sqlite3_bind_parameter_index(res, "@nom");
        int ap_p = sqlite3_bind_parameter_index(res, "@ap_p");
        int ap_m = sqlite3_bind_parameter_index(res, "@ap_m");
        int fec = sqlite3_bind_parameter_index(res, "@fec");
        int dir = sqlite3_bind_parameter_index(res, "@dir");
        int tel = sqlite3_bind_parameter_index(res, "@tel");
        int ema = sqlite3_bind_parameter_index(res, "@ema");
        int plan= sqlite3_bind_parameter_index(res, "@plan");
        int sem =  sqlite3_bind_parameter_index(res, "@sem");

        sqlite3_bind_text(res, idm, id_alumno,40,SQLITE_STATIC);       /* cambia el valor por elidenitficador */
        sqlite3_bind_text(res, nom, nombre,40,SQLITE_STATIC);
        sqlite3_bind_text(res, ap_p, ap_paterno,40,SQLITE_STATIC);
        sqlite3_bind_text(res, ap_m, ap_materno,40,SQLITE_STATIC);
        sqlite3_bind_text(res, fec, fecha_nac,40,SQLITE_STATIC);
        sqlite3_bind_text(res, dir, direccion,40,SQLITE_STATIC);
        sqlite3_bind_text(res, tel, telefono,40,SQLITE_STATIC);
        sqlite3_bind_text(res, ema, email,40,SQLITE_STATIC);
        sqlite3_bind_text(res, plan, id_plan,40,SQLITE_STATIC);
        sqlite3_bind_text(res, sem, semestre,40,SQLITE_STATIC);

    }
    int step = sqlite3_step(res);/* */
    if (step == SQLITE_ROW) {
        printf("\t Datos correctos %s\n", sqlite3_column_text(res, 0));  /* Imprime el resultado de la consulta*/
    }
}

/***Esta función se encarga de actualizar el doucmento Planes_Disponibles.txt**/
void actualizar_planes(sqlite3 *db){
    char *sql;
    char *err=0;
    int rc;
    const char*data;
    pfile=fopen("Planes_Disponibles.txt","w");
    fprintf(pfile,"-----   PLANES DISPONIBLES PARA ALUMNOS   -------\nID\tNombre\tNumeroSemestres\tFecha\n");
    sql="SELECT * from PLANES";
    rc=sqlite3_exec(db,sql,print_archivo,(void*)data,&err);
    if(rc!=SQLITE_OK){
        printf("SQL error %s\n",err);
    }
    else{
        printf("\t Nueva lista disponible\n");
    }
    fclose(pfile);
}

/****Esta función realiza un insert en la tabla Alumnos en la base de datos****/
void alta_alumnos(sqlite3 *db)
{
     char nombre[40];
     char ap_materno[40];
     char ap_paterno[40];
     char f_nacimiento[40];
     char direccion[40];
     char telefono[40];
     char correo[40];
     char id_alumno[40];
     char semes_alumno[40];

     char id_plan[40];
     int status=2;
     bool correcto=false;
while(status != 1){
     system("cls");
     printf("\to----------------------------------------------------------o\n");
     printf("\t| ================   Alta de Alumnos  ===================  |\n");
     printf("\to----------------------------------------------------------o\n");
     printf("\to----------------------------------------------------------o\n");
     printf("\t|   Para dar de alto un alumno necesitas                   |\n");
     printf("\t|   1)Nombres              2)Apellido Paterno              |\n");
     printf("\t|   3)Apellido Materno     4)Fecha de nacimiento.          |\n");
     printf("\t|   5)Direcci%cn            6)Correo Electr%cnico.           |\n",162,162);
     printf("\t|   7)Tel%cfono             8)ID-Curp                       |\n",130);
     printf("\t|   9)Semestre                                             |\n");
     printf("\t|   Presiona una tecla para agregar los datos:             |\n");
     printf("\to----------------------------------------------------------o\n");
     fflush( stdin );
     printf("\t 1) ");
     scanf("\t%[^\n]",nombre);
     fflush( stdin );
     printf("\t 2) ");
     scanf("%s",ap_paterno);
     fflush( stdin );
     printf("\t 3) ");
     fflush( stdin );
     scanf("%s",ap_materno);
     correcto=true;

     do{
      printf("\t 4) ");
      scanf("%s",&f_nacimiento);

            if(f_nacimiento[6]>='0' && f_nacimiento[6]<='9' && f_nacimiento[7]>='0' && f_nacimiento[7]<='9'){       /*año validacion numeros*/
                if(f_nacimiento[3]>='0' && f_nacimiento[3]<'2' && f_nacimiento[4]>='0' && f_nacimiento[4]<='9'){    /*mes validacion numeros*/
                    if(f_nacimiento[3]=='1'){
                        if(!(f_nacimiento[4]>='0' && f_nacimiento[4]<='2')){                      /*mes validacion 12*/
                            printf("\t Mes Incorrecto\n");
                        }
                    }

                    if(f_nacimiento[0]>='0' && f_nacimiento[0]<'4' && f_nacimiento[1]>='0' && f_nacimiento[1]<='9')
                        { /*dia validacion numero*/
                        if(f_nacimiento[0]=='3'){
                            if(!(f_nacimiento[1]>='0' && f_nacimiento[1]<='1')){                  /*dia validacion 31*/
                                printf("\t D%ca Incorrecto\n",161);                        /*dia incorrecto*/
                                continue;
                              }
                          }
                        correcto=false;                                                     /*validado correctamente*/
                        }
                    else{
                        printf("\t D%ca Incorrecto\n",161);                                /*dia incorrecto*/
                    }
                }
                else{
                    printf("\t Mes Incorrecto\n");                                    /*mes incorrecto numero */
                    }
            }
            else{
                printf("\t A%co Incorrecto\n",164);                                       /*año incorrecto numero*/
                 }
        }while(correcto);


     printf("\t 5) ");
     fflush( stdin );
     scanf("%[^\n]",direccion);

    do{                                                                                 /* validacion del correo*/
        printf("\t 6) ");
        fflush( stdin );
        scanf("%s",&correo);
        for(int i=0;i<40;i++)
            {
                if(correo[i]== '@')
                {                                                         /* si tiene @ es correcto*/
                    correcto=false;
                }
            }
            if(correcto){
                printf("\t Correo Incorrecto\n");                                      /* no tiene @ es incorrecto*/
            }
        }while(correcto);

     printf("\t 7) ");
     fflush( stdin );
     scanf("%[0-9]",&telefono);
     correcto=true;

     printf("\t 8) ");
     fflush( stdin );
     scanf("%s",&id_alumno);

     printf("\t 9) ");
     fflush( stdin );
     scanf("%s",&semes_alumno);

     system("cls");

        printf("\to---------------------------------------------------------o\n");
        printf("\t| ================   Alta de Alumnos  ====================|\n");
        printf("\to---------------------------------------------------------o\n");
        printf("\to---------------------------------------------------------o\n");
        printf("\t|                                                         | \n");
        printf("\t|   Son correctos los datos?  1)si 2)no:                  | \n");
        printf("\to---------------------------------------------------------o\n");
        printf("\t Nombre: %s %s %s\n",&nombre,&ap_paterno,&ap_materno);
        printf("\t Nacimiento: %s\n",&f_nacimiento);
        printf("\t Direcci%cn: %s\n",162,&direccion);
        printf("\t Tel%cfono: %s\n",130,&telefono);
        printf("\t Email: %s\n",&correo);
        printf("\t CURP: %s\n",&id_alumno);
        printf("\t Semestre %s\n",&semes_alumno);
        printf("\n\t Opci%cn .-",162);
        cin>>status;
   }

    system("cls");

    printf("\to---------------------------------------------------------o\n");
    printf("\t| ================   Alta de Alumnos  =================== |\n");
    printf("\to---------------------------------------------------------o\n");
    printf("\to---------------------------------------------------------o\n");
    printf("\t|   Para dar de alta al alumno es                         |\n");
    printf("\t|   es necesario conocer el ID del plan     .             |\n");
    printf("\t|   La lista est%c en la carpeta del programa.             |\n",160);
    printf("\t|   Desea actualizar la lista?  1)si 2)no:                |\n");
    printf("\to---------------------------------------------------------o\n");
    printf("\n\t Opci%cn .-",162);
    cin>>status;
    if(status == 1){
        actualizar_planes(db);                                                             /*Se actualiza el txt con las materias de la db*/
    }
    int cant_planes=1;
    while(cant_planes--){
        printf("\n\t Ingrese el No. del plan ID .-  ");                                             /*id del plan*/
        scanf("%s",&id_plan);
        printf("\t Es correcto el plan asingnado 1)si 2)no\n\t ");                   /*definicion si es correcto el id del plan o no*/ cin>>status;
    }

    insert_alumnos(db,id_alumno,nombre,ap_paterno,ap_materno,f_nacimiento,direccion,telefono,correo,semes_alumno,id_plan);/* Mandamos a guardar datos a la bd*/
    system("cls");
    printf("\to---------------------------------------------------------o\n");
    printf("\t| ================   Alta de Alumnos  ====================|\n");
    printf("\to---------------------------------------------------------o\n");
    printf("\to---------------------------------------------------------o\n");
    printf("\t|   Los datos del alumno son:                             |\n\n");
    printf("\to---------------------------------------------------------o\n");
    query_alumnos(db,id_alumno);                                                          /* selecciona los datos del Alumno y los imprime de la db*/
    printf("\t Ingresa 1 para continuar\n");
    printf("\n\t Opci%cn .-",162);
    scanf("%d",&status);
    system("cls");

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
    sql="SELECT ID_Materia,ID_Plan,Semestre FROM POSEE where ID_Plan LIKE @Id_P;";  /* Instruccion sql para la seleccion de materias de cada plan en tabla POSEE*/
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
    sql="INSERT INTO PLANES (ID, Nombre, Num_Semestre, Fecha) VALUES (@Id_P,@nom,@sem,@dat);";
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

/***Esta función se encarga de buscar los valores del maestro en la base de datos***/
void query_maestros(sqlite3 *db,char* id_maestro){
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

}

/***Esta función se encarga de insertar los valores del maestro y materias  en la base de datos***/
void insert_mtr_mst(sqlite3 *db,int id_materia, char* id_maestro, int status){
    char *sql;
    char *err=0;
    int rc;
    sqlite3_stmt *res;
    sql="INSERT INTO IMPARTE (ID_Maestro, ID_Materia, Status) VALUES (@Id_M,@Id_T,@status);";/* Inserta los en la tabla imparte los tres valores de esta tabla*/
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Prepara la sentencia sql*/
    if(rc!=SQLITE_OK){
        printf("         IMPARTE-SQL error %s\n",err);                  /* Imprime el error de la sentencia*/
    }
    else{
        printf("         Valores ingresados correctamente.\n");         /* Cambia los identificades por valores en la sentencia*/
        int idm = sqlite3_bind_parameter_index(res, "@Id_M");           /* busca en donde esta el identificador*/
        int idt = sqlite3_bind_parameter_index(res, "@Id_T");
        int idstatus = sqlite3_bind_parameter_index(res, "@status");
        sqlite3_bind_text(res, idm, id_maestro,40,SQLITE_STATIC);       /* Cambia el identificador por un valor text*/
        sqlite3_bind_int(res, idt, id_materia);                         /* Cambia el identificador por un valor int*/
        sqlite3_bind_text(res, idstatus,(status==1?"IMPARTE":"NO IMPARTE"),40,SQLITE_STATIC);/* cambia el identificaro a imparte si status es igual a 1 si no a no imparte*/
    }
    int step = sqlite3_step(res);                                       /* Realiza la consulta sql*/
    if (step == SQLITE_ROW) {

        printf("         %s\n", sqlite3_column_text(res, 0));           /* Imprime datos devueltos de la consulta*/

    }
}

/***Esta función se encarga de insertar los valores del maestro en la base de datos***/
void insert_maestros(sqlite3 *db,char* id_maestro, char* nombre, char* ap_paterno, char* ap_materno, char* fecha_nac, char* direccion, char* telefono, char* email){
    char *sql;
    char *err=0;
    int rc;
    sqlite3_stmt *res;                                                  /* Inserta todos los valores de maestro sentncia sql*/
    sql="INSERT INTO MAESTROS (Id_Ma, Nombre, ApPaterno, ApMaterno, FNacimiento, Direccion, Telefono, Email) VALUES (@Id_M,@nom,@ap_p,@ap_m,@fec,@dir,@tel,@ema);";
    rc=sqlite3_prepare_v2(db,sql,-1,&res,0);                            /* Prepara la sentencia sql*/
    if(rc!=SQLITE_OK){
        printf("SQL error %s\n",err);                                   /* Imprime el mensaje de error*/
    }
    else{
        printf("         Valores de maesto guardados correctamente.\n");/* Cambia los identificador por los valores*/
        int idm = sqlite3_bind_parameter_index(res, "@Id_M");           /* Busca el lugar del identificador*/
        int nom = sqlite3_bind_parameter_index(res, "@nom");
        int ap_p = sqlite3_bind_parameter_index(res, "@ap_p");
        int ap_m = sqlite3_bind_parameter_index(res, "@ap_m");
        int fec = sqlite3_bind_parameter_index(res, "@fec");
        int dir = sqlite3_bind_parameter_index(res, "@dir");
        int tel = sqlite3_bind_parameter_index(res, "@tel");
        int ema = sqlite3_bind_parameter_index(res, "@ema");
        sqlite3_bind_text(res, idm, id_maestro,40,SQLITE_STATIC);       /* cambia el valor por elidenitficador */
        sqlite3_bind_text(res, nom, nombre,40,SQLITE_STATIC);
        sqlite3_bind_text(res, ap_p, ap_paterno,40,SQLITE_STATIC);
        sqlite3_bind_text(res, ap_m, ap_materno,40,SQLITE_STATIC);
        sqlite3_bind_text(res, fec, fecha_nac,40,SQLITE_STATIC);
        sqlite3_bind_text(res, dir, direccion,40,SQLITE_STATIC);
        sqlite3_bind_text(res, tel, telefono,40,SQLITE_STATIC);
        sqlite3_bind_text(res, ema, email,40,SQLITE_STATIC);
    }
    int step = sqlite3_step(res);/* */
    if (step == SQLITE_ROW) {
        printf("         correcto %s\n", sqlite3_column_text(res, 0));  /* Imprime el resultado de la consulta*/
    }
}

/***Esta función se encarga de actualizar el doucmento Materias_Disponibles.txt que se encuantra en la carpta del proyecto***/
void actualizar_materias(sqlite3 *db){
    char *sql;
    char *err=0;
    int rc;
    const char*data;
    pfile=fopen("Materias_Disponibles.txt","w");                        /* abrimos el archivo en modo edicion*/
    sql="SELECT * from materias;";                                      /* Instruccion sql para seleccionar todas las materias*/
    fprintf(pfile,"-----   MATERIAS DISPONIBLES PARA MAESTROS   -----\nID\tNOMBRE\n");/* Titulo en el documento txt*/
    rc=sqlite3_exec(db,sql,print_archivo,(void*)data,&err);             /* realiza la consulta sql*/
    if(rc!=SQLITE_OK){
        printf("         Materias-SQL error %s\n",err);
    }
    else{
        printf("         Nueva lista disponible\n");
    }
    fclose(pfile);
}

/***Esta función se encarga de presentar alta de maestros,
contine todo el proceso y re direcciona hacia las funciones de insercion y select con la base de datos***/
void alta_maestros(sqlite3 *db){
    char nombre[40];
    char ap_paterno[40];
    char ap_materno[40];
    char fecha_nac[40];
    char direccion[40];
    char telefono[40];
    char email[40];
    char id_maestro[40];
    int cant_materias;
    int cant_mat_dar;
    int id_materia;
    int status=2;
    bool correcto=false;
    while(status != 1){                                                                     /* Pide datos haste que esten correctos aprobados por el usuario*/
        system("cls");
        printf("         °----------------------------------------------------------°\n");  /*Menu Alta maestros*/
        printf("         | ==============       Alta Maestros       =============== |\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    Introduce los siguientes datos:                       !\n\n");
        printf("         !    1) Nombre             2) Apellido Paterno             !\n\n");
        printf("         !    3) Apellido Materno   4) Fecha Nacimiento DD/MM/YY    !\n\n");
        printf("         !    5) Direccion          6) Telefono                     !\n\n");
        printf("         !    7) Email              8)RFC                           !\n\n");
        printf("         °----------------------------------------------------------°\n");
        fflush( stdin );                                                                    /* Limpiar buffer*/
        printf("         1)");                                                              /* Nombre*/
        scanf("%[^\n]", nombre);
        printf("         2)");                                                              /* apellido paterno*/
        fflush( stdin );
        scanf("%s",ap_paterno);
        printf("         3)");                                                              /* apellido materno*/
        fflush( stdin );
        scanf("%s",ap_materno);
        correcto=true;
        do{                                                                                 /* Validacion fecha*/
            printf("         4)");
            fflush( stdin );
            scanf("%s",fecha_nac);
            if(fecha_nac[6]>='0' && fecha_nac[6]<='9' && fecha_nac[7]>='0' && fecha_nac[7]<='9'){       /*año validacion numeros*/
                if(fecha_nac[3]>='0' && fecha_nac[3]<'2' && fecha_nac[4]>='0' && fecha_nac[4]<='9'){    /*mes validacion numeros*/
                    if(fecha_nac[3]=='1'){
                        if(!(fecha_nac[4]>='0' && fecha_nac[4]<='2')){                      /*mes validacion 12*/
                            printf("         mes incorrecto\n");
                        }
                    }
                    if(fecha_nac[0]>='0' && fecha_nac[0]<'4' && fecha_nac[1]>='0' && fecha_nac[1]<='9'){ /*dia validacion numero*/
                        if(fecha_nac[0]=='3'){
                            if(!(fecha_nac[1]>='0' && fecha_nac[1]<='1')){                  /*dia validacion 31*/
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
        printf("         5)");                                                              /* direccion*/
        fflush( stdin );
        scanf("%[^\n]",direccion);
        printf("         6)");                                                              /* telefono*/
        fflush( stdin );
        scanf("%[0-9]",telefono);                                                           /* solamente acepta los primeros numeros*/
        correcto=true;
        do{                                                                                 /* validacion del correo*/
            printf("         7)");
            fflush( stdin );
            scanf("%s",email);
            for(int i=0;i<40;i++){
                if(email[i]== '@'){                                                         /* si tiene @ es correcto*/
                    correcto=false;
                }
            }
            if(correcto){
                printf("         email incorrecto\n");                                      /* no tiene @ es incorrecto*/
            }
        }while(correcto);
        printf("         8)");                                                              /* RFC*/
        fflush( stdin );
        scanf("%s",&id_maestro);
        system("cls");
        printf("         °----------------------------------------------------------°\n");      /*Muestra datos*/
        printf("         | ==============       Alta Maestros       =============== |\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         !    ¿Son correctos los datos?  1)si 2)no:                 !\n\n");
        printf("         °----------------------------------------------------------°\n");
        printf("         Nombre:\t%s %s %s\n",&nombre,&ap_paterno,&ap_materno);
        printf("\n         Nacimiento:\t%s\n",&fecha_nac);
        printf("\n         Direccion:\t%s\n",&direccion);
        printf("\n         Telefono:\t%s\n",&telefono);
        printf("\n         Email:\t%s\n",&email);
        printf("\n         RFC:\t%s\n",&id_maestro);
        printf("\n         Opci%cn .-",162);
        cin>>status;
    }
    system("cls");
    insert_maestros(db,id_maestro,nombre,ap_paterno,ap_materno,fecha_nac,direccion,telefono,email);/* MAndamos a guardar datos a la bd*/
    printf("         °----------------------------------------------------------°\n");      /*Actualizacion lista*/
    printf("         | ==============       Alta Maestros       =============== |\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         !    Para dar de alta las materias del maestro             !\n\n");
    printf("         !    es necesario conocer el ID de la materia.             !\n\n");
    printf("         !    La lista est%c en la carpeta del programa.             !\n\n",160);
    printf("         !    ¿Desea actualizar la lista?  1)si 2)no:               !\n\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         Opci%cn .-",162);
    cin>>status;
    if(status == 1){
        actualizar_materias(db);                                                                /* Se actualiza el txt con las materias de la db*/
    }
    printf("         Ingrese el numero de materias del maestro.-\n         ");                  /* Numero de materias del maestro*/
    scanf("%d",&cant_materias);
    while(cant_materias--){                                                                     /* para cada materia*/
        printf("         ID materia.-\n         ");                                             /* id de cada materia*/
        scanf("%d",&id_materia);
        printf("         ¿Esta impatiendo la materia? 1)si 2)no\n         ");                   /* definicion si imparte la materia o no*/
        cin>>status;
        insert_mtr_mst(db,id_materia,id_maestro,status);                                        /* guarda las materias del maestro en la db*/
    }
    system("cls");
    printf("         °----------------------------------------------------------°\n");      /*Datos ya guardados del maestro*/
    printf("         | ==============       Alta Maestros       =============== |\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         °----------------------------------------------------------°\n");
    printf("         !    Los datos del maestro son:                            !\n\n");
    printf("         °----------------------------------------------------------°\n");
    query_maestros(db,id_maestro);                                                          /* selecciona los datos del maestro y los imprime de la db*/
    printf("         Ingresa una 1 para continuar\n");
    scanf("%d",&status);
    system("cls");
}
