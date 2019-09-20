//
//  Test5ReplaceBlankspace.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/10.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "Test5ReplaceBlankspace.hpp"

void replaceBlankSpaces(char* originChars, int length)
{
    if (originChars == nullptr || length == 0)
        return;
    
    int originLength = 0;
    int numberOfBlankSpace = 0;
    int i = 0;
    while (originChars[i] != '\0') {
        originLength++;
        if (originChars[i] == ' ')
            numberOfBlankSpace++;
        i++;
    }
    
    int newLength = originLength + 2 * numberOfBlankSpace;
    int originIndex = originLength;
    int newIndex = newLength;
    if (newLength > length) {
        return;
    }
    
    while (originIndex >= 0 && newIndex > originIndex) {
        if (originChars[originIndex] == ' ') {
            originChars[newIndex--] = '0';
            originChars[newIndex--] = '2';
            originChars[newIndex--] = '%';
        } else {
            originChars[newIndex--] = originChars[originIndex];
        }
        originIndex--;
    }
}
