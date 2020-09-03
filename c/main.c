#include "H/SC92F725x_C.H"
#include "H/Function_Init.H"

unsigned int times = 0;
volatile unsigned int counter = 0; 

void delay_s(unsigned int time)
{
	WDTCON |= 0x10;
    times = time;
    while(times > 0)
    {
        WDTCON |= 0x10;
    }
}

char putchar(char c)
{
    SBUF =  c ;
    while(!TI);
    TI = 0;
    EUART = 1;
    return c;
}

void main(void)
{
    IO_Init();
    BTM_Init();
//    Uart0_Init();
//	WDT_Init();
	EX_Init();
	P13 = 0;
    while(1)
    {
		WDTCON |= 0x10;		    //Çå¿´ÃÅ¹·
        if (0 == P20 && ADC_RESP() < 1.0)
        {
            delay_s(1);
			if(0 == P20)
            {
				if(ADC_BAT()>3.5)
				{
//			printf("bt:%f\n",ADC_Test());
					P13 = 1;
					P26 = 1;
					delay_s(3*4);
					P26 = 0;
				}
			}
        }
        else if (1 == P20 && ADC_RESP() > 1.0)
        {
            delay_s(1);
            if(1 == P20)
            {
                P26 = 1;
                delay_s(4*4);
                P26 = 0;
//				delay_s(6*4);
				P13 = 1;
            }
        }	
		if(ADC_RESP() > 1.0) 
		{
			P13 = 1;
		}
		else
		{
			P13 = 0;
		}
		if(counter > 200)
		{
			PCON |= 0x02;
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
		}
//		delay_s(4);	
    }
}
