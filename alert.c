#include<lpc21xx.h>
#include "alert.h"
#include "delay.h"
void AlertInit(void)
{
  IODIR0 |=(1<<GREEN_LED_PIN)|(1<<YELLOW_LED_PIN)|(1<<RED_LED_PIN)|(1<<BUZZER_PIN);
  IOSET0 =(1<<GREEN_LED_PIN)|(1<<YELLOW_LED_PIN)|(1<<RED_LED_PIN)|(1<<BUZZER_PIN);
}
void GREENLED_ON(void)
{
   IOCLR0 = (1<<GREEN_LED_PIN);
}
void GREENLED_OFF(void)
{
   IOSET0=(1<<GREEN_LED_PIN);
}
void YELLOWLED_ON(void)
{
   IOCLR0 = (1<<YELLOW_LED_PIN);
}
void YELLOWLED_OFF(void)
{
   IOSET0 = (1<<YELLOW_LED_PIN);
}
void REDLED_ON(void)
{
   IOCLR0 = (1<<RED_LED_PIN);
}
void REDLED_OFF(void)
{
   IOSET0 = (1<<RED_LED_PIN);
}
void BUZZER(void)
{
   IOSET0=(1<<BUZZER_PIN);
}
void BUZZER_OFF(void)
{
   IOCLR0=(1<<BUZZER_PIN);
}
void NoTrainAlert(void)
{
  GREENLED_OFF();
  YELLOWLED_OFF();
  REDLED_OFF();
  BUZZER_OFF();
}
void REDLED_OFF(void)
