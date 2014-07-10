//Author : SATEJ V KHANDEPARKAR
//UART PROGRAM FOR LPC 2148 

#include <lpc214x.h>  //includes all register definitions

#define Fosc     12000000
#define Fcclk    (Fosc * 5)
#define Fcco     (Fcclk * 4)
#define Fpclk    (Fcclk / 4 ) * 1

#define UART_BPS  9600  // Set the baud rate 

const unsigned char SEND_STRING[] = "UART TEST STRING \n";
const unsigned char SEND_STRING_NEW[] = "TEST PASSED \n";




void INIT_UART(void)   //initialise the UART
{
	unsigned int baud_16;
	U0LCR = 0X83;  //SET DLAB TO 1
	baud_16 = (Fpclk / 16 ) / UART_BPS ;
	U0DLM = baud_16 / 256;
	U0DLL = baud_16 % 256;
	U0LCR = 0X03; // LOCK THE DLAB BIT TO 0

}


// function to send data byte
void UART_SEND_DATA_BYTE(char DATA)
{
	U0THR = DATA;
	while ((U0LSR&0X40)==0);


}

//function to send string
void UART_SEND_STR(const unsigned char *str)
{
	while(1)
	{
		if (*str == '\0') break;
		{
			UART_SEND_DATA_BYTE(*str++);
		}
	
	
	}
	
}


int main(void)
{
	PINSEL0 = 0X00000005; //enalble UART0 RX and TX pins 
	PINSEL1 = 0X00000000;
	PINSEL2 = 0X00000000;
	
	INIT_UART();
	UART_SEND_STR(SEND_STRING);
	while((U0LSR&0X01)== 0 );
	UART_SEND_STR(SEND_STRING_NEW);
	
	
	while(1)
	{ 
	
	}
	
	return 0;

}






