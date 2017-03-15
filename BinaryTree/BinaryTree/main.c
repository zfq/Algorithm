//
//  main.c
//  BinaryTree
//
//  Created by zhaofuqiang on 2017/3/8.
//  Copyright © 2017年 zhaofuqiang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void initData(BinaryTree *tree);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    initBinaryTree(tree);
    initData(tree);
    
    preOrder(tree, tree->root);
    
    printf("\n");
    inOrder(tree, tree->root);
    
    printf("\n");
    postOrder(tree, tree->root);
    
    printf("\n");
    breadthFirstOrder(tree, tree->root);
    int a = 1;
    return 0;
}

void initData(BinaryTree *tree)
{
    //创建根节点2
    insertLeft(tree, NULL, 2,NULL);
    
    //2L = 5 2R = 8
    BinaryTreeNode *leftNode = NULL;
    BinaryTreeNode *rightNode = NULL;
    insertLeft(tree, tree->root, 5, &leftNode);
    insertRight(tree, tree->root, 8, &rightNode);
    
    //5L=4 5R=6
    insertLeft(tree, leftNode, 4, NULL);
    insertRight(tree, leftNode, 6, NULL);
//
//    //8L=3 8R=1
    insertLeft(tree, rightNode, 3, NULL);
    insertRight(tree, rightNode, 1, NULL);
    
//    int a = 1;
}
