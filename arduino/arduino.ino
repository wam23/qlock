#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "secret.h" // ssid and password
/*
 * ESP8266
 * https://makesmart.net/esp8266-http-get-request/
 * http://worldtimeapi.org/api/timezone/Europe/Zurich
 */
WiFiClient client;
HTTPClient http;

int hour = 0;
int minute = 0;
int second = 0;

void updateSeconds()
{
  static const unsigned long REFRESH_INTERVAL = 1000; // ms
  static unsigned long lastRefreshTime = 0;

  if (millis() - lastRefreshTime >= REFRESH_INTERVAL)
  {
    lastRefreshTime += REFRESH_INTERVAL;
    second++;
    if (second >= 60)
    {
      second = 0;
      minute++;
    }
    if (minute >= 60)
    {
      minute = 0;
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
  Serial.print("Start Wifi");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print(".");
  }
  Serial.println("Connected");

  if (http.begin(client, "http://worldtimeapi.org/api/timezone/Europe/Zurich"))
  {

    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK)
    {
      String payload = http.getString();
      //Serial.println(payload);
      Serial.printf("old: %d:%d:%d\n", hour, minute, second);
      int start = payload.indexOf("datetime");
      hour = payload.substring(start + 22, start + 24).toInt();
      minute = payload.substring(start + 25, start + 27).toInt();
      second = payload.substring(start + 28, start + 30).toInt();
      Serial.printf("new: %d:%d:%d\n", hour, minute, second);
    }
    else
    {
      Serial.printf("HTTP-Error: ", http.errorToString(httpCode).c_str());
    }

    http.end();
    Serial.println("Disconnected Wifi");
  }
  else
  {
    Serial.printf("HTTP failed");
  }
}

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
