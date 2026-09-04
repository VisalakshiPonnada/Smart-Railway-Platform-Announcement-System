#ifndef _RTC_H_
#define _RTC_H_
#include <lpc21xx.h>

#define FOSC 12000000
#define CCLK (5*FOSC)
#define PCLK (CCLK/4)

#define PREINT_VAL ((int)(PCLK/32768)-1)
#define PREFRAC_VAL (PCLK-((PREINT_VAL+1)*32768))

#define RTC_ENABLE (1<<0)
#define RTC_RESET (1<<1)
#define RTC_CLKSRC (1<<4)

#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6

void RTC_Init(void);
void GetRTCTimeInfo(U32 *hour,U32 *minute,U32 *second);
void GetRTCDateInfo(U32 *date,U32 *month,U32 *year);
void GetRTCDay(U32*day);
void DisplayRTCTimeInfo(U32 hour,U32 minute,U32 second);
void DisplayRTCDateInfo(U32 date,U32 month,U32 year);
void DisplayRTCDay(U32 day);
void SetRTCTimeInfo(U32 hour,U32 minute,U32 second);
void SetRTCDateInfo(U32 date,U32 month,U32 year);
void SetRTCDay(U32 day);
#endif
