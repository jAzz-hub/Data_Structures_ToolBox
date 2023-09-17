#ifndef T_H
#define T_H

#include <iostream>
#include <vector>


using namespace std;

typedef struct Node Node;
typedef struct Tree Tree;


struct Node
{
    int key;
    int value;
};


struct Tree
{
    Node sub_root;
    Tree *left_branch , *right_branch;
};


Tree* Constructor_Tree();

bool empty(Tree** T);

void Insert_Node(Tree **T, Node N);

// void Remove_Node(Tree **T, Tree **f, Node N);

void inOrdem(Tree *T);


void Right_DFS(Tree **T, Tree *auxT);

void Remove_Node(Tree** T, int N);



// void BFS(Tree *T);

#endif