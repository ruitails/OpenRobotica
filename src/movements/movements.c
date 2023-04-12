//Source file for all movement functions1
#include "movements.h"
#include <Arduino.h>

// MOTOR A
#define An1 15
#define An2 16
#define PWM_A 4

// MOTOR B
#define B1 26
#define B2 28
#define PWM_B 5

// MOTOR C
#define C1 30
#define C2 32
#define PWM_C 6

// MOTOR D
#define D1 36
#define D2 34
#define PWM_D 7

// Define PWM Speed values
#define SLOW 100


//Move forward
void frente(){
    //Front
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    //Front
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
    //Front
    digitalWrite(C1, HIGH);
    digitalWrite(C2, LOW);
    //Front
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move backwards 
void tras(void){
    //Back
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    //Back
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH);
    //Back
    digitalWrite(C1, LOW);
    digitalWrite(C2, HIGH);
    //Back
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move right
void direita(void){
    //Front
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    //Back
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH);
    //Back
    digitalWrite(C1, LOW);
    digitalWrite(C2, HIGH);
    //Front
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move left
void esquerda(void){
    //Back
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    //Front
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
    //Front
    digitalWrite(C1, HIGH);
    digitalWrite(C2, LOW);
    //Back
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move clockwise
void horario(void){
    //Back
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    //Front
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
    //Back
    digitalWrite(C1, LOW);
    digitalWrite(C2, HIGH);
    //Front
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move anti-clockwise
void anti(void){
    //Front
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    //Back
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH);
    //Front
    digitalWrite(C1, HIGH);
    digitalWrite(C2, LOW);
    //Back
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move front-right
void cima_direita(void){
    //STOP
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    //Front
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    //STOP
    digitalWrite(C1, LOW);
    digitalWrite(C2, LOW);
    //Front
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move front-left
void cima_esquerda(void){
    //Front
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    //STOP
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
    //Front
    digitalWrite(C1, HIGH);
    digitalWrite(C2, LOW);
    //STOP
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move back-right
void baixo_direita(){
    //Front
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    //STOP
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH);
    //Front
    digitalWrite(C1, LOW);
    digitalWrite(C2, HIGH);
    //STOP
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Move back-left
void baixo_esquerda(){
    //STOP
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    //Back
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    //STOP
    digitalWrite(C1, LOW);
    digitalWrite(C2, LOW);
    //Back
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);

    analogWrite(PWM_A, SLOW);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Stop
void stop(){
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    digitalWrite(C1, LOW);
    digitalWrite(C2, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);

    analogWrite(PWM_A, 0);
    analogWrite(PWM_B, 0);
    analogWrite(PWM_C, 0);
    analogWrite(PWM_D, 0);
}