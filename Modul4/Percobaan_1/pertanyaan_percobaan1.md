### 1. Apa fungsi perintah analogRead() pada rangkaian praktikum ini?
Fungsi `analogRead(potensioPin)` digunakan untuk membaca tegangan analog yang masuk dari potensiometer melalui pin A0.
*   Arduino memiliki fitur **ADC 10-bit**, yang artinya perintah ini akan mengubah tegangan analog (0V hingga 5V) menjadi nilai digital (angka diskrit) dalam rentang **0 hingga 1023**.
*   Dalam rangkaian ini, nilai tersebut merepresentasikan posisi fisik dari tuas potensiometer.



### 2. Mengapa diperlukan fungsi map() dalam program tersebut?
Fungsi `map()` diperlukan karena adanya **perbedaan skala** antara input (potensiometer) dan output (servo):
*   **Input (ADC):** Memiliki rentang nilai digital dari **0 sampai 1023**.
*   **Output (Servo):** Library `Servo.h` membutuhkan input sudut dalam rentang **0 sampai 180 derajat**.

Tanpa fungsi `map()`, nilai 1023 dari potensiometer tidak bisa langsung digunakan karena melebihi batas sudut maksimal servo. Fungsi ini secara matematis menyelaraskan (menskalakan) nilai ADC agar proporsional dengan sudut servo yang diinginkan.

---

### 3. Modifikasi program berikut agar servo hanya bergerak dalam rentang 30° hingga 150°, meskipun potensiometer tetap memiliki rentang ADC 0–1023. Jelaskan program pada file README.md

Berikut adalah perubahan pada bagian fungsi `map()` agar servo hanya bergerak di rentang terbatas:

```cpp
// Bagian yang dimodifikasi pada fungsi loop
void loop() {
  val = analogRead(potensioPin);

  // Mengubah rentang output dari 0-180 menjadi 30-150
  pos = map(val, 0, 1023, 30, 150); 

  myservo.write(pos);
  
  Serial.print("ADC: ");
  Serial.print(val);
  Serial.print(" | Sudut Terbatas: ");
  Serial.println(pos);

  delay(15);
}
```

