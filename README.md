# Arduino Stopwatch Library

The Arduino Stopwatch Library is a library for the Arduino platform that provides a simple and easy-to-use interface for building and controlling stopwatch functionalities.

## Features

The Arduino Stopwatch Library provides the following features:

- Start (restart), stop the stopwatch.
- Measure elapsed time in microseconds, milliseconds, seconds.
- Returns true if a certain timeout has elapsed and enables the timer to start.
- Wait until a relative time or absolute time has elapsed since the timer started.

## Installation

Follow this steps:

1. **Download** the latest version of the library from the [GitHub repository](https://github.com/Louishattiger/cronoLibrary).
2. **Open** the Arduino IDE and select `Sketch` > `Include Library` > `Add .ZIP Library`.
3. **Select** the downloaded ZIP file and click `Open`.
4. The library should now be installed and ready to use in your project.

## Usage

To use the library in your code, simply include the Stopwatch library header file:

```c++
#include <crono.h>
```

Then, create an instance of the Stopwatch class and start the stopwatch:

```c++
Crono cronometro;

void setup() {
  cronometro.restart();
}

void loop() {
  unsigned long elapsedMillis = cronometro.elapse2millis();
  // do something with the elapsed time
}
```

For more information on how to use the library, please refer to the examples provided in the library repository.