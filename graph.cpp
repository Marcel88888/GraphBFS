#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "graph.h"
using namespace std;

template <typename T>
void Graph<T>::makeGraph(string name) {
    ifstream file;
    file.open(name.c_str());
    if(file.good()) {
        int n; // quantity of nodes
        int nr1, nr2; // numbers of nodes
        T var;
        file >> n;
        if (n <= 0){
            cout<<"Incorrect data"<<endl;
            return;
        }
        nod = n;
        nodes = new Node<T>[n];
        for (int i = 0; i < nod; ++i) {
            file >> var;
            nodes[i].setVariable(var);
        }
        for (int i = 0; i < nod; ++i) {
            nodes[i].setNumber(i);
        }
        while (file >> nr1 >> nr2){
            if (nr1 < 0 || nr2 < 0) {
                cout<<"Incorrect data"<<endl;
                return;
            }
            Node<T>* ptr;
            ptr = &nodes[nr2];
            nodes[nr1].addNeighbour(ptr);
        }
        file.close();
    }
    else {
        cout << "Program failed to open the file" << endl;
        return;
    }
}

template <typename T>
void Graph<T>::write(){
    for (int i = 0; i < getNodes(); ++i) {
        cout << i << "|  ";
        nodes[i].nwrite();
        cout << endl;
    }
}

template <typename T>
void Graph<T>::writeVars() {
    for (int i = 0; i < getNodes(); ++i)
        cout << i << " variable: " << nodes[i].getVariable() << endl;
}

template <typename T>
void Graph<T>::bfs(int s) {
    int i;
    int a;
    bool *visited = new bool[nod];
    for (i = 0; i < nod; ++i)
        visited[i] = false;
    queue<int> que;
    vector<int> sons;
    visited[s] = true;
    que.push(s);
    while (!que.empty()) {
        a = que.front();
        sons.push_back(a);
        cout << a << "  ";
        que.pop();
        for (i = 0; i < nodes[a].getNeighboursSize(); ++i) {
            if (!visited[nodes[a].getNeighboursNumber(i)]) {
                visited[nodes[a].getNeighboursNumber(i)] = true;
                que.push(nodes[a].getNeighboursNumber(i));
            }
        }
    }
    for (i = 0; i < sons.size()-1; ++i)
        nodes[sons[i]].setSon(sons[i+1]);
}

template <typename T>
void Graph<T>::testingArguments() {
    nod = 6;
    nodes = new Node<T>[nod];
    for (int i = 0; i < nod; ++i) {
        nodes[i].setVariable(0);
    }
    for (int i = 0; i < nod; ++i) {
        nodes[i].setNumber(i);
    }
    Node<T>* ptr1;
    ptr1 = &nodes[2];
    nodes[0].addNeighbour(ptr1);

    Node<T>* ptr2;
    ptr2 = &nodes[5];
    nodes[0].addNeighbour(ptr2);

    Node<T>* ptr3;
    ptr3 = &nodes[2];
    nodes[1].addNeighbour(ptr3);

    Node<T>* ptr4;
    ptr4 = &nodes[3];
    nodes[1].addNeighbour(ptr4);

    Node<T>* ptr5;
    ptr5 = &nodes[2];
    nodes[2].addNeighbour(ptr5);

    Node<T>* ptr6;
    ptr6 = &nodes[4];
    nodes[2].addNeighbour(ptr6);

    Node<T>* ptr7;
    ptr7 = &nodes[1];
    nodes[3].addNeighbour(ptr7);

    Node<T>* ptr8;
    ptr8 = &nodes[0];
    nodes[4].addNeighbour(ptr8);

    Node<T>* ptr9;
    ptr9 = &nodes[3];
    nodes[4].addNeighbour(ptr9);

    Node<T>* ptr10;
    ptr10 = &nodes[1];
    nodes[5].addNeighbour(ptr10);
}


template <typename T>
int Graph<T>::getNodes() {
    return nod;
}

template <typename T>
Node<T>* Graph<T>::getOneNode(int a) {
    return &nodes[a];
}

template <typename T>
Graph<T>::Graph() {
    nod = 0;
    nodes = nullptr;
}

template <typename T>
Graph<T>::~Graph() {
    delete []nodes;
}

template class Graph<int>;