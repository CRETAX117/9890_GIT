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

void caratula(){
	char mensaje[MAX_L] = {"Pulse cualquier tecla para continuar"};
	char universidad[MAX_L] = {"UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE"};
	char materia[MAX_L] = {"FUNDAMENTOS DE LA PROGRAMACI%cN"};
	char titulo[MAX_L] = {"PROYECTO FINAL"};
	
	int a, b;
	
	margenes();
	centrarTexto(universidad, 3);
	centrarTexto(materia, 5);
	centrarTexto(titulo, 7);
	
	for(int i=40;i < 76+3; i++){
    	gotoxy(i,27); printf("%c",177);
	}
	for(int i=40;i < 76+3; i++){
    	gotoxy(i,27); printf("%c",219);
    	Sleep(52);
	}
	centrarTexto(mensaje, 29); getch();
}

void caratula1(){
	char mensaje[MAX_L] = {"Pulse cualquier tecla para continuar"};
	int select;	
	int c=2;
	int d=20;
	int e=30;
	
	margenes();
	ocultarCursor();
	gotoxy(20+d, 5-c); printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	gotoxy(26+d, 9-c); printf("Electr%cnica y Automatizacion", 162);
	
	espe();
	
	gotoxy(10+e, 21-c); printf("Materia: Fundamentos de la Programaci%cn", 162);
	gotoxy(10+e, 22-c); printf("Tema: Uso de Git y Github");
	gotoxy(10+e, 23-c); printf("Integrantes:");
	gotoxy(10+e, 24-c); printf("C%crdenas Brandon", 160);
	gotoxy(10+e, 25-c); printf("Valdivieso Steven");
	gotoxy(10+e, 26-c); printf("Chiriboga Josue");
	gotoxy(10+e, 27-c); printf("NRC: 9890");
	
	cuadros1(19+d, 4-c, 39, 1);
	cuadros1(25+d,8-c, 28, 1);
	cuadros1(46, 12-c, 25, 5);
	cuadros1(39,18, 39, 6);
	
	
//	gotoxy(10+e, 28); printf("Para iniciar pulse 1: "); scanf("%d", select); fflush(stdin);
    for(int i=40;i < 76+3; i++){
    	gotoxy(i,27); printf("%c",177);
	}
	for(int i=40;i < 76+3; i++){
    	gotoxy(i,27); printf("%c",219);
    	Sleep(52);
	}
	centrarTexto(mensaje, 29); getch();
}
