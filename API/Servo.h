#include<stdio.h>
#include<stdlib.h>
#include"PWM.h"
#include<math.h>

#ifndef SERVO
#define SERVO

void initServo(void);
void servoSelect(void);
#define servoMin        150
#define servoMax        600
#define servoneutral    375

#endif
