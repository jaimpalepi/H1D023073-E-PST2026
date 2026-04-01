# Penjelasan Program `tugas_akhir.ino`

Program ini bertujuan untuk menyalakan 6 LED secara bergantian, dibagi menjadi dua grup: tiga LED di sisi kiri dan tiga LED di sisi kanan.

## Pembagian Pin

- **Grup Kiri**: Terdiri dari 3 LED yang terhubung ke Pin 2, 3, dan 4.
- **Grup Kanan**: Terdiri dari 3 LED yang terhubung ke Pin 5, 6, dan 7.

## Penjelasan Kode per Baris

### Variabel Global

```c++
// Array untuk pin LED grup kiri (pin 2, 3, 4)
int ledKiri[] = {2, 3, 4};
```
- **Penjelasan**: `ledKiri` adalah sebuah array (kumpulan data) yang menyimpan nomor-nomor pin untuk grup LED sebelah kiri.

```c++
// Array untuk pin LED grup kanan (pin 5, 6, 7)
int ledKanan[] = {5, 6, 7};
```
- **Penjelasan**: `ledKanan` adalah array yang menyimpan nomor-nomor pin untuk grup LED sebelah kanan.

```c++
// Durasi tunda dalam milidetik
int jeda = 500;
```
- **Penjelasan**: `jeda` adalah variabel untuk mengatur berapa lama (dalam milidetik) setiap grup LED akan menyala sebelum bergantian. 500ms = 0.5 detik.

### Fungsi `setup()`

Fungsi `setup()` hanya berjalan sekali saat Arduino pertama kali dinyalakan.

```c++
void setup() {
  // Mengatur semua pin LED kiri sebagai OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(ledKiri[i], OUTPUT);
  }
```
- **Penjelasan**: Perulangan `for` ini berjalan sebanyak 3 kali untuk mendaftarkan setiap pin dalam array `ledKiri` (pin 2, 3, 4) sebagai `OUTPUT`.

```c++
  // Mengatur semua pin LED kanan sebagai OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(ledKanan[i], OUTPUT);
  }
}
```
- **Penjelasan**: Sama seperti sebelumnya, perulangan ini mendaftarkan setiap pin dalam array `ledKanan` (pin 5, 6, 7) sebagai `OUTPUT`.

### Fungsi `loop()`

Fungsi `loop()` berjalan terus-menerus setelah `setup()` selesai.

```c++
void loop() {
  // 1. Nyalakan grup LED kiri, matikan grup kanan
  nyalakanGrup(ledKiri);
  matikanGrup(ledKanan);
```
- **Penjelasan**: Memanggil fungsi `nyalakanGrup` untuk menyalakan semua LED kiri dan `matikanGrup` untuk memastikan semua LED kanan mati.

```c++
  // Tahan selama durasi 'jeda'
  delay(jeda);
```
- **Penjelasan**: Program berhenti sejenak selama 500 milidetik, membiarkan grup LED kiri tetap menyala.

```c++
  // 2. Nyalakan grup LED kanan, matikan grup kiri
  nyalakanGrup(ledKanan);
  matikanGrup(ledKiri);
```
- **Penjelasan**: Memanggil fungsi `nyalakanGrup` untuk menyalakan semua LED kanan dan `matikanGrup` untuk mematikan semua LED kiri.

```c++
  // Tahan selama durasi 'jeda'
  delay(jeda);
}
```
- **Penjelasan**: Program kembali berhenti sejenak selama 500 milidetik, membiarkan grup LED kanan menyala. Setelah ini, `loop()` akan mengulang dari awal.

### Fungsi Tambahan

Untuk membuat kode lebih rapi, dibuat dua fungsi bantuan.

```c++
// Fungsi untuk menyalakan semua LED dalam satu grup
void nyalakanGrup(int pins[]) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins[i], HIGH);
  }
}
```
- **Penjelasan**: Fungsi ini menerima sebuah array pin sebagai input. Perulangan `for` kemudian menyalakan (`HIGH`) setiap pin yang ada di dalam array tersebut.

```c++
// Fungsi untuk mematikan semua LED dalam satu grup
void matikanGrup(int pins[]) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins[i], LOW);
  }
}
```
- **Penjelasan**: Fungsi ini bekerja seperti `nyalakanGrup`, tetapi tugasnya adalah untuk mematikan (`LOW`) setiap pin yang ada di dalam array input.
