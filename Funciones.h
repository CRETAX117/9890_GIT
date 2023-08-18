/*
Libreria de Funciones y estructuras
-Colocar aqui las funciones principales
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define MAX_L 100

char usuario[MAX_L];
char contra[MAX_L];

struct fecha_G{
	char dia[10];	
	char mes[10];	
	char anio[10];	
};

struct usuario{
	char nomUser[MAX_L];
	char password[8];
};

struct persona{
	char nombre[20];
	char apellido[20];
	char cedula[10];
	struct fecha_G fecha;
	struct usuario user;
};

struct notas{
	char parcial_1[5];
	char parcial_2[5];
	char parcial_3[5];
	char promedio[5];
};

struct materia{
	char nrc[5];
	char materia[20];
	
};

struct docente{
	struct persona data_teacher;
	struct usuario user_teahcer;
	struct materia asg_teacher;
};
	
struct estudiante{
	struct persona;
};


//Funciones de correo

