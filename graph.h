#ifndef PROJECT2_GRAPH_H
#define PROJECT2_GRAPH_H
#include <iostream>
#include "node.h"
using namespace std;

template <typename T>
class Graph {

private:
    int nod; // number of nodes
    Node<T> *nodes; // C++ daje dużo możliowości wskaźnikom, więc mogłem zrobić na wskaźnikach, bo są
                    // wydajniesze, ale to też jest dobrze.

public:
    void write(); // writes out the adjacency arrays
    void writeVars(); // writes out the nodes' variables
    void makeGraph(string); // reads from file and makes a graph
    int getNodes(); // returns a number of nodes
    Node<T>* getOneNode(int); // returns the element of array "nodes"
    void bfs(int);  // does BFS algorithm   BFS może kończyć program ze względu na niespełnienie zasady 3, ale za to nawet nie odejmował punktów
    void testingArguments(); // sets arguments for tests;
    Graph(); // constructor
    ~Graph(); // destructor
};

#endif //PROJECT2_GRAPH_H
