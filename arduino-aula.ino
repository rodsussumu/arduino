#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11
#define Higrometro A1
#define LDR A2
#define LED_VERDE 12
#define LED_VERMELHO 13

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(Higrometro, INPUT);
  pinMode(LDR, INPUT);
  dht.begin();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  float umidadeSolo = analogRead(Higrometro);
  float luminosidade = analogRead(LDR);
  

    Serial.print(umidade);
    Serial.print(temperatura);
    Serial.print(umidadeSolo);
    Serial.print(luminosidade);

    if(umidadeSolo > 511.5) {
        digitalWrite(LED_VERDE, HIGH);    
    } else {
         digitalWrite(LED_VERMELHO, LOW); 
    }

}
