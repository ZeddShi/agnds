//
//  DivideAndConquer.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/8.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "DivideAndConquer.hpp"

void merge(int *array, int left, int right, int *result);

void merge_sort(int *array, int left, int right, int *result)
{
    if (right - left == 0) {
        return;
    } else if (right - left == 1){
        if (array[left] > array[right]) {
            int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
        }
        return;
    } else {
        int center = ((right - left) / 2 + left);
        merge_sort(array, left, center, result);
        merge_sort(array, center + 1, right, result);
        merge(array, left, right, result);
        
        for (int i = left; i <= right; i++) {
            array[i] = result[i];
        }
    }
}

void merge(int *array, int left, int right, int *result)
{
    int center = (right - left) / 2 + left;
    int left_index = left;
    int left_end_index = center;
    int right_index = center + 1;
    int right_end_index = right;
    int result_index = left;
    
    while (left_index <= left_end_index && right_index <= right_end_index) {
        if (array[left_index] <= array[right_index]) {
            result[result_index++] = array[left_index++];
        } else {
            result[result_index++] = array[right_index++];
        }
    }
    while (left_index <= left_end_index) {
        result[result_index++] = array[left_index++];
    }
    while (right_index <= right_end_index) {
        result[result_index++] = array[right_index++];
    }
}
