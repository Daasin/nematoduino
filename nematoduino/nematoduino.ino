//
// Settings
//

// Factor for converting muscle weights to motor speeds
#define MUSCLE_FACTOR 0.5

// How long (in ms) to run motors for each 'tick' of the simulation
#define MOTOR_RUN_TIME 100

//
// Robot code
//

#include <avr/pgmspace.h>

#include <Worm.hpp>

#include "motors.hpp"
#include "sensor.hpp"

Worm worm;
Motors motors;
Sensor sensor(25.0);

void setup() {
}

void loop() {

  if(sensor.triggered()) {
    worm.noseTouch();
  }
  else {
    worm.chemotaxis();
  }

  int16_t leftMuscle = worm.getLeftMuscle();
  int16_t rightMuscle = worm.getRightMuscle();

  int16_t leftMotor = MUSCLE_FACTOR*leftMuscle;
  int16_t rightMotor = MUSCLE_FACTOR*rightMuscle;

  motors.run(leftMotor, rightMotor);

  delay(MOTOR_RUN_TIME);
}
