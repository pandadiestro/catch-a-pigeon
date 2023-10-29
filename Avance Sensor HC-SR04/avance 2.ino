#include "WiFi.h"
#include "ThingSpeak.h"

const char* ssid = "<YOUR-SSID-HERE>";
const char* password =  "<YOUR-PASSWORD-HERE>";

const int trigPin = 5;
const int echoPin = 18;

WiFiClient  client;

const unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "<YOUR-API-KEY-HERE>";

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;

void setup() {
    Serial.begin(115200);

    // Esto es para la conexión a wifi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }

    // Para thingspeak
    ThingSpeak.begin(client);

    // Esto es para el sensor ultrasónico
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
    if ((millis() - lastTime) > timerDelay) {
        // Clears the trigPin
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        // Devuelve la lectura
        duration = pulseIn(echoPin, HIGH);

        // Calcula la distancia
        distanceCm = duration * SOUND_SPEED/2;

        if (distanceCm < 10) {
            int x = ThingSpeak.writeField(myChannelNumber, 1, distanceCm, myWriteAPIKey);
            if (x == 200){
                Serial.println("Channel update successful.");
            } else {
                Serial.println("Problem updating channel. HTTP error code " + String(x));
            }
        }

        // Prints the distance in the Serial Monitor
        Serial.print("Distance (cm): ");
        Serial.println(distanceCm);

        lastTime = millis();
    }
}
