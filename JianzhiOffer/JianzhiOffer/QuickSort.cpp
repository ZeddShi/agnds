//
//  QuickSort.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/16.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "QuickSort.hpp"
#include <stdlib.h>
#include <time.h>
#include <exception>

using namespace std;
int randomAccess(int start, int end);
void swap(int *a, int *b);
int partition(int data[], int start, int end);

void quickSort(int data[], int start, int end)
{
    int index = partition(data, start, end);
    if (index > start) {
        quickSort(data, start, index - 1);
    }
    if (index < end) {
        quickSort(data, index + 1, end);
    }
}

int partition(int data[], int start, int end)
{
    if (data == nullptr || start  < 0 || end < start)
        throw std::exception();
    int partitionNum = start - 1;
    int index = randomAccess(start, end);
    swap(&data[index], &data[end]);
    for (int i = start; i < end; i++) {
        if (data[i] < data[end]) {
            partitionNum++;
            if (partitionNum != i)
                swap(&data[i], &data[partitionNum]);
        }
    }
    partitionNum++;
    swap(&data[end], &data[partitionNum]);
    return partitionNum;
}

int randomAccess(int start, int end)
{
    srand((unsigned)time(nullptr));
    return (rand() % (end - start + 1)) + start;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSortTest()
{
    const int length = 8;
    int datas[length] = {8, 2, 4, 3, 5, 9, 7, 6};
    quickSort(datas, 0, length - 1);
    for (int i = 0; i < length; i++) {
        cout << datas[i] << endl;
    }
}
