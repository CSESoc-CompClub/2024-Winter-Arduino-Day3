// Sample Solution for Bonus Task 2

// Initialise the variables for the pins
int buttonPin = 2;
int ledPin = 13;

// Variables for us
int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

unsigned long time = 0;           // the last time the output pin was toggled
unsigned long debounce = 200UL;   // the debounce time, increase if the output flickers

void setup()
{
  pinMode(buttonPin,  INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int reading = digitalRead(buttonPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH) {
      state = LOW;
    } else {
      state = HIGH;
    }
    time = millis();
  }

  digitalWrite(ledPin, state);
  previous = reading;
}