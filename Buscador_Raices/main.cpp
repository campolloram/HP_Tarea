// Raices de Polinomio ax^3 + bx^2 + cx + d ---------------- HP---------------------
// 02 Junio 2020
// Importando librerias necesarias
#include <cmath>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;




int main(){
	/**
	* Funcion para encontrar raices reales de polinimios
	* cubicos de la forma ax^3 + bx^2 + cx + d
	* utilizando division sintetica y formula general de 
	* polinomios cuadrados
	*/

	// Definiendo nuestras variables a utilizar:

	float a, b, c, d; 						// Coeficientes del polinomio
	int i;									// Iterador
	float discriminante;					// Aqui almacenaremos nuestro discriminante b^2 -4ac
	float RzDisc;							// Raiz del discriminante
	float a2, b2, c2, d2;					// Resultados de division sintetica
	float x, gradiente, x2, fx, error_abs;	// Variables par realizar Newton Raphson
	float raiz1,raiz2, raiz3;				// Nuestros ultimas dos raices
	

    cin >> a >> b >> c >> d;   // Leemos y guardamos valores
    // Tratamos de encontrar la primera raiz usando iteracion


    // Primero tratamos de encontrar una buena aproximacion para iniciar Newton R

    if( a + b + c + d < d ){
    	x = a + b + c + d;
    }
    else{
    	x = d;
    }
    if(raiz1 > a*8 + b*4 + c*2 + d){
    	x = a*8 + b*4 + c*2 + d;
    }

    x2 = x;
    // Ahora usamos Newton Raphson para encontrar nuestra primera raiz
	while(error_abs>.0001 or i <= 100000)     	// Le damos 1000 iteraciones como Maximo
	{
		x = x2;
		fx = (pow(x, 3) * a) + (pow(x, 2) * b) + (x * c) + (d);
		gradiente = (pow(x, 2) * a * 3) + (x * b * 2) + c;
		x2 = x - fx/gradiente;
		error_abs = abs(x2 - x)/x2;	
		i += 1;			
	}
	
	if(i == 100000){
		cout<<"{}"<<endl;			// Este if solo se cumple si llega al maximo de iteraciones
		return 0;
	}
	raiz1 = x2;

		
		
	// Aplicamos division sintetica y reducimos a polinomio cuadrado
	// En este caso nuestra i contiene el valor de nuestra primera raiz
	a2 = (raiz1 * 0) + a;
	b2 = (a2 * raiz1) + b;
	c2 = (b2 * raiz1) + c;							// Estos valores son los que usamos para resolver la ecuacion cuadratica
	d2 = (c2 * raiz1) + d;
	
	// 
	
	// Resolviendo la ecuacion general de polinomio cuadratico (-b +- sqrt(b^2 -4ac))/(2a)


	discriminante = ((b2 * b2) - (4 * a2 * c2));    			// Este es el discriminante del polinomio cuadrado de la forma b^2 - 4ac 
	
	RzDisc = sqrt(discriminante);								// Sacamos su raiz 
	
	
	raiz2 = ((-1 * b2) - (RzDisc)) / (2 * a2);					// Ahora solo sacamos (-b +- sqrt(discr))/(2a)
	
	raiz3 = ((-1 * b2) + (RzDisc)) / (2 * a2);

    // Imprimimos resultados de la forma solicitada:

    //cout<<"{ "<<i<<", "<<raiz2<<", "<<raiz3<<"}"<<endl;
    cout<<"{";
    if(raiz1 != 0)
    {
    	cout<<raiz1;
    }
    if(not isnan(raiz2))
    {
    	cout<<", "<<raiz2;
	}
	if(not isnan(raiz3))
	{
    	cout<<", "<<raiz3;		// Aqui solo checamos que sean numeros reales y no 0
	}

	cout<<"}"<<endl;
    return 0;

}