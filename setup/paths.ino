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
  int orientation = 2, flag = 0;

  while (flag < 2)    // drives past 2 intersections
  {
    straight_line(1);
    if (analogRead(linha_E1) < limbo)
    {
      while (analogRead(linha_E1) < limbo){
        straight_line(1); 
      }
    }
  }

  while (analogRead(linha_D1) > limbo)
  {
    straight_line(1);
  }

  Serial.print("\n Caminho BC percorrido");
  pause();
}

//PATH C_F
void path_CF() {
  int flag = 0;         //Flag set to 0 in order to help count the number of intersections
  int orientation = 1;  //Front of the car facing north
  int flag2 = 0;

  //**
  //              GOES FROM POINT C TO POINT F
  //**
  while (flag < 3)  // drives past 4 intersections
  {

    straight_line(orientation);
    if (analogRead(linha_D1) < limbo)  //Right sensor detecting black
    {
      while (analogRead(linha_D1) < limbo) {
        straight_line(orientation);
      }
      Serial.print("\n Ultrapassou Interseção");
      Serial.print(flag);
      if (flag2 == 0)
        delay(250);
      flag++;  //After right sensor stops detecting black - counts 1 intersection
      flag2++;
      pause();
      frente();
      delay(500);
    }
  }

  Serial.print("\n Caminho CF percorrido");
  pause();
}