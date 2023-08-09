/*
presentacion
*/
#include <conio.h>
#include "Gotoxy.h"

void caratula(){
	int select;
	
int c=2;
int d=20;
int e=30;
	
	gotoxy(20+d, 5-c); printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	gotoxy(26+d, 9-c); printf("Electr%cnica y Automatizacion", 162);
	
	letras();
	
	gotoxy(10+e, 21-c); printf("Materia: Fundamentos de la Programaci%cn", 162);
	gotoxy(10+e, 22-c); printf("Tema: Ordenar datos de usuarios");
	gotoxy(10+e, 23-c); printf("Nombre: C%crdenas Brandon", 160);
	gotoxy(10+e, 24-c); printf("NRC: 9890");
	
	cuadros(19+d, 4-c, 39, 1);
	cuadros(25+d,8-c, 28, 1);
	cuadros(45, 12-c, 25, 5);
	cuadros(39,18, 39, 4);
//hola x	
	margenes();
	
//	gotoxy(10+e, 28); printf("Para iniciar pulse 1: "); scanf("%d", select); fflush(stdin);
    carga(27, 42);
//	gotoxy(4,27); printf("                                                        ");
		
//	getch();
}
