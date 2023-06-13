
 #include "Node.hpp"

using namespace std;
Node::Node()
{
    this->next = nullptr;
    this->previous = nullptr;
    this->cor="colorido de mais";
}

Node::Node(string cor)
{
    this->next = nullptr;
    this->previous = nullptr;
    this->cor = cor;
}

