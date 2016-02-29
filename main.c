
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Scheduler include files. */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

#include "temperatureTask.h"
#include "motionTask.h"
#include "decoderTask.h"

/**
 *  main function of the program here
 *  Creates the task and starts the scheduler
 */

int main()
{
	//xTaskCreate(temperatureTask, (const portCHAR *)"", 256, NULL, 3, NULL);
	xTaskCreate(motionTask, (const portCHAR *)"", 256, NULL, 3, NULL);
	xTaskCreate(decoderTask, (const portCHAR *)"", 256, NULL, 3, NULL);
    //vTaskStartScheduler();
}



/**
 *  This function needs to be here.
 *
 *  @param xTask
 *  @param pcTaskName
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, portCHAR *pcTaskName)
{
    while (1)
        ;
}
