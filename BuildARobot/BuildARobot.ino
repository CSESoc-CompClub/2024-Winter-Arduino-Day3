// Declare your constants here!
// --- pin names ---

// --- variables ---

// Setup your variables here!
void setup()
{

}

// Implement the functions below to complete the stages!
void loop()
{
    // --- stage 1 ---
    ledControl();
    statsCap();

    // --- stage 2 ---
    statsDrain();

    // --- stage 3 ---
    recharge();

    // --- stage 4 ---
    detectPerson();

    // --- stage 5 ---
    aliveCheck();

    // --- challenge ---
    lightSequence();
  }
}

void ledControl() {
  // Stage 1 TODO 
  // Controls the brightness of the LEDs based on the robot's stats
}

void statsCap() {
  // Stage 1 TODO
  // Caps the stats at 100
}

void statsDrain() {
  // Stage 2 TODO
  // Drains the energy and happiness stats every few seconds
}

void recharge() {
  // Stage 3 TODO
  // Spins the motor and increases the energy stat
}

void detectObject() {
  // Stage 4 TODO
  // If the IR sensor detects an obstacle, increase the happiness stat
}

void aliveCheck() {
  // Stage 5 TODO
  // Kills the robot if its happiness or energy reaches 0
}

void lightSequence() {
  // Challenge TODO
  /* 
    Have the happiness LED flash a random number of times.
    You have 5 seconds to press the remaining button the correct number of times.
    Complete 5 rounds to win. Any mistake results in a failure. 
    Reward for succeeding is up to you. Consequence for failing is also up to you.
  */

}

