#include "DHT.h"
#define dht_type DHT11 //define qual o tipo de sensor DHTxx que se está utilizando
/**
* Configurações iniciais sobre os sensores
* DHT11, LM35, LDR5 e TCRT5000
*/
int dht_pin = A2;
DHT dht_1 = DHT(dht_pin, dht_type); //pode-se configurar diversossensores DHTxx
int switch_pin = 7;
void setup()
{
Serial.begin(9600);
dht_1.begin();
pinMode(switch_pin, INPUT);
}
void loop()
{
/**
* Bloco do DHT11
*/

// EQUAÇÃO LINEAR (20 - 55)
float leitura = dht_1.readHumidity();
float umidadeReal = 2.5 * leitura - 122.5;

// SENSORES SIMULADOS
float umidadeSimulada1 = leitura - 20;
float umidadeSimulada2 = leitura - 30;
float umidadeSimulada3 = leitura - 15;
float umidadeSimulada4 = leitura - 35;

if (isnan(leitura))
{
Serial.println("Erro ao ler o DHT");
}
else
{
Serial.print(umidadeReal);
Serial.println(";");
Serial.print(umidadeSimulada1);
Serial.println(";");
Serial.print(umidadeSimulada2);
Serial.println(";");
Serial.print(umidadeSimulada3);
Serial.println(";");
Serial.print(umidadeSimulada4);
Serial.println(";");
}
delay(3500);
}
