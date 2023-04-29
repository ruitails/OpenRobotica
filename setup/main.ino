void loop()
{ 
  int orientation = 1;

  first_box();
  path_BC();

  rotate(3);    //Rotates as if it was facing backwards
  pause();

  path_CF();
  
  calibrate_axis_x(orientation);

  while(analogRead(linha_F2) > limbo)
  {  
    anti();
  }

  path_FE();

  esquerda();
  delay(500);

  calibrate_axis_x(orientation);

  rotate(2);

  frente();
  delay(1000);

  stop();
  digitalWrite(MAGNET_F, LOW);

  tras();
  delay(500);

  while (true){stop();}
}