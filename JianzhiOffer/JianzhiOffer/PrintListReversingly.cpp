//
//  PrintListReversingly.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/15.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};

void printListReversingly(ListNode *pHead)
{
    if (pHead != nullptr) {
        if (pHead -> m_pNext != nullptr) {
            printListReversingly(pHead -> m_pNext);
        }
        printf("%d\n", pHead -> m_nKey);
    }
}

void test(ListNode *pHead)
{
    
}
