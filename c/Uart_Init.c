#include "H/Function_Init.H" 

void Uart0_Init(void);
bit UartSendFlag = 0; //发送中断标志位
bit UartReceiveFlag = 0; //接收中断标志位

/*****************************************************
*函数名称：void Uart0_Init(void)
*函数功能：Uart0中断初始化
*入口参数：void
*出口参数：void
*****************************************************/
void Uart0_Init(void)    //选择Timer1作为波特率信号发生器
{
	P1CON &= 0XF3;
	P1PH |= 0X0C;	 //TX/RX为带上拉输入
	SCON = 0X50;     //方式1，允许接收数据
	PCON |= 0X80; 
	T2CON = 0x00;    //使用定时器1作UART时钟
	TMOD = 0X20;     //定时器1  8位自动重载
	TMCON = 0X02;    //定时器1   Fsys；
	TL1 = 217;		
	TH1 = 217;		 //UART 波特率24M情况下=38400；
	TR1 = 1;		 //启动Timer0
	EUART = 1;	     //允许UART中断
	EA = 1;		     //开总中断
}

/*****************************************************
*函数名称：void UartInt(void) interrupt 4
*函数功能：Uart0中断服务函数
*入口参数：void
*出口参数：void
*****************************************************/
void UartInt(void) interrupt 4
{
	if(TI)
	{
		EUART = 0;
//	    Uart0SendFlag = 1;
	}
	if(RI)
	{
		RI=0;
//        Uart0ReceiveFlag = 1;
	}
}
