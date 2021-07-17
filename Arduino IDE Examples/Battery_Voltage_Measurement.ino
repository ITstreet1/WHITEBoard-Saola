/* Small modification of Sparkfun example
 * Author Dejan Petrovic
 * 7/17/2021
 * v1.0
*/
#define VBATPIN A0
void setup() {
  Serial.begin(9600);
}
void loop() {
    float measuredvbat = analogRead(VBATPIN);
    Serial.print("VBat: " ); 
    Serial.println(measuredvbat);
    measuredvbat *= 2;    // we divided by 2, so multiply back
    measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
    measuredvbat /= 4095; // convert to voltage, 12-bit resolution
    Serial.print("VBat: " ); 
    Serial.println(measuredvbat);
    delay(1000);
}
