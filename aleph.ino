#include <NewPing.h>
#include <L298N.h>
// Definindo os pinos de controle da ponte H para o motor de torque
#define Motor1_ENA 9
#define Motor1_ENB 10
#define Motor1_IN1 7
#define Motor1_IN2 8

// Definindo os pinos de controle da ponte H para o motor de direção
#define Motor2_ENA 11
#define Motor2_ENB 12
#define Motor2_IN1 4
#define Motor2_IN2 5

// Definindo os pinos do sensor ultrassônico
#define EchoPin 2
#define TrigPin 3

void setup() {
  pinMode(Motor1_ENA, OUTPUT);
  pinMode(Motor1_ENB, OUTPUT);
  pinMode(Motor1_IN1, OUTPUT);
  pinMode(Motor1_IN2, OUTPUT);
  pinMode(Motor2_ENA, OUTPUT);
  pinMode(Motor2_ENB, OUTPUT);
  pinMode(Motor2_IN1, OUTPUT);
  pinMode(Motor2_IN2, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // Medindo a distância até o obstáculo
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  long duration = pulseIn(EchoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Desviando do obstáculo se estiver muito próximo
  if (distance < 20) {
    // Parando os motores
    digitalWrite(Motor1_ENA, 0);
    digitalWrite(Motor1_ENB, 0);
    digitalWrite(Motor2_ENA, 0);
    digitalWrite(Motor2_ENB, 0);

    // Retrocedendo por 1 segundo
    digitalWrite(Motor1_IN1, LOW);
    digitalWrite(Motor1_IN2, HIGH);
    analogWrite(Motor1_ENA, 127);
    analogWrite(Motor1_ENB, 0);
    digitalWrite(Motor2_IN1, LOW);
    digitalWrite(Motor2_IN2, HIGH);
    analogWrite(Motor2_ENA, 127);
    analogWrite(Motor2_ENB, 0);
    delay(1000);

    // Girando para a esquerda por 1 segundo
    digitalWrite(Motor1_IN1, LOW);
    digitalWrite(Motor1_IN2, HIGH);
    analogWrite(Motor1_ENA, 127);
    analogWrite(Motor1_ENB, 0);
    digitalWrite(Motor2_IN1, HIGH);
    digitalWrite(Motor2_IN2, LOW);
    analogWrite(Motor2_ENA, 127);
    analogWrite(Motor2_ENB, 0);
    delay(1000);
  } else {
    // Continuando em frente com velocidade máxima
    digitalWrite(Motor1_IN1, HIGH);
    digitalWrite(Motor1_IN2, LOW);
    analogWrite(Motor1_ENA, 255);
    analogWrite(Motor1_ENB, 0);
    digitalWrite(Motor2_IN1, HIGH);
    digitalWrite(Motor2_IN2, LOW);
    analogWrite(Motor2_ENA, 255);
    analogWrite(Motor2_ENB, 0);
  }
}
