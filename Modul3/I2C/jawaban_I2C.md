# Jawaban Pertanyaan I2C

## 1) Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian tersebut!

**Penjelasan:**
Komunikasi I2C (Inter-Integrated Circuit) adalah protokol serial sinkron 2-kabel (SDA untuk data, SCL untuk clock). Arduino bertindak sebagai **Master**, LCD I2C (dengan backpack PCF8574) sebagai **Slave** dengan alamat 0x27.

**Cara Kerja:**
1. Arduino (Master) kirim **START condition** (SDA low saat SCL high).
2. Kirim **alamat slave** 0x27 (7-bit) + bit R/W (0 untuk write).
3. LCD akui (ACK) dengan tarik SDA low.
4. Kirim **register command/data** (e.g., 0x80 untuk DDRAM addr, lalu data karakter).
5. Ulang untuk multiple bytes, akhiri **STOP condition** (SDA high saat SCL high).
6. Pin: SDA ke A4, SCL ke A5 (Arduino Uno), LCD dapat 5V/GND.

Library `LiquidCrystal_I2C` abstrak ini, convert fungsi seperti `lcd.print()` jadi byte sequences via Wire.h.

## 2) Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan pin kanan tertukar!

**Tidak harus persis, tapi direkomendasikan:**
- Standar: **Kiri: 5V**, **Tengah (wiper): A0**, **Kanan: GND**. Putar kiri → 0V (ADC~0), putar kanan → 5V (ADC~1023).

**Jika kiri↔kanan tertukar (Kiri:GND, Kanan:5V):**
- Putar kiri → ~5V (ADC~1023, bar penuh).
- Putar kanan → ~0V (ADC~0, bar kosong).
- Efek: **Baris visual terbalik** (putar searah jarum jam naik level, bukan berlawanan). ADC masih akurat baca voltage 0-5V, fungsi sama tapi intuisi terbalik. Tidak rusak hardware.

## 3) Modifikasi program dengan menggabungkan antara UART dan I2C (keduanya sebagai output)...

**Kode Modifikasi (copy-paste ke Arduino IDE, compile & upload ke I2C.ino atau file baru):**

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>  // Opsional, untuk compatibility

// Inisialisasi LCD I2C alamat 0x27, 16 kolom x 2 baris.
// Ganti 0x27 jika LCD Anda 0x3F (scan dengan I2C scanner).
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinPot = A0;  // Pin ADC untuk potensiometer (wiper ke A0)

void setup() {
  Serial.begin(9600);  // Inisialisasi UART Serial Monitor (baud 9600)
  lcd.init();          // Inisialisasi LCD I2C
  lcd.backlight();     // Nyalakan backlight LCD
}

void loop() {
  int nilai = analogRead(pinPot);              // Baca nilai ADC (0-1023) dari potensiometer

  // Hitung voltase (5V reference Arduino Uno)
  float volt = nilai * 5.0 / 1023.0;           
  // Hitung persentase (0-100%)
  int persen = round((volt / 5.0) * 100);      

  // OUTPUT UART ke Serial Monitor (format tepat seperti table)
  Serial.print("ADC: ");                    
  Serial.print(nilai);                             
  Serial.print(" Volt: ");                  
  Serial.print(volt, 2);  // 2 desimal                  
  Serial.print(" V Persen: ");              
  Serial.print(persen);                            
  Serial.println("%");                       

  // OUTPUT I2C ke LCD (sama seperti original: ADC di baris 1, bar di baris 2)
  // Baris 1: ADC value
  lcd.setCursor(0, 0);  // Posisi cursor kolom 0, baris 0
  lcd.print("ADC: "); 
  lcd.print(nilai);     
  lcd.print("   ");  // Clear sisa karakter (3 spasi cukup untuk 1023)

  // Baris 2: Bar graph (map 0-1023 ke 0-16 blok)
  int panjangBar = map(nilai, 0, 1023, 0, 16);  // Scale ke lebar LCD 16 char
  lcd.setCursor(0, 1);  // Cursor baris 1
  for (int i = 0; i < 16; i++) {
    if (i < panjangBar) {
      lcd.print((char)255);  // Custom char block/full (pastikan definisikan jika perlu)
    } else {
      lcd.print(" ");        // Kosong
    }
  }
  
  delay(200);  // Delay 200ms untuk stabilitas tampilan
}
```

**Penjelasan Setiap Baris Kode (README-style):**
- **#include**: Library Wire untuk I2C, LiquidCrystal_I2C untuk LCD commands, Arduino.h opsional.
- **lcd(0x27,16,2)**: Object LCD, alamat I2C, ukuran.
- **pinPot = A0**: Input analog.
- **setup()**: Start Serial + LCD init/backlight.
- **loop() nilai = analogRead()**: Baca raw ADC.
- **volt & persen**: Konversi linear 10-bit ADC ke V & % (round untuk integer %).
- **Serial.print chain**: Exact format Q3 untuk pot kiri (ADC0 → ADC: 0 Volt: 0.00 V Persen: 0%).
- **lcd baris 0**: `setCursor(0,0)` posisi, print ADC.
- **map()**: Scale ke 16 char.
- **for loop bar**: Print blok (char255 = full block Unicode/ custom) atau space.
- **delay**: Hindari flicker.

**Catatan:** 
- Jika block tidak muncul, tambah custom char `lcd.createChar(0, blockArray)`.
- Format Serial match pot kiri contoh.

## 4) Lengkapi table berikut...

| ADC | Volt | Percen(%) |
|-----|------|-----------|
| 1   | 0.00 | 0         |
| 21  | 0.10 | 2         |
| 49  | 0.24 | 5         |
| 74  | 0.36 | 7         |
| 96  | 0.47 | 9         |

**Cara Hitung:** Volt = ADC * 5/1023 (~0.00489*ADC), % = round(Volt/5 *100). Match Serial output.

**Test:** Upload kode, putar pot, bandingkan LCD/Serial.

