
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "ELWmKBLk35vYSEyz5qzZQY26Ipkrfhv1"; // token setelah create project
char ssid[] = "1245"; // SSID HP yang dipakai teathering
char pass[] = "lalalayeyeye"; // password

Servo servo;

//kendali melalui slider
BLYNK_WRITE(V0) {
servo.write(param.asInt());
}

//kendali melalui button untuk rotasi ke kanan
BLYNK_WRITE(V1) {
  int sudut;
  if (sudut = 0){
    servo.write(sudut);
  } else {
    servo.write(180);
  }
}

//kendali melalui button untuk rotasi ke kiri
BLYNK_WRITE(V2) {
  int sudut;
  if (sudut = 0){
    servo.write(sudut);
  } else {
    servo.write(-180);
  }
}

void gerakRotasi(){
  int sudut = 0;
  for (sudut = 0; sudut < 180; sudut+=1){
    servo.write(sudut);
    delay(10);
  }
  for (sudut = 180; sudut >= 1; sudut-=1){
    servo.write(sudut);
    delay(10);
  }
}

//kendali melalui button untuk rotasi looping
BLYNK_WRITE(V3) {
  if(param.asInt() == 1) {     // if Button sends 1
    gerakRotasi();// start the function
  }
}

void setup() {
  // put your setup code here, to run once:
  //Debug console 
  //Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(2); //pin D4
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
