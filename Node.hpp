/*  Node.hpp
    Jean Paul López Pándura
    
    Última modificación: 02/11/2023
    Este header declara las funciones y atributos de Node */
#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <sstream>
/*  una clase que guarda un string con el valor de una IP, y un dato que
    representa la cantidad de veces que apareció en la bitácora */
class Node {
  private:
    std::string *ip;
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
    Node(int data,std::string ip);

    /*  Destructor */
    ~Node();

    /*  cambia los valores del nodo
        - recibe un int que representa las veces que se repite la IP
        - recibe un string con la IP */
    void setData(int data,std::string ip);
    /*  regresa el número de veces que aparece la ip en bitácora */
    int  getData();
    /*  compara el valor de una IP con la del nodo */
    bool compareIp(Node* node);

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
};
#endif /* NODE_HPP */