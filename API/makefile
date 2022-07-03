RobotTest: Servo.c Sensor.c I2C.c PWM.c MotorHat.c robot.c robottest.c
	gcc -c Servo.c
	gcc -c Sensor.c -lbcm2835
	gcc -c I2C.c -lbcm2835
	gcc -c PWM.c -lbcm2835
	gcc -c MotorHat.c -lbcm2835
	gcc -c robot.c	-lbcm2835
	gcc -o robi robottest.c I2C.o PWM.o MotorHat.o robot.o Sensor.o Servo.o -lbcm2835 -lm

clean:
	rm robi
	rm Servo.o
	rm Sensor.o
	rm I2C.o
	rm PWM.o
	rm MotorHat.o
	rm robot.o
	# rm Servo.h.gch
	# rm Sensor.h.gch
	# rm I2C.h.gch
	# rm PWM.h.gch
	# rm MotorHat.h.gch
	# rm robot.h.gch