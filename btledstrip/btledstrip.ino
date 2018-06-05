#define RP 5
#define BP 9
#define GP 4
#define IP 7

char val;

int cyclespeed = 1400;
int r = 0;
int g = 0; 
int b = 0;
int rv, gv, bv;

void setup() 
{
  pinMode(RP,OUTPUT);
  pinMode(GP,OUTPUT);
  pinMode(BP,OUTPUT);

  Serial.begin(38400);
}

void loop() 
{
  if(Serial.available())
  {
    val = Serial.read();

    if (val == ('o'))
    {
      Off();
    }
    if (val == ('s'))
    {
     rergb();
     setRGB();
    }
  }
}

void Off()
{
  analogWrite(RP, 0);
  analogWrite(GP, 0);
  analogWrite(BP, 0);  
}
void rergb()
{
  while(!Serial.available()) {}
  rv = Serial.read();
  while(!Serial.available()) {}
  gv = Serial.read();
  while(!Serial.available()) {}
  bv = Serial.read();   
}

void setRGB()
{
  analogWrite(RP, rv);
  analogWrite(GP, gv);
  analogWrite(BP, bv);   
}

