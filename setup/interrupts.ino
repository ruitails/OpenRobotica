void magnet_on_F() {
  digitalWrite(MAGNET_F, HIGH);
  // stop();
  // delay(2000);  
  // digitalWrite(BUTTON_F, LOW);
}

void magnet_on_E() {
  // digitalWrite(MAGNET_D, HIGH);
  digitalWrite(BUTTON_E, LOW);
}

void magnet_on_T() {
  digitalWrite(MAGNET_T, HIGH);
  // digitalWrite(BUTTON_T, LOW);
}

void magnet_on_D() {
  digitalWrite(MAGNET_E, HIGH);
  // digitalWrite(BUTTON_D, LOW);
}