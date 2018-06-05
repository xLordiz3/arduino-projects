import processing.serial.*;
import controlP5.*;

Serial port;
ControlP5 ard;
PFont font;

int rt,gt,bt;

void setup()
{
  size(425, 125);
  noStroke();
  frameRate(15);
  printArray(Serial.list());
  port = new Serial(this, "COM9", 9600);
  ard = new ControlP5(this);
  font = createFont("calibri light bold", 20);
  
  ard.addButton("send");
  ard.addButton("off");

  ard.addSlider("rt")
  .setRange(0,255)
  .setValue(0)
  .setPosition(10, 55)
  .setSize(255, 15);
  
  ard.addSlider("gt")
  .setRange(0,255)
  .setValue(0)
  .setPosition(10, 80)
  .setSize(255, 15);
  
  ard.addSlider("bt")
  .setRange(0,255)
  .setValue(0)
  .setPosition(10, 105)
  .setSize(255, 15);


}
void draw()
{
  background(150, 150, 150);
  fill(0, 255, 0);
  textFont(font);
  text("LED Strip Control", 10, 20);
  fill(rt,gt,bt);
  rect(305, 60, 55, 55, 7);
}

void off()
{
  println("Off");
  port.write('o');
}

void send()
{
  port.write('s');
  port.write(rt);
  port.write(gt);
  port.write(bt);
}
