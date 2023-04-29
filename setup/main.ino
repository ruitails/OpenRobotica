void loop()
{ 
  int orientation = 1;

  first_box();
  path_BC();
  rotate(3);    //Rotates as if it was facing backwards
  path_CF();
  
  calibrate_axis_x(orientation);

  inverse_rotate(2);
  path_FE();
  drop_first();

  while (true){stop();}
}