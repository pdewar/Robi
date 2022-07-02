#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "PWM.h"
#include "I2C.h"

int PWMInit(unsigned char address){
	i2cInit(address,1);

	setAllPWM(0,0);
	write8(__MODE2, __OUTDRV);
	write8(__MODE1, __ALLCALL);
	bcm2835_delay(5);

	unsigned int mode1 = readU8(__MODE1);
	mode1 = mode1 & ~ __SLEEP;
	write8(__MODE1, mode1);
	bcm2835_delay(5);

	return 0;
}

int setPWMFreq(int freq){

	float prescalevel = 25000000.0;
	unsigned int oldmode, newmode;
	float prescale;
	float fvalue;

	prescalevel = prescalevel / 4096.0;
	prescalevel = prescalevel / (float)freq;
	prescalevel -= 1;
	prescale = (float)floor(prescalevel + 0.5);

	oldmode = readU8(__MODE1);
	printf("oldmode %d\n",oldmode);

	newmode = (oldmode & 0x7f) | 0x10;
	printf("newmode %d\n",newmode);

	write8(__MODE1, newmode);
	write8(__PRESCALE, (unsigned char) floor(prescale));

	write8(__MODE1, oldmode);

	bcm2835_delay(5);

	write8(__MODE1, oldmode | 0x80);

	return 0;
}

extern int setPWM(int channel, int on, int off){

	write8(__LED0_ON_L+4*channel, on & 0xFF);
	write8(__LED0_ON_H+4*channel, on >> 8);
	write8(__LED0_OFF_L+4*channel, off & 0xFF);
	write8(__LED0_OFF_H+4*channel, off >>8);

	return 0;
}

int setAllPWM(int on, int off){

	write8(__ALL_LED_ON_L, on & 0xFF);
	write8(__ALL_LED_ON_H, on >> 8);
	write8(__ALL_LED_OFF_L, off & 0xFF);
	write8(__ALL_LED_OFF_H, off >> 8);

	return 0;
}

int PWMInit2(void){
	setAllPWM(0,0);
	write8(__MODE2, __OUTDRV);
	write8(__MODE1, __ALLCALL);
	bcm2835_delay(5);

	unsigned int mode1 = readU8(__MODE1);
	mode1 = mode1 & ~ __SLEEP;
	write8(__MODE1, mode1);
	bcm2835_delay(5);

	return 0;
}
