#include<LPC21XX.h>
#include "types.h"
#include "interrupt.h"
#define EINT3_VIC_CHNO 17
volatile U8 edit_mode=0;
void eint3_ISR(void) __irq
{
  edit_mode=1;
  EXTINT=(1<<3);
  VICVectAddr=0;
}
void EINT3_Init(void)
{
  PINSEL1=PINSEL1 & ~(3<<8);
  PINSEL1 |=(3<<8);

  EXTMODE|=(1<<3);
  EXTPOLAR =EXTPOLAR & ~(1<<3);
  EXTINT=(1<<3);
  VICIntSelect &=~(1<<EINT3_VIC_CHNO);
  VICVectAddr0=(U32)eint3_ISR;
  VICVectCntl0=(1<<5)| EINT3_VIC_CHNO;
  VICIntEnable|= (1<<EINT3_VIC_CHNO);
  //EXTINT=(1<<0);
}
