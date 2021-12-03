#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

#define limite 5
using namespace std;

int cantidadGente = 0;
int quedaUno;

void gotoxy(int x,int y){  
    HANDLE hCon;  
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y = y;  
    SetConsoleCursorPosition(hCon, dwPos);  
}

void muestraSitios(){
	gotoxy(40,2); 
	printf("Sala de espera");
	gotoxy(20,6); 
	printf("Barbero 1");
	gotoxy(60,6); 
	printf("Barbero 2");
	gotoxy(43,10); 
	printf("Cajas");
}

void actualizaSalaEspera(){
	gotoxy(40,4); 
	for(int k = 0; k < cantidadGente; k++) 
		printf("[ * ] "); 
	Sleep(1500);	
	if(cantidadGente == 1){
		cantidadGente -= 1;
		quedaUno = 1;
	}
	else
		cantidadGente -= 2;			
	system("cls");
	muestraSitios();	
	gotoxy(40,4); 
	for(int k = 0; k < cantidadGente; k++) 
		printf("[ * ] "); 
	Sleep(1000);
}

void actualizaBarberosyCajas(){
	if(quedaUno == 1){
		gotoxy(25,8); printf("[ * ]                                          "); Sleep(1000);
		gotoxy(25,8); printf("                                                 "); Sleep(500);
		gotoxy(44,12); printf("[ * ]"); Sleep(1000);
	}else{
		gotoxy(25,8); printf("[ * ]                                   [ * ]"); Sleep(1000);
		gotoxy(25,8); printf("                                                 "); Sleep(500);
		gotoxy(44,12); printf("[ * ] [ * ]"); Sleep(1000);		
	}
	system("cls");
}

void pideDatos(){
	printf("Cuanta gente hay en la sala de espera?:  ");
	scanf("%d", &cantidadGente);
	system("cls");
}

void proceso(){
	pideDatos();
	do{		
		muestraSitios();
		actualizaSalaEspera();
		actualizaBarberosyCajas();		
	}
	while(cantidadGente > 0);
	printf("\n\n\n\t FIN DEL PROGRAMA");
}

int main(){	
	proceso();	
	return 0;
}
