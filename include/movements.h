//Header file for movement functions
#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>

//MOTOR A
#define A1 22
#define A2 24
#define PWM_A 4

//MOTOR B
#define B1 26
#define B2 28
#define PWM_B 5

//MOTOR C
#define C1 30
#define C2 32
#define PWM_C 6

//MOTOR D
#define D1 36
#define D2 34
#define PWM_D 7


//Define PWM Speed values
#define SLOW 100

void frente(void);
void tras(void);
void direita(void);
void esquerda(void);
void horario(void);
void anti(void);
void cima_direita(void);
void cima_esquerda(void);
void baixo_direita(void);
void baixo_esquerda(void);
void stop(void);