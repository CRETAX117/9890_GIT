/*
Libreria del Menu
*/
/*
Libreria del Menu
Se estructurara el menu funcional
*/
//#include "Funciones.h"
#include "Portadas.h"

void initSelect_Inicio();
void registroSelect();
int confirm_regist();
int registro_estudent_select();
void menu_student();

//-------------MENU SELECCION INICIO SESION-------------
void initSelect_Inicio(){	//MENU INICIO SESION
	limpiar_data();
	RETORNO_RG:
	CLS(0);
	inicioSesion();
	ocultarCursor();
	int a = 8, action, aux;
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
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
			HWND consoleWnd = GetConsoleWindow(); 		// Obtiene el identificador de la ventana de la consola
			CLS(0);
			margenes();
			exitit();
            SendMessage(consoleWnd, WM_CLOSE, 0, 0); 	// Cierra la ventana de la consola
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
		}else if(in==ENTER || in==SPACE){		//Acciones tecla ENTER
			if(x==0){					//Funcion 0
				erase(27, 15, 87, 15);
				mostrarCursor();
				setColor(White, Black);
				cuadros2(25, 14, 70, 1);
				signInUser();
				ocultarCursor();
				
				cuadros2(25, 14, 70, 1);
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(25, 19, 70, 1);
				setColor(White, Black);		//Cambio de color por defecto
				cuadros1(25, 23, 28, 3);
				cuadros1(67, 23, 28, 3);
				
				x=1;
				goto RETORNO;
				break;
				
			}else if(x==1){				//Funcion 1
				erase(27, 20, 87, 20);
				mostrarCursor();
				setColor(White, Black);
				cuadros2(25, 19, 70, 1);
				signInPass();
				ocultarCursor();
				
				cuadros2(25, 14, 70, 1);	
				cuadros2(25, 19, 70, 1);	
				setColor(Black, White);		//Cambio de color de fondo
				cuadros1(25, 23, 28, 3);
				setColor(White, Black);		//Cambio de color por defecto
				cuadros1(67, 23, 28, 3);
				
				x=2;
				goto RETORNO;
				break;
				
			}else if(x==2){				//Funcion 2
				CLS(0);
				registro_estudent_select();
				comprobar();
				final_registro_alumno(correoinst);
				break;
				
			}else if(x==3){				//Funcion 3
				CLS(0);
				if(verificarCredenciales(usuario, contra)){
					margenes();
					char salida[MAX_L] = {"Verificacion completa"};
					centrarTexto(salida, 14);
					printf("\a");
					Sleep(1200);
					menu_student();
					limpiar_data();
					break;
				}else{
					CLS(0);
					margenes();
					Inicio_Incorrecto();
					break;
				}
				
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
//-------------MENU ESTUDIANTE-------------
void menu_student(){	//MENU SELECCION REGISTRO GENERAL
	CLS(0);
	RETORNO_RGA:
	Menu_Estudiante();
	
	char in, sec, action, aux;
	int x;
	
	while(true){
		in = getch();
		if(in == UP || in == DOWN || in == LEFT || in == RIGHT){
			x=0;
			setColor(Black, White);
			lineasHV(5, 11, 60, 13);
			setColor(White, Black);
			lineasHV(5, 14, 60, 16);
			lineasHV(5, 17, 60, 19);
			break;
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
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
		}else if(in==ENTER){		//Acciones tecla ENTER
			if(x==0){					//Funcion 0
				CLS(0);
				aux = in_notes1();
				if(aux == 1){
				x=0;
					aux=0;
					goto RETORNO_RGA;
				}
				break;
				
			}else if(x==1){				//Funcion 1
				CLS(0);
				aux = in_notes2();
				if(aux == 1){
				x=2;
					aux=0;
					goto RETORNO_RGA;
				}
				break;
				
			}else if(x==2){				//Funcion 2
				CLS(0);
				aux = in_notes3();
				if(aux == 1){
				x=3;
					aux=0;
					goto RETORNO_RGA;
				}
				break;
				
			}
			
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
			imprimir_notasTXT();
			CLS(0);
			break;
		}
		
		switch(x){
			case 0:
				setColor(Black, White);
				lineasHV(5, 11, 60, 13);
				setColor(White, Black);
				lineasHV(5, 14, 60, 16);
				lineasHV(5, 17, 60, 19);
				break;
			case 1:
				lineasHV(5, 11, 60, 13);
				setColor(Black, White);
				lineasHV(5, 14, 60, 16);
				setColor(White, Black);
				lineasHV(5, 17, 60, 19);
				break;
			case 2:
				lineasHV(5, 11, 60, 13);
				lineasHV(5, 14, 60, 16);
				setColor(Black, White);
				lineasHV(5, 17, 60, 19);
				setColor(White, Black);
				break;
		}
	}
}


//-------------CONFIRMACION-------------
int confirm_regist(){	//MENU SELECCION REGISTRO GENERAL
	CLS(0);
	imprimir_datos();
	
	char in, sec, action, aux;
	int x=0;
	
	while(true){
		in = getch();
		if(in == UP || in == DOWN || in == LEFT || in == RIGHT){
			setColor(Black, White);		//Cambio de color de fondo
			cuadros1(24, 20, 8, 1);
			setColor(White, Black);
			cuadros1(80, 20, 11, 1);
			x=0;
			break;
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				break;
		}	
	}

	while(in!=ESCAPE){
		in=getch();
		if(in==UP){					//Acciones flecha arriba
			if((x>=0 && x<2)){
				x--;
			}else{
				x=1;
			}
		}else if(in==DOWN){			//Acciones flecha abajo
			if((x>=0 && x<2)){
				x++;
			}else{
				x=0;
			}
				
		}else if(in==ENTER || in==SPACE){		//Acciones tecla ENTER
			if(x==0){					//Funcion 0
				x=0;
				
				return 1;
			
			}else if(x==1){				//Funcion 1
				x=1;
				return 2;
			}
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				break;
		}
		
		
		switch(x){
			case 0:
				setColor(Black, White);		//Cambio de color de fondo
				cuadros1(24, 20, 8, 1);
				setColor(White, Black);
				cuadros1(80, 20, 11, 1);
				break;
			case 1:
				cuadros1(24, 20, 8, 1);
				setColor(Black, White);		//Cambio de color de fondo
				cuadros1(80, 20, 11, 1);
				setColor(White, Black);
				break;
		}
	}
}

//-------------MENU SELECCION REGISTRO ESTUDIANTE-------------
int registro_estudent_select(){
	int x;
	RETURN_RGE2:
	limpiar_data();
	CLS(1);
	registro_estudiante();	//CAMBIABLE
	char in, sec, aux, alert;
	
	
	while(true){
		in = getch();
		if(in == UP || in == DOWN || in == LEFT || in == RIGHT){
			setColor(Black, White);		//Cambio de color de fondo
			cuadros2(35, 7, 70, 1); 	//Cuadro cedula
			setColor(White, Black);		//Cambio de color por defecto
			cuadros2(35, 12, 70, 1);	//Cuadro nombres
			cuadros2(35, 17, 70, 1);	//Cuadro apellidos
			cuadros2(36, 23, 4, 1);		//Cuadro dia
			cuadros2(57, 23, 4, 1);		//Cuadro mes
			cuadros2(75, 23, 6, 1);		//Cuadro anio
			cuadros1(94, 23, 19, 3);	//Cuadro registro
			
			RETORNO_RGE1:
			break;
			
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
			break;
		}
	}
	
	do{
		in=getch();
		if(in==UP){					//Acciones flecha arriba
			if((x>=0 && x<7)){
				x--;
			}else{
				x=6;
			}
		}else if(in==DOWN){			//Acciones flecha abajo
			if((x>=0 && x<7)){
				x++;
			}else{
				x=0;
			}
				
		}else if(in==LEFT){			//Acciones flecha izquierda
			if(x<7 && x>2){
				x--;
			}
		}else if(in==RIGHT){		//Acciones flecha derecha
			if(x==6){
				x=0;	
			}else if(x>=3 && x<7){
				x++;
			}
		}else if(in==ENTER){		//Acciones tecla ENTER Y ESPACIO
			if(x==0){							//Funcion 
				erase(37, 8, 70, 8);
				setColor(White, Black);
				cuadros2(35, 7, 70, 1); //Cuadro cedula
				in_cedula();
				alert = cedula_check();
				if(alert == 1){
					alert = 0;
					goto RETURN_RGE2;
				}else if(alert == 2){
					alert = 0;
					goto RETURN_RGE2;
				}else if(alert == 3){
					cuadros2(35, 7, 70, 1); 	//Cuadro cedula
					setColor(Black, White);		//Cambio de color de fondo
					cuadros2(35, 12, 70, 1);	//Cuadro nombres
					setColor(White, Black);		//Cambio de coor por defecto
					cuadros2(35, 17, 70, 1);	//Cuadro apellidos
					cuadros2(36, 23, 4, 1);		//Cuadro dia
					cuadros2(57, 23, 4, 1);		//Cuadro mes
					cuadros2(75, 23, 6, 1);		//Cuadro anio
					cuadros1(94, 23, 19, 3);	//Cuadro registro
				
					x=1;		
				}
			
				
			}else if(x==1){				//Funcion 1
				erase(37, 13, 70, 13);
				setColor(White, Black);
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				in_names();
				alert = word_check(name1, name2);
				if(alert == 1){
					x=0;
					alert = 0;
					goto RETURN_RGE2;
				}else{
				
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				setColor(Black, White);		//Cambio de color de fondo		
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				
				x=2;
				}
				
			}else if(x==2){				//Funcion 2
				erase(37, 18, 70, 18);
				setColor(White, Black);
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				in_lastnames();
				alert = word_check(apellido1, apellido2);
				if(alert == 1){
					x=0;
					alert = 0;
					goto RETURN_RGE2;
				}else{
				
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				setColor(Black, White);		//Cambio de color de fondo		
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				
				x=3;
				goto RETORNO_RGE1;
				break;
				}
			}else if(x==3){				//Funcion 3
				erase(38, 24, 40, 24);
				setColor(White, Black);
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				in_day();
				alert = num_check(day);
				if(alert == 1){
					x=0;
					alert = 0;
					goto RETURN_RGE2;
				}else{
					cuadros2(35, 7, 70, 1); 	//Cuadro cedula
					cuadros2(35, 12, 70, 1);	//Cuadro nombres
					cuadros2(35, 17, 70, 1);	//Cuadro apellidos
					cuadros2(36, 23, 4, 1);		//Cuadro dia
					setColor(Black, White);		//Cambio de color de fondo
					cuadros2(57, 23, 4, 1);		//Cuadro mes
					setColor(White, Black);		//Cambio de coor por defecto
					cuadros2(75, 23, 6, 1);		//Cuadro anio
					cuadros1(94, 23, 19, 3);	//Cuadro registro

					x=4;
					goto RETORNO_RGE1;
					break;		
				}
	
				
			}else if(x==4){				//Funcion 4
				erase(59, 24, 61, 24);
				setColor(White, Black);
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				in_month();
				alert = num_check(month);
				if(alert == 1){
					x=0;
					alert = 0;
					goto RETURN_RGE2;
				}else{
				
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				setColor(Black, White);		//Cambio de color de fondo		
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				
				x=5;
				goto RETORNO_RGE1;
				break;
				}
			}else if(x==5){				//Funcion 5
				erase(77, 24, 80, 24);
				setColor(White, Black);
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				in_year();
//				alert = num_check(year);
				if(alert == 1){
					x=0;
					alert = 0;
					goto RETURN_RGE2;
				}else{
				
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				setColor(Black, White);		//Cambio de color de fondo		
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				setColor(White, Black);		//Cambio de coor por defecto
				
				x=6;
				goto RETORNO_RGE1;
				break;
				}
				
			}else if(x==6){				//Funcion 5
				break;
			}
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				CLS(0);
				return 2;
				break;
		}
		
		switch(x){
			case 0:
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				break;
			case 1:
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				break;
			case 2:
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				break;
			case 3:
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				break;
			case 4:
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				break;
			case 5:
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				setColor(Black, White);		//Cambio de color de fondo
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				setColor(White, Black);		//Cambio de coor por defecto
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				break;
			case 6:
				cuadros2(35, 7, 70, 1); 	//Cuadro cedula
				cuadros2(35, 12, 70, 1);	//Cuadro nombres
				cuadros2(35, 17, 70, 1);	//Cuadro apellidos
				cuadros2(36, 23, 4, 1);		//Cuadro dia
				cuadros2(57, 23, 4, 1);		//Cuadro mes
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				setColor(Black, White);		//Cambio de color de fondo
				cuadros1(94, 23, 19, 3);	//Cuadro registro
				setColor(White, Black);		//Cambio de coor por defecto
				break;
		}
	}while(in!=ESCAPE);
	aux = confirm_regist();
	if(aux==1){
		x=0;
		CLS(0);
		return 2;
	}else if(aux==2){
		CLS(0);
		return 1;
	}
}