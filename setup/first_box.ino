void first_box()
{
  int flag = 0;               //Flag set to 0 in order to help count the number of intersections
  int orientation = 1;        //Front of the car facing north

  //**********************************************************
  //              GOES FROM POINT A TO POINT B 
  //**********************************************************
  while (flag < 4)    // drives past 4 intersections
  {

    straight_line(orientation);
    if (analogRead(linha_D1) < limbo)   //Right sensor detecting black
    {
      while (analogRead(linha_D1) < limbo)
      {
        straight_line(orientation);     
      }
      Serial.print("\n Ultrapassou Interseção");
      Serial.print(flag);
      flag++;       //After right sensor stops detecting black - counts 1 intersection
    }
  }

  Serial.print("\n Caminho AB percorrido");
  pause();


  //************************************
  //  Correct position and orientation
  //************************************

  calibrate_pickup(orientation);
  Serial.print("\n Calibração terminada");


  // **********************************************************
  //                    PICKS UP FIRST BOX
  // **********************************************************

  // //Repeats until it correctly picks up the box
  while(digitalRead(BUTTON_F) == 1)
  {
    int count = 0;
    //Drives straight ahead to try and grab box 
    while(digitalRead(BUTTON_F) == 1 && count < 100 )
    {
      frente();
      delay(10);
      count++;

    }
    pause();

    //Reverses 
    while(analogRead(linha_F3) > limbo)
    {
      tras();
    }
    pause();
  }

  Serial.print("\n Primeira caixa coletada");


  //**********************************************************
  //                 ROTATES 90º (Clockwise)
  //**********************************************************

  // //ROTATE 90º (clockwise)
  // while((analogRead(linha_E2) > limbo && analogRead(linha_D2) > limbo))
  // {
  //   horario();
  // }
  // pause();


  // //GETS BACK ON THE TRACK 
  // while(analogRead(linha_T2) > limbo && analogRead(linha_F2) > limbo)
  // {
  //   esquerda();
  // }
  // pause();


  //**********************************************************

    //                 Correct position
    //                 Correct orientation

  //**********************************************************
}