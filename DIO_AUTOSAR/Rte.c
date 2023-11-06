#include "Rte_Type.h"


Button SWC_1_SR_SPort_SR_Button_State;


Std_ReturnType Rte_Write_SWC_1_SR_SPort_SR_Button_State (Button* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;


   }

   else{
      SWC_1_SR_SPort_SR_Button_State = *data;

      return_value = E_OK;
   }
   return return_value;
}

Std_ReturnType Rte_Read_SWC_2_SR_RPort_SR_Button_State (Button* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      *data = SWC_1_SR_SPort_SR_Button_State;
      return_value = E_OK;
   }
   return return_value;
}



