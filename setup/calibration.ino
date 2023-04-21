void straight_line(int sensor_frente)
{
  /*If variable sensor_frente is:
  1 - Car is oriented towards the front sensor (Oriented North)
  2 - Car is oriented towards the left sensor (Oriented West)
  3 - Car is oriented towards the right sensor (Oriented South)
  4 - Car is oriented towards the back sensor (Oriented Right)
  */

  int NO, N, NE;
  int SO, S, SEA;
  int flag_lastpose;

  //Define which sensors are used in each case
  //Car oriented north (Front sensor)
  if (sensor_frente == 1){
    NO = 0;     //Left-Front sensor
    N =  1;     //Mid-Front sensor
    NE = 2;     //Right-Front sensor
    SO = 8;     //Left-Back sensor
    S  = 7;     //Mid-Back sensor
    SEA = 6;    //Right-Back sensor
  }

  //Car oriented west (Left sensor)
  else if (sensor_frente == 2){
    NO = 3;     //Left-Front sensor
    N =  4;     //Mid-Front sensor
    NE = 5;     //Right-Front sensor
    SO = 11;    //Left-Back sensor
    S  = 10;    //Mid-Back sensor
    SEA = 9;    //Right-Back sensor
  }

  //Car oriented south (Back sensor)
  else if (sensor_frente == 3){
    NO = 6;     //Left-Front sensor
    N =  7;     //Mid-Front sensor
    NE = 8;     //Right-Front sensor
    SO = 2;     //Left-Back sensor
    S  = 1;     //Mid-Back sensor
    SEA = 0;    //Right-Back sensor
  }

  //Car oriented east (Right sensor)
  else if (sensor_frente == 4){
    NO = 9;     //Left-Front sensor
    N =  10;    //Mid-Front sensor
    NE = 11;    //Right-Front sensor
    SO = 5;     //Left-Back sensor
    S  = 4;     //Mid-Back sensor
    SEA = 3;    //Right-Back sensor
  }

  //**********************************************************
  //Mid-Front sensor detecting black
  //**********************************************************

  if (analogRead(N) < limbo)
  {
    if (analogRead(SO) < limbo || analogRead(SEA) < limbo)
    {
      if (analogRead(SO) < limbo){flag_lastpose = 1;}         //Left-Back sensor detecting black
      else if (analogRead(SEA) < limbo){flag_lastpose = 2;}   //Right-Back sensor detecting black

      //Car slightly tilted - centers the robot axis before rotating if necessary
      while(analogRead(linha_MEIO) > limbo)
      {
        switch (sensor_frente)
        {
          case 1: frente();  break;        //Front Sensor
          case 2: esquerda();  break;      //Left Sensor
          case 3: tras();   break;         //Back Sensor
          case 4: direita();  break;       //Right sensor
        }
      }


      //Left-Back Sensor detecting black
      //Tilted to the left - rotates robot to obtain correct orientation
      if(flag_lastpose == 1){
        while(analogRead(N) > limbo || analogRead(S) > limbo){
          horario();
        }
      }

      //Right-Back Sensor detecting black
      //Tilted to the right - rotates robot to obtain correct orientation
      else if(flag_lastpose == 2)
      {
        //Rotates until one of the back sensors detects black
        while(analogRead(N) > limbo ||  analogRead(S) > limbo){
          anti();
        }
      }

    }

    else 
    {
      //Perfectly aligned or DESCONHECIDO - drives straight ahead
      switch (sensor_frente)
      {
        case 1: frente();  break;        //Front Sensor
        case 2: esquerda();  break;      //Left Sensor
        case 3: tras();   break;         //Back Sensor
        case 4: direita();  break;       //Right sensor
      }
  }
  }



  //**********************************************************
  //Left-Front sensor detecting black
  //**********************************************************

  else if (analogRead(NO) < limbo)
  {

    //Car tilted to the right - rotates the robot 
    switch (sensor_frente)
    {     
      case 1: //Front Sensor
        while(analogRead(linha_MEIO) > limbo){
          //frente_esquerda();} 
          esquerda();}
        break;
            
      case 2: //Left Sensor  
        while(analogRead(linha_MEIO) > limbo){
          //tras_esquerda();}  
          tras();}
        break;  
          
      case 3: //Back Sensor
        while(analogRead(linha_MEIO) > limbo){
          //tras_direita();}   
          direita();}
        break;   

      case 4: //Right sensor  
        while(analogRead(linha_MEIO) > limbo){
          //frente_direita();}  
          frente();}
        break;       
    }


    while(analogRead(N) > limbo || analogRead(S) > limbo){
      anti();
    }
  }


  //**********************************************************
  //Right-Front sensor detecting black
  else if (analogRead(NE) < limbo)
  {

    //Car tilted to the left - rotates the robot 
    switch (sensor_frente)
    {     
      case 1: //Front Sensor
        while(analogRead(linha_MEIO) > limbo){
          //frente_esquerda();} 
          direita();}
        break;
            
      case 2: //Left Sensor  
        while(analogRead(linha_MEIO) > limbo){
          //tras_esquerda();}  
          frente();}
        break;  
          
      case 3: //Back Sensor
        while(analogRead(linha_MEIO) > limbo){
          //tras_direita();}   
          esquerda();}
        break;   

      case 4: //Right sensor  
        while(analogRead(linha_MEIO) > limbo){
          //frente_direita();}  
          tras();}
        break;       
    }

    while(analogRead(N) > limbo || analogRead(S) > limbo){
      horario();
    }
  }


  //**********************************************************
  //Front sensor not detecting anything
  else{
    switch (sensor_frente)
    {
      case 1: frente();  break;        //Front Sensor
      case 2: esquerda();  break;      //Left Sensor
      case 3: tras();   break;         //Back Sensor
      case 4: direita();  break;       //Right sensor
    }
  }
}