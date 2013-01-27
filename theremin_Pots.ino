#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

unsigned int curval1;

#define CONTROL_RATE 64


void setup(){
  startMozzi(CONTROL_RATE); // set a control rate of 64 (powers of 2 please)
  aSin.setFreq(440u); // set the frequency with an unsigned int or a float
}


void updateControl(){
  curval1 = analogRead(A0);
  curval1 = map(curval1, 0, 1024, 220, 880);
  
}


int updateAudio(){
  aSin.setFreq(curval1);
  return aSin.next(); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}
