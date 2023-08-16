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

void caratula1(){
    system("cls");
    ocultarCursor();
    lineasHV(0, 0, 119, 28);
    lineasHV(5, 1, 115, 3);
    centrarTexto("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE", 2);

    // Cambiar el color del segundo rectángulo y el texto "FUNDAMENTOS DE PROGRAMACION"
    lineasHV(10, 4, 110, 6);
    centrarTexto("FUNDAMENTOS DE PROGRAMACION", 5);

    // Cambiar el color del tercer rectángulo y el texto "ESTUDIANTE: JOSUE CHIRIBOGA"
    //system("COLOR F9");
    lineasHV(15, 7, 105, 12);
    centrarTexto("-------------------INTEGRANTES-------------------", 8);
    centrarTexto("BRANDON CARDENAS", 9);
    centrarTexto("JOSUE CHIRIBOGA", 10);
    centrarTexto("STEVEN VALDIVIESO", 11);

    espe1(16);

    centrarTexto("CARGANDO BASE DE DATOS...", 23);
    carga(25, 30);
    gotoxy(4, 21);
    printf("                                                        ");
    gotoxy(4, 21);
    centrarTexto("BIENVENIDO: PRESIONA ENTER PARA CONTINUAR", 23);
    getch();
}

void inicioSesion(){
	char usuario[MAX_L];
	char contra[MAX_L];
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
	gotoxy(76, 25); printf("INICIAR SESION");
	
	getch();
	
}


