int potPin = 0;
int posMotorPin = 3;
int negMotorPin = 5;

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
  // 0-5 V as an integer between 0 and 1023)  
  int potReading = analogRead(potPin);
  
  // Convert the 0-1023 potentiometer reading to a value between -255 and 255
  // (255 is the Arduino max PWM duty cycle. Positive values will drive the
  // motor in one direction, negative values will drive it the other)
  // (Consequently, 0 motor speed will be directly in between 0-1023)
  int outputSignal = map(potreading, 0, 1023, -255, 255);
  
  // Print the readings to the serial monitor so we can see what's going on
  Serial.print("Pot reading: ");
  Serial.print(potReading);
  Serial.print("\tOutput signal: ");
  Serial.println(outputSignal);
  
  // If the output signal is a positive value, send the signal through
  // the output pin that handles positive values
  if(correctedReading >= 0){
    analogWrite(posMotorPin, outputSignal);
  }
  // If the output signal is a negative value, send the singal through
  // the output pin that handles negative values
  else{
    outputSignal = abs(outputSignal);
    analogWrite(negMotorPin, outputSignal);
  }  
}
