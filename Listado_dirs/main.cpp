// Listado de directorios ------------ HP --------------------
// 02 Junio 2020
// Importando librerias necesarias
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include  <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <experimental/filesystem>
#include <filesystem>
using namespace std::filesystem;
using namespace std;

void explorar(path dir_name,ofstream& MyFile){
    /**
    * Funcion para explorar cada directorio,
    * se llama asi misma cada que encuentra un nuevo directorio.
    * Usamos <filesystem> para obtener la variable "size" 
    */
    DIR *dir;
    struct dirent *entry;                                         // Llamando estructuras necesarias para directorios
    struct stat info;

    //1 abrir
    dir = opendir(dir_name.c_str());
    if(!dir){
        cout<< "Directorio no encontrado\n" <<endl;               // If en caso de no existir ruta
        return;

    }

    //2 leer

    while (      (entry = readdir(dir))  !=NULL){                 // Cilco principal

        if( entry->d_name[0] != '.'){
            path myRoot(dir_name);
            myRoot /= path(entry->d_name);

            stat(myRoot.string().c_str(),&info);
            if(S_ISDIR(info.st_mode)){                            // Si es directorio, aplicamos recursividad                       
                MyFile <<"\""<<entry->d_name<<"\""<<": [ \n";
                explorar(myRoot,MyFile);
            }
            else{                                                 // En caso de no serlo imprimimos "name" y "size"
                
                MyFile <<"{ \"name\" :"<< "\""<<entry->d_name <<"\"," <<"\"size\":"<<file_size(myRoot)<<"},\n";
            }
        }
    }
    //3 Cerrar
    closedir(dir);                                                // Nos aseguramos de cerrar el directorio
    MyFile << "]\n";
}






int main(){
    
    string dir_name;                                              // Variables de inicio
    cin >> dir_name;
    ofstream MyFile("dir.json");                                  // Creamos dir.json
    MyFile << "{ \"files\":[\n";
    explorar(dir_name,MyFile);                                    // Funcion principal
    MyFile<<"}";

    MyFile.close();                                               // Cerramos dir.json
    return 0;
    }


