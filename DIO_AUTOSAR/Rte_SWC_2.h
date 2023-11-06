#ifndef RTE_SWC_2_H_
#define RTE_SWC_2_H_


#include "Rte.h"


extern void set_Pin(LED_Channel Channel,LED_State Level);


#define    Rte_Call_CS_RPort_2_set_LED(Channel,Level)     (set_Pin(Channel,Level))
#define    Rte_Read_SR_RPort_SR_Button_State(data)     (Rte_Read_SWC_2_SR_RPort_SR_Button_State(data))


#endif
