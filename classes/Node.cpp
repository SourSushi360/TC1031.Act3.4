/*  Node.cpp
    Jean Paul López Pándura
    
    Última modificación: 03/11/2023
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
std::string Node::getIp() {
    return *this->ip;
}

// setters
void Node::setData(int data,std::string ip) {
    *this->data = data;
    *this->ip = ip;
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
bool Node::isBigger(std::string ip) {
    std::string auxA, auxB;
    int ipa, ipb;
    std::stringstream IPa(ip),IPb(*this->ip);
    for (int i = 0;i < 3;i++){
        std::getline(IPa,auxA,'.');
        std::getline(IPb,auxB,'.');
        ipa = stoi(auxA);
        ipb = stoi(auxB);
        if (ipa != ipb) {
            return ipa < ipb;
        }
    }
    return ipa < ipb;
}
bool Node::isEqual(std::string ip) {
    return *this->ip == ip;
}
void Node::updateData() {
    *this->data = this->getData() + 1;
}

// print
void Node::print() {
    std::cout << *this->ip << "," << this->getData() << "\n";
}
