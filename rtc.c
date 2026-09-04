#include<lpc21xx.h>
#include "lcd.h"
#include "lcd_defines.h"
#include "rtc.h"
#include "types.h"
s8 week[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
void RTC_Init(void)
{
    CCR=RTC_RESET;
        PREINT=PREINT_VAL;
        PREFRAC=PREFRAC_VAL;
        CCR=RTC_ENABLE;
}
void GetRTCTimeInfo(U32 *hour,U32 *minute,U32 *second)
{
    *hour=HOUR;
        *minute=MIN;
        *second=SEC;
}
void GetRTCDateInfo(U32 *date,U32 *month,U32 *year)
{
     *date=DOM;
         *month=MONTH;
         *year=YEAR;
}
void GetRTCDay(U32 *day)
{
      *day=DOW;
}
void DisplayRTCTimeInfo(U32 hour,U32 minute,U32 second)
{
cmdLCD(GOTO_LINE1_POS0);
charLCD((hour/10)+'0');
charLCD((hour%10)+'0');
charLCD(':');

charLCD((minute/10)+'0');
charLCD((minute%10)+'0');
charLCD(':');

charLCD((second/10)+'0');
charLCD((second%10)+'0');

}
void DisplayRTCDateInfo(U32 date,U32 month,U32 year)
{
cmdLCD(GOTO_LINE2_POS0);
charLCD((date/10)+'0');
charLCD((date%10)+'0');
charLCD('/');
charLCD((month/10)+'0');
charLCD((month%10)+'0');
charLCD('/');
charLCD((year/10)+'0');
charLCD((year%10)+'0');
}
void DisplayRTCDay(U32 day)
{
cmdLCD(GOTO_LINE1_POS0+10);
strLCD(week[day]);
}
void SetRTCTimeInfo(U32 hour,U32 minute,U32 second)
{
      HOUR=hour;
          MIN=minute;
          SEC=second;
}
void SetRTCDateInfo(U32 date,U32 month,U32 year)
{
      DOM=date;
          MONTH=month;
          YEAR=year;
}
void SetRTCDay(U32 day)
{
      DOW=day;
}
void SetDemoTime(void)
{
    SEC=30;
        MIN=18;
        HOUR=17;

        DOM=7;
        MONTH=8;
        YEAR=26;
}
