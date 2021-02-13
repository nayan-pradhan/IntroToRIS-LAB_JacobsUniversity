/* Button
Turns on and off a light emitting diode(LED) connected to digital
pin 13, when pressing a pushbutton attached to pin 2. */

#define LED_BUILTIN 13
const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;

void setup(){
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); // init led pin as input
  pinMode(LED_BUILTIN, OUTPUT); // init led pin as output
}

void loop(){
  buttonState = digitalRead(buttonPin); // read state of pushbotton value
  Serial.print(buttonState);
  digitalWrite(LED_BUILTIN, LOW);
  if (buttonState == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  
}
