/* Code to control the mouse pointer
 * through the movement of the head
 * Change values at vx and vy (+300 and -100 in my case)
 * using the TEST code to make your project work.
 * 
 * Gabry295
 */

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>


MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

 // vx = (gx+300)/200;  // "+300" because the x axis of gyroscope give values about -350 while it's not moving. Change this value if you get something different using the TEST code, chacking if there are values far from zero.
 // vy = -(gz-100)/200; // same here about "-100"
 Serial.println("a/g:\t");
 Serial.print(ax); Serial.print("\t");
 Serial.print(ay); Serial.print("\t");
 Serial.print(az); Serial.print("\t");
 Serial.print(gx); Serial.print("\t");
 Serial.print(gy); Serial.print("\t");
 Serial.println(gz);
      

 
  delay(20);
}
