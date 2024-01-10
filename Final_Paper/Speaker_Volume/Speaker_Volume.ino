void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int knobValue = analogRead(A0);
 
  float voltage = knobValue * (5.0/1023.0);
 
  Serial.print(knobValue);
 
  Serial.print("-");
 
  Serial.println(voltage);
 
  analogWrite(11, voltage);
 
  delay(1000);
}
