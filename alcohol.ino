#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// --- Pin Definitions ---
const int mq3Pin = A0;      // MQ3 Sensor connected to Analog Pin A0
const int buttonPin = 2;    // Push button on Pin 2
const int buzzerPin = 8;    // Buzzer on Pin 8
const int servoPin = 9;     // Servo Motor on PWM Pin 9

// --- Constants & Variables ---
const int threshold = 400;  // Sensitivity threshold (adjust based on testing)
int motorPos = 0;           // Current position of the servo (0-180)
bool engineRunning = false;

// Initialize LCD (Address 0x27 or 0x3F are common)
LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo myServo;

void setup() {
  pinMode(mq3Pin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Uses internal resistor, wire button to GND
  pinMode(buzzerPin, OUTPUT);
  
  myServo.attach(servoPin);
  myServo.write(0); // Start at 0 degrees
  
  lcd.init();
  lcd.backlight();
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(mq3Pin);
  bool buttonPressed = digitalRead(buttonPin) == LOW;

  // Check for Alcohol/Smoke first (Safety Priority)
  if (sensorValue > threshold) {
    stopEngine("Alcohol/Smoke!");
  } 
  // Start engine if button is pressed and no alcohol detected
  else if (buttonPressed && !engineRunning) {
    startEngine();
  }

  // Display status when running normally
  if (engineRunning && sensorValue <= threshold) {
    lcd.setCursor(0, 0);
    lcd.print("Engine: Running ");
    lcd.setCursor(0, 1);
    lcd.print("Air: Clean      ");
  }
}

// Function to gradually start the motor
void startEngine() {
  lcd.clear();
  lcd.print("Starting...");
  for (motorPos = 0; motorPos <= 180; motorPos += 1) {
    myServo.write(motorPos);
    delay(20); // Controls the speed of "gradual" start
  }
  engineRunning = true;
}

// Function to gradually stop and alert
void stopEngine(String reason) {
  if (engineRunning) {
    lcd.clear();
    lcd.print(reason);
    digitalWrite(buzzerPin, HIGH);
    
    // Gradual stop
    for (motorPos = 180; motorPos >= 0; motorPos -= 1) {
      myServo.write(motorPos);
      delay(15);
    }
    
    digitalWrite(buzzerPin, LOW);
    engineRunning = false;
    
    lcd.setCursor(0, 1);
    lcd.print("Engine Stopped ");
    delay(3000); // Pause to show the message
  }
}
