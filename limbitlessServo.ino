
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position 
int incomingByte = 0;
String read_string = "";
String exponent = "";
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on p`in 9 to the servo object 
  myservo.write(0);
} 

void loop() 
{ 

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    int trueByte = int(incomingByte);

    if (trueByte == 1){
      for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
      }
      Serial.end();
      delay(5000);
      Serial.begin(9600); 
    }
    myservo.write(0);



  } 
}








