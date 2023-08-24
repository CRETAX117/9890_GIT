/*
presentacion
*/
#include <conio.h>
#include "Gotoxy.h"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESCAPE 27
#define SPACE 32

/*
Codigo reutilizable
_________________
in=getch();
if(in==UP){
	goto O2;
}else if(in==DOWN){
	goto O1;
}
_________________
options();
gotoxy(a,b); setColor(Black, White); 
puts(c);
setColor(White, Black);
*/

void proximamente(){
	CLS(1);
	char xd[MAX_L] = {"===PROXIMAMENTE==="};
	char a[MAX_L] = {"Pulse ESC para salir"};
	margenes();
	centrarTexto(xd, 13);
	Sleep(1500);
	centrarTexto(a, 27);
	noESCAPE();	
}

void caratula1(){
	char titulo[MAX_L] = {"UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE"};
    system("cls");
    ocultarCursor();
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto(titulo, 2);

    // Cambiar el color del segundo rectÃ¡ngulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(10, 4, 110, 6);
    centrarTexto("FUNDAMENTOS DE PROGRAMACION", 5);

    // Cambiar el color del tercer rectÃ¡ngulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(15, 7, 105, 12);
    centrarTexto("-------------------INTEGRANTES-------------------", 8);
    centrarTexto("BRANDON CARDENAS", 9);
    centrarTexto("JOSUE CHIRIBOGA", 10);
    centrarTexto("STEVEN VALDIVIESO", 11);

    espe1(16);

    centrarTexto("CARGANDO BASE DE DATOS...", 23);
    carga(4, 116, 25, 30);
    gotoxy(4, 21);
    printf("                                                        ");
    gotoxy(4, 21);
    centrarTexto("BIENVENIDO: PRESIONA ENTER PARA CONTINUAR", 23);
    getch();
}

void inicioSesion(){
	char titulo[MAX_L] = {"UNIVERSIDAD DE LAS FUERZAS ARMADAS"};
//	CLS(0);
	margenes();
	ocultarCursor();
	cuadros1(41, 2, 36, 1);
	centrarTexto(titulo, 3);
	espe1(6);
	gotoxy(25, 13); printf("USUARIO:");
	cuadros2(25, 14, 70, 1); 
	gotoxy(25, 18); printf("CONTRASE%cA:", 165);
	cuadros2(25, 19, 70, 1);
	
	cuadros1(25, 23, 28, 3);
	cuadros1(67, 23, 28, 3);
	gotoxy(34, 25); printf("REGISTRARSE");
	gotoxy(75, 25); printf("INICIAR SESION");
	
}

//-----------Portada de Registro General-------------
void Registro_General(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(30, 4, 90, 6);
    centrarTexto("REGISTRO GENERAL ", 5);

    // Cambiar el color del tercer rectángulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(5, 8, 50, 10);
    gotoxy(7, 9); printf("1.- ESTUDIANTES", 9);
    
    lineasHV(5, 12, 50, 14);
    gotoxy(7, 13); printf("2.- DOCENTES", 13);
    
    lineasHV(5, 16, 50, 18);
    gotoxy(7, 17); printf("3.- SALIR", 17);

}

void register_view(){
	char titulo[MAX_L] = {"REGISTRO"};
	
	margenes();
	cuadros1(55, 2, 11, 1);
	centrarTexto(titulo, 3);
	gotoxy(6, 5); printf("DATOS INGRESADOS");
	gotoxy(6,8); printf("CEDULA:\t");	
	gotoxy(6,13); printf("NOMBRES\t:");
	gotoxy(6, 18); printf("APELLIDOS\t:");
	gotoxy(6, 22); printf("FECHA DE NACIMIENTO:\t");
}

void registro_estudiante(){
	CLS(0);
	char titulo[MAX_L] = {"REGISTRO DEL ESTUDIANTE"};
	margenes();
	ocultarCursor();
	cuadros1(47, 1, 25, 1);
	centrarTexto(titulo, 2);
	
	gotoxy(4,5); printf("Ingrese los siguientes datos:");
	gotoxy(6,8); printf("CEDULA (solo numeros):");	
	cuadros2(35, 7, 70, 1); //Cuadro cedula
	gotoxy(6,13); printf("NOMBRES COMPLETOS:");
	cuadros2(35, 12, 70, 1); //Cuadro nombres
	gotoxy(6, 18); printf("APELLIDOS COMPLETOS:");
	cuadros2(35, 17, 70, 1);	//Cuadro apellidos
	gotoxy(6, 22); printf("FECHA DE NACIMIENTO:");
	gotoxy(8, 23); printf("(Solo numeros)");
	gotoxy(38, 22); printf("DD");
	cuadros2(36, 23, 4, 1);		//Cuadro dia
	centrarTexto("MM", 22);
	cuadros2(57, 23, 4, 1);		//Cuadro mes
	gotoxy(78, 22); printf("YY");
	cuadros2(75, 23, 6, 1);		//Cuadro anio
	cuadros1(94, 23, 19, 3);	//Cuadro registro	
	gotoxy(99, 25); printf("REGISTRARSE");
}

void registro_docente(){
	CLS(0);
	char titulo[MAX_L] = {"REGISTRO DEL DOCENTE"};
	margenes();
	ocultarCursor();
	cuadros1(47, 1, 25, 1);
	centrarTexto(titulo, 2);
	gotoxy(4,5); printf("Ingrese los siguientes datos:");
	gotoxy(6,8); printf("CEDULA (solo numeros):");
	cuadros2(35, 7, 70, 1); //Cuadro cedula
	gotoxy(6,13); printf("NOMBRES COMPLETOS:");
	cuadros2(35, 12, 70, 1); //Cuadro nombres
	gotoxy(6, 18); printf("APELLIDOS COMPLETOS:");
	cuadros2(35, 17, 70, 1);	//Cuadro apellidos
	gotoxy(6, 22); printf("FECHA DE NACIMIENTO:");
	gotoxy(8, 23); printf("(Solo numeros)");
	gotoxy(38, 22); printf("DD");
	cuadros2(36, 23, 4, 1);		//Cuadro dia
	centrarTexto("MM", 22);
	cuadros2(57, 23, 4, 1);		//Cuadro mes
	gotoxy(78, 22); printf("YY");
	cuadros2(75, 23, 6, 1);		//Cuadro anio
	cuadros1(94, 23, 19, 3);	//Cuadro registro	
	gotoxy(99, 25); printf("REGISTRARSE");	
}

//-----------Portada de Materia Docente-------------
void Materia_Docentes() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectÃ¡ngulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(30, 4, 90, 6);
    centrarTexto("MATERIAS - DOCENTE", 5);

    // Cambiar el color del tercer rectÃ¡ngulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(5, 8, 50, 10);
    gotoxy(7, 9); printf("1.- FUNDAMENTOS DE PROGRAMACION", 9);
    
    lineasHV(5, 12, 50, 14);
    gotoxy(7, 13); printf("2.- PROGRAMACION ORIENTADA A OBJETOS", 13);
    
    lineasHV(5, 16, 50, 18);
    gotoxy(7, 17); printf("3.- ESTRUCTURA DE DATOS", 17);
    
    lineasHV(40, 22, 80, 24);
    centrarTexto("Pulse la tecla ESC para regresar", 23);
    
}	

//-----------Portada de Menu Docente-------------
void Menu_Docente() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectÃ¡ngulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(30, 4, 90, 6);
    centrarTexto("MENU - DOCENTE", 5);

    // Cambiar el color del tercer rectÃ¡ngulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(5, 8, 50, 10);
    gotoxy(7, 9); printf("1.- MODIFICAR DOCENTE", 9);
    
    lineasHV(5, 12, 50, 14);
    gotoxy(7, 13); printf("2.- MOSTRAR DATOS DEL ALUMNO", 13);
    
    lineasHV(5, 16, 50, 18);
    gotoxy(7, 17); printf("3.- MOSTRAR TODOS LOS DATOS DE ALUMNOS", 17);

}

//-----------Portada de Menu Estudiante-------------
void Menu_Estudiantes() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(30, 4, 90, 6);
    centrarTexto("MENU - ESTUDIANTE", 5);

    // Cambiar el color del tercer rectángulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(5, 8, 50, 10);
    gotoxy(7, 9); printf("1.- MOSTRAR ESTUDIANTE", 9);
    
    lineasHV(5, 12, 50, 14);
    gotoxy(7, 13); printf("2.- MATERIAS DEL ESTUDIANTE", 13);
    
}

//-----------Portada de Materias Estudiantes-------------
void Materias_Estudiantes() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(30, 4, 90, 6);
    centrarTexto("MATERIAS ALUMNO ", 5);

    // Cambiar el color del tercer rectángulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(5, 8, 50, 10);
    gotoxy(7, 9); printf("1.- FUNDAMENTOS DE PRGRAMACION", 9);
    
    lineasHV(5, 12, 50, 14);
    gotoxy(7, 13); printf("2.-PROGRAMACION ORIENTADA A OBJETOS", 13);
    
    lineasHV(5, 16, 50, 18);
    gotoxy(7, 17); printf("3.- ESTRUCTURA DE DATOS ", 17);

	lineasHV(40, 22, 80, 24);
	centrarTexto("Pulse la tecla ESC para regresar",23 );
    
}

//-----------NUEVA PORTADA MENU ESTUDIANTE-------------
void Menu_Estudiante() {
    system("cls");
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(20, 4, 100, 6);
    centrarTexto("MENU - ESTUDIANTE", 5);

    // Cambiar el color del tercer rectángulo 
    //system("COLOR F9");
    lineasHV(30, 7, 90, 9);
    centrarTexto("MATERIAS ASIGNADAS", 8);
    
    lineasHV(5, 11, 60, 13);
    gotoxy(7, 12); printf("FUNDAMENTOS DE PROGRAMACION", 12);
    
    lineasHV(5, 14, 60, 16);
    gotoxy(7, 15); printf("PROGRAMACION ORIENTADA A OBJETOS", 15);
    
    lineasHV(5, 17, 60, 19);
    gotoxy(7, 18); printf("ESTRUCTURA DE DATOS", 18);
    
    //lineasHV(40, 26, 80, 28);
    centrarTexto("Pulse la tecla ESC para regresar", 26);
    
}

//-----------NUEVA PORTADAS PARA LAS MATERIAS-------------
void Materias() {
    system("cls");
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(20, 4, 100, 6);
    centrarTexto("AQUI VAN LAS MATERIAS", 5);

    // Cambiar el color del tercer rectángulo 
    //system("COLOR F9");
    lineasHV(5, 8, 30, 10);
    gotoxy(7, 9); printf("NOTA 1", 9);
    
    lineasHV(5, 11, 30, 13);
    gotoxy(7, 12); printf("NOTA 2", 12);
    
    lineasHV(5, 14, 30, 16);
    gotoxy(7, 15); printf("NOTA 3", 15);
    
    lineasHV(5, 17, 30, 19);
    gotoxy(7, 18); printf("PROMEDIO ", 18);
    
    //lineasHV(40, 26, 80, 28);
    centrarTexto("Pulse la tecla ESC para regresar", 26);
    
}

//-----------NUEVA PORTADA DE FUNDAMENTOS DE LA PROGRAMACION-------------
void Fund_Programacion() {
    system("cls");
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(20, 4, 100, 6);
    centrarTexto("MENU - DOCENTE", 5);

    // Cambiar el color del tercer rectángulo 
    //system("COLOR F9");
    lineasHV(30, 7, 90, 9);
    centrarTexto("FUNDAMENTOS DE PROGRAMACION", 8);
    
    lineasHV(5, 11, 30, 13);
    gotoxy(7, 12); printf("ESTUDIANTE 1", 12);
    
    lineasHV(5, 14, 30, 16);
    gotoxy(7, 15); printf("ESTUDIANTE 2", 15);
    
    lineasHV(5, 17, 30, 19);
    gotoxy(7, 18); printf("ESTUDIANTE 3", 18);
    
    lineasHV(5, 20, 30, 22);
    gotoxy(7, 21); printf("ESTUDIANTE 4", 21);
    
    lineasHV(5, 23, 30, 25);
    gotoxy(7, 24); printf("ESTUDIANTE 5", 24);
    
    //lineasHV(40, 26, 80, 28);
    centrarTexto("Pulse la tecla ESC para regresar", 26);
    
}

//-----------NUEVA PORTADA DE PROGRAMACION ORIENTADA A OBJETOS-------------
void Prog_Orientada() {
    system("cls");
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(20, 4, 100, 6);
    centrarTexto("MENU - DOCENTE", 5);

    // Cambiar el color del tercer rectángulo 
    //system("COLOR F9");
    lineasHV(30, 7, 90, 9);
    centrarTexto("PROGRAMACION ORIENTADA A OBJETOS", 8);
    
    lineasHV(5, 11, 30, 13);
    gotoxy(7, 12); printf("ESTUDIANTE 1", 12);
    
    lineasHV(5, 14, 30, 16);
    gotoxy(7, 15); printf("ESTUDIANTE 2", 15);
    
    lineasHV(5, 17, 30, 19);
    gotoxy(7, 18); printf("ESTUDIANTE 3", 18);
    
    lineasHV(5, 20, 30, 22);
    gotoxy(7, 21); printf("ESTUDIANTE 4", 21);
    
    lineasHV(5, 23, 30, 25);
    gotoxy(7, 24); printf("ESTUDIANTE 5", 24);
    
    //lineasHV(40, 26, 80, 28);
    centrarTexto("Pulse la tecla ESC para regresar", 26);
    
}

//-----------NUEVA PORTADA DE ESTRUCTURA DE DATOS-------------
void Estruc_Datos() {
    system("cls");
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(20, 4, 100, 6);
    centrarTexto("MENU - DOCENTE", 5);

    // Cambiar el color del tercer rectángulo 
    //system("COLOR F9");
    lineasHV(30, 7, 90, 9);
    centrarTexto("ESTRUCTURA DE DATOS", 8);
    
    lineasHV(5, 11, 30, 13);
    gotoxy(7, 12); printf("ESTUDIANTE 1", 12);
    
    lineasHV(5, 14, 30, 16);
    gotoxy(7, 15); printf("ESTUDIANTE 2", 15);
    
    lineasHV(5, 17, 30, 19);
    gotoxy(7, 18); printf("ESTUDIANTE 3", 18);
    
    lineasHV(5, 20, 30, 22);
    gotoxy(7, 21); printf("ESTUDIANTE 4", 21);
    
    lineasHV(5, 23, 30, 25);
    gotoxy(7, 24); printf("ESTUDIANTE 5", 24);
    
    //lineasHV(40, 26, 80, 28);
    centrarTexto("Pulse la tecla ESC para regresar", 26);
    
}