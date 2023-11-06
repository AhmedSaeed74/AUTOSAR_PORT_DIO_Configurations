/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   Utils.h                                                      *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [Version]:     1.0.0                                                        *
 *                                                                             *
 * [DATE]:        07/10/2023                                                   *
 *                                                                             *
 * [DESCRIPTION]: header file for the standard types                           *
 *                                                                             *
 *******************************************************************************/

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg,bit)   ((reg) |= (1<<bit))
#define CLEAR_BIT(reg,bit)   (reg&= ~(1<<bit))
#define TOGGLE_BIT(reg,bit)   (reg ^= (1<<bit))
#define READ_BIT(reg,bit)   ((reg >> bit)&1)
#define WRITE_BIT(reg,bit,val) ((reg &= (~(1<<bit))) | (val << bit))

#define READ_ALL_REGISTER_PINS(reg) ((reg) & 0xFFFFFFFF)



#endif /* UTILS_H_ */
