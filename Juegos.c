#include<stdio.h>	//Lectura y escritura
#include<time.h>  //para generar los numeros aleatorios
#include<string.h>  //para obtener longitud de cadena
#include<conio.h>	//para el getch();
#include<stdlib.h>  //para limpiar la pantalla
#include<unistd.h>  //para el pid
#include<windows.h>  //para el sleep
#include<pthread.h>  //para los hilos

int ContadorCasillas=0, espacios=0; // Para los gatos
int tiempoMS=1000, banderaCorrecto=0, contadorJS=0, posicionJS=0, banderaTiempo=0, nivelJS=0, contadorPuntosJS=0, teclaIncorrecta=0;  //Para los hilos del Juego 4
//pthread_mutex_t MUTEX = PTHREAD_MUTEX_INITIALIZER;
char tecla; //  Tecla del juego 4

//  Estos tres arreglos son del juego 4
char numericoG[10] = {'0','1','2','3','4','5','6','7','8','9'};
char alfabeticoG[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char alfanumericoG[36] = {'a','b','1','c','2','d','3','e','f','4','g','h','5','i','6','j','k','7','l','m','n','8','o','p','q','9','r','s','t','0','u','v','w','x','y','z'};

char ArregloGato[3][3] = { {'*', '*', '*'},  
						   {'*', '*', '*'},  
						   {'*', '*', '*'}  };
						   
char ArregloGatoExtremo[10][10] = { {'*', '*', '*','*', '*', '*','*', '*', '*','*'}, 
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'},
									{'*', '*', '*','*', '*', '*','*', '*', '*','*'}   };

char monito[25][25] = {     {' ',' ',' ',' ',' ','.','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','w','W','W','W','W','W','w',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',' ','O',' ',' ',' ','O',' ',')',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','(',' ',' ',' ','w',' ',' ',' ',')',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','-','-','-','s','-','-','-',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ','3','=','=','=','=','H','=','=','=','=','K'} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','H',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ','\\',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ','\\',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ',' ',' ','\\',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',' ','\\',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
							{' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
							{' ','_','_','_','_','T','_','_','_','_',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} 	};
							
//------------------------------------------------------------------------    J U E G O   S E C R E T O    ---------------------------------------------------------------------------------------------

void errorExit(char *strerr){		//Mensaje de error en caso de que no se pueda crear algun hilo
	perror(strerr);
	exit(1);
}

void *hilo01_rutina(){  		//Contador de tiempo
	int asd=tiempoMS;
	banderaTiempo=0;
	int i;
	for(i=0; i<asd; i++){
		if(banderaCorrecto == 1){
			break;
		}else{
			//pthread_mutex_lock(&MUTEX);
			Sleep(1);
			contadorJS += 1;
			//pthread_mutex_unlock(&MUTEX);	
		}
	}
	//printf("\n\nBANDERA TIEMPO = 1  !!!!");
	printf("\n\nSe termino tu tiempo :(");
	banderaTiempo=1;	
}

void *hilo2_rutina(){		//Guarda y compara la tecla presionada con el tiempo del hilo01
	
	switch(nivelJS){
		case 1:
			while(banderaTiempo == 0){		//Mientras esté aún en tiempo
				if(banderaCorrecto != 1 && banderaTiempo == 0){
					tecla=getch();
					if(banderaTiempo != 0){		//Entra quí si se termina el tiempo
						banderaCorrecto=2;
					}
				}			
				if(tecla == numericoG[posicionJS] && banderaCorrecto != 2){   // Correcto
					tiempoMS-=10;
					contadorJS=0;
					banderaCorrecto=1;
					contadorPuntosJS+=1;
					break;
				}else{   			//Tecla erronea
					if(banderaCorrecto != 2){
						banderaCorrecto=2;
						teclaIncorrecta=1;
						printf("\n\nTecla incorrecta! :(");
					}
				}
			}
		break;
		
		case 2:
			while(banderaTiempo == 0){
				if(banderaCorrecto != 1 && banderaTiempo == 0){
					tecla=getch();
					if(banderaTiempo != 0){
						banderaCorrecto=2;
					}
				}			
				if(tecla == alfabeticoG[posicionJS] && banderaCorrecto != 2){	//Correcto
					tiempoMS-=10;
					contadorJS=0;
					banderaCorrecto=1;
					contadorPuntosJS+=1;
					break;
				}else{  
					if(banderaCorrecto != 2){
						banderaCorrecto=2;
						teclaIncorrecta=1;
						printf("\n\nTecla incorrecta! :(");
					}
				}
			}
		break;
		
		case 3:
			while(banderaTiempo == 0){
				if(banderaCorrecto != 1 && banderaTiempo == 0){
					tecla=getch();
					if(banderaTiempo != 0){
						banderaCorrecto=2;
					}
				}			
				if(tecla == alfanumericoG[posicionJS] && banderaCorrecto != 2){		//Correcto
					tiempoMS-=10;
					contadorJS=0;
					banderaCorrecto=1;
					contadorPuntosJS+=1;
					break;
				}else{   
					if(banderaCorrecto != 2){
						banderaCorrecto=2;
						teclaIncorrecta=1;
						printf("\n\nTecla incorrecta! :(");
					}					
				}
			}	
		break;	
		
		default:
			printf("\n\nERROR. Numero ingresado no valido\nSaliendo del programa...");	
			banderaCorrecto=2;
		break;
	}	
	
	if(banderaTiempo == 1 && banderaCorrecto != 1 && teclaIncorrecta != 1){
		//printf("\n\nSe termino tu tiempo :(");
		banderaCorrecto=2;
	}	
}
							
int dameAleatorio(int tipo){		//Genera un numero aleatorio personalizado para cada nivel de dificultad
	int n=0, x=0;	
	switch(tipo){
		case 1: 
			n = (x = 0+rand()%(9) );
			return n;
		break;
			
		case 2:
			n = (x = 0+rand()%(25) );
			return n;
		break;
		
		case 3:
			n = (x = 0+rand()%(35) );
			return n;
		break;
		
		break;
	}	
}							
							
//-----------------------------------------------------------------------------    A H O R C A D  O    --------------------------------------------------------------------------------------------
	
int compruebaGanadorAhorcado(char palabra[], char letras[], int longitud, int letrasLong){
	int contador=0;
	int i, j;
	for(i=0; i<longitud; i++){
		for(j=0; j<letrasLong; j++){
			if(palabra[i] == letras[j]){
				contador+=1;
				break;
			}
		}
	}
	if(contador == (longitud-espacios) ){
		return 1;
	}else{
		return 0;
	}
}	
	
int compruebaLetraRepetida(char palabra[], char letra, char letras[], int letrasLong){
	int bandera=5;
	int i;
	//printf("\n\nENTRO COMPRUEBA LETRA REPETIDA.\n\n\n");
	if(letrasLong >= 1){  // Esto quiere decir que solo entre aquí cuando NO sea el PRIMER TURNO
		for(i=0; i<letrasLong; i++){
			//printf("\n  Letras = %c   y LETRA INGRESADA = %c",letras[i], letra);
			if(letras[i] == letra){
				system("cls");
				printf("\n\n\n\tESA LETRA YA LA HABIAS INGRESADO ANTES, INTENTA CON OTRA.\n\n\n\n\n\n\n");
				bandera=0;
			}
		}
	}else{
		//printf("\nREGRESO 1");
		return 1;
	}
	if(bandera != 1){
		//printf("\nREGRESO BANDERA = %d ",bandera);
		return bandera;
	}else{
		return 1;
	}
}	
			
void cuentaEspacios(char palabra[]){
	int longitud=0;
	longitud = strlen(palabra);
	int i;
	for(i=0; i<longitud; i++ ){
		if(palabra[i] == ' '){
			espacios += 1;
			//printf("Encontre un espacio\n");
		}
	}
}			
							
void dibujaMonito(int errores){
	switch(errores){		
		case 1:		// Imprime palo vertical
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(i==24){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
		
		case 2:		// Imprime base
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
			
		case 3: 	// Imprime palo horizontal
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
		
		case 4: 	// Imprime palo vertical chiquito
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0 || j==19 && i<5 ){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
		
		case 5:
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0 || j==19 && i<5 || monito[i][j]=='(' || monito[i][j]==')' || monito[i][j]=='w' || monito[i][j]=='W' || monito[i][j]=='s' || monito[i][j]=='O' || monito[i][j]=='-'){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
	
		case 6:
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0 || j==19 && i<5 || monito[i][j]=='(' || monito[i][j]==')' || monito[i][j]=='w' || monito[i][j]=='W' || monito[i][j]=='s' || monito[i][j]=='O' || monito[i][j]=='-' || monito[i][j]=='H' ){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;					
		
		case 7:
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0 || j==19 && i<5 || monito[i][j]=='(' || monito[i][j]==')' || monito[i][j]=='w' || monito[i][j]=='W' || monito[i][j]=='s' || monito[i][j]=='O' || monito[i][j]=='-' || monito[i][j]=='H' || i==10 && j>19){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
		
		case 8:
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0 || j==19 && i<5 || monito[i][j]=='(' || monito[i][j]==')' || monito[i][j]=='w' || monito[i][j]=='W' || monito[i][j]=='s' || monito[i][j]=='O' || monito[i][j]=='-' || monito[i][j]=='H' || i==10 && j>13){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
		
		case 9:
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					if(j==5 || i==24 || i == 0 || j==19 && i<5 || monito[i][j]=='(' || monito[i][j]==')' || monito[i][j]=='w' || monito[i][j]=='W' || monito[i][j]=='s' || monito[i][j]=='O' || monito[i][j]=='-' || monito[i][j]=='H' || i==10 && j>13 || monito[i][j]=='/'){
						printf("%c",monito[i][j]);
					}
					else{
						printf(" ");
					}
				}
				printf("\n");
			}
		break;
		
		case 10:
			for(int i=0; i<25; i++){
				for(int j=0; j<25; j++){
					printf("%c", monito[i][j]);
				}
				printf("\n");
			}
		break;
		
		default:
			printf("ERROR. Medita tus errores durante tres dias en ayuno.");
		break;						
	}
	printf("\n\n\n");	
}							
				
int erroresAhorcado(char palabra[], char letras[], int longitud, int letrasLong){	
	//printf("\n\nEntro ERRORES AHORCADO...");
	//printf("\nPOSICION = %d", letrasLong-1);
	
	int x=0;
	for(int i=0; i<longitud; i++){
		if(palabra[i] == letras[letrasLong-1])
			x+=1;		
	}
	if(x >= 1){
		x=100;
	}else{
		x=1;
	}
	return x;}				
				
void despliegaPalabra(char palabra[], char letras[], int longitud){	
	char letra=0;
	int longitudLetras=0;
	longitudLetras = strlen(letras) ;
	
	for(int i=0; i<longitud; i++){
		for(int j=0; j<longitudLetras; j++){
			if(letras[j] == palabra[i]){
				letra = palabra[i];
			}			
		}
		if(letra == palabra[i]){
			printf(" %c ",letra);
		}else if(palabra[i] == ' '){
			printf("      ");
		}else{
			printf("  __  ");
		}
	}	
}				
				
// --------------------------------------------------------------------------------    G A T O S    -------------------------------------------------------------------------------------------				

int CompruebaGanador(int fila, int columna, int tipo){
	int Bandera=0, Ganador=0;
	int AcumBolaFila=0, AcumBolaColumna=0, AcumTacheFila=0, AcumTacheColumna=0;	
	ContadorCasillas+=1;	
	//printf("\n\nLLEGUE A COMPRUEBA GANADOR");	
	if(tipo==1){
		for(int i=0; i<fila; i++){
			for(int j=0; j<columna; j++){
				if(ArregloGato[i][j]=='O'){
					//printf("\n\nENTRO IF 01");
					AcumBolaFila+=1;
					if(AcumBolaFila == 3){
						//printf("\n\nENTRO IF ANIDADO 1");
						Ganador=1;
						Bandera=1;
						return Ganador;
					}
				}
				if(ArregloGato[i][j]=='X'){
					//printf("\n\nENTRO IF 02");
					AcumTacheFila+=1;
					if(AcumTacheFila == 3){
						//printf("\n\nENTRO IF ANIDADO 2");
						Ganador=2;
						Bandera=1;
						return Ganador;
					}
				}
				if(ArregloGato[j][i]=='O'){
					//printf("\n\nENTRO IF 03");
					AcumBolaColumna+=1;
					if(AcumBolaColumna == 3){
						//printf("\n\nENTRO IF ANIDADO 3");
						Ganador=1;
						Bandera=1;
						return Ganador;
					}
				}
				if(ArregloGato[j][i]=='X'){
					//printf("\n\nENTRO IF 04");
					AcumTacheColumna+=1;
					if(AcumTacheColumna == 3){
						//printf("\n\nENTRO IF ANIDADO 4");
						Ganador=2;
						Bandera=1;
						return Ganador;
					}
				}
			}
			AcumBolaFila=0;
			AcumBolaColumna=0;
			AcumTacheFila=0;
			AcumTacheColumna=0;
		}	
		if(ArregloGato[0][0]=='X' && ArregloGato[1][1]=='X' && ArregloGato[2][2]=='X'  ||  ArregloGato[2][0]=='X' && ArregloGato[1][1]=='X' && ArregloGato[0][2]=='X'){
			Ganador=2;
			Bandera=1;
			return Ganador;
		}
		if(ArregloGato[0][0]=='O' && ArregloGato[1][1]=='O' && ArregloGato[2][2]=='O'  ||  ArregloGato[2][0]=='O' && ArregloGato[1][1]=='O' && ArregloGato[0][2]=='O'){
			Ganador=1;
			Bandera=1;
			return Ganador;
		}		
		//printf("\n\nCONTADOR CASILLAS:   [%d]",ContadorCasillas);
		if(ContadorCasillas == 9){
			return 3;
		}			
		if(Ganador == 0){
			//printf("\n\n\nENTRO A DONDe NO HAY GANADOR EN COMRPROBAR\n\n\n");
			return 0;
		}
	}
	if(tipo==2){
		for(int i=0; i<fila; i++){
			for(int j=0; j<columna; j++){
				if(ArregloGatoExtremo[i][j]=='O'){
					//printf("\n\nENTRO IF 01");
					AcumBolaFila+=1;
					if(AcumBolaFila == 4){
						//printf("\n\nENTRO IF ANIDADO 1");
						Ganador=1;
						Bandera=1;
						return Ganador;
					}
				}							
				if(ArregloGatoExtremo[i][j]=='X'){
					//printf("\n\nENTRO IF 02");
					AcumTacheFila+=1;
					if(AcumTacheFila == 4){
						//printf("\n\nENTRO IF ANIDADO 2");
						Ganador=2;
						Bandera=1;
						return Ganador;
					}
				}
				if(ArregloGatoExtremo[i][j]=='*' || ArregloGatoExtremo[i][j]=='X'){
					AcumBolaFila=0;
				}	
				if(ArregloGatoExtremo[i][j]=='*' || ArregloGatoExtremo[i][j]=='O'){
					AcumTacheFila=0;
				}
				if(ArregloGatoExtremo[j][i]=='O'){
					//printf("\n\nENTRO IF 03");
					AcumBolaColumna+=1;
					if(AcumBolaColumna == 4){
						//printf("\n\nENTRO IF ANIDADO 3");
						Ganador=1;
						Bandera=1;
						return Ganador;
					}
				}
				if(ArregloGatoExtremo[j][i]=='X'){
					//printf("\n\nENTRO IF 04");
					AcumTacheColumna+=1;
					if(AcumTacheColumna == 4){
						//printf("\n\nENTRO IF ANIDADO 4");
						Ganador=2;
						Bandera=1;
						return Ganador;
					}
				}
				if(ArregloGatoExtremo[j][i]=='*' || ArregloGatoExtremo[j][i]=='X'){
					AcumBolaColumna=0;
				}
					if(ArregloGatoExtremo[j][i]=='*' || ArregloGatoExtremo[j][i]=='O'){
					AcumTacheColumna=0;
				}
			}
			AcumBolaFila=0;
			AcumBolaColumna=0;
			AcumTacheFila=0;
			AcumTacheColumna=0;
		}			
		//printf("\n\nCONTADOR CASILLAS:   [%d]",ContadorCasillas);
		if(ContadorCasillas > (fila*columna)-1  ){                      // -1 ---------------------------------------------------------------------------
			return 3;
		}			
		if(Ganador == 0){
			//printf("\n\n\nENTRO A DONDe NO HAY GANADOR EN COMRPROBAR\n\n\n");
			return 0;
		}
	}
		
}

void TurnoComputadora(int fila, int columna,int tipo){
	int fila_c=0, columna_c=0, bandera=0,bandera2=0,ganador=10;
	srand(time(NULL));	
	if(tipo==1){
		ganador = CompruebaGanador(3,3,1);
		while(bandera == 0 && ContadorCasillas < 9 && ganador == 0){
			//srand(time(NULL));
			for(int j=0; j<5; j++){
				columna_c = 0+rand()%(2-0+1);  //El rand es:  (mínimo)+rand()%([máximo]-[mínimo]+[1])
				fila_c = 0+rand()%(2-0+1);
				//printf("\n\n  X = [%d]  -  Y = [%d]",fila_c,columna_c);
			}		
			if(tipo==1){
				if(ArregloGato[1][1] == '*'){  //Para tirar en la casilla de en medio
				ArregloGato[1][1] = 'X';
				bandera=1;
				}
				else{
					if(ArregloGato[fila_c][columna_c] == '*'){ //Para llenar cualquier otra casilla random
						ArregloGato[fila_c][columna_c] = 'X';
						bandera=1;
					}
					else{
						//rep = rep+1;
						//printf("\nEntre a Recursividad  -  [%d]",rep);
						//printf("\nFila: [%d]    Columna: [%d]   Casillas:  [%d]",fila_c, columna_c,ContadorCasillas);
					}
				}
			}		
		}
	}		
	
	
	//Bandera = 0 -> No hay ganador   //Bandera2 = 1 -> Salir del ciclo ó Se efectuó tiro del tache
	//------------------------------------------------------------------------------------------------------------
	if(tipo==2){
		int ContAcumBolaFila=0, ContAcumTacheFila=0, ContAcumBolaColumna=0, ContAcumTacheColumna=0,NumAleatorio=0,BolaFila=0,TacheFila=0,BolaColumna=0,TacheColumna=0;
		ganador = CompruebaGanador(fila,columna,2);
		while(bandera2 == 0 && ContadorCasillas < (fila*columna)-1 && ganador == 0){	
			//printf("\n\nENTRO WHILE 1");		
			for(int q=0; q<fila; q++){
				//printf("\nQ = [%d]",q);
				for(int w=0; w<columna; w++){
					//printf("\nW = [%d]",w);						
					if(ArregloGatoExtremo[q][w]=='O'){
						//printf("\n\nENTRO IF 1 WHILE 1");
						ContAcumBolaFila+=1;
						BolaFila+=1;
					}										
					if(ArregloGatoExtremo[q][w]=='X'){
						//printf("\n\nENTRO IF 2 WHILE 1");
						ContAcumTacheFila+=1;
						TacheFila+=1;
					}
					//ALGORTIMO TAPAR 3 Y GANAR
					if(ContAcumTacheFila==3 || ContAcumBolaFila==3){
						//Cuenta Filas
						//printf("\n\nENTRO IF 3 WHILE 1");
						if(ArregloGatoExtremo[q][w+1]=='*' && w+1<columna && bandera2==0){
							//printf("\nENTRO IF ANIDADO 1 IF 3 WHILE 1");
							ArregloGatoExtremo[q][w+1]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",q,w+1);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[q][w-3]=='*' && w-3>=0 && bandera2==0){
							//printf("\nENTRO IF ANIDADO 2 IF 3 WHILE 1");							
							ArregloGatoExtremo[q][w-3]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",q,w-3);
							bandera2=1;
							break;
						}
					}
					if(ArregloGatoExtremo[q][w]=='*' || ArregloGatoExtremo[q][w]=='X'){
						//printf("\n\nENTRO IF 4 WHILE 1");
						ContAcumBolaFila=0;
						BolaFila=0;
					}	
					if(ArregloGatoExtremo[q][w]=='*' || ArregloGatoExtremo[q][w]=='O'){
						//printf("\n\nENTRO IF 5 WHILE 1");
						ContAcumTacheFila=0;
						TacheFila=0;
					}					
						//Comprueba Columnas
					if(ArregloGatoExtremo[w][q]=='O'){
						//printf("\n\nENTRO IF 6 WHILE 1");
						ContAcumBolaColumna+=1;
					}						
					if(ArregloGatoExtremo[w][q]=='X'){
						//printf("\n\nENTRO IF 7 WHILE 1");
						ContAcumTacheColumna+=1;
					}					
					if(ContAcumBolaColumna==3 || ContAcumTacheColumna==3){
						//Cuenta Columnas
						//printf("\n\nENTRO IF 8 WHILE 1");
						if(ArregloGatoExtremo[w+1][q]=='*' && w+1<fila && bandera2==0){
							//printf("\nENTRO IF ANIDADO 1 IF 8 WHILE 1");
							ArregloGatoExtremo[w+1][q]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",w+1,q);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[w-3][q]=='*' && q-3>=0 && bandera2==0){
							//printf("\nENTRO IF ANIDADO 2 IF 8 WHILE 1");
							ArregloGatoExtremo[w-3][q]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",w-3,q);
							bandera2=1;
							break;
						}
					}					
					if(ArregloGatoExtremo[w][q]=='*' || ArregloGatoExtremo[w][q]=='X'){
						//printf("\n\nENTRO IF 9 WHILE 1");
						ContAcumBolaColumna=0;
					}	
					if(ArregloGatoExtremo[w][q]=='*' || ArregloGatoExtremo[w][q]=='O'){
						//printf("\n\nENTRO IF 10 WHILE 1");
						ContAcumTacheColumna=0;
					}	
					
					
								
					//ALGORITMO TAPAR 2 Y GANAR					
					if(ContAcumBolaFila==2 || ContAcumTacheFila==2){
						//Cuenta Filas
						//printf("\n\nENTRO IF 11 WHILE 1");
						if(ArregloGatoExtremo[q][w+1]=='*' && w+1<columna && bandera2==0){
							//printf("\nENTRO IF ANIDADO 1 IF 11 WHILE 1");
							ArregloGatoExtremo[q][w+1]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",q,w+1);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[q][w-2]=='*' && w-2>=0 && bandera2==0){
							//printf("\nENTRO IF ANIDADO 2 IF 11 WHILE 1");							
							ArregloGatoExtremo[q][w-2]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",q,w-2);
							bandera2=1;
							break;
						}
						/*if(ArregloGatoExtremo[q][w-3]=='*' && w-3>=0 && bandera2==0){
							printf("\nENTRO IF ANIDADO 3 IF 3 WHILE 1");
							ArregloGatoExtremo[q][w-3]='X';
							printf("\nTIRO HECHO EN [%d] [%d]",q,w-3);
							bandera2=1;
						}*/
					}					
					if(ArregloGatoExtremo[q][w]=='*' || ArregloGatoExtremo[q][w]=='X'){
						//printf("\n\nENTRO IF 12 WHILE 1");
						ContAcumBolaFila=0;
						BolaFila=0;
					}	
					if(ArregloGatoExtremo[q][w]=='*' || ArregloGatoExtremo[q][w]=='O'){
						//printf("\n\nENTRO IF 13 WHILE 1");
						ContAcumTacheFila=0;
						TacheFila=0;
					}
					
						//Comprueba Columnas
					/*if(ArregloGatoExtremo[w][q]=='O'){
						printf("\n\nENTRO IF 14 WHILE 1");
						ContAcumBolaColumna+=1;
					}						
					if(ArregloGatoExtremo[w][q]=='X'){
						printf("\n\nENTRO IF 15 WHILE 1");
						ContAcumTacheColumna+=1;
					}*/				
					if(ContAcumBolaColumna==2 || ContAcumTacheColumna==2){
						//Cuenta Columnas
						//printf("\n\nENTRO IF 16 WHILE 1");
						if(ArregloGatoExtremo[w+1][q]=='*' && w+1<fila && bandera2==0){
							//printf("\nENTRO IF ANIDADO 1 IF 16 WHILE 1");
							ArregloGatoExtremo[w+1][q]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",w+1,q);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[w-2][q]=='*' && w-2>=0 && bandera2==0){
							//printf("\nENTRO IF ANIDADO 2 IF 16 WHILE 1");
							ArregloGatoExtremo[w-2][q]='X';
							//printf("\nTIRO HECHO EN [%d] [%d]",w-2,q);
							bandera2=1;
							break;
						}
						/*if(ArregloGatoExtremo[w][q-3]=='*' && q-3>=0 && bandera2==0){
							printf("\nENTRO IF ANIDADO 3 IF 8 WHILE 1");
							ArregloGatoExtremo[w][q-3]='X';
							printf("\nTIRO HECHO EN [%d] [%d]",w,q-3);
							bandera2=1;
						}*/
					}					
					if(ArregloGatoExtremo[w][q]=='*' || ArregloGatoExtremo[w][q]=='X'){
						//printf("\n\nENTRO IF 17 WHILE 1");
						ContAcumBolaColumna=0;
					}	
					if(ArregloGatoExtremo[w][q]=='*' || ArregloGatoExtremo[w][q]=='O'){
						//printf("\n\nENTRO IF 18 WHILE 1");
						ContAcumTacheColumna=0;
					}
					if(bandera == 1){
						break;
					}			
				}
					
				ContAcumBolaFila=0;
				ContAcumBolaColumna=0;
				ContAcumTacheFila=0;
				ContAcumTacheColumna=0;	
				if(bandera==1){
					break;
				}			
			}
			//ALGORITMO TAPAR 1
			while(bandera2 == 0){
				//printf("\n\nENTRO WHILE 2 WEEEEEEEEEEEEEEEEEEEEEEEEY");
				for(int a=0; a<fila; a++){
					srand(time(NULL));
					for(int s=0; s<columna; s++){						
						NumAleatorio = 1+rand()%(4+1);
						if(ArregloGatoExtremo[a][s]=='O' && NumAleatorio==1 && ArregloGatoExtremo[a-1][s]=='*' && a-1>=0 && bandera2==0 ){
							//printf("\nENTRO IF 1 WHILE 2");
							ArregloGatoExtremo[a-1][s]='X';
							printf("\nTIRO HECHO EN [%d] [%d]",a-1,s);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[a][s]=='O' && NumAleatorio==2 && ArregloGatoExtremo[a][s+1]=='*' && s+1<columna && bandera2==0 ){
							//printf("\nENTRO IF 2 WHILE 2");
							ArregloGatoExtremo[a][s+1]='X';
							printf("\nTIRO HECHO EN [%d] [%d]",a,s+1);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[a][s]=='O' && NumAleatorio==3 && ArregloGatoExtremo[a+1][s]=='*' && a+1<fila && bandera2==0 ){
							//printf("\nENTRO IF 3 WHILE 2");
							ArregloGatoExtremo[a+1][s]='X';
							printf("\nTIRO HECHO EN [%d] [%d]",a+1,s);
							bandera2=1;
							break;
						}
						if(ArregloGatoExtremo[a][s]=='O' && NumAleatorio==4 && ArregloGatoExtremo[a][s-1]=='*' && s-1>=0 && bandera2==0 ){
							//printf("\nENTRO IF 4 WHILE 2");
							ArregloGatoExtremo[a][s-1]='X';
							printf("\nTIRO HECHO EN [%d] [%d]",a,s-1);
							bandera2=1;
							break;
						}						
						if(bandera==1){
							break;
						}						
					}
					if(bandera==1){
						break;
					}
				}
			}
			/*if(ArregloGatoExtremo[fila_c][columna_c] == '*'){ //Para llenar cualquier otra casilla random
				ArregloGatoExtremo[fila_c][columna_c] = 'X';
				bandera=1;
			}*/
		}		
	}		
}

void LimpiarTablero(int fila, int columna,int tipo){
	if(tipo==1){
		for(int i=0; i<fila; i++){
			for(int j=0; j<columna; j++){
				ArregloGato[i][j]='*';
			}
		}
	}
	if(tipo==2){
		for(int i=0; i<fila; i++){
			for(int j=0; j<columna; j++){
				ArregloGatoExtremo[i][j]='*';
			}
		}
	}	
}

void MostrarTablero(int fila, int columna, int tipo){  //int tipo es el tipo de gato. 1 para el gato normal, 0 para el gato extremo.
	if(tipo == 1){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("[ %c ]  ",ArregloGato[i][j]);
			}
			printf("\n");
		}
	}
	else{
		for(int i=0; i<fila; i++){
			for(int j=0; j<columna; j++){
				printf("[ %c ]  ",ArregloGatoExtremo[i][j]);
			}
			printf("\n");
		}
	}
}

// -------------------------------------------------------------------------------    J U E G O S    ----------------------------------------------------------------------------------------------

int Gato(){
	int fila, columna,bandera=0,x=0;
	char JugarOtraVez='s';	
	while(bandera == 0){
		printf("\n\nEste es el tablero:  \n\n");
		MostrarTablero(3,3,1);
		printf("\nEn que fila quieres tirar?:   ");
		scanf("%d",&fila);
		printf("\nEn que columna quieres tirar?:   ");
		scanf("%d",&columna);
		system("cls");
		if(ArregloGato[fila][columna]=='O' || ArregloGato[fila][columna]=='X'  || fila>2 || columna>2 ){
			system("cls");
			printf("\nERROR. ESA CASILLA YA ESTA LLENA\nPor favor, ingrese una casilla valida.");
			bandera=0;
		}
		else{
			ArregloGato[fila][columna]='O';  //Llena la casilla con tu turno
			//bandera = CompruebaGanador(3,3,1);
			system("cls");
			TurnoComputadora(3,3,1);	
			bandera = CompruebaGanador(3,3,1);		
			//printf("\n\nBANDERA:  %d  \n\n",bandera);
		}		
		if(bandera == 1){
			system("COLOR B0");
			system("cls");
			printf("\n\nEste es el tablero:\n\n");
			MostrarTablero(3,3,1);
			printf("\n\nGANASTE!!");
		}
		if(bandera == 2){
			system("COLOR CF");
			system("cls");
			printf("\n\nEste es el tablero:\n\n");
			MostrarTablero(3,3,1);
			printf("\n\nPERDISTE :(  ");				
		}
		if(bandera == 3){
			system("cls");
			printf("\n\nEste es el tablero:\n\n");
			MostrarTablero(3,3,1);
			printf("\n\nEMPATE!! ");				
		}
	}
	printf("\n\n\tDESEAS VOLVER A JUGAR? [SI/NO] :   ");
	scanf("%s",&JugarOtraVez);
	if(JugarOtraVez == 's'){
		system("COLOR 70");
		system("cls");
		bandera=0;
		ContadorCasillas=0;
		LimpiarTablero(3,3,1);
		Gato();
	}
	if(JugarOtraVez == 'n'){
		system("COLOR 70");
		system("cls");
		ContadorCasillas=0;
		bandera=1;
		LimpiarTablero(3,3,1);
		printf("\n\n\n[ 1 ] - Ir al menu de juegos\n");
		printf("[ 2 ] - Salir\n");
		printf("\nQue deseas hacer?:   ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("\n\nVolviendo al menu de juegos...\n\n");
				return 1;
				break;
			case 2:
				printf("\n\nGracias por jugar!!  n.n ");
				return x;
				break;
			default: 
				printf("\n\nERROR. Numero ingresado no valido\nSaliendo del programa...");	
				return x;
				break;
		}		
	}
}

int GatoExtremo(){
	int filas, columnas,bandera=0,FilaTirar, ColumnaTirar,x=0;
	char JugarOtraVez='s';	
	printf("\n\nDe cuantas filas quieres que sea el gato? [Maximo 10] :   ");
	scanf("%d",&filas);
	printf("\n\nDe cuantas columnas quieres que sea el gato? [Maximo 10] :   ");
	scanf("%d",&columnas);
	if(filas<4 || columnas<4){
		printf("\nERROR. MATRIZ DEMASIADO CORTA. INGRESE NUMEROS MAYORES DE 4");
		bandera=10;
		system("cls");
		GatoExtremo();
	}
	while(bandera==0){
		printf("\n\nEste es el tablero:  \n\n");
		MostrarTablero(filas,columnas,2);
		printf("\nEn que fila quieres tirar?:   ");
		scanf("%d",&FilaTirar);
		printf("\nEn que columna quieres tirar?:   ");
		scanf("%d",&ColumnaTirar);
		system("cls");
		if(ArregloGatoExtremo[FilaTirar][ColumnaTirar]=='O' || ArregloGatoExtremo[FilaTirar][ColumnaTirar]=='X'  || FilaTirar > filas-1 || ColumnaTirar > columnas-1 ){
			system("cls");
			printf("\nERROR. ESA CASILLA YA ESTA LLENA O NO ESTA EN EL RANGO\nPor favor, ingrese una casilla valida.");
			bandera=0;
		}
		else{
			ArregloGatoExtremo[FilaTirar][ColumnaTirar]='O';  //Llena la casilla con tu turno	
			system("cls");		
			TurnoComputadora(filas,columnas,2);	
			bandera = CompruebaGanador(filas,columnas,2);		
			//printf("\n\nBANDERA:  %d  \n\n",bandera);
		}
		if(bandera == 1){
			system("COLOR B0");
			system("cls");
			printf("\n\nEste es el tablero:\n\n");
			MostrarTablero(filas,columnas,2);
			printf("\n\nGANASTE!!");
		}
		if(bandera == 2){
			system("COLOR CF");
			system("cls");
			printf("\n\nEste es el tablero:\n\n");
			MostrarTablero(filas,columnas,2);
			printf("\n\nPERDISTE :(  ");				
		}
		if(bandera == 3){
			system("cls");
			printf("\n\nEste es el tablero:\n\n");
			MostrarTablero(filas,columnas,2);
			printf("\n\nEMPATE!! ");				
		}		
	}
	printf("\n\n\tDESEAS VOLVER A JUGAR? [SI/NO] :   ");
	scanf("%s",&JugarOtraVez);
	if(JugarOtraVez == 's'){
		system("COLOR 70");
		bandera=0;
		ContadorCasillas=0;
		LimpiarTablero(filas,columnas,2);
		GatoExtremo();
	}	
	if(JugarOtraVez == 'n'){
		system("COLOR 70");
		bandera=1;
		ContadorCasillas=0;
		LimpiarTablero(filas,columnas,2);
		printf("\n\n\n[ 1 ] - Ir al menu de juegos\n");
		printf("[ 2 ] - Salir\n");
		printf("\nQue deseas hacer?:   ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("\n\nVolviendo al menu de juegos...\n\n");
				x=1;
				return x;
				break;
			case 2:
				printf("\n\nGracias por jugar!!  n.n ");
				return x;
				break;
			default: 
				printf("\n\nERROR. Numero ingresado no valido\nSaliendo del programa...");	
				return x;
				break;
		}
	}
}

int Ahorcado(){
	int bandera=0, longitud=0, x=0, errores=0, nivel=0, letrasLong=0, e=0, aciertos=0, ganador=0;
	char palabra[99], letras[26], JugarOtraVez='s', letra, pasa='n';
	
	printf("\n\n\t INSTRUCCIONES:  ");
	printf("\n\n1. Un jugador tiene que escribir una palabra, esa sera la que se use para el juego.");
	printf("\n2. Se jugara por turnos. Cada jugador puede escribir solo una letra por turno.");
	printf("\n3. Gana el jugador que logre escribir la palabra completa.");
	
	printf("\n\n[ 1 ] - Facil - Juega con una sola palabra.");
	printf("\n[ 2 ] - Dificil - Juega desde con una palabra hasta una frase completa.");
	printf("\n\nQue nivel de dificultad quieres? [Escribe el numero]:    ");
	scanf("%d", &nivel);
	if(nivel<1 || nivel>2){
		printf("\n\n\tERROR. Digita un numero valido.");
		system("cls");
		Ahorcado();
	}
	
	while(JugarOtraVez == 's'){		
		if(nivel == 1){     //Fácil
			printf("\n\n\nIngresa la palabra:   ");
			scanf("%s", &palabra);
			longitud = strlen(palabra) ;		
			system("cls"); 			
			while(errores != 10){
				while(bandera == 0){
					despliegaPalabra(palabra, letras, longitud);
					printf("\n\nEscribe una letra:   ");
					scanf("%s", &letra);
					bandera = compruebaLetraRepetida(palabra, letra, letras, letrasLong);					
			    }
			    bandera=0;
				letras[letrasLong] = letra;
				letrasLong+=1;
				e = erroresAhorcado(palabra, letras, longitud, letrasLong);	
				if(e > 99 ){
					aciertos+=1;
					e = 0;
				}else{
					errores = errores + e;
					e = 0;
				}				
				system("cls");
				printf("Llevas %d errores !!\n",errores);	
				//printf("Longitud palabra:  %d\n\n\n", longitud);
				dibujaMonito(errores);							
				if(errores == 10){
					system("COLOR CF");
					printf("\n\n\tLLEGASTE A 10 ERRORES. PERDISTE! :C ");										
				}
				ganador = compruebaGanadorAhorcado(palabra, letras, longitud, letrasLong);
				if(ganador == 1){
					system("COLOR B0");
					printf("\n\n\tACERTASTE TODO, GANASTE!!  :D ");
					errores = 10;
				}		
			}
		}		
		if(nivel == 2){ 	// Difícil
			printf("\n\n\nIngresa la palabra:   ");
			fflush(stdin);                  //Estas dos lineas comentadas van juntas
			scanf("%[^\n]", palabra);       //Son para leer una cadena incluyendo los ewspacios
			cuentaEspacios(palabra);
			longitud = strlen(palabra) ;		
			system("cls");
			do{
				while(bandera == 0){
					despliegaPalabra(palabra, letras, longitud);
					printf("\n\nEscribe una letra:   ");
					scanf("%s", &letra);
					bandera = compruebaLetraRepetida(palabra, letra, letras, letrasLong);					
			    }
			    bandera=0;
				letras[letrasLong] = letra;
				letrasLong+=1;
				e = erroresAhorcado(palabra, letras, longitud, letrasLong);	
				if(e > 99 ){
					aciertos+=1;
					e = 0;
				}else{
					errores = errores + e;
					e = 0;
				}				
				system("cls");
				printf("Llevas %d errores !!\n",errores);
				dibujaMonito(errores);							
				if(errores == 10){
					system("COLOR CF");
					printf("\n\n\tLLEGASTE A 10 ERRORES. PERDISTE! :C ");										
				}
				ganador = compruebaGanadorAhorcado(palabra, letras, longitud, letrasLong);
				if(ganador == 1 ){
					system("COLOR B0");
					printf("\n\n\tACERTASTE TODO, GANASTE!!  :D ");
					errores = 10;
				}				
			}while(errores != 10);
		}		
		printf("\n\n\tDESEAS VOLVER A JUGAR? [SI/NO] :   ");
		scanf("%s",&JugarOtraVez);
			if(JugarOtraVez == 's'){
				system("COLOR 70");
				espacios=0;
				for(int q=0; q<99; q++)
					palabra[q]=0;
				for(int w=0; w<26; w++)
					letras[w]=0;			
				Ahorcado();
			}
			if(JugarOtraVez == 'n'){
				system("COLOR 70");
				printf("\n\n\n[ 1 ] - Ir al menu de juegos\n");
				printf("[ 2 ] - Salir\n");
				printf("\nQue deseas hacer?:   ");
				scanf("%d",&x);
				switch(x){
					case 1:
						printf("\n\nVolviendo al menu de juegos...\n\n");
						return x;
						break;
					case 2:
						printf("\n\nGracias por jugar!!  n.n ");
						return x;
						break;
					default: 
						printf("\n\nERROR. Numero ingresado no valido\nSaliendo del programa...");	
						return x;
						break;
				}		
			}		
	}		
}

int JuegoSecreto(){
	
	int contador=0;
	char ran='s', otro, JugarOtraVez='s';
	int n=0, t=0, x=0;
	
	pthread_t thread1, thread2;
	
	system("cls");
	printf("\n\nINSTRUCCIONES:");
	printf("Escribe rapidamente la tecla que veas en pantalla.");
	printf("\n\n[ 1 ] - Facil - Juega con el teclado numerico.");
	printf("\n[ 2 ] - Dificil - Juega con el teclado alfabetico.");
	printf("\n[ 3 ] - EXTREMO - Juega con el teclado numerico y alfabetico.");
	printf("\n\nQue nivel de dificultad quieres? [Escribe el numero]:    ");
	scanf("%d", &nivelJS);
	if(nivelJS<1 || nivelJS>3){
		printf("\n\n\tERROR. Digita un numero valido.");
		system("cls");
		Ahorcado();
	}
	
	while(JugarOtraVez == 's'){
		switch(nivelJS){
			case 1:
				while(ran == 's'){
					n=dameAleatorio(1);
					posicionJS=n;					
					if(banderaCorrecto != 2){						
						printf("\n\n\n\n\tCARACTER:   %c               ",numericoG[n]);
						Sleep(250);
						system("cls");
						banderaCorrecto=0;
						
						if(0 != pthread_create(&thread1, NULL, hilo01_rutina, NULL))
							errorExit("Hilo 1 no puede ser creado");
						if(0 != pthread_create(&thread2, NULL, hilo2_rutina, NULL))
							errorExit("Hilo 1 no puede ser creado");
						pthread_join(thread1, NULL);
						pthread_join(thread2, NULL);							
					}else{
						system("COLOR CF");
						ran='n';
						Sleep(100);
					}
				}
			break;
			
			case 2:
				while(ran == 's'){
					n=dameAleatorio(2);	
					posicionJS=n;				
					if(banderaCorrecto != 2){
						printf("\n\n\n\n\tCARACTER:   %c               ",alfabeticoG[n]);
						Sleep(250);
						system("cls");
						banderaCorrecto=0;
						
						if(0 != pthread_create(&thread1, NULL, hilo01_rutina, NULL))
							errorExit("Hilo 1 no puede ser creado");
						if(0 != pthread_create(&thread2, NULL, hilo2_rutina, NULL))
							errorExit("Hilo 1 no puede ser creado");
						pthread_join(thread1, NULL);
						pthread_join(thread2, NULL);						
					}else{
						system("COLOR CF");
						ran='n';
						Sleep(100);
					}
				}
			break;
			
			case 3:
				while(ran == 's'){
					n=dameAleatorio(3);	
					posicionJS=n;				
					if(banderaCorrecto != 2){
						printf("\n\n\n\n\tCARACTER:   %c               ",alfanumericoG[n]);
						Sleep(250);
						system("cls");
						banderaCorrecto=0;
						
						if(0 != pthread_create(&thread1, NULL, hilo01_rutina, NULL))
							errorExit("Hilo 1 no puede ser creado");
						if(0 != pthread_create(&thread2, NULL, hilo2_rutina, NULL))
							errorExit("Hilo 1 no puede ser creado");
						pthread_join(thread1, NULL);
						pthread_join(thread2, NULL);
						}else{
							system("COLOR CF");
							ran='n';
							Sleep(100);
						}
					}
			break;				
		}	
		
		printf("\n\n\nTu tiempo final de:  %d",tiempoMS);
		printf("\n\n\n\n\tTU PUNTUACION ES DE:   %d", contadorPuntosJS);		
		printf("\n\n\tDESEAS VOLVER A JUGAR? [SI/NO] :   ");
		scanf("%s",&JugarOtraVez);
		if(JugarOtraVez == 's'){
			system("COLOR 70");	
			tiempoMS=1000;
			banderaCorrecto=0;
			contadorJS=0;
			posicionJS=0;
			banderaTiempo=0;
			nivelJS=0;
			contadorPuntosJS=0;	
			teclaIncorrecta=0;	
			JuegoSecreto();
		}
		if(JugarOtraVez == 'n'){
			system("COLOR 70");
			tiempoMS=1000;
			banderaCorrecto=0;
			contadorJS=0;
			posicionJS=0;
			banderaTiempo=0;
			nivelJS=0;
			contadorPuntosJS=0;	
			teclaIncorrecta=0;
			printf("\n\n\n[ 1 ] - Ir al menu de juegos\n");
			printf("[ 2 ] - Salir\n");
			printf("\nQue deseas hacer?:   ");
			scanf("%d",&x);
			switch(x){
				case 1:
					printf("\n\nVolviendo al menu de juegos...\n\n");
					return x;
					break;
				case 2:
					printf("\n\nGracias por jugar!!  n.n ");
					return x;
					break;
				default: 
					printf("\n\nERROR. Numero ingresado no valido\nSaliendo del programa...");	
					return x;
					break;
			}		
		}
	}		
}

// -------------------------------------------------------------------------------    M E N Ú S    ---------------------------------------------------------------------------------------------
	
int MenuJuegos(){
	int x=0;
	system("COLOR 70");
	printf("\nDigita el numero del juego que desees jugar.\n\n");
	printf("[ 1 ] - Gato\n");
	printf("[ 2 ] - Gato Extremo\n");
	printf("[ 3 ] - Ahorcado\n");
	printf("[ 4 ] -  ????  \n");
	printf("\nQue juego deseas jugar?:   ");
	scanf("%d",&x);	
	system("cls");
	return x;
}

void Opciones(){
	int Juego=0,n=0;
	Juego = MenuJuegos();
	
	switch(Juego){
		
		case 1:
			system("cls");
			n = Gato();
			if(n == 1){
				Opciones();
			}else{
				system("cls");
				system("COLOR 0F");
				printf("\n\n\tGRACIAS POR HABER JUGADO!!  n.n\n\n\n\n");
				exit(1);
			}
		break;
		
		case 2:
			system("cls");
			n = GatoExtremo();
			if(n == 1){
				Opciones();
			}else{
				system("cls");
				system("COLOR 0F");
				printf("\n\n\tGRACIAS POR HABER JUGADO!!  n.n\n\n\n\n");
				exit(1);
			}
		break;
		
		case 3:
			system("cls");
			n = Ahorcado();
			if(n == 1){
				Opciones();
			}else{
				system("cls");
				system("COLOR 0F");
				printf("\n\n\tGRACIAS POR HABER JUGADO!!  n.n\n\n\n\n");
				exit(1);
			}
		break;
		
		case 4: 
			system("cls");
			n = JuegoSecreto();
			if(n == 1){
				Opciones();
			}else{
				system("cls");
				system("COLOR 0F");
				printf("\n\n\tGRACIAS POR HABER JUGADO!!  n.n\n\n\n\n");
				exit(1);
			}
		break;
		
		default:
			printf("\n\tERROR. Por favor digite un numero valido\n\n");
			Opciones();
		break;			
	}	
}

int main(){	
	srand(getpid());
	Opciones();
	return 0;
}
