//
// Created by letooov on 5/3/18.
//

#include <iostream>

template<class Type>
struct Node
{
    Node<Type> *Next;
    Node<Type> *Prev;
    Type Data;
public:
    Node(Type _data): Next(NULL), Prev(NULL), Data(_data)
    {}
};

template<class Type>
class List
{
    Node<Type> *Begin;
    Node<Type> *End;
    Node<Type> *Current;
public:
    List(): Begin(NULL), End(NULL), Current(NULL)
    {}
    ~List()
    {
        Node<Type> *iterNode;
        while(Begin)
        {
            iterNode = Begin->Next;
            delete Begin;
            Begin = iterNode;
        }
    }

    int listSize()
    {
        Node<Type> *iterNode = Begin;
        int count = 0;
        while(iterNode)
        {
            ++count;
            iterNode = iterNode->Next;
        }
        return count;
    }

    void insertNode(Type _data, int _position)
    {
        Node<Type> *iterNode = Begin;
        Node<Type> *newNode = new Node<Type>(_data);
        int i = 0;
        if(_position <= listSize() - 1 && _position >= 0)
        {
            while (i != _position) {
                iterNode = iterNode->Next;
                ++i;
            }

            if ((iterNode->Next && iterNode->Prev) || iterNode == End) {
                iterNode->Prev->Next = newNode;
                newNode->Prev = iterNode->Prev;
            } else if (iterNode == Begin) {
                Begin = newNode;
            }
            newNode->Next = iterNode;
            iterNode->Prev = newNode;
        }
    }

    void deleteNode(int _position)
    {
        Node<Type> *iterNode = Begin;
        int i = 0;
        if(_position <= listSize() - 1 && _position >= 0)
        {
            while (i != _position)
            {
                iterNode = iterNode->Next;
                ++i;
            }

            if(iterNode->Next && iterNode->Prev)
            {
                iterNode->Next->Prev = iterNode->Prev;
                iterNode->Prev->Next = iterNode->Next;
            }
            else if(iterNode == Begin)
            {
                Begin = iterNode->Next;
                Begin->Prev = NULL;
            }

            else if (iterNode == End)
            {
                End = iterNode->Prev;
                End->Next = NULL;
            }

            delete iterNode;
        }
    }

    void toNext()
    {
        if(Current && Current->Next)
        {
            Current = Current->Next;
        }
    }

    void toPrev()
    {
        if(Current && Current->Prev)
        {
            Current = Current->Prev;
        }
    }

    void getData()
    {
        if(Current)
        {
            std::cout << Current->Data << std::endl;
        }
    }

    bool initFirstNode(Node<Type> *_firstNode)
    {
        Begin = _firstNode;
        End = _firstNode;
        Current = _firstNode;
    }

    void addToEnd(Type _data)
    {
        Node<Type> *newNode = new Node<Type>(_data);
        if(!Begin && !End)
        {
            initFirstNode(newNode);
        }
        else
        {
            newNode->Prev = End;
            End->Next = newNode;
            End = newNode;
        }
    }

    void addToBegin(Type _data)
    {

        Node<Type> *newNode = new Node<Type>(_data);
        if(!Begin && !End)
        {
            initFirstNode(newNode);
        }
        else
        {
            newNode->Next = Begin;
            Begin->Prev = newNode;
            Begin = newNode;
        }
    }

    void showList()
    {
        Node<Type> *iterNode = Begin;
        while(iterNode)
        {
            std::cout << iterNode->Data << " ";
            iterNode = iterNode->Next;
        }
        std::cout << std::endl;
    }
};
