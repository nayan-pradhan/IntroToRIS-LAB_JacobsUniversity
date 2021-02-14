#include <Servo.h>
Servo s; // create servo object

void setup(){
  s.attach(8); // control signal on pin 8
}

void loop() {
  s.write(0);
  delay(3000);
  s.write(45);
  delay(3000); 
  s.write(90);
  delay(3000); 
  s.write(135);
  delay(3000);  
  s.write(180);
  delay(3000);
}
