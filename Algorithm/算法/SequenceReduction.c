//
//  SequenceReduction.c
//  算法
//
//  数列还原
//
//  Created by _ on 16/05/2017.
//  Copyright © 2017 zfq. All rights reserved.
//

#include "SequenceReduction.h"


/*
 5 5 
 4 0 0 2 0
 
 先用一个二维数组 求出所有全排列，然后逐个比对
 
 */

void sr_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


/**
 是否应该交换, 用来去重复的全排列
 去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换
 
 @param array 原始数组
 @param left 左边
 @param right 右边
 @return false表示不应该交换，true表示应该交换
 */
bool sr_should_swap(int *array, int left, int right)
{
    while (left < right) {
        if (array[left] == array[right]) {
            return false;
        }
        left++;
    }
    return true;
}

//全排列
/*
 全排列就是从第一个数字起每个数分别与它后面的数字交换
 
 (aa交换) => abcd a不动 bcd重复 =>得到所有以a开头的全排列
        (bb交换) => bcd b不动 cd重复动作 left=1
                (cc交换) => cd left=2
                        c不动 此时就剩d了， left=3 right = 3, left == right 结束
                         left == right (当left == right时 就可以打印数据了)
                (cd交换) => dc
        (bc交换) => cbd
                ...
 
        (bd交换) => dcb
                 ...
 把aa交换回来 恢复成 abcd
 (ab交换) => bacd  b不动 acd重复 =>得到所有以b开头的全排列
  ...
  把ab交换回来 恢复成 abcd ,为下面的a与c交换做准备
 (ac交换) => cbad  c不动 bad重复 =>得到所有以c开头的全排列
 (ad交换) => dbca  d不动 bca重复 =>得到所有以d开头的全排列
 
 所有循环总共有n次，即数字的个数
 
 */
void permutation(int *originArray, int left, int right)
{
    int i = 0;
    if (left == right) {
        for (i = 0; i <= right; i++) {
            printf("%d ",originArray[i]);
        }
        printf("\n");
    } else {
        for ( i = left; i <= right; i++) {
            if (sr_should_swap(originArray, left, i)) {
                sr_swap(&(originArray[i]), &(originArray[left]));
                //从第left+1的下标开始全排列
                permutation(originArray, left+1, right);
                sr_swap(&(originArray[i]), &(originArray[left]));
            }
        }
    }
}

/**
 全排列

 @param originArray 数组
 @param left 起始下标
 @param right 终止下标
 */
void permutation2(int *originArray, int left, int right)
{
    for (int i = left; i <= right; i++) {
        
        sr_swap(&originArray[i],&originArray[left]);
        //判断数组中剩余的待全排列的元素是否大于1,如果大于1，就继续排列 否则就直接打印当前排列好的数据
        if (left+1 < right) {
            permutation2(originArray, left+1, right);
        } else {
            //打印这一组结果
            for (int j = 0; j <= right; j++) {
                printf("%d ",originArray[j]);
            }
            printf("\n");
        }
        sr_swap(&originArray[i],&originArray[left]);
    }
}

/*
void swap2(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}
void perm(int list[], int k, int m)
{
    int i;
    if(k > m)
    {
        for(i = 0; i <= m; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
    else
    {
        for(i = k; i <= m; i++)
        {
            swap2(&list[k], &list[i]);
            perm(list, k + 1, m);
            swap2(&list[k], &list[i]);
        }
    }
}
*/

/**
 判断此数组是否符号条件

 @param array 数组
 @param len 数组长度
 @param pairs 指定符号条件的对数
 @return true表示符合条件，false表示不符合条件
 */
bool isMatch(int *array, int len, int pairs)
{
    bool result = false;
    int currPairs = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (array[i] < array[j]) {
                currPairs++;
            }
        }
    }
    
    printf("符号条件的个数为:%d\n",currPairs);
    if (currPairs == pairs) {
        result = true;
    }
    return result;
}

