# Jawaban Pertanyaan Praktikum Modul 5

## 5.5.4 Pertanyaan Praktikum (Percobaan 5A: Multitasking)

**1. Apakah ketiga task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!**
[cite_start]Ketiga task (`TaskBlink1`, `TaskBlink2`, dan `Taskprint`) berjalan secara **concurrent** atau bersamaan secara logika[cite: 150, 167]. [cite_start]Namun, pada mikrokontroler dengan satu inti (*single-core*), task tersebut sebenarnya berjalan secara bergantian dengan sangat cepat melalui pengaturan **Kernel Scheduler**[cite: 92, 106]. [cite_start]Mekanisme ini memungkinkan pembagian waktu eksekusi CPU sehingga setiap tugas tampak seolah-olah berjalan serempak tanpa ada penundaan (*buffer*) yang dirasakan pengguna[cite: 68, 70].

**2. Bagaimana cara menambahkan task keempat? Jelaskan langkahnya!**
Untuk menambahkan task keempat, langkah-langkah yang harus dilakukan adalah:
* [cite_start]Mendefinisikan fungsi task baru (misalnya `void Task4(void *pvParameters)`) yang berisi *infinite loop* `while(1)`[cite: 138, 139].
* [cite_start]Di dalam fungsi `setup()`, panggil fungsi `xTaskCreate()` untuk mendaftarkan task tersebut ke dalam sistem[cite: 122, 182].
* [cite_start]Tentukan parameter yang diperlukan pada `xTaskCreate` seperti nama fungsi, nama teks task, ukuran *stack*, parameter input, prioritas, dan *task handle*[cite: 122, 123, 124, 125, 126, 127].

**3. Modifikasilah program dengan menambah sensor (misalnya potensiometer), lalu gunakan nilainya untuk mengontrol kecepatan LED! Bagaimana hasilnya?**
Hasilnya, kecepatan kedipan LED akan berubah secara dinamis sesuai dengan input nilai analog dari potensiometer. [cite_start]Secara teknis, nilai pembacaan sensor akan digunakan sebagai argumen dalam fungsi `vTaskDelay()`[cite: 216]. [cite_start]Karena sistem menggunakan RTOS, perubahan kecepatan kedipan pada satu LED tidak akan mengganggu atau menghentikan eksekusi task lainnya karena scheduler tetap membagi waktu secara konsisten[cite: 70, 150].

---

