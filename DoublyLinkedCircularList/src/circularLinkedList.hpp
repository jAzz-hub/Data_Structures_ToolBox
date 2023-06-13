#ifndef CIRCULARLINKEDLIST_HPP
#define CIRCULARLINKEDLIST_HPP
#include "Node.hpp"

using namespace std;
class circularLinkedList
{

    public:
        int size;
        Node *PonteiroFrente;
        Node *PonteiroTras;
        

        circularLinkedList();
        circularLinkedList(Node *Ponteiro);
        bool vazia();
        void Insert();
        void ShowList();
        // ~circularLinkedList();
};
#endif