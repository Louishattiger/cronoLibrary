#include <crono.h>

//////////////////////////////////////////////////////////////////////////
//
//  Modulo: Ejemplo del Cronometro de alta precision
//
//  Autor: J.A. Holgado
//  Ultima modificacion: 20/03/23
//  Plataforma: Arduino
//  Asignatura: Programacion de Sistemas Empotrados y de Tiempo Real
//  Departamento: Lenguaje y Sistemas Informatico
//  Universidad de Granada
//
//  Objetivo: Ejemplo sencillo del uso del cronometro de alta precision
//
//  Materiales:
//
//
///////////////////////////////////////////////////////////////////////////

#include "crono.h"

int count;
double tiempo_millis_0;
double tiempo_micros_0;
double tiempo_millis_1;
double tiempo_micros_1;

//Definicion y creacion del cronometro
Crono cronometro_millis = Crono(0);
Crono cronometro_micros = Crono(1);

void setup()
{
	count=0;
  	//el cronometro se tiene que reiniciar
	cronometro_millis.restart();
	cronometro_micros.restart();
	Serial.begin(9600);
}

void loop()
{
	delay(2000);
	tiempo_millis_0 = cronometro_millis.elapse2millis();
	tiempo_micros_0 = cronometro_millis.elapse2micros();
	tiempo_millis_1 = cronometro_micros.elapse2millis();
	tiempo_micros_1 = cronometro_micros.elapse2micros();
	Serial.print("Activation for millis para el cronometro millis");
	Serial.print(count);
	Serial.print(" = ");
	Serial.println(tiempo_millis_0);
	Serial.print("Activation for miscros para el cronometro millis");
	Serial.print(count);
	Serial.print(" = ");
	Serial.println(tiempo_micros_0);
	Serial.print("Activation for millis para el cronometro micros");
	Serial.print(count);
	Serial.print(" = ");
	Serial.println(tiempo_millis_1);
	Serial.print("Activation for miscros para el cronometro micros");
	Serial.print(count);
	Serial.print(" = ");
	Serial.println(tiempo_micros_1);
	cronometro_millis.waitMillis(2000);
	//cronometro_micros.waitMillis(2000);
	count=count+1;	
}
