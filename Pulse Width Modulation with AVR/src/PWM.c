#include <avr/io.h> // header files 
#include <util/delay.h>

void Initiate_PWM()
{
   /*
   TCCR2 - Timer Counter Control Register (TIMER2)
   -----------------------------------------------
   BITS DESCRIPTION
   

   NO:   NAME   DESCRIPTION
   --------------------------
   BIT 7 : FOC2   Force Output Compare [Not used in this example]
   BIT 6 : WGM20  Wave form generartion mode [SET to 1]
   BIT 5 : COM21  Compare Output Mode        [SET to 1]
   BIT 4 : COM20  Compare Output Mode        [SET to 0]

   BIT 3 : WGM21  Wave form generation mode [SET to 1]
   BIT 2 : CS22   Clock Select               [SET to 0]
   BIT 1 : CS21   Clock Select               [SET to 1]
   BIT 0 : CS20   Clock Select               [SET to 0]

   The above settings are for
   --------------------------

   Timer Clock = CPU Clock/8 (Pre-scaling by 8)
   Mode        = Fast PWM
   PWM Output  = Non Inverted

   */


   TCCR2|=(1<<WGM20)|(1<<WGM21)|(1<<COM21)|(1<<CS21);

   //Set OC2 PIN as output. It is  PD7 on ATmega16

   DDRD|=(1<<PD7);
}


//Function to set PWM duty cycle 
void SetPWM_DutyCycle(uint8_t duty_cycle)
{
   OCR2=duty_cycle;
}

//Delay in Milli-second
void Wait()
{
 _delay_ms(4);
}

void main()
{
   uint8_t bright=0;

   //Initialize PWM Channel 2
   Initiate_PWM();

   //Do this forever
   while(1)
   {
      //Now Loop with increasing brightness

      for(bright=0;bright<255;bright++)
      {
         //Now Set The Brighness using PWM

         SetPWM_DutyCycle(bright);

         //Now Wait For Some Time
         Wait();
      }

      //Now Loop with decreasing brightness

      for(bright=255;bright>0;bright--)
      {
         //Now Set The Brighness using PWM

         SetPWM_DutyCycle(bright);

         //Now Wait For Some Time
         Wait();
      }
   }
   }
