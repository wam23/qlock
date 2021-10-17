#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
/*
 * ESP8266
 * https://makesmart.net/esp8266-http-get-request/
 * http://worldtimeapi.org/api/timezone/Europe/Zurich
 */

HTTPClient sender;

const char *ssid = "WLAN_SSID";
const char *password = "WLAN_PASSWD";

int hour = 0;
int min = 0;
int sec = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  String datetime = "2021-10-14T22:03:52.040778+02:00";
  String hour = datetime.substring(11, 13);
  String min = datetime.substring(14, 16);

  Serial.println(hour + ":" + min);
}

void loop()
{
  // put your main code here, to run repeatedly:
  updateSeconds();
  updateTime();
}

void updateSeconds();
{
  static const unsigned long REFRESH_INTERVAL = 1000; // ms
  static unsigned long lastRefreshTime = 0;

  if (millis() - lastRefreshTime >= REFRESH_INTERVAL)
  {
    lastRefreshTime += REFRESH_INTERVAL;
    sec++;
    if (sec >= 60)
    {
      sec = 0;
      min++;
    }
    if (min >= 60)
    {
      min = 0;
      hour++;
    }
    if (hour >= 24)
    {
      hour = 0;
    }
  }
}

void updateTime()
{
  static const unsigned long REFRESH_INTERVAL = 60 * 60 * 1000; // ms
  static unsigned long lastRefreshTime = 0;

  if (millis() - lastRefreshTime >= REFRESH_INTERVAL)
  {
    lastRefreshTime += REFRESH_INTERVAL;
    updateWebTime();
  }
}

void updateWebTime()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print(".");
  }
  Serial.println("Connected");

  if (sender.begin("http://worldtimeapi.org/api/timezone/Europe/Zurich"))
  {

    int httpCode = sender.GET();
    if (httpCode == HTTP_CODE_OK)
    {
      String payload = sender.getString();
      Serial.println(payload);
      int start = payload.indexOf("datetime");
      int hour = payload.substring(22, 24);
      int min = payload.substring(25, 27);
      int sec = payload.substring(28, 30);
    }
    else
    {
      Serial.printf("HTTP-Error: ", sender.errorToString(httpCode).c_str());
    }

    sender.end();
    Serial.println("Disconnected");
  }
  else
  {
    Serial.printf("HTTP-Verbindung konnte nicht hergestellt werden!");
  }
}
