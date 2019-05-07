//Author:Rami Janini

//Description:
//Arduino glove for the blind

//Engineering Tips:
//Mount the ultrasonic sensor on the bottom of the glove
//Mount the arduino on the top of the glove

//Components:
//Ultrasonic sensor, buzzer, redLED, greenLED
//2018©


const int trigPin = 2;
const int echoPin = 4;
int buzzer = 6;
int redLED = 9;
int greenLED = 13;


void setup() { 
Serial.begin(9600);
pinMode(redLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(buzzer, OUTPUT);

}

 
void loop()

{
long duration, inches, cm, mm;
pinMode(trigPin, OUTPUT); 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2000); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(1000); 
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT); 
duration = pulseIn(echoPin, HIGH);

cm = microsecondsToCentimeters(duration);

Serial.print(cm);
Serial.print("cm ");
Serial.println("");




if (cm < 50){
  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(redLED,LOW);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(greenLED, LOW);
  
}








else if (cm > 50){
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(greenLED, HIGH);

  
}

}

long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}
