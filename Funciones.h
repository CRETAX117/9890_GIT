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
char contraRegist[MAX_L];
char cedula[9];
char name1[MAX_L];
char name2[MAX_L];
char apellido1[MAX_L];
char apellido2[MAX_L];
char day[4];
char month[4];
char year[4];
char correoinst[MAX_L];

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void limpiarCadena(char *cadena){
	memset(cadena, 0, strlen(cadena));
}

int nullComp(const char *cadena) {
    if (cadena == NULL || strlen(cadena) == 0) {
        return 1; // La cadena está vacía
    }
    return 0; // La cadena no está vacía
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

const int MAX_ALUMNOS_POR_MATERIA = 5;
const int MAX_MATERIAS_POR_ALUMNO = 3;

struct FechaNacimiento {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    string identificacion;
    FechaNacimiento fechaNacimiento;
};

struct Usuario {
    string correo;
    string contrasenia;
};

struct Notas {
    double nota1;
    double nota2;
    double nota3;
};

struct Materia {
    string nombre;
    string codigo;
    Persona profesor;
    string alumnos[MAX_ALUMNOS_POR_MATERIA];
    Notas notasPorAlumno[MAX_ALUMNOS_POR_MATERIA];
    int numAlumnos = 0;
};

struct Docente {
    Persona persona;
    string codigoDocente;
    Usuario usuario;
    Materia materia;
};

struct Alumno {
    Persona persona;
    string codigoEstudiante;
    Usuario usuario;
    string materias[MAX_MATERIAS_POR_ALUMNO];
    Notas notasPorMateria[MAX_MATERIAS_POR_ALUMNO];
    int numMaterias = 0;
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
void in_cedula() {
    mostrarCursor();
    gotoxy(37, 8);
    scanf("%[^\n]", cedula); fflush(stdin);
//    fgets(cedula, 10, stdin);
//    limpiarBuffer(); // Limpia el búfer después de leer la cédula
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


void in_names() {
	mostrarCursor();
    char temp[MAX_L * 2]; // Un solo búfer para ambos nombres
    
    gotoxy(37, 13);
    fgets(temp, sizeof(temp), stdin);
    
    // Extraer los nombres del búfer
    sscanf(temp, "%s %s", name1, name2); // Suponiendo que name1 y name2 son globales
	ocultarCursor();
}

void in_lastnames() {
	mostrarCursor();
    char temp[MAX_L * 2]; // Un solo búfer para ambos apellidos
    
    gotoxy(37, 18);
    fgets(temp, sizeof(temp), stdin);
    
    // Extraer los apellidos del búfer
    sscanf(temp, "%s %s", apellido1, apellido2); // Suponiendo que apellido1 y apellido2 son globales
	ocultarCursor();
}

void in_day(){
	mostrarCursor();
    gotoxy(38, 24);
    scanf("%2s", day);
    fflush(stdin);
    ocultarCursor();
}

int num_check(char *num){
	char solonum[MAX_L] = {"SOLO INGRESE NUMEROS"};
	int error=0;
	
	error=numeros(num);
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
	return 0;
}

int word_check(char word[MAX_L], char word2[MAX_L]){
	char soloword[MAX_L] = {"SOLO INGRESE LETRAS"};
	int error=0, error2=0;
	error=letras(word);
	error2=letras(word2);
	
	if(error == 1 || error2 == 1){
		error=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(45, 11, 28, 5);
		printf("\a");
		centrarTexto(soloword, 14);
		CLS(1700);
		return 1;
	}
	return 0;
}

void in_month(){
	mostrarCursor();
    gotoxy(59, 24);
    scanf("%2s", month);
    fflush(stdin);
    ocultarCursor();
}

void in_year(){
	mostrarCursor();
    gotoxy(77, 24);
    scanf("%4s", year);
    fflush(stdin);
    ocultarCursor();
}

void imprimir_datos(){
	CLS(0);
	
	char titulo[MAX_L] = {"REGISTRO"};
	
	margenes();
	cuadros1(53, 2, 12, 1);
	centrarTexto(titulo, 3);
	gotoxy(6, 5); printf("DATOS INGRESADOS");
	gotoxy(6,7); printf("CEDULA:\t");		cout<<cedula;
	gotoxy(6,9); printf("NOMBRES:\t");		cout<<name1<<" "<< name2;
	gotoxy(6, 11); printf("APELLIDOS:\t");	cout<<apellido1<<" "<<apellido2;
	gotoxy(6, 13); printf("FECHA DE NACIMIENTO:\t");	cout<<day<<"/"<<month<<"/"<<year;	

	cuadros1(24, 20, 8, 1);
	gotoxy(26, 21);	printf("CERRAR");
	cuadros1(80, 20, 11, 1);
	gotoxy(82, 21);	printf("CONFIRMAR");
}

void limpiar_data(){
	limpiarCadena(usuario);
	limpiarCadena(contra);
	limpiarCadena(contraRegist);
	limpiarCadena(cedula);
	limpiarCadena(name1);
	limpiarCadena(name2);
	limpiarCadena(apellido1);
	limpiarCadena(apellido2);
	limpiarCadena(day);
	limpiarCadena(month);
	limpiarCadena(year);
	limpiarCadena(correoinst);
}

void comprobar(){
	if(nullComp(cedula) || nullComp(name1) || nullComp(name2) || nullComp(apellido1) || nullComp(apellido2) || nullComp(day) || nullComp(month) || nullComp(year) ){
		CLS(100);
		margenes();
		char salida[MAX_L] = {"PORFAVOR VUELVA A REALIZAR EL PROCESO"};
		char error[MAX_L] = {"VALORES INCOMPLETOS"};
		char a[MAX_L] = {"Pulse ESC para salir"};
		centrarTexto(salida, 16);
		centrarTexto(error, 14);
		centrarTexto(a, 27);
		escape();
	}else{
	}
}

void mayus_a_minus(char palabra[], int n) {
    for (int i = 0; i < n; i++) {
        if (palabra[i] >= 'A' && palabra[i] <= 'Z') {
            palabra[i] = palabra[i] + 32; // Diferencia entre mayúsculas y minúsculas
        }
    }
}
void generarCorreoPersonalizado(char *correo, char *name1 , char *name2, char *lastname) {
	int n;
	strcpy(correo, "");
    strncat(correo, name1, 1); // Primera letra del primer nombre
    strncat(correo, name2, 1); // Primera letra del segundo nombre
    strcat(correo, lastname);
    strcat(correo, "@espe.edu.ec");
    
    n = strlen(correo);
    mayus_a_minus(correo, n);
}

void imprimirTXT(char *nombe){
	
}

void final_registro(char *correo){
	CLS(0);
	generarCorreoPersonalizado(correoinst, name1, name2, apellido1);
	char titulo[MAX_L] = {"REGISTRO"};
	char mensaje[MAX_L] = {"Su correo institucional es:"};
	char contrasenia[MAX_L] = {"Create a password (8 espacios)"};
	
	margenes();
	cuadros1(53, 2, 12, 1);
	centrarTexto(titulo, 3);
	centrarTexto(mensaje, 5);
	centrarTexto(correoinst, 7);
	centrarTexto(contrasenia, 12);
	
	cuadros1(32, 14, 55, 1);
	mostrarCursor();
	gotoxy(55, 15); scanf("%8[^n]", contraRegist);
	ocultarCursor();	
}


