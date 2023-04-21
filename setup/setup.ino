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

//Define PWM Speed values
#define FAST 175
#define MEDIUM 110
#define SLOW 95

//550 para cima é branco
#define limbo 550

//sensor linha frente
#define linha_F1 0
#define linha_F2 1
#define linha_F3 2

//sensor linha esquerda
#define linha_E1 3
#define linha_E2 4
#define linha_E3 5

//sensor linha tras
#define linha_T1 6
#define linha_T2 7
#define linha_T3 8

//sensor linha direita
#define linha_D1 9
#define linha_D2 10
#define linha_D3 11

//sensor linha meio
#define linha_MEIO 12


void setup(){

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

  Serial.begin(9600);
}