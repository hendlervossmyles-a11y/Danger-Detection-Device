// Pin Definitions
const int BUTTON_PIN = 2; // The Sabotage Freeze Button
const int GREEN_LED  = 4; // Represents normal software execution
const int RED_LED    = 5; // Represents a frozen software state
const int Buzzer     = 6; // Triggers Buzzer

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  // Start with normal operation
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  // Initalize Serial
  Serial.begin(9600);
}

void loop() {
  // 1. Simulate a normal blinking system clock/timer
  digitalWrite(GREEN_LED, HIGH);
  delay(10); // Only 10 miliseconds off to make light apear solid
  digitalWrite(GREEN_LED, LOW);
  delay(10);

  // 2. Check if the "Danger" button is pressed
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // Force a visual software freeze state
    digitalWrite(GREEN_LED, LOW); // Kill the normal process light
    digitalWrite(RED_LED, HIGH);  // Lock the Red error light ON
    digitalWrite(Buzzer, HIGH); // Start buzzer
    
    // TRAP THE ARDUINO IN AN INFINITE LOOP
    // The microcontroller is now entirely "frozen" 
    while(1) {
      Serial.print("DANGER!\n");
      delay(3000);
    }
  }
}