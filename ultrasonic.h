#ifndef ULTRASONIC_H
#define ULTRASONIC_H

int ultra_dist()
{
unsigned long count; 
	  
      TCNT1=0; // CLEAR THE TIMER

		write(portd,0,h);
	    _delay_us(10);
	    write(portd,1,l);  //Trigger Pulse
		
		
		while( read(portd,1) == 0 ); //WAIT FOR WAVES TO BE SENT
		
		
		TCCR1B = 3; //START TIMER WITH CLK/64
		
		
		while( read(portd,0) == 1 ); //WAIT UNTILL ECHO HAS ARRIVED
		
		TCCR1B =0; //STOP THE TIMER
		
		count = TCNT1; //COPY TIMER VALUE
		
		count = count*64;
		count = count *330;		
		count = count *100;
		
		count = count/2;		
		count= count/12000000;

        return count;
}

#endif

