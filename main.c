#include<lpc21xx.h>
#include "train.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "rtc.h"
#include "types.h"
#include "delay.h"
#include "alert.h"
#include "keypad_defines.H"
#include "interrupt.h"
U32 hour,min,sec;
U32 date,month,year;
U32 day;
U1 index;
U8 i;
extern volatile U8 edit_mode;
int main(void)
{
InitLCD();
RTC_Init();
SetDemoTime();
AlertInit();
Init_KPM();
EINT3_Init();
while(1)
{
        GetRTCTimeInfo(&hour,&min,&sec);
    GetRTCDateInfo(&date,&month,&year);
        GetRTCDay(&day);
index=FindCurrentTrain(hour,min);
   if(edit_mode==1)
   {
     Adminconfigmode();
         edit_mode=0;
         continue;
         }
    if(index !=255)
        {
   if(hour==TrainDB[index].arrivalhour && min<TrainDB[index].arrivalminute)
   {
   YELLOWLED_ON();
  GREENLED_OFF();
   REDLED_OFF();
   DisplayTrainInfo(index);
   }
   else if(hour==TrainDB[index].arrivalhour && min==TrainDB[index].arrivalminute)
   {
   YELLOWLED_OFF();
   REDLED_OFF();
   GREENLED_ON();
         BUZZER();
         delay_s(1);
         BUZZER_OFF();
   DisplayTrainInfo(index);
   }
   else if(TrainDB[index].updatedarrivalminute>0)
   {
   GREENLED_OFF();
YELLOWLED_OFF();
   REDLED_ON();
   BUZZER_OFF();
}
else if(hour>TrainDB[index].departurehour ||
(TrainDB[index].departurehour && min>=TrainDB[index].departureminute))
{
   NoTrainAlert();
}
}
else
{
   NoTrainAlert();
  DisplayRTCTimeInfo(hour,min,sec);
  DisplayRTCDateInfo(date,month,year);
  DisplayRTCDay(day);
}
}
}
