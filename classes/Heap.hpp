/*  Heap.hpp
    Jean Paul López Pándura
    
    Última modificación: 03/11/2023
    Este header declara las funciones y atributos de la clase Heap */
#ifndef HEAP_HPP
#define HEAP_HPP

#include "Node.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

/*  estructura que guarda la cuenta y el puerto de un valor del AVL */
struct Ip {
    /*  un vector que guarda la cantidad de veces que aparece el puerto en
    la bitácora */
    int count;
    /*  un vector que guarda la ip */
    int port;
};

class Heap {
private:
    /*  estructura que guarda la cuenta y el puerto de un valor del AVL */
    std::vector<Ip> heapArray;

    /* Recorre el heap de abajo hacia arriba, intercambiando elementos
       para mantener el orden del MAX heap */
    void heapifyUp(int index);
    
    /*  Recorre el heap desde la raíz, intercambiando elementos para mantener
        el orden del MAX heap */
    void heapifyDown(int index);
    /*  Inserta un nuevo elemento en el MAX heap */
    void insert(Node* node);

public:
    /*  Constructor */
    Heap();
    /*  Destructor */
    ~Heap();  

    /*  Regresa el valor del elemento Máximo (raíz) del MAX heap */
    int getMax();
    /*  Borra el elemento Máximo(Raiz) del MAX heap */
    void deleteMax();
    /*  Regresa true si el heap está vacío */
    bool isEmpty();
    /*  Regresa el número de elementos que contiene el heap */
    int size();
    /*  función que extrae todos los nodos dentro de aun AVL 
    y los mete en un heap */
    void extract(Node* node);
    /*  imprime el heap en preorder */
    void print();
};

#endif  /* HEAP_HPP */