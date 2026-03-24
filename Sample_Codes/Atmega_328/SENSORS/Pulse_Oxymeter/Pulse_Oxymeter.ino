#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include "SoftwareSerial.h"


#define REPORTING_PERIOD_MS     1000
SoftwareSerial esp(3, 2); // RX, TX

PulseOximeter pox;

uint32_t tsLastReport = 0;

// Callback (registered below) fired when a pulse is detected
void onBeatDetected()
{
    Serial.println("Beat!");
}

void setup()
{
    Serial.begin(9600);
    esp.begin(9600);

    Serial.print("Initializing pulse oximeter..");
   
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }

   
    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop()
{
    // Make sure to call update as fast as possible
    pox.update();

    // Asynchronously dump heart rate and oxidation levels to the serial
    // For both, a value of 0 means "invalid"
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        // Serial.print("Heart rate:");
        // Serial.print(pox.getHeartRate());
        // Serial.print("bpm / SpO2:");
        // Serial.print(pox.getSpO2());
        // Serial.println("%");
        float HR = pox.getHeartRate();
        float SPO2 = pox.getSpO2();

        String payload = "{\"HR\":" + String(HR) + "\"SPO2\":" + String(SPO2) + "}";
        Serial.println(payload);

        esp.println(payload);

        tsLastReport = millis();
    }
}
