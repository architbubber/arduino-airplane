//RECIEVER//
#include <Servo.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

struct packet {
  byte posx;
  byte posy;
  byte posz;
  byte posr;
} State;

RF24 radio(9, 10);
const uint64_t pipe =183 ;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo esc;
int x;

void reset(){
posx=90;posy=90;posz=90;posr=0;
}

void setup(void) {
  esc.attach(3,1060,2000);
  myservo1.attach(7);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(8);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening(); 
reset();
}

void loop(void) {
  if (radio.available()) {
     Serial.println("radio available");
    radio.read(&State, sizeof(State));
    x=map(State.posr,0,180,1060,2000);      //esc min-max
    esc.writeMicroseconds(x) ;
    myservo1.write(State.posx);
    myservo2.write(State.posy);
    myservo3.write(State.posz);
    myservo4.write(State.posz);
    delay(5);
 
 /* Serial.print(State.posx);
    Serial.print(F(", "));
    Serial.print(State.posy);
    Serial.print(F(", "));
    Serial.print(State.posz);
    Serial.print(F(", "));
    Serial.println(x); */
  }
else{
  Serial.println("no radio available");
  reset();
    x=map(State.posr,0,180,1060,2000);      //esc min-max
    esc.writeMicroseconds(x) ;
    myservo1.write(State.posx);
    myservo2.write(State.posy);
    myservo3.write(State.posz);
    myservo4.write(State.posz);
  }
}
