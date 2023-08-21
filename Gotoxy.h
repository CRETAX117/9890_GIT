/*
Libreria Gotoxy
Colocar aqui las funciones graficas
*/

#include <iostream>
#include <windows.h>
#define MAX_L 100		//Maximo de caracteres en una cadena
#define MAX_X 120		//Maximo de pantalla horizontal (inicia en 0)
#define MAX_Y 29		//Maximo de pantala vertical (inicia en 0)

using namespace std;

//Funciones graficas

void CLS(int tim){
	Sleep(tim);
	system("cls");
}

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

void cuadros1(int x, int y, int m, int n) {
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
void cuadros2(int x, int y, int m, int n) {
    int i, j;

    // Dibujar la esquina superior izquierda
    gotoxy(x, y);
    printf("%c", 218);

    // Dibujar la parte superior del cuadro
    for (i = 0; i < m; i++) {
        printf("%c", 196);
    }
    printf("%c", 191);

    // Dibujar los lados del cuadro
    for (j = 1; j <= n; j++) {
        gotoxy(x, y + j);
        printf("%c",179);
        gotoxy(x + m + 1, y + j);
        printf("%c", 179);
    }

    // Dibujar la esquina inferior izquierda
    gotoxy(x, y + n + 1);
    printf("%c", 192);

    // Dibujar la parte inferior del cuadro
    for (i = 0; i < m; i++) {
        printf("%c", 196);
    }
    printf("%c", 217);
}

void lineasHV(int cs, int fs, int ci, int fi) {
    int i;
    for (i = cs; i <= ci; i++) {
        gotoxy(i, fs); printf("%c", 205);
        gotoxy(i, fi); printf("%c", 205);
    }
    for (i = fs; i <= fi; i++) {
        gotoxy(cs, i); printf("%c", 186);
        gotoxy(ci, i); printf("%c", 186);
    }
    gotoxy(cs, fs); printf("%c", 201);
    gotoxy(ci, fi); printf("%c", 188);
    gotoxy(ci, fs); printf("%c", 187);
    gotoxy(cs, fi); printf("%c", 200);
}

void centrarTexto(char* texto, int y) {
    int longitud = strlen(texto);
    gotoxy(60 - (longitud / 2), y);
    printf(texto);
}

void carga(int xi, int xf, int alt, int tim){
	for(int i=xi;i < xf; i++){
    	gotoxy(i,alt); printf("%c",177);
	}
	for(int i=xi;i < xf; i++){
    	gotoxy(i,alt); printf("%c",219);
    	Sleep(tim);
	}
}

void regresar(){
	char texto[MAX_L] = {"Pulse la tecla ESC para regresar al menu principal"};
	cuadros1(29, 18, 60, 1);
	centrarTexto(texto, 19);
}

// Definición de colores
enum ConsoleColors {
    Black = 0,
    Blue = 1,
    Green = 2,
    Red = 4,
    Yellow = 6,
    White = 7
};

// Función para cambiar el color de texto y fondo
void setColor(int textColor, int bgColor) {
    int color = textColor + (bgColor * 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void exitit(){
	char salida[] = {"CERRANDO SESION"};
	centrarTexto(salida, 13);
	carga(29, 92, 14, 13);
}

void erase(int xi, int yi, int xf, int yf){
	for(int i=yi; i<=yf; i++){
		for(int j=xi; j<=xf; j++){
			gotoxy(j, i); printf(" ");
		}
	}
}

//Funcion de letras
void espe1(int inicioY) {
    int centroX = 60; // Coordenada X del centro
//    int inicioY = 16; // Coordenada Y de inicio

    // Calcular el ancho total de las letras (E + S + P + E)
    int anchoTotal = 5 + 7 + 7 + 5; // Suma de los anchos de cada letra y espacios

    // Calcular la coordenada X de inicio para que las letras estén centradas
    int inicioX = centroX - (anchoTotal / 2);

    // Imprimir la letra E
	setColor(2, 0);
    gotoxy(inicioX, inicioY); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 1); printf("%c%c", 219, 219);
    gotoxy(inicioX, inicioY + 2); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 3); printf("%c%c", 219, 219);
    gotoxy(inicioX, inicioY + 4); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);

    // Espacio entre letras
    inicioX += 5 + 2; // Ancho de letra + espacio

    // Imprimir la letra S

    gotoxy(inicioX, inicioY); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 1); printf("%c%c", 219, 219);
    gotoxy(inicioX, inicioY + 2); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 3); printf("   %c%c", 219, 219);
    gotoxy(inicioX, inicioY + 4); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);

    // Espacio entre letras
    inicioX += 5 + 2; // Ancho de letra + espacio

    // Imprimir la letra P

    gotoxy(inicioX, inicioY); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 1); printf("%c%c  %c", 219, 219, 219);
    gotoxy(inicioX, inicioY + 2); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 3); printf("%c%c", 219, 219);
    gotoxy(inicioX, inicioY + 4); printf("%c%c", 219, 219);

    // Espacio entre letras
    inicioX += 5 + 2; // Ancho de letra + espacio

    // Imprimir la letra E

    gotoxy(inicioX, inicioY); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 1); printf("%c%c", 219, 219);
    gotoxy(inicioX, inicioY + 2); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    gotoxy(inicioX, inicioY + 3); printf("%c%c", 219, 219);
    gotoxy(inicioX, inicioY + 4); printf("%c%c%c%c%c", 219, 219, 219, 219, 219);
    setColor(7, 0);
}

void espe2(int b){
	int a=41;
	
	// Imprimir la letra E
	setColor(4, 0);
		
	gotoxy(7+a, 0+b); printf("|||||");
    gotoxy(7+a, 1+b); printf("||");
    gotoxy(7+a, 2+b); printf("|||||");
    gotoxy(7+a, 3+b); printf("||");
    gotoxy(7+a, 4+b); printf("|||||");
    
	setColor(6, 0);
                                     
    // Imprimir la letra S       
    
	gotoxy(13+a, 0+b); printf("|||||");
    gotoxy(13+a, 1+b); printf("||");
    gotoxy(13+a, 2+b); printf("|||||");
    gotoxy(13+a, 3+b); printf("   ||");
    gotoxy(13+a, 4+b); printf("|||||");

    // Imprimir la letra P
    gotoxy(19+a, 0+b); printf("|||||");
    gotoxy(19+a, 1+b); printf("|| ||");
    gotoxy(19+a, 2+b); printf("|||||");
    gotoxy(19+a, 3+b); printf("||");
    gotoxy(19+a, 4+b); printf("||");
    
	setColor(2, 0);

    // Imprimir la letra E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
    gotoxy(25+a, 0+b); printf("|||||");
    gotoxy(25+a, 1+b); printf("||");
    gotoxy(25+a, 2+b); printf("|||||");
    gotoxy(25+a, 3+b); printf("||");
    gotoxy(25+a, 4+b); printf("|||||");
    
	setColor(7, 0);
}

//_____________________________________________________________________________________

//Funciones de control
void ocultarCursor(){
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hcon, &cci);
}

void mostrarCursor(){
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = TRUE;

	SetConsoleCursorInfo(hcon, &cci);
}

void escape(){
	char esc = 27;
	char aux;
	while(true){
		aux = getch();
		if (aux == esc){ 								// Verifica si se ha presionado la tecla ESC
            HWND consoleWnd = GetConsoleWindow(); 		// Obtiene el identificador de la ventana de la consola
			CLS(0);
			margenes();
			exitit();
            SendMessage(consoleWnd, WM_CLOSE, 0, 0); 	// Cierra la ventana de la consola
            break; 										// Sale del bucle
        }
	}
}

void noESCAPE(){
	char esc = 27;
	char aux;
	while(true){
		aux = getch();
		if (aux == esc){ 								// Verifica si se ha presionado la tecla ESC
            break; 										// Sale del bucle
        }
	}
}