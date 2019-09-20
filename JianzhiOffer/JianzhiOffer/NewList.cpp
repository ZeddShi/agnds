//
//  NewList.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/27.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "NewList.hpp"
#include <stdlib.h>

List_Node* CreateListNode(int value)
{
    List_Node* pNode = new List_Node();
    pNode->value = value;
    pNode->pNext = nullptr;
    
    return pNode;
}

List_Node* CreatList(int max)
{
    List_Node *pHead = nullptr;
    for (int i = max; i >= 1; i--) {
        List_Node *p = new List_Node();
        p->value = i;
        p->pNext = pHead;
        pHead = p;
    }
    return pHead;
}

void ConnectListNodes(List_Node* pCurrent, List_Node* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    
    pCurrent->pNext = pNext;
}

void PrintListNode(List_Node* pNode)
{
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->value);
    }
}

void PrintList(List_Node* pHead)
{
    printf("PrintList starts.\n");
    
    List_Node* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->value);
        pNode = pNode->pNext;
    }
    
    printf("\nPrintList ends.\n");
}

void DestroyList(List_Node* pHead)
{
    List_Node* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(List_Node** pHead, int value)
{
    List_Node* pNew = new List_Node();
    pNew->value = value;
    pNew->pNext = nullptr;
    
    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        List_Node* pNode = *pHead;
        while(pNode->pNext != nullptr)
            pNode = pNode->pNext;
        
        pNode->pNext = pNew;
    }
}

void RemoveNode(List_Node** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;
    
    List_Node* pToBeDeleted = nullptr;
    if((*pHead)->value == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->pNext;
    }
    else
    {
        List_Node* pNode = *pHead;
        while(pNode->pNext != nullptr && pNode->pNext->value != value)
            pNode = pNode->pNext;
        
        if(pNode->pNext != nullptr && pNode->pNext->value == value)
        {
            pToBeDeleted = pNode->pNext;
            pNode->pNext = pNode->pNext->pNext;
        }
    }
    
    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
