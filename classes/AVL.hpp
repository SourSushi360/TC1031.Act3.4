/*  AVL.hpp
    Jean Paul López Pándura

    Última modificación: 03/31/2023
    Un header que declara las funciones y atributos de la clase AVL,
    el cual es un árbol binario autobalanceado conformado de nodos */
#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"
#include <iostream>
/*  Una clase que actúa como un árbol binario autobalanceado,
    Está conformada de Nodos */
class AVL {
    private:
        /*  el nodo raíz */
        Node *root;
        /*  recibe un nodo y regresa su altura */
        int height(Node* node);
        /*  recibe un nodo y regresa su factor de balanceo
            = altura izquierda - altura derecha */
        int balance(Node* node);
        
        /*  rota a la derecha los subnodos de un nodo
            recibe un nodo y regresa el nuevo nodo principal con sus subnodos */
        Node* rotateRight(Node* x);
        /*  rota a la izquierda los subnodos de un nodo
            recibe un nodo y regresa el nuevo nodo principal con sus subnodos*/
        Node* rotateLeft(Node* y);
        /*  recibe un nodo y regresa el subnodo más pequeño a su derecha */
        Node* findMinNode(Node *node);
        /*  función de apoyo para el insert principal, permite ser recursivo */
        Node* insert(Node* node, std::string ip);
    public:
        /*  Constructor default */
        AVL();
        /*  Destructor */
        ~AVL();

        /*  función que recibe un ip y lo inserta en el AVL */
        void insert(std::string ip);
        /*  función que regresa la altura del AVL */
        int height();
        /*  función que imprime en preorder */
        void print();
};
#endif /* AVL_HPP */