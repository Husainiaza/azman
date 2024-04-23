#define buzzer 25
#define ds1820 15
#define relay1 26
#define relay2 27

int led1=12;

void setup() {
pinMode(buzzer,OUTPUT);
pinMode(ds1820,OUTPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(led1,OUTPUT);

}

void loop() {

digitalWrite(led1,HIGH);
delay(500);
digitalWrite(led1,LOW);
delay(500);
}

