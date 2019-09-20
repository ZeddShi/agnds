//
//  SearchAndReplace.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/8.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "SearchAndReplace.hpp"

bool isDuplicate(int *array, int length, int *duplication)
{
    if (array == nullptr || length == 0) {
        return false;
    }
    
    for (int i =0; i < length; i++) {
        if (array[i] < 0 || array[i] > length - 1) {
            return false;
        }
    }
    
    for (int i =0; i < length; i++) {
        while (array[i] != i) {
            if (array[i] == array[array[i]]) {
                *duplication = array[i];
                return true;
            }
            
            int tmp = array[i];
            array[i] = array[tmp];
            array[tmp] = tmp;
        }
    }
    return false;
}
