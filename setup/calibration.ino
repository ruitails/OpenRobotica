/*If variable sensor_frente is:
  1 - Car is oriented towards the front sensor (Oriented North)
  2 - Car is oriented towards the left sensor  (Oriented West)
  3 - Car is oriented towards the back sensor  (Oriented South)
  4 - Car is oriented towards the right sensor (Oriented Right)
*/

// **********************************************************
//               CALIBRATE STRAIGHT PATH
// **********************************************************
void straight_line(int sensor_frente)
{
  int NO, N, NE;
  int S1, S2, S3;
  int count = 0, flag = 0;

  //Define which sensors are used in each case
  switch(sensor_frente){
    case 1:       //Front sensor oriented north 
      NO = 0;     //Left-Front sensor
      N =  1;     //Mid-Front sensor
      NE = 2;     //Right-Front sensor
      S1 = 6;
      S2 = 7;
      S3 = 8;
      break;
    case 2:       //Left sensor oriented north
      NO = 3;     //Left-Front sensor
      N =  4;     //Mid-Front sensor
      NE = 5;     //Right-Front sensor
      break;
    case 3:       //Back sensor oriented north
      NO = 6;     //Left-Front sensor
      N =  7;     //Mid-Front sensor
      NE = 8;     //Right-Front sensor
      break;
    case 4:       //Right sensor oriented north
      NO = 9;     //Left-Front sensor
      N =  10;    //Mid-Front sensor
      NE = 11;    //Right-Front sensor
      break;
  }


  //**********************************************************
  //          Left-Front sensor detecting black
  //**********************************************************
  if (analogRead(NO) < limbo && analogRead(N) > limbo && analogRead(NE) > limbo)
  {
    //Centers the robot on the line - Center of mass
    while (analogRead(linha_MEIO) > limbo)
    {
      switch(sensor_frente){
        case 1: esquerda(); break;  //Front Sensor
        case 2: tras();     break;  //Left Sensor
        case 3: direita();  break;  //Back Sensor
        case 4: frente();   break;  //Right Sensor
      }

      delay(10);  
      count++;
      if (count == 20){
        break;}
    }

    count = 0;

    //Car tilted to the right - rotates the robot 
    // while(analogRead(N) > limbo && analogRead(S) > limbo){
    while(analogRead(N) > limbo){
      anti();
      delay(10);
      count++;
      if (count == 20){break;}
    }

    flag = 0;
  }

  

  //**********************************************************
  // Front sensor not detecting anything  or
  // Mid-Front sensor detecting black
  //**********************************************************
  else
  {
    switch (sensor_frente)
    {
      case 1: frente();    break;      //Front Sensor
      case 2: esquerda();  break;      //Left Sensor
      case 3: tras();      break;      //Back Sensor
      case 4: direita();   break;      //Right sensor
    }
  }
}


// **********************************************************
//               CALIBRATE AXIS (coordinates)
// **********************************************************

void calibrate_axis_xy(int sensor_frente)
{
  int N, NE, E, EN;
  int count = 0;

  //Define which sensors are used in each case
  switch(sensor_frente)
  {
    case 1:       //Front sensor oriented north
      N =  1;     //Front-Mid sensor
      NE = 2;     //Front-Right sensor
      EN = 9;     //Right-Front sensor
      E  = 10;     //Right-Mid sensor
      break;
    case 2:       //Left sensor oriented north
      N =  4;     //Front-Mid sensor
      NE = 5;     //Front-Right sensor
      EN = 0;     //Right-Front sensor
      E  = 1;     //Right-Mid sensor
      break;
    case 3:       //Back sensor oriented north
      N =  7;     //Front-Mid sensor
      NE = 8;     //Front-Right sensor
      EN = 3;     //Right-Front sensor
      E  = 4;     //Right-Mid sensor
      break;
    case 4:       //Right sensor oriented north
      N =  10;    //Front-Mid sensor
      NE = 11;    //Front-Right sensor
      EN = 6;     //Right-Front sensor
      E  = 7;     //Right-Mid sensor
      break;
  }

  //Calibrate the y axis
  while (analogRead(E) > limbo)
  {  
    Serial.print("\n A corrigir coordenadas y");
    switch (sensor_frente){
      case 1: tras();       break;      //Front Sensor
      case 2: direita();    break;      //Left Sensor
      case 3: frente();     break;      //Back Sensor
      case 4: esquerda();   break;}     //Right sensor 

    delay(10);
    count++;

    if (analogRead(EN) < limbo || count > 40){
      count = 0;
      while (analogRead(E) > limbo){
        switch (sensor_frente){
          case 1: frente();       break;     //Front Sensor
          case 2: esquerda();     break;     //Left Sensor
          case 3: tras();         break;     //Back Sensor
          case 4: direita();      break;     //Right sensor
        }
        delay(5);
        count++;
        if(count > 100){break;}
      }
      count = 0;
    }
  }

  pause();
  count = 0;

  //Calibrate the x axis
  while (analogRead(N) > limbo)
  {  
    Serial.print("\n A corrigir coordenadas x");
    switch (sensor_frente){
      case 1: esquerda();     break;      //Front Sensor
      case 2: tras();         break;      //Left Sensor
      case 3: direita();      break;      //Back Sensor
      case 4: frente();       break;}     //Right sensor 

    delay(5);
    count++;

    if (analogRead(NE) < limbo || count > 80){
      count = 0;
      while (analogRead(N) > limbo){
        switch (sensor_frente){
          case 1: direita();   break;      //Front Sensor
          case 2: frente();    break;      //Left Sensor
          case 3: esquerda();  break;      //Back Sensor
          case 4: tras();      break;      //Right sensor
        }
        delay(5);
        count++;
        if(count > 100){break;}
      }
      count = 0;
    }
  }

  pause();
}


void calibrate_axis_x(int sensor_frente)
{
  int ON;
  int count = 0;

  //Define which sensors are used in each case - Perpendicular with the x axis used  --- O --- | N | --- E ---
  switch(sensor_frente){
    case 1: ON = 5;   break;
    case 2: ON = 8;   break;
    case 3: ON = 11;  break;
    case 4: ON = 2;   break;}


  //Calibrate the X axis
  while (analogRead(linha_MEIO) > limbo)
  {  
    Serial.print("\n A corrigir coordenadas y");
    switch (sensor_frente){
      case 1: tras();       break;    //Front Sensor
      case 2: direita();    break;    //Left Sensor
      case 3: frente();     break;    //Back Sensor
      case 4: esquerda();   break;}   //Right sensor 

    delay(5);
    count++;

    if (analogRead(ON) < limbo || count > 60){
      count = 0;
      while (analogRead(linha_MEIO) > limbo){
          switch (sensor_frente){
            case 1: frente();     break;    //Front Sensor
            case 2: esquerda();   break;    //Left Sensor
            case 3: tras();       break;    //Back Sensor
            case 4: direita();    break;}   //Right sensor
        delay(5);
        count++;
        if(count > 60){break;}
      }
      count = 0;
    }
  }

  pause();
}



// **********************************************************
//              CALIBRATE ORIENTATION (theta)
// **********************************************************

void calibrate_orientation_xy(int orientation)
{
  int N, NO, E, EN;
  int count = 0;

  //Define which sensors are used in each case - Parallel with the y axis used 
  switch(orientation)
  {
    case 1:       //Front sensor oriented north
      N =  1;     //Front-Mid sensor
      NO = 0;     //Front-Right sensor
      EN = 9;     //Right-Front sensor
      E  = 10;     //Right-Mid sensor
      break;
    case 2:       //Left sensor oriented north
      N =  4;     //Front-Mid sensor
      NO = 3;     //Front-Right sensor
      EN = 0;     //Right-Front sensor
      E  = 1;     //Right-Mid sensor
      break;
    case 3:       //Back sensor oriented north
      N =  7;     //Front-Mid sensor
      NO = 6;     //Front-Right sensor
      EN = 3;     //Right-Front sensor
      E  = 4;     //Right-Mid sensor
      break;
    case 4:       //Right sensor oriented north
      N =  10;    //Front-Mid sensor
      NO = 9;    //Front-Right sensor
      EN = 6;     //Right-Front sensor
      E  = 7;     //Right-Mid sensor
      break;
  }

  //Calibrate orientation
  while (analogRead(N) > limbo && analogRead(E) > limbo)
  {  
    // if(analogRead(linha_MEIO) < limbo)
    // {
      Serial.print("\n A corrigir orientação");
      // anti();
      horario();

      delay(5);
      count++;

      if (analogRead(EN) < limbo || analogRead(NO) < limbo || count > 60){
        while (analogRead(E) > limbo && analogRead(N) > limbo){
          // horario();
          anti();
        }
        count = 0;
      }
    // }

    // else{calibrate_axis_xy(orientation);}
  }

  pause();
}


void calibrate_orientation_x(int orientation)
{
  int O, OS, E, EN;
  int count = 0;

  //Define which sensors are used in each case - Perpendicular with the x axis used
  switch(orientation)
  {
    case 1:       //Front sensor oriented north
      O =  4;     //Left-Mid sensor
      OS = 3;     //Left-Front sensor
      EN = 9;     //Right-Front sensor
      E  = 10;    //Right-Mid sensor
      break;
    case 2:       //Left sensor oriented north
      O =  7;     //Left-Mid sensor
      OS = 6;     //Left-Front sensor
      EN = 0;     //Right-Front sensor
      E  = 1;     //Right-Mid sensor
      break;
    case 3:       //Back sensor oriented north
      O =  10;    //Left-Mid sensor
      OS = 9;    //Left-Front sensor
      EN = 3;     //Right-Front sensor
      E  = 4;     //Right-Mid sensor
      break;
    case 4:       //Right sensor oriented north
      O =  1;     //Left-Mid sensor
      OS = 0;     //Left-Front sensor
      EN = 6;     //Right-Front sensor
      E  = 7;     //Right-Mid sensor
      break;
  }


  //Calibrate orientation
  while (analogRead(O) > limbo || analogRead(E) > limbo)
  {  
    // if (analogRead(linha_MEIO) < limbo)
    // {
      Serial.print("\n A corrigir orientação");
      horario();

      delay(5);
      count++;

      if (analogRead(OS) < limbo || analogRead(EN) < limbo || count > 60){
        while (analogRead(O) > limbo && analogRead(E) > limbo){
          anti();
        }
        count = 0;
      }
    // }

    // else {calibrate_axis_x(orientation);}
  }

  pause();
}