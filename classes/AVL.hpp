/*  AVL.hpp
    Jean Paul López Pándura

    Última modificación: 02/31/2023
    Un header que declara las funciones y atributos de la clase AVL,
    el cual es un árbol binario autobalanceado */
#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"
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
        Node* insert(Node* node, int val);
        /*  función de apoyo para el remove principal, permite ser recursivo */
        Node* remove(Node* node, int val);
    public:
        /*  Constructor default */
        AVL();
        /*  Destructor */
        ~AVL();

        /*  función que recibe un ip y lo inserta en el AVL */
        void insert(std::string ip);
        /*  función que regresa la altura del AVL */
        int height();
};
#endif /* AVL_HPP */