# Penjelasan Modifikasi Program UART.ino (LED Blink on '2')

Program dimodifikasi agar LED berkedip terus-menerus saat menerima '2' sampai perintah baru ('1'/'0'). Menggunakan `millis()` untuk non-blocking blink (interval 500ms). Perintah baru override blink.

## Kode Lengkap dengan Penjelasan Baris per Baris:

```
1: #include <Arduino.h>  // Include library Arduino core untuk fungsi dasar.
2: 
3: const int PIN_LED = 12;  // Pin LED didefinisikan sebagai konstanta.
4: 
5: // Variabel untuk blink non-blocking
6: bool blinkActive = false;  // Status apakah mode blink aktif (true=on).
7: unsigned long previousMillis = 0;  // Waktu terakhir flip LED (ms).
8: const long blinkInterval = 500;  // Interval kedip (500ms = 1Hz).
9: bool ledState = false;  // State saat ini LED (false=off).
10: 
11: void setup() {
12:   Serial.begin(9600);  // Inisialisasi serial communication baud 9600.
13:   Serial.println(\"Ketik '1' nyala, '0' mati, '2' blink (sampai perintah baru)\");  // Instruksi user.
14:   pinMode(PIN_LED, OUTPUT);  // Set pin sebagai output.
15: }
16: 
17: void loop() {
18:   // Handle serial input (prioritas tinggi, override blink)
19:   if (Serial.available() > 0) {
20:     char data = Serial.read();  // Baca input char.
21:     if (data == '1') {
22:       digitalWrite(PIN_LED, HIGH);  // Nyalakan LED.
23:       Serial.println(\"LED ON\");
24:       blinkActive = false;  // Stop blink.
25:     }
26:     else if (data == '0') {
27:       digitalWrite(PIN_LED, LOW);  // Matikan LED.
28:       Serial.println(\"LED OFF\");
29:       blinkActive = false;  // Stop blink.
30:     }
31:     else if (data == '2') {
32:       blinkActive = true;  // Aktifkan mode blink.
33:       Serial.println(\"LED BLINK aktif (kirim '1'/'0' untuk stop)\");
34:     }
35:     else if (data != '\\n' && data != '\\r') {
36:       Serial.println(\"Perintah tidak dikenal\");
37:     }
38:   }
39: 
40:   // Handle blink jika aktif
41:   if (blinkActive) {
42:     unsigned long currentMillis = millis();  // Ambil waktu sekarang.
43:     if (currentMillis - previousMillis >= blinkInterval) {  // Cek apakah sudah waktunya flip.
44:       previousMillis = currentMillis;  // Update waktu terakhir.
45:       ledState = !ledState;  // Toggle state (HIGH/LOW).
46:       digitalWrite(PIN_LED, ledState);  // Update LED.
47:     }
48:   }
49: }
```

**Penjelasan Tambahan:**
- Blink override oleh '1'/'0', tapi serial tetap responsif (no delay()).
- millis() memastikan loop() jalan terus, serial check setiap iterasi ~mudah.

