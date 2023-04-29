void first_box()
{
  int flag = 0;               //Flag set to 0 in order to help count the number of intersections
  int orientation = 1;        //Front of the car facing north

  path_AB();

  //************************************
  //  Correct position and orientation
  //************************************
  calibrate_axis_xy(orientation);
  calibrate_orientation_xy(orientation);
  //************************************


  // **********************************************************
  //                    PICKS UP FIRST BOX
  // ********************************************************** 

  //Repeats until it correctly picks up the box
  while(digitalRead(BUTTON_F) == 1)
  {
    int count = 0;

    //Drives straight ahead to try and grab box
    Serial.print("\n Forwards"); 
    while(digitalRead(BUTTON_F) == 1 && count < 100 )
    {
      frente();
      delay(10);
      count++;
    }
    pause();

    //Reverses 
    Serial.print("\n Backwards");
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
    //Reverses
    Serial.print("\n Backwards"); 
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
    horario();
  }
  
  Serial.print("\n Rotação completada");
  pause();


  //************************************
  //  Correct position and orientation
  //************************************
  calibrate_axis_x(orientation); 
  // calibrate_orientation_x(orientation);
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
  calibrate_axis_xy(orientation); 
  calibrate_orientation_xy(orientation);
  //************************************



  // // **********************************************************
  // //                 DRIVES TO NEXT STATION
  // // **********************************************************
  // //DRIVE TO STATION 2 
  // flag = 0;

  // while(flag < 1)
  // {
  //   straight_line(1);
  //   if (analogRead(linha_E3) < limbo)
  //   {
  //     while (analogRead(linha_E3) < limbo)
  //     {
  //       straight_line(1);
  //     }
  //     flag++;
  //   }
  // }
  // pause();


  //  //************************************
  // //  Correct position and orientation
  // //************************************
  // calibrate_axis_xy(orientation); 
  // calibrate_orientation_xy(orientation);
  // //************************************
}


void second_box()
{
  int flag = 0;               //Flag set to 0 in order to help count the number of intersections
  int orientation = 2;        //Left side of the car facing north

  // ******************************
  //      PICKS UP SECOND BOX
  // ******************************
  pick_box(orientation);
  
  //******************************
  //   RETURN TO INITIAL POSE
  // ******************************
  // Drives to previous station (First station) - In order to have space to rotate

  while(analogRead(linha_D2) > limbo)
  {
    tras();
  }
  pause();

  // ******************************
  //    ROTATES 90º (Clockwise)
  // ******************************

  //Correct pose and orientation
  calibrate_axis_x(orientation); 
  calibrate_orientation_x(orientation);
  //********************

  rotate(orientation);
  orientation++;

  //Correct pose and orientation
  calibrate_axis_x(orientation); 
  calibrate_orientation_x(orientation);
  //********************


  // ******************************
  //   DRIVES BACK TO THE TRACK
  // ******************************

  back_to_track(orientation);

  // Correct pose and θ
  calibrate_axis_xy(orientation); 
  calibrate_orientation_xy(orientation);
  //********************


  // **********************************************************
  //                 DRIVES TO NEXT STATION
  // **********************************************************

  // drive_to_station(orientation, 2, 1);     //Mode 1 - Drives straight ahead to next station (2 intersections)

  // Correct pose and θ
  // calibrate_axis_xy(orientation); 
  // calibrate_orientation_xy(orientation);
  //********************
} 


void third_box()
{
  int flag = 0;               //Flag set to 0 in order to help count the number of intersections
  int orientation = 2;        //Left side of the car facing north

  // ******************************
  //      PICKS UP SECOND BOX
  // ******************************
  pick_box(orientation);
  
  //******************************
  //   RETURN TO INITIAL POSE
  // ******************************
  // Drives to previous station (First station) - In order to have space to rotate

  // while(analogRead(linha_F2) > limbo)
  // {
  //   direita();
  // }
  // pause();

  // ******************************
  //    ROTATES 90º (Clockwise)
  // ******************************

  //Correct pose and orientation
  // calibrate_axis_x(orientation); 
  // calibrate_orientation_x(orientation);
  //********************

  // rotate(orientation);
  // orientation++;

  //Correct pose and orientation
  // calibrate_axis_x(orientation); 
  // calibrate_orientation_x(orientation);
  //********************


  // ******************************
  //   DRIVES BACK TO THE TRACK
  // ******************************

  // back_to_track(orientation);

  // Correct pose and θ
  // calibrate_axis_xy(orientation); 
  // calibrate_orientation_xy(orientation);
  //********************


  // **********************************************************
  //                 DRIVES TO NEXT STATION
  // **********************************************************

  // drive_to_station(orientation, 3, 1);     //Mode 1 - Drives straight ahead to next station (1 intersection)

  // Correct pose and θ
  // calibrate_axis_xy(orientation); 
  // calibrate_orientation_xy(orientation);
  //********************
} 



void forth_box()
{
  int flag = 0;               //Flag set to 0 in order to help count the number of intersections
  int orientation = 2;        //Left side of the car facing north

  // ******************************
  //      PICKS UP SECOND BOX
  // ******************************
  pick_box(orientation);
  
  //******************************
  //   RETURN TO INITIAL POSE
  // ******************************
  // Drives to previous station (First station) - In order to have space to rotate

  // while(analogRead(linha_E2) > limbo)
  // {
  //   frente();
  // }
  // pause();

  // ******************************
  //    ROTATES 90º (Clockwise)
  // ******************************

  //Correct pose and orientation
  // calibrate_axis_x(orientation); 
  // calibrate_orientation_x(orientation);
  //********************

  // rotate(orientation);
  // orientation++;

  //Correct pose and orientation
  // calibrate_axis_x(orientation); 
  // calibrate_orientation_x(orientation);
  //********************
} 