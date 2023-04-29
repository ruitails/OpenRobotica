//PATH A_B
void path_AB()
{
  int orientation = 1, flag = 0;
  //**********************************************************
  //              GOES FROM POINT A TO POINT B 
  //**********************************************************
  while (flag < 4)    // drives past 4 intersections
  {
    straight_line(orientation);
    if (analogRead(linha_D1) < limbo)
    {
      while (analogRead(linha_D1) < limbo){
        straight_line(orientation); }

      //Prints
      Serial.print("\n Ultrapassou Interseção");
      Serial.print(flag);

      //After right sensor stops detecting black - counts 1 intersection
      flag++;       
      pause();
      if (flag < 3){
        frente();
        delay(500);
      }
    }
  }

  Serial.print("\n Caminho AB percorrido");
  pause();
}


//PATH B_C
void path_BC()
{
  int orientation = 1, flag = 0;

  frente();
  delay(500);

  while (flag < 2)    // drives past 2 intersections
  {
    straight_line(orientation);
    if (analogRead(linha_E1) < limbo)
    {
      while (analogRead(linha_E1) < limbo){
        straight_line(orientation); 
      }
      flag++;
      stop();
    }
    
  }

  while (analogRead(linha_D1) > limbo)
  {
    straight_line(orientation);
  }

  stop();

  Serial.print("\n Caminho BC percorrido");
  pause();
}

//PATH C_F
void path_CF() 
{
  int orientation = 1, flag = 0;

  // calibrate_axis_xy(orientation);

  frente();
  delay(500);


  while (flag < 3)    // drives past 4 intersections
  {
    straight_line(orientation);
    if (analogRead(linha_E3) < limbo)
    {
      while (analogRead(linha_E3) < limbo){
        straight_line(orientation); }

      flag++;       
      pause();
    }
  }
}


//PATH F_E
void path_FE()
{
  int orientation = 1, flag = 0;

  while (flag < 4)    // drives past 4 intersections
  {
    straight_line(orientation);
    if (analogRead(linha_D1) < limbo)
    {
      while (analogRead(linha_D1) < limbo){
        straight_line(orientation); }

      flag++;       
      pause();
    }
  }
}