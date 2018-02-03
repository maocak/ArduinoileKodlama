const int right_led=2;
const int left_led=3;

const int enablePin=4;
const int motor1Pin=5;
const int motor2Pin=6;

const int switchPin=8;
const int pot=0;
int value=0;
 
void setup() {
// put your setup code here, to run once:
pinMode(right_led,OUTPUT);
pinMode(left_led,OUTPUT);

pinMode(switchPin, INPUT);

pinMode(motor1Pin,OUTPUT);
pinMode(motor2Pin, OUTPUT);
pinMode(enablePin,OUTPUT);
}

void loop() {

// put your main code here, to run repeatedly:
value=analogRead(pot);
value=map(value,0,1024,0,255);
analogWrite(enablePin, value);
delay(10);

if(digitalRead(switchPin)== HIGH)
{
digitalWrite(motor1Pin,LOW);
digitalWrite(motor2Pin,HIGH);
digitalWrite(right_led, HIGH);
digitalWrite(left_led, LOW);
}
else
{
digitalWrite(motor1Pin, HIGH);
digitalWrite(motor2Pin, LOW);
digitalWrite(right_led, LOW);
digitalWrite(left_led, HIGH);
}
}
