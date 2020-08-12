#include "H/Function_Init.H" 

void Uart0_Init(void);
bit UartSendFlag = 0; //�����жϱ�־λ
bit UartReceiveFlag = 0; //�����жϱ�־λ

/*****************************************************
*�������ƣ�void Uart0_Init(void)
*�������ܣ�Uart0�жϳ�ʼ��
*��ڲ�����void
*���ڲ�����void
*****************************************************/
void Uart0_Init(void)    //ѡ��Timer1��Ϊ�������źŷ�����
{
	P1CON &= 0XF3;
	P1PH |= 0X0C;	 //TX/RXΪ����������
	SCON = 0X50;     //��ʽ1�������������
	PCON |= 0X80; 
	T2CON = 0x00;    //ʹ�ö�ʱ��1��UARTʱ��
	TMOD = 0X20;     //��ʱ��1  8λ�Զ�����
	TMCON = 0X02;    //��ʱ��1   Fsys��
	TL1 = 217;		
	TH1 = 217;		 //UART ������24M�����=38400��
	TR1 = 1;		 //����Timer0
	EUART = 1;	     //����UART�ж�
	EA = 1;		     //�����ж�
}

/*****************************************************
*�������ƣ�void UartInt(void) interrupt 4
*�������ܣ�Uart0�жϷ�����
*��ڲ�����void
*���ڲ�����void
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
