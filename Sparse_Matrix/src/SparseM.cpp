
#include "SparseM.hpp"

using namespace std;

SparseMatrix::SparseMatrix()
{
    this->NumOfj = 0;
    this->NumOfi = 0;
    this->Lines = NULL;
}

SparseMatrix::SparseMatrix(int j, int i)
{
    this->NumOfj = j;
    this->NumOfi = i;

    this->Lines = (Node**)malloc( sizeof(Node*) * i );
    for(int k = 0; k<i; k++)
    {
        this->Lines[k] = (Node*)malloc( sizeof(Node) * j );
    }
}

bool SparseMatrix::EmptyLine(int i)
{
    if(this->Lines[i] == NULL) return true;

    else return false;
}

void SparseMatrix::ShowElements(int NumOfj, int NumOfi)
{
    if(NumOfi>this->NumOfi || NumOfj>this->NumOfj)
    {
        cout<<"O range que deseja ser visualizado está além dos valores alocados na esturtura de dados";
        return;
    }

    else
    {
        cout<<endl<<endl;
        cout<<"Matriz Esparsa:"<<endl;

        for(int i = 0; i<NumOfi; i++)
        {   
            cout<<endl;
            for(int ji = 0; ji<NumOfj; ji++)
            {
                cout<<Lines[i][ji].value<<" ";
            }
        }
    }

}

void SparseMatrix::InsertElements(int value, int iTarget, int jTarget)
{
    bool hA = iTarget<this->NumOfi && jTarget<this->NumOfj;
    bool hB = iTarget>=0 && jTarget>=0;

    if(hA && hB)    this->Lines[iTarget][jTarget].value = value;
    
    else    cout<<"Valores de inserção de i e j são muito grandes!!"<<endl;
}

void SparseMatrix::RemoveElement(int i, int j)
{
    bool hA = i<this->NumOfi && j<this->NumOfj;
    bool hB = i>=0 && j>=0;

    if(hA && hB)    this->Lines[i][j].value = 0;
    
    else    cout<<"Valores de inserção de i e j são muito grandes!!"<<endl;

}

void SparseMatrix::DeleteLine(int i)
{

    bool hA = i>this->NumOfi || i<0;

    if(!hA)
    {
        free(this->Lines[i]);

        for(int index = 0; index<this->NumOfj; index++) this->Lines[i-1] = Lines[i];

        this->NumOfi = this->NumOfi-1;

        this->Lines = (Node**)realloc(Lines, sizeof(Node)*this->NumOfi);
    }

    else
    {
        cout<<"A remoção da linha não pode ser realizada, escolha um valor de linha menor ou de maior que -1"<<endl;
    }
}

void SparseMatrix::DeleteColumn(int j)
{

    bool hA = j>this->NumOfj || j<0;

    if(hA)
    {
        for(int i ; i<this->NumOfi; i++)
        {
            delete (&this->Lines[i][j]);
            
            for(int index = 0; index<this->NumOfj; index++) this->Lines[index][j] = Lines[index][j-1];
        }

        this->NumOfj = this->NumOfj-1;

        this->Lines = (Node**)realloc(Lines, sizeof(Node)*this->NumOfj);
    }


    else
    {
        cout<<"A remoção da coluna não pode ser realizada, escolha um valor de coluna menor  ou de maior que -1 ou de maior que -1";
    }
}

