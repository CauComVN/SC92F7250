#ifndef _Function_Init_H_
#define _Function_Init_H_

#include <stdio.h>
#include "SC92F725x_C.H"
#include "intrins.H"
#define uchar unsigned char
#define uint unsigned int

#define IapROM  0x00	  //0x00��ѡ��ROM������  0x02��ѡ��EEPROM������
#define IapEPPROM  0x02	  //0x00��ѡ��ROM������  0x02��ѡ��EEPROM������

extern void IO_Init(void);
extern void BTM_Init(void);
extern void Uart0_Init(void);
extern float ADC_BAT(void);
extern float ADC_RESP(void);


/*****************************************
˵����ѡ�����IC
*****************************************/
#define SC92F7252  0
#define SC92F7251  1
#define SC92F7250  2

#define IC_MODEL  SC92F7250

#endif