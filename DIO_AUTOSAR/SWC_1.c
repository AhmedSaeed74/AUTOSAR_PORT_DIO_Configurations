#include "Rte_SWC_1.h"



#define BCH 40
/*
*Runnable:SWC_1_Runnable_1
*Event Type:
*DATA ACCESS:
* DATA SEND POINT:  Rte_Write_SR_SPort_SR_Button_State(Button SR_Button_State)
*SYNCHRONOUS-SERVER-CALL-POINT:  Rte_Call_CS_RPort_1_get_Button(Button_Channel Channel,Button_State Level)
*/
void SWC_1_Runnable_1(void)
{
    uint8 Level = 0;
    Button B1;
    B1.Channel = BCH;
    Rte_Call_CS_RPort_1_get_Button(B1.Channel, &B1.State);
    Rte_Write_SR_SPort_SR_Button_State(&B1.State);

}


