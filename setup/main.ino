void loop()
{ 
  int orientation = 1;
  straight_line(orientation);

  first_box();
  second_box();

  Serial.print("\n Stopping....");
  while (true)
  {
    stop();
  }  

}


  // Serial.print("\n Sensor 1 = ");
  // Serial.print(analogRead(linha_D1));
  // Serial.print(" | ");
  // Serial.print("\n Sensor 2 = ");
  // Serial.print(analogRead(linha_D2));
  // Serial.print(" | ");
  // Serial.print("\n Sensor 3 = ");
  // Serial.print(analogRead(linha_D3));
  // Serial.print(" | ");

  // delay(2000);
  // }