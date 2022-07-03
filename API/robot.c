#include"robot.h"
#include"MotorHat.h"
#include"Sensor.h"
#include"Servo.h"
#include<bcm2835.h>
#include"PWM.h"

extern void initrobbi(void)
{
	initHat();
	run(RELEASE,0);
	run(RELEASE,1);
	initSensor();
	initServo();	
}

extern void right(int speed){
	setSpeed(1,speed);
}

extern void left(int speed){
	setSpeed(0,speed);
}

extern void bturnleft(void)
{
	left(100);
	right(0);
	run(BACKWARD,0);
	run(BACKWARD,1);
	bcm2835_delay(1*1000);
}

extern void bturnright(void)
{
	left(0);
	right(100);
	run(BACKWARD,0);
	run(BACKWARD,1);
	bcm2835_delay(1*1000);
}

extern void fturnright(void)
{
	left(100);
	right(0);
	run(FORWARD,0);
	run(FORWARD,1);
	bcm2835_delay(1*1000);
}

extern void fturnleft(void)
{
	left(0);
	right(100);
	run(FORWARD,0);
	run(FORWARD,1);
	bcm2835_delay(1*1000);
}

extern void stop(void){
	run(RELEASE,0);
	run(RELEASE,1);
}

extern void forward(int speed, int seconds){
	left(speed);
	right(speed);
	run(FORWARD,0);
	run(FORWARD,1);
	bcm2835_delay(seconds*1000);
}

extern void backward(int speed, int seconds){
	left(speed);
	right(speed);
	run(BACKWARD,0);
	run(BACKWARD,1);
	bcm2835_delay(seconds*1000);
}

extern void motorhatSelect(void){
	bcm2835_i2c_setSlaveAddress(0x60);
	PWMInit2();
	setPWMFreq(1600);
}

extern void servoSelect(void){
	bcm2835_i2c_setSlaveAddress(0x40);
	PWMInit2();
	setPWMFreq(60);
}

extern void lookleft(void){
	setPWM(0, 0, servoMin);
}

extern void lookright(void){
	setPWM(0, 0, servoMax);
}

extern void lookahead(void){
	setPWM(0,0,servoNeutral);
}
