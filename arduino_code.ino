#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int leftClickIR = 8;
int rightClickIR = 9;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  pinMode(leftClickIR, INPUT);
  pinMode(rightClickIR, INPUT);
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Simplify movement values
  int xMove = ax / 1000;
  int yMove = ay / 1000;

  // Read IR sensors
  int leftClick = digitalRead(leftClickIR);
  int rightClick = digitalRead(rightClickIR);

  // Send data as comma-separated string
  Serial.print(xMove);
  Serial.print(",");
  Serial.print(yMove);
  Serial.print(",");
  Serial.print(leftClick);
  Serial.print(",");
  Serial.println(rightClick);

  delay(50); // adjust responsiveness
}
