#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "secret.h"

/*
 * https://makesmart.net/esp8266-http-get-request/
 * http://worldtimeapi.org/api/timezone/Europe/Zurich
 */

WiFiClient client;
HTTPClient http;

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
