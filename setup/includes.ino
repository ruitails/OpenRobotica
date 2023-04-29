/*If variable sensor_frente is:
  1 - Car is oriented towards the front sensor (Oriented North)
  2 - Car is oriented towards the left sensor (Oriented West)
  3 - Car is oriented towards the right sensor (Oriented South)
  4 - Car is oriented towards the back sensor (Oriented Right)
*/

//Picks up the desired box (implemented with touro mode)
void pick_box(int sensor_frente)
{ 
  int BUTTON, NE, flag = 0;

  switch(sensor_frente){
    case 1: BUTTON = 18;  //Front sensor oriented north 
            NE = 2;
            break;   
    case 2: BUTTON = 3;   //Left sensor oriented north 
            NE = 5;
            break;   
    case 3: BUTTON = 2;   //Back sensor oriented north 
            NE = 8;
            break;   
    case 4: BUTTON = 19;  //Right sensor oriented north 
            NE = 11;
            break;   
  }

  //Repeats until it correctly picks up the box
  while(digitalRead(BUTTON) == 1)
  {
    int count = 0;

    //Drives straight ahead to try and grab box 
    while(digitalRead(BUTTON) == 1 && count < 100 ){
      switch(sensor_frente){
        case 1: frente();    break;   //Front sensor oriented north 
        case 2: esquerda();  break;   //Left sensor oriented north 
        case 3: tras();      break;   //Back sensor oriented north 
        case 4: direita();   break;}  //Right sensor oriented north 

      delay(10);
      count++;}

    pause();

    //Reverses 
    while(analogRead(NE) > limbo)
    {
      switch(sensor_frente){
        case 1: tras();       break;   //Front sensor oriented north 
        case 2: direita();    break;   //Left sensor oriented north 
        case 3: frente();     break;   //Back sensor oriented north 
        case 4: esquerda();   break;}  //Right sensor oriented north 
    }
    pause();

    flag = 1;   //Checks if the car did the reverse maneuver
  }

  //In order to guarantee that the car reverses - happens when the box gets picked up before expected
  if (flag == 0){
    while(analogRead(NE) > limbo){     //REVERSES 
      switch(sensor_frente){
        case 1: tras();       break;   //Front sensor oriented north 
        case 2: direita();    break;   //Left sensor oriented north 
        case 3: frente();     break;   //Back sensor oriented north 
        case 4: esquerda();   break;}} //Right sensor oriented north 

    pause();}
}

//Rotates the car 90º (clockwise)
void rotate(int sensor_frente)
{
  int E_MID;

  switch(sensor_frente){
    case 1: E_MID = 10; break;  //Front sensor oriented north 
    case 2: E_MID = 1;  break;  //Left sensor oriented north 
    case 3: E_MID = 4;  break;  //Back sensor oriented north 
    case 4: E_MID = 7;  break;  //Right sensor oriented north 
  }

  while(analogRead(E_MID) > limbo)
  {
    // if (analogRead(linha_MEIO) < limbo)
    // {
      horario();
    // }
    // else{calibrate_axis_x(sensor_frente);}
  }

  pause();
}

//Rotates the car -90º (Anti-clockwise)
void inverse_rotate(int sensor_frente)
{
  int E_MID;

  switch(sensor_frente){
    case 1: E_MID = 10; break;  //Front sensor oriented north 
    case 2: E_MID = 1;  break;  //Left sensor oriented north 
    case 3: E_MID = 4;  break;  //Back sensor oriented north 
    case 4: E_MID = 7;  break;  //Right sensor oriented north 
  }

  while(analogRead(E_MID) > limbo)
  {
      anti();
  }

  pause();
}

//Makes the car drive west (to the left side) until it reaches the desired position (reaches the track)
void back_to_track(int sensor_frente)
{
  /*If variable sensor_frente is:
  1 - Car is oriented towards the front sensor (Oriented North)
  2 - Car is oriented towards the left sensor (Oriented West)
  3 - Car is oriented towards the right sensor (Oriented South)
  4 - Car is oriented towards the back sensor (Oriented Right)*/
  
  int N_MID;

  switch(sensor_frente){
    case 1: N_MID = 1;  break;  //Front sensor oriented north 
    case 2: N_MID = 4;  break;  //Left sensor oriented north 
    case 3: N_MID = 7;  break;  //Back sensor oriented north 
    case 4: N_MID = 10; break;  //Right sensor oriented north 
  }

  while(analogRead(N_MID) > limbo)
  {
    switch(sensor_frente){
        case 1: esquerda();   break;   //Front sensor oriented north 
        case 2: tras();       break;   //Left sensor oriented north 
        case 3: direita();    break;   //Back sensor oriented north 
        case 4: frente();     break;}  //Right sensor oriented north 
  }
  pause();
}


//Drives the car to the desired station (mode: 1 - next station | 2 - previous station)
void drive_to_station(int sensor_frente, int intersecoes, int mode)
{
  /*If variable sensor_frente is:
  1 - Car is oriented towards the front sensor (Oriented North)
  2 - Car is oriented towards the left sensor (Oriented West)
  3 - Car is oriented towards the right sensor (Oriented South)
  4 - Car is oriented towards the back sensor (Oriented Right)*/
  
  int NE, orientation, flag = 0;

  switch(sensor_frente){
    case 1: NE = 2;   break;   
    case 2: NE = 5;   break;   
    case 3: NE = 8;   break;   
    case 4: NE = 11;  break;   
  }

  switch(mode){
    case 1:                                 //Mode Next Station (Drives straight ahead)
      switch(sensor_frente){
        case 1: orientation = 4; break;
        case 2: orientation = 1; break;
        case 3: orientation = 2; break;
        case 4: orientation = 3; break;}
    case 2:                                 //Mode Previous Station (Drives backwards)
      switch(sensor_frente){
        case 1: orientation = 2; break;
        case 2: orientation = 3; break;
        case 3: orientation = 4; break;
        case 4: orientation = 1; break;}
  }

  while(flag < intersecoes)
  {
    straight_line(orientation);       //Drives straight ahead
    if (analogRead(NE) < limbo)
    {
      while (analogRead(NE) < limbo)
      {
        straight_line(orientation);
      }
      flag++;
    }
  }
  pause();
}