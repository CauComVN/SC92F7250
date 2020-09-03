#include "H/Function_Init.H"

extern volatile unsigned int counter;

void EX_Init(void);

void EX_Init(void)
{	
	P2CON = 0x7C;  //�ж�IO������Ϊ��������
	P2PH  |= 0x01;     //�ж�IO������Ϊ���������
 
	//INT24�ж�
    //�½�������	
    INT2F = 0X10 ;    //0000 xxxx  0�ر� 1ʹ��
    //����������	
	INT2R = 0X10 ;    //0000 xxxx  0�ر� 1ʹ��	
	
	//�ⲿ�ж����ȼ�����
	IE  |= 0x01;	//0000 0x0x
	IE1 |= 0x08;	//0000 x000  INT2ʹ��
	IP  |= 0X00;
	IP1 |= 0X00;
	EA = 1;
}

/*****************************************************
*�������ƣ�void EX0/2() interrupt	0/10
*�������ܣ��ⲿ�жϷ�����
*��ڲ�����void
*���ڲ�����void
*****************************************************/

void EX2() interrupt	10
{
	counter = 0;
}
