#define TOTAL_TRAINS 3
#include "types.h"
typedef struct
{
  U32 trainnumber;
  s8 trainname[25];
  U1 arrivalhour;
  U1 arrivalminute;
  U1 departurehour;
  U1 departureminute;
  U1 updatedarrivalhour;
  U1 updatedarrivalminute;
  U1 updateddeparturehour;
  U1 updateddepartureminute;
  U1 platform;
  U8 delayminutes;
}TrainInfo_t;
extern TrainInfo_t TrainDB[];
void DisplayTrainInfo(U1 index);
U1 FindCurrentTrain(U32 hour,U32 minute);
void editdelay(U32 index);
void updatetraintime(U32 index,U32 delayhour,U32 delayminute);
