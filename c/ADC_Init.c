#include "H/Function_Init.H"

void ADC_Init(uint Channel);
unsigned int ADCValue = 0x0000;
bit AdcFlag = 0;

/*****************************************************
*函数名称：void ADC_Test(void)
*函数功能：ADC测试
*入口参数：void
*出口参数：void
*****************************************************/
float ADC_BAT(void)
{
	float btValue = 0;
	ADC_Init(7);

	ADCCON |= 0X40;   //开始ADC转换
	while(!AdcFlag);	         		 //等待 ADC转换完成;
	AdcFlag = 0;
	ADCValue = (ADCVH<<4)+(ADCVL>>4);
	btValue = ADCValue*5.0/4096;
	return  btValue;
}


float ADC_RESP(void)
{
	float reqValue = 0;
	ADC_Init(1);

	ADCCON |= 0X40;   //开始ADC转换
	while(!AdcFlag);	         		 //等待 ADC转换完成;
	AdcFlag = 0;
	ADCValue = (ADCVH<<4)+(ADCVL>>4);
	reqValue = ADCValue*5.0/4096;
	return  reqValue;
}

/*****************************************************
*函数名称：void ADC_Init(uint Channel)
*函数功能：ADC初始化
*入口参数：Channel
*出口参数：void
*****************************************************/
void ADC_Init(uint Channel)
{
	ADCCON = 0X80|Channel;		//开启ADC，ADC采样频率为2M ,选择Channel位ADC采样口
	if(Channel<8)
	{
		ADCCFG0 = 1<<Channel;   //设置Channel作为采样口
	}
	else
	{
		ADCCFG1 = 1<<(Channel-8);   //设置Channel作为采样口
	}
	IE |= 0X40;        //开启ADC中断
	EA = 1;
}


void ADC_Interrupt(void) interrupt 6
{
	ADCCON &= ~(0X10);  //清中断标志位
	AdcFlag = 1;
}