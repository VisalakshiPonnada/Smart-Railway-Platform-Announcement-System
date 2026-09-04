#include<lpc21xx.h>
#include "lcd.h"
#include "lcd_defines.h"
#include "train.h"
#include "types.h"
#include "delay.h"
#include<string.h>
extern volatile U8 edit_mode;
TrainInfo_t TrainDB[TOTAL_TRAINS]={

   {11019,"KONARK EXP ",6,30,6,35,6,30,6,35,1,0},

   {12864,"HOWRAH EXP ",10,40,10,45,10,40,10,45,2,0},

   {17031,"ARONAI EXP ",17,20,17,21,17,20,17,21,3,0}

};
void DisplayTrainInfo(U1 index)
{
  int i,j;
  U8 len,hour,min,sec;
  U8 diff;
  static U8 mode=0;
  static U8 lastsec=255;
  len=strlen(TrainDB[index].trainname);
  for(i=-16;i<len;i++)
                {
        if(edit_mode==1)
                  return;
GetRTCTimeInfo(&hour,&min,&sec);
        if(sec>=lastsec)
        diff=sec-lastsec;
        else
        diff=(sec+60)-lastsec;
  if(diff>=5)
  {
    lastsec=sec;
        mode=!mode;
  }
  cmdLCD(GOTO_LINE1_POS0);
  U32LCD(TrainDB[index].trainnumber);
        charLCD(' ');
                for(j=0;j<16;j++)
                {
                if((i+j)>=0 && (i+j)<len)
                charLCD(TrainDB[index].trainname[i+j]);
                else
                charLCD(' ');
                }
  cmdLCD(GOTO_LINE2_POS0);
  if(mode==0)
  {
  charLCD(TrainDB[index].updatedarrivalhour/10+'0');
  charLCD(TrainDB[index].updatedarrivalhour%10+'0');
  charLCD(':');
  charLCD(TrainDB[index].updatedarrivalminute/10+'0');
  charLCD(TrainDB[index].updatedarrivalminute%10+'0');
  charLCD(' ');
 charLCD(TrainDB[index].updateddeparturehour/10+'0');
  charLCD(TrainDB[index].updateddeparturehour%10+'0');
  charLCD(':');
  charLCD(TrainDB[index].updateddepartureminute/10+'0');
  charLCD(TrainDB[index].updateddepartureminute%10+'0');

  strLCD((s8 *)" PF");
  charLCD(' ');
  charLCD(TrainDB[index].platform+'0');
  }
  else
  {
    //GetRTCTimeInfo(&hour,&min,&sec);
        strLCD((s8*)"      ");
        charLCD((hour/10)+'0');
charLCD((hour%10)+'0');
charLCD(':');

charLCD((min/10)+'0');
charLCD((min%10)+'0');
charLCD(':');

charLCD((sec/10)+'0');
charLCD((sec%10)+'0');
strLCD((s8*)"      ");
  }
                delay_ms(300);
                }
   }
 U1 FindCurrentTrain(U32 hour,U32 minute)
{
  U1 i;
  for(i=0;i<TOTAL_TRAINS;i++)
  {
    if(TrainDB[i].updatedarrivalminute>0)
        {
    if(hour==TrainDB[i].updatedarrivalhour)
            if(minute>=TrainDB[i].updatedarrivalminute-1 && minute<=TrainDB[i].updateddepartureminute)
          return i;
        }
        else
        {
          if(hour==TrainDB[i].arrivalhour)
            if(minute>=TrainDB[i].arrivalminute-1 && minute<=TrainDB[i].departureminute)
          return i;
        }
  }
  return 255;
}

