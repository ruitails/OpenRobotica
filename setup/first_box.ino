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
  calibrate_axis_xy(orientation);
  calibrate_orientation_xy(orientation);
  //************************************


  // **********************************************************
  //                    PICKS UP FIRST BOX
  // **********************************************************

  flag = 0; 

  // //Repeats until it correctly picks up the box
  while(digitalRead(BUTTON_F) == 1)
  {
    int count = 0;

    Serial.print("\n CHAAARGE");
    //Drives straight ahead to try and grab box 
    while(digitalRead(BUTTON_F) == 1 && count < 100 )
    {
      frente();
      delay(10);
      count++;

    }
    pause();

    Serial.print("\n PI PI PI PI ...");
    //Reverses 
    while(analogRead(linha_F3) > limbo)
    {
      tras();
    }
    pause();

    flag = 1;   //Checks if the car did the reverse maneuver
  }
  Serial.print("\n Primeira caixa coletada");

  //In order to guarantee that the car reverses - happens when the box gets picked up before expected
  if (flag == 0)
  {
    Serial.print("\n PI PI PI PI ...");
    //Reverses 
    while(analogRead(linha_F3) > limbo){
      tras();
    }
    pause();
  }


  // **********************************************************
  //                 ROTATES 90º (Clockwise)
  // **********************************************************

  // ROTATE 90º (clockwise) - In order to get the LEFT SIDE of the car to FACE NORTH
  while(analogRead(linha_D2) > limbo)
  {
    if (analogRead(linha_MEIO) < limbo)
    {
      horario();
    }
    else{calibrate_axis_x(orientation);}
  }
  
  Serial.print("\n Rotação completada");
  pause();


  //************************************
  //  Correct position and orientation
  //************************************
  calibrate_axis_x(orientation); 
  calibrate_orientation_x(orientation);
  //************************************


  // **********************************************************
  //                 DRIVES BACK TO THE TRACK
  // ********************************************************** 
  while(analogRead(linha_F2) > limbo)
  {
    esquerda();
  }
  pause();


  //Left side of the car facing north
  orientation = 2;


  //************************************
  //  Correct position and orientation
  //************************************
  // calibrate_axis_xy(orientation); 
  // calibrate_orientation_xy(orientation);
  //************************************



  // **********************************************************
  //                 DRIVES TO NEXT STATION
  // **********************************************************
  //DRIVE TO STATION 2 
  // int flag = 0;

  // while(flag < 1)
  // {
  //   straight_line(orientation);
  //   if (analogRead(linha_E3) < limbo)
  //   {
  //     while (analogRead(linha_E3) < limbo)
  //     {
  //       straight_line(orientation);
  //     }
  //     flag++;
  //   }
  // }
  // pause();
}