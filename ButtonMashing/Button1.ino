// Code for the Button Bonus Task 1

// Declare the Variables for the Pins used
int buttonPin = 2;
int ledPin = 13;

// Store the buttonState
int buttonState = 0;

void setup() {
  // Starting Serial input/output to output stuff if we want to
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the state of the button (is it pressed or not?)
  buttonState = digitalRead(buttonPin);

  // Check if the pushbutton is pressed
  if (buttonState == HIGH) {
    // The Button is pressed -> turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // The button is not pressed -> turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
