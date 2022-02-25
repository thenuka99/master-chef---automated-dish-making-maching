 #define F_CPU 8000000UL
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <util/delay.h>
 #include <string.h>
 #include <stdlib.h>

 #define  Trigger_pin0	PA0	/* Trigger pin  d_kiri*/
 #define  Trigger_pin1	PA1	/* Trigger pin  water*/
 #define  Trigger_pin2	PA2	/* Trigger pin  M_kiri*/
 double distancemeter(int currycase);
 int TimerOverflow = 0;
 long count;
 double distance;
 double addin(double volume,int currycase);

 ISR(TIMER1_OVF_vect)
 {
	 TimerOverflow++;	/* Increment Timer Overflow count */
 }

 int main(void)
 {
	 DDRB = 0xFF;
	 DDRC = 0x00;
	 int curryNum = 0, personNum = 0;
	 while (personNum == 0)
	 {
		 if (PINC & (1 << 0))
		 {
			 if (PINC  & (1 << 1))
			 {
				 if (PINC  & (1 << 2))
				 {
					 personNum = 7;
				 }
				 else
				 {
					 personNum = 3;
				 }
			 }
			 else if (PINC  & (1 << 2))
			 {
				 personNum = 5;
			 }
			 else if (PINC  & (1 << 3))
			 {
				 personNum = 9;
			 }
			 else
			 {
				 personNum = 1;
			 }
		 }
		 else if (PINC  & (1 << 1))
		 {
			 if (PINC  & (1 << 2))
			 {
				 personNum = 6;
			 }
			 else
			 {
				 personNum = 2;
			 }
		 }
		 else if (PINC  & (1 << 3))
		 {
			 personNum = 8;
		 }
		 else if (PINC  & (1 << 2))
		 {
			 personNum = 4;
		 }
	 }
	 while (curryNum == 0)
	 {
		 if (PINC  & (1 << 4))
		 {
			 if (PINC  & (1 << 5))
			 {
				 if (PINC  & (1 << 6))
				 {
					 curryNum = 7;
				 }
				 else
				 {
					 curryNum = 3;
				 }
			 }
			 else if (PINC  & (1 << 6))
			 {
				 curryNum = 5;
			 }
			 else if (PINC  & (1 << 7))
			 {
				 curryNum = 9;
			 }
			 else
			 {
				 curryNum = 1;
			 }
		 }
		 else if (PINC  & (1 << 5))
		 {
			 if (PINC  & (1 << 6))
			 {
				 curryNum = 6;
			 }
			 else
			 {
				 curryNum = 2;
			 }
		 }
		 else if (PINC  & (1 << 7))
		 {
			 curryNum = 8;
		 }
		 else if (PINC  & (1 << 6))
		 {
			 curryNum = 4;
		 }
	 }
	 
	 
	 PORTB = 0x40;

	 while(1)
	 {
		 
		 switch (curryNum)
		 {
			 case 1:
			 switch (personNum)
			 {
				 case 1:
				 {
					 addin(1,1);
					 _delay_ms(100);
					 addin(5,2);
					 _delay_ms(100);
					 addin(2,3);
					 _delay_ms(100);
					 break;
				 }
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 2:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 3:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 4:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 5:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 6:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 7:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 8:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
			 case 9:
			 switch (personNum)
			 {
				 case 1:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 2:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 3:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 4:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 5:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 6:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 7:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 8:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
				 case 9:
				 addin(1,1);
				 _delay_ms(100);
				 addin(5,2);
				 _delay_ms(100);
				 addin(2,3);
				 _delay_ms(100);
				 break;
			 }
			 break;
		 }
	 }
	 
	 
 }
 
 double distancemeter(int currycase){
	 
	 
	 
	 
	 switch (currycase)
	 {
		 case 1:
		 DDRA = 0x01;		/* Make trigger pin as output */
		 break;
		 
		 case 2:
		 DDRA = 0x02;		/* Make trigger pin as output */
		 break;
		 
		 case 3:
		 DDRA = 0x04;		/* Make trigger pin as output */
		 break;
	 }
	 
	 
	 PORTD = 0xFF;		/* Turn on Pull-up */
	 
	 sei();			/* Enable global interrupt */
	 TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	 TCCR1A = 0;		/* Set all bit to zero Normal operation */
	 
	 /* Give 10us trigger pulse on trig. pin to HC-SR04 */
	 switch (currycase)
	 {
		 case 1:
		 {
			 PORTA |= (1 << Trigger_pin0);
			 _delay_us(10);
			 PORTA &= (~(1 << Trigger_pin0));
			 break;
		 }
		 case 2:
		 {
			 PORTA |= (1 << Trigger_pin1);
			 _delay_us(10);
			 PORTA &= (~(1 << Trigger_pin1));
			 break;
		 }
		 case 3:
		 {
			 PORTA |= (1 << Trigger_pin2);
			 _delay_us(10);
			 PORTA &= (~(1 << Trigger_pin2));
			 break;
		 }
	 }
	 
	 TCNT1 = 0;	/* Clear Timer counter */
	 TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
	 TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	 TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

	 /*Calculate width of Echo by Input Capture (ICP) */
	 
	 while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	 TCNT1 = 0;	/* Clear Timer counter */
	 TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
	 TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	 TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	 TimerOverflow = 0;/* Clear Timer overflow count */

	 while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	 count = ICR1 + (65535 * TimerOverflow);	/* Take count */
	 /* 8MHz Timer freq, sound speed =343 m/s */
	 distance = (double)count / 466.47;
	 
	 _delay_ms(200);
	 return distance;

 }
 
 double addin(double volume,int currycase){
	 
	 
	 double constant = distancemeter(currycase);
	 switch (currycase)
	 {
		 case 1:
		 {
			 PORTB = 0x41;
			 _delay_ms(100);
			 PORTB = 0x40;
			 break;
		 }
		 case 2:
		 {
			 PORTB = 0x44;
			 _delay_ms(100);
			 PORTB = 0x40;
			 break;
		 }
		 case 3:
		 {
			 PORTB = 0x50;
			 _delay_ms(100);
			 PORTB = 0x40;
			 break;
		 }
	 }
	 double j=1;
	 while(j>0)
	 {
		 double x = distancemeter(currycase);
		 j = volume - x + constant;
	 }
	 switch (currycase)
	 {
		 case 1:
		 {
			 
			 PORTB = 0x42;
			 _delay_ms(100);
			 PORTB = 0x40;
			 break;
		 }
		 case 2:
		 {
			 PORTB = 0x48;
			 _delay_ms(100);
			 PORTB = 0x40;
			 break;
		 }
		 case 3:
		 {
			 PORTB = 0x60;
			 _delay_ms(100);
			 PORTB = 0x40;
			 break;
		 }
	 }
	 return 0;
 }

