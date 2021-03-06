#ifndef MAIN_C
#define MAIN_C
// Global includes
#include <htc.h>

// Local includes
//#include "c:/tc/devdelay.c"
#include<delays.h>
#include "c:/tc/usb.h"
#include "c:/tc/HardwareProfile.h"
#include "c:/tc/usb_function_hid.h"
#include "c:/tc/genericHID.h"

 //PIC 18F4550 fuse configuration:
// Config word 1 (Oscillator configuration)
 //20Mhz crystal input scaled to 48Mhz and configured for USB operation
__CONFIG(1, USBPLL & IESODIS & FCMDIS & XTPLL & CPUDIV1 & PLLDIV5);
// Config word 2
__CONFIG(2, VREGEN & PWRTDIS & BOREN & BORV20 & WDTDIS & WDTPS32K);
// Config word 3
__CONFIG(3, PBDIGITAL & LPT1DIS & MCLREN);
// Config word 4
__CONFIG(4, XINSTDIS & STVREN & LVPDIS & ICPORTDIS & DEBUGDIS);
// Config word 5, 6 and 7 (protection configuration)
__CONFIG(5, UNPROTECT);
__CONFIG(6, UNPROTECT);
__CONFIG(7, UNPROTECT);

// local prototypes
int aa;

void ProcessIO(void);
int index=0;
char gelen_veri[8];char uyan[]="01010101";
int bolum=0;
int a=0;
void uyandir()
{
	for(int a=0;a<8;a++)
	{PORTDbits.RD0=uyan[a]-48;
		 _delay( 10000 );
 _delay( 10000 );
_delay( 7450 );
 
		
	}
	
PORTDbits.RD0=0;
	 _delay( 10000 );
 _delay( 10000 );
_delay( 7450 );
	
	
	}
	char senk[]="00000000";
	char senk1[]="11111111";

	
	
	
	int ar=0;
	int index;

	
	
	kodla_gonder(int sayi)

{ index = 0 ;
	while( index != 8 )
 {
     gelen_veri[ 7 - index ] = sayi % 2;
    bolum=sayi/2;
    sayi=bolum;
     index++;
 }

 
 PORTDbits.RD0 = 1;
 _delay( 10000 );
 _delay( 10000 );
_delay( 4450 );


 
 
 
 PORTDbits.RD0 = 0;
 
 _delay( 10000 );
 _delay( 10000 );
_delay( 4450 );
 
 for( aa = 0 ; aa < 8 ; aa++ )
 {
	 PORTDbits.RD0 = gelen_veri[aa];
	_delay( 10000 );
 _delay( 10000 );
_delay( 1187 );
	 PORTDbits.RD0 = ~PORTDbits.RD0; 
	_delay( 10000 );
 _delay( 10000 );
_delay( 1187 );
	 
 }
 

 
 
 
 
 
 
  




 PORTDbits.RD0 = 0;
 
 _delay( 250 -1 );
 _delay( 250 -1 );
_delay( 250 -1 );
 
	_delay( 250 -1);
}

int sayi=0;
// Main function
void main(void)
{
//	ADCON1=0x06;
//PORTA=0x01;
	 
	 TRISB=0b11100000;
	 PORTB=0;
	 
	TRISC = 0b00000000;
	TRISD = 0b00000000;
	TRISE = 0b00000000;

PORTC=0;
PORTD=0;
	PORTE=0;
	USBOutHandle = 0;
USBInHandle = 0;
		USBDeviceInit();

	


for(int jkl=0;jkl<64;jkl++){

ToSendDataBuffer[jkl]=0;

ReceivedDataBuffer[jkl]=0;
}
ToSendDataBuffer[1]='S';
ToSendDataBuffer[2]='a';
ToSendDataBuffer[3]='i';
ToSendDataBuffer[4]='m';
int say=0;
	 while (1)
    
   {
	   
	   USBDeviceTasks();
if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1))continue;

if(!HIDRxHandleBusy(USBOutHandle))
    {  
switch(ReceivedDataBuffer[0])
{
case '1':
//if(RB0==0)RB0=1;
//seri_porta_veri_gonder('1');
break;

case 'l':
uyandir();
uyandir();
uyandir();

kodla_gonder( 22 );

 break;


case '2':
//PORTBbits.RB1=1;
//seri_porta_veri_gonder('2');
uyandir();
		uyandir();
uyandir();

kodla_gonder('2');
break;
case '3':
//PORTBbits.RB2=1;
//seri_porta_veri_gonder('3');

break;

case '4':
//PORTBbits.RB3=1;
uyandir();
		uyandir();
uyandir();

kodla_gonder('4');
break;
case '5':
//PORTBbits.RB4=1;
//seri_porta_veri_gonder('5');
uyandir();
		uyandir();
uyandir();

kodla_gonder('5');
break;
case '6':
PORTBbits.RB5=1;
break;
case '7':
//seri_porta_veri_gonder('7');
uyandir();
		uyandir();
uyandir();

kodla_gonder('7');
break;
case '8':
PORTBbits.RB7=1;
break;
case 'a':
PORTBbits.RB0=0;
break;
case 'b':
	uyandir();
		uyandir();
uyandir();

kodla_gonder('b');
break;
case 'c':
PORTBbits.RB2=0;
break;
case 'd':
	uyandir();
		uyandir();
uyandir();

kodla_gonder('d');
break;
case 'e':
	uyandir();
		uyandir();
uyandir();

kodla_gonder('e');
break;
case 'f':
PORTBbits.RB5=0;
break;
case 'g':
	uyandir();
		uyandir();
uyandir();

kodla_gonder('g');
break;
case 'h':
PORTBbits.RB7=0;
break;





default:
ToSendDataBuffer[0]='G';
ToSendDataBuffer[1]='e';
ToSendDataBuffer[2]='c';
ToSendDataBuffer[3]='e';
ToSendDataBuffer[4]='r';
ToSendDataBuffer[5]='l';
ToSendDataBuffer[6]='i';
ToSendDataBuffer[7]=' ';
ToSendDataBuffer[8]='K';
ToSendDataBuffer[9]='o';
ToSendDataBuffer[10]='m';
ToSendDataBuffer[11]='u';
ToSendDataBuffer[12]='t';
ToSendDataBuffer[13]=' ';
ToSendDataBuffer[14]='D';
ToSendDataBuffer[15]='e';
ToSendDataBuffer[16]='g';
ToSendDataBuffer[17]='i';
ToSendDataBuffer[18]='l';
ToSendDataBuffer[19]='.';
ToSendDataBuffer[20]='.';
ToSendDataBuffer[21]='.';
if(!HIDTxHandleBusy(USBInHandle))
USBInHandle = HIDTxPacket(HID_EP,ToSendDataBuffer,64);

break;



}


USBOutHandle=HIDRxPacket(HID_EP,ReceivedDataBuffer,64);



}
/*
	if(RB7==1)
	{uyandir();
		uyandir();
		uyandir();
		senkron();
		kodla_gonder('S');
		kodla_gonder('a');
		kodla_gonder('i');
		kodla_gonder('m');
		kodla_gonder(' ');
		kodla_gonder('S');
		kodla_gonder('U');
		kodla_gonder('N');
		kodla_gonder('E');
		kodla_gonder('L');
		kodla_gonder('!');
		kodla_gonder(22);
	DelayMs(500);
		
		}*/
	   /*
	   	if(RB6==1)
	{uyandir();
		uyandir();
		uyandir();
		senkron();
		
		kodla_gonder('D');
		kodla_gonder('e');
		kodla_gonder('n');
		kodla_gonder('e');
		kodla_gonder('m');
		kodla_gonder('e');
		kodla_gonder(' ');
		kodla_gonder('D');
		kodla_gonder('e');
		kodla_gonder('n');
		kodla_gonder('e');
		kodla_gonder('m');
		kodla_gonder('e');
		kodla_gonder(' ');
	kodla_gonder(33);
		DelayMs(500);
		
		}
	   
	   */
   }
	
	
	}

#endif
