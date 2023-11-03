/*  main.cpp
    Jean Paul López Pándura
    
    Última modificación: 03/11/2023
    Este programa trabaja en conjunto con un archivo llamado bitacora3.txt,
    dónde están almacenados los registros de varios accesos fallidos con su
    respectivo código de error.
    
    El proceso va a almacenar estos registros en un AVL, el cual recordará
    la dirección IP y la cantidad de veces que aparece en la bitácora */
#include "classes/AVL.hpp"
#include "classes/Heap.hpp"
#include <fstream>
#include <vector>

int main() {
    AVL avl;
    // lectura de los datos
    std::ifstream bitacora ("bitacora3.txt");
    std::string line;
    
    while (getline(bitacora,line)) {
        std::stringstream streamA(line);
        std::string ip;
        for (int i=0;i <= 3;i++) {
            std::getline(streamA,ip,' ');
        }
        std::stringstream streamB(ip);
        for (int i=0;i < 2;i++) {
            std::getline(streamB,ip,':');
        }
        avl.insert(ip);
    }

    bitacora.close();

    // agrega los valores al heap
    Heap heap;
    heap.extract(avl.getRoot());
    heap.print();

    return 1;
}