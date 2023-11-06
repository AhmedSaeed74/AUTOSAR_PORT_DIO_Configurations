#ifndef RTE_TYPE_H_
#define RTE_TYPE_H_


#include "Std_Types.h"


typedef    uint8     Std_ReturnType;

#define    E_OK     (0u)

#define    E_NOT_OK     (1u)

#define    RTE_E_UNCONNECTED     (134u)



/*
#define NULL ((void*)0)
*/



/*
THIS IS IMPLEMENTED DATA TYPES OF TYPE => VALUE
*/
typedef    uint8     Button_State;
typedef    uint8     LED_State;
typedef    uint8     Button_Channel;
typedef    uint8     LED_Channel;

/*
THIS IS IMPLEMENTED DATA TYPES OF TYPE => ARRAY
*/


/*
THIS IS IMPLEMENTED DATA TYPES OF TYPE => STRUCT
*/
typedef struct {
     Button_Channel    Channel;
     Button_State    State;

}Button;


#endif
