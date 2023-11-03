/*  heap.cpp
    Jean Paul López Pándura
    
    ultima modificación: 31/10/2023
    este programa define las funciones de la clase heap, declarada
    en heap.hpp */
#include "heap.hpp"
#include <iostream>

// constructores
Heap::Heap() {};
Heap::~Heap() {};
// private
void Heap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1)/2;
        if (heapArray[index] > heapArray[parentIndex]) {
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

        if (left < size && heapArray[left] > heapArray[largest]) {
            largest = left;
        } if (right < size && heapArray[right] > heapArray[largest]) {
            largest = right;
        } if (largest != index) {
            std::swap(heapArray[index],heapArray[largest]);
            index = largest;
        }
    } while (largest != index);
}
// public
void Heap::insert(int value) {
    int index = size();
    heapArray.push_back(value);
    heapifyUp(index);
}
int Heap::getMax() {
    return heapArray[0];
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
void Heap::print (int option) {
    switch (option) {
        case 1:
            preorder(0,heapArray);
            break;
        case 2:
            inorder(0,heapArray);
            break;
        case 3:
            postorder(0,heapArray);
            break;
        case 4:
            levelByLevel(heapArray);
            break;
        default:
            std::cout << "opcion invalida\n";
    }
}
// print helper
void Heap::preorder(int index,std::vector<int> heapArray) {
    if (index < heapArray.size()) {
        // Print the current element
        std::cout << heapArray[index] << " ";
        // Recursively traverse the left and right subtrees
        preorder(2 * index + 1,heapArray);
        preorder(2 * index + 2,heapArray);
    }
}
void Heap::inorder(int index,std::vector<int> heapArray) {
    if (index < heapArray.size()) {
        // Recursively traverse the left subtree
        inorder(2 * index + 1,heapArray);
        // Print the current element
        std::cout << heapArray[index] << " ";
        // Recursively traverse the right subtree
        inorder(2 * index + 2,heapArray);
    }
}
void Heap::postorder(int index,std::vector<int> heapArray) {
    if (index < heapArray.size()) {
        // Recursively traverse the left and right subtrees
        postorder(2 * index + 1,heapArray);
        postorder(2 * index + 2,heapArray);
        // Print the current element
        std::cout << heapArray[index] << " ";
    }
}
void Heap::levelByLevel(std::vector<int> heapArray) {
    for (int i = 0; i < heapArray.size(); i++) {
        std::cout << heapArray[i] << " ";
    }
}
