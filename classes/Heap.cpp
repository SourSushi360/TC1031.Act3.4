/*  Heap.cpp
    Jean Paul López Pándura
    Luis Fernando Cuevas Arroyo A01637254
    
    ultima modificación: 03/11/2023
    este programa define las funciones de la clase heap, declarada
    en Heap.hpp */
#include "Heap.hpp"

// constructores
Heap::Heap() {};
Heap::~Heap() {};
// private
void Heap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1)/2;
        if (heapArray[index].count > heapArray[parentIndex].count) {
            std::swap(heapArray[index],heapArray[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}
void Heap::heapifyDown(int index) {
    int size = heapArray.size();
    int left,right,largest;
   do {
        left = 2*index + 1;
        right = 2*index + 2;
        largest = index;

        if (left < size && heapArray[left].count > heapArray[largest].count) {
            largest = left;
        } if (right < size && heapArray[right].count > heapArray[largest].count) {
            largest = right;
        } if (largest != index) {
            std::swap(heapArray[index],heapArray[largest]);
            index = largest;
        }
    } while (largest != index);
}
void Heap::insert(Node *node) {
    
    int index = size();
    Ip aux;
    aux.count = node->getData();
    aux.port = node->getPort();
    heapArray.push_back(aux);
    heapifyUp(index);
}
// public
int Heap::getMax() {
    return heapArray[0].count;
}
void Heap::deleteMax() {
    if (isEmpty()) {
        return;
    }
    heapArray[0] = heapArray.back();
    heapArray.pop_back();
    heapifyDown(0);
}
bool Heap::isEmpty() {
    return heapArray.empty();
}
int Heap::size() {
    return heapArray.size();
}
void Heap::extract(Node *node) {
    if (node != nullptr) {
        this->insert(node);
        extract(node->getLeft());
        extract(node->getRight());
    }
}

// print helper
void levelByLevel(std::vector<Ip> heapArray) {
    for (int i = 0; i < heapArray.size(); i++) {
        std::cout << heapArray[i].port << " - " << heapArray[i].count << " times\n";
    }
}
void Heap::print () {
    levelByLevel(heapArray);
}
