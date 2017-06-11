#include <Arduino.h>
#include <Homie.h>
#include <SoftwareSerial.h>

const int PIN_TX = 4; // display rx pin
const int PIN_RX = 5; // not used

SoftwareSerial sws(PIN_RX, PIN_TX);

HomieNode lightNode("disp", "disp");

bool textHandler(String value) {
    Serial.print("Text: ");
    Serial.println(value);

    sws.print(value);

    Homie.setNodeProperty(lightNode, "text", value);
    return true;
}

void setup() {
    sws.begin(9600);

    delay(100);
    sws.print("v"); // cmd to reset display

    Homie.setFirmware("esp8266-display", "1.0.0");

    lightNode.subscribe("text", textHandler);
    Homie.registerNode(lightNode);
    Homie.setup();
}

void loop() {
    Homie.loop();
}
