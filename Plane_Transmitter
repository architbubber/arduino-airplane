//TRANSMITTER//
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <LiquidCrystal.h>

struct packet {
  byte posx;
  byte posy;
  byte posz;
  byte posr;
} State;

RF24 radio(9, 10);
const uint64_t pipe =183 ;

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  lcd.begin(16, 2);
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("   BUBBERSONS");
   lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("   PLANE V2.0");
  delay(1000);

}

void loop(void) {
   
    
    State.posx = map(analogRead(A0),0, 1023, 0, 180);
    State.posy = map(analogRead(A1), 0, 1023, 180, 0);
    State.posz = map(analogRead(A2), 0, 1023, 0, 180);
    State.posr =  map(analogRead(A3),0, 1023, 0, 180); //esc-min,max//
    radio.write(&State, sizeof(State));
    lcd.print(State.posx);
    
    Serial.println(State.posr);

    
    }
