/* Callibration links:
 *  MQ135: https://hackaday.io/project/3475-sniffing-trinket/log/12363-mq135-arduino-library
 *  MICCS5524: https://cdn-learn.adafruit.com/downloads/pdf/adafruit-mics5524-gas-sensor-breakout.pdf 
 */

// LIBRARIES
#include <DHT.h>;
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;

// DEFINITIONS and 
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

// DECLERATIONS
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int multiGasReading;
int alcoholGasReading;
int check;
int humidity;
int temperature;

  
void setup() {
  // INITIALIZATIONS
  Serial.begin(9600);
  dht.begin();
  lcd.begin(20,4);
  lcd.setBacklight(50); // from 0 to 255
}

void loop() {
  // READINGS
  multiGasReading = analogRead(A0);
  alcoholGasReading = analogRead(A1);
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // LCD-ING
  lcd.setCursor(0, 0);
  lcd.println("Purity Sensor #1");
  lcd.setCursor(7, 1);
  lcd.println(multiGasReading);
  lcd.setCursor(9,1);
  lcd.println("         ");
  delay(1500);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.println("Purity Sensor #2");
  lcd.setCursor(7, 1);
  lcd.print(alcoholGasReading);
  lcd.setCursor(9,1);
  lcd.println("         ");
  delay(1500);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.println("   Temperature    ");
  lcd.setCursor(7, 1);
  lcd.println(temperature);
  lcd.setCursor(9,1);
  lcd.println("c        ");
  delay(1500);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.println("    Humidity     ");
  lcd.setCursor(7, 1);
  lcd.println(humidity);
  lcd.setCursor(9,1);
  lcd.println("%         ");
  delay(1500);
  lcd.clear(); 
   
  // PRINTING
  // Serial.println("Multi Gas Reading: %s \n Alcohol Gas Reading: %s", multiGasReading, alcoholGasReading);
  Serial.println("Multi Gas Reading:");
  Serial.println(multiGasReading);
  Serial.println("Alcohol Gas Reading:");
  Serial.println(alcoholGasReading);
  Serial.println("Temperature Reading:");
  Serial.println(temperature);
  Serial.println("Humidity Reading");
  Serial.println(humidity);
  Serial.println("\n");
}
