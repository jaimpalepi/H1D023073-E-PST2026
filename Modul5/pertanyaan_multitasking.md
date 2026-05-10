## 5.6.4 Pertanyaan Praktikum (Percobaan 5B: Komunikasi Task)

**1. Apakah kedua task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!**
[cite_start]Kedua task berjalan secara **concurrent**[cite: 258]. [cite_start]Mekanismenya diatur oleh *Kernel Scheduler* yang berpindah antar task `read_data` dan `display`[cite: 277]. [cite_start]Task `read_data` mengirimkan data ke antrean menggunakan `xQueueSend`, sementara task `display` mengambil data tersebut menggunakan `xQueueReceive`[cite: 289, 295]. Jika antrean kosong, task penerima akan menunggu (dalam status *blocked*) hingga data tersedia tanpa membuang siklus CPU secara sia-sia.

**2. Apakah program ini berpotensi mengalami race condition? Jelaskan!**
[cite_start]Program ini **tidak berpotensi** mengalami *race condition* karena penggunaan **Queue** (`xQueue`) sebagai media komunikasi[cite: 273, 303]. *Race condition* biasanya terjadi jika dua task mengakses variabel global yang sama secara bersamaan. [cite_start]Dengan `xQueue`, akses data dikelola secara aman oleh kernel FreeRTOS, sehingga integritas data tetap terjaga meskipun task berjalan secara bersamaan[cite: 289, 295].

**3. Modifikasilah program dengan menggunakan sensor DHT sesungguhnya sehingga informasi yang ditampilkan dinamis. Bagaimana hasilnya?**
[cite_start]Hasilnya adalah output pada Serial Monitor akan menampilkan data suhu dan kelembapan yang berubah-ubah sesuai kondisi lingkungan secara *real-time*[cite: 68]. [cite_start]Secara kode, nilai statis pada `struct readings` dalam task `read_data` diganti dengan hasil pembacaan pin sensor DHT[cite: 287, 288]. [cite_start]Data dinamis tersebut kemudian dikirim melalui `my_queue` dan ditampilkan oleh task `display` sesuai jadwal yang ditentukan oleh scheduler[cite: 295, 297, 299].