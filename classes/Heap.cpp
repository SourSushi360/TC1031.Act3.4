/*  Heap.cpp
    Jean Paul López Pándura
    Luis Fernando Cuevas Arroyo A01637254

    última modificación: 03/11/2023
    Este programa define las funciones de la clase heap, declarada
    en Heap.hpp */
#include "Heap.hpp"
#include <fstream>

// constructores
Heap::Heap(){};

Heap::~Heap(){};

// private

// Función para subir un elemento en el montículo
void Heap::heapifyUp(int index) {
  while (index > 0) {
    int parentIndex = (index - 1) / 2;
    if (heapArray[index]->getData() > heapArray[parentIndex]->getData()) {
      std::swap(heapArray[index], heapArray[parentIndex]);
      index = parentIndex;
    } else {
      break;
    }
  }
  // Complejidad: O(log n), donde "n" es el número de elementos en el montículo.
}

// Función para bajar un elemento en el montículo
void Heap::heapifyDown(int index) {
  int size = heapArray.size();
  
  while (true) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heapArray[left]->getData() > heapArray[largest]->getData()) {
      largest = left;
    }

    if (right < size && heapArray[right]->getData() > heapArray[largest]->getData()) {
      largest = right;
    }

    if (largest == index) {
      break;
    }

    std::swap(heapArray[index], heapArray[largest]);
    index = largest;
  }
  // Complejidad: O(log n), donde "n" es el número de elementos en el montículo.
}

// Insertar un elemento en el montículo
void Heap::insert(Node *node) {
  int index = size();
  heapArray.push_back(node);
  heapifyUp(index);
  // Complejidad: O(log n), donde "n" es el número de elementos en el montículo.
}

// public

// Obtener el elemento máximo del montículo
Node* Heap::getMax() {
  return heapArray[0];
  // Complejidad: O(1), ya que siempre se devuelve el primer elemento del
  // montículo.
}

// Eliminar el elemento máximo del montículo
void Heap::deleteMax() {
  if (isEmpty()) {
    return;
  }
  heapArray[0] = heapArray.back();
  heapArray.pop_back();
  heapifyDown(0);
  // Complejidad: O(log n), donde "n" es el número de elementos en el montículo.
}

// Verificar si el montículo está vacío
bool Heap::isEmpty() {
  return heapArray.empty();
  // Complejidad: O(1), ya que simplemente verifica si el vector subyacente está
  // vacío.
}

// Obtener el número de elementos en el montículo
int Heap::size() {
  return heapArray.size();
  // Complejidad: O(1), ya que simplemente devuelve el tamaño del vector
  // subyacente.
}

// Extraer elementos del árbol y agregarlos al montículo
void Heap::extract(Node *node) {
  if (node != nullptr) {
    this->insert(node);
    extract(node->getLeft());
    extract(node->getRight());
  }
  // Complejidad: O(m * log n), donde "m" es el número de elementos en el árbol
  // que se está extrayendo.
}

// Función auxiliar para imprimir el montículo nivel por nivel
void levelByLevel(const std::vector<Node*> &heapArray) {
  for (int i = 0; i < heapArray.size(); i++) {
    std::cout << heapArray[i]->getIp() << "," << heapArray[i]->getData() << "\n";
  }

  // Crear un archivo "atack.txt" y escribir los datos en él
  std::ofstream archivo("attack.csv");

  if (archivo.is_open()) {
    for (int i = 0; i < heapArray.size(); i++) {
      archivo << heapArray[i]->getIp() << "," << heapArray[i]->getData() << "\n";
    }

    archivo.close();
    std::cout << "Datos guardados en attack.csv" << std::endl;
  } else {
    std::cerr << "No se pudo abrir el archivo attack.csv" << std::endl;
  }
}

// Imprimir el montículo nivel por nivel
void Heap::print() {
    Node* aux;
    for (int i = 0;i < this->size();i++) {
        aux = this->getMax();
        aux->print();
        this->deleteMax();
    }
    // Complejidad: O(n), donde "n" es el número de elementos en el montículo.
}
