#define F_CPU 16000000

#include <avr/io.h>
#include <stdbool.h>
#include <interrupt.h>


#define PRESCALER 1024
#define TOP 65535

#define MS800 (F_CPU/PRESCALER) * 800 / 1000
#define MS200 (F_CPU/PRESCALER) * 200 / 1000

ISR(TIMER1_OVF_vect) 
{
	//if(state == 1)
	//{
	//	PORTB = 0 << PB7;
	//	TCNT1 = TOP - MS800;
	//	state = 0;
	//}
	//else if(state == 0)
	//{
	//	PORTB = 1 << PB7;
	//	TCNT1 = TOP - MS200 ;
	//	state = 1;
	//}
	PORTB ^= 1 << PB7;
	TCNT1 = TOP - MS800;
}




int main(void)
{
	bool state = 1;

	DDRB = 0xFF;
	PORTB = 1 << PB7;
	
	TCCR1A = 0;
	
	// Prescaler 1024
	TCCR1B |= (1 << CS12) | (1 << CS10);
	
	TCNT1 = TOP - MS800;
	
	TIMSK1 |= (1 << TOIE1);
	
	sei();
	
	while(1)
	{
		;;
	}
	
}
