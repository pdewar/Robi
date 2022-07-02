#include<bcm2835.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include <pthread.h>

#ifndef SENSOR_H
#define SENSOR_H

#define ECHO RPI_V2_GPIO_P1_18
#define TRIG RPI_V2_GPIO_P1_16

void initSensor(void);
void gpio_reset();
double readSensor(void);
double get_time(void);

#endif
