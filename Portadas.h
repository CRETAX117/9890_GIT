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
	int select;
	
	int c=2;
	int d=20;
	int e=30;
	
	gotoxy(20+d, 5-c); printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	gotoxy(26+d, 9-c); printf("Electr%cnica y Automatizacion", 162);
	
	espe();
	
	gotoxy(10+e, 21-c); printf("Materia: Fundamentos de la Programaci%cn", 162);
	gotoxy(10+e, 22-c); printf("Tema: Ordenar datos de usuarios");
	gotoxy(10+e, 23-c); printf("Nombre: C%crdenas Brandon", 160);
	gotoxy(10+e, 24-c); printf("NRC: 9890");
	
	cuadros1(19+d, 4-c, 39, 1);
	cuadros1(25+d,8-c, 28, 1);
	cuadros1(45, 12-c, 25, 5);
	cuadros1(39,18, 39, 4);
//hola x	
	margenes();
	
//	gotoxy(10+e, 28); printf("Para iniciar pulse 1: "); scanf("%d", select); fflush(stdin);
    carga(27, 42);
//	gotoxy(4,27); printf("                                                        ");
		
//	getch();
}
