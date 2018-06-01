#ifndef servomotor_H
#define servomotor_H

void servo()
{
 int i,n; //declaration of variables n and i.
    n=0 ;  // initialize n to 0.
    while(n<3)  //enter and execute the loop if n is lesser than 3.
	{
	    for(i=0;i<=75;i++) //one half of one turn takes lesser time if i<=higher value. if i <=15, movement is slow.
        
		{
		    write(portc,0,h);  //values to control one half of one turn.
		    _delay_us(1500);
		    write(portc,0,l);
		    _delay_us(18500);
		}
	    _delay_us(2500);
		
		for(i=0;i<=75;i++)
		{ 
		    write(portc,0,h);  //values to control the other half of one turn.
		    _delay_us(1000);
		    write(portc,0,l);
		    _delay_us(19000);
		}
	    _delay_us(2500);   
    n++ ;  //increment n value after one iteration.
	}
}

#endif


