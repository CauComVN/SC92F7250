#include "H/Function_Init.H"
/*****************************************************
*函数名称：void IO_Init(void)
*函数功能：IO初始化
*入口参数：void
*出口参数：void
*****************************************************/
void IO_Init(void)
{
	P2CON = 0x7E;  //设置P2为带上拉输入IO
	P2PH  = 0x01;
	
	P1CON |= 0x08;  //设置P2为带上拉输入IO
	P1PH  &= 0xF7;
	SC92F7250_NIO_Init(); //未引出IO口配置
	
}