#include "Servo.h"

void initServo(void){
	unsigned i2cAddress = 0x40;
	PWMInit(i2cAddress);
	setPWMFreq(60);
	setPWM(0, 0, servoNeutral);
}

void setServoPulse(int channel, double pulse){
	double pulseLength = 1000000;            // 1,000,000 us per second
	pulseLength /= 60;                       // 60 Hz
  	pulseLength /= 4096;                     // 12 bits of resolution
  	pulse *= 100000;
  	pulse /= pulseLength;
  	setPWM(channel, 0, pulse);
}
