/*******************************************************************************
 *                                                                             *
 * [MODULE]:      DIO                                                          *
 *                                                                             *
 * [FILE NAME]:   DIO.c                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        07/10/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: source file for DIO driver                                   *
 *                                                                             *
 *******************************************************************************/

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "tm4c123gh6pm.h"
#include "Dio.h"

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    if (ChannelId >= DIO_NUMBER_OF_CHANNELS)
    {
        /* Invalid channel ID, handle error as needed */
/*#error Invalid channel ID */
    }

    /* Map the ChannelId to the appropriate GPIO port and pin */
    uint8 portIndex = ChannelId / DIO_NUMBER_OF_PINS_IN_PORT;
    uint8 pinIndex = ChannelId % DIO_NUMBER_OF_PINS_IN_PORT;

    volatile uint32* gpioDataReg = NULL_PTR;

    /* Determine the GPIO data register based on the port index */
    switch (portIndex)
    {
    case 0:
            gpioDataReg = &(GPIO_PORTA_DATA_R);
            break;

        case 1:
            gpioDataReg = &(GPIO_PORTB_DATA_R);
            break;

        case 2:
            gpioDataReg = &(GPIO_PORTC_DATA_R);
            break;

        case 3:
            gpioDataReg = &(GPIO_PORTD_DATA_R);
            break;

        case 4:
            gpioDataReg = &(GPIO_PORTE_DATA_R);
            break;

        case 5:
            gpioDataReg = &(GPIO_PORTF_DATA_R);
            break;

    default:
        break;
    }

    /* Read the value of the specified pin */
    uint32 pinValue = (*gpioDataReg >> pinIndex) & 0x01;

    /* Convert the read value to Dio_LevelType and return */
    return (uint8)pinValue;
}


/************************************************************************************
 * Service Name: Dio_WriteChannel
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - ID of DIO channel.
 *                  Level - Value to be written.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set a level of a channel.
 ************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    if (ChannelId >= DIO_NUMBER_OF_CHANNELS) {
        /* Invalid channel ID, handle error as needed */
/* #error Invalid channel ID */
    }

    /* Check if Level is either DIO_LOW or DIO_HIGH */
    if ((Level != STD_LOW) && (Level != STD_HIGH)) {
        /* Invalid Level, handle error as needed */
/* #error Invalid Level */
    }

    /* Map the ChannelId to the appropriate GPIO port and pin */
    uint8 portIndex = ChannelId / DIO_NUMBER_OF_PINS_IN_PORT;
    uint8 pinIndex = ChannelId % DIO_NUMBER_OF_PINS_IN_PORT;

    volatile uint32* gpioDataReg = NULL_PTR;

    /* Determine the GPIO data register based on the port index */
    switch (portIndex)
    {
    case 0:
        gpioDataReg = &(GPIO_PORTA_DATA_R);
        break;

    case 1:
        gpioDataReg = &(GPIO_PORTB_DATA_R);
        break;

    case 2:
        gpioDataReg = &(GPIO_PORTC_DATA_R);
        break;

    case 3:
        gpioDataReg = &(GPIO_PORTD_DATA_R);
        break;

    case 4:
        gpioDataReg = &(GPIO_PORTE_DATA_R);
        break;

    case 5:
        gpioDataReg = &(GPIO_PORTF_DATA_R);
        break;

    default:
        break;

    }

    /* Write the Level to the specified pin */
    if (Level == STD_LOW)
    {
        /* Clear the bit */
        *gpioDataReg &= ~(1U << pinIndex);
    }

    else if (Level == STD_HIGH)
    {
        /* Set the bit */
        *gpioDataReg |= (1U << pinIndex);
    }
}


/************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType - Level of all channels of that port.
* Description: Function to return the level of all channels of the specified DIO port.
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    if (PortId >= DIO_NUMBER_OF_PORTS)
    {
        /* Invalid PortId, handle error as needed */
/* #error Invalid Port ID */
    }

    volatile uint32* gpioDataReg = NULL_PTR;

    /* Determine the GPIO data register based on the PortId */
    switch (PortId)
    {
    case 0:
        gpioDataReg = &(GPIO_PORTA_DATA_R);
        break;

    case 1:
        gpioDataReg = &(GPIO_PORTB_DATA_R);
        break;

    case 2:
        gpioDataReg = &(GPIO_PORTC_DATA_R);
        break;

    case 3:
        gpioDataReg = &(GPIO_PORTD_DATA_R);
        break;

    case 4:
        gpioDataReg = &(GPIO_PORTE_DATA_R);
        break;

    case 5:
        gpioDataReg = &(GPIO_PORTF_DATA_R);
        break;

    default:
        break;
    }

    /* Read the value of the specified port */
    return (uint8)*gpioDataReg;
}

/************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set a value of the port.
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    if (PortId >= DIO_NUMBER_OF_PORTS)
    {
        /* Invalid PortId, handle error as needed */
        /* #error Invalid Port ID */
    }

    volatile uint32* gpioDataReg = NULL_PTR;

    /* Determine the GPIO data register based on the PortId */
    switch (PortId)
    {
    case 0:
        gpioDataReg = &(GPIO_PORTA_DATA_R);
        break;

    case 1:
        gpioDataReg = &(GPIO_PORTB_DATA_R);
        break;

    case 2:
        gpioDataReg = &(GPIO_PORTC_DATA_R);
        break;

    case 3:
        gpioDataReg = &(GPIO_PORTD_DATA_R);
        break;

    case 4:
        gpioDataReg = &(GPIO_PORTE_DATA_R);
        break;

    case 5:
        gpioDataReg = &(GPIO_PORTF_DATA_R);
        break;

    default:
        break;
    }

    /* Write the specified Level to the port */
    *gpioDataReg = Level;
}
