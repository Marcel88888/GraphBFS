#include <iostream>
#include <fstream>
#include "node.h"
using namespace std;

template <typename T>
void Node<T>::addNeighbour(Node* node) {
    neighbours.push_back(node);
}

template <typename T>
void Node<T>::nwrite() {
    for (int i = 0; i < neighbours.size(); ++i)
        cout << neighbours[i]->number << "  ";
}

template <typename T>
void Node<T>::setNumber(int n) {
    number = n;
}

template <typename T>
void Node<T>::setVariable(T n) {
    variable = n;
}

template <typename T>
void Node<T>::setSon(int a) {
    son = a;
}

template <typename T>
int Node<T>::getNeighboursSize() {
    return neighbours.size();
}

template <typename T>
int Node<T>::getNeighboursNumber(int a) {
    return neighbours[a]->number;
}

template <typename T>
int Node<T>::getVariable() {
    return variable;
}

template <typename T>
int Node<T>::getSon() {
    return son;
}

template <typename T>
Node<T>::Node() {
    son = -1;
}

template <typename T>
Node<T>::~Node() {
    for (int i = 0; i < neighbours.size(); ++i)
        delete neighbours[i];
}

template class Node<int>;