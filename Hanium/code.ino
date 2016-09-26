#include <SoftwareSerial.h>
SoftwareSerial BTSerial(8, 7);
int ledPin = 13;
int vib = 4;
int sound = 1;
unsigned int anal_sound;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(vib, INPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  long measurement =TP_init();
  anal_sound = analogRead(sound);
  if (measurement > 1000){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW); 
  }
  Serial.print("Viberate : ");
  Serial.println(measurement);
  Serial.print("Sound : ");
  Serial.println((anal_sound));
  BTSerial.print("Viberate : ");
  BTSerial.println(measurement);
  BTSerial.print("Sound : ");
  BTSerial.println((anal_sound));
  delay(10);
}
long TP_init(){
  long measurement=pulseIn (vib, HIGH);
  return measurement;
}
