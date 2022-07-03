#include<stdio.h>
#include<bcm2835.h>
#include"MotorHat.h"
#include"Sensor.h"
#include"Servo.h"
#include"PWM.h"

#ifndef ROBOT
#define ROBOT

extern void initrobbi(void);
extern void right(int speed);
extern void left(int speed);
extern void bturnleft(void);
extern void bturnright(void);
extern void fturnright(void);
extern void fturnleft(void);
extern void stop(void);
extern void forward(int speed, int seconds);
extern void backward(int speed, int seconds);
extern void motorhatSelect(void);
extern void servoSelect(void);
extern void lookleft(void);
extern void lookright(void);
extern void lookahead(void);

#endif

