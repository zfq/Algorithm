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

//广度优先
void breadthFirstOrder(BinaryTree *tree, BinaryTreeNode *root);
#ifdef __cplusplus
}
#endif
//二叉树的深度 假定一个节点深度为1
#endif /* binaryTree_h */
