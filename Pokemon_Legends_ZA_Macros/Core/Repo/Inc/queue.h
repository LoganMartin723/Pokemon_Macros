/*
 * queue.h
 *
 *  Created on: Dec 7, 2024
 *      Author: LogMa
 */

#include "main.h"
#include "stdint.h"

#include "../../Repo/Inc/cpp_main.h"

#ifndef REPO_INC_QUEUE_H_
#define REPO_INC_QUEUE_H_


#define QUEUE_BUFF_SIZE 50
#define BUFF_END 49


class queue{
    void* buffer[QUEUE_BUFF_SIZE];
    uint8_t head = 0;
    uint8_t tail = 0;

public:
    queue();
    bool enqueue(void* msg);
    bool dequeue(void** msg);
};


#endif /* REPO_INC_QUEUE_H_ */
