#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <vector>


using namespace std;

typedef struct Node Node;
typedef struct AVL AVL;


struct Node
{
    int key;
    int value;
    int height;
};


struct AVL
{
    Node sub_root;
    AVL *left_branch , *right_branch;
    int weight;
};


AVL* Constructor_AVL();

bool empty(AVL** T);

int weightScan(AVL** T);

int maxWeight(int first, int second);

int weightsReazon(AVL **T);

void RRight(AVL **T);

void RLeft(AVL **T);

void RightThenLeft(AVL **T);

void LeftThenRight(AVL **T);

void Insert_Node(AVL **T, Node N);

// void Remove_Node(AVL **T, AVL **f, Node N);

void inOrdem(AVL *T);


void Right_DFS(AVL **T, AVL *auxT);

void Remove_Node(AVL** T, int N);



// void BFS(AVL *T);

#endif