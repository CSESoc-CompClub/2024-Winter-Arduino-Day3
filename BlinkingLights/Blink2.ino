// This is the solution code for the First Bonus Task of
// Blinking and Fading Lights Question

void setup() {
  // Sets up the data transmission speed (baud-rate)
  // This is set at 9600 bits per second
  // Useful if you need to send information to/from
  // the arduino
  Serial.begin(9600);

  // Set the Builtin LED to Output (light)
  pinMode(LED_BUILTIN, OUTPUT);

  // Have the LED_BUILTIN start in an "LOW" state
  // This will keep the LED off
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait 1000 milliseconds (1 second) before continuing
  delay(1000);

  // Turn the LED off
  digitalWrite(LED_BUILTIN, LOW);

  // Wait 1000 milliseconds (1 second) before continuing
  delay(1000);

  // Turn the LED on
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait 2000 milliseconds (2 second) before continuing
  delay(2000);

  // Turn the LED off
  digitalWrite(LED_BUILTIN, LOW);

  // Wait 2000 milliseconds (2 seconds) before continuing
  delay(2000);

    // Turn the LED on
  digitalWrite(LED_BUILTIN, HIGH);

  // Wait 3000 milliseconds (3 second) before continuing
  delay(3000);

  // Turn the LED off
  digitalWrite(LED_BUILTIN, LOW);

  // Wait 3000 milliseconds (3 seconds) before continuing
  delay(3000);

  // When the Arduino reaches this block of code, it will
  // get stuck in the while loop and be unable to return to
  // the start of the loop function
  while (true) {
    // If you wanted to add some code inside, you could 
    // add a delay statement but it's not really necessary
    // delay(10000);
  }
}
