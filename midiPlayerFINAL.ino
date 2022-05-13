#include <MIDI.h>
#include <Servo.h>
Servo aimServo;
Servo strikeServo;
const int aimPin = 9;
const int strikePin = 10;
#define melodyPin 12
#define NoteOn  9
#define DURATION 50

MIDI_CREATE_DEFAULT_INSTANCE();


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(1200);
  aimServo.attach(aimPin);
  strikeServo.attach(strikePin);
}

void loop() {
  if (MIDI.read()){
      if(MIDI.getType() >>4 == NoteOn){ //get the 4 most significant bits
        int note = MIDI.getData1();
        playNote(note);
    }
}
    
}

  void playNote(int note){
      boolean isHigh = (note >= 72);
      
      note = note % 12;

      if(isHigh && note == 0) note = 12;
      
      switch(note){
        case 0: //C5
          tone(melodyPin, 523, DURATION);
          aimServo.write(48);
          strike();
          break;
          
        case 2: //D
          tone(melodyPin, 587, DURATION);
          aimServo.write(58);
          strike();
          break;
          
        case 4: //E
          tone(melodyPin, 659, DURATION);
          aimServo.write(68);
          strike();
          break;
          
        case 5: //F
          tone(melodyPin, 698, DURATION);
          aimServo.write(85);
          strike();
          break;
         
        case 7: //G
          tone(melodyPin, 784, DURATION);
          aimServo.write(95);
          strike();
          break;
          
        case 9: //A
          tone(melodyPin, 880, DURATION);
          aimServo.write(105);
          strike();
          break;
          
        case 11: //B
          tone(melodyPin, 988, DURATION);
          aimServo.write(117);
          strike();
          break;
          
        case 12: //C6
          tone(melodyPin, 1047, DURATION);
          aimServo.write(130);
          strike();
          break;
      }
    }

    void strike(){
      delay(200);
      strikeServo.write(60);
      delay(100);
      strikeServo.write(80);
      delay(100);
   }
