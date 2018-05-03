#include <iostream>
#include "List.cpp"

int main()
{
    List<int> A;
    for(int i = 0; i < 100; i+=10)
    {
        A.addToEnd(i);
    }
    A.showList();
    A.addToBegin(-10);
    A.showList();
    A.addToEnd(100);
    A.showList();
    A.deleteNode(1);
    A.showList();
    A.insertNode(85,8);
    A.showList();
    return 0;
}