# Robi

Design of a driver that allows a robot, controlled by a Raspberry Pi 3b+, to move and avoid objects. 
The driver is implemented using the Broadcom BCM 2835 library to interact with DC motors,  a servo, and an ultrasonic sensor with 
the use of hats and the I2C protocol.

## API docs

- initrobbi(); - Initialize the motorhat, servohat and ultrasonic sensor by calling inithat(), initServo(), initSensor(). Also allows access to the GPIO pins that are used to establish an i2c connection.

- initSensor(); - Initialize the Ultrasonic Distance Sensor by setting the echo pin as an input and the trigger pin as an output.

- initServo(); - Initialize the servo that controls the movement of the Ultrasonic Distance Sensor. This selects the servo as a slave and sets the pulse width modulation frequency to 60Hz.

- motorhatSelect(); - Initiate communication to the DC motors over the i2c bus by setting the slave address to 0x60 and the PWM frequency to 1600Hz.

- servoSelect(); - Initiate communication to the servo over the i2c bus by setting the slave address to 0x40 and the PWM frequency to 60Hz.

- lookright(); - Moves the servo to a 0-degree angle having the Ultrasonic Distance Sensor point to the right. For this command to work, either initServo() or servoSelect() is called first.

- lookleft(); - Moves the servo to a 180-degree angle having the Ultrasonic Distance Sensor point to the left. For this command to work, either initServo() or servoSelect() is called first.

- lookahead(); - Moves the servo to a 90-degree angle having the Ultrasonic Distance Sensor point in the forward-facing direction. For this command to work, either initServo() or servoSelect() is called first.

- readSensor(); - Reads the distance of an object in relation to the Ultrasonic Sensor. It returns the distance as a type double. 

- bturnleft(); - Rotate DC motors backward and towards the right direction such that the robot will be facing the left direction.

- bturnright(); - Rotate DC motors backward and towards the left direction such that the robot will be facing the right direction.

- forward(int speed, int seconds); - Rotate DC motors forward. The function takes two inputs the speed at which is desired for the DC motors to spin forward and seconds which is the duration at which is desired to keep the DC motors spinning.

- backward(int speed, int seconds); - Rotate DC motors backward. The function takes two inputs the speed at which is desired for the DC motors to spin backward and seconds which is the duration at which is desired to keep the DC motors spinning.

- stop(void); - Stops DC motors from rotating forward or backward.

- right(int speed); - Sets the speed at which the right DC motor will be moving when rotating either backward or forward. This function is used in different functions like the forward(), backward(), bturnleft(),  bturnright() . etc

- left(int speed); - Sets the speed at which the left DC motor will be moving when rotating either backward or forward. This function is used in different functions like the forward(), backward(), bturnleft(),  bturnright() . etc.


## Demo

![ezgif com-gif-maker](https://user-images.githubusercontent.com/101536624/177025420-4372033d-c71a-4bb1-9afc-3974a295997c.gif)
