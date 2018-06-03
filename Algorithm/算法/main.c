//
//  main.c
//  算法
//
//  Created by _ on 16/10/17.
//  Copyright © 2016年 zfq. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "charContain.h"
#include "SequenceReduction.h"

int strToInt(char *);
void decimalToBinay(int num);
void convertStr(char *str);
void bubbleSort(int *array,int len);
void selectSort(int *array,int len);
void insertSort(int *array,int len);
void quickSort(int *array,int left,int right);
void quickSort2(int data[],int length,int start,int end);
int binarySearch(int A[],int len, int num);


int main(int argc, const char * argv[]) {
    
    /*
    char *str = "1234";
    int c = strToInt(str);
    printf("%i\n",c);
     */
    
    /*
    decimalToBinay(12); // 1100
     */
    
    /*
    char *str = "Hello  ";
    convertStr(str);
     */
    
    /*
    int a[] = {3,2,1,4,3,5,9,8,7,6}; //,4,3,5,9,8,7,6
    bubbleSort(a,10);
    selectSort(a, 10);
    insertSort(a, 10);
    quickSort2(a, 10,0, 9);
    
    //打印
    for (int i = 0; i < 10; i++) {
        printf("%i ",a[i]);
    }
     */
    
    /*
    int a[] = {3,3,5};
    size_t size = sizeof(a)/sizeof(a[0]);
    binarySearch(a, size, 3);
     */
    
    /*
    bool isContain = charContain2("ABCCCD", "A");
    char c = firstRepeatedChar("ABC!!CCDD");
    bool result = isSubsequence("ABCCCD", "BD");
    size_t t1= sizeof(int);
    */
    
    /*
    char *b = "ABCDE"; b[1] = '4'; //这种b存放在常量区，不可修改，b是个指针
     */
    
    /*
    char b[] = "ABCDE";
    reverseString(b, 0, 3);
    printf("%s\n",b);
     */
    
    /*
    int a[5] = {4, 0, 1, 2 ,0};
    bool result = isMatch(a, 5, 3);
    char *info = result == true ? "符号条件":"不符合条件";
    printf("%s\n",info);
    swap1(a, (a+1));
    */
    
    /*
    int a[] = {1, 2 ,3,4};
    permutation2(a, 0, 2);
     */
    
    /*
    char *str = "jsdfsdf sdfsdf";
    size_t hash = 1+*str;
    while (*str) {
        hash = *str++;
    }
    */
    
    /*
    int a[] = {-4,4};
//    int a[] = {1,1};
    maxDiffInArray(a, 2);
     */
    
    int a[] = {-5,-3,-1,-2,-1};
    maxSumOfSubarray(a, 5);
    return 0;
}

//二分查找,假定数组A从小到大排列
int binarySearch(int A[],int len, int num)
{
    int left = 0,right = len-1;
    while (left < right) {
        int mid = (left + right)/2;
        if (A[mid] < num) {
            left = mid+1;
        } else if (A[mid] > num) {
            right = mid - 1;
        } else {
            printf("找到数字,位置为:%d\n",mid);
            return mid;
        }
    }
    
    if (A[left] != num) {
        printf("没有找到数字\n");
        return -1;
    } else {
        printf("找到数字,位置为:%d\n",left);
        return left;
    }
}

//合并两个有序数组 A足够长
void merge (int A[],int m,int B[],int n)
{
    
    int len = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    
    while (len > 0) {
        
        //B中还有未遍历的元素,说明B数组多，A的少直接赋值
        if (i < 0) {
            A[len] = B[j];
            j--;
            len--;
            continue;
        }
        
        //A中还有未剩下的元素,说明B数组数量少
        if (j < 0) {
            A[len] = A[i];
            j--;
            len --;
            continue;
        }
        
        // B中的元素比A的大，则B继续走
        if (A[i] < B[j]) {
            A[len] = B[j];
            j--;
        }
        len--;
        
    }
}

int randomInRange(int start,int end)
{
    return start + (arc4random())%(end - start+1);
}

void swapP(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int data[],int length,int start,int end)
{
    if (data == NULL || length <= 0 || start < 0 || end > length-1) {
        printf("Invalid parameters");
        return -1;
    }
    
    int index = randomInRange(start,end);
    swapP(&data[index], &data[end]);
    
    int small = start - 1;
    for (index = start; index < end; index ++) {
        
        if (data[index] < data[end]) {
            small++;
            if (small != index) {
                swapP(&data[index], &data[small]);
            }
        }
    }
    small++;
    swapP(&data[small], &data[end]);
    return small;
}

void quickSort2(int data[],int length,int start,int end)
{
    if (start == end) {
        return;
    }
    
    int index = partition(data, length, start, end);
    if (index > start) {
        quickSort2(data, length, start,index-1);
    }
    
    if (index < end) {
        quickSort2(data, length, index+1,end);
    }
}


//=====================
//快速排序
/*
 设置两个变量i,j 其中i=0,j=len-1,
 i从前往后搜索，找到第一个大于key的值a[i]，将a[i]与a[j]互换
 j从后往前搜索,找到第一个小于key的值a[j],将a[j]与a[i]互换
 直到i=j时停止
 然后使i+1 j-1继续上述步骤 直到i=j 循环结束
 */
void swap(int a,int b);
void quickSort(int *array,int left,int right)
{
    if (left >= right) {
        return;
    }
    int key = array[left];  //key相当于挖的坑，
    int first = left;
    int last = right;
    
    while (first < last) {
        //如果没有找到比key小的数，就继续往前寻找,坑是first
        while (first < last && array[last] >= key) {
            last--;
        }
        array[first] = array[last]; //找到这样的数就把它赋值给key所在的位置（即坑的位置）
        
        //如果没有找到比key大的数，就继续往后寻找,坑是last
        while (first < last && array[first] <= key) {
            first++;
        }
        array[last] = array[first];
    }
    
    array[first] = key;
    quickSort(array, left, first-1);
    quickSort(array, first+1, right);
}

void swap(int a,int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//=====================
//插入排序
void insertSort(int *array,int len)
{
    for (int i = 0; i < len; i++) {
        int j = i+1;
        int tmp = array[j]; //array[j]为待插入的元素
        while (j > 0 && tmp < array[j-1]) {
            if (array[j-1] > tmp) {
                array[j] = array[j-1]; //后移
            }
            j--;
        }
        array[j] = tmp; //插入元素
    }
}

//321 0
//3201 3021

//=====================
//选择排序
/* 
 找到最小的数的位置 让他跟第一个数交换位置 ，找到次小的数的位置，让他跟第二个数交换位置，
 以此类推，直到交换到len-2的位置,(len-1)为最后一位
 */

void selectSort(int *array,int len)
{
    for (int i = 0; i < len-1; i ++) {
        int min = i;
        for (int j = i+1; j < len; j++) {   //注意是 j < len 不是j<len-1
            if (array[min] > array[j]) {
                min = j;
            }
        }
        
        //找到最小数 就与第i个数交换位置
        if (min != i) {
            int tmp = array[min];
            array[min] = array[i];
            array[i] = tmp;
        }
    }
}

//=====================
//冒泡排序
void bubbleSort(int *array,int len)
{
    for (int i = 0;i < len-1 ;i ++) {
        for (int j = 0; j < len-1-i; j++) {
            
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}


void convertStr(char *str)
{
    if (str == NULL) {
        return;
    }
    
    //获取空格的个数
    int spaceCount = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    
    char *newStr = malloc((strlen(str) + spaceCount*3 + 1) * sizeof(char));
    int n=0;
    
    for (int m = 0; m < strlen(str); m++) {
        if (str[m] == ' ') {
            newStr[n] = '%';
            newStr[n+1] = '2';
            newStr[n+2] = '0';
            n = n+2;
        } else {
            newStr[n] = str[m];
        }
        
        n++;
    }
    
    newStr[n] = '\0';
    
    //打印
    printf("%s",newStr);
    
    
    free(newStr);
}


void decimalToBinay(int num)  //2 10
{
    char a[100];
    memset(a, 0, sizeof(a));
    
    int i = 0;
    while (num >=2 ) {
        int c = num %2;
        a[i] = c + '0';
        i++;
        num = num/2;
    }
    a[i] = num + '0';
    a[i+1]='\0';
    
    int length = i+1;
    for (int j = length; j >= 0 ; j--) {
        printf("%c",a[j]);
    }
}

int strToInt(char *str)
{
    if (!str) {
        return 0;
    }
    
    int num = 0;
    
    //符号位
    int factor = 1;
    if (strlen(str) >= 1) {
        if (str[0] == '+') {
            str++;
        } else if (str[0] == '-') {
            str++;
            factor = -1;
        }
    }
    
    while (*str != '\0') {
        num = num * 10 + *str - '0';
        str++;
    }
    
    return num * factor;
}
