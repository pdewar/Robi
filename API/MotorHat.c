#include <assert.h>
#include <bcm2835.h>
#include "PWM.h"
#include "MotorHat.h"
#include <stdio.h>

void initMotors(){
	motors[0].pwm = 8;
	motors[0].in2 = 9;
	motors[0].in1 = 10;
	motors[1].pwm = 13;
	motors[1].in2 = 12;
	motors[1].in1 = 11;
}

void setPin(int pin, int value){
	if(!(pin>0 && pin<15)){
		printf("wrong pin Number must be between 0 and 15\n");
	}
	if (!((value ==0) || (value == 1))){
		printf("value must be 0 or 1\n");
	}
	if(value == 0){
		setPWM(pin, 0, 4096);
	}
	if(value ==1){
		setPWM(pin, 4096, 0);
	}
}



void run(unsigned char command, int motorID) {
	if(command == FORWARD){
		setPin(motors[motorID].in2,0);
		setPin(motors[motorID].in1,1);
	}
	else if(command == BACKWARD){
		setPin(motors[motorID].in2,1);
		setPin(motors[motorID].in1,0);
	}
	else if(command == RELEASE){
		setPin(motors[motorID].in1,0);
		setPin(motors[motorID].in2,0);
	}
	else{
		printf("invalid command");
	}
}

void setSpeed(int motorID, int speed){
	if(!((speed<=255) && (speed >=0))){
		printf("wrong speed must be between 0 and 255\n");
	}
	setPWM(motors[motorID].pwm,0, speed*16);
}



void initHat(){
	unsigned i2cAddress = 0x60;
	initMotors();
	PWMInit(i2cAddress);
	setPWMFreq(1600);
}
