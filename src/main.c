/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: seif gendy
 */

#include "../../LED_ANIMATION/include/BIT_MATH.h"
#include "../../LED_ANIMATION/include/GPIO_interface.h"
#include "../../LED_ANIMATION/include/RCC_interface.h"
#include "../../LED_ANIMATION/include/STD_TYPES.h"
#include "../../LED_ANIMATION/include/STK_interface.h"

void main(void)
{

	RCC_voidInit();
    RCC_voidEnablePrephiralClock( RCC_AHB , RCC_AHB_GPIOAEN);
    void MSTK_voidInit(void);

    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN0 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN0 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN0 ,  0 );


    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN1 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN1 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN1 ,  0 );


    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN2 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN2 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN2 ,  0 );

    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN3 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN3 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN3 ,  0 );

    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN4 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN4 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN4 ,  0 );

    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN5 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN5 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN5 ,  0 );

    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN6 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN6 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN6 ,  0 );

    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN7 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN7 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN7 ,  0 );


    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN8 ,  GPIO_OUTPUT );
    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN8 , GPIO_LOW_SPEED  );
    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN8 ,  0 );





     u8 no_of_leds = 0 ;
	 u8 end_value = 8  ;


     u8 no_of_leds2 = 0 ;
     u8 end_value2 = 8  ;

     u8 snakeDone = 0   ;
     u8 pingpongDone = 0 ;


     u8 var_1 = 0   ;
     u8 var_2 = 3   ;

     u8 var_3 = 0   ;
     u8 var_4 = 7   ;

     void holding_led(u8 led_number)
    		    {

    		    	MGPIO_voidSetPinValue( GPIO_PORTA ,led_number ,  GPIO_PIN_HIGH );

    		    }



     void snake(){
     		 for (no_of_leds = 0; no_of_leds <= end_value; no_of_leds ++)

     		 {
     		   				 MGPIO_voidSetPinValue( GPIO_PORTA ,no_of_leds ,  GPIO_PIN_HIGH );
     		   				 MSTK_voidSetBusyWait(10000000);
     		   				 MGPIO_voidSetPinValue( GPIO_PORTA ,no_of_leds ,  GPIO_PIN_LOW );
     		   				 MSTK_voidSetBusyWait(10000000);

     		   				 if (no_of_leds == end_value)
     		   				 {
     		   					holding_led(no_of_leds);
     		   					no_of_leds = 0 ;
     		   					end_value -- ;
                                 if(end_value == 0)
                                 {
                                 	snakeDone = 1 ;
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,0 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,1 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,2 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,3 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,4 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,5 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,6 ,  GPIO_PIN_LOW );
                                 	MGPIO_voidSetPinValue( GPIO_PORTA ,7 ,  GPIO_PIN_LOW );
                                 	break;
                                 }


     		   				 }


        	     }
     }





     void pingpong()
     {

     	 for (no_of_leds2 = 0; no_of_leds2 <= end_value2; no_of_leds2 ++)

     		 {
     		   				 MGPIO_voidSetPinValue( GPIO_PORTA ,no_of_leds2 ,  GPIO_PIN_HIGH );
     		   				 MSTK_voidSetBusyWait(10000000);
     		   				 MGPIO_voidSetPinValue( GPIO_PORTA ,no_of_leds2 ,  GPIO_PIN_LOW );
     		   				 MSTK_voidSetBusyWait(10000000);

     		   				 if (no_of_leds2 == end_value2)
     		   				 {
     		   		 for (no_of_leds2 = 8 ; no_of_leds2 > 0 ; no_of_leds2 -- )
     		   		 {
     		   			 MGPIO_voidSetPinValue( GPIO_PORTA ,no_of_leds2 - 1 ,  GPIO_PIN_HIGH );
     		   			 MSTK_voidSetBusyWait(10000000);
     		   			 MGPIO_voidSetPinValue( GPIO_PORTA ,no_of_leds2 - 1 ,  GPIO_PIN_LOW );
     				     MSTK_voidSetBusyWait(10000000);
     				     if(no_of_leds2 == 1)
     				     {
     				     pingpongDone = 1 ;
     				     }
     		   		 }
     		   		 break ;
     		   				 }


       	     }




     }










     void warda(){
     		 for (var_1 = 4; var_1 < 8 ; var_1 ++)

     		 {


     		   	 MGPIO_voidSetPinValue( GPIO_PORTA ,var_1 ,  GPIO_PIN_HIGH );

     	   		MGPIO_voidSetPinValue( GPIO_PORTA ,var_2 ,  GPIO_PIN_HIGH);
     	   	MSTK_voidSetBusyWait(10000000);
                 var_2 -- ;

     		 }


     }


     void wardaClose(){
     		 for (var_3 = 0; var_3 < 4 ; var_3 ++)

     		 {


     		   	 MGPIO_voidSetPinValue( GPIO_PORTA ,var_3 ,  GPIO_PIN_LOW );

     	   		MGPIO_voidSetPinValue( GPIO_PORTA ,var_4 ,  GPIO_PIN_LOW);
     	   	MSTK_voidSetBusyWait(10000000);
                 var_4 -- ;

     		 }


     }








snake();
if(snakeDone == 1 )
{
pingpong();
if (pingpongDone == 1)
{
warda();
wardaClose();
}

}




	}




