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
void mayus_a_minus(char palabra[], int n) {
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
}
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
