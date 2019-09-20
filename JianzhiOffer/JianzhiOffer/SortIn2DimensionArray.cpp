//
//  SortIn2DimensionArray.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/10.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#include "SortIn2DimensionArray.hpp"

bool isNumberInMetrix(int* metrix, int rows, int columns, int number)
{
    bool found = false;
    
    if (metrix != nullptr && rows >= 1 && columns >= 1) {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            if (metrix[row * columns + column] > number) {
                column--;
            } else if (metrix[row * columns + column] == number){
                found = true;
                break ;
            } else
                row++;
        }
    }
    
    return found;
}
