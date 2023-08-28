
#include "T.hpp"

int main()
{
    
    Tree *T = Constructor_Tree();


    Node n;
    n.key = 3;
    n.value = 22;

    Node k;
    k.key = 2;
    k.value = 11;

    Node v;
    v.key = 40;
    v.value = 33;

    Node a;
    a.key = 13;
    a.value = 33;


    Node b;
    b.key = 7;
    b.value = 33;


    Node e;
    e.key = 1;
    e.value = 33;

    Node d;
    d.key = 33;
    d.value = 33;

    Insert_Node(&T, n);
    Insert_Node(&T, k);
    Insert_Node(&T, d);
    Insert_Node(&T, e);
    Insert_Node(&T, b);
    Insert_Node(&T, a);
    Insert_Node(&T, v);

    inOrdem(T);
}