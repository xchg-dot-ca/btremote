/**
 * Created my Misha Lytvynyuk, xchg.ca, @2015
 */

#define left 5
#define right 3
#define up 4
#define down 2
#define trigger 7

int newCommand = -1;
int currentCommand = -1;

enum MoveValues {
  TILT_UP,
  TILT_DOWN,
  PAN_LEFT,
  PAN_RIGHT,
  STOP,
  TIGGER_ON,
  TIGGER_OFF
};

void moveHead(int direction) {  
  switch(direction) {
    case TILT_UP: digitalWrite(left,LOW); digitalWrite(right,LOW); digitalWrite(up,HIGH); digitalWrite(down,LOW); break;
    case TILT_DOWN: digitalWrite(left,LOW); digitalWrite(right,LOW); digitalWrite(up,LOW); digitalWrite(down,HIGH); break;
    case PAN_LEFT: digitalWrite(left,HIGH); digitalWrite(right,LOW); digitalWrite(up,LOW); digitalWrite(down,LOW); break;
    case PAN_RIGHT: digitalWrite(left,LOW); digitalWrite(right,HIGH); digitalWrite(up,LOW); digitalWrite(down,LOW); break;
    case STOP: digitalWrite(left,LOW); digitalWrite(right,LOW); digitalWrite(up,LOW); digitalWrite(down,LOW); break;
    case TIGGER_ON: digitalWrite(trigger,HIGH); break;
    case TIGGER_OFF: digitalWrite(trigger,LOW); break;
  }
}

void setup()
{
  Serial.begin(115200); // Opening the serial port
}

void loop() {
  if(Serial.available()) {
    newCommand = -1;
    currentCommand = -1;
  }

  while(Serial.available()) {
      newCommand = Serial.read();
  }
  
  if(newCommand != currentCommand) {
    currentCommand = newCommand;
    moveHead(currentCommand);
  }
      
  // Echo command back to Commander for DEBUGGING
  /*
  if (currentCommand != "") {
    commandLabel.concat(currentCommand);
    Serial.print(commandLabel);
  }*/     
}
