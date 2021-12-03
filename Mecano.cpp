#include<stdio.h>	//Lectura y escritura
#include<time.h>  //para generar los numeros aleatorios
#include<conio.h>	//para el getch();
#include<stdlib.h>  //para limpiar la pantalla
#include<unistd.h>  //para el pid
#include<windows.h>  //para el sleep

int dedos[8], cantidad_dedos=0, puntos=0;

char indice_derecho[9]  = { '6','7','y','u','h','j','n','m',' ' };
char medio_derecho[5]   = { '8','i','k',',',' ' };
char anular_derecho[5]  = { '9','o','l','.',' ' };
char menique_derecho[7] = { '0','p','-','{','+','}',' ' };

char indice_izquierdo[9]  = { '4','5','r','t','f','g','v','b',' ' };
char medio_izquierdo[5]   = { '3','e','d','c',' ' };
char anular_izquierdo[5]  = { '2','w','s','x',' ' };
char menique_izquierdo[7] = { '|','1','q','a','z','<',' ' };

char mano_izquierda[26] = { '4','5','r','t','f','g','v','b',' ','3','e','d','c',' ','2','w','s','x',' ','|','1','q','a','z','<',' ' };
char mano_derecha[28]   = { '6','7','y','u','h','j','n','m',' ','8','i','k',',',' ','9','o','l','.',' ','0','p','ñ','-','{','+','¿','}',' ' };
char ambas_manos[54]    = { '4','5','r','t','f','g','v','b',' ','3','e','d','c',' ','2','w','s','x',' ','|','1','q','a','z','<',' ',
							'6','7','y','u','h','j','n','m',' ','8','i','k',',',' ','9','o','l','.',' ','0','p','ñ','-','{','+','¿','}',' ' };

int comprueba_error(int tipo, int tecla, int aleatorio, int dedo){	
	switch(tipo){
		case 1:
			if(tecla == mano_izquierda[aleatorio]){
				puntos+=1;
				return	0;
			}else{
				system("COLOR CF");
				printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
				return	1;		
			}
		break;
		
		case 2:
			if(tecla == mano_derecha[aleatorio]){
				puntos+=1;
				return	0;
			}else{
				system("COLOR CF");
				printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
				return	1;		
			}
		break;
		
		case 3:
			if(tecla == ambas_manos[aleatorio]){
				puntos+=1;
				return	0;
			}else{
				system("COLOR CF");
				printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
				return	1;		
			}
		break;
		
		case 4:
			switch(dedo){
				case 1:
					if(tecla == indice_izquierdo[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;	
					
				case 2:
					if(tecla == medio_izquierdo[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;
					
				case 3:
					if(tecla == anular_izquierdo[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;
				
				case 4:
					if(tecla == menique_izquierdo[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;
				
				case 5:
					if(tecla == indice_derecho[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;
				
				case 6:
					if(tecla == medio_derecho[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;
				
				case 7:
					if(tecla == anular_derecho[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;
				
				case 8:
					if(tecla == menique_derecho[aleatorio]){
						puntos+=1;
						return 0;
					}else{
						system("COLOR CF");
						printf("\n\n\tINCORRECTO!       TECLA PULSADA:  %c", tecla);
						return 1;		
					}
				break;									
			}				
		break;	
	}	
}

void elige_dedos(int dedos_cantidad){
	int dedo=0, dedo_repetido=0, n=0;
	
	if(dedos_cantidad == 1){
		printf("\n\n %d° DEDO :  ", n+1);
		scanf("%d", dedos[0]);
	}
	if(dedos_cantidad > 1){
		while(dedos_cantidad > 0){
			printf("\n\n %d° DEDO :  ", n+1);
			scanf("%d", &dedo);
			for(int i=0; i<n; i++){
				if(dedos[i] == dedo){   		
					printf("\n\n\tERROR!. ESE DEDO YA LO HABIAS INGRESADO, POR FAVOR INGRESA OTRO.");
					dedo_repetido=1;
					break;
				}				
			}
			if(dedo_repetido != 1){
				dedos[n] = dedo;
				n+=1;
				dedos_cantidad-=1;
			}		
		}	
	}
}

int imprime_instrucciones(int tipo){
	int ayuda=0;
	
	if(tipo == 4){		
		printf("\n\nCuantos dedos quieres utilizar?:   ");
		scanf("%d", &cantidad_dedos);
		if(cantidad_dedos == 0 || cantidad_dedos >8){
			printf("\n\n\tERROR!. POR FAVOR INGRESA UN NUMERO VALIDO.");
			imprime_instrucciones(4);
		}else{
			system("cls");
			printf("\n\nEstos son los dedos disponibles:   ");
			printf("\n\n[ 1 ] - INDICE IZQUIERDO");
			printf("\n[ 2 ] - MEDIO IZQUIERDO");
			printf("\n[ 3 ] - ANULAR IZQUIERDO");
			printf("\n[ 4 ] - MENIQUE IZQUIERDO");
			printf("\n[ 5 ] - INDICE DERECHO");
			printf("\n[ 6 ] - MEDIO DERECHO");
			printf("\n[ 7 ] - ANULAR DERECHO");
			printf("\n[ 8 ] - MENIQUE DERECHO");
			printf("\n\nCuales vas a usar? (Escribe el numero de dedo):   ");
			elige_dedos(cantidad_dedos);
			system("cls");
			printf("\n\n\tINTRUCCIONES: Presiona la tecla que veas en pantalla con los dedos correspondientes");
			printf("\n\nNecesitas ayuda para saber que tecla coresponde a cada dedo? [ 1 = SI / 0 = NO ]:   ");
			scanf("%d", &ayuda);
			system("cls");
			printf("\n\n\n\n\tCOMENZAMOS!!");
			Sleep(1000);
			system("cls");
		}		
	}else{
		system("cls");
		printf("\n\n\tINTRUCCIONES: Presiona la tecla que veas en pantalla con los dedos correspondientes");
		printf("\n\nNecesitas ayuda para saber que tecla coresponde a cada dedo? [ 1 = SI / 0 = NO ]:   ");
		scanf("%d", &ayuda);
		system("cls");
		printf("\n\n\n\n\tCOMENZAMOS!!");
		Sleep(1000);
		system("cls");
	}	
	return ayuda;	
}

void imprime_ayuda(int tipo, int aleatorio, int dedo){
	switch(tipo){
		case 1:			//Mano izquierda
			if(aleatorio >= 0 && aleatorio <= 7)
				printf("\n\n\n\n\t[ INDICE IZQUIERDO ]       ");
			else if(aleatorio >= 9 && aleatorio <= 12)
				printf("\n\n\n\n\t[  MEDIO IZQUIERDO ]       ");
			else if(aleatorio >= 14 && aleatorio <= 17)
				printf("\n\n\n\n\t[ ANULAR IZQUIERDO ]       ");
			else if(aleatorio >= 19 && aleatorio <= 24)
				printf("\n\n\n\n\t[ MENIQUE IZQUIERDO ]       ");	
			else if(mano_izquierda[aleatorio] == ' ')
				printf("\n\n\n\n\t[ ESPACIO ]       ");	
			else
				printf("\n\n\n\n\tERROR!. ALEATORIO FUERA DE RANGO.");	
		break; 
		
		case 2: 		//Mano derecha
			if(aleatorio >= 0 && aleatorio <= 7)
				printf("\n\n\n\n\t[ INDICE DERECHO ]       ");
			else if(aleatorio >= 9 && aleatorio <= 12)
				printf("\n\n\n\n\t[ MEDIO DERECHO ]       ");
			else if(aleatorio >= 14 && aleatorio <= 17)
				printf("\n\n\n\n\t[ ANULAR DERECHO ]       ");
			else if(aleatorio >= 19 && aleatorio <= 26)
				printf("\n\n\n\n\t[ MENIQUE DERECHO ]       ");
			else if(mano_derecha[aleatorio] == ' ')
				printf("\n\n\n\n\t[ ESPACIO ]       ");	
			else
				printf("\n\n\n\n\tERROR!. ALEATORIO FUERA DE RANGO.");		
		break;	
		
		case 3:			//Ambas manos
			if(aleatorio >= 0 && aleatorio <= 7)
				printf("\n\n\n\n\t[ INDICE IZQUIERDO ]       ");
			else if(aleatorio >= 9 && aleatorio <= 12)
				printf("\n\n\n\n\t[ MEDIO IZQUIERDO ]       ");
			else if(aleatorio >= 14 && aleatorio <= 17)
				printf("\n\n\n\n\t[ ANULAR IZQUIERDO ]       ");
			else if(aleatorio >= 19 && aleatorio <= 24)
				printf("\n\n\n\n\t[ MENIQUE IZQUIERDO ]       ");	
			if(aleatorio >= 26 && aleatorio <= 33)
				printf("\n\n\n\n\t[ INDICE DERECHO]       ");
			else if(aleatorio >= 35 && aleatorio <= 38)
				printf("\n\n\n\n\t[ MEDIO DERECHO ]       ");
			else if(aleatorio >= 40 && aleatorio <= 43)
				printf("\n\n\n\n\t[ ANULAR DERECHO ]       ");
			else if(aleatorio >= 45 && aleatorio <= 52)
				printf("\n\n\n\n\t[ MENIQUE DERECHO ]       ");
			else if(ambas_manos[aleatorio] == ' ')
				printf("\n\n\n\n\t[ ESPACIO ]       ");		
		break;
		
		case 4:			//Dedo x dedo
			switch(dedo){
				case 1: 
					printf("\n\n\n\n\t[ INDICE IZQUIERDO ]       ");
					if(indice_izquierdo[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}						
				break;
				case 2: 
					printf("\n\n\n\n\t[ MEDIO IZQUIERDO ]       ");
					if(medio_izquierdo[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;
				case 3: 
					printf("\n\n\n\n\t[ ANULAR IZQUIERDO ]       ");
					if(anular_izquierdo[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;
				case 4: 
					printf("\n\n\n\n\t[ MENIQUE IZQUIERDO ]       ");
					if(menique_izquierdo[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;
				case 5: 
					printf("\n\n\n\n\t[ INDICE DERECHO ]       ");
					if(indice_derecho[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;
				case 6: 
					printf("\n\n\n\n\t[ MEDIO DERECHO ]       ");
					if(medio_derecho[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;
				case 7: 
					printf("\n\n\n\n\t[ ANULAR DERECHO ]       ");
					if(anular_derecho[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;
				case 8: 
					printf("\n\n\n\n\t[ MENIQUE DERECHO ]       ");
					if(menique_derecho[aleatorio] == ' '){
						system("cls");
						printf("\n\n\n\n\t[ ESPACIO ]       ");	
					}
				break;				
			}
		break;							
	}
	
}

int dameAleatorio(int limite){		
	int n=0, x=0;		
	n = (x = 0+rand()%(limite) );
	return n;			
}

int izquierda(int tipo){
	int ayuda=0, aleatorio=0, aleatorio_dos=0, error=0, mano=0, dedo=0;
	char tecla, jugar, caracter;
	
	ayuda = imprime_instrucciones(tipo);	
	while(error == false){		
		switch(tipo){
			case 1:
				system("cls");
				aleatorio=dameAleatorio(25);		
				if(ayuda == true)
					imprime_ayuda(tipo, aleatorio, 0);	
				printf("\n\n\n\n\n\t [ %c ]", mano_izquierda[aleatorio]);
				tecla=getch();	
				error=comprueba_error(tipo, tecla, aleatorio, 0); 				
			break;
			
			case 2:
				system("cls");
				aleatorio=dameAleatorio(27);		
				if(ayuda == true)
					imprime_ayuda(tipo, aleatorio,0);	
				printf("\n\n\n\n\n\t [ %c ]", mano_derecha[aleatorio]);
				tecla=getch();	
				error=comprueba_error(tipo, tecla, aleatorio, 0); 
			break;
			
			case 3:
				system("cls");
				aleatorio=dameAleatorio(53);		
				if(ayuda == true)
					imprime_ayuda(tipo, aleatorio,0);	
				printf("\n\n\n\n\n\t [ %c ]", ambas_manos[aleatorio]);
				tecla=getch();	
				error=comprueba_error(tipo, tecla, aleatorio, 0); 
			break;
			
			case 4:
				system("cls");
				aleatorio_dos = dameAleatorio(cantidad_dedos);  //Me da la POSICIÓN del arreglo dedos[]
				dedo = dedos[aleatorio_dos];			//Saco el DEDO correspondiente a la posición				
														
				if(dedo == 1 || dedo == 5 )					
					aleatorio = dameAleatorio(9);
				else if(dedo == 4 || dedo == 8)
					aleatorio = dameAleatorio(7);
				else
					aleatorio = dameAleatorio(5);		
									
				if(ayuda == true)
					imprime_ayuda(tipo, aleatorio, dedo);	
							
							
				switch(dedo){
					case 1:
						printf("\n\n\n\n\n\t [ %c ]", indice_izquierdo[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;	
					
					case 2:
						printf("\n\n\n\n\n\t [ %c ]", medio_izquierdo[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;
					
					case 3:
						printf("\n\n\n\n\n\t [ %c ]", anular_izquierdo[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;
					
					case 4:
						printf("\n\n\n\n\n\t [ %c ]", menique_izquierdo[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;
					
					case 5:
						printf("\n\n\n\n\n\t [ %c ]", indice_derecho[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;
					
					case 6:
						printf("\n\n\n\n\n\t [ %c ]", medio_derecho[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;
					
					case 7:
						printf("\n\n\n\n\n\t [ %c ]", anular_derecho[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;
					
					case 8:
						printf("\n\n\n\n\n\t [ %c ]", menique_derecho[aleatorio]);
						tecla=getch();
						error=comprueba_error(tipo, tecla, aleatorio, dedo);
					break;									
				}				
			break;					
		}
				
	}	
	printf("\n\n\n\tPUNTOS LOGRADOS:  [ %d ] ", puntos);
	printf("\n\n\n\nDeseas volver a jugar?:  [ SI / NO ]: ");
	scanf("%s", &jugar);
	if(jugar == 's'){
		system("cls");
		system("COLOR 70");
		return 1;
	}else if(jugar == 'n'){
		system("cls");
		return 0;
	}else{
		printf("\n\n\n\nCARACTER NO VALIDO. SALIENDO...");
		Sleep(1000);
		return 0;
	}		
}

void opciones(){
	int opcion=0, n=0;
	
	system("COLOR 70");
	printf("\n\n\n\tBienvenido al programa para mejorar tu mecanografia!");
	printf("\n\n[ 1 ] - Solo mano IZQUIERDA");
	printf("\n[ 2 ] - Solo mano DERECHA");
	printf("\n[ 3 ] - AMBAS MANOS");
	printf("\n[ 4 ] - DEDO POR DEDO");
	printf("\n\nQue modalidad deseas?:   ");
	scanf("%d", &opcion);	
	n = izquierda(opcion);
	if(n == false){
		system("COLOR 0F");
		printf("\n\n\n\tGRACIAS POR USAR LA APLICACION!!!   n.n");
	}		
	else
		opciones();
}

int main(){	
	srand(getpid());
	opciones();
	return 0;
}
