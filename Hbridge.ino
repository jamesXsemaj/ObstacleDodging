const int toggleSwitch = 2; // Digital Pin 2 connects to the toggle switch
const int motorTerminal1 = 3; // Digital Pin 3 connects to motor terminal 1
const int motorTerminal2 = 4; // Digital Pin 4 connects to motor terminal 2
const int motorTerminal3 = 11; // Digital Pin 3 connects to motor terminal 1
const int motorTerminal4 = 12; // Digital Pin 4 connects to motor terminal 2
const int enablePin = 9; // Digital pin 9 connects to the enable pin 
const int motorPin = 6;// motor speed
int i=0;
void setup() {
pinMode(toggleSwitch, INPUT); //the toggle switch functions as an input 

//The rest of the pins function as outputs
pinMode(motorTerminal1, OUTPUT);
pinMode(motorTerminal2, OUTPUT);
pinMode(motorTerminal3, OUTPUT);
pinMode(motorTerminal4, OUTPUT);
pinMode(enablePin, OUTPUT);
pinMode(motorPin, OUTPUT);

digitalWrite(enablePin, HIGH);
}

void loop() {
  digitalWrite(toggleSwitch, HIGH);
digitalWrite(motorTerminal1, HIGH); //black  these logic levels create forward direction
digitalWrite(motorTerminal2, LOW); 
digitalWrite(motorTerminal3, HIGH); //red  these logic levels create forward direction
digitalWrite(motorTerminal4, LOW); 
//digitalWrite(motor1Terminal1, LOW); //turn motor on
  //digitalWrite(motor1Terminal2, HIGH);
  analogWrite(motorPin, 255);//set speed
}

