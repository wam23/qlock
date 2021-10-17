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
