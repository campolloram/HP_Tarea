----------------------------------------README -------------------------------------------
--------------------------------- Ejercicio_1 Tarea HP -----------------------------------

 
Hecho por: Guillermo Campollo
Fecha: Junio 2 2020



REQUERIMIENTOS:

	En este codigo se utiliza la libreria <filesystem> la cual en caso de ser compilada desde una cpu con OS Linux, necesita usarse compiladores >'g++-9'  para que compile correctamente. Se utiliza el ISO c++17, el cual esta especificado en CMakeLists.txt


FUNCIONAMIENTO:

	El programa hace uso de recursion en caso de encontrarse con directorios dentro del directorio base. Inicialmente no habia implementado recursion pero como no especificaba el problema correctamente que hacer en caso de encontrar un directorio, preferi incluir esta modalidad.
	
	
EJECUCION:

Una vez que se ejecuta el programa, le pedira al usuario que ingrese la ruta absoluta del directorio deseado, este programa generara un archivo llamado dir.json el cual contiene todos los archivos dentro del directorio base.


INFORMACION ADICIONAL:

El codigo fue creado usando Linux con distribucion Ubuntu 20.04 y como antes mencionado la libreria <filesystem> para poder ejecutarse en distribuciones diferentes.




