int potPin = 0;
int posMotorPin = 3;
int negMotorPin = 5;

void drive_motor(int reading){
  // Do the logic conversion of the potentiometer reading into output signals
  // that the motor circuit can use.
  
}

void setup(){
  // Set the pin mode for the PWM output pins to drive the motor  
  pinMode(posMotorPin, OUTPUT);
  pinMode(negMotorPin, OUTPUT);
  
  // Begin serial communication with the computer
  // (Not necessary for the system to work, just sp we can print the values on
  // screen and see what's happening)
  Serial.begin(9600);
}

void loop(){
  // Read the analog voltage from the potentiometer
  // (This will do an analog-to-digital conversion (ADC) with 10 bit
  // resolution, meaning the it stores a reads a voltage between
  // 0-5 V as an integer between 0 and 1024)  
  int potReading = analogRead(potPin);
  
  // Send that potentiometer reading to a function that will handle driving 
  // the motor
  drive_motor(potReading);
  
  // Print the potentiometer reading to the serial monitor so we can see
  // what's going on
  Serial.println(potReading);
}
