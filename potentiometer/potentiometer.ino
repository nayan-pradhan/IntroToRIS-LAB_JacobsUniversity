void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0); // read the input on analog pin 0:
  float voltage = sensorValue*(5.0/1023.0); // Convert the analog reading (from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage);
}
