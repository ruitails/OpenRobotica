void loop()
{ 
  int orientation = 1;

  first_box();

  path_BC();

  rotate(orientation);

  path_CF();

  while (true){stop();}  
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