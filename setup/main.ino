void loop()
{
  int orientation = 1;
  straight_line(orientation);
  // int NO, N, NE, SO, S, SEA;

  // NO = 0;     //Left-Front sensor
  // N =  1;     //Mid-Front sensor
  // NE = 2;     //Right-Front sensor
  // SO = 8;     //Left-Back sensor
  // S  = 7;     //Mid-Back sensor
  // SEA = 6;    //Right-Back sensor

  // int sensor_frente = 1;

  // if (analogRead(N) < limbo)
  // {
  //   //Car slightly tilted - centers the robot axis before rotating if necessary
  //   frente();

  //   //Tilted to the left - rotates robot to obtain correct orientation
  //   if(analogRead(SO) < limbo || analogRead(S) > limbo || analogRead(SEA) > limbo){
  //     delay(50);
  //     while(analogRead(N) > limbo || analogRead(S) > limbo){
  //       horario();
  //     }
  //   }

  //   //Tilted to the right - rotates robot to obtain correct orientation
  //   else if(analogRead(SEA) < limbo || analogRead(S) > limbo || analogRead(SO) > limbo){
  //     delay(50);
  //     while(analogRead(N) > limbo || analogRead(S) > limbo){
  //       anti();
  //     }
  //   }
  // }

  
  // Serial.print("\n Sensor 1 = ");
  // Serial.print(analogRead(linha_MEIO));
  // Serial.print(" | ");

  // delay(2000);


}
