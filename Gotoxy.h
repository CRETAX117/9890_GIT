/*
Libreria Gotoxy
Colocar aqui las funciones graficas
*/

#include <windows.h>
#define MAX_L 100		//Maximo de caracteres en una cadena
#define MAX_X 120		//Maximo de pantalla horizontal (inicia en 0)
#define MAX_Y 29		//Maximo de pantala vertical (inicia en 0)

//Funciones graficas

void CLS(int tim){
	system("cls");
	Sleep(tim);
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

void centrarTexto(char* texto, int f) {
    int longitud = strlen(texto);
    gotoxy(60 - (longitud / 2), f);
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
	carga(14, 10);
}

void erase(int xi, int yi, int xf, int yf){
	for(int i=yi; i<=yf; i++){
		for(int j=xi; j<=xf; j++){
			gotoxy(j, i); printf(" ");
		}
	}
}

//Funcion de letras
void espe(){
	int a=41;
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

void noESCAPE(){
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