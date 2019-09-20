//
//  DivideAndConquer.hpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/8.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#ifndef DivideAndConquer_hpp
#define DivideAndConquer_hpp

#include <stdio.h>

void merge_sort(int *array, int left, int right, int *result);

#endif /* DivideAndConquer_hpp */


/*
 int array[] = {1, 3, 5, 10, 9, 6, 2, 8, 4, 7};
 int length = sizeof(array) / sizeof(int);
 int *ptr = new int(length);
 merge_sort(array, 0, length - 1, ptr);
 for (int i = 0; i < length; i++) {
 cout << array[i] << endl;
 }
*/
