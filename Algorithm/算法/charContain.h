//
//  charContain.h
//  算法
//
//  Created by _ on 17/3/29.
//  Copyright © 2017年 zfq. All rights reserved.
//

#ifndef charContain_h
#define charContain_h

#include <stdio.h>
#include <stdbool.h>

/**
 判断字符串b中的字符是否都在字符串a中

 @param a 长字符串
 @param b 短字符串
 @return true表示b中的字符是否都在字符串a中
 */
bool charContain(char *a, char *b);

/**
 判断字符串b中的字符是否都在字符串a中, 利用ASCII码数组
 
 @param a 长字符串
 @param b 短字符串
 @return true表示b中的字符是否都在字符串a中
 */
bool charContain2(char *a, char *b);

/**
 返回第一个重复的字符串

 @param a 字符串
 @return 返回第一个重复的字符串，如果不存在 返回\0
 */
char firstRepeatedChar(char *a);

/**
 判断b字符串是否是a的子序列，子串不要求在原字符串中是连续的,空串也算是a的子串

 @param a 字符串
 @param b 字符串
 @return 返回值
 */
bool isSubsequence(char *a, char *b);

/**
 判断一个数是否在数组中，
 

 @param findNum 带查找的数
 @param array 数组
 @param arraySize 数组长度
 @return 返回值
 */
bool numIsExistInArray(int findNum, int *array, int arraySize);

bool reverseString(char *a, int from, int to);
#endif /* charContain_h */
