#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

#define NUMPIXELS 8
#define DELAYVAL 50
#define PIN 6
int totalColumns = 16;
int totalRows = 2;

LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);
Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
int sensorVal;
int trig=7;//
int echo=8;//
float distance;//
int i = 0;
int current_minutes = 0;
int previous_minuyes = 0;
unsigned long time;
signed short minutes;
int stay_time = 0;
int current_time;
int previous_time;


void pixelClear(){
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, 0, 0, 0);
    pixels.show();
    Serial.println("1");
    delay(DELAYVAL);
  }
}

void Neopixel() {
  pixels.clear();
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, 255, 0, 255);
    pixels.show();
    Serial.println("1");
    delay(DELAYVAL);
  }

}

void testTimer() {
  time = millis();
  minutes = time/60000;
}

void testDistance(){
  digitalWrite(trig,LOW);
   delayMicroseconds(2);//Delay 2us, delay() is milliseconds
   digitalWrite(trig,HIGH);
   delayMicroseconds(10);//Delay to form a 10us high level signal
   digitalWrite(trig,LOW);
   distance=pulseIn(echo,HIGH)/58.3;
}


void setup() {
  Serial.begin(9600);
  pixels.begin();
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  lcd.init(); 
  lcd.backlight(); // use to turn on and turn off LCD back light
}



void lcd1(){
  stay_time = current_time - previous_time; 
  if (sensorVal>600 || sensorVal <400){
  lcd.setCursor(0, 0);
  lcd.print("Your voice is higher than");
  lcd.setCursor(0,1);
  lcd.print("50  DB, be quiet please.");//need to change according to the number
  delay(2000);
  lcd.clear();

  }
  if ((stay_time < 60) && (stay_time >= 0)){
  lcd.setCursor(0, 0);
  lcd.print("You have studied for:");
  lcd.setCursor(0,1);
  lcd.print(stay_time);
  lcd.print("  minutes");
  delay(1000);
  lcd.clear();
  }
  if(stay_time >= 60){
  lcd.setCursor(0, 0);
  lcd.print("You have studied over 60");
  lcd.setCursor(0,1);
  lcd.print("minutes,please take a break.");
  delay(1000);
  lcd.clear();    
  }
  if (stay_time < 0){
  lcd.setCursor(0, 0);
  lcd.print("You have rest");
  lcd.setCursor(0,1);
  lcd.print(-stay_time);
  lcd.print("  minutes");
  delay(1000);
  lcd.clear();
  }
}

void loop() {
  sensorVal = analogRead(A0);
  Serial.println(sensorVal);
  delay(100);
  testDistance();
  //Serial.println("diatance:");
  //Serial.println(distance);
  lcd1();

if (sensorVal>600 || sensorVal <450){
  Neopixel();
  delay(500);
  pixelClear();
}
  if (distance < 40 || distance > 1000 ){
    testTimer();
    stay_time = current_time - previous_time;
    //Serial.println("have stay:"); 
    //Serial.println(stay_time);
    
    current_time = minutes;
}
    if ((40<= distance) && (distance<=1000) ){
    testTimer();
    //stay_time = current_time - previous_time; 
    //Serial.println(stay_time);
    
    previous_time = minutes;
  }
  //Serial.println("total:");
  //Serial.println(minutes);
  //delay(2000);
  //Serial.println(distance);
  delay(100);
}




