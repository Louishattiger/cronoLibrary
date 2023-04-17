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
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//Definicion de crono
#include "crono.h"

/////////////////////////////////////////////
// 4) méthode blanco dans loop dans blanco on fait une fonction mathématique -> on retourne le temps moyen, min et max = WCET
// 5) utiliser chrono.waitMilisUntil à la fin du loop 
//Constructor por defecto
Crono::Crono() {
	// Start.
	restart(); //=> this -> restart();
}

Crono::Crono(int tipo) {
  // Start.
  _tipo = tipo;
  restart(); 
}

void Crono::restart() {
  if(_tipo == 0){
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

// à revoir les elapse2
double Crono::elapse2millis() {
  if(_tipo == 0){
    unsigned long tiempo = millis();
    return (double) (tiempo - _startTime);
  }
  unsigned long tiempo = micros();
  return (double) (tiempo - _startTime);
}

double Crono::elapse2micros() {
  if(_tipo == 0){
    unsigned long tiempo = millis();
    return (double) (tiempo - _startTime);
  }
  unsigned long tiempo = micros();
  return (double) (tiempo - _startTime);
}

double Crono::elapse2seconds() {
  return _startTime/1000;
}

double Crono::stop2millis() {
  if(_tipo == 0){
    return (double) (_stopTime - _startTime);
  }
  return (double) ((_stopTime - _startTime)/1000);  
  
}

double Crono::stop2micros() {
  if(_tipo == 0){
    return (double) ((_stopTime - _startTime)*1000);
  }
  return (double) (_stopTime - _startTime);
}

double Crono::stop2seconds() {
  if(_tipo == 0){
    return (double) ((_stopTime - _startTime)/1000);
  }
  return (double) ((_stopTime - _startTime)/1000000);
}

bool Crono::hasPassedMillis(double timeout) {
  if(_tipo == 0){
    if(_startTime > timeout){
      return true;
    }
    return false;
  }
  timeout = timeout*1000;
  if(_startTime > timeout){
    return true;
  }
  return false;
}

bool Crono::hasPassedMillis(unsigned long timeout) {
  if(_tipo == 0){
    if(_startTime > timeout){
      return true;
    }
    return false;
  }
  timeout = timeout*1000;
  if(_startTime > timeout){
    return true;
  }
  return false;
}

bool Crono::hasPassedSeconds(double timeout) {
  if(_tipo == 0){
    timeout = timeout*1000;
    if(_startTime > timeout){
      return true;
    }
    return false;
  }
  timeout = timeout*1000000;
  if(_startTime > timeout){
    return true;
  }
  return false;
}

bool Crono::hasPassedSeconds(unsigned long timeout) {
  if(_tipo == 0){
    timeout = timeout*1000;
    if(_startTime > timeout){
      return true;
    }
    return false;
  }
  timeout = timeout*1000000;
  if(_startTime > timeout){
    return true;
  }
  return false;
}

bool Crono::hasPassedMillis(double timeout, bool restartIfPassed) {
  if(_tipo == 0){
    if(_startTime > timeout){
      if(restartIfPassed){
        _startTime = 0;
      }
      return true;
    }
    return false;
  }
  timeout = timeout*1000;
  if(_startTime > timeout){
    if(restartIfPassed){
      _startTime = 0;
    }
    return true;
  }
  return false;
}

bool Crono::hasPassedMillis(unsigned long timeout, bool restartIfPassed) {
  if(_tipo == 0){
    if(_startTime > timeout){
      if(restartIfPassed){
        _startTime = 0;
      }
      return true;
    }
    return false;
  }
  timeout = timeout*1000;
  if(_startTime > timeout){
    if(restartIfPassed){
      _startTime = 0;
    }
    return true;
  }
  return false;
}

bool Crono::hasPassedSeconds(double timeout, bool restartIfPassed) {
  if(_startTime/1000 > timeout){
    if(restartIfPassed){
      _startTime = 0;
    }
    return true;
  }
  return false;
}

bool Crono::hasPassedSeconds(unsigned long timeout, bool restartIfPassed) {
  if(_startTime/1000 > timeout){
    if(restartIfPassed){
      _startTime = 0;
    }
    return true;
  }
  return false;
}

void Crono::waitMillis(double timeout) {
  if(_tipo == 0){
    delay(timeout);
    restart();
  }
  timeout = timeout*1000;
  delay(timeout);
  restart();
}

void Crono::waitMillis(unsigned long timeout) {
  if(_tipo == 0){
    delay(timeout);
    restart();
  }
  timeout = timeout*1000;
  delay(timeout);
  restart()
}

void Crono::waitMillisuntil(double timeout) {
  if(_tipo == 0){
    delay(timeout - _startTime);
    restart();
  }
  timeout = timeout*1000;
  delay(timeout - _startTime);
  restart();
}

void Crono::waitMillisuntil(unsigned long int timeout) {
  if(_tipo == 0){
    delay(timeout - _startTime);
    restart();
  }
  timeout = timeout*1000;
  delay(timeout - _startTime);
  restart();
}













