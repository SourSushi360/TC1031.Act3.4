/*  AVL.cpp
    Jean Paul López Pándura
    
    Última modificación: 02/11/2023
    Desarrolla las funciones declaradas en AVL.hpp */
#include "AVL.hpp"

// Constructors & destructors
AVL::AVL() {
    this->root = nullptr;
}
AVL::~AVL() {
    delete this->root;
}

// getters
int AVL::height(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->getHeight();
}
int AVL::balance(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->getLeft()) - height(node->getRight());
}
Node* AVL::findMinNode(Node *node) {
    Node* aux = node->getRight();
    while (aux->getLeft() != nullptr) {
        aux = aux->getLeft();
    }
    
    return aux;
}
Node* AVL::getRoot() {
    return this->root;
}

// procesos de ordenamiento
Node* AVL::rotateRight(Node* y) {
    Node* x = y->getLeft();
    Node* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);
    y->setHeight(1 + (x->getLeft() != nullptr ? x->getLeft()->getHeight() : 0));
    x->setHeight(1 + (y->getRight() != nullptr ? y->getRight()->getHeight() : 0));

    return x;
}
Node* AVL::rotateLeft(Node* x) {
    Node* y = x->getRight();
    Node* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);
    x->setHeight(1 + (x->getLeft() != nullptr ? x->getLeft()->getHeight() : 0));
    y->setHeight(1 + (y->getRight() != nullptr ? y->getRight()->getHeight() : 0));

    return y;
}

// insert node from AVL
Node* AVL::insert(Node *node,std::string ip) {
    // busca el lugar vacío para el nodo
    if (node == nullptr) {
        Node *newNode = new Node(1,ip);
        return newNode;
    } if (node->isEqual(ip)) {
        node->updateData();
        return node;
    } else if (node->isBigger(ip)) {
        node->setLeft(insert(node->getLeft(),ip));
    } else if (!node->isBigger(ip)) {
        node->setRight(insert(node->getRight(),ip));
    }

    // actualiza la altura
    int leftH = height(node->getLeft()), rightH = height(node->getRight());
    int height_ = leftH > rightH ? (1 + leftH) : (1 + rightH);
    node->setHeight(height_);

    // encuentra su balance y hace rotaciones al respecto
    int balance_ = balance(node);
    if (balance_ > 1 && node->getLeft()->isBigger(ip)) {
        return rotateRight(node);
    }
    if (balance_ < -1 && node->getRight()->isBigger(ip)) {
        return rotateLeft(node);
    }
    if (balance_ > 1 && node->getLeft()->isBigger(ip)) {
        node->setLeft(rotateLeft(node->getLeft()));
        return rotateRight(node);
    }
    if (balance_ < -1 && node->getRight()->isBigger(ip)) {
        node->setRight(rotateRight(node->getRight()));
        return rotateLeft(node);
    }

    return node;
}

// public methods
void AVL::insert(std::string ip) {
    this->root = insert(this->root,ip);
}
int AVL::height() {
    return this->root->getHeight();
}
    // print helper
void preorder(Node *node) {
    if (node != nullptr) {
        node->print();
        preorder(node->getLeft());
        preorder(node->getRight());
    }
}
void AVL::print() {
    preorder(this->root);
}
