/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: dell
 */
#include"util/delay.h"
#include "../Files/STDTYPES.h"
#include "../Files/BIT_MATH.h"
#include "../Files/CHECK_ERROR.h"
#include "PORT_Config.h"
#include "PORT_private.h"
#include "PORT_REG.h"
#include "PORT_Interface.h"
#include"DIO_REG.h"
#include"DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"

int main(void)
{

	 PORT_VoidInit();
	 LCD_VoidInit();
	 LCD_VoidSendData(' ');
/**/
u8 Space[8]=
		{
			 0x00
			,0x00
			,0x00
			,0x00
			,0x00
			,0x00
			,0x00
			,0x00

		};
/*Dall_alphapet (د)*/
u8 Dal_ALPHA[8]=
		{
			 0x01
			,0x01
			,0x01
			,0x01
			,0x01
			,0x01
			,0xFF
			,0x00

		};
/*AEN_alphapet (ع)*/
u8 AEN_ALPHA[8]=
		{
			 0b00001111
			,0b00001000
			,0b00001000
			,0b00001000
			,0b00001000
			,0b00001000
			,0b00011111
			,0b00000000

		};
/*ALEF_alphapet (ا)*/
u8 ALEF_ALPHA[8]=
		{
			 0b00010000
			,0b00010000
			,0b00010000
			,0b00010000
			,0b00010000
			,0b00010000
			,0b00011111
			,0b00000000

		};

/*the first half of mosadas*/
u8 Mosads1[8]={
		 0b00011111
		,0b00011111
		,0b00011010
		,0b00011010
		,0b00011110
		,0b00011000
		,0b00011000
		,0b00011000};
/*the Second half of mosadas*/
u8 Mosads2[8]={
		 0b00011110
		 ,0x00
		 ,0x00
		 ,0x00
		 ,0x00
		 ,0x00
		 ,0x00
		 ,0x00

		};
/*the rosasa of mosadas*/
u8 Rosasa[8]=
		{
		  0b00000100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};
/*the body of hamocsha*/
u8 Hamocsha[8]=
		{
		  0b00001110
		 ,0b00001010
		 ,0b00001010
		 ,0b00001110
		 ,0b00000100
		 ,0b00011111
		 ,0b00000100
		 ,0b00011111

		};
u8 StaticHalfBody1[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00000100
		 ,0b00011111
		 ,0b00000100
		};
u8 DynamicHalfBody2_Ani0[8]=
		{
		  0b00000100
		 ,0b00000100
		 ,0b00001010
		 ,0b00010001
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};
u8 DynamicHalfBody1_HandAbove[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00010101
		 ,0b00001110
		 ,0b00000100
		 ,0b00000100
		};
u8 DynamicHalfBody1_HandDown[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00000100
		 ,0b00000100
		 ,0b00001110
		 ,0b00010101
		};
u8 DynamicHalfBody1_HandRight[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00000101
		 ,0b00000110
		 ,0b00000100
		 ,0b00000100
		};
u8 DynamicHalfBody1_HandLeft[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00010100
		 ,0b00001100
		 ,0b00000100
		 ,0b00000100
		};
u8 DynamicHalfBody1_HandMiddle[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00000100
		 ,0b00000100
		 ,0b00000100
		 ,0b00000100
		};


u8 DynamicHalfBody2_LegLeftDown[8]=
		{
		  0b00000100
		 ,0b00000100
		 ,0b00001100
		 ,0b00010100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};
u8 DynamicHalfBody2_LegMiddle[8]=
		{
		  0b00000100
		 ,0b00000100
		 ,0b00000100
		 ,0b00000100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};
u8 DynamicHalfBody2_LegRightDown[8]=
		{
		  0b00000100
		 ,0b00000100
		 ,0b00000110
		 ,0b00000101
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};
u8 DynamicHalfBody2_LegRightAbove[8]=
		{
		  0b00000100
		 ,0b00000101
		 ,0b00000110
		 ,0b00000100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};
u8 DynamicHalfBody2_LegLeftAbove[8]=
		{
		  0b00000100
		 ,0b00010100
		 ,0b00001100
		 ,0b00000100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		};


/*when hamocsha dead*/
u8 HamocshaMatt[8]=
		{
		  0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00010100
		 ,0b00010101
		 ,0b00011111
		 ,0b00010101
		 ,0b00010100
		};

u8 FootballStart[8]=
		{
		  0b00011111
		 ,0b00010001
		 ,0b00010001
		 ,0b00011111
		 ,0b00000100
		 ,0b00011110
		 ,0b00011101
		 ,0b00000100
		};


u8 Ball_Hand0[8]=
		{
          0b00001110
		 ,0b00001010
		 ,0b00001010
		 ,0b00001110
		 ,0b00000100
		 ,0b00000100
		 ,0b00000100
		 ,0b00000100

		};
u8 Ball_Hand1[8]=
		{
          0b00001110
		 ,0b00001010
		 ,0b00001010
		 ,0b00001110
		 ,0b00000100
		 ,0b00000100
		 ,0b00010100
		 ,0b00000100

		};
u8 Ball_Hand2[8]=
		{
          0b00001110
		 ,0b00001010
		 ,0b00001010
		 ,0b00001110
		 ,0b00010100
		 ,0b00000100
		 ,0b00000100
		 ,0b00000100

		};

u8 Ball_Leg0[8]=
		{
		  0b00000100
		 ,0b00000100
		 ,0b00001100
		 ,0b00011100
		 ,0b00011100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000

		};
u8 Ball_Leg1[8]=
		{
		  0b00000100
		 ,0b00000100
		 ,0b00010100
		 ,0b00001100
		 ,0b00010100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000

		};

u8 Ball_Leg2[8]=
		{
		  0b00010100
		 ,0b00011100
		 ,0b00010100
		 ,0b00010100
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000
		 ,0b00000000

		};
u8 *MyName="Doaa Mohamed";



//LCD_VoidCreateSpecialChar(Mosads1,0,0,0);
//LCD_VoidCreateSpecialChar(Mosads2,1,0,1);
//LCD_VoidSendString( "Don't Kill Me");
//LCD_VoidCreateSpecialChar(Hamocsha,2,0,14);
//LCD_VoidCreateSpecialChar(HamocshaMatt,3,0,15);
//LCD_VoidSendNumber(333);
//LCD_VoidSendString("Meko");



	 while(1)
	 {



		LCD_VoidSendString( "Hello I'm Doaa");
		_delay_ms(1000);
		LCD_VoidSendCommand(0x01);


		 /*MY Name in SineWave*/
         /*
		        u8 Counter=0;
				   u8 XPos;
				 for(u8 l=0;l<strlen(MyName);l++)
				 {
				 if(l%2==0)
					 XPos=0;
				else
					XPos=1;

				 LCD_VoidGoToPos(XPos,l);
				 LCD_VoidSendData(MyName[l]);
				 _delay_ms(500);
				 }
				 LCD_VoidSendCommand(0x01);
				 		 _delay_ms(500);

           */
		 /*my name in Arabic with Sine Wave*/

		/*
		  u8 Counter=0;
		   u8 XPos;
		 for(u8 l=0;l<4;l++)
		 {if(l%2==0)
			 XPos=0;
		else
			XPos=1;

		 LCD_VoidCreateSpecialChar(Dal_ALPHA,0,XPos,Counter+3);
		 LCD_VoidCreateSpecialChar(AEN_ALPHA,1,XPos,Counter+2);
		 LCD_VoidCreateSpecialChar(ALEF_ALPHA,2,XPos,Counter+1);
		 LCD_VoidCreateSpecialChar(AEN_ALPHA,3,XPos,Counter+0);
		 Counter+=4;
		 _delay_ms(500);
		 }
		 LCD_VoidSendCommand(0x01);
		 		 _delay_ms(500);
		*/



/* as yaphta simulating from left to right*/
/* for(u8 k=0;k<14 ;k++)
 {
	 LCD_VoidGoToPos(0,k);
	 LCD_VoidSendString("DOAA");
	 _delay_ms(150);
	 LCD_VoidSendCommand(0x01);
 }
*/






/*animation vidio */

	  /*Can Running*/

		LCD_VoidSendString( "I Can Run");
		 _delay_ms(1000);
		LCD_VoidSendCommand(0x01);
		/*Moving from Left to Right*/

		 LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,0);
		 LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,0);
		 _delay_ms(500);
		 LCD_VoidSendCommand(0x01);
		 for(u8 k=1;k<15 ;k++)
		 {
		 LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,k);
		 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,k);
		 _delay_ms(100);
		LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,k);
		 _delay_ms(150);
		 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightAbove,1,1,k);
		 _delay_ms(100);
		 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,k);
		  _delay_ms(200);
		 LCD_VoidSendCommand(0x01);

		 }


		 /*Moving from Right to Left*/
		 LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,15);
		LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,15);
				 _delay_ms(500);
				 LCD_VoidSendCommand(0x01);
				 for(s8 k=14;k>=0 ;k--)
				 {

				LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,k);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,k);
				  _delay_ms(100);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,k);
				   _delay_ms(150);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftAbove,1,1,k);
				 _delay_ms(200);

				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,k);
				 _delay_ms(200);
				 LCD_VoidSendCommand(0x01);

				 }


		/*Dancing*/
				 LCD_VoidSendString( "I Love Dancing");
				  _delay_ms(1000);
				 LCD_VoidSendCommand(0x01);



				 LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,7);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,7);
				 _delay_ms(500);
				  LCD_VoidSendCommand(0x01);

				 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandAbove,0,0,7);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,7);
				  _delay_ms(250);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandDown,0,0,7);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,7);
				  _delay_ms(250);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
				  _delay_ms(250);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandRight,0,0,7);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
				  _delay_ms(250);
				  LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,7);
				  LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,7);
				   _delay_ms(250);
				     LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
				     LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
				   	 _delay_ms(250);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandMiddle,0,0,7);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftAbove,1,1,7);
				   	 _delay_ms(250);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,7);
				   	 _delay_ms(250);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
				     LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
				   	 _delay_ms(250);


				   	 LCD_VoidSendCommand(0x01);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,6);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,6);
				   	_delay_ms(250);
				     LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,6);
				   	 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,6);
				   	_delay_ms(250);
				     LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandRight,0,0,6);
				     LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,6);
				   	_delay_ms(250);
				   	LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandMiddle,0,0,6);
				   	LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,6);
				   	_delay_ms(250);
				   	LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandDown,0,0,6);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,6);
				   	_delay_ms(250);
				   	LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,6);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightAbove,1,1,6);
				    _delay_ms(250);
				    LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,6);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,6);
				     _delay_ms(250);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandAbove,0,0,6);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,6);
				    _delay_ms(250);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandDown,0,0,6);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightAbove,1,1,6);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandRight,0,0,6);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,6);
					_delay_ms(250);



					LCD_VoidSendCommand(0x01);



/*
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandAbove,0,0,7);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,7);
				  _delay_ms(250);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandDown,0,0,7);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,7);
				   _delay_ms(250);
				    LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,7);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,7);
				   	 _delay_ms(250);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
				   _delay_ms(250);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandRight,0,0,7);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
				   _delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
					 _delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandMiddle,0,0,7);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftAbove,1,1,7);
					 _delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,7);
					 _delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,7);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,7);
					 _delay_ms(250);




					 LCD_VoidSendCommand(0x01);
					 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,8);
					 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,8);
					_delay_ms(250);
					 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,8);
					 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,8);
					_delay_ms(250);
					 LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandRight,0,0,8);
					 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,8);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandMiddle,0,0,8);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,8);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandDown,0,0,8);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,8);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(StaticHalfBody1,0,0,8);
				    LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,8);
				    _delay_ms(250);

					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandLeft,0,0,8);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightAbove,1,1,8);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandAbove,0,0,8);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegLeftDown,1,1,8);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandDown,0,0,8);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightAbove,1,1,8);
					_delay_ms(250);
					LCD_VoidCreateSpecialChar(DynamicHalfBody1_HandRight,0,0,8);
					LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegRightDown,1,1,8);
					_delay_ms(250);

*/





		/*Playing Football*/

				LCD_VoidSendString( "I Play Football");
				  _delay_ms(1000);
				 LCD_VoidSendCommand(0x01);
				 LCD_VoidCreateSpecialChar(FootballStart,0,0,5);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_Ani0,1,1,5);
				 LCD_VoidGoToPos(0,7);
				 LCD_VoidSendString( "Let's Go");
				 _delay_ms(2000);
				 LCD_VoidSendCommand(0x01);
				 for(u8 h=0;h<2;h++)
				 {
				 LCD_VoidCreateSpecialChar(Ball_Hand0,0,0,5);
				 LCD_VoidCreateSpecialChar(Ball_Leg0,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand0,0,0,5);
				 LCD_VoidCreateSpecialChar(Ball_Leg1,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand0,0,0,5);
				 LCD_VoidCreateSpecialChar(Ball_Leg2,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand1,0,0,5);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand2,0,0,5);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand1,0,0,5);
				 LCD_VoidCreateSpecialChar(DynamicHalfBody2_LegMiddle,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand0,0,0,5);
				 LCD_VoidCreateSpecialChar(Ball_Leg2,1,1,5);
				 _delay_ms(200);
				 LCD_VoidCreateSpecialChar(Ball_Hand0,0,0,5);
				 LCD_VoidCreateSpecialChar(Ball_Leg1,1,1,5);
				 _delay_ms(200);
				 }
				 LCD_VoidSendCommand(0x01);


		 /*Killing*/
		 u8 k=0;
		 LCD_VoidSendString( "Don't Kill Me");
		 _delay_ms(1000);
		 LCD_VoidSendCommand(0x01);
		 LCD_VoidCreateSpecialChar(Mosads1,0,0,0);
		 LCD_VoidCreateSpecialChar(Mosads2,1,0,1);
		 LCD_VoidCreateSpecialChar(Hamocsha,2,0,14);
		 for(k=0;k<12;k++)
		 {
			 LCD_VoidCreateSpecialChar(Rosasa,4,0,k+2);
			 _delay_ms(200);
			 LCD_VoidCreateSpecialChar(Space,5,0,k+2);

		 }
		 if(k==12)
		 {
			 LCD_VoidCreateSpecialChar(Space,5,0,14);
			 LCD_VoidCreateSpecialChar(HamocshaMatt,3,0,15);
			 _delay_ms(500);
		 }
		 LCD_VoidSendCommand(0x01);
		 _delay_ms(500);



	}
	return 0;
}
