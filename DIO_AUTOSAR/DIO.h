/*******************************************************************************
 *                                                                             *
 * [MODULE]:      DIO                                                          *
 *                                                                             *
 * [FILE NAME]:   DIO.h                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        07/10/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for DIO driver                                   *
 *                                                                             *
 *******************************************************************************/

#ifndef DIO_H
#define DIO_H

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define DIO_NUMBER_OF_CHANNELS     48
#define DIO_NUMBER_OF_PORTS        6
#define DIO_NUMBER_OF_PINS_IN_PORT 8

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);



#endif /* DIO_H */
