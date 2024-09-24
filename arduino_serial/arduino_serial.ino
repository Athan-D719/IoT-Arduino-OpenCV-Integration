#include <Servo.h>
Servo servoMotor1;
Servo servoMotor2;
Servo servoMotor3;
int incomingByte = 0; // for incoming serial data

void setup() {
   Serial.begin(9600);
  servoMotor1.attach(8);
  servoMotor2.attach(9);
  servoMotor3.attach(10);
  servoMotor1.write(100); //143
  servoMotor2.write(130);
  servoMotor3.write(130);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(4000);
}

void loop() {
  // send data only when you receive data:
  if (Serial.read() == 'f') { //Serial.available() > 0 && wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
    // read the incoming byte:
//    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(Serial.read());
    digitalWrite(LED_BUILTIN, HIGH);

    //CLICK
    servoMotor1.write(180); 
    delay(500);
    servoMotor1.write(100);
    delay(3000);
    servoMotor1.write(180); 
    delay(500);
    servoMotor1.write(100);
    delay(4000);
    
    //CTRL + W
    
    servoMotor2.write(150);
    delay(500);
    servoMotor3.write(150);
    delay(500);
    servoMotor2.write(130);
    servoMotor3.write(130);
    //W
    delay(3000); 
    
    //CLICK
    servoMotor1.write(180); 
    delay(500);
    servoMotor1.write(100);
    delay(2500);
    digitalWrite(LED_BUILTIN, LOW);

    
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    }
}
