/*  Heap.hpp
    Jean Paul López Pándura
    
    Última modificación: 03/11/2023
    Este header declara las funciones y atributos de la clase Heap */
#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class Heap {
private:
    /*  un vector que guarda la cantidad de veces que aparece el puerto en
    la bitácora */
    std::vector<int> heapArray;
    /*  un vector que guarda la ip */
    std::vector<std::string> ip;

    /* Recorre el heap de abajo hacia arriba, intercambiando elementos
       para mantener el orden del MAX heap */
    void heapifyUp(int index);
    
    /*  Recorre el heap desde la raíz, intercambiando elementos para mantener
        el orden del MAX heap */
    void heapifyDown(int index);

public:
    /*  Constructor */
    Heap();
    /*  Destructor */
    ~Heap();  

    /*  Inserta un nuevo elemento en el MAX heap */
    void insert(int value);
    /*  Regresa el valor del elemento Máximo (raíz) del MAX heap */
    int getMax();
    /*  Borra el elemento Máximo(Raiz) del MAX heap */
    void deleteMax();
    /*  Regresa true si el heap está vacío */
    bool isEmpty();
    /*  Regresa el número de elementos que contiene el heap */
    int size();
};

#endif  /* HEAP_HPP */