#include <LiquidCrystal.h>

// initialize LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

const int thermistorPin = A0; 

void setup() {
  Serial.begin(9600); // Start serial monitor
  lcd.begin(16, 2);

  lcd.print("Place finger on");
  lcd.setCursor(0, 1);
  lcd.print("sensor...");
  // NO lcd.clear() here! We want it to stay until finger detected
}

void loop() {
  int sensorValue = analogRead(thermistorPin);
  Serial.println(sensorValue);  // For monitoring readings

  if (sensorValue > 500) { // Adjust if needed
    lcd.clear();
    lcd.print("Analyzing");
    
    for (int i = 0; i < 6; i++) { // 6 dots instead of 3
      delay(500); // 500ms delay per dot -> total ~3 seconds
      lcd.print(".");
    }
    
    lcd.clear();
    lcd.print("MATCH FOUND!");
    delay(2000);
    lcd.clear();
    lcd.print("Prom with me?");
    
    while (true); // Stop here after asking
  }
}
