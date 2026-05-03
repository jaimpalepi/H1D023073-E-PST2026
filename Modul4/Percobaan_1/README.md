```markdown
# Dokumentasi Modifikasi Kendali Servo

## Deskripsi Program
Program ini mengontrol posisi motor servo menggunakan potensiometer melalui mekanisme ADC. 
Terdapat modifikasi khusus pada pembatasan gerak mekanik servo.

## Penjelasan Teknis
1. **Input ADC**: Program tetap membaca nilai penuh dari potensiometer (0-1023) melalui pin A0.
2. **Mapping Skala**: Menggunakan fungsi `map(val, 0, 1023, 30, 150)`. 
   - Saat potensiometer di posisi minimal (0), servo akan berada di sudut **30°**.
   - Saat potensiometer di posisi maksimal (1023), servo akan berada di sudut **150°**.
3. **Tujuan**: Modifikasi ini berguna untuk membatasi gerak mekanis jika servo dipasang pada sistem yang memiliki hambatan fisik atau struktur yang tidak memungkinkan rotasi penuh 180 derajat.
4. **Output PWM**: Sinyal PWM dikirimkan melalui pin 9 untuk menggerakkan servo ke posisi yang telah dibatasi tersebut.
```