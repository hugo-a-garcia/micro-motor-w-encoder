/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *motor_M1 = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *motor_M2 = AFMS.getMotor(2);

void setup()
{
    Serial.begin(115200);  // set up Serial library at 9600 bps
    Serial.setTimeout(20); // default timeout is 1000ms
    Serial.println("Adafruit Motorshield v2 - DC Motor test!");

    AFMS.begin(); // create with the default frequency 1.6KHz
    //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

    // Set the speed to start, from 0 (off) to 255 (max speed)
    motor_M1->setSpeed(0);
    motor_M1->run(FORWARD);
    // turn on motor
    motor_M1->run(RELEASE);

    // Set the speed to start, from 0 (off) to 255 (max speed)
    motor_M2->setSpeed(0);
    motor_M2->run(FORWARD);
    // turn on motor
    motor_M2->run(RELEASE);
}

void loop()
{
    uint8_t i;
    uint8_t direction;
    bool newData;

    if (Serial.available() > 0)
    {
        //receivedChar = Serial.read();
        direction = Serial.read();
        newData = true;
        // if (direction > 0 & direction <= 5) {
        //     newData = true;
        // }
        
    }
    if (newData == true)
    {
        //Serial.println(direction);
        newData = false;

        switch (direction)
        {
        case 49:
            motor_M1->run(RELEASE);
            motor_M2->run(RELEASE);
            break;
        case 50:
            motor_M1->setSpeed(127);
            motor_M1->run(FORWARD);
            motor_M2->setSpeed(127);
            motor_M2->run(FORWARD);
            break;
        case 51:
            motor_M1->setSpeed(-127);
            motor_M1->run(BACKWARD);
            motor_M2->setSpeed(-127);
            motor_M2->run(BACKWARD);
            break;
        case 52:
            motor_M1->setSpeed(-127);
            motor_M1->run(BACKWARD);
            motor_M2->setSpeed(127);
            motor_M2->run(FORWARD);
            break;
        case 53:
            motor_M1->setSpeed(127);
            motor_M1->run(FORWARD);
            motor_M2->setSpeed(-127);
            motor_M2->run(BACKWARD);
            break;
        //default:
            //Serial.println("DEFAULT");
        }
    }
}

void forward()
{
    motor_M1->run(FORWARD);
    motor_M2->run(FORWARD);
    motor_M1->setSpeed(127);
    motor_M2->setSpeed(127);
}