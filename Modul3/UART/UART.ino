#include <Arduino.h>

const int PIN_LED = 12;

// Variabel untuk blink non-blocking
bool blinkActive = false;
unsigned long previousMillis = 0;
const long blinkInterval = 500;
bool ledState = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Ketik &#39;1&#39; nyala, &#39;0&#39; mati, &#39;2&#39; blink (sampai perintah baru)");
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // Handle serial input (prioritas tinggi, override blink)
  if (Serial.available() > 0) {
    char data = Serial.read();
    if (data == &#39;1&#39;) {
      digitalWrite(PIN_LED, HIGH);
      Serial.println("LED ON");
      blinkActive = false;
    }
    else if (data == &#39;0&#39;) {
      digitalWrite(PIN_LED, LOW);
      Serial.println("LED OFF");
      blinkActive = false;
    }
    else if (data == &#39;2&#39;) {
      blinkActive = true;
      Serial.println("LED BLINK aktif (kirim &#39;1&#39;/&#39;0&#39; untuk stop)");
    }
    else if (data != &#39;\\n&#39; &amp;&amp; data != &#39;\\r&#39;) {
      Serial.println("Perintah tidak dikenal");
    }
  }

  // Handle blink jika aktif
  if (blinkActive) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(PIN_LED, ledState);
    }
  }
}
