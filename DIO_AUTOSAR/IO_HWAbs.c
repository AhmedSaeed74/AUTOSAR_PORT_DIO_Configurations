
#include "Rte_IO_HWAbs.h"
#include "DIO.h"
#include "Port.h"
#include "Rte.h"

/*
*Runnable:get_Pin
*Event Type:operation invoked event
*DATA ACCESS:
*/
void get_Pin(Button_Channel Channel,Button_State* Level)
{

    *Level = Dio_ReadChannel(Channel);
}



/*
*Runnable:set_Pin
*Event Type:operation invoked event
*DATA ACCESS:
*/
void set_Pin(LED_Channel Channel,LED_State Level)
{

    Dio_WriteChannel(Channel, Level);
}



/*
*Runnable:Init
*Event Type:init
*DATA ACCESS:
*/
void Init(void)
{

    Port_Init();



}


