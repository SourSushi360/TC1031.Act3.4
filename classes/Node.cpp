/*  Node.cpp
    Jean Paul López Pándura
    
    Última modificación: 02/11/2023
    Desarrolla las funciones declaradas en el header Node.hpp */
#include "Node.hpp"

// Constructors & destructors
Node::Node(int data,std::string ip) {
    this->ip = new std::string(ip);
    this->data = new int(data);
    this->height = new int(0);
    this->left = nullptr;
    this->right = nullptr;
}
Node::Node() {
    this->ip = new std::string;
    this->data = new int;
    this->height = new int(0);
    this->left = nullptr;
    this->right = nullptr;
}
Node::~Node() {
    delete this->ip;
    delete this->data;
    delete this->height;
    delete this->left;
    delete this->right;
}

// getters
int Node::getData() {
    return *this->data;
}
int Node::getHeight() {
    return *this->height;
}
Node* Node::getLeft() {
    return this->left;
}
Node* Node::getRight() {
    return this->right;
}

// setters
void Node::setData(int data,std::string ip) {
    *this->data = data;
}
void Node::setHeight(int height) {
    *this->height = height;
}
void Node::setLeft(Node *left) {
    this->left = left;
}
void Node::setRight(Node *right) {
    this->right = right;
}

// operations
bool Node::compareIp(Node* ptr) {
    std::stringstream streamA(*ptr->ip), streamB(*this->ip);
    std::string ipA, ipB, auxA, auxB;
    int ipa, ipb;
    for (int i=0;i <= 3;i++){
        std::getline(streamA,ipA,' ');
    }
    for (int i=0;i <= 3;i++){
        std::getline(streamB,ipB,' ');
    }
    std::stringstream IPa(ipA),IPb(ipB);
    for (int i = 0;i < 3;i++){
        std::getline(IPa,auxA,'.');
        std::getline(IPb,auxB,'.');
        ipa = stoi(auxA);
        ipb = stoi(auxB);
        if (ipa < ipb){
            return true;
        } else if (ipa > ipb){
            return false;
        }
    }

    std::getline(IPa,auxA,':');
    std::getline(IPb,auxB,':');
    if (ipa < ipb){
            return true;
    } else {
        return false;
    }
}
