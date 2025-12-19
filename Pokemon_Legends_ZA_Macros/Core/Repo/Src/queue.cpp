/*
 * queue.cpp
 *
 *  Created on: Dec 7, 2024
 *      Author: LogMa
 */


#include "../../Repo/Inc/queue.h"

queue::queue(){
    // q_load = 0 via "attribute = 0" style
}

bool queue::enqueue(void* msg){ //works with the tail
    bool ok = false;
    if ((tail == BUFF_END && head == 0) || (tail + 1) == head){ //This means that the buffer will be "empty" and we will be unable to dequeue
        ok = false;
    }
    else{
        buffer[tail] = msg;

        if(tail == BUFF_END){
            tail = 0;
        }
        else
            tail++;

        ok = true;
    }
    return ok;
}

bool queue::dequeue(void** msg){ //works with the head
    bool ok = false;
    if (head == tail) {
        ok = false;
    }
    else{
        *msg = buffer[head];

        buffer[head] = 0;

        if(head == (BUFF_END))
            head = 0;
        else
            head++;
        ok=true;
    }
    return ok;
}

