#include<stdio.h>

void Tres(){
	int x=0, y=0, operacion;
	
	//Pide datos
	printf("\nIngresa un numero entero positivo:  ");
	scanf("%d", &x);
	printf("Ingresa otro numero entero positivo:  ");
	scanf("%d", &y);
	
	if(x <= 0 || y <= 0){
		printf("Los datos ingresados no son validos. El resultado es: 0");
	}		
	else{
		printf("\n\n[1] - Suma\n[2] - Resta\n[3] - Multiplicacion\n[4] - Division\n\n");
		printf("De estas opciones, que operacion desea realizar?");
		scanf("%d", &operacion);	
			
		switch(operacion){
			case 1:
				printf("\n\tEl resultado de la suma es: %d", x + y);
				break;
			case 2:
				printf("\n\tEl resultado de la resta es: %d", x - y);
				break;
			case 3:
				printf("\n\tEl resultado de la multiplicacion es: %d", x * y);
				break;
			case 4:
				printf("\n\tEl resultado de la division es: %d", x/y);
				break;	
			default:	
				printf("El resultado es: 0");
				break;	
		}
	}		
}

void Dos(){
	//Pide datos
	float m1, b1, m2, b2;
	printf("\tRECTA UNO\n\n");
	printf("Dame el valor de la pendiente (m):  ");
	scanf("%f", &m1);
	printf("Dame el valor de la interseccion en el eje Y (b):  ");
	scanf("%f", &b1);
	printf("\t\n\nRECTA DOS\n\n");
	printf("Dame el valor de la pendiente (m):  ");
	scanf("%f", &m2);
	printf("Dame el valor de la interseccion en el eje Y (b):  ");
	scanf("%f", &b2);
	
	//Pregunta (condicion)
	if(m1 == m2){
		printf("Las rectas NO se intersectan\n\n\n");
	}		
	else{
		printf("Las rectas SI se intersectan");
		
		//Resuelve la ecuacion
		float m, b, x;
		m = (m2 * -1) + m1;
		b = (b1 * -1) + b2;
		x = b / m;
		
		//Sustituyendo
		float y;
		y = (m1 * x) + b1;
		
		//Imprimiendo resultado
		printf("\nSe intersectan en el punto ( %.2f , %.2f )\n\n\n", x,y);		
	}	
}

int main(){
	Dos();
	Tres();
	return 0;
}


