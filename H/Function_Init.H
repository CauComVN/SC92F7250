#ifndef _Function_Init_H_
#define _Function_Init_H_

#include <stdio.h>
#include "SC92F725x_C.H"
#include "intrins.H"
#define uchar unsigned char
#define uint unsigned int

#define IapROM  0x00	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作
#define IapEPPROM  0x02	  //0x00：选择ROM区操作  0x02：选择EEPROM区操作

extern void IO_Init(void);
extern void BTM_Init(void);
extern void Uart0_Init(void);
extern float ADC_BAT(void);
extern float ADC_RESP(void);
void EX_Init(void);


/*****************************************
说明：选择测试IC
*****************************************/
#define SC92F7252  0
#define SC92F7251  1
#define SC92F7250  2

#define IC_MODEL  SC92F7250

#endif