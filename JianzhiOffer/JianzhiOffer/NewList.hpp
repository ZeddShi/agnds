//
//  NewList.hpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/27.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#ifndef NewList_hpp
#define NewList_hpp

#include <stdio.h>

struct List_Node {
    int value;
    List_Node *pNext;
};

List_Node* CreateListNode(int value);
List_Node* CreatList(int max);
void ConnectListNodes(List_Node* pCurrent, List_Node* pNext);
void PrintListNode(List_Node* pNode);
void PrintList(List_Node* pHead);
void DestroyList(List_Node* pHead);
void AddToTail(List_Node** pHead, int value);
void RemoveNode(List_Node** pHead, int value);

#endif /* NewList_hpp */
