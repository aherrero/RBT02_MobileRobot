byte PWM_SERVO_1 = 10;
byte PWM_SERVO_2 = 9;
 
int pwm_value_1;
int pwm_value_2;
 
void setup() {
  pinMode(PWM_SERVO_1, INPUT);
  pinMode(PWM_SERVO_2, INPUT);
  Serial.begin(115200);
}
 
void loop() {
  pwm_value_1 = pulseIn(PWM_SERVO_1, HIGH);
  pwm_value_2 = pulseIn(PWM_SERVO_2, HIGH);
  Serial.print("THRO: ");
  Serial.print(pwm_value_1);
  Serial.print(", AILE: ");
  Serial.println(pwm_value_2);
}
