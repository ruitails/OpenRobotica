void drop_first()
{
  int orientation = 1;

  esquerda();
  delay(800);

  calibrate_axis_x(orientation);

  rotate(2);

  calibrate_axis_x(2);
  calibrate_orientation_x(2);

  anti();
  delay(200);
  stop();

  frente();
  delay(1500);

  stop();
  digitalWrite(MAGNET_F, LOW);

  tras();
  delay(500);
}