#include<bcm2835.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<pthread.h>
#include"SENSOR.h"

void initSensor(void){
	bcm2835_gpio_fsel(ECHO, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(TRIG, BCM2835_GPIO_FSEL_OUTP);
}

void gpio_reset()
{
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_18, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_16, BCM2835_GPIO_PUD_OFF);

	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_18, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_16, BCM2835_GPIO_FSEL_INPT);
}

double readSensor(void)
{
    struct timespec start,end;

    double pulse_start, pulse_end, pulse_duration;
    double distance;

    bcm2835_gpio_write(TRIG,LOW);

    bcm2835_delay(10); // Waiting for sensor to settle

    bcm2835_gpio_write(TRIG,HIGH); // Set TRIG to true

    bcm2835_delayMicroseconds(10); // Sleep

    bcm2835_gpio_write(TRIG,LOW); // Set TRIG to false

    while (bcm2835_gpio_lev(ECHO)==0){
        clock_gettime(CLOCK_MONOTONIC, &start);
        pulse_start = start.tv_nsec;
    }

    while(bcm2835_gpio_lev(ECHO)==1){
        clock_gettime(CLOCK_MONOTONIC, &end);
        pulse_end = end.tv_nsec; // get the time in nanoseconds
    }
    
    pulse_duration = (pulse_end - pulse_start)/1000000000; // convert time to seconds

    distance = pulse_duration * 17150;

    gpio_reset();
    
    if(distance <= 0){
        return 12;
    }
    return distance;
}
