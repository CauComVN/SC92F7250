#include "H/Function_Init.H"

void ADC_Init(uint Channel);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;

/*****************************************************
*�������ƣ�void ADC_Test(void)
*�������ܣ�ADC����
*��ڲ�����void
*���ڲ�����void
*****************************************************/
float ADC_BAT(void)
{
	float btValue = 0;
	ADC_Init(7);

	ADCCON |= 0X40;   //��ʼADCת��
	while(!AdcFlag);	         		 //�ȴ� ADCת�����;
	AdcFlag = 0;
	ADCValue = (ADCVH<<4)+(ADCVL>>4);
	btValue = ADCValue*5.0/4096;
	return  btValue;
}


float ADC_RESP(void)
{
	float reqValue = 0;
	ADC_Init(1);

	ADCCON |= 0X40;   //��ʼADCת��
	while(!AdcFlag);	         		 //�ȴ� ADCת�����;
	AdcFlag = 0;
	ADCValue = (ADCVH<<4)+(ADCVL>>4);
	reqValue = ADCValue*5.0/4096;
	return  reqValue;
}

/*****************************************************
*�������ƣ�void ADC_Init(uint Channel)
*�������ܣ�ADC��ʼ��
*��ڲ�����Channel
*���ڲ�����void
*****************************************************/
void ADC_Init(uint Channel)
{
	ADCCON = 0X80|Channel;		//����ADC��ADC����Ƶ��Ϊ2M ,ѡ��ChannelλADC������
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //����Channel��Ϊ������
	}
	else
	{
		ADCCFG1 = 1<<(Channel-8);   //����Channel��Ϊ������
	}
	IE |= 0X40;        //����ADC�ж�
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X10);  //���жϱ�־λ
	AdcFlag = 1;
}