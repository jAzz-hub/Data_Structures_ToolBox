
#include "Node.hpp"
using namespace std;
Node::Node(){
    this->next = NULL;
    this->j = 0;
    this->value = 0;
}

Node::Node(int j, int value){
    this->next = NULL;
    this->j = j;
    this->value = value;
}

