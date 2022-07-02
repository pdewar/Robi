#include<stdio.h>
#include<regex.h>
#include<fcntl.h>
#include<unistd.h>
#include<bcm2835.h>
#include"I2C.h"

#define BUFFERSIZE 4096

extern int i2cInit(int address, int buss){
	Address *theAddress;
	
	theAddress = (Address*)malloc(sizeof(Address));
	
	theAddress->address = address;
	theAddress->bussNumber = buss;
	
	//i2c initialization should also go here.
	
	if (!bcm2835_init()){
		printf("bcm2835_init failed. Are you running as root??\n");
		return 1;
	}
	
	if (!bcm2835_i2c_begin()){
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
	}

	bcm2835_i2c_setSlaveAddress(address); //set HAT address to 0x41
	return 0;
}

extern void  write8(unsigned char reg, unsigned char value){
	char buff[2];
	buff[0] = reg;
	buff[1] = value;
	uint8_t result;
	result = bcm2835_i2c_write(buff,2);
	//if(result == BCM2835_I2C_REASON_OK){printf("Sucess\n");}
	if(result == BCM2835_I2C_REASON_ERROR_NACK){printf("Received a NACK\n");}
	if(result == BCM2835_I2C_REASON_ERROR_CLKT){printf("Received Clock Stretch Timeout\n");}
	if(result == BCM2835_I2C_REASON_ERROR_DATA){printf("Not all data is sent/received\n");}
	return;
}

extern unsigned int readU8(unsigned char reg){
	unsigned char value;
	unsigned char buffer[2];
	buffer[0] = reg;
	uint8_t result;
	result = bcm2835_i2c_read(buffer,2);
	//if(result == BCM2835_I2C_REASON_OK){printf("Sucess\n");}
	if(result == BCM2835_I2C_REASON_ERROR_NACK){printf("Received a NACK\n");}
	if(result == BCM2835_I2C_REASON_ERROR_CLKT){printf("Received Clock Stretch Timeout\n");}
	if(result == BCM2835_I2C_REASON_ERROR_DATA){printf("Not all data is sent/received\n");}
	value = buffer[0];
	return value;
}
