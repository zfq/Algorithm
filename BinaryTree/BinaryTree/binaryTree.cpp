//  binaryTree.c
//  BinaryTree
//
//  1代表成功 其他值代表失败
//
//  Created by zhaofuqiang on 2017/3/8.
//  Copyright © 2017年 zhaofuqiang. All rights reserved.
//

#include "binaryTree.h"
#include <stdbool.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void initBinaryTree(BinaryTree *tree)
{
    tree->size = 0;
    
    if (tree->root != NULL) {
        //释放tree->root
    }
    tree->root = NULL;
}

/*
 是否是叶子节点
 */
int isLeafNode(BinaryTreeNode *node)
{
    return node->left == NULL;
}

BinaryTreeNode * createTreeNode(binary_type data)
{
    BinaryTreeNode *newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
 /**
  将数据插入到node的左子树上，如果node不存在 则返回false

  @param tree tree
  @param node node
  @param data 数据
  @param leftNode 左子树新的叶子节点
  @return false表示插入失败，true表示插入成功
  */

bool insertLeft(BinaryTree *tree, BinaryTreeNode *node, binary_type data, BinaryTreeNode **leftNode)
{
    if (tree == NULL) return false;
    
    //判断节点node是不是叶子节点, 如果不是 则插入失败
    if (node && node->left) return false;
    
	//新建一个新的节点，并赋值
    BinaryTreeNode *newNode = createTreeNode(data);
    if (newNode == NULL) {
        return false;
    }
    
    //如果是空树，则将新建一个root节点
    if (tree->size == 0) {
        tree->root = newNode;
    } else {
        if (node == NULL) {
            return false;
        }
        node->left = newNode;
    }
    
    tree->size++;
    if (leftNode != NULL) {
        *leftNode = newNode;
    }
	return true; 
}


/*
 将数据data插入到节点node的右子树上
 */
bool insertRight(BinaryTree *tree, BinaryTreeNode *node, binary_type data, BinaryTreeNode **rightNode)
{
    if (tree == NULL) return false;
    
    //判断节点node是不是叶子节点, 如果不是 则插入失败
    if (node && node->right != NULL) return false;
    
    //新建一个新的节点，并赋值
    BinaryTreeNode *newNode = createTreeNode(data);
    if (newNode == NULL) {
        return false;
    }
    
    //如果是空树，则将新建一个root节点
    if (tree->size == 0) {
        tree->root = newNode;
    } else {
        if (node == NULL) {
            return false;
        }
        node->right = newNode;
    }
    
    tree->size++;
    
    if (rightNode != NULL) {
        *rightNode = newNode;
    }
    return true;
}

/**
 先序遍历 根左右

 @param tree 二叉树
 */
void preOrder(BinaryTree *tree, BinaryTreeNode *root)
{
    if (root == NULL) {
        return;
    } else {
        binary_type data = root->data;
        printf("%i ",data);
        
        preOrder(tree, root->left);
        preOrder(tree, root->right);
    }
}

/**
 中序遍历 左 根 右

 @param tree 二叉树
 @param root 根节点
 */
void inOrder(BinaryTree *tree, BinaryTreeNode *root)
{
    if (root == NULL) {
        return;
    } else {
        inOrder(tree, root->left);
        binary_type data = root->data;
        printf("%i ",data);
        inOrder(tree, root->right);
    }
}

/**
 后序遍历

 @param tree 二叉树
 @param root 根节点
 */
void postOrder(BinaryTree *tree, BinaryTreeNode *root)
{
    if (root == NULL) {
        return;
    } else {
        postOrder(tree, root->left);
        postOrder(tree, root->right);
        binary_type data = root->data;
        printf("%i ",data);
    }
}

/**
 广度优先遍历
 
 @param tree 二叉树
 @param root 根节点
 */
void breadthFirstOrder(BinaryTree *tree, BinaryTreeNode *root)
{
    if (root == NULL) {
        return;
    } else {
        queue<BinaryTreeNode *> myQueue;
        myQueue.push(tree->root);
        while (!myQueue.empty()) {
            BinaryTreeNode *node = myQueue.front();
            myQueue.pop();
            printf("%i ",node->data);
            
            if (node->left) {
                myQueue.push(node->left);
                
            }
            if (node->right) {
                myQueue.push(node->right);
            }
        }
    }
}


/**
 按层级变量二叉树，并在每一行尾部换行

 @param tree 二叉树
 @param root 根节点
 */
void breadthFirstOrderByLevel(BinaryTree *tree, BinaryTreeNode *root)
{
    if (root == NULL) {
        return;
    } else {
        int parentSize = 1, childSize = 0;
        queue<BinaryTreeNode *> myQueue;
        myQueue.push(tree->root);
        while (!myQueue.empty()) {
            BinaryTreeNode *node = myQueue.front();
            myQueue.pop();
            printf("%i ",node->data);
            
            if (node->left) {
                myQueue.push(node->left);
                childSize++;
            }
            if (node->right) {
                myQueue.push(node->right);
                childSize++;
            }
            
            parentSize--;
            if (parentSize == 0) {
                parentSize = childSize;
                childSize = 0;
                printf("\n");
            }
            
        }
    }
}

/**
 获取二叉树的高度

 @param root 根节点
 @return 二叉树的高度
 */
int getBinaryTreeHeight(BinaryTreeNode *root)
{
    if (root == NULL) {
        return 0;
    } else {
        return 1+ max(getBinaryTreeHeight(root->left), getBinaryTreeHeight(root->right));
    }
}

void breadOrderRecursively(BinaryTreeNode *root, int level, vector<vector<BinaryTreeNode *>> array)
{
    if (root == NULL) {
        return;
    }
    vector<BinaryTreeNode *> tmpArray = array[level];
    tmpArray.push_back(root);
    
    breadOrderRecursively(root->left, level+1, array);
    breadOrderRecursively(root->right, level+1, array);
}

void breadOrder(BinaryTree *tree)
{
    if (tree == NULL) {
        return;
    } else {
        int height = getBinaryTreeHeight(tree->root);
        //初始化数组 数组里面存放的是数组
        
        vector<vector<BinaryTreeNode *>> array(height);
        for (int i = 0; i < height; i++) {
            vector<BinaryTreeNode *> tmpArray;
            array[i] = tmpArray;
        }
        
        //递归变量
        breadOrderRecursively(tree->root, 0,array);
        
        //打印数组
        for (int i = 0 ; i < array.size(); i++) {
            vector<BinaryTreeNode *> tmpArray = array[i];
            for (int j = 0; j < tmpArray.size(); j++) {
                printf("%i ",tmpArray[j]->data);
            }
            printf("\n");
        }
        
        
        
    }
}


/*
//广度优先遍历 queue可以用链表实现
void PrintBFS(Node* root) {
    queue<Node*> Q;
    Q.push(root);
    do {
        Node *node = Q.front();
        Q.pop();
        cout << node->data << " ";
        if (node->pLeft)
            Q.push(node->pLeft);
        if (node->pRight)
            Q.push(node->pRight);
    }
    while (!Q.empty());
}
*/
