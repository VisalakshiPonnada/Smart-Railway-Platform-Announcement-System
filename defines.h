#define WRITEBYTE(WORD,STARTBIT,BYTE)\
        WORD=(WORD & (U32)(~(0XFF << STARTBIT)))|\
                     (BYTE<<STARTBIT)

#define READBIT(WORD,BIT) ((WORD>>BIT)&1)

#define WRITEBIT(WORD,BIT,BITLEVEL)\
        WORD=(WORD & (U32) ~ 1(<<BIT))|\
                     (BITLEVEL<<BIT)

#define READWRITEBIT(WORD,DBIT,SBIT) \
        WORD=((WORD & ~(1<<DBIT))|\
                     ((WORD>>SBIT)&1)<<DBIT)

#define READWRITEBIT2(DWORD,SWORD,DBIT,SBIT) \
        DWORD=((DWORD & ~(1<<DBIT))|\
                     (((SWORD>>SBIT)&1)<<DBIT))
#define WRITENIBBLE(WORD,STARTBIT,NIBBLE) \
        WORD=((WORD &(U32)~0XF<<STARTBIT)|(NIBBLE<<STARTBIT))
#define READNIBBLE(WORD,STARTBIT) ((WORD>>STARTBIT)&15)
