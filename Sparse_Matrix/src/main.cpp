
#include "SparseM.hpp"

int main()
{
    int a = 0;

    SparseMatrix M = SparseMatrix(5,5);

    //Consertar função de Inserção em Matriz esparsa;

    M.ShowElements(2,2);
    M.ShowElements(5,5);
    M.InsertElements(1,3,1);
    cout<<endl;
    cout<<endl;
    M.InsertElements(0, 0, 1);
    M.InsertElements(4, 1, 0);
    M.InsertElements(7, 2, 0);
    M.InsertElements(1, 0, 0);
    M.InsertElements(1, 1, 2);
    M.InsertElements(8, 2, 0);
    M.InsertElements(2, 0, 0);
    M.InsertElements(9, 1, 0);
    M.InsertElements(2, 2, 3);
    M.DeleteColumn(2);
    M.ShowElements(4,5);
    M.DeleteLine(2);
    cout<<endl;
    M.ShowElements(4,4);
    M.InsertElements(2, 0, 0);

    return 0;
}