/*
Libreria de Funciones y estructuras
-Colocar aqui las funciones principales
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include "Portadas.h"
#define MAX_L 100

char usuario[MAX_L];
char contra[MAX_L];
char cedula[9];
char name1[MAX_L];
char name2[MAX_L];
char apellido1[MAX_L];
char apellido2[MAX_L];
char day[4];
char month[4];
char year[4];
char contraRegist[MAX_L];
char correoinst[MAX_L];

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void limpiarCadena(char *cadena){
	memset(cadena, 0, strlen(cadena));
}

int nullComp(const char *cadena) {
    if (cadena == NULL || strlen(cadena) == 0) {
        return 1; // La cadena estÃ¡ vacÃ­a
    }
    return 0; // La cadena no estÃ¡ vacÃ­a
}

int numeros(char a[]){
	int i;
	int error = 0;
	while(a[i] != '\0'){
		if(a[i] < '0' || a[i] > '9'){
			error = 1;
			break;
		}
		i++;
	}
	return error;
}

int letras(char a[]){
	int i;
	int error = 0;
	while(a[i] != '\0'){
		if((a[i] < 'A' || a[i] > 'Z') && (a[i] < 'a' || a[i] > 'z') && (a[i] != ' ')){
			error = 1;
			break;
		}
		i++;
	}	
	return error;
}

const int MAX_MATERIAS = 3;
const int MAX_ALUMNOS = 5;

struct Fecha {
    std::string dia;
    std::string mes;
    std::string anio;
};

struct Usuario {
    std::string nombreUsuario;
    std::string contrasenia;
};

struct Persona {
    std::string identificacion;
    std::string nombre1;
    std::string nombre2;
    std::string apellido1;
    std::string apellido2;
    Fecha fechaNacimiento;
};

struct Docente {
    Persona persona;
    int valid;
    int codigoDocente;
    std::string materiaAsignada;
    Usuario usuario;
};

struct Notas {
    float nota1;
    float nota2;
    float nota3;
};

struct Materia {
    std::string nombre;
    Docente docente;
};

struct Alumno {
    Persona persona;
    int valid;
    int codigoEstudiante;
    Usuario usuario;
    std::string materias[MAX_MATERIAS];
    Notas notasPorMateria[MAX_MATERIAS];
};

Alumno alumno1;
Alumno alumno2;
Alumno alumno3;
Alumno alumno4;
Alumno alumno5;

void signInUser(){
	gotoxy(27, 15); cin.getline(usuario, 60, '\n'); fflush(stdin);
}

void signInPass(){
	gotoxy(27, 20); cin.getline(contra, 60, '\n'); fflush(stdin);
}

//FUNCIONES GENERALES DE INGRESO
bool verificar_cedula(int vect[]){
	int i,r,s=0,s1=0,st=0;
	for(i=0;i<10;i=i+2){
		r= vect[i]*2;
		if(r>9)
		r-=9;
		s+=r;
	}


	for(i=1;i<9;i=i+2){
		s1+=vect[i];
	}
	st=10-((s+s1)%10);
		if(st==10)
		st=0;
		if(vect [9]==st)
		return true;
		else
		return false;
}
//Ingreso de la cedula.
void in_cedula() {
    mostrarCursor();
    gotoxy(37, 8);
    scanf("%[^\n]", cedula); fflush(stdin);
//    fgets(cedula, 10, stdin);
//    limpiarBuffer(); // Limpia el bÃºfer despuÃ©s de leer la cÃ©dula
    ocultarCursor();
}

int cedula_check(){
	char solonum[MAX_L] = {"SOLO INGRESE NUMEROS"};
	char verif[MAX_L] = {"CEDULA NO VALIDA"};
	int error=0, validacion, tam;
	
	error=numeros(cedula);
	tam = strlen(cedula);
	if(error==1){
		error=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(45, 11, 28, 5);
		printf("\a");
		centrarTexto(solonum, 14);
		CLS(1700);
		return 1;
	}
	int cedint[9]; // DeclaraciÃ³n de una matriz de enteros para almacenar los dÃ­gitos
    int contador = 0;

    // Convertir cada dÃ­gito de la cadena en un entero y almacenarlo en la matriz
    for (int i = 0; i < 9; i++) {
        if (cedula[i] >= '0' && cedula[i] <= '9') {
            cedint[contador] = cedula[i] - '0'; // Convertir carÃ¡cter a entero
            contador++;
        }
    }
 
	validacion=verificar_cedula(cedint);
	if(validacion){
		validacion=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(46, 11, 26, 5);
		printf("\a");
		centrarTexto(verif , 14);
		CLS(1700);
		return 2;
	}else{
		return 3;
	}
}


void in_names() {
	mostrarCursor();
    char temp[MAX_L * 2]; // Un solo bÃºfer para ambos nombres
    
    gotoxy(37, 13);
    fgets(temp, sizeof(temp), stdin);
    
    // Extraer los nombres del bÃºfer
    sscanf(temp, "%s %s", name1, name2); // Suponiendo que name1 y name2 son globales
	ocultarCursor();
}

void in_lastnames() {
	mostrarCursor();
    char temp[MAX_L * 2]; // Un solo bÃºfer para ambos apellidos
    
    gotoxy(37, 18);
    fgets(temp, sizeof(temp), stdin);
    
    // Extraer los apellidos del bÃºfer
    sscanf(temp, "%s %s", apellido1, apellido2); // Suponiendo que apellido1 y apellido2 son globales
	ocultarCursor();
}

void in_day(){
	mostrarCursor();
    gotoxy(38, 24);
    scanf("%2s", day);
    fflush(stdin);
    ocultarCursor();
}

int num_check(char *num){
	char solonum[MAX_L] = {"SOLO INGRESE NUMEROS"};
	int error=0;
	
	error=numeros(num);
	if(error==1){
		error=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(45, 11, 28, 5);
		printf("\a");
		centrarTexto(solonum, 14);
		CLS(1700);
		return 1;
	}
	return 0;
}

int word_check(char word[MAX_L], char word2[MAX_L]){
	char soloword[MAX_L] = {"SOLO INGRESE LETRAS"};
	int error=0, error2=0;
	error=letras(word);
	error2=letras(word2);
	
	if(error == 1 || error2 == 1){
		error=0;
		ocultarCursor();
		CLS(0);
		margenes();
		cuadros1(45, 11, 28, 5);
		printf("\a");
		centrarTexto(soloword, 14);
		CLS(1700);
		return 1;
	}
	return 0;
}

void in_month(){
	mostrarCursor();
    gotoxy(59, 24);
    scanf("%2s", month);
    fflush(stdin);
    ocultarCursor();
}

void in_year(){
	mostrarCursor();
    gotoxy(77, 24);
    cin.getline(year, 5, '\n');
    fflush(stdin);
    ocultarCursor();
}

void imprimir_datos(){
	CLS(0);
	
	char titulo[MAX_L] = {"REGISTRO"};
	
	margenes();
	cuadros1(53, 2, 12, 1);
	centrarTexto(titulo, 3);
	gotoxy(6, 5); printf("DATOS INGRESADOS");
	gotoxy(6,7); printf("CEDULA:\t");		cout<<cedula;
	gotoxy(6,9); printf("NOMBRES:\t");		cout<<name1<<" "<< name2;
	gotoxy(6, 11); printf("APELLIDOS:\t");	cout<<apellido1<<" "<<apellido2;
	gotoxy(6, 13); printf("FECHA DE NACIMIENTO:\t");	cout<<day<<"/"<<month<<"/"<<year;	

	cuadros1(24, 20, 8, 1);
	gotoxy(26, 21);	printf("CERRAR");
	cuadros1(80, 20, 11, 1);
	gotoxy(82, 21);	printf("CONFIRMAR");
}

void limpiar_data(){
	limpiarCadena(usuario);
	limpiarCadena(contra);
	limpiarCadena(contraRegist);
	limpiarCadena(cedula);
	limpiarCadena(name1);
	limpiarCadena(name2);
	limpiarCadena(apellido1);
	limpiarCadena(apellido2);
	limpiarCadena(day);
	limpiarCadena(month);
	limpiarCadena(year);
	limpiarCadena(correoinst);
}

void limpiarDocentes(std::vector<Docente>& docentes) {
    for (auto& docente : docentes) {
        docente.persona.identificacion = "";
        docente.persona.nombre1 = "";
        docente.persona.nombre2 = "";
        docente.persona.apellido1 = "";
        docente.persona.apellido2 = "";
        docente.persona.fechaNacimiento = {0, 0, 0};
        docente.codigoDocente = 0;
        docente.materiaAsignada = "";
        docente.usuario.nombreUsuario = "";
        docente.usuario.contrasenia = "";
    }
}

void limpiarAlumno(Alumno& alumno) {
    alumno.persona.identificacion = "";
    alumno.persona.nombre1 = "";
    alumno.persona.nombre2 = "";
    alumno.persona.apellido1 = "";
    alumno.persona.apellido2 = "";
    alumno.persona.fechaNacimiento.dia = "";
    alumno.persona.fechaNacimiento.mes = "";
    alumno.persona.fechaNacimiento.anio = "";
    alumno.codigoEstudiante = 0;
    for (int i = 0; i < MAX_MATERIAS; ++i) {
        alumno.materias[i] = "";
        alumno.notasPorMateria[i].nota1 = 0.0f;
        alumno.notasPorMateria[i].nota2 = 0.0f;
        alumno.notasPorMateria[i].nota3 = 0.0f;
    }
    alumno.usuario.nombreUsuario = "";
    alumno.usuario.contrasenia = "";
}

void comprobar(){
	if(nullComp(cedula) || nullComp(name1) || nullComp(name2) || nullComp(apellido1) || nullComp(apellido2) || nullComp(day) || nullComp(month) || nullComp(year) ){
		CLS(100);
		margenes();
		char salida[MAX_L] = {"PORFAVOR VUELVA A REALIZAR EL PROCESO"};
		char error[MAX_L] = {"VALORES INCOMPLETOS"};
		char a[MAX_L] = {"Pulse ESC para salir"};
		centrarTexto(salida, 16);
		centrarTexto(error, 14);
		centrarTexto(a, 27);
		escape();
	}else{
		
	}
}

void mayus_a_minus(char palabra[], int n) {
    for (int i = 0; i < n; i++) {
        if (palabra[i] >= 'A' && palabra[i] <= 'Z') {
            palabra[i] = palabra[i] + 32; // Diferencia entre mayÃºsculas y minÃºsculas
        }
    }
}

//GENERAR NRC
int generarCodigo() {
    int longitud = rand() % 2 + 4; // Generar longitud aleatoria entre 4 y 5
    int codigo;

    if (longitud == 4) {
        codigo = rand() % 9000 + 1000;
    } else {
        codigo = rand() % 90000 + 10000;
    }

    return codigo;
}

void generarCorreoPersonalizado(char *correo, char *name1 , char *name2, char *lastname) {
	int n;
	strcpy(correo, "");
    strncat(correo, name1, 1); // Primera letra del primer nombre
    strncat(correo, name2, 1); // Primera letra del segundo nombre
    strcat(correo, lastname);
    strcat(correo, "@espe.edu.ec");
    
    n = strlen(correo);
    mayus_a_minus(correo, n);
}

// FUNCION PARA VALIDAR EL CORREO ELECTRONICO: JOSUE CHIRIBOGA
bool validarCorreo(const char *correo) {
    int atCount = 0;  // Contador de símbolos '@'
    int dotCount = 0; // Contador de símbolos '.'
    int length = strlen(correo); // Obtiene la longitud de la cadena
    // Recorre cada caracter en la cadena
    for (int i = 0; i < length; i++) {
        if (correo[i] == '@') {
            atCount++; // Incrementa el contador si encuentra '@'
        } else if (correo[i] == '.') {
            dotCount++; // Incrementa el contador si encuentra '.'
        }
    }
    // Verifica si hay exactamente un '@' y al menos un '.'
    return (atCount == 1 && dotCount >= 1);
}

/*int main() {
    // ... (código previo)
    for (int i = 0; i < cantidadEstudiantes; i++) {
        // ... (código previo)
        if (validarCorreo(estudiantes[i].correo.correoinst)) {
            printf("Correo electronico valido: %s\n", estudiantes[i].correo.correoinst);
        } else {
            printf("Correo electronico NO valido: %s\n", estudiantes[i].correo.correoinst);
        }
    }
    return 0;
}*/

void guardarDocenteEnArchivo(const Docente& docente, std::ofstream& archivo) {
    archivo << "Identificacion: " << docente.persona.identificacion << std::endl;
    archivo << "Nombres: " << docente.persona.nombre1 << " " << docente.persona.nombre2 << std::endl;
    archivo << "Apellidos: " << docente.persona.apellido1 << " " << docente.persona.apellido2 << std::endl;
    archivo << "Fecha Nacimiento: " << docente.persona.fechaNacimiento.dia << "/"
            << docente.persona.fechaNacimiento.mes << "/" << docente.persona.fechaNacimiento.anio << std::endl;
    archivo << "Codigo: " << docente.codigoDocente << std::endl;
    archivo << "Materia Asignada: " << docente.materiaAsignada << std::endl;
    archivo << "Usuario: " << docente.usuario.nombreUsuario << std::endl;
    archivo << "Contrasenia: " << docente.usuario.contrasenia << std::endl;
    archivo << "                         " << std::endl;
	
}

void guardarAlumnoEnArchivo(const Alumno& alumno, std::ofstream& archivo) {
	archivo << "Identificacion: " << alumno.persona.identificacion << std::endl;
    archivo << "Nombres: " << alumno.persona.nombre1 << " " << alumno.persona.nombre2 << std::endl;
    archivo << "Apellidos: " << alumno.persona.apellido1 << " " << alumno.persona.apellido2 << std::endl;
    archivo << "Fecha Nacimiento: " << alumno.persona.fechaNacimiento.dia << "/"
            << alumno.persona.fechaNacimiento.mes << "/" << alumno.persona.fechaNacimiento.anio << std::endl;
    archivo << "Codigo: " << alumno.codigoEstudiante << std::endl;
    archivo << "Materias: ";
    for (int i = 0; i < MAX_MATERIAS; ++i) {
        archivo << alumno.materias[i] << " " << alumno.notasPorMateria[i].nota1 << " "
                << alumno.notasPorMateria[i].nota2 << " " << alumno.notasPorMateria[i].nota3;
        if (i < MAX_MATERIAS - 1) {
            archivo << ", ";
        }
    }
    archivo << std::endl;
    archivo << "Usuario: " << alumno.usuario.nombreUsuario << std::endl;
    archivo << "Contrasenia: " << alumno.usuario.contrasenia << std::endl;
    archivo << "                         " << std::endl;
}

void guardar_credenciales_alumno(const Alumno& alumno, std::ofstream& init){
	init << "Usuario: " << alumno.usuario.nombreUsuario << std::endl;
    init << "Contrasenia: " << alumno.usuario.contrasenia << std::endl;
    init << "                         " << std::endl;
}

void guardar_credenciales_docente(const Docente& docente, std::ofstream& init){
	init << "Usuario: " << docente.usuario.nombreUsuario << std::endl;
    init << "Contrasenia: " << docente.usuario.contrasenia << std::endl;
    init << "                         " << std::endl;
}

void imprimir_studentTXT(){
	Alumno alumno_aux = {
        {cedula, name1, name2, apellido1, apellido2, {day, month, year}},1,
        generarCodigo(), {correoinst, contraRegist}
    };
    
    ofstream archivo;
    ofstream init;
    
    archivo.open("estudiante.txt", ios::app);
	init.open("credenciales.txt", ios::app);
	
	if (archivo.is_open() && init.is_open()) {
        guardarAlumnoEnArchivo(alumno_aux, archivo);
        guardar_credenciales_alumno(alumno_aux, init);

        archivo.close();
        init.close();
    } else {
		CLS(100);
		margenes();
		char salida[MAX_L] = {"FALLO AL REGISTRAR"};
		char a[MAX_L] = {"Pulse ESC para salir"};
		centrarTexto(salida, 14);
		centrarTexto(a, 27);
		escape();
    }
}

void imprimir_docentTXT(){
	Docente docent_aux = {
        {cedula, name1, name2, apellido1, apellido2, {day, month, year}},
        2, generarCodigo(), "MATERIA", {correoinst, contraRegist}
    };
    
    ofstream archivo;
    ofstream init;
    
    archivo.open("docente.txt", ios::app);
	init.open("credenciales.txt", ios::app);
	
	if (archivo.is_open() && init.is_open()) {
        guardarDocenteEnArchivo(docent_aux, archivo);
        guardar_credenciales_docente(docent_aux, init);

        archivo.close();
        init.close();
    } else {
		CLS(100);
		margenes();
		char salida[MAX_L] = {"FALLO AL REGISTRAR"};
		char a[MAX_L] = {"Pulse ESC para salir"};
		centrarTexto(salida, 14);
		centrarTexto(a, 27);
		escape();
    }
}


void final_registro_alumno(char *correo){
	CLS(0);
	generarCorreoPersonalizado(correoinst, name1, name2, apellido1);
	char titulo[MAX_L] = {"REGISTRO"};
	char mensaje[MAX_L] = {"Su correo institucional es:"};
	char contrasenia[MAX_L] = {"Create a password (8 espacios)"};
	
	margenes();
	cuadros1(53, 2, 12, 1);
	centrarTexto(titulo, 3);
	centrarTexto(mensaje, 5);
	centrarTexto(correoinst, 7);
	centrarTexto(contrasenia, 12);
	
	cuadros1(32, 14, 55, 1);
	mostrarCursor();
	gotoxy(55, 15); scanf("%9s", contraRegist);
	ocultarCursor();
	imprimir_studentTXT();	
}

void final_registro_docente(char *correo){
	CLS(0);
	generarCorreoPersonalizado(correoinst, name1, name2, apellido1);
	char titulo[MAX_L] = {"REGISTRO"};
	char mensaje[MAX_L] = {"Su correo institucional es:"};
	char contrasenia[MAX_L] = {"Create a password (8 espacios)"};
	
	margenes();
	cuadros1(53, 2, 12, 1);
	centrarTexto(titulo, 3);
	centrarTexto(mensaje, 5);
	centrarTexto(correoinst, 7);
	centrarTexto(contrasenia, 12);
	
	cuadros1(32, 14, 55, 1);
	mostrarCursor();
	gotoxy(55, 15); scanf("%9s", contraRegist);
	ocultarCursor();
	imprimir_docentTXT();	
}

bool verificarCredenciales(const std::string& usuario, const std::string& contrasenia) {
    if (usuario.empty() || contrasenia.empty()) {
        return false;  // Si alguna de las cadenas de ingreso está vacía
    }

    std::ifstream archivo("credenciales.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo de credenciales." << std::endl;
        return false;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Usuario: ") != std::string::npos) {
            std::string usuarioArchivo = linea.substr(9);  // Saltar "Usuario: "
            if (getline(archivo, linea) && linea.find("Contrasenia: ") != std::string::npos) {
                std::string contraseniaArchivo = linea.substr(13);  // Saltar "Contrasenia: "

                if (usuarioArchivo == usuario && contraseniaArchivo == contrasenia) {
                    archivo.close();
                    return true;  // Credenciales coinciden
                }
            }
        }
    }

    archivo.close();
    return false;  // Credenciales no coinciden
}

//GENERAR CODIGO ESTUDIANTE
int numeroUsuario = 1; // Variable global para el número de usuario

/*// Función para generar el código de usuario
void generarCodigo(struct Persona *persona) {
    sprintf(persona->codigoUsuario, "L%04d", numeroUsuario);
    numeroUsuario++;
}*/

void calcularPromedio(int nota1, int nota2, int nota3) {
    int suma = nota1 + nota2 + nota3;
    int promedio = suma;

    printf("El promedio es: %d\n", promedio);

    if (suma >= 42) {
        printf("Aprobado");
    } else {
        printf("Reprobado");
    }
}

