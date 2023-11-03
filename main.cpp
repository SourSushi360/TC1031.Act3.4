/*  main.cpp
    Jean Paul López Pándura
    
    Última modificación: 03/11/2023
    Este programa trabaja en conjunto con un archivo llamado bitacora3.txt,
    dónde están almacenados los registros de varios accesos fallidos con su
    respectivo código de error.
    
    El proceso va a almacenar estos registros en un AVL, el cual recordará
    la dirección IP y la cantidad de veces que aparece en la bitácora */
#include "classes/AVL.hpp"
#include <fstream>
#include <vector>
int main() {
    AVL avl;
    // lectura de los datos
    std::ifstream bitacora ("bitacora3.txt");
    std::string line;
    
    /*
    while (getline(bitacora,line)) {
        std::stringstream streamA(line);
        std::string ip;
        for (int i=0;i <= 3;i++){
            std::getline(streamA,ip,' ');
        }
        avl.insert(ip);
    }
    */
    Node node;
    for (int i=0;i < 5000;i++) {
        getline(bitacora,line);
        std::stringstream streamA(line);
        std::string ip;
        for (int i=0;i <= 3;i++){
            std::getline(streamA,ip,' ');
        }
        avl.insert(ip);
    }

    bitacora.close();
    
    // print de los datos en orden
    avl.print();

    return 1;
}