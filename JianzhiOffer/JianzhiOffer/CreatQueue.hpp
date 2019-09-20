//
//  CreatQueue.hpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/19.
//  Copyright © 2017年 Zedd. All rights reserved.
//

#ifndef CreatQueue_hpp
#define CreatQueue_hpp

#include <iostream>
#include <string>

#define QUEUELEN 100

struct QueueData {
    std::string name;
    int age;
};

struct CustomQueue {
    QueueData data[QUEUELEN];
    int head;
    int tail;
};

#pragma mark - manage queue
CustomQueue* initQueue();
bool isQueueEmpty(CustomQueue *queue);
bool isQueueFull(CustomQueue *queue);
void clearQueue(CustomQueue *queue);
void releaseQueue(CustomQueue *queue);
void addDataToQueue(CustomQueue *queue, QueueData data);
QueueData* leaveQueue(CustomQueue *queue);
QueueData* readQueue(CustomQueue *queue);
int queueLength(CustomQueue *queue);
#endif /* CreatQueue_hpp */
