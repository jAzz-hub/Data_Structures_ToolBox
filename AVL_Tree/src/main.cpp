
#include "AVL.hpp"

int main()
{

    AVL *T = Constructor_AVL();


    Node n;
    n.key = 1;
    n.value = 22;

    Node k;
    k.key = 3;
    k.value = 11;

    Node v;
    v.key = 5;
    v.value = 33;

    Node a;
    a.key = 7;
    a.value = 33;


    Node b;
    b.key = 11;
    b.value = 33;


    Node e;
    e.key = 13;
    e.value = 33;

    Node d;
    d.key = 0;
    d.value = 33;

    Insert_Node(&T, n);
    Insert_Node(&T, k);
    Insert_Node(&T, v);
    Insert_Node(&T, a);
    Insert_Node(&T, b);
    Insert_Node(&T, e);
    Insert_Node(&T, d);

    inOrdem(T);
    Remove_Node(&T, &T, k);
    cout<<endl;
    cout<<T->sub_root.key<<endl;
    cout<<T->left_branch->right_branch->sub_root.key<<endl;
    cout<<T->right_branch->sub_root.key<<endl;
    cout<<T->left_branch->left_branch->sub_root.key<<endl;
    cout<<T->right_branch->right_branch->sub_root.key<<endl;



    cout<<endl;
}