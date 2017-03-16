/** \file hdr_special_registers.h
 * \brief Header with definition of bits in special registers in ARMv7-M core
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2010-04-02
 */

/******************************************************************************
* chip: ARMv7-M (Cortex-M3)
* compiler: arm-none-eabi-gcc (Sourcery G++ Lite 2009q3-68) 4.4.1
******************************************************************************/

#ifndef HDR_SPECIAL_REGISTERS_H_
#define HDR_SPECIAL_REGISTERS_H_

/*
+-----------------------------------------------------------------------------+
| PRIMASK - Register to mask out configurable exceptions
+-----------------------------------------------------------------------------+
*/

#define PRIMASK_MASK_EXCEPTIONS_bit			0

#define PRIMASK_MASK_EXCEPTIONS				(1 << PRIMASK_MASK_EXCEPTIONS_bit)

/*
+-----------------------------------------------------------------------------+
| FAULTMASK - Register to raise priority to the HardFault level
+-----------------------------------------------------------------------------+
*/

#define FAULTMASK_MASK_EXCEPTIONS_bit		0

#define FAULTMASK_MASK_EXCEPTIONS			(1 << FAULTMASK_MASK_EXCEPTIONS_bit)

/*
+-----------------------------------------------------------------------------+
| CONTROL - The special-purpose control register
+-----------------------------------------------------------------------------+
*/

#define CONTROL_THREAD_UNPRIVILEGED_bit		0
#define CONTROL_ALTERNATE_STACK_bit			1

#define CONTROL_THREAD_UNPRIVILEGED			(1 << CONTROL_THREAD_UNPRIVILEGED_bit)
#define CONTROL_ALTERNATE_STACK				(1 << CONTROL_ALTERNATE_STACK_bit)

/******************************************************************************
* END OF FILE
******************************************************************************/
#endif /* HDR_SPECIAL_REGISTERS_H_ */
