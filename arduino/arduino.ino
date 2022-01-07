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

  led_setup();
  //timer_setup();
  //wifi_setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  led_loop();
  //timer_loop();
  //wifi_loop();
}
