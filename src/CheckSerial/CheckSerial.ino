/*
  ThorinDev / Chris Nethercott
  Check Serial
*/

const int tx = 1;
const int rx = 0;
char inSerial[15];

void setup() {
  Serial.begin(9600);

  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
}

void loop() {
  int i = 0;
  int m = 0;
  
  delay(500);

  if(Serial.available() > 0) {
    while(Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    CheckProtocol(inSerial);
  }
}

void CheckProtocol(char inStr[]) {
  int i = 0;
  int m = 0;

  Serial.println(inStr);

  if(!strcmp(inStr,"hello")) {
    Serial.println("World");
    //You can have anything here. Turning a relay on/led
    for(m = 0; m < 11; m++) {
      inStr[m] = 0;
    }
    i = 0;
  }
}
