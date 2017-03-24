const int sensorPin = 0;
const float baselineTemp = 26.0;// a pair of useful constants

void setup () {
  Serial.begin(9600); // opens a serial port
  
  for(int pinNumber = 2; pinNumber<5; pinNumber++) { 
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal); // send the temp sensor values to the serial monitor
 
  float voltage = (sensorVal/1024.0) * 5.0;// convert the ADC sensor reading to voltage
  
  Serial.print (", Volts: ");  
  Serial.print(voltage); // send converted readings to serial monitor
  
  float temperature = (voltage - .5) * 100;
 
  Serial.print (", degrees C: ");
  // convert the voltage temperature in degrees
  Serial.println(temperature);
  
  if(temperature < baselineTemp+2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
  
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
  
  }else if(temperature >= baselineTemp+6){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
  }
  delay(1);
}
