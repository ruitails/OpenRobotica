void first_box()
{
  int flag = 0;               //Flag set to 0 in order to help count the number of intersections
  int orientation = 1;        //Front of the car facing north

  //**********************************************************
  //              GOES FROM POINT A TO POINT B 
  //**********************************************************
  while (flag < 4)    // ignores 4 intersections
  {

    straight_line(orientation);
    if (analogRead(linha_D1) < limbo)   //Right sensor detecting black
    {
      while (analogRead(linha_D1) < limbo)
      {
        straight_line(orientation);     
      }
      //pause();
      flag++;       //After right sensor stops detecting black - counts 1 intersection
    }
  }

  pause();

  //**********************************************************

    //                 Correct position
    //                 Correct orientation

  //**********************************************************


  // **********************************************************
  //                    PICKS UP FIRST BOX
  // **********************************************************

  // //Repeats until it correctly picks up the box
  while(digitalRead(BUTTON_F) == 1)
  {
    //Drives straight ahead to try and grab box 
    while(digitalRead(BUTTON_F) == 1)
    {
      frente();

    }
    pause();

    //Reverses 
    while(analogRead(linha_F3) > limbo)
    {
      tras();
    }
    pause();
  }


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