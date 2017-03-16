




#include "mainTask1.h"






void vTask1( void *pvParameters  )
{
	(void )pvParameters;

	int rxVariable;

	for( ;; )
	{

    	//vTaskDelay(10);

    	if(xQueueReceive(globalQueueHandle,&rxVariable,1000))
    	{
    		GPIOA->ODR ^= (1<<0);
    	}


	}
}

void vTask2( void *pvParameters  )
{

	int i;

	(void )pvParameters;

	for( ;; )
	{

    	vTaskDelay(100);
    	GPIOA->ODR ^= (1<<5);
    	i++;
    	xQueueSend(globalQueueHandle,&i,200);

	}
}

