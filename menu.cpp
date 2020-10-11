#include <iostream>
#include "menu.h"
using namespace std;

void Menu::menuOperation() {
    int c;
    Graph <int> gr;
    cout << "---------------------MENU---------------------";
    cout << endl << "Options: " << endl;
    cout << " 1- to make a graph from a file." << endl;
    cout << " 2- to write out the adjacency arrays." << endl;
    cout << " 3- to write out the nodes' variables." << endl;
    cout << " 4- to do BFS for the graph." << endl;
    cout << " 5- to exit." << endl;
    do {
        cout << endl << "Your choice: ";
        cin >> c;
        switch (c) {
            case 1: {
                string file;
                cout << "Type the name of the file containing the graph's data: ";
                cin >> file;
                gr.makeGraph(file);
                break;
            }
            case 2: {
                gr.write();
                break;
            }
            case 3: {
                gr.writeVars();
                break;
            }
            case 4: {
                cout << "Visited in order:" << endl;
                gr.bfs(0);
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                cout << "There is no such a choice. ";
                break;
            }
        }
    }
    while(c != 5);
}