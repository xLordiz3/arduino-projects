#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

int KP1 = 2;
int KP2 = 3;
int LP1 = 4;
int LP2 = 5;
int UGP = 6;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, UGP, NEO_GRB + NEO_KHZ800);

enum {PRESSED, RELEASED} zs = RELEASED, xs = RELEASED;

void setup()
{
  Serial.begin(9600);
  strip.begin();
  
  pinMode(KP1, INPUT_PULLUP);
  pinMode(KP2, INPUT_PULLUP);
  pinMode(LP1, OUTPUT);
  pinMode(LP2, OUTPUT);

  digitalWrite(KP1 , HIGH);
  digitalWrite(KP2 , HIGH);
  digitalWrite(LP1 , HIGH);
  digitalWrite(LP2 , HIGH);
}

void enableKB(void)
{
  attachInterrupt(digitalPinToInterrupt(KP1), zp, FALLING);
  attachInterrupt(digitalPinToInterrupt(KP2), xp, FALLING);
  Keyboard.begin();
  interrupts();
}

void waitKP2ress(void)
{
  unsigned char _=0;
  while (digitalRead(KP1) || digitalRead(KP2))
  {
    delay(334);
  }
}

void wait2krelease(void)
{
  unsigned char _=0;
  while(!digitalRead(KP1) || !digitalRead(KP2))
  {
    delay(155);
  }
}

void loop()
{
  waitKP2ress();
  wait2krelease();
  enableKB();
  while(1)
  {
    if (zs == PRESSED)
    {
      if(digitalRead(KP1))
      {
        zs = RELEASED;
        Keyboard.release('z');
      }
    }
    if (xs == PRESSED)
    {
      if(digitalRead(KP2))
      {
        xs = RELEASED;
        Keyboard.release('x');
      }
    }
    delay(1);
  }
}

void zp(void)
{
  Keyboard.press('z');
  zs = PRESSED;
}

void xp(void)
{
  Keyboard.press('x');
  xs = PRESSED;
}

void stripslowall()
{
  int p = 7;
  for (int i = 0; i <= p; i++)
  {
    strip.setPixelColor(i,255,0,0);
  }
}

