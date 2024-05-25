// C++ code
//
#include <Servo.h>
Servo servo_9;
int cm;
int polegadas = 0;
int ang = 0;
int ledPinVerde = 13;
int ledPinVermelho = 12;

void setup(){
  servo_9.attach(9, 500, 2500);
  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinVermelho, OUTPUT);
}

long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);

}
void abrir(){
  	digitalWrite(ledPinVermelho, LOW);
    digitalWrite(ledPinVerde, HIGH); 
    for (ang = 90; ang <= 90; ang += 2){
          servo_9.write(ang);
          delay(15);  
    }
}

void fechar(){
  	digitalWrite(ledPinVermelho, HIGH);
    digitalWrite(ledPinVerde, LOW);
    for (ang = 0; ang >= 0; ang -= 1){
        servo_9.write(ang);
        delay(15);
    }
}
  
  

void loop(){
	cm = 0.01723 * readUltrasonicDistance(6, 6);
    polegadas = (cm / 2.54); 
  	if (cm <= 100){
    	abrir();
    }
  	else{  
    	fechar();
    }
}
