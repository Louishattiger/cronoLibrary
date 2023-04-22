//////////////////////////////////////////////////////////////////////////
//
//  Modulo: Implementacion del Cronometro de alta precision
//
//  Autor: J.A. Holgado
//  Ultima modificacion: 20/03/23
//  Plataforma: Arduino
//  Asignatura: Programacion de Sistemas Empotrados y de Tiempo Real
//  Departamento: Lenguaje y Sistemas Informatico
//  Universidad de Granada
//
//  Objetivo: Programacion de un cronometro de alta precision
//
//  Materiales:
//
//
///////////////////////////////////////////////////////////////////////////

//Necesario para cargar las definiciones basicas de Arduino
/*
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
*/

//Definicion de crono
#include "crono.h"

/////////////////////////////////////////////
// 4) méthode blanco dans loop dans blanco on fait une fonction mathématique -> on retourne le temps moyen, min et max = WCET
// 5) utiliser chrono.waitMilisUntil à la fin du loop 
//Constructor por defecto
Crono::Crono() {
	// Start.
  tipo = 0; // por defecto el cronometro es en millis
	restart(); //=> this -> restart();
}

Crono::Crono(int type) {
  // Start.
  tipo = type;
  restart(); 
}

void Crono::restart() {
  if(tipo == 0){
    _startTime = millis();
  }
  else {
    _startTime = micros();
  }
  _stopTime = _startTime;
  _isActive = true;
}

bool Crono::isActive() {
  return _isActive;
}

double Crono::elapse2millis() {
  if(_isActive){
    if(tipo == 0){
      unsigned long tiempo = millis();
      return (double) (tiempo - _startTime);
    }
    unsigned long tiempo = millis();
    return (double) (tiempo - _startTime/1000);
  }
  if(tipo == 0){
    return (double) (_stopTime - _startTime);
  }
  return (double) (_stopTime - _startTime)/1000;
}

double Crono::elapse2micros() {
  if(_isActive){
    if(tipo == 0){
      unsigned long tiempo = micros();
      return (double) (tiempo - _startTime*1000);
    }
    unsigned long tiempo = micros();
    return (double) (tiempo - _startTime);
  }
  if(tipo == 0){
    return (double) (_stopTime - _startTime)*1000;
  }
  return (double) (_stopTime - _startTime);
}

double Crono::elapse2seconds() {
  if(_isActive){
    if(tipo == 0){
      unsigned long tiempo = millis()/1000;
      return (double) (tiempo - _startTime/1000);
    }
    unsigned long tiempo = millis()/1000;
    return (double) (tiempo - _startTime/1000000);
  }
  if(tipo == 0){
    return (double) (_stopTime - _startTime)/1000;
  }
  return (double) (_stopTime - _startTime)/1000000;
}

double Crono::stop2millis() {
  _isActive = false;
  tipo = 0;
  _stopTime = millis();
  return elapse2millis();
}

double Crono::stop2micros() {
  _isActive = false;
  tipo = 1;
  _stopTime = micros();
  return elapse2micros();
}

double Crono::stop2seconds() {
  _isActive = false;
  tipo = 0;
  _stopTime = millis();
  return elapse2millis()/1000;
}

bool Crono::hasPassedMillis(double timeout) {
  return (elapse2millis() >= timeout);
}

bool Crono::hasPassedMillis(unsigned long timeout) {
  return (elapse2millis() >= (double) timeout);
}

bool Crono::hasPassedSeconds(double timeout) {
  return (elapse2seconds() >= timeout);
}

bool Crono::hasPassedSeconds(unsigned long timeout) {
  return (elapse2seconds() >= (double) timeout);
}

bool Crono::hasPassedMillis(double timeout, bool restartIfPassed) {
  bool hasPassed = hasPassedMillis(timeout);
  if(hasPassed && restartIfPassed){
    restart();
  }
  return hasPassed;
}

bool Crono::hasPassedMillis(unsigned long timeout, bool restartIfPassed) {
  bool hasPassed = hasPassedMillis(timeout);
  if(hasPassed && restartIfPassed){
    restart();
  }
  return hasPassed;
}

bool Crono::hasPassedSeconds(double timeout, bool restartIfPassed) {
  bool hasPassed = hasPassedSeconds(timeout);
  if(hasPassed && restartIfPassed){
    restart();
  }
  return hasPassed;
}

bool Crono::hasPassedSeconds(unsigned long timeout, bool restartIfPassed) {
  bool hasPassed = hasPassedSeconds(timeout);
  if(hasPassed && restartIfPassed){
    restart();
  }
  return hasPassed;
}

void Crono::waitMillis(double timeout) {
  unsigned long startToWait = millis();
  while((millis() - startToWait) < timeout){
    delay(1);
  }
}

void Crono::waitMillis(unsigned long timeout) {
  waitMillis((double) timeout);
}

void Crono::waitMillisuntil(double timeout) {
  double elapsedTime = elapse2millis();
  if (elapsedTime < timeout){
    waitMillis(timeout - elapsedTime);
  }
}

void Crono::waitMillisuntil(unsigned long timeout) {
  waitMillisuntil((double) timeout);
}













