#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {

private:
    int number;
    T variable;
    int son;
    vector <Node<T>*> neighbours;

    // C++ rule of three
public:
    void addNeighbour(Node<T>*); // adds the element to the "neighbours" vector
    void nwrite(); // writes out numbers of the elements of "neighbours" vector
    void setNumber(int); // sets the number
    void setVariable(T); // sets the variable
    void setSon(int); // sets the son
    int getNeighboursSize(); // returns the size of "neighbours" vector
    int getNeighboursNumber(int); // returns the number of chosen "neighbours" element
    int getVariable(); // returns the variable
    int getSon(); // returns the son
    Node(); // constructor
    ~Node(); // destructor
};
#endif //PROJECT2_NODE_H
