#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>     //standard AVR library
#include <util/delay.h> // delay library
#include <avr/interrupt.h>
#include <stdlib.h>

int main(void) //main starts
{
	DDRD = 0x0F;
	DDRA = 0x00;
	DDRC = 0xFF;
	DDRB = 0xFF;
	
	
	//getting curry number and number of person as bitwise
	int curryNum = 0, personNum = 0;
	while (personNum == 0)
	{
		if (PINA & (1 << 0))
		{
			if (PINA & (1 << 1))
			{
				if (PINA & (1 << 2))
				{
					personNum = 7;
				}
				else
				{
					personNum = 3;
				}
			}
			else if (PINA & (1 << 2))
			{
				personNum = 5;
			}
			else if (PINA & (1 << 3))
			{
				personNum = 9;
			}
			else
			{
				personNum = 1;
			}
		}
		else if (PINA & (1 << 1))
		{
			if (PINA & (1 << 2))
			{
				personNum = 6;
			}
			else
			{
				personNum = 2;
			}
		}
		else if (PINA & (1 << 3))
		{
			personNum = 8;
		}
		else if (PINA & (1 << 2))
		{
			personNum = 4;
		}
	}
	while (curryNum == 0)
	{
		if (PINA & (1 << 4))
		{
			if (PINA & (1 << 5))
			{
				if (PINA & (1 << 6))
				{
					curryNum = 7;
				}
				else
				{
					curryNum = 3;
				}
			}
			else if (PINA & (1 << 6))
			{
				curryNum = 5;
			}
			else if (PINA & (1 << 7))
			{
				curryNum = 9;
			}
			else
			{
				curryNum = 1;
			}
		}
		else if (PINA & (1 << 5))
		{
			if (PINA & (1 << 6))
			{
				curryNum = 6;
			}
			else
			{
				curryNum = 2;
			}
		}
		else if (PINA & (1 << 7))
		{
			curryNum = 8;
		}
		else if (PINA & (1 << 6))
		{
			curryNum = 4;
		}
	}
	

	int period = 100; /* Set period in between two steps */
    PORTC =0x01;
	switch (curryNum)
	{
		case 1:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 2:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 3:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 4:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 5:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 6:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 7:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 8:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
		case 9:
		switch (personNum)
		{
			case 1:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 2:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 3:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 4:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 5:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 6:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 7:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 8:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
			case 9:
			{
				/* Rotate Stepper Motor clockwise with Half step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x08;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
					PORTD = 0x04;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x02;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x01;
					_delay_ms(period);
				}
				PORTD = 0x09; /* Last step to initial position */
				_delay_ms(period);
				_delay_ms(1000);

				/* Rotate Stepper Motor Anticlockwise with Full step sequence */
				for (int i = 0; i < 12; i++)
				{
					PORTD = 0x09;
					_delay_ms(period);
					PORTD = 0x03;
					_delay_ms(period);
					PORTD = 0x06;
					_delay_ms(period);
					PORTD = 0x0C;
					_delay_ms(period);
				}
				PORTD = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				break;
			}
		}
		break;
	}
}
