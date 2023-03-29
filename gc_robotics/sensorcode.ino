#include <Wire.h>

#include <Adafruit_Sensor.h> 

#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

void setup(void) 

{
  
}

void loop(void) 

{

   sensors_event_t event; 

   accel.getEvent(&event);

   Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");

   Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");

   Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");

   delay(100);

}
