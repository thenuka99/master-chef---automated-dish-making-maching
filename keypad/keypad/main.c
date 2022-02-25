#ifndef F_CPU

#define F_CPU 16000000UL // clock speed is 16MHz

#endif

#include <avr/io.h>     // AVR header
#include <util/delay.h> // delay header
#include "lcd.h"
#include "keypad header.h"
#define KEY_PRT PORTA
#define KEY_DDR DDRA
#define KEY_PIN PINA
int i = 0, j = 0, no = 0;
int timer_r;
char curryNum();
char personNum();
int currynumber = 0, personnumber = 0;
void PLAYNOTE();

int main(void)
{
    
	DDRC = 0xFF;
	LCD_Set();

	LCD_Write_String("     WELCOME     ");
	_delay_ms(1000);

	//...............................................................................................................................................................................
	do
	{
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("    ADD CURRY");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     NUMBER");

		curryNum();
		currynumber = no;
		_delay_ms(1000);
		LCD_cmd(0x01); // clear screen
		LCD_Write_String(" CONFIRM CURRY ");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     NUMBER");
		_delay_ms(1000);
		do
		{
			LCD_cmd(0x01); // clear screen
			LCD_Write_String("ENTER + RESELECT");
			LCD_cmd(0xC0); // move cursor to the start of 2nd line
			LCD_Write_String("ENTER x CONFIRM");
			char accept = keyfind();
			switch (accept)
			{
				case ('*'):
				i = 1;
				j = 1;
				//...............................................................................................................................................................................
				do
				{
					LCD_cmd(0x01); // clear screen
					LCD_Write_String("   ADD NUMBER");
					LCD_cmd(0xC0); // move cursor to the start of 2nd line
					LCD_Write_String("   OF PERSONS");

					personNum();
					personnumber = no;
					_delay_ms(1000);
					LCD_cmd(0x01); // clear screen
					LCD_Write_String(" CONFIRM NUMBER");
					LCD_cmd(0xC0); // move cursor to the start of 2nd line
					LCD_Write_String("   OF PERSONS");
					_delay_ms(1000);
					do
					{
						LCD_cmd(0x01); // clear screen
						LCD_Write_String("ENTER + RESELECT");
						LCD_cmd(0xC0); // move cursor to the start of 2nd line
						LCD_Write_String("ENTER x CONFIRM");
						char accept = keyfind();
						switch (accept)
						{
							case ('*'):
							i = 1;
							j = 1;
							LCD_cmd(0x01); // clear screen
							LCD_Write_String("STARTING........");
							LCD_cmd(0xC0); // move cursor to the start of 2nd line
							_delay_ms(1000);
							LCD_Write_String("HAPPY MEAL!");
							break;
							case ('+'):
							i = 1;
							j = 0;
							break;
							default:
							i = 0;
						}

					} while (i == 0);

				} while (j == 0);
				//...........................................................................................................................................................................
				break;
				case ('+'):
				i = 1;
				j = 0;
				break;
				default:
				i = 0;
			}

		} while (i == 0);

	} while (j == 0);

	switch (currynumber)
	{
		case 1:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x11;
			break;
			case 2:
			PORTC = 0x12;
			break;
			case 3:
			PORTC = 0x13;
			break;
			case 4:
			PORTC = 0x14;
			break;
			case 5:
			PORTC = 0x15;
			break;
			case 6:
			PORTC = 0x16;
			break;
			case 7:
			PORTC = 0x17;
			break;
			case 8:
			PORTC = 0x18;
			break;
			case 9:
			PORTC = 0x19;
			break;
		}
		break;
		case 2:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x21;
			break;
			case 2:
			PORTC = 0x22;
			break;
			case 3:
			PORTC = 0x23;
			break;
			case 4:
			PORTC = 0x24;
			break;
			case 5:
			PORTC = 0x25;
			break;
			case 6:
			PORTC = 0x26;
			break;
			case 7:
			PORTC = 0x27;
			break;
			case 8:
			PORTC = 0x28;
			break;
			case 9:
			PORTC = 0x29;
			break;
		}
		break;
		case 3:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x31;
			break;
			case 2:
			PORTC = 0x32;
			break;
			case 3:
			PORTC = 0x33;
			break;
			case 4:
			PORTC = 0x34;
			break;
			case 5:
			PORTC = 0x35;
			break;
			case 6:
			PORTC = 0x36;
			break;
			case 7:
			PORTC = 0x37;
			break;
			case 8:
			PORTC = 0x38;
			break;
			case 9:
			PORTC = 0x39;
			break;
		}
		break;
		case 4:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x41;
			break;
			case 2:
			PORTC = 0x42;
			break;
			case 3:
			PORTC = 0x43;
			break;
			case 4:
			PORTC = 0x44;
			break;
			case 5:
			PORTC = 0x45;
			break;
			case 6:
			PORTC = 0x46;
			break;
			case 7:
			PORTC = 0x47;
			break;
			case 8:
			PORTC = 0x48;
			break;
			case 9:
			PORTC = 0x49;
			break;
		}
		break;
		case 5:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x51;
			break;
			case 2:
			PORTC = 0x52;
			break;
			case 3:
			PORTC = 0x53;
			break;
			case 4:
			PORTC = 0x54;
			break;
			case 5:
			PORTC = 0x55;
			break;
			case 6:
			PORTC = 0x56;
			break;
			case 7:
			PORTC = 0x57;
			break;
			case 8:
			PORTC = 0x58;
			break;
			case 9:
			PORTC = 0x59;
			break;
		}
		break;
		case 6:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x61;
			break;
			case 2:
			PORTC = 0x62;
			break;
			case 3:
			PORTC = 0x63;
			break;
			case 4:
			PORTC = 0x64;
			break;
			case 5:
			PORTC = 0x65;
			break;
			case 6:
			PORTC = 0x66;
			break;
			case 7:
			PORTC = 0x67;
			break;
			case 8:
			PORTC = 0x68;
			break;
			case 9:
			PORTC = 0x69;
			break;
		}
		break;
		case 7:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x71;
			break;
			case 2:
			PORTC = 0x72;
			break;
			case 3:
			PORTC = 0x73;
			break;
			case 4:
			PORTC = 0x74;
			break;
			case 5:
			PORTC = 0x75;
			break;
			case 6:
			PORTC = 0x76;
			break;
			case 7:
			PORTC = 0x77;
			break;
			case 8:
			PORTC = 0x78;
			break;
			case 9:
			PORTC = 0x79;
			break;
		}
		break;
		case 8:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x81;
			break;
			case 2:
			PORTC = 0x82;
			break;
			case 3:
			PORTC = 0x83;
			break;
			case 4:
			PORTC = 0x84;
			break;
			case 5:
			PORTC = 0x85;
			break;
			case 6:
			PORTC = 0x86;
			break;
			case 7:
			PORTC = 0x87;
			break;
			case 8:
			PORTC = 0x88;
			break;
			case 9:
			PORTC = 0x89;
			break;
		}
		break;
		case 9:
		switch (personnumber)
		{
			case 1:
			PORTC = 0x91;
			break;
			case 2:
			PORTC = 0x92;
			break;
			case 3:
			PORTC = 0x93;
			break;
			case 4:
			PORTC = 0x94;
			break;
			case 5:
			PORTC = 0x95;
			break;
			case 6:
			PORTC = 0x96;
			break;
			case 7:
			PORTC = 0x97;
			break;
			case 8:
			PORTC = 0x98;
			break;
			case 9:
			PORTC = 0x99;
			break;
		}
		break;
	}

	//Countdown coding --------------------------------------------------------

	_delay_ms(1000);
	LCD_cmd(0xC0); // move cursor to the start of 2nd line
	LCD_Write_String("HAVE A NICE DAY!");
	_delay_ms(1000);
	LCD_cmd(0x01); // clear screen

int Time[9][9]={{10,11,12,13,14,15,16,17,18},{10,14,12,13,14,15,16,17,18},{10,11,12,13,14,15,16,17,18},{10,11,12,13,14,15,16,17,18},{10,11,12,13,14,15,16,17,18},{10,11,12,13,14,15,16,17,18},{10,11,12,13,14,15,16,17,18},{10,11,12,13,14,15,16,17,18},
{10,11,12,13,14,15,16,17,18},};

	timer_r=Time[personnumber-1][currynumber-1];

	LCD_Write_String("PREPARE MEAL IN:");
	_delay_ms(1000);

	for (i = timer_r; i >= 0; i--)
	{
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		char time[5];
		itoa(i, time, 10);
		LCD_Write_String(time);
		LCD_Write_String("\n MIN");
		_delay_ms(24000);
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
	}
	
	LCD_cmd(0x01); // clear screen
	LCD_Write_String("YOUR MEAL IS");
	LCD_cmd(0x01); // clear screen
	LCD_Write_String("   READY  ");
	_delay_ms(1000);
	LCD_cmd(0x01); // clear screen
	LCD_cmd(0xC0); // move cursor to the start of 2nd line
	LCD_Write_String("   THANK YOU !");
	_delay_ms(1000);

	return 0;
}

char curryNum()
{
	char test = keyfind();
	switch (test)
	{
		case ('1'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("     POTATO");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 1;
		break;
		case ('2'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("      DHAL");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 2;
		break;
		case ('3'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("     CARROT");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 3;
		break;
		case ('9'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("      BEETROOT");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 9;
		break;
		case ('4'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("     PUMPKIN");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 4;
		break;
		case ('5'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("     BEANS");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 5;
		break;
		case ('6'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("	OKRA");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 6;
		break;
		case ('7'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("	BRINJAL");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 7;
		break;
		case ('8'):
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("   CABBAGE");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     CURRY");
		no = 8;
		break;
		default:
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("   PLEASE ADD");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     NUMBER");
		_delay_ms(1000);
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("   ADD CURRY");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     NUMBER ");
		curryNum();
	}
}
char personNum()
{
	char test = keyfind();
	switch (test)
	{
		case ('1'):
		no = 1;
		break;
		case ('2'):
		no = 2;
		break;
		case ('3'):
		no = 3;
		break;
		case ('9'):
		no = 9;
		break;
		case ('4'):
		no = 4;
		break;
		case ('5'):
		no = 5;
		break;
		case ('6'):
		no = 6;
		break;
		case ('7'):
		no = 7;
		break;
		case ('8'):
		no = 8;
		break;
		default:
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("   PLEASE ADD");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("     NUMBER");
		_delay_ms(1000);
		LCD_cmd(0x01); // clear screen
		LCD_Write_String("   ADD NUMBER");
		LCD_cmd(0xC0); // move cursor to the start of 2nd line
		LCD_Write_String("   OF PERSONS");

		personNum();
	}
}

// Speaker coding ----------------------------------------------------------
void Time()
{
	switch (personnumber)
	{
		
	case 1:
	timer_r = 10;
	break;
	case 2:
	LCD_cmd(0x01); // clear screen
	timer_r = 11;
	break;
	case 3:
	LCD_cmd(0x01); // clear screen
	timer_r = 12;
	break;
	case 4:
	LCD_cmd(0x01); // clear screen
	timer_r = 13;
	break;
	case 5:
	LCD_cmd(0x01); // clear screen
	timer_r = 14;
	break;
	case 6:
	LCD_cmd(0x01); // clear screen
	timer_r = 15;
	break;
	case 7:
	LCD_cmd(0x01); // clear screen
	timer_r = 16;
	break;
	case 8:
	LCD_cmd(0x01); // clear screen
	timer_r = 17;
	break;
	case 9:
	LCD_cmd(0x01); // clear screen
	timer_r = 18;
	break;}
}
void PLAYNOTE()
{
	long int i, cycles = 3;

	PORTD = 0xFF;

	for (i = 0; i < 100; i++)
	{
		for (i = 0; i < cycles; i++)
		{
			PORTD = 0x04;
			_delay_ms(100);
			PORTD = 0x00;
			_delay_ms(100);
			PORTD = 0x04;
		}
		_delay_ms(200);
		for (i = 0; i < cycles; i++)
		{
			PORTD = 0x04;
			_delay_ms(100);
			PORTD = 0x00;
			_delay_ms(100);
			PORTD = 0x04;
		}
		_delay_ms(200);
		for (i = 0; i < cycles; i++)
		{
			PORTD = 0x04;
			_delay_ms(100);
			PORTD = 0x00;
			_delay_ms(200);
			PORTD = 0x04;
		}
	}
}