/*******************************************************************************
 *                                                                             *
 * [MODULE]:      PORT                                                         *
 *                                                                             *
 * [FILE NAME]:   Port.c                                                       *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        07/10/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for Port driver                                  *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "tm4c123gh6pm.h"
#include "Port.h"

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
void Port_Init(void)
{
    /* Enable the clock for GPIO Port F */
    SYSCTL_RCGCGPIO_R |= (1U << 5);

    /* Wait until the clock for GPIO Port F is ready */
    while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0);

    /* Unlock GPIO Port F */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;

    /* Enable the commit register for GPIO Port F */
    GPIO_PORTF_CR_R |= (1U << 5);

    /* Set the direction of the pin */
    GPIO_PORTF_DIR_R |= (1U << 5);

    /* Enable digital functionality for the pin */
    GPIO_PORTF_DEN_R |= (1U << 5);
}



