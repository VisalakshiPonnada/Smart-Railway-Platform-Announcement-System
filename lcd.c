#include<lpc21xx.h>
#include "types.h"
#include "delay.h"
#include "defines.h"
#include "lcd_defines.h"

void writeLCD(U8 byte)
{
   WRITEBYTE(IOPIN0,LCD_DATA,byte);
   IOCLR0=1<<LCD_RW;
   IOSET0=1<<LCD_EN;
   delay_us(1);
   IOCLR0=1<<LCD_EN;
   delay_ms(2);
}
void cmdLCD(U8 cmd)
{
IOCLR0=1<<LCD_RS;
writeLCD(cmd);
}
void InitLCD(void)
{
 IODIR0|=((0XFF<<LCD_DATA)|(1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN));
 delay_ms(15);
 cmdLCD(0X30);
 delay_ms(4);
 delay_ms(100);
 cmdLCD(0X30);
 delay_us(100);
cmdLCD(0X30);
 cmdLCD(MODE_8BIT_2LINE);
 cmdLCD(DSP_ON_CUR_BLK);
 cmdLCD(CLEAR_LCD);
 cmdLCD(SHIFT_CUR_RIGHT);
}
void charLCD(U8 asciival)
{
IOSET0=1<<LCD_RS;
writeLCD(asciival);
}
void strLCD(s8 *str)
{
while(*str)
charLCD(*str++);
}
void U32LCD(U32 n)
{
U8 a[10];
s32 i=0;
if(n==0)
{
charLCD('0');
}
else
{
while(n>0)
{
a[i]=(n%10)+48;
n/=10;
i++;
}
for(--i;i>=0;i--)
charLCD(a[i]);
}
}
void s32LCD(s32 n)
{
if(n<0)
{
charLCD('-');
n=-n;
}
U32LCD(n);
}
void F32LCD(f32 fn,U8 ndp)
{
U32 n;
s32 i;
if(fn<0.0)
{
charLCD('-');
fn=-fn;
}
n=fn;
U32LCD(n);
charLCD('.');
for(i=0;i<ndp;i++)
{
fn=(fn-n)*10;
n=fn;
charLCD(n+48);
}
 }
  void BUILDCGRAM(U8 *p,U8 nbytes)
  {
  U8 i;
  cmdLCD(GOTO_CGRAM_START);
  IOSET0=1<<LCD_RS;
  for(i=0;i<nbytes;i++)
  {
  writeLCD(p[i]);
  }
  cmdLCD(GOTO_LINE1_POS0);
  }
while(n>0)
