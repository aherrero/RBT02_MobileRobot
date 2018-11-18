#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor motorBackRight(4);
AF_DCMotor motorBackLeft(3);

AF_DCMotor motorFrontLeft(2);
AF_DCMotor motorFrontRight(1);

byte PWM_ELEV = 10;
byte PWM_AILE = 9;

void goForwardLeft(int speed)
{
    // Serial.print(", goForwardLeft: ");
    // Serial.println(speed);

    motorBackLeft.setSpeed(speed);
    motorBackLeft.run(1);  // BL forward

    motorFrontLeft.setSpeed(speed);
    motorFrontLeft.run(1);  // BL forward
}

void goForwardRight(int speed)
{
    // Serial.print("goForwardRight: ");
    // Serial.print(speed);

    motorBackRight.setSpeed(speed);
    motorBackRight.run(2);  // 4 BR forward

    motorFrontRight.setSpeed(speed);
    motorFrontRight.run(2);  // 4 BR forward
}

void goBackwardLeft(int speed)
{
    // Serial.print("goBackward: ");
    // Serial.println(speed);

    motorBackLeft.setSpeed(speed);
    motorBackLeft.run(2);  // BL forward

    motorFrontLeft.setSpeed(speed);
    motorFrontLeft.run(2);  // BL forward
}

void goBackwardRight(int speed)
{
    // Serial.print("goBackward: ");
    // Serial.println(speed);

    motorBackRight.setSpeed(speed);
    motorBackRight.run(1);  // 4 BR backward

    motorFrontRight.setSpeed(speed);
    motorFrontRight.run(1);  // 4 BR backward
}

void moveRobot(int speedX, int turn)
{
    if(speedX >= 0)
    {
        //speedX = speedX - 255;

        if(turn >= 0)
        {
            turn = 100 - turn;
            goForwardRight(speedX * turn/100);
            goForwardLeft(speedX);
        }
        else
        {
            turn = turn + 100;
            goForwardRight(speedX);
            goForwardLeft(speedX * turn/100);
        }
    }
    else
    {
        speedX = - speedX;

        if(turn >= 0)
        {
            turn = 100 - turn;
            goBackwardRight(speedX * turn/100);
            goBackwardLeft(speedX);
        }
        else
        {
            turn = turn + 100;
            goBackwardRight(speedX);
            goBackwardLeft(speedX * turn/100);
        }
    }
}


void setup()
{
    //Serial.begin(9600);           // set up Serial library at 9600 bps
}

void loop()
{
    int pwm_value_1 = pulseIn(PWM_ELEV, HIGH);
    int pwm_value_2 = pulseIn(PWM_AILE, HIGH);

    if(pwm_value_1 != 0)
    {

        int moveX = map(pwm_value_1, 1095, 1911, -255, 255);
        int turn = - map(pwm_value_2, 1100, 1918, -100, 100);

        // Serial.print("moveX: ");
        // Serial.print(moveX);
        // Serial.print(", turn: ");

        moveRobot(moveX, turn);
    }


    delay(10);


}
