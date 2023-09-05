#include <SoftwareSerial.h>
SoftwareSerial btSerial(10, 11);
int buttonPin = 3;
int presssensor_reading = A0;
int P_value = 0;
bool buttonPressed = false;
 int Sensor_Value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 btSerial.begin(9600);
   btSerial.println("Jet ski lol");

}

void loop() {
    // put your main code here, to run repeatedly:
  Sensor_Value = analogRead(presssensor_reading );
        btSerial.println("Below is analog sensor Value");
    btSerial.println(Sensor_Value);
    delay(2000);
  if( digitalRead(buttonPin) == HIGH &&  buttonPressed == false) { 
    buttonPressed = true; 
    btSerial.println("Has been pressed");
    btSerial.println(buttonPressed);
  }
  else {
     btSerial.println("Has not been pressed");
  }
  if (buttonPressed == true) {
     P_value = analogRead (presssensor_reading); 
      btSerial.println(buttonPressed);
  if(P_value > 100){
      btSerial.println("Has been pressed with force sensor");
      btSerial.println(Sensor_Value); 
      delay(2000);
       buttonPressed = false;
   }
  }
  if(buttonPressed == false && P_value > 100){
    btSerial.println("Precaution Alert:");
    btSerial.println("No button detected");
    btSerial.println("Force detected");
     delay(2000);
  }
}
