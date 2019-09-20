//
//  BinaryTree.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/16.
//  Copyright © 2017年 Zedd. All rights reserved.
//
#include "BinaryTree.hpp"

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->value = value;
    pNode->left = nullptr;
    pNode->right = nullptr;
    
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->value);
        
        if(pNode->left != nullptr)
            printf("value of its left child is: %d.\n", pNode->left->value);
        else
            printf("left child is nullptr.\n");
        
        if(pNode->right != nullptr)
            printf("value of its right child is: %d.\n", pNode->right->value);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }
    
    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);
    
    if(pRoot != nullptr)
    {
        if(pRoot->left != nullptr)
            PrintTree(pRoot->left);
        
        if(pRoot->right != nullptr)
            PrintTree(pRoot->right);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->left;
        BinaryTreeNode* pRight = pRoot->right;
        
        delete pRoot;
        pRoot = nullptr;
        
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
