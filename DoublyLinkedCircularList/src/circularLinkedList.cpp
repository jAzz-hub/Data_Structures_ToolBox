
#include "circularLinkedList.hpp"
#include "Node.hpp"

using namespace std;
circularLinkedList::circularLinkedList()
{
    this->size = 0;
    this->PonteiroFrente = NULL;
    this->PonteiroTras = NULL;
}

circularLinkedList::circularLinkedList(Node *nozinho)
{
    this->size = 1;
    this->PonteiroFrente = nozinho;
    this->PonteiroTras = PonteiroFrente;
}

bool circularLinkedList::vazia()
{
    
    if(this->PonteiroFrente==NULL && PonteiroTras==NULL)
        return true;
    
    else 
        return false;

}

void circularLinkedList::Insert()
{
    string choice;
    cout<<"Escolha a cor à ser inserida:";
    cin>>choice;

    Node *nozinho = new Node(choice);

    if(this->vazia())
    {
        nozinho->next=nozinho;
        nozinho->previous=nozinho;
        this->PonteiroFrente = nozinho;
        this->PonteiroTras = nozinho;
    }
    else
    {
        this->PonteiroFrente->next = nozinho;

        nozinho->next = this->PonteiroTras;
        nozinho->previous = this->PonteiroFrente;
        this->PonteiroTras->previous = nozinho;
        this->PonteiroFrente->next = nozinho;
        this->PonteiroFrente = nozinho;
    }
    this->size++;
}

void circularLinkedList::ShowList()
{
    int ref = this->size;

    Node* aux = this->PonteiroTras;

    cout<<"A lista circular está disposta da seguinte forma:"<<endl;

    do 
    {
        cout<<aux->cor<<endl;
        aux = aux->next;
        ref--;
    }while(ref>0);
    
}

