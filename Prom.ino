#include <LiquidCrystal.h>

// Initialize LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

const int thermistorPin = A0;
const int touchThreshold = 530; // bingo sweet spot
const int noTouchThreshold = 500; 
// Program state
enum State {
  WAITING_FOR_TOUCH,
  LOADING,
  SHOWING_INVITATION
};

State currentState = WAITING_FOR_TOUCH;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  // Show initial message
  displayWaitingMessage();
}

void loop() {
  int sensorValue = analogRead(thermistorPin);
  Serial.println(sensorValue); // For debugging
  
  switch (currentState) {
    case WAITING_FOR_TOUCH:
      if (sensorValue > touchThreshold) {
        // Confirm touch with multiple readings
        if (confirmTouch()) {
          currentState = LOADING;
          showLoadingAnimation();
        }
      }
      break;
      
    case LOADING:
      // Loading animation is handled in showLoadingAnimation()
      // After loading completes, state will be changed to SHOWING_INVITATION
      break;
      
    case SHOWING_INVITATION:
      // This state just keeps displaying the invitation
      // No specific code needed as we don't change from this state
      break;
  }
  
  delay(100); // Small delay to prevent reading too frequently
}

// Display the waiting message
void displayWaitingMessage() {
  lcd.clear();
  lcd.print("Place finger on");
  lcd.setCursor(0, 1);
  lcd.print("sensor...");
}

// Confirm the touch by taking multiple readings
bool confirmTouch() {
  int confirmations = 0;
  
  for (int i = 0; i < 5; i++) {
    delay(200);
    int value = analogRead(thermistorPin);
    Serial.print("Confirmation read: ");
    Serial.println(value);
    
    if (value > touchThreshold) {
      confirmations++;
    }
  }
  
  return (confirmations >= 4); // Return true if at least 4 out of 5 readings confirm touch
}

// Show the loading animation and then transition to invitation
void showLoadingAnimation() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Analyzing...");
  
  int percentages[] = {0, 20, 40, 60, 80, 100};
  
  for (int i = 0; i < 6; i++) {
    lcd.setCursor(0, 1);
    lcd.print("Progress: ");
    lcd.print(percentages[i]);
    lcd.print("%   ");
    delay(600);
  }
  
  // Show the final invitation
  lcd.clear();
  lcd.print("MATCH FOUND!");
  delay(2000);
  
  lcd.clear();
  lcd.print("Prom with me?");
  
  // Change state to invitation display
  currentState = SHOWING_INVITATION;
}
