/*
 * mainTask1.h
 *
 *  Created on: 14.02.2017
 *      Author: Micha³
 */

#ifndef TASKS_TASK1_MAINTASK1_H_
#define TASKS_TASK1_MAINTASK1_H_

#include "FreeRTOS.h"
#include "task.h"
#include "stm32f10x.h"
#include "queue.h"

extern void vTask1( void *pvParameters  );
extern void vTask2( void *pvParameters  );

xQueueHandle globalQueueHandle;
#endif /* TASKS_TASK1_MAINTASK1_H_ */
