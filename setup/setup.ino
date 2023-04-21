//********************
//       Motores
//********************
//MOTOR A
#define A1 26
#define A2 28
#define PWM_A 4

//MOTOR B
#define B1 22
#define B2 24
#define PWM_B 5

//MOTOR C
#define C1 32
#define C2 30
#define PWM_C 6

//MOTOR D
#define D1 36
#define D2 34
#define PWM_D 7


//********************
// Sensores de linha
//********************
//Frente
#define linha_F1 0
#define linha_F2 1
#define linha_F3 2

//Esquerda
#define linha_E1 3
#define linha_E2 4
#define linha_E3 5

//Tras
#define linha_T1 6
#define linha_T2 7
#define linha_T3 8

//Direita
#define linha_D1 9
#define linha_D2 10
#define linha_D3 11

//Meio - Centro de massa
#define linha_MEIO 12


//********************
//  Outros sensores
//********************
//Interruptores
#define BUTTON_F 18
#define BUTTON_E 20 
#define BUTTON_T 21
#define BUTTON_D 19

//Ímans
#define MAGNET_F 13
#define MAGNET_E 12
#define MAGNET_T 11
#define MAGNET_D 10


//********************
//     Variáveis 
//********************
//PWM Speed values
#define FAST 175
#define MEDIUM 100
#define SLOW 85

//Infrared sensor values
#define limbo 550       // ( 550 > x  - BRANCO ) 
                        // ( 550 < x  - PRETO )


void setup(){

  //Motors as OUTPUT
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(PWM_A,OUTPUT);

  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(PWM_B,OUTPUT);

  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(PWM_C,OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(PWM_D,OUTPUT);


  //Line sensors - INPUT
  pinMode(linha_F1, INPUT);
  pinMode(linha_F2, INPUT);
  pinMode(linha_F3, INPUT);

  pinMode(linha_E1, INPUT);
  pinMode(linha_E2, INPUT);
  pinMode(linha_E3, INPUT);

  pinMode(linha_T1, INPUT);
  pinMode(linha_T2, INPUT);
  pinMode(linha_T3, INPUT);

  pinMode(linha_D1, INPUT);
  pinMode(linha_D2, INPUT);
  pinMode(linha_D3, INPUT);

  pinMode(linha_MEIO, INPUT);


  //MagnetPins as OUTPUT
  pinMode(MAGNET_F, OUTPUT);
  pinMode(MAGNET_E, OUTPUT);
  pinMode(MAGNET_T, OUTPUT);
  pinMode(MAGNET_D, OUTPUT);  


  //ButtonPins as INPUT with a pull-up resistor: Connect Button from digital pin to 0V
  pinMode(BUTTON_F, INPUT_PULLUP);
  pinMode(BUTTON_E, INPUT_PULLUP);
  pinMode(BUTTON_T, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);


  //Attach interrupts to Button pins
   attachInterrupt(digitalPinToInterrupt(BUTTON_F), magnet_on_F, FALLING);
   attachInterrupt(digitalPinToInterrupt(BUTTON_E), magnet_on_E, FALLING);
   attachInterrupt(digitalPinToInterrupt(BUTTON_T), magnet_on_T, FALLING);
   attachInterrupt(digitalPinToInterrupt(BUTTON_D), magnet_on_D, FALLING);


  Serial.begin(9600);
}