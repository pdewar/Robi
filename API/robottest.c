#include"robot.h"
#include<bcm2835.h>
#include<stdio.h>
#include"Sensor.h"
#include"Servo.h"

double dist_right = 0;
double dist_left = 0;

int main(int argc,char** argv){
	initrobbi();
	while(1 == 1){
		motorhatSelect();

		while(readSensor() > 11){
			forward(100,0.01);
		}
		
		stop();
		delay(1000);

		servoSelect();
		lookleft();
		delay(1000);
		dist_right = readSensor();
		
		lookright();
		delay(1000);
		dist_left = readSensor();
        
		lookahead();
		
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
