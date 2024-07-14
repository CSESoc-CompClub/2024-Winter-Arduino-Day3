// --- pin names ---
int eLed = 11; // energy led
int hLed = 10; // happiness led
int sensor = 3; // ir sensor
int enA = 6; // motor speed
int in1 = 5; // motor power
int in2 = 4; // motor spin direction
int eButton = 12; // energy button
int hButton = 2; // happiness button
int alive = true; // robot is alive

// --- variables ---
int happiness = 0; // happiness value
int energy = 0; // energy value
const long refreshInterval = 1000; // every 1 seconds (1000 ms)
unsigned long lastRefreshTime = 0; // last time stats were  updated

void setup()
{
  // --- debugging w serial ---
  Serial.begin(9600);
  Serial.println("Serial Working");
  
  // --- pin modes ---
  pinMode(eLed, OUTPUT);
  pinMode(hLed, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(eButton, INPUT);
  pinMode(hButton, INPUT);
  
  // --- initial variables  ---
  energy = 100;
  happiness = 100;
  
  // --- turn motors off ---
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop()
{
  // --- stage 5 ---
  if (alive) {
    // --- stage 1 ---
    ledControl();
    statsCap();

    // --- stage 2 ---
    statsDrain();

    // --- stage 3 ---
    recharge();

    // --- stage 4 ---
    detectObject();

    // --- stage 5 ---
    aliveCheck();

    // --- challenge ---
    lightSequence();

  } else {
    digitalWrite(eLed, LOW);
    digitalWrite(hLed, LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}

void ledControl() {
  analogWrite(eLed, (energy * 2.55));
  analogWrite(hLed, (happiness * 2.55));
}

void statsCap() {
  if (energy > 100) {
    energy = 100;
  }
  if (happiness > 100) {
    happiness = 100;
  }
}

void statsDrain() {
  unsigned long currentTime = millis();
  if (currentTime - lastRefreshTime >= refreshInterval) {
    lastRefreshTime = currentTime;
    if (energy > 0) {
      energy -= 1;
    }
    if (happiness > 0) {
      happiness -= 1;
    }
    Serial.println(String("Energy: ") + energy);
    Serial.println(String("Happiness: ") + happiness);
  }
}

// they can customise this to make the motor spin in various directions
void recharge() {
  int energyButton = digitalRead(eButton);
  int motorOn = digitalRead(motorPower);
  int motorDirection = digitalRead(motorSpin);

  // while the button is being held
  if (energyButton == HIGH) {
    energy += 1;
    Serial.println("Recharging...");
    controlMotors();
  }
}

void controlMotors() {
  analogWrite(enA, 255); //speed goes from 0 to 255, 255 is max speed
  // turn motors on (spins forward)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void detectObject() {
  int sensorStatus = digitalRead(sensor);
  if (sensorStatus == LOW) {
    happiness += 1;
    Serial.println("Object detected!");
  }
}

void aliveCheck() {
  if (energy == 0 || happiness == 0) {
    alive = false;
  }
}

void lightSequence() {
  /* Not actually arduino code but here's some pseudo code:
      1. use a temporary variable (numFlashes) to store how many times the light would flash in one round
      2. have my first for loop to loop from int i = 0; i < 5 (number of rounds)
      3. have the happiness LED flash numFlashes time
      4. have a timer count for 5 seconds (similar to task 2) for button input from hButton
      6. use an integer variable (count) to count the number of times digitalRead(hButton) == HIGH
      7a. if count == numFlashes, correct and move onto the next round until 5 rounds is done --> give reward (up to the student)
      7b. if count != numFlashes, incorrect and break out of the minigame --> apply penalty (also up to the student)
  */
  // (no clue if this approach works though)
}

