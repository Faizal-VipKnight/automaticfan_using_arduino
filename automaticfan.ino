int trig = 7;   //ultrasonic trig pin (conncet to pin 7 arduino/esp)
int echo = 8;   //ultrasonic echo pin (conncet to pin 8 arduino/esp)
byte fan = 6;   //mini fan connected to pin 6 arduino uno (conncet to pin 6 arduino/esp)

long duration;
float distance;

void setup() {
  
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(fan, OUTPUT);
}

void loop() {
digitalWrite(trig, LOW);
delayMicroseconds(3);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration/58;  //based on ultrasonic datasheet

    if(distance < 30){
      digitalWrite(fan, HIGH);
    }else{
      digitalWrite(fan, LOW);
    }
}
