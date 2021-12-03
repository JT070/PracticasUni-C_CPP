#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char Alfabeto[52]={'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'    };
char Cadena[50];



int recursividad(int x){
    int Resultado=0;
    if(x==0){ //esta condición es para detener la recursividad, se detiene cuando el parámetro ahora es cero.
        return(Resultado);  //regresa el resultado de la operación contenida en el else
    }
    else{
        Resultado = x + recursividad(x-1);  //se manda a lmar a si misma la función y se le resta 1 cada vez que se vuelve a llamar
    }
}

void NumerosAleatorios(){
    int tt=0, x=0;
    srand(time(0));
    int arr[50];
	int i=0;
    for(i=0; i<10; i++){
        arr[i] = (x = 1+rand()%(9) );  //Llena el arreglo con numeros aleatorios del 1 al 100
        //printf("[%d] ", arr[i]); esto nomas es una prueba de escritorio xdxd
        //tt = recursividad(arr[i]); //se manda a llamar la función de recursividad y el valor que devuelve se asigna a la variable tt
        //if(tt == 15){  //compara la variable que sea igual al número que nosotros escojamos arbitrariamente (el que el programador elija)
        //    printf("El numero es [%d] y esta en la posicion [%d] del arreglo!! \n\n",arr[i],i ); //imprime el numero que empieza la sucesión y su poscion en el arreglo
        //}
        printf("[%d]  ", arr[i]);
    }
    printf("\n\n");
}

void NumerosyLetras(){
	
	int NumeroMaximoVecesCaracterRepetido=3 , LongitudCadena = 15;  //ESTOS VALORES SE PUEDEN EDITAR O PERSONALIZAR
	
    int NumeroAleatorio=0, AleatorioChiquito=0;
    int i=0,j=0,k=0,qq=0;  //Iteradores
    int arr[50];
    char Letra;
    srand(time(0));

    while(i < LongitudCadena){
        AleatorioChiquito = 1+rand()%(NumeroMaximoVecesCaracterRepetido) ;
        for(j=0; j < AleatorioChiquito; j++){
            NumeroAleatorio = 1+rand()%(9);
            for(qq; qq<1000000000; qq++){}			
            printf("%d",NumeroAleatorio);
            i=i+1;
            NumeroAleatorio = 0;
        }
        AleatorioChiquito =0 ;
        AleatorioChiquito = 1+rand()%(NumeroMaximoVecesCaracterRepetido);
        for(k=0; k < AleatorioChiquito; k++){
            NumeroAleatorio = 1+rand()%(52);
            for(qq; qq<1000000000; qq++){}	
            Letra = Alfabeto[NumeroAleatorio];
            printf("%c",Letra);
            i=i+1;
            NumeroAleatorio = 0;
        }
        AleatorioChiquito =0 ;
    }
    printf("\n\n");
}

int main(){
    //NumerosAleatorios();
    NumerosyLetras();
    return 0;
}
