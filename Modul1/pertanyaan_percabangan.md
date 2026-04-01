# Pertanyaan dan Jawaban untuk `percabangan.ino`

### 1. Jelaskan apa yang dilakukan oleh program pada file `percabangan.ino`!
Program ini mengontrol sebuah LED yang terhubung ke pin 12. LED tersebut akan berkedip, dimulai dari kecepatan yang lambat (delay 1 detik) dan secara bertahap menjadi lebih cepat. Setelah mencapai kecepatan kedip tercepat (delay 0.1 detik), program akan berhenti sejenak selama 3 detik, lalu mengulang seluruh siklus dari awal.

### 2. Variabel apa saja yang digunakan dalam program dan apa fungsinya?
- **`const int ledPin = 12;`**: Ini adalah konstanta integer yang nilainya tidak bisa diubah. Fungsinya adalah untuk mendefinisikan bahwa LED terhubung pada pin digital nomor 12.
- **`int timeDelay = 1000;`**: Ini adalah variabel integer yang nilainya bisa berubah. Fungsinya adalah untuk menyimpan nilai durasi jeda (delay) dalam milidetik. Nilai awalnya adalah 1000 milidetik (1 detik) dan akan berkurang seiring berjalannya program untuk mempercepat kedipan LED.

### 3. Jelaskan bagaimana kondisi `if-else` mempengaruhi jalannya program!
Struktur `if-else` pada program ini berfungsi sebagai pengontrol kecepatan kedipan LED dan mekanisme untuk mereset siklus.
- **`if (timeDelay <= 100)`**: Program akan memeriksa apakah nilai `timeDelay` sudah mencapai 100 atau kurang. Jika ya, artinya LED sudah mencapai kecepatan kedip maksimum. Program kemudian akan menjalankan kode di dalam blok `if`: berhenti selama 3 detik (`delay(3000);`) dan mereset `timeDelay` kembali ke nilai awal (`timeDelay = 1000;`).
- **`else`**: Jika kondisi `if` tidak terpenuhi (artinya `timeDelay` masih lebih besar dari 100), maka program akan menjalankan kode di dalam blok `else`: mengurangi nilai `timeDelay` sebanyak 100 (`timeDelay -= 100;`). Ini membuat durasi kedipan pada siklus berikutnya menjadi lebih singkat (lebih cepat).

### 4. Apa yang terjadi ketika nilai `timeDelay` mencapai 100?
Ketika `timeDelay` mencapai nilai 100, LED akan menyelesaikan satu siklus kedip dengan kecepatan tersebut (100ms nyala, 100ms mati). Setelah itu, pada pengecekan kondisi berikutnya, `if (timeDelay <= 100)` akan bernilai benar (`true`). Akibatnya, program akan berhenti selama 3 detik dan kemudian nilai `timeDelay` diatur ulang menjadi 1000 untuk memulai siklus dari awal lagi.

### 5. Berapa lama jeda waktu sebelum program mengulang dari awal setelah mencapai kecepatan kedip maksimum?
Jeda waktu sebelum program mengulang dari awal adalah 3000 milidetik atau 3 detik. Ini ditentukan oleh perintah `delay(3000);` yang ada di dalam blok `if`.
