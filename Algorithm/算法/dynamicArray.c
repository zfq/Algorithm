//
//  dynamicArray.c
//  算法
//
//  Created by _ on 18/05/2017.
//  Copyright © 2017 zfq. All rights reserved.
//

#include "dynamicArray.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct dynamic_array_data_ {
    struct dynamic_array_data_ *next;
    struct dynamic_array_data_ *pre;
    void *data;
} dynamic_array_data;

typedef struct dynamic_array_ {
    int size;
    void (*destroy)(void *data);
    dynamic_array_data *header;
} dynamic_array;



//创建数组
dynamic_array * dynamic_array_init(int capacity)
{
    dynamic_array *header = NULL;
    dynamic_array *array = NULL;
    array = realloc(header, capacity * sizeof(dynamic_array_data));
    if (array == NULL) {
        printf("Creat dynamic array failed!\n");
    }
    return array;
}


//数组长度
int dynamic_array_size(dynamic_array *array)
{
    return array->size;
}

//添加数据
bool dynamic_array_append(dynamic_array *array, dynamic_array_data *data);

bool dynamic_array_delete(dynamic_array *array, int index, void (*dealloc)())
{
    bool result = false;
    
    dynamic_array_data *currData = array->header;
    int currIndex = 0;
    while (currData) {
        if (currIndex == index) {
            //找到前一个节点
            dynamic_array_data *pre_data = currData->pre;
            pre_data->next = currData->next;
            currData->next = NULL;
            
            //释放数据
            if (dealloc) {
//                currData->dealloc = dealloc;
            }
            if (currData) {
                free(currData);
            }
            result = true;
        }
        currIndex++;
        currData = currData->next;
    }
    
    return result;
}
