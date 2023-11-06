#ifndef RTE_SWC_1_H_
#define RTE_SWC_1_H_


#include "Rte.h"


extern void get_Pin(Button_Channel Channel,Button_State* Level);


#define    Rte_Write_SR_SPort_SR_Button_State(data)     (Rte_Write_SWC_1_SR_SPort_SR_Button_State(data))
#define    Rte_Call_CS_RPort_1_get_Button(Channel,Level)     (get_Pin(Channel,Level))



#endif
