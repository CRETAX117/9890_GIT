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
char apellido1[MAX_L];
char apellido2[MAX_L];
char day[4];
char month[4];
char year[4];

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

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
void in_cedula() {
    mostrarCursor();
    gotoxy(37, 8);
    fgets(cedula, 10, stdin);
    limpiarBuffer(); // Limpia el búfer después de leer la cédula
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
