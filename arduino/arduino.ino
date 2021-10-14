/*
 * ESP8266
 * https://makesmart.net/esp8266-http-get-request/
 * http://worldtimeapi.org/api/timezone/Europe/Zurich
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  String datetime = "2021-10-14T22:03:52.040778+02:00";
  String hour = datetime.substring(11, 13);
  String min = datetime.substring(14, 16);

  Serial.println(hour + ":" + min);
}

void loop() {
  // put your main code here, to run repeatedly:

}
