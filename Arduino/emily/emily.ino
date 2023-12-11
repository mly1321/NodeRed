#include <Servo.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 10

Servo servoMotor; // Crie um objeto Servo
int sensorPin = A0; // Pino do sensor de temperatura LM35
int servoPin = 3;  // Pino do servo motor
int ruidoPin = A1; //Pino sensor de ruído
int ledVerm = 13; //Pino led Vermelho
int ledVerde = 11; //Pino led Verde
int ledAmarelo = 12; //Pino led amarelo
int sensorValue;
float temperatureC;
int ruidoValue;
float ruidodB;


float alto = 200;;
float baixo = 70;

void setup() {
 servoMotor.attach(servoPin); // Anexe o servo ao pino
 Serial.begin(9600);
 servoMotor.write(0);
 pinMode(ledAmarelo,OUTPUT);
 pinMode(ledVerm,OUTPUT);
 pinMode(ledVerde,OUTPUT);
}

void loop() {
  int soma = 00;
  float media;
  DHT.read(DHT11_PIN);
  float temperatura = DHT.temperature; // Leia a temperatura em graus Celsius
  float umidade = DHT.humidity; // Leia a umidade relativa em porcentagem
 
  
  
  for (int i=0;i<50;i++){
    soma += analogRead(ruidoPin);
    delay(20);
  }

  media = soma/50;

if (media > alto){
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVerm, HIGH);
  digitalWrite(ledAmarelo, LOW);
  servoMotor.write(90);
  delay(700);
  servoMotor.write(0);
  }

  if(media<alto){
    if(media>baixo){
 		  digitalWrite(ledVerde, LOW);
 		  digitalWrite(ledVerm, LOW);
 		  digitalWrite(ledAmarelo, HIGH);
  }
 	  }
 
 if (media < baixo){
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVerm, LOW);
  digitalWrite(ledAmarelo, LOW);
  }

 if (isnan(temperatura) || isnan(umidade)) {
  Serial.println("Erro ao ler o sensor DHT!");
 } else {
  Serial.print("{'Temperatura' : ");
  Serial.print(temperatura);
  Serial.println(" '°C'");
  Serial.print(",'Umidade': ");
  Serial.print(umidade);
  Serial.println(" '%'}");
 }
 
 Serial.print(media*0.48828125);
 delay(1000);
}