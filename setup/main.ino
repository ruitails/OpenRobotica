void loop()
{
  int orientation = 1;
  straight_line(orientation);

  first_box();

  Serial.print("\n Stopping....");
  while (true)
  {
    stop();
  }
}



  // Test code:

  // Serial.print("\n Sensor 1 = ");
  // Serial.print(digitalRead(BUTTON_F));
  // Serial.print(" | ");

  // delay(2000);
  // }