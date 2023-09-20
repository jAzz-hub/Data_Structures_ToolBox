

#include "AVL.hpp"

AVL* Constructor_AVL(){
	return NULL;
}

bool empty(AVL** T)
{
    return *T == NULL;
}

int weightScan(AVL **T)
{
    if(*T == NULL)
        return -1;

    else
        return (*T)->weight;
}

int maxWeight(int first, int second)
{
    if (first>second) 
        return first;
    else 
        return second;
}

int weightsReazon(AVL **T)
{
    return weightScan(&(*T)->right_branch) - weightScan(&(*T)->left_branch);
}

void RRight(AVL **T)
{
    AVL *auxT;
    
    auxT = (*T)->left_branch; 
    (*T)->left_branch = auxT->right_branch;
    auxT->right_branch = (*T);

    (*T)->weight = maxWeight(weightScan(&(*T)->left_branch),weightScan(&(*T)->right_branch)) + 1;
    auxT->weight = maxWeight(weightScan(&auxT->left_branch), (*T)->weight) + 1;

   (*T) = auxT;
}

void RLeft(AVL **T)
{
    AVL *auxT;
    
    auxT = (*T)->right_branch; 
    (*T)->right_branch = auxT->left_branch;
    auxT->left_branch = (*T);

    (*T)->weight = maxWeight(weightScan(&(*T)->left_branch),weightScan(&(*T)->right_branch)) + 1;
    auxT->weight = maxWeight(weightScan(&auxT->left_branch), (*T)->weight ) + 1;

    (*T) = auxT;
}

void RightThenLeft(AVL **T)
{
    RLeft(&(*T)->left_branch);
    RRight(T);
}

void LeftThenRight(AVL **T)
{
    RRight(&(*T)->right_branch);
    RLeft(T);
}


void Insert_Node(AVL** T, Node N)
{

    

    if (empty(T)) 
    {
        *T = (AVL*)malloc(sizeof(AVL));
    
        (*T)->left_branch = NULL;
        (*T)->right_branch = NULL;
    
        (*T)->weight = 0;
        (*T)->sub_root = N;

    }
    else 
    {

        if(N.key < (*T)->sub_root.key)
        {
            Insert_Node( &(*T)->left_branch, N);
            if(weightScan(&(*T)->left_branch) - weightScan(&(*T)->right_branch)==2)
            {
                N.key < (*T)->left_branch->sub_root.key ? RRight(T) : RightThenLeft(T); 
            }
        }

        if(N.key > (*T)->sub_root.key)
        {
            Insert_Node( &(*T)->right_branch, N);
            if(weightScan(&(*T)->right_branch) - weightScan(&(*T)->left_branch)==2)
            {
                N.key > (*T)->right_branch->sub_root.key ? RLeft(T) : LeftThenRight(T);
            }
        }
        
    }

    (*T)->weight = maxWeight( weightScan(&(*T)->left_branch), weightScan(&(*T)->right_branch))  + 1;
}

/// @brief Função que mostra elementos de uma árvore de forma ordenada devido ao desempilhamento ao fim de uma recursividade
/// @param T Ponteiro para a árvore
void inOrdem(AVL *T)
{
    if(!(T==NULL))
    {
        inOrdem(T->left_branch);
        printf("%d\t", T->sub_root.key);
        inOrdem(T->right_branch);
    }
}


void Right_DFS(AVL **T,AVL*auxT)
{ 

	if ((*T)->right_branch != NULL)
    { 
		Right_DFS(&(*T)->right_branch, auxT);
		return;    
    }
  	
    auxT->sub_root = (*T)->sub_root;
    auxT = *T; 
    *T = (*T)->left_branch;
    free(auxT);


} 


void rebalanceTree(AVL** T)
{
    int Assimetry;
    int AssimetryLeft = (*T)->left_branch ? weightScan( &(*T)->left_branch->left_branch ) - weightScan( &(*T)->left_branch->right_branch ) : 0;
    int AssimetryRight = (*T)->right_branch ? weightScan( &(*T)->right_branch->left_branch ) - weightScan( &(*T)->right_branch->right_branch ) : 0;    

    Assimetry = weightScan(&(*T)->left_branch) - weightScan(&(*T)->right_branch);

    //Sub raízes esquerda e direita com assimetria de 2:
        
        // Assimetria esquerda >=0:
        if(Assimetry == 2 && (AssimetryLeft) >= 0)
            RRight(T);
        
        // Assimetria esquerda menor que 0:
        if(Assimetry == 2 && (AssimetryLeft) < 0)
            RightThenLeft(T);
    
    //Sub raízes esquerda e direita com assimetria de -2:
        // Assimetria direita maior que 0:
        if( Assimetry == -2 && AssimetryRight >= 0)
            LeftThenRight(T);
        
        //// Assimetria direita menor que 0:
        if( Assimetry == -2 && AssimetryRight < 0)
            RLeft(T);
}

void Remove_Node(AVL** T, AVL** TCopy, Node N)
{
   AVL*auxTree;

    if(empty(T))
    {
        return;
    }
    
    if(N.key < (*T)->sub_root.key) {Remove_Node(&(*T)->left_branch, T, N); return;}
    
    if(N.key > (*T)->sub_root.key) {Remove_Node(&(*T)->right_branch, T, N); return;}
   
    if((*T)->right_branch == NULL)
    {
        auxTree = *T;
        *T = (*T)->left_branch;
        free(auxTree);

        rebalanceTree(TCopy);

        return;
    }

    if( (*T)->left_branch!=NULL )
    {

        Right_DFS(&(*T)->right_branch, *T);

        rebalanceTree(TCopy);
        rebalanceTree(T);
        return;
    }
    auxTree = *T;
    *T = (*T)->right_branch;
    free(auxTree);


    rebalanceTree(TCopy);
    rebalanceTree(T);
    // Nenhm filho, remove o nó
    // Um filho, remove o nó e liga o seu filho ao seu pai
    // Dois filhos, remove o nó e liga o maior nó à direita do seu filho esquerdo ao seu pai
}

