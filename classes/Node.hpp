/*  Node.hpp
    Jean Paul López Pándura
    
    Última modificación: 03/11/2023
    Este header declara las funciones y atributos de Node */
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <sstream>
/*  una clase que guarda un string con el valor de una IP, y un dato que
    representa la cantidad de veces que apareció en la bitácora */
class Node {
  private:
    /*  representa el valor de la ip
        es el key value */
    int *ip;
    /*  representa cuantas veces ha aparecido el valor
        es el número de accesos*/
    int *data;

    int *height;
    Node *right;
    Node *left;

  public:
    /*  Constructuor sin parámetros
        crea un nodo vacío */
    Node(); 

    /*  Constructor con parámetros
        - recibe un int que representa las veces que se repite la IP
        - recibe un string con la IP */
    Node(int data,int ip);

    /*  Destructor */
    ~Node();

    /*  compara el valor de su IP con la del nodo recibido
        regresa true si es mayor, false si es menor */
    bool isBigger(int ip);
    /*  compara el valor de su IP con la del nodo recibido
        regresa true si es igual, false si es diferente */
    bool isEqual(int ip);
    /*  le suma uno a la cantidad de veces que ha aparecido la IP */
    void updateData();

    /*  cambia los valores del nodo
        - recibe un int que representa las veces que se repite la IP
        - recibe un string con la IP */
    void setData(int data,int ip);
    /*  regresa el número de veces que aparece la ip en bitácora */
    int  getData();
    /*  regresa el número del puerto */
    int getPort();
    /*  cambia el nodo a la derecha, o 'mayor' */
    void setRight(Node* node);
    /*  regresa un puntero al nodo de la derecha */
    Node* getRight();
    /*  cambia el nodo a la izquierda o 'menor' */
    void setLeft(Node* node);
    /*  regresa el puntero al nodo de la izquierda */
    Node* getLeft();
    /*  cambia la altura del nodo en el BST */
    void setHeight(int height);
    /*  regresa la altura del nodo */
    int getHeight();
    /*  imprime en formato al nodo */
    void print();
};
#endif /* NODE_HPP */