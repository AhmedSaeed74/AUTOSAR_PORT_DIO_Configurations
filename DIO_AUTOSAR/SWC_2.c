#include "Rte_SWC_2.h"


#define BCH 40
#define LCH 41

/*
*Runnable:SWC_2_Runnable_1
*Event Type:
*DATA ACCESS:
* DATA READ ACCESS:   SR_Button_State    Rte_Read_SR_RPort_SR_Button_State()
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_CS_RPort_2_set_LED(LED_Channel Channel,LED_State Level)
*/
void SWC_2_Runnable_1(void)
{
    Button B1;
    B1.Channel = BCH;

    Rte_Read_SR_RPort_SR_Button_State(&B1.State);
    Rte_Call_CS_RPort_2_set_LED(LCH, !B1.State);

}


