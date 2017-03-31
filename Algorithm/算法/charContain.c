//
//  stringContain.c
//  算法
//
//  Created by _ on 17/3/29.
//  Copyright © 2017年 zfq. All rights reserved.
//

#include "charContain.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool charContain(char *a, char *b)
{
    int hash = 0;
    
    /*
     
     a[i]-'A' 的取值范围为0~57 (z-A = 122 - 65 = 57)
     所以 1 << (a[i]-'A')的取值返回为（0，2，4，6，8...,144）,(即0~2n)
     即让1左移动（a[i]-'A'）位
     |表示按位或，只要有一个为1，那么结果就为1，否则
     
     int型变量占4字节 共32位
     int型变量a的第k位清0，即a=a&~(1<<k)
     将int型变量a的第k位置1， 即a=a|(1<<k)
     
     c++中有这个文件
     #include <bitset>
     */
    //计算hash
    size_t len = strlen(a);
    for (size_t i = 0; i < len; i++) {
        hash |= (1 << (a[i] - 'A'));
    }
    
    //判断字符串a中是否都包含字符串b中的字符
    for (int i = 0; i < strlen(b); i++) {
        if ((hash & (1 << (b[i] - 'A'))) == 0) {
            return false;
        }
    }
    return true;
}

bool charContain2(char *a, char *b)
{
    //ASCII码总共128个
    int array[128] = {0};
    
    //标记数组
    for (int i = 0; i < strlen(a); i++) {
        array[a[i]] = 1;
    }
    
    for (int j = 0; j < strlen(b); j++) {
        if (array[b[j]] == 0) {
            return false;
        }
    }
    
    return true;
}

char firstRepeatedChar(char *a)
{
    //ASCII码总共128个
    int array[128] = {0};
    //标记数组
    for (int i = 0; i < strlen(a); i++) {
        array[a[i]] += 1;
        if (array[a[i]] > 1) {
            return a[i];
        }
    }
    return '\0';
}

bool isSubsequence(char *a, char *b)
{
    //abcd  de
    if (strlen(b) == 0) {
        return true;
    }
    
    int i = 0,j = 0;
    size_t lenA = strlen(a);
    size_t lenB = strlen(b);
    while (i < lenA && j < lenB) {
        
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            i++;
        }
        
    }
    if (i == lenA && j < lenB) {
        return false;
    } else {
        return true;
    }
}

//给40亿个不重复的unsigned int的整数，没排过序的，然后再给一个数，如何快速判断这个数是否在那40亿个数当中
bool numIsExistInArray(int findNum, int *array, int arraySize)
{
    //使用bitmap来判断,用每一个
    int bitSize = sizeof(int) * 8;  //int类型所占的位数
    long long maxIntValue = pow(2,bitSize-1) - 1;  //unint = 2^n  intMax = 2^(n-1)-1
    //2^31 - 1 = 2147483647 约为2520MB
    char *p = (char *)malloc(maxIntValue * sizeof(char));
    memset(p, 0, maxIntValue);
    
    for (int i = 0; i < arraySize; i++) {
        p[array[i]] = '1';   //或者*p|=(1<<(i%maxIntValue))
    }
    
    bool result = true;
    if (p[findNum] == 0) {
        result = false;
    }
    
    free(p);
    return result;
}

