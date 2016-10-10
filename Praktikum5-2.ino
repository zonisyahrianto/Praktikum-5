void setup() {
  Serial.begin(115200);

}

void loop() {
  Serial.write(0xF0);
  Serial.write(0x1F);
  Serial.write(0x2F);
  Serial.write(0xF3);
  Serial.write(0xF4);
  delay(2000);
}
