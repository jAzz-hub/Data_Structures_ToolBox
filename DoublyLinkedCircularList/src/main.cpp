
#include "circularLinkedList.hpp"

 int main()
 {
    Node *bola_1 = new Node("Amarela");

    Node *bola_x = new Node();

    circularLinkedList lista_1 = circularLinkedList(bola_1);
    circularLinkedList lista_2 = circularLinkedList();


    cout<<bola_1->cor;
    lista_1.Insert();
    lista_1.Insert();
    lista_1.Insert();

    lista_1.ShowList();
    return 0;
}