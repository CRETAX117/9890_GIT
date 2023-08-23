/*
Libreria del Menu
*/
/*
Libreria del Menu
Se estructurara el menu funcional
*/
#include "Funciones.h"

void initSelect_Inicio();
void registroSelect();
int confirm_regist();
int registro_estudent_select();
int registro_docent_select();

//-------------MENU SELECCION INICIO SESION-------------
void initSelect_Inicio(){	//MENU INICIO SESION
	RETORNO_RG:
	CLS(0);
	inicioSesion();
	ocultarCursor();
	int a = 8, action;
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
				registroSelect();
				break;
				
			}else if(x==3){				//Funcion 3
				CLS(0);
				proximamente();
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
//-------------MENU SELECCION REGISTRO GENERAL-------------
void registroSelect(){	//MENU SELECCION REGISTRO GENERAL
	CLS(0);
	RETORNO_RGA:
	Registro_General();
	
	char in, sec, action, aux;
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
			break;
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				break;
		}	
	}

	do{
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
				
		}else if(in==ENTER || in==SPACE){		//Acciones tecla ENTER
			if(x==0){					//Funcion 0
				aux = registro_estudent_select();
				x=0;
				if(aux == 1){
					comprobar();
					final_registro(correoinst);
					limpiar_data();
//					GUARDADO DE DATOS
					break;
				}else if(aux == 2){
					CLS(100);
					margenes();
					char salida[MAX_L] = {"PORFAVOR VUELVA A REALIZAR EL PROCESO"};
					char a[MAX_L] = {"Pulse ESC para salir"};
					centrarTexto(salida, 14);
					centrarTexto(a, 27);
					escape();
				}
				
			}else if(x==1){				//Funcion 1
				x=1;
				aux = registro_docent_select();
				if(aux == 4){
//					VERIFICACION;
//					GUARDADO DE DATOS
					break;
				}else if(aux == 3){
					CLS(100);
					margenes();
					char salida[MAX_L] = {"PORFAVOR VUELVA A REALIZAR EL PROCESO"};
					char a[MAX_L] = {"Pulse ESC para salir"};
					centrarTexto(salida, 14);
					centrarTexto(a, 27);
					escape();
				}
			}
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				break;
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
	}while(in!=ESCAPE);
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
				alert = num_check(year);
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

////-------------MENU SELECCION REGISTRO DOCENTE-------------
int registro_docent_select(){
	RETURN_RGD2:
	limpiar_data();
	CLS(1);
	registro_docente();
	char in, sec, aux, alert=0;
	int x;	
	
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
			
			RETORNO_RGD1:
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
					goto RETURN_RGD2;
				}else if(alert == 2){
					alert = 0;
					goto RETURN_RGD2;
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
					goto RETURN_RGD2;
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
					goto RETURN_RGD2;
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
				goto RETORNO_RGD1;
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
					goto RETURN_RGD2;
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
					goto RETORNO_RGD1;
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
					goto RETURN_RGD2;
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
				goto RETORNO_RGD1;
				break;
				}
			}else if(x==5){				//Funcion 5
				erase(77, 24, 80, 24);
				setColor(White, Black);
				cuadros2(75, 23, 6, 1);		//Cuadro anio
				in_year();
				alert = num_check(year);
				if(alert == 1){
					x=0;
					alert = 0;
					goto RETURN_RGD2;
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
				goto RETORNO_RGD1;
				break;
				}
				
			}else if(x==6){				//Funcion 5
				break;
			}
		}else if(in==ESCAPE){		//Acciones tecla ESCAPE
				CLS(0);
				return 3;
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
		return 3;
	}else if(aux==2){
		CLS(0);
		return 4;
	}
}