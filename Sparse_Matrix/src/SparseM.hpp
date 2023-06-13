#ifndef SPARSEM_HPP
#define SPARSEM_HPP
#include "Node.hpp"

using namespace std;
class SparseMatrix
{
    public: 
        int NumOfj = 1;
        int NumOfi = 1;
        Node **Lines;


    SparseMatrix();
    SparseMatrix(int NumOfj, int NumOfi);
    bool EmptyLine(int i);
    // InsertElement(i, j, value);
    void ShowElements(int NumOfj, int NumOfi);
    void InsertElements(int value, int iTarget, int jTarget);
    void DeleteLine(int i);
    void DeleteColumn(int j);
    void RemoveElement(int i, int j);
};
#endif

