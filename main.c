

/* Standard includes. */
#include <stdio.h>
#include <string.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* Library includes. */
#include "stm32f10x.h"
#include "gpio.h"
#include "Tasks/Task1/mainTask1.h"
volatile unsigned long ulHighFrequencyTimerTicks;
/*-----------------------------------------------------------*/

//extern void SystemInit(void);
//extern void vTask1( void *pvParameters  );
//extern void vTask2( void *pvParameters  );
/**
 * Configures the timers and interrupts for the fast interrupt test as
 * described at the top of this file.
 */




int main( void )
{


	 //SystemInit();
	#ifdef RAM_FLASH
		SCB->VTOR = ((uint32_t)0x20000000);   // ram
	 #else
		SCB->VTOR = ((uint32_t)0x08000000);   // flash
	 #endif

	RCC->APB2ENR = RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN |
							 RCC_APB2ENR_AFIOEN;

	gpio_pin_cfg(GPIOA, 5, GPIO_CRx_MODE_CNF_OUT_PP_2M_value);
	gpio_pin_cfg(GPIOA, 0, GPIO_CRx_MODE_CNF_OUT_PP_2M_value);

	globalQueueHandle = xQueueCreate(3, sizeof(int));

 	xTaskCreate( vTask2, ( signed portCHAR * ) "task1", configMINIMAL_STACK_SIZE*2,
 							NULL, tskIDLE_PRIORITY +1, NULL );

 	xTaskCreate( vTask1, ( signed portCHAR * ) "task1", configMINIMAL_STACK_SIZE*2,
 	 							NULL, tskIDLE_PRIORITY +1, NULL );


	/* Start the scheduler. */
	vTaskStartScheduler();



    /* Will only get here if there was insufficient memory to create the idle
    task. */
	return 0;
}





void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed portCHAR *pcTaskName )
{
	for( ;; );
}
