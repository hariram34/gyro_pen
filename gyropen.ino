#include <I2Cdev.h>
#include <SoftwareSerial.h>
#include <MPU6050.h>
char data [50];
//int button = 8;
int click_status;

//const int rxpin = 6, txpin = 7;
//SoftwareSerial bluetooth(rxpin, txpin);

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;


void setup() {
 // bluetooth.begin(38400);
  pinMode(button, INPUT_PULLUP);
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  //vx = (gy+100)/200;  
  //vy = -(gz-100)/200; 

//click_status = digitalRead(button);
click_status = 0;

sprintf (data, "%d,%d,%d,%d", gx, gy,gz, click_status);
//bluetooth.println(data);
delay(20);
//bluetooth.flush();
}
