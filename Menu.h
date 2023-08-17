/*
Libreria del Menu
*/
/*
Libreria del Menu
Se estructurara el menu funcional
*/
#include "Portadas.h"
#include "Funciones.h"

void initSelect_Inicio();
void registroSelect();

void initSelect_Inicio(){
	CLS(0);
	inicioSesion();
	ocultarCursor();
	int a = 8;
	char in, sec;
	int x;
	
	while(true){
		in = getch();
		if(in == UP || in == DOWN || in == LEFT || in == RIGHT){
			x=0;
			setColor(Black, White);
			cuadros2(25, 14, 70, 1);
			setColor(White, Black);
			cuadros2(25, 19, 70, 1);
			cuadros1(25, 23, 28, 3);
			cuadros1(67, 23, 28, 3);
			RETORNO:
			break;
		}		
	}
	
	while(true){
		in = getch();
		if(in==UP){					//Acciones flecha arriba
			if((x>=0 && x<4)){
				x--;
			}else{
				x=3;
			}
		}else if(in==DOWN){			//Acciones flecha abajo
			if((x>=0 && x<4)){
				x++;
			}else{
				x=0;
			}
				
		}else if(in==LEFT){			//Acciones flecha izquierda
			if(x==3){
				x=2;
			}
		}else if(in==RIGHT){		//Acciones flecha derecha
			if(x==2){
				x=3;
			}
		}else if(in==ENTER){		//Acciones tecla ENTER
			if(x==0){					//Funcion 0
				erase(27, 15, 87, 15);
				mostrarCursor();
				setColor(White, Black);
				cuadros2(25, 14, 70, 1);
				gotoxy(27, 15); cin.getline(usuario, 60, '\n'); 
				ocultarCursor();
				x=0;
				goto RETORNO;
				break;
				
			}else if(x==1){				//Funcion 1
				erase(27, 20, 87, 20);
				mostrarCursor();
				setColor(White, Black);
				cuadros2(25, 19, 70, 1);
				gotoxy(27, 20); cin.getline(contra, 60, '\n'); 
				ocultarCursor();
				x=1;
				goto RETORNO;
				break;
				
			}else if(x==2){				//Funcion 2
				CLS(0);
				registroSelect();
				break;
				
			}else if(x==3){				//Funcion 3
				CLS(0);

				break;
				
			}else if(x==4){				//Funcio 4
				CLS(0);

				break;
				
			}else if(x==5){				//Funcion 5
				CLS(0);

				break;
				
			}
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
			HWND consoleWnd = GetConsoleWindow(); 		// Obtiene el identificador de la ventana de la consola
			CLS(0);
			margenes();
			exitit();
            SendMessage(consoleWnd, WM_CLOSE, 0, 0); 	// Cierra la ventana de la consola
		}
		
		switch(x){
			case 0:
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(25, 14, 70, 1);
				setColor(White, Black);		//Cambio de color por defecto
				cuadros2(25, 19, 70, 1);
				cuadros1(25, 23, 28, 3);
				cuadros1(67, 23, 28, 3);
				break;
			case 1:
				cuadros2(25, 14, 70, 1);	
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(25, 19, 70, 1);	
				setColor(White, Black);		//Cambio de color por defecto
				cuadros1(25, 23, 28, 3);
				cuadros1(67, 23, 28, 3);
				break;
			case 2:
				cuadros2(25, 14, 70, 1);
				cuadros2(25, 19, 70, 1);
				setColor(Black, White);		//Cambio de color de fondo
				cuadros1(25, 23, 28, 3);
				setColor(White, Black);		//Cambio de color por defecto
				cuadros1(67, 23, 28, 3);
				break;
			case 3:
				cuadros2(25, 14, 70, 1);
				cuadros2(25, 19, 70, 1);
				cuadros1(25, 23, 28, 3);
				setColor(Black, White);		//Cambio de color de fondo
				cuadros1(67, 23, 28, 3);
				setColor(White, Black);		//Cambio de color por defecto
				break;
		}
	}
} 

void registroSelect(){
	Registro_General();
	
	char in, sec;
	int x;
	
	while(true){
		in = getch();
		if(in == UP || in == DOWN || in == LEFT || in == RIGHT){
			setColor(Black, White);		//Cambio de color de fondo
			lineasHV(5, 8, 50, 10);
			setColor(White, Black);		//Cambio de coor por defecto
    		lineasHV(5, 12, 50, 14);
		    lineasHV(5, 16, 50, 18);
			x=0;
			RETORNO:
			break;
		}		
	}
	
	while(true){
		in=getch();
		if(in==UP){					//Acciones flecha arriba
			if((x>=0 && x<3)){
				x--;
			}else{
				x=2;
			}
		}else if(in==DOWN){			//Acciones flecha abajo
			if((x>=0 && x<3)){
				x++;
			}else{
				x=0;
			}
				
		}else if(in==ENTER){		//Acciones tecla ENTER
			if(x==0){					//Funcion 0

				x=0;
				goto RETORNO;
				break;
				
			}else if(x==1){				//Funcion 1

				x=1;
				goto RETORNO;
				break;
				
			}else if(x==2){				//Funcion 2
				CLS(0);

				break;
				
			}else if(x==3){				//Funcion 3
				CLS(0);

				break;
				
			}else if(x==4){				//Funcio 4
				CLS(0);

				break;
				
			}else if(x==5){				//Funcion 5
				CLS(0);

				break;
				
			}
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				CLS(0);
		}
		
		
		switch(x){
			case 0:
				setColor(Black, White);		//Cambio de color de fondo
				lineasHV(5, 8, 50, 10);
				setColor(White, Black);		//Cambio de coor por defecto
    			lineasHV(5, 12, 50, 14);
			    lineasHV(5, 16, 50, 18);
				break;
			case 1:
				lineasHV(5, 8, 50, 10);		
				setColor(Black, White);		//Cambio de color de fondo
    			lineasHV(5, 12, 50, 14);
				setColor(White, Black);		//Cambio de color por defecto
			    lineasHV(5, 16, 50, 18);
				break;
			case 2:
				lineasHV(5, 8, 50, 10);
    			lineasHV(5, 12, 50, 14);
				setColor(Black, White);		//Cambio de color de fondo		
			    lineasHV(5, 16, 50, 18);
				setColor(White, Black);		//Cambio de color por defecto
				break;
		}
	}
}