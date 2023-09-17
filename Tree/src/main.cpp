
#include "T.hpp"

int main()
{
    
    Tree *T = Constructor_Tree();


    Node n;
    n.key = 5;
    n.value = 22;

    // Node k;
    // k.key = 3;
    // k.value = 11;

    Node v;
    v.key = 7;
    v.value = 33;

    // Node a;
    // a.key = 2;
    // a.value = 33;


    // Node b;
    // b.key = 4;
    // b.value = 33;


    // Node e;
    // e.key = 6;
    // e.value = 33;

    Node d;
    d.key = 8;
    d.value = 33;

    Insert_Node(&T, n);
    // Insert_Node(&T, k);
    Insert_Node(&T, v);
    // Insert_Node(&T, a);
    // Insert_Node(&T, b);
    // Insert_Node(&T, e);
    Insert_Node(&T, d);

    inOrdem(T);
    printf("\n");
    Remove_Node(&T, 8);
    inOrdem(T);

    // BFS(T);
}