/*
Librerias de gotoxy
*/
#include <windows.h>
#define MAX_X 120
#define MAX_Y 30

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

void lineas_V(int x, int y){
	for(int i=1; i<y; i++){
		gotoxy(x, i); printf("%c", 186);
	}
}

void lineas_H(int x, int y){
	for(int i=1; i<x; i++){
		gotoxy(i, y); printf("%c", 205);
	}
}

void letras(){
	int a=39;
	int b=2;
	
	// Imprimir la letra E
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	
	gotoxy(7+a, 9+b); printf("|||||");
    gotoxy(7+a, 10+b); printf("||");
    gotoxy(7+a, 11+b); printf("|||||");
    gotoxy(7+a, 12+b); printf("||");
    gotoxy(7+a, 13+b); printf("|||||");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                                     
    // Imprimir la letra S       
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);                              
    
	gotoxy(13+a, 9+b); printf("|||||");
    gotoxy(13+a, 10+b); printf("||");
    gotoxy(13+a, 11+b); printf("|||||");
    gotoxy(13+a, 12+b); printf("   ||");
    gotoxy(13+a, 13+b); printf("|||||");

    // Imprimir la letra P
    gotoxy(19+a, 9+b); printf("|||||");
    gotoxy(19+a, 10+b); printf("|| ||");
    gotoxy(19+a, 11+b); printf("|||||");
    gotoxy(19+a, 12+b); printf("||");
    gotoxy(19+a, 13+b); printf("||");
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

    // Imprimir la letra E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    gotoxy(25+a, 9+b); printf("|||||");
    gotoxy(25+a, 10+b); printf("||");
    gotoxy(25+a, 11+b); printf("|||||");
    gotoxy(25+a, 12+b); printf("||");
    gotoxy(25+a, 13+b); printf("|||||");
    
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void margenes(){
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE );
	
	lineas_H(MAX_X-2, 0); 						//Horizontal sup
	lineas_V(1, MAX_Y);							//Vertical izq
	lineas_V(MAX_X-2, MAX_Y);					//Vertical der
	lineas_H(MAX_X-2, MAX_Y); 					//Horizontal inf
	
	gotoxy(1, 0); printf("%c", 201); 			//Esquina sup izq
	gotoxy(MAX_X-2, 0); printf("%c", 187); 		//Esquina sup der
	gotoxy(1, MAX_Y); printf("%c", 200); 		//Esquina inf izq
	gotoxy(MAX_X-2, MAX_Y); printf("%c", 188); 	//Esquina inf izq
	
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void cuadros(int x, int y, int m, int n) {
    int i, j;

    // Dibujar la esquina superior izquierda
    gotoxy(x, y);
    printf("%c", 201);

    // Dibujar la parte superior del cuadro
    for (i = 0; i < m; i++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    // Dibujar los lados del cuadro
    for (j = 1; j <= n; j++) {
        gotoxy(x, y + j);
        printf("%c",186);
        gotoxy(x + m + 1, y + j);
        printf("%c", 186);
    }

    // Dibujar la esquina inferior izquierda
    gotoxy(x, y + n + 1);
    printf("%c", 200);

    // Dibujar la parte inferior del cuadro
    for (i = 0; i < m; i++) {
        printf("%c", 205);
    }
    printf("%c", 188);
}

void centrarTexto(char* texto, int f) {
    int longitud = strlen(texto);
    gotoxy(40 - (longitud / 2), f);
    printf(texto);
}

void carga(int alt, int tim){
	for(int i=40;i < 76+3; i++){
    	gotoxy(i,alt); printf("%c",177);
	}
	for(int i=40;i < 76+3; i++){
    	gotoxy(i,alt); printf("%c",219);
    	Sleep(tim);
	}
}