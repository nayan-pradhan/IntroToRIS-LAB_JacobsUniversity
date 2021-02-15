int TMP36= A0; // The middle lead is connected to analog-in 0. 
int temperature= 0;
int wait_ms= 20; // wait time betweem measurements in millisec. 
#define NR_SAMPLES 10
int samples[NR_SAMPLES]; // array of samples

void setup(){ 
  Serial.begin(9600);
}

void loop(){
  float sum= 0.0;
  for (int i=0; i< NR_SAMPLES; ++i){
    // map values from range [0, 410] to [-50, 150]
    samples[i]= map(analogRead(TMP36), 0, 410, -50, 150); 
    sum += samples[i];
    delay(wait_ms);
  }
  float mean= sum/NR_SAMPLES;
  float sum_square_deviation= 0.0; 
  for (int i=0; i< NR_SAMPLES; ++i){
    sum_square_deviation += (samples[i] - mean)*(samples[i] - mean); 
  }
  float standard_deviation= sqrt(sum_square_deviation/NR_SAMPLES); 
  Serial.print("mean: ");
  Serial.print(mean, 3);
  Serial.print(" C, \t std: "); Serial.println(standard_deviation);
}
