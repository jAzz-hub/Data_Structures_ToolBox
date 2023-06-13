#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <string>

using namespace std;
class Node
{
    public: 
        int j;
        int value;
        Node *next;

    Node();
    Node(int j, int value);
};
#endif

