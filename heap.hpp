/**************************************************************************
 * Encabezado de Arboles Heap
 * Autor: Gerardo Rodríguez Hernández
 * Fecha: 19/10/2023
 * Descripcion:
 * El objetivo de esta actividad esimplementar el ADT MAX Heap
 * utilizando un vector como estructura subyascente
 **************************************************************************/

#ifndef HEAP_h
#define HEAP_h

#include <vector>
#include <iostream>
#include <stdexcept>

class Heap {
private:
    std::vector<int> heapArray;

    // Recorre el heap de abajo hacia arriba, intercambiando elementos
    // para mantener el orden del MAX heap.
    void heapifyUp(int index);
    
    // Recorre el heap desde la raíz, intercambiando elementos para mantener
    // el orden del MAX heap
    void heapifyDown(int index);

public:
    // Constructor
    Heap();

    // Destructor
    ~Heap();  

    // Inserta un nuevo elemento en el MAX heap
    void insert(int value);

    // Regresa el valor del elemento Máximo (raíz) del MAX heap
    int getMax();

    // Borra el elemento Máximo(Raiz) del MAX heap
    void deleteMax();
    
    // Regresa true si el heap está vacío
    bool isEmpty();
    
    // Regresa el número de elementos que contiene el heap
    int size();
    
    //Imprime cada uno de los datos almacenados en el HEAP dependiendo del parámetro en entrada
    // 1: Preorder
    // 2: Inorder
    // 3: Postorder
    // 4: Level by Level 
    void print(int option);
    void preorder(int index,std::vector<int> heapArray);
    void inorder(int index,std::vector<int> heapArray);
    void postorder(int index,std::vector<int> heapArray);
    void levelByLevel(std::vector<int> heapArray);
};

#endif