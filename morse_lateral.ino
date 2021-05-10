#define kbd_es_es
#include "DigiKeyboard.h"

const byte button_di=0; // defino input del pulsador para di
const byte button_dah=2; //defino inputo del pulsador para dah
const byte buzzer=1; // defino input del buzzer
const byte di_delay=100;
const byte dah_delay=3*di_delay;
const byte tone_hz=440;

byte letra=1;  // variable en bytes que irá acumulando los 1 y 0 según dit or dha. 
byte count=0;
byte space=1;

unsigned long startTime;
unsigned long endTime;
unsigned long duration;
byte timerRunning=0;
byte timerRunningRelease=0;





void setup()
{
  DigiKeyboard.update();
  DigiKeyboard.delay(5000);
  pinMode(button_di, INPUT);
  digitalWrite(button_di, HIGH); // pull up resistor en la entrada del botón
  pinMode(button_dah, INPUT);
 // digitalWrite(button_dah, HIGH); // pull up resistor en la entrada del botón
  
  pinMode(buzzer, OUTPUT);
  
}

void loop() 
{
  DigiKeyboard.update();
  if (digitalRead(button_di==LOW))
  {
    sound(0,di_delay,tone_hz);
    letra = letra << 1;
    startTime=millis();
  }
  if (digitalRead(button_dah==LOW))
  {
    sound(1,di_delay,tone_hz);
    letra = letra << 1;
    letra++;
    startTime=millis();
  }
  if (digitalRead(button_dah==HIGH) && digitalRead(button_di==HIGH))
  {
    endTime=millis();
    duration=endTime - startTime;
    if (duration > di_delay && duration < dah_delay) // temrinó la letra
    {
      space=0;
      print_letra(letra);
    }
    if (duration > dah_delay && space==0) // terminó la palabra
    {
      space=1;
      DigiKeyboard.print(F(" "));
    }

          
    
  }
  
  delay(20);
 }

 void print_letra(byte letra)
  {
    if (letra==5)
              DigiKeyboard.print(F("A"));   
            else if (letra==24)
              DigiKeyboard.print(F("B"));
            else if (letra==26)  
              DigiKeyboard.print(F("C"));
            else if (letra==12)  
              DigiKeyboard.print(F("D"));
            else if (letra==2)  
              DigiKeyboard.print(F("E"));
            else if (letra==18)  
              DigiKeyboard.print(F("F"));
            else if (letra==14)  
              DigiKeyboard.print(F("G"));
            else if (letra==16)  
              DigiKeyboard.print(F("H"));
            else if (letra==4)  
              DigiKeyboard.print(F("I"));
            else if (letra==23)  
              DigiKeyboard.print(F("J"));
            else if (letra==13)  
              DigiKeyboard.print(F("K"));
            else if (letra==20)  
              DigiKeyboard.print(F("L"));
            else if (letra==7)  
              DigiKeyboard.print(F("M"));
            else if (letra==6)  
              DigiKeyboard.print(F("N"));
            else if (letra==15)  
              DigiKeyboard.print(F("O"));
            else if (letra==22)  
              DigiKeyboard.print(F("P"));
            else if (letra==29)  
              DigiKeyboard.print(F("Q"));
            else if (letra==10)  
              DigiKeyboard.print(F("R"));
            else if (letra==8)  
              DigiKeyboard.print(F("S"));
            else if (letra==3)  
              DigiKeyboard.print(F("T"));
            else if (letra==9)  
              DigiKeyboard.print(F("U"));
            else if (letra==17)  
              DigiKeyboard.print(F("V"));
            else if (letra==11)  
              DigiKeyboard.print(F("W"));
            else if (letra==25)  
              DigiKeyboard.print(F("X"));
            else if (letra==27)  
              DigiKeyboard.print(F("Y"));
            else if (letra==28)  
              DigiKeyboard.print(F("Z"));

            letra=1;
          }

 void sound(byte di_dah,byte duration,byte tone_hz)
 {
  tone(buzzer,tone_hz);
  if(di_dah==0)
    delay(duration);
   else
    delay(duration*3);
   
  noTone(buzzer);
  delay(duration);
 }
    
