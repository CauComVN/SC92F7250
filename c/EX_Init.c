#include "H/Function_Init.H"

extern volatile unsigned int counter;

void EX_Init(void);

void EX_Init(void)
{	
	P2CON = 0x7C;  //中断IO口设置为高阻输入
	P2PH  |= 0x01;     //中断IO口设置为高阻带上拉
 
	//INT24中断
    //下降沿设置	
    INT2F = 0X10 ;    //0000 xxxx  0关闭 1使能
    //上升沿设置	
	INT2R = 0X10 ;    //0000 xxxx  0关闭 1使能	
	
	//外部中断优先级设置
	IE  |= 0x01;	//0000 0x0x
	IE1 |= 0x08;	//0000 x000  INT2使能
	IP  |= 0X00;
	IP1 |= 0X00;
	EA = 1;
}

/*****************************************************
*函数名称：void EX0/2() interrupt	0/10
*函数功能：外部中断服务函数
*入口参数：void
*出口参数：void
*****************************************************/

void EX2() interrupt	10
{
	counter = 0;
}
