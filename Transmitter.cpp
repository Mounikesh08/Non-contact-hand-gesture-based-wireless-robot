#include <Wire.h>
#include <MPU6050.h> // Library for MPU6050 accelerometer/gyroscope
#include <RF24.h>    // Library for RF communication

// Initialize MPU6050
MPU6050 mpu;

// Initialize RF24
RF24 radio(7, 8); // CE, CSN pins
const byte address[6] = "00001"; // Communication address

// Analog pins for accelerometer and push buttons
const int memsxPin = A0; // X-axis accelerometer (mapped from MPU6050)
const int memsyPin = A1; // Y-axis accelerometer (mapped from MPU6050)
const int pickPin = A2;  // Pick action button
const int placePin = A3; // Place action button
const int upPin = A4;    // Up movement button
const int downPin = A5;  // Down movement button

// Variable to track gesture detection
int keyCheck = 0;

// Accelerometer thresholds (adjusted for mapped values)
const int thresholdHigh = 400; // High threshold for gesture detection
const int thresholdLow = 330;  // Low threshold for gesture detection

// Push button threshold
const int buttonThreshold = 500;

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);

  // Initialize I2C for MPU6050
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1); // Halt if connection fails
  }

  // Initialize RF module
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); // Set power level to minimum
  radio.stopListening(); // Set as transmitter

  // Set pin modes for push buttons
  pinMode(memsxPin, INPUT);
  pinMode(memsyPin, INPUT);
  pinMode(pickPin, INPUT);
  pinMode(placePin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
}

void loop() {
  // Read accelerometer data from MPU6050
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Map accelerometer values to analog range (0-1023) for compatibility with appendix logic
  int memsx = map(ax, -17000, 17000, 0, 1023); // X-axis
  int memsy = map(ay, -17000, 17000, 0, 1023); // Y-axis

  // Read push button states
  int pick = analogRead(pickPin);
  int place = analogRead(placePin);
  int up = analogRead(upPin);
  int down = analogRead(downPin);

  // Reset keyCheck for each loop
  keyCheck = 0;

  // Gesture detection logic (mirroring appendix structure)
  if (memsx > thresholdHigh) {
    keyCheck = 1;
    Serial.print("1"); // Right movement
    radio.write("1", sizeof("1")); // Send via RF
  }
  else if (memsx < thresholdLow) {
    keyCheck = 1;
    Serial.print("2"); // Left movement
    radio.write("2", sizeof("2"));
  }
  else if (memsy > thresholdHigh) {
    keyCheck = 1;
    Serial.print("3"); // Forward movement
    radio.write("3", sizeof("3"));
  }
  else if (memsy < thresholdLow) {
    keyCheck = 1;
    Serial.print("4"); // Backward movement
    radio.write("4", sizeof("4"));
  }
  else if (pick > buttonThreshold) {
    keyCheck = 1;
    Serial.print("5"); // Pick action
    radio.write("5", sizeof("5"));
  }
  else if (place > buttonThreshold) {
    keyCheck = 1;
    Serial.print("6"); // Place action
    radio.write("6", sizeof("6"));
  }
  else if (down > buttonThreshold) {
    keyCheck = 1;
    Serial.print("7"); // Down movement
    radio.write("7", sizeof("7"));
  }
  else if (up > buttonThreshold) {
    keyCheck = 1;
    Serial.print("8"); // Up movement
    radio.write("8", sizeof("8"));
  }
  else if (keyCheck == 0) {
    Serial.print("idle"); // No gesture detected
    radio.write("0", sizeof("0")); // Send idle command
  }

  // Print newline for debugging clarity
  Serial.println();

  // Reset keyCheck for next iteration
  keyCheck = 0;

  // Delay for stability (matches appendix)
  delay(1000);
}
