#include "robot.h"
#include <bcm2835.h>
#include <stdio.h>
#include "SENSOR.h"
#include "Servo.h"
#include "PWM.h"

double dist_right = 0;
double dist_left = 0;

int main(int argc,char** argv){
	initrobbi();
	initSensor();
	initServo();
	while(1 == 1){
		motorhatSelect();

		while(readSensor() > 11){
			forward(100,0.01);
		}
		
		stop();
		delay(1000);

		servoSelect();
		setPWM(0, 0, servoMin); // look left
		delay(1000);
		dist_right = readSensor();
		
		setPWM(0, 0, servoMax); // look right
		delay(1000);
		dist_left = readSensor();
        
		setPWM(0,0,servoneutral); // look ahead
		
		if(dist_right > dist_left){
			motorhatSelect();
			bturnright();
		}
		if(dist_right < dist_left){
			motorhatSelect();
			bturnleft();
		}

	}
	return 0;
}
