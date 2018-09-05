//define
#include <SoftwareSerial.h>
SoftwareSerial BT(8,9);//tx=8,rx=9
char value;
int time = millis(); //millisceond
//setup
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);//pin 0,1  
  BT.begin(9600);//pin 0,1
}

//loop
void loop()
{
 if(Serial.available()>0){
  value=Serial.read();
  BT.print(value);
  Control_LED_onoff();
 }
 if(BT.available()>0){
    value=BT.read();
  Serial.print(value);
  Control_LED_onoff();
  Send_LED_status();
 }
  
 
}
void Control_LED_onoff()
{
 switch (value) {
     case 'o':
     case 'O':
       digitalWrite(13, HIGH);
       Serial.println("LED is turnning on!");
       break;
     case 'x':
     case 'X':
       digitalWrite(13, LOW);
       Serial.println("LED is turnning off!");
       break;
     default:
      Serial.println("Input O or X only!");
 }
}
void Send_LED_status()
{
  int now_time = millis();
  if((now_time - time) >= 100)     //actives every 100 milliseconds
  {
    int LED_status = digitalRead(13);  //send the status of LED to smartphone over BT
    BT.write(LED_status); 
    Serial.print("Send LED_status: ");
    Serial.println(LED_status);
  //  time = now_time;
  }
}


