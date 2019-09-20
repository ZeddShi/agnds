//
//  CreatQueue.cpp
//  JianzhiOffer
//
//  Created by Zedd on 2017/9/19.
//  Copyright © 2017年 Zedd. All rights reserved.
//

// 将队列最后一位移到第一位
// 可以获取某个位置的值
// 可以插入到队列中的某个位置


#include "CreatQueue.hpp"

using namespace std;

CustomQueue* initQueue()
{
    CustomQueue *queue = new CustomQueue;
    if (queue) {
        queue->head = 0;
        queue->tail = 0;
        return queue;
    }
    else
        return nullptr;
}

bool isQueueEmpty(CustomQueue *queue)
{
    return (queue->head == queue->tail);
}

bool isQueueFull(CustomQueue *queue)
{
    return (queue->tail == QUEUELEN);
}

void clearQueue(CustomQueue *queue)
{
    if (queue) {
        queue->head = 0;
        queue->tail = 0;
    }
}

void releaseQueue(CustomQueue *queue)
{
    if (queue) {
        delete queue;
        queue = nullptr;
    }
}

void addDataToQueue(CustomQueue *queue, QueueData data)
{
    if (isQueueFull(queue))
        cout << "the queue is full" << endl;
    else
        queue->data[queue->tail++] = data;
}

QueueData* leaveQueue(CustomQueue *queue)
{
    if (isQueueEmpty(queue))
        return nullptr;
    QueueData *toLeave = &(queue->data[queue->head++]);
    return toLeave;
}

QueueData* readQueue(CustomQueue *queue)
{
    if (isQueueEmpty(queue))
        return nullptr;
    else
        return &(queue->data[queue->head]);
}

int queueLength(CustomQueue *queue)
{
    return (queue->tail - queue->head);
}










