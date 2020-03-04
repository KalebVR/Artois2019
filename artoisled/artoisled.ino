#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_NeoPixel.h>
Adafruit_MMA8451 mma = Adafruit_MMA8451();
#define PIN 5 
#define NUMPIXELS 160 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 0 
void setup(void) {
pixels.begin(); 
Serial.begin(9600);
Serial.println("Adafruit MMA8451 test!");
  if (! mma.begin()) {
    Serial.println("Couldnt start");
     while (1);
  }
    Serial.println("MMA8451 found!");
    mma.setRange(MMA8451_RANGE_8_G);
    Serial.print("Range = "); Serial.print(8 << mma.getRange());  
    Serial.println("G");
}
void loop() {
  mma.read(); 
  Serial.print("X:\t");
  Serial.print(mma.x); 
  Serial.print("\tY:\t"); 
  Serial.print(mma.y); 
  Serial.print("\tZ:\t"); 
  Serial.print(mma.z); 
  Serial.println();
  sensors_event_t event; 
  mma.getEvent(&event);
  Serial.print("X: \t"); 
  Serial.print(event.acceleration.x); 
  Serial.print("\t");
  Serial.print("Y: \t"); 
  Serial.print(event.acceleration.y); 
  Serial.print("\t");
  Serial.print("Z: \t"); 
  Serial.print(event.acceleration.z); 
  Serial.print("\t");
for(int i=0; i<NUMPIXELS; i++) {
  if(mma.x>0&&mma.y>0&&mma.z>9){ 
    pixels.setPixelColor(i, pixels.Color(150, 150, 0));
  } //
  else if(mma.x>0&&mma.y>0&&mma.z<0){
    pixels.setPixelColor(i, pixels.Color(50, 50, 50));
  }
  else if (mma.x>0&&mma.y<0&&mma.z<0){
    pixels.setPixelColor(i, pixels.Color(50, 50, 50)); 
  }
  else if(mma.x>0&&mma.y<0&&mma.z>0){
    pixels.setPixelColor(i, pixels.Color(255, 255, 0));
  }
 else if(mma.x<0&&mma.y<0&&mma.z<0){
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  else if(mma.x<0&&mma.y>0&&mma.z<0){ //
    pixels.setPixelColor(i, pixels.Color(150, 150, 0));
  } //
  else if(mma.x<0&&mma.y>0&&mma.z>0){ //
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  else if(mma.x<0&&mma.y<0&&mma.z>0){
    pixels.setPixelColor(i, pixels.Color(50, 50, 50)); 
  }
  else{
    pixels.setPixelColor(i, pixels.Color(150, 150, 0));
  }
  }
    pixels.show();  
    delay(500); 
}
 
