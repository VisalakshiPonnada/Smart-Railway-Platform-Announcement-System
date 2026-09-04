#include "train.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "keypad_defines.H"
#include "edit.h"
#include "types.h"
#include "alert.h"
#include "delay.h"
U32 key;
void Adminconfigmode(void)
{
cmdLCD(0X01);
strLCD("ADMINMODE");
cmdLCD(GOTO_LINE2_POS0);
strLCD("1.TRAIN 2.RTC");
key=keyscan();
if(key==1)
  edittraininfo();
  else if(key==2)
  editrtc();
}
void edittraininfo(void)
{
U8 key;
cmdLCD(0X01);
strLCD("SELECT TRAIN");
cmdLCD(GOTO_LINE2_POS0);
strLCD("1 2 3");
key=keyscan();
if(key>=1 && key<=3)
editdelay(key-1);
}
void editrtc(void)
{
 cmdLCD(0X01);
strLCD("RTC EDIT");
cmdLCD(GOTO_LINE2_POS0);
strLCD("ENTER DATE");
}
void editdelay(U32 index)
{
  U32 delayhour=0;
  U32 delayminute=0;
  U32 key;
  U8 count=0;
  cmdLCD(0X01);
strLCD("DELAY HH:MM");
cmdLCD(GOTO_LINE2_POS0);
while(1)
{
  key=keyscan();
  if(key==13)
  {
    delayhour=0;
        delayminute=0;
        count=0;
        cmdLCD(GOTO_LINE2_POS0);
        strLCD("               ");
cmdLCD(GOTO_LINE2_POS0);
  }
  else if(key==14)
  {
  if(count==4 && delayhour<24 && delayminute<60)
  {
  updatetraintime(index,delayhour,delayminute);
 cmdLCD(GOTO_LINE1_POS0);
 if(delayhour>0 || delayminute>0)
 {
    REDLED_ON();
        YELLOWLED_OFF();
        GREENLED_OFF();
 }
strLCD("DELAY UPDATED");
delay_s(2);
cmdLCD(0X01);
return;
}
}
else if(key>=0 && key<=9)
{
 if(count<2)
 {
   delayhour=delayhour*10+key;
   charLCD(key+'0');
   count++;
   if(count==2)
   charLCD(':');
}
   else if(count<4)
   {
   delayminute=delayminute*10+key;
   charLCD(key+'0');
   count++;
}
}
}
}
void updatetraintime(U32 index,U32 delayhour,U32 delayminute)
{
  U32 total;
  total=TrainDB[index].arrivalhour*60;
  total=total+TrainDB[index].arrivalminute;
  total=total+(delayhour*60);
  total=total+delayminute;
  TrainDB[index].updatedarrivalhour=(total/60)%24;
  TrainDB[index].updatedarrivalminute=total%60;
  total=TrainDB[index].departurehour*60;
  total=total+TrainDB[index].departureminute;
  total=total+(delayhour*60);
  total=total+delayminute;
  TrainDB[index].updateddeparturehour=(total/60)%24;
  TrainDB[index].updateddepartureminute=total%60;
}
