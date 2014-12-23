#define A_PIN 10
#define B_PIN 9
#define C_PIN 8
#define ENABLE_PIN 7
#define CHANGE_PIN 2

#define MAX_STATES 7

volatile int state = 0;

void change();

void setup(){
  //attachInterrupt(0, change, LOW);
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(CHANGE_PIN, INPUT_PULLUP);
}

void loop(){
  digitalWrite(ENABLE_PIN, HIGH);
  digitalWrite(A_PIN, state & 1 << 2);
  digitalWrite(B_PIN, state & 1 << 1);
  digitalWrite(C_PIN, state & 1);
  delay(1000);
  state = (state++) % MAX_STATES;
  
}

void change(){
  state = (state++) % MAX_STATES;
}
