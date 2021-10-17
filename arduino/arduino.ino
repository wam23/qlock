/*
 * Board: ESP8266
 */

int hour = 0;
int minute = 0;
int second = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup");
  
  updateWebTime(); // init with web time
}

void loop()
{
  // put your main code here, to run repeatedly:
  updateSeconds();
  updateTime();
}
