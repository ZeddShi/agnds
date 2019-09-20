//
//  SortIn2DimensionArray.hpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/10.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#ifndef SortIn2DimensionArray_hpp
#define SortIn2DimensionArray_hpp

#include <stdio.h>

bool isNumberInMetrix(int *metrix, int rows, int columns, int number);

#endif /* SortIn2DimensionArray_hpp */


/*
 int twoDimensionArray[4][3] = {{1, 2, 7}, {2, 5, 8}, {3, 6, 9}, {8, 9 ,10}};
 bool isIn = isNumberInMetrix((int *)twoDimensionArray, 4, 3, 8);
 if (isIn) {
 cout << "the number is in metrix" << endl;
 } else {
 cout << "isnot in" << endl;
 }
*/
