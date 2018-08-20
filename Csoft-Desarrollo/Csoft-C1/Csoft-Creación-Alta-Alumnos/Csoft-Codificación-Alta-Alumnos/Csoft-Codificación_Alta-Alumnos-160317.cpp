/*=========================================================*/
/*Autor: Jesús Alberto Goiz Barrales                       */
/*Componente: AltaAlumnos                                  */
/*Fecha:16/03/17                                           */
/*Descripción:Función para dar de alto un alumno           */
/*Versión: 0.3                                             */
/*=========================================================*/

/*==========================================================*/
/* El programa contiene lo siguiente:                       */
/*static int callback (void *data,int argc, char **argv,char **az_col_name)
/*void query_alumnos(sqlite3 *db,char* id_alumno)                             */
/*void insert_alumnos(sqlite3 *db,char* id_alumno, char* nombre, char* ap_paterno, char* ap_materno, char* fecha_nac, char* direccion, char* telefono, char* email,char* semestre,char* id_plan)*/
/*static int print_archivo(void *data,int argc, char **argv,char *az_col_name)*/
/*void actualizar_planes(sqlite3 *db)*/
/*void alta_alumnos(sqlite3 *db)*/
/*int main()*/
/*==========================================================*/
/*Funcion que tendra el menu de alumnos para poder ingresar
los datos de este mismo de una manera ordenada y
almacenarlos en la base de datos con el respctivo Id de
cada plan que se tenga previamente registrado           */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sqlite3.h"                                  /*Interaccion base de datos*/

using namespace std;
FILE *pfile;

/***Esta función se encarga de imprimir los datos encontrados en la base de datos***/
static int callback (void *data,int argc, char **argv,char **az_col_name)
{
    int i;
    for(i=0;i<argc;i++){
         fprintf(pfile,"%s\t",argv[i]);                                  /* Imprime en el archivo txt los planes que estan disponibles en la bd*/
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
    sql="SELECT * FROM ALUMNOS where Id_Al=@Id_A;";                     /* Selecciona a los alumnas con un id especifico sentencia sql*/
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
    if (step == SQLITE_ROW) {                                           /* indica el resultado de la instrucción sql, valores del maestro*/

        printf("\t\t Nombre: %s %s %s\n", sqlite3_column_text(res, 1),sqlite3_column_text(res, 2),sqlite3_column_text(res, 3));
        printf("\t\t Fecha: %s\n", sqlite3_column_text(res, 4));
        printf("\t\t Direccion: %s\n", sqlite3_column_text(res, 5));
        printf("\t\t Telefono: %s\n", sqlite3_column_text(res, 6));
        printf("\t\t Email: %s\n", sqlite3_column_text(res, 7));
        printf("\t\t ID Alumno: %s\n", sqlite3_column_text(res, 0));
        printf("\t\t Plan: %s\n", sqlite3_column_text(res, 8));
        printf("\t\t Semestre:\%s\n", sqlite3_column_text(res, 9));

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
        printf("\t\t Valores del alumno guardados correctamente.\n");/* Cambia los identificador por los valores*/
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
        printf("\t\t Datos correctos %s\n", sqlite3_column_text(res, 0));  /* Imprime el resultado de la consulta*/
    }
}

static int print_archivo(void *data,int argc, char **argv,char *az_col_name)
{
    int i;
    for(i=0;i<argc;i++){
     fprintf(pfile,"%s\t",argv[i]);                                  /* Imprime en el archivo txt con los planes disponibles en la bd*/
    }
  fprintf(pfile,"\n");
    return 0;
}

/***Esta función se encarga de actualizar el doucmento Planes_Disponibles.txt**/

void actualizar_planes(sqlite3 *db){
    char *sql;
    char *err=0;
    int rc;
    const char*data;
    pfile=fopen("Planes_Disponibles.txt","w");
    fprintf(pfile,"-----   PLANES DISPONIBLES PARA ALUMNOS   -------\nID\tNombre\t\tNumeroSemestres\tFecha\n");
    sql="SELECT * from PLANES";
    rc=sqlite3_exec(db,sql,callback,(void*)data,&err);
    if(rc!=SQLITE_OK){
        printf("SQL error %s\n",err);
    }
    else{
        printf("\t\t Nueva lista disponible\n");
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
     printf("\t\to----------------------------------------------------------o\n");
     printf("\t\t| ================   Alta de Alumnos  ===================  |\n");
     printf("\t\to----------------------------------------------------------o\n");
     printf("\t\to----------------------------------------------------------o\n");
     printf("\t\t|   Para dar de alto un alumno necesitas                   |\n");
     printf("\t\t|   1)Nombres              2)Apellido Paterno              |\n");
     printf("\t\t|   3)Apellido Materno     4)Fecha de nacimiento.          |\n");
     printf("\t\t|   5)Direcci%cn            6)Correo Electr%cnico.           |\n",162,162);
     printf("\t\t|   7)Tel%cfono             8)ID-Curp                       |\n",130);
     printf("\t\t|   9)Semestre                                             |\n");
     printf("\t\t|   Presiona una tecla para agregar los datos:             |\n");
     printf("\t\to----------------------------------------------------------o\n");
     fflush( stdin );
     printf("\t\t 1) ");
     scanf("\t\t%[^\n]",nombre);
     fflush( stdin );
     printf("\t\t 2) ");
     scanf("%s",ap_paterno);
     fflush( stdin );
     printf("\t\t 3) ");
     fflush( stdin );
     scanf("%s",ap_materno);
     correcto=true;

     do{
      printf("\t\t 4) ");
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


     printf("\t\t 5) ");
     fflush( stdin );
     scanf("%[^\n]",direccion);

    do{                                                                                 /* validacion del correo*/
        printf("\t\t 6) ");
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

     printf("\t\t 7) ");
     fflush( stdin );
     scanf("%[0-9]",&telefono);
     correcto=true;

     printf("\t\t 8) ");
     fflush( stdin );
     scanf("%s",&id_alumno);

     printf("\t\t 9) ");
     fflush( stdin );
     scanf("%s",&semes_alumno);

     system("cls");

        printf("\t\to---------------------------------------------------------o\n");
        printf("\t\t| ================   Alta de Alumnos  ====================|\n");
        printf("\t\to---------------------------------------------------------o\n");
        printf("\t\to---------------------------------------------------------o\n");
        printf("\t\t|                                                         | \n");
        printf("\t\t|   Son correctos los datos?  1)si 2)no:                  | \n");
        printf("\t\to---------------------------------------------------------o\n");
        printf("\t\t Nombre: %s %s %s\n",&nombre,&ap_paterno,&ap_materno);
        printf("\t\t Nacimiento: %s\n",&f_nacimiento);
        printf("\t\t Direcci%cn: %s\n",162,&direccion);
        printf("\t\t Tel%cfono: %s\n",130,&telefono);
        printf("\t\t Email: %s\n",&correo);
        printf("\t\t CURP: %s\n",&id_alumno);
        printf("\t\t Semestre %s\n",&semes_alumno);
        printf("\n\t\t Opci%cn .-",162);
        cin>>status;
   }

    system("cls");

    printf("\t\to---------------------------------------------------------o\n");
    printf("\t\t| ================   Alta de Alumnos  =================== |\n");
    printf("\t\to---------------------------------------------------------o\n");
    printf("\t\to---------------------------------------------------------o\n");
    printf("\t\t|   Para dar de alta al alumno es                         |\n");
    printf("\t\t|   es necesario conocer el ID del plan     .             |\n");
    printf("\t\t|   La lista est%c en la carpeta del programa.             |\n",160);
    printf("\t\t|   Desea actualizar la lista?  1)si 2)no:                |\n");
    printf("\t\to---------------------------------------------------------o\n");
    printf("\n\t\t Opci%cn .-",162);
    cin>>status;
    if(status == 1){
        actualizar_planes(db);                                                             /*Se actualiza el txt con las materias de la db*/
    }
    int cant_planes=1;
    while(cant_planes--){
        printf("\n\t\t Ingrese el No. del plan ID .-  ");                                             /*id del plan*/
        scanf("%s",&id_plan);
        printf("\t\t Es correcto el plan asingnado 1)si 2)no\n\t\t ");                   /*definicion si es correcto el id del plan o no*/ cin>>status;
    }

    insert_alumnos(db,id_alumno,nombre,ap_paterno,ap_materno,f_nacimiento,direccion,telefono,correo,semes_alumno,id_plan);/* Mandamos a guardar datos a la bd*/
    system("cls");
    printf("\t\to---------------------------------------------------------o\n");
    printf("\t\t| ================   Alta de Alumnos  ====================|\n");
    printf("\t\to---------------------------------------------------------o\n");
    printf("\t\to---------------------------------------------------------o\n");
    printf("\t\t|   Los datos del alumno son:                             |\n\n");
    printf("\t\to---------------------------------------------------------o\n");
    query_alumnos(db,id_alumno);                                                          /* selecciona los datos del Alumno y los imprime de la db*/
    printf("\t\t Ingresa 1 para continuar\n");
    printf("\n\t\t Opci%cn .-",162);
    scanf("%d",&status);
    system("cls");

}


int main()
{
    sqlite3 *db;
    int res;

    res=sqlite3_open("test8.db",&db);

    alta_alumnos(db);

    return 0;
}
