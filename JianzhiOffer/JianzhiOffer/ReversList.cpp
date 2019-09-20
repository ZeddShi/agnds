//
//  ReversList.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/27.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "ReversList.hpp"
#include "NewList.hpp"


List_Node* reverseList(List_Node *pHead)
{
    if (pHead == nullptr || pHead->pNext == nullptr)
        return pHead;
    List_Node *pNode = pHead->pNext;
    List_Node *pNewHead = reverseList(pNode);
    pNode->pNext = pHead;
    pHead->pNext = nullptr;
    
    return pNewHead;
}

List_Node* iteratorReverseList(List_Node *pHead)
{
    List_Node *pNewHead = nullptr;
    List_Node *pNode = pHead;
    List_Node *pPre = nullptr;
    while (pNode != nullptr) {
        List_Node *next = pNode->pNext;
        if (next == nullptr)
            pNewHead = pNode;
        pNode->pNext = pPre;
        pPre = pNode;
        pNode = next;
    }
    return pNewHead;
}


void reverseListTest()
{
    List_Node *pHead = CreatList(10);
    PrintList(pHead);
    List_Node *listReversed = reverseList(pHead);
    PrintList(listReversed);
}

void iteratorReverseTest()
{
    List_Node *pHead = CreatList(10);
    PrintList(pHead);
    List_Node *listReversed = iteratorReverseList(pHead);
    PrintList(listReversed);
}
