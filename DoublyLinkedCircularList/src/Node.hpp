#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>

using namespace std;
class Node
{
    public: 
        Node *next;
        Node *previous;
        string cor;

    Node();
    Node(string cor);
};
#endif