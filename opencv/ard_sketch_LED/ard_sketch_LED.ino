int LED_pin=13;
char receivedOptionChar;
boolean newData = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting up!");
  pinMode(LED_pin,OUTPUT);
  digitalWrite(LED_pin,HIGH);
}

int recvChar() {
 if (Serial.available() > 0) {
  receivedOptionChar = Serial.read();
  if(receivedOptionChar != '\n')
    newData = true;
    return 1;
  }
  return 0;
}
void cleanup(){
  receivedOptionChar = char("");
  newData = false;
}
void loop() {
  if(recvChar()==1){
    if(receivedOptionChar == '1'){
      digitalWrite(LED_pin,HIGH);
    }
    else if(receivedOptionChar == '0'){
      digitalWrite(LED_pin,LOW);
    }
  };
  cleanup();
}
