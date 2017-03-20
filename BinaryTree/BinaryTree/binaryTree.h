//
//  binaryTree.h
//  BinaryTree
//
//  Created by zhaofuqiang on 2017/3/8.
//  Copyright © 2017年 zhaofuqiang. All rights reserved.
//

#ifndef binaryTree_h
#define binaryTree_h

#include <stdio.h>
#include <stdbool.h>

typedef int binary_type;

typedef struct BinaryTreeNode_ {
    binary_type data;
    struct BinaryTreeNode_ *left;
    struct BinaryTreeNode_ *right;
} BinaryTreeNode;


typedef struct BinaryTree_ {
    BinaryTreeNode *root;   //指向根节点的指针
    int size;
} BinaryTree;

#ifdef __cplusplus
extern "C" {
#endif


void initBinaryTree(BinaryTree *tree);
bool insertLeft(BinaryTree *tree, BinaryTreeNode *node, binary_type data, BinaryTreeNode **leftNode);
bool insertRight(BinaryTree *tree, BinaryTreeNode *node, binary_type data, BinaryTreeNode **rightNode);

//先序遍历
void preOrder(BinaryTree *tree, BinaryTreeNode *root);

//中序遍历
void inOrder(BinaryTree *tree, BinaryTreeNode *root);

//后序遍历
void postOrder(BinaryTree *tree, BinaryTreeNode *root);

//层级遍历
void breadthFirstOrder(BinaryTree *tree, BinaryTreeNode *root);

//层级遍历 且每层尾部要换行
void breadthFirstOrderByLevel(BinaryTree *tree, BinaryTreeNode *root);
    
void breadOrder(BinaryTree *tree);

//获取二叉树深度
int getBinaryTreeHeight(BinaryTreeNode *root);
    
#ifdef __cplusplus
}
#endif
//二叉树的深度 假定一个节点深度为1
#endif /* binaryTree_h */
