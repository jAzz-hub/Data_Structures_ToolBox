

#include "T.hpp"


Tree* Constructor_Tree(){
	return NULL;
}

bool empty(Tree** T)
{
    return *T == NULL;

}

void Insert_Node(Tree** T, Node N)
{
    
    if (empty(T)) 
    {
        *T = (Tree*)malloc(sizeof(Tree));
        (*T)->left_branch = NULL;
        (*T)->right_branch = NULL;
        (*T)->sub_root = N;

    } 
    else 
    {
        if(N.key < (*T)->sub_root.key)
        {
            Insert_Node( &(*T)->left_branch, N);
        }
        if(N.key > (*T)->sub_root.key)
        {

            Insert_Node( &(*T)->right_branch, N);
        }
    }
}

/// @brief Função que mostra elementos de uma árvore de forma ordenada devido ao desempilhamento ao fim de uma recursividade
/// @param T Ponteiro para a árvore
void inOrdem(Tree *T)
{
    if(!(T==NULL))
    {
        inOrdem(T->left_branch);
        printf("%d\t", T->sub_root.key);
        inOrdem(T->right_branch);
    }
}
