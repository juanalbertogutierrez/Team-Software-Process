/* ------------------------------------------------------------------------------------------------------------- */
/* Nombre del programa: M󤵬o Enlazamiento a la Db a C                                                          */
/* Autor: Brenda Robles Antonio, Juan Alberto Gutierrez Canto                                                                                  */
/* Matricula: 2440073, 24400063                                                                                            */
/* Fecha: 29/04/17 ultima modificacion 03/05/17                                                                           */
/*Version 0.2             */
/* Descripci󮺠Hacer un programa que cree la base de datos en .db y genere las tablas                           */
/* ------------------------------------------------------------------------------------------------------------- */
/* Lista de Contenido                    */
/* Includes                              */
/* Declaraciones Globales                */
/* Funci󮺠int callback()               */
/* Funci󮺠acceso()                     */
/* Funci󮺠create_planes()              */
/* Funci󮺠create_alumnos()             */
/* Funci󮺠create_maestros()            */
/* Funci󮺠create_materias()            */
/* Funci󮺠create_usuarios()            */
/* Funci󮺠create_cursa()               */
/* Funci󮺠create_imparte()			 */
/* Funci󮺠create_posee()				 */
/* ------------------------------------------------------------------------------------ */
/* Instrucciones de Reus󠠠                                                            */
/* En este c󤩧o se reutilizaron querys de SQL		                                    */
/* ------------------------------------------------------------------------------------ */
/*Flujo de c󤩧o:                                                                      */
/* 1.- Crear tabla planes                                                               */
/* 2.- Crear tabla alumnos                                                              */
/* 3.- Crear tabla maestros                                                             */
/* 4.- Crear tabla materias                                                             */
/* 5.- Crear tabla usuarios                                         					*/
/* 6.- Crear tabla cursa																*/
/* 7.- Crear tabla imparte																*/
/* 8.- Crear tabla posee																*/
/* Nota ya realizado el delate se debera salir del programa  o hacer select             */
/* Declaraci󮠤e librer�*/
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
/*Funciones*/
static int callback(void *data, int argc, char **argv, char **azColName)
{
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void acceso(int res,sqlite3 *db)
{
    if( res )
    {
        fprintf(stderr, "No se puede acceder a la Db: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stdout, "DB abierta exitosamente\n");
    }
}
void create_planes(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Planes("\
		"ID VARCHAR(45),"\
		"Nombre VARCHAR(45) NOT NULL,"\
		"Num_Semestre INT NOT NULL,"\
		"Fecha DATE NOT NULL,"\
		"PRIMARY KEY (`ID`));";

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_alumnos(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Alumnos ("\
		  "ID_Al VARCHAR(45),"\
		  "Nombre VARCHAR(45) NOT NULL,"\
		  "ApPaterno VARCHAR(45) NOT NULL,"\
		  "ApMaterno VARCHAR(45) NULL,"\
		  "FNacimiento DATE NOT NULL,"\
		  "Direccion VARCHAR(45) NOT NULL,"\
		  "Telefono VARCHAR(45) NOT NULL,"\
		  "Email VARCHAR(45) NOT NULL,"\
		  "ID_Plan VARCHAR(45) NOT NULL,"\
		  "Semestre INT NOT NULL,"\
		  "PRIMARY KEY (`ID_Al`),"\
		  "CONSTRAINT `ID`"\
		    "FOREIGN KEY (`ID_Plan`)"\
		    "REFERENCES `Planes` (`ID`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE);";

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_maestros(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Maestros ("\
		  "ID_Ma VARCHAR(45),"\
		  "Nombre VARCHAR(45) NOT NULL,"\
		  "ApPaterno VARCHAR(45) NOT NULL,"\
		  "ApMaterno VARCHAR(45) NOT NULL,"\
		  "FNacimiento DATE NOT NULL,"\
		  "Direccion VARCHAR(45) NOT NULL,"\
		  "Telefono VARCHAR(45) NOT NULL,"\
		  "Email VARCHAR(45) NOT NULL,"\
		  "PRIMARY KEY (`ID_Ma`));";

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_materias(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Materias ("\
		"ID_M VARCHAR(45),"\
		"Nombre VARCHAR(45) NOT NULL,"\
		"PRIMARY KEY (`ID_M`));",

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_usuarios(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Usuarios ("\
		  "ID_U VARCHAR(45),"\
		  "Nombre VARCHAR(45) NOT NULL,"\
		  "ApPaterno VARCHAR(45) NOT NULL,"\
		  "ApMaterno VARCHAR(45) NOT NULL,"\
		  "FNacimiento DATE NOT NULL,"\
		  "Direccion VARCHAR(45) NOT NULL,"\
		  "Telefono VARCHAR(45) NOT NULL,"\
		  "Email VARCHAR(45) NOT NULL,"\
		  "Tipo_Usuario VARCHAR(45) NOT NULL,"\
		  "PRIMARY KEY (`ID_U`));";

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_cursa(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Cursa ("\
		  "ID_Alumno VARCHAR(45) NOT NULL,"\
		  "ID_Materia VARCHAR(45) NOT NULL,"\
		  "Calificacion FLOAT NULL,"\
		  "PRIMARY KEY (`ID_Alumno`, `ID_Materia`),"\
		  "CONSTRAINT `ID_Al`"\
		    "FOREIGN KEY (`ID_Alumno`)"\
		    "REFERENCES `Alumnos` (`ID_Al`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE,"\
		  "CONSTRAINT `ID_M`"\
		    "FOREIGN KEY (`ID_Materia`)"\
		    "REFERENCES `Materias` (`ID_M`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE);";


    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_imparte(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Imparte ("\
		  "ID_Maestro VARCHAR(45) NOT NULL,"\
		  "ID_Materia VARCHAR(45) NOT NULL,"\
		  "Status VARCHAR(45) NOT NULL,"\
		  "PRIMARY KEY (`ID_Maestro`, `ID_Materia`),"\
		  "CONSTRAINT `ID_Ma`"\
		    "FOREIGN KEY (`ID_Maestro`)"\
		    "REFERENCES `Maestros` (`ID_Ma`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE,"\
		  "CONSTRAINT `ID_Mt`"\
		    "FOREIGN KEY (`ID_Materia`)"\
		    "REFERENCES `Materias` (`ID_M`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE);";

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
void create_posee(sqlite3 *db)
{
    char *Err = 0;
    char *sql;
    int rc;
    /* Creaccion de tabla en DB */
    sql = "CREATE TABLE IF NOT EXISTS Posee ("\
		  "ID_Materia VARCHAR(45) NOT NULL,"\
		  "ID_Plan VARCHAR(45) NOT NULL,"\
		  "Semestre INT NOT NULL,"\
		  "PRIMARY KEY (`ID_Materia`, `ID_Plan`),"\
		  "CONSTRAINT `ID_MAT`"\
		    "FOREIGN KEY (`ID_Materia`)"\
		    "REFERENCES `Materias` (`ID_M`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE,"\
		  "CONSTRAINT `ID_p`"\
		    "FOREIGN KEY (`ID_Plan`)"\
		    "REFERENCES `Planes` (`ID`)"\
		    "ON DELETE CASCADE "\
		    "ON UPDATE CASCADE);";

    /* Ejecutar los camandos de DB en SQL*/
    rc = sqlite3_exec(db, sql, callback, 0, &Err);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", Err);
        sqlite3_free(Err);
    }
    else
    {
        fprintf(stdout, "Tabla creada\n");
    }
}
int main()
{
    sqlite3 *db;
    int res;
    int opc=0;
    res = sqlite3_open("test.db",&db);
    do
    {
        printf("Menu\n");
        printf("1.- Acceso\n");
        printf("2.- Create Planes\n");
        printf("3.- Create Alumnos\n");
        printf("4.- Create Maestros\n");
        printf("5.- Create Materias\n");
        printf("6.- Create Usuarios\n");
        printf("7.- Create Cursa\n");
        printf("8.- Create Imparte\n");
        printf("9.- Create Posee\n");
        printf("10.- Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opc);
        printf("\n");
        switch(opc)
        {
            case 1:
                acceso(res,db);
                break;
            case 2:
                create_planes(db);
                break;
            case 3:
                create_alumnos(db);
                break;
            case 4:
                create_maestros(db);
                break;
            case 5:
                create_materias(db);
                break;
            case 6:
                create_usuarios(db);
                break;
            case 7:
            	create_cursa(db);
            	break;
            case 8:
            	create_imparte(db);
            	break;
            case 9:
            	create_posee(db);
            	break;
            case 10:
                printf("Esta usted saliendo del programa\n");
                break;
            default:
                printf("Error\nIngrese una opciion correcta\n");
        }
    }while(opc!=10);
    sqlite3_close(db);
    return 0;
}
