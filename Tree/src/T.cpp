

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


// void Remove_Node(Tree **T, Tree **Tcopy, Node N)
// {
//     Tree* aux;



// }

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


void Right_DFS(Tree **T, Tree *auxT)
{ 

	if ((*T)->right_branch != NULL){ 
		Right_DFS(&(*T)->right_branch, auxT);
		return;
  }
  	
  auxT->sub_root = (*T)->sub_root;
  auxT = *T; 
  *T = (*T)->left_branch;
  free(auxT);
} 


void Remove_Node(Tree** T, int value)
{
    Tree *auxTree;

    if(empty(T))
    {
        return;
    }
    
    if(value < (*T)->sub_root.key) {Remove_Node(&(*T)->left_branch, value); return;}
    
    if(value > (*T)->sub_root.key) {Remove_Node(&(*T)->right_branch, value); return;}


   
    if((*T)->right_branch == NULL)
    {
        auxTree = *T;
        *T = (*T)->left_branch;
        free(auxTree);
        return;
    }

    if( (*T)->left_branch!=NULL )
    {
        Right_DFS(&(*T)->right_branch, *T);
        return;
    }
    auxTree = *T;
    *T = (*T)->right_branch;
    free(auxTree);

    // Nenhm filho, remove o nó
    // Um filho, remove o nó e liga o seu filho ao seu pai
    // Dois filhos, remove o nó e liga o maior nó à direita do seu filho esquerdo ao seu pai
}

// void BFS(Tree *T)
// {

// }

