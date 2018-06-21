//define,include
//#include <SoftwareSerial.h>
#define LED 13
//SoftwareSerial bt(10,11);
int init_interval = 1000;
int delta = 200;
int interval = 0;
int cmd_length = 0;
int index = 0;
//setup
void setup()
{
  pinMode(LED,OUTPUT);
  int interval = init_interval;
  Serial.begin(9600); 
  //Serial.bt(9600);
}

//loop
void loop()
{
  blink();
  change();
  check();
}
void blink()
{
  digitalWrite(LED,HIGH);
  delay(interval);
  digitalWrite(LED,LOW);
  delay(1000);
}
void change()
{
  if(interval>delta){
    interval = interval-delta;
  }else{
    interval = init_interval;
  }
  Serial.print("Interval =");
  Serial.println(interval);
}
void check()
{
  index=0;
  cmd_length = Serial.available();
  Serial.print("Now Arduino buffer has num : ");
  Serial.println(cmd_length);
  char cmd[index];
  //init_array(cmd);
  
  if(cmd_length>0)
  {
    while(index<cmd_length)
    {
      cmd[index] = Serial.read();
      index++;
    }
      init_interval = atoi(cmd);
    }
}
/*void init_array(char input_array)
{
  index = 0;
  input_array[index] = '\0'
  index++;
}*/