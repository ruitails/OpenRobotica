// Forward
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}
    
// Backward
void tras(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}
    
//Turn Anti-clockwise
void anti(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}
    
//Turn Clockwise
void horario(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Turn right
void direita(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Turn Left
void esquerda(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Diagonal Front-Right

void frente_esquerda(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Diagonal Front-Left

void frente_direita(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Diagonal Back-Right
void tras_esquerda(){
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

    analogWrite(PWM_A, MEDIUM);
    analogWrite(PWM_B, SLOW);
    analogWrite(PWM_C, SLOW);
    analogWrite(PWM_D, SLOW);
}

//Diagonal Back-Left
void tras_direita(){
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

    analogWrite(PWM_A, MEDIUM);
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

