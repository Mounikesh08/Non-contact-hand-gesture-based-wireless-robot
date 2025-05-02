#include <RF24.h>    // Library for RF communication
#include <Servo.h>   // Library for servo control

// Initialize RF24
RF24 radio(7, 8); // CE, CSN pins
const byte address[6] = "00001"; // Communication address

// Motor pins for navigation platform (L293D motor driver)
const int motor1 = 2; // Motor 1 forward
const int motor2 = 3; // Motor 1 backward
const int motor3 = 4; // Motor 2 forward
const int motor4 = 5; // Motor 2 backward

// Servo pins for robotic arm
const int pickServoPin = 6;  // Gripper pick action
const int placeServoPin = 7; // Gripper place action
const int upServoPin = 8;    // Arm up movement
const int downServoPin = 9;  // Arm down movement

// Servo objects
Servo pickServo;
Servo placeServo;
Servo upServo;
Servo downServo;

// Variable to track command validity
int dataCheck = 0;

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);

  // Initialize RF module
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN); // Set power level to minimum
  radio.startListening(); // Set as receiver

  // Set motor pins as outputs
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  // Attach servos to their respective pins
  pickServo.attach(pickServoPin);
  placeServo.attach(placeServoPin);
  upServo.attach(upServoPin);
  downServo.attach(downServoPin);

  // Initialize servos to neutral position
  pickServo.write(90);
  placeServo.write(90);
  upServo.write(90);
  downServo.write(90);

  // Ensure all motors are stopped initially
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}

void loop() {
  if (radio.available()) {
    char data;
    radio.read(&data, sizeof(data)); // Read incoming command
    Serial.print("Received: ");
    Serial.println(data);

    dataCheck = 1; // Mark command as received

    // Navigation platform control (DC motors via L293D)
    if (data == '3') { // Forward movement
      digitalWrite(motor1, HIGH); // Motor 1 forward
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, HIGH); // Motor 2 forward
      digitalWrite(motor4, LOW);
      delay(1500); // Move for 1.5 seconds
      digitalWrite(motor1, LOW); // Stop motors
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, LOW);
    } 
    else if (data == '4') { // Backward movement
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, HIGH); // Motor 1 backward
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, HIGH); // Motor 2 backward
      delay(1500); // Move for 1.5 seconds
      digitalWrite(motor1, LOW); // Stop motors
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, LOW);
    } 
    else if (data == '1') { // Right turn
      digitalWrite(motor1, HIGH); // Motor 1 forward
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, HIGH); // Motor 2 backward
      delay(500); // Turn for 0.5 seconds
      digitalWrite(motor1, LOW); // Stop motors
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, LOW);
    } 
    else if (data == '2') { // Left turn
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, HIGH); // Motor 1 backward
      digitalWrite(motor3, HIGH); // Motor 2 forward
      digitalWrite(motor4, LOW);
      delay(500); // Turn for 0.5 seconds
      digitalWrite(motor1, LOW); // Stop motors
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, LOW);
    } 
    // Robotic arm control (servo motors)
    else if (data == '5') { // Pick action
      pickServo.write(120); // Move gripper to pick position
      delay(1000); // Hold for 1 second
      pickServo.write(90); // Return to neutral
      placeServo.write(90); // Ensure place servo is neutral
    } 
    else if (data == '6') { // Place action
      placeServo.write(60); // Move gripper to place position
      delay(1000); // Hold for 1 second
      placeServo.write(90); // Return to neutral
      pickServo.write(90); // Ensure pick servo is neutral
    } 
    else if (data == '7') { // Arm down
      downServo.write(120); // Move arm down
      delay(1000); // Hold for 1 second
      downServo.write(90); // Return to neutral
      upServo.write(90); // Ensure up servo is neutral
    } 
    else if (data == '8') { // Arm up
      upServo.write(60); // Move arm up
      delay(1000); // Hold for 1 second
      upServo.write(90); // Return to neutral
      downServo.write(90); // Ensure down servo is neutral
    } 
    else { // Invalid command
      dataCheck = 0;
      Serial.println("Invalid Command. Please Try Again !!!");
      Serial.println();
      
      // Stop all motors and reset servos
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, LOW);
      pickServo.write(90);
      placeServo.write(90);
      upServo.write(90);
      downServo.write(90);
      
      delay(1500); // Wait before checking next command
    }
  } else {
    // No data received, ensure motors are stopped
    if (dataCheck == 0) {
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(motor3, LOW);
      digitalWrite(motor4, LOW);
    }
  }
}

      else if(data == '7')
  {
    DataCheck = 1; 
  digitalWrite(up, HIGH);
  digitalWrite(down, LOW);
  delay(1000);
  digitalWrite(up, LOW);
  digitalWrite(down, LOW);
  
}

        else if(data == '8')
  {
    DataCheck = 1; 
  digitalWrite(up, LOW);
  digitalWrite(down,HIGH);
  delay(1000);
  digitalWrite(up, LOW);
  digitalWrite(down, LOW);
  
  
}


  else if(DataCheck == 0)
  {
  Serial.println("Invalid Command. Please Try Again !!! ");
    Serial.println();
    DataCheck = 0;
    delay(1500);
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor1, LOW);
  }
}
}
