#include <WiFi.h>
#include <ThingSpeak.h>

#define timeSeconds 10
#define LED 26
#define PIR_pin 27

#define CHANNEL_ID 2303936

// Timer: Auxiliary variables
unsigned long now = 0;
unsigned long lastTrigger = 0;
bool startTimer = false;
bool motion = false;

// RAM movement method call
void
IRAM_ATTR set_movement()
{
    digitalWrite(led, HIGH);
    startTimer = true;
    lastTrigger = millis();
}

const char* SSID = "SAENZ- 5GHZ";   // your network SSID (name)
const char* PASS = "22091309";   // your network password

const char* APIKey = "Q02O49HHHFT16LGG";

int number = 0;
WiFiClient client;

void
setup()
{
    Serial.begin(115200);         // Initialize serial
    Serial.println("Attempting to connect");

    WiFi.begin(SSID, PASS);
    WiFi.waitForConnectResult();

    Serial.println("\nWiFi Connected.");

    while (!ThingSpeak.begin(client)) {
        ThingSpeak.begin(client);
    }   // Initialize ThingSpeak
    Serial.println("\nThingSpeak Connected.");

    pinMode(motionSensor, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(motionSensor), set_movement, RISING);

    // Set LED to LOW
    pinMode(led, OUTPUT);
    digitalWrite(26, LOW);
}

void
loop()
{
    now = millis();
    if((digitalRead(led) == HIGH) && (motion == false)) {
        Serial.println("MOTION DETECTED!!!");
        motion = true;
    }
    if(startTimer && (now - lastTrigger > (timeSeconds*1000))) {
        Serial.println("Motion stopped...");
        digitalWrite(led, LOW);
        startTimer = false;
        motion = false;
        int x = ThingSpeak.writeField(CHANNEL_ID, 1, millis(), APIKey);
    }
}
