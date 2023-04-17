#include <crono.h>

int count;
double tiempo;

//Definicion y creacion del cronometro
Crono cronometro;

void setup()
{
	count=0;
  //el cronometro se tiene que reiniciar
	cronometro.restart();
	Serial.begin(9600);
}

void loop()
{
	delay(2000);
	tiempo = cronometro.elapse2millis();
  Serial.print("Activacion ");
  Serial.print(count);
  Serial.print(" = ");
	Serial.println(tiempo);
	count=count+1;	
}
