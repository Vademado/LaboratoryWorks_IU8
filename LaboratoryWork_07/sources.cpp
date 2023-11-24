#include "sources.h"

void AddBegin(MyList& list, Node* p)
{
    if (list.pFirst == nullptr)
        list.pEnd = list.pFirst->pNext = list.pEnd->pPrev = p;
    else
    {
        p->pNext = list.pFirst;
        p->pPrev = list.pEnd;
    }
    list.pFirst = list.pFirst->pPrev = list.pEnd->pNext = p;
}

void AddEnd(MyList& list, Node* p)
{
    if (list.pEnd == nullptr)
        list.pFirst = list.pFirst->pNext = list.pEnd->pPrev = p;
    else
    {
        p->pPrev = list.pEnd;
        p->pNext = list.pFirst;
    }
    list.pFirst->pPrev = list.pEnd = list.pEnd->pNext = p;
}

void RemoveNode(MyList& list, Node* p)
{
    if (list.pFirst == nullptr)
    {
        std::cerr << "ERROR: List is empty" << std::endl;
        // return; !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else if (p->pNext == p)
    {
        list.pEnd = list.pFirst = nullptr;
    }
    else
    {
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
    }
    delete p;
}

Node* extractFront(MyList& list)
{
    if (list.pFirst == nullptr)
        return nullptr;
    Node* p = list.pFirst;
    list.pFirst = list.pFirst->pNext;
    if (p == list.pFirst)
        list.pFirst = list.pEnd = nullptr;
    else
    {
        list.pFirst->pPrev = list.pEnd;
        list.pEnd->pNext = list.pFirst;
    }
    return p;
}

Node* extractBack(MyList& list)
{
    if (list.pEnd == nullptr)
        return nullptr;
    Node* p = list.pEnd;
    list.pEnd = list.pEnd->pPrev;
    if (p == list.pEnd)
        list.pFirst = list.pEnd = nullptr;
    else
    {
        list.pFirst->pPrev = list.pEnd;
        list.pEnd->pNext = list.pFirst;
    }
    return p;
}

void print(MyList& list)
{
}