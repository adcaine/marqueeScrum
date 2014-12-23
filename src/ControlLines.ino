#define A_PIN 10
#define B_PIN 9
#define C_PIN 8
#define NUM_DECODER_PINS 3
#define ENABLE_PIN 7


#define NUM_COLS 3

int state = 0;
int decoderPins[3] = {A_PIN, B_PIN, C_PIN};

void setup(){
  for(unsigned int i = 0; i < NUM_DECODER_PINS; i++){
    pinMode(decoderPins[i], OUTPUT);
  }
  pinMode(ENABLE_PIN, OUTPUT);
}

void loop(){
  digitalWrite(ENABLE_PIN, HIGH);
  setControlLines(decoderPins, state);
  delay(1000);
  state = (++state) % (NUM_COLS - 1);  
}


void setControlLines(int pinArray[], int value){
  for(unsigned int i = 0; i < NUM_DECODER_PINS; i++){
    digitalWrite(pinArray[i], value & (1 << (NUM_DECODER_PINS - 1 - i)));
  }
}

