RobotTest: Servo.c SENSOR.c I2C.c PWM.c MotorHat.c robot.c robottest.c
	gcc -c Servo.c
	gcc -c SENSOR.c -lbcm2835
	gcc -c I2C.c -lbcm2835
	gcc -c PWM.c -lbcm2835
	gcc -c MotorHat.c -lbcm2835
	gcc -c robot.c	-lbcm2835
	gcc -o robi robottest.c I2C.o PWM.o MotorHat.o robot.o SENSOR.o Servo.o -lbcm2835 -lm

clean:
	rm Servo.o
	rm SENSOR.o
	rm I2C.o
	rm PWM.o
	rm MotorHat.o
	rm robot.o
	# rm Servo.h.gch
	# rm SENSOR.h.gch
	# rm I2C.h.gch
	# rm PWM.h.gch
	# rm MotorHat.h.gch
	# rm robot.h.gch
