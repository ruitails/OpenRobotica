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

  //Define which sensors are used in each case
  //Front sensor oriented north
  if (sensor_frente == 1){
    NO = 0;     //Left-Front sensor
    N =  1;     //Mid-Front sensor
    NE = 2;     //Right-Front sensor
    SO = 8;     //Left-Back sensor
    S  = 7;     //Mid-Back sensor
    SEA = 6;    //Right-Back sensor
  }

  //Left sensor oriented north
  else if (sensor_frente == 2){
    NO = 3;     //Left-Front sensor
    N =  4;     //Mid-Front sensor
    NE = 5;     //Right-Front sensor
    SO = 11;    //Left-Back sensor
    S  = 10;    //Mid-Back sensor
    SEA = 9;    //Right-Back sensor
  }

  //Back sensor oriented north
  else if (sensor_frente == 3){
    NO = 6;     //Left-Front sensor
    N =  7;     //Mid-Front sensor
    NE = 8;     //Right-Front sensor
    SO = 2;     //Left-Back sensor
    S  = 1;     //Mid-Back sensor
    SEA = 0;    //Right-Back sensor
  }

  //Right sensor oriented north
  else if (sensor_frente == 4){
    NO = 9;     //Left-Front sensor
    N =  10;    //Mid-Front sensor
    NE = 11;    //Right-Front sensor
    SO = 5;     //Left-Back sensor
    S  = 4;     //Mid-Back sensor
    SEA = 3;    //Right-Back sensor
  }


  //**********************************************************
  //Left-Front sensor detecting black
  //**********************************************************
  if (analogRead(NO) < limbo && analogRead(N) > limbo && analogRead(NE) > limbo)
  {

    //Centers the robot on the line - Center of mass
    switch (sensor_frente)
    {     
      case 1: //Front Sensor
        while(analogRead(linha_MEIO) > limbo){
          // frente_esquerda();} 
          esquerda();}
        break;
            
      case 2: //Left Sensor  
        while(analogRead(linha_MEIO) > limbo){
          // tras_esquerda();}  
          tras();}
        break;  
          
      case 3: //Back Sensor
        while(analogRead(linha_MEIO) > limbo){
          // tras_direita();}   
          direita();}
        break;   

      case 4: //Right sensor  
        while(analogRead(linha_MEIO) > limbo){
          // frente_direita();}  
          frente();}
        break;       
    }


    //Car tilted to the right - rotates the robot 
    // while(analogRead(N) > limbo && analogRead(S) > limbo){
    while(analogRead(N) > limbo){
      // anti();
      horario();
    }
  }


  //**********************************************************
  //Right-Front sensor detecting black
  //**********************************************************
  else if (analogRead(NE) < limbo && analogRead(N) > limbo && analogRead(NO) > limbo)
  {

    //Centers the robot on the line - Center of mass
    switch (sensor_frente)
    {     
      case 1: //Front Sensor
        while(analogRead(linha_MEIO) > limbo){
          // frente_esquerda();} 
          direita();}
        break;
            
      case 2: //Left Sensor  
        while(analogRead(linha_MEIO) > limbo){
          // tras_esquerda();}  
          frente();}
        break;  
          
      case 3: //Back Sensor
        while(analogRead(linha_MEIO) > limbo){
          // tras_direita();}   
          esquerda();}
        break;   

      case 4: //Right sensor  
        while(analogRead(linha_MEIO) > limbo){
          // frente_direita();}  
          tras();}
        break;       
    }

    //Car tilted to the left - rotates the robot 
    // while(analogRead(N) > limbo && analogRead(S) > limbo){
    while(analogRead(N) > limbo){
      // horario();
      anti();
    }
  }


  //**********************************************************
  // Front sensor not detecting anything  or
  // Mid-Front sensor detecting black
  //**********************************************************
  else{
    switch (sensor_frente)
    {
      case 1: frente();    break;      //Front Sensor
      case 2: esquerda();  break;      //Left Sensor
      case 3: tras();      break;      //Back Sensor
      case 4: direita();   break;      //Right sensor
    }
  }
}