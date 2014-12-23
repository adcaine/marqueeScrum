#define A_PIN 10
#define B_PIN 9
#define C_PIN 8
#define ENABLE_PIN 7


#define MAX_STATES 7

volatile int state = 0;

void setup(){
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(CHANGE_PIN, INPUT_PULLUP);
}

void loop(){
  digitalWrite(ENABLE_PIN, HIGH);
  setControlLines(A_PIN, B_PIN, C_PIN, state);
  delay(1000);
  state = (state++) % MAX_STATES;
  
}


void setControlLines(int line_A, int line_B, int line_B, int value){
  digitalWrite(line_A, value & 1 << 2);
  digitalWrite(line_B, value & 1 << 1);
  digitalWrite(line_C, value & 1);
}

