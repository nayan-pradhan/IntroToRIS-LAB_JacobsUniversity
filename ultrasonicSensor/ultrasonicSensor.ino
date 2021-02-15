const int trig = 7;
const int echo = 6;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig, HIGH); //send an impulse to trigger the sensor start the measurement
  delayMicroseconds(15); // minimum impulse width required by HC-RS4 sensor
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH); // waits until sensor outputs the result
  // result is encoded as the pulse width in microseconds
  // ’duration’ is the time it takes sound from the transmitter back to the receiver after it bounces off an obstacle

  const long vsound = 340; // m/s
  long dist = (duration/2L) * vsound/10000L; // 10000 is just the scaling factor to get the result in [cm]
  if (dist > 500L || dist < 2L){
    Serial.println("Invalid range!");
  }
  else{
    Serial.print(dist);
    Serial.println(" cm");
  }
  delay(1000);
}
