//
//  MergeSortedlist.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/27.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "MergeSortedlist.hpp"
#include "NewList.hpp"


List_Node* mergeSortedList(List_Node *list_1, List_Node *list_2)
{
    if (list_1 == nullptr)
        return list_2;
    if (list_2 == nullptr)
        return list_1;
    List_Node *pNewHead = (list_1->value <= list_2->value) ? list_1 : list_2;
    List_Node *pNode_1 = pNewHead;
    List_Node *pNode_2 = (pNewHead == list_1) ? list_2 : list_1;
    while (pNode_1->pNext != nullptr && pNode_2 != nullptr) {
        List_Node *next_1 = pNode_1->pNext;
        List_Node *next_2 = pNode_2->pNext;
        if (pNode_1->value <= pNode_2->value) {
            if (next_1->value > pNode_2->value) {
                pNode_1->pNext = pNode_2;
                pNode_2->pNext = next_1;
                pNode_1 = pNode_2;
                pNode_2 = next_2;
                continue;
            }
            pNode_1 = next_1;
        }
    }

    while (pNode_1->pNext == nullptr)
        pNode_1->pNext = pNode_2;
    
    return pNewHead;
}

void mergeSortedListTest()
{
    int array1[8] = {2, 4, 6, 7, 8, 10, 14, 23};
    int array2[8] = {1, 3, 5, 9, 12, 15, 17, 25};
    List_Node *header_1 = nullptr;
    List_Node *header_2 = nullptr;
    for (int i = 7; i >= 0; i--) {
        List_Node *p = new List_Node();
        p->value = array1[i];
        p->pNext = header_1;
        header_1 = p;
    }
    PrintList(header_1);
    for (int j = 7; j >= 0; j--) {
        List_Node *p = new List_Node();
        p->value = array2[j];
        p->pNext = header_2;
        header_2 = p;
    }
    PrintList(header_2);
    List_Node *pNew = mergeSortedList(header_1, header_2);
    PrintList(pNew);
}
