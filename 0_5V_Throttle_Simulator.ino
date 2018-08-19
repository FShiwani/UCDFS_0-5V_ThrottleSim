// Simplified 0-5V Throttle Simulator
// UCD Formula Student (UCDFS)
// Description: Outputs a PWM Voltage Level between 0-5V depending on potentiometer setting.
//              The potentiometer in this case is taking place of the physical pedal
// Target Platform: Arduino Nano
// Author: Fahd Shiwani

#define MAX_POTENTIOMETER_VALUE 1023
#define PWM_RESOLUTION 255

const int POTENTIOMETER_PIN = A0;
const int OUTPUT_PIN = 9;
float CURRENT_POTENTIOMETER_VALUE = 0;

void setup() {
  pinMode(POTENTIOMETER_PIN, INPUT); // defining potentiometer pin as input
  pinMode(OUTPUT_PIN, OUTPUT); // defining output voltage pin as output
  Serial.begin(9600); // starting serial communication

}

void loop() {
  // Read current potentiometer value
  CURRENT_POTENTIOMETER_VALUE = analogRead(POTENTIOMETER_PIN);

  // Print to serial monitor
  //Serial.println("Potentiometer Value is " + (String) CURRENT_POTENTIOMETER_VALUE);

  // Output corresponding 0-5V signal using PWM.
  analogWrite(OUTPUT_PIN, (CURRENT_POTENTIOMETER_VALUE/MAX_POTENTIOMETER_VALUE)*PWM_RESOLUTION);

}
