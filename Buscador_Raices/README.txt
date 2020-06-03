----------------------------------------README -------------------------------------------
--------------------------------- Ejercicio_2 Tarea HP -----------------------------------

 
Hecho por: Guillermo Campollo
Fecha: Junio 2 2020



REQUERIMIENTOS:

Este codigo se realizo con un compilador g++-9 e ISO c++17


FUNCIONAMIENTO:

La manera en la cual calcula las raices es:
1. Primero usamos Newton Raphson para encontrar nuestra primer raiz utilizando 100,000 iteraciones como maximo o un error absoluto de .0001
2. Teniendo esta raiz, utilizamos division sintetica para encontrar nuestro polinomio cuadratico.
3. Usando el polinimio cuadratico utilizamos la formula general (-b +- sqrt(b^2 -4ac))/(2a) y encontramos nuestras siguientes dos raices despejando.


	
EJECUCION:

El programa recive 4 flotantes los cuales representan los coeficientes de un polinomio de la forma ax^3 + bx^2 + cx + d Dichos numeros se dan de forma descendente (primero a luego b ...) y regresa como resultado un print de la forma "{}" en caso de no encontrar raices y {r1,r2,r3} en caso de si encontrar raices.


INFORMACION ADICIONAL:

El codigo fue creado usando Linux con distribucion Ubuntu 20.04 y se buildeo con CMAKE 3.16
