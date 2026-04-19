# Jawaban Pertanyaan UART

## 1) Jelaskan proses dari input keyboard hingga LED menyala/mati!
Proses:
1. User ketik char ('1' atau '0') di Serial Monitor dan tekan Enter.
2. Data dikirim via UART ke Arduino.
3. Di `loop()`: `Serial.available() > 0` terdeteksi.
4. `Serial.read()` baca char.
5. Jika '1': `digitalWrite(PIN_LED, HIGH)` nyalakan LED, print \"LED ON\".
6. Jika '0': `digitalWrite(PIN_LED, LOW)` matikan LED, print \"LED OFF\".
7. Loop berulang, tunggu input berikutnya.

## 2) Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika baris tersebut dihilangkan?
- **Mengapa?** `Serial.available()` cek apakah ada data byte di buffer serial yang siap dibaca. Hindari blok/blind read.
- **Jika dihilangkan?** `Serial.read()` akan return -1 (no data) terus-menerus atau baca garbage/noise, causing wrong LED control dan spam print.

## 3) Modifikasi program sudah dilakukan di UART.ino. Lihat README.md untuk penjelasan baris per baris.

## 4) Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem
- **Gunakan millis()!**
  - **delay()**: Blokir eksekusi (selama delay, tidak cek serial input baru). LED blink kasar, input '1'/'0' tertunda.
  - **millis()**: Non-blocking, cek waktu relatif. `loop()` tetap responsif untuk serial, blink smooth tanpa ganggu input lain.

