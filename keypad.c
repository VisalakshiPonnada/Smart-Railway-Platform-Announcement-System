#include <lpc21xx.h>
#include "types.h"
#include "defines.h"
#include "kpm_defines.h"
#include "delay.h"
U32 KPMLUT[4][4]={{1,2,3,10},{4,5,6,11},{7,8,9,12},{13,0,14,15}};
void Init_KPM(void)
{
                  WRITENIBBLE(IODIR1,ROW0,15);
}
U32 colscan(void)
{
if(READNIBBLE(IOPIN1,COL0)<15)
return 0;
else
return 1;
}
U32 rowcheck(void)
{
U32 rno;
for(rno=0;rno<4;rno++)
{
WRITENIBBLE(IOPIN1,ROW0,~(1<<rno));
if(colscan()==0)
break;
}
IOCLR1=15<<ROW0;
return rno;
}
U32 colcheck(void)
{
U32 cno;
for(cno=0;cno<4;cno++)
{
if(READBIT(IOPIN1,(cno+COL0))==0)
break;
}
return cno;
}
U32 keyscan(void)
{
U32 rno,cno;
U32 key;
while(colscan());
rno=rowcheck();
cno=colcheck();
while(!colscan());
key=KPMLUT[rno][cno];
return key;
}
}
