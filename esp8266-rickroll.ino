#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <SimpleTimer.h>

#define CHANGE_SSID_MS  (10 * 1000)
#define PASSWORD "RickAstley"
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

SimpleTimer timer;
uint8_t currentPhrase = 0;

const char* phrases[] = {
  "Never gonna give you up",
  "Never gonna let you down",
  "Never gonna run around and desert you",
  "Never gonna make you cry",
  "Never gonna say goodbye",
  "Never gonna tell a lie and hurt you"
};

void setup() {
  
  delay(1000);
  Serial.begin(115200);
  
  WiFi.hostname("ESP-RickRoll");
  WiFi.mode(WIFI_AP);

  timer.setInterval(CHANGE_SSID_MS, []() {
    WiFi.begin(phrases[currentPhrase], PASSWORD);
    currentPhrase = (currentPhrase++) % ARRAY_SIZE(phrases);
  });
}

void loop() {
  timer.run();
}
