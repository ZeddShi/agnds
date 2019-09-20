//
//  ReconstructBinaryTree.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/16.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "ReconstructBinaryTree.hpp"

BinaryTreeNode* constuct(int *start_preorder, int *end_preorder, int *start_inorder, int *end_inorder);

BinaryTreeNode* constructBinaryTree(int *preorder, int *inorder, int length)
{
    if (length <= 0 || preorder == nullptr || inorder == nullptr)
        return nullptr;
    return constuct(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* constuct(int *start_preorder, int *end_preorder, int *start_inorder, int *end_inorder)
{
    int rootValue = start_preorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root -> value = rootValue;
    root -> left = root -> right = nullptr;
    
    if (start_preorder == end_preorder) {
        if (start_inorder == end_inorder && *start_preorder == *start_inorder)
            return root;
        else
            printf("Invalid input\n");
    }
    
    int *rootInorder = start_inorder;
    while (*rootInorder != rootValue && rootInorder < end_inorder)
        rootInorder++;
    if (*rootInorder != rootValue && rootInorder == end_inorder)
        printf("Invalid input");
    
    int leftLength = int(rootInorder - start_inorder);
    int *leftPreorder_end = start_preorder + leftLength;
    
    if (leftLength > 0)
        root -> left = constuct(start_preorder + 1, leftPreorder_end, start_inorder, rootInorder - 1);
    
    if (leftLength < end_inorder - start_inorder)
        root -> right = constuct(leftPreorder_end + 1, end_preorder, rootInorder + 1, end_inorder);
    
    return root;
}

void test()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *pRoot = constructBinaryTree(preorder, inorder, length);
    PrintTree(pRoot);
}
