/*
Libreria de Funciones y estructuras
-Colocar aqui las funciones principales
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include "Portadas.h"
#define MAX_L 100

char usuario[MAX_L];
char contra[MAX_L];
char cedula[9];
char name1[MAX_L];
char name2[MAX_L];

void limpiarCadena(char cadena[MAX_L], int tam){
	// Llena la cadena con caracteres nulos para borrar su contenido
    for (int i = 0; i < tam; i++) {
        cadena[i] = '\0';
    }
}

int numeros(char a[]){
	int i;
	int error = 0;
	while(a[i] != '\0'){
		if(a[i] < '0' || a[i] > '9'){
			error = 1;
			break;
		}
		i++;
	}
	return error;
}

int letras(char a[]){
	int i;
	int error = 0;
	while(a[i] != '\0'){
		if((a[i] < 'A' || a[i] > 'Z') && (a[i] < 'a' || a[i] > 'z') && (a[i] != ' ')){
			error = 1;
			break;
		}
		i++;
	}	
	return error;
}

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

void signInUser(){
	gotoxy(27, 15); cin.getline(usuario, 60, '\n'); fflush(stdin);
}

void signInPass(){
	gotoxy(27, 20); cin.getline(contra, 60, '\n'); fflush(stdin);
}


bool verificar_cedula(int vect[]){
	int i,r,s=0,s1=0,st=0;
	for(i=0;i<10;i=i+2){
		r= vect[i]*2;
		if(r>9)
		r-=9;
		s+=r;
	}


	for(i=1;i<9;i=i+2){
		s1+=vect[i];
	}
	st=10-((s+s1)%10);
		if(st==10)
		st=0;
		if(vect [9]==st)
		return true;
		else
		return false;
}
//Ingreso de la cedula
void in_cedula(){
	mostrarCursor();
	gotoxy(37,8); cin.getline(cedula, 10, '\n'); fflush(stdin); 
	ocultarCursor();
}

int cedula_check(){
	char solonum[MAX_L] = {"SOLO INGRESE NUMEROS"};
	char verif[MAX_L] = {"CEDULA NO VALIDA"};
	int error=0, validacion, tam;
	
	error=numeros(cedula);
	tam = strlen(cedula);
	if(error==1){
		error=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(45, 11, 28, 5);
		printf("\a");
		centrarTexto(solonum, 14);
		CLS(1700);
		return 1;
	}
	int cedint[9]; // Declaración de una matriz de enteros para almacenar los dígitos
    int contador = 0;

    // Convertir cada dígito de la cadena en un entero y almacenarlo en la matriz
    for (int i = 0; i < 9; i++) {
        if (cedula[i] >= '0' && cedula[i] <= '9') {
            cedint[contador] = cedula[i] - '0'; // Convertir carácter a entero
            contador++;
        }
    }
 
	validacion=verificar_cedula(cedint);
	if(validacion){
		validacion=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(46, 11, 26, 5);
		printf("\a");
		centrarTexto(verif , 14);
		CLS(1700);
		return 2;
	}else{
		return 3;
	}
}


//Ingreso nombres
void in_names(){
	char caracter;
    int indice = 0;
	mostrarCursor();
	gotoxy(37, 13); //cin.getline(name1, 15, '\n'); //cin.getline(name2, 15, '\n'); fflush(stdin);
	scanf("%99s %99[^\n]", name1, name2);
	ocultarCursor(); 
}


//-----------------------
//STRUCT VALIDACION CORREO
/*struct Apellidos {
    char apellidopaterno[20];
    char apellidomaterno[20];
};

struct Nombres {
    char primernombre[20];
    char segundonombre[20];
};

struct Correo {
    char correoinst[50];
    struct Nombres nombres;
    struct Apellidos apellidos;
};

struct Secuencia {
    int numapellidos;
    struct Apellidos apellidos;
};

struct Estudiante {
    struct Correo correo;
    struct Nombres nombres;
    struct Apellidos apellidos;
    struct Secuencia secuencia;
};*/

//Funciones de correo
/*void mayus_a_minus(char palabra[], int n) {
    for (int i = 0; i < n; i++) {
        if (palabra[i] >= 'A' && palabra[i] <= 'Z') {
            palabra[i] = palabra[i] - 'A' + 'a';
        }
    }
}

void ingresarApellido(struct Apellidos *apellidos) {
    printf("Ingrese su Apellido Paterno: ");
    scanf("%19s", apellidos->apellidopaterno);

    printf("Ingrese su Apellido Materno: ");
    scanf("%19s", apellidos->apellidomaterno);
}

void imprimirApellido(struct Apellidos apellido) {
    printf("Apellido Paterno: %s\n", apellido.apellidopaterno);
    printf("Apellido Materno: %s\n", apellido.apellidomaterno);
}

void ingresarNombre(struct Nombres *nombres) {
    printf("Ingrese su Primer Nombre: ");
    scanf("%19s", nombres->primernombre);

    printf("Ingrese su Segundo Nombre: ");
    scanf("%19s", nombres->segundonombre);
}

void imprimirNombre(struct Nombres nombres) {
    printf("Primer Nombre: %s\n", nombres.primernombre);
    printf("Segundo Nombre: %s\n", nombres.segundonombre);
}

void generarCorreoPersonalizado(char *correoinst, struct Nombres nombres, struct Apellidos apellidos) {
    strcpy(correoinst, "");
    strncat(correoinst, nombres.primernombre, 1); // Primera letra del primer nombre
    strncat(correoinst, nombres.segundonombre, 1); // Primera letra del segundo nombre
    strcat(correoinst, apellidos.apellidopaterno);
    strcat(correoinst, "@espe.edu.ec");
}*/

//MAIN VALIDACION CORREO
/*int main() {
    int cantidadEstudiantes;

    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &cantidadEstudiantes);

    struct Nombres nombres;
    struct Apellidos apellidos;
    struct Secuencia secuencia;
    struct Correo correo;
    struct Estudiante estudiante;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        printf("\nEstudiante %d:\n", i + 1);

        ingresarApellido(&apellidos);
        ingresarNombre(&nombres);

        generarCorreoPersonalizado(correo.correoinst, nombres, apellidos);

        imprimirApellido(apellidos);
        imprimirNombre(nombres);

        // Aplicar conversión a minúsculas solo al imprimir el correo
        mayus_a_minus(correo.correoinst, strlen(correo.correoinst));
        printf("Correo electronico: %s\n", correo.correoinst);
    }

    return 0;
}*/
