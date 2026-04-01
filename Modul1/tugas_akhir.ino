// Array untuk pin LED grup kiri (pin 2, 3, 4)
int ledKiri[] = {2, 3, 4};
// Array untuk pin LED grup kanan (pin 5, 6, 7)
int ledKanan[] = {5, 6, 7};
// Durasi tunda dalam milidetik
int jeda = 500;

void setup() {
  // Mengatur semua pin LED kiri sebagai OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(ledKiri[i], OUTPUT);
  }
  // Mengatur semua pin LED kanan sebagai OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(ledKanan[i], OUTPUT);
  }
}

void loop() {
  // 1. Nyalakan grup LED kiri, matikan grup kanan
  nyalakanGrup(ledKiri);
  matikanGrup(ledKanan);
  // Tahan selama durasi 'jeda'
  delay(jeda);

  // 2. Nyalakan grup LED kanan, matikan grup kiri
  nyalakanGrup(ledKanan);
  matikanGrup(ledKiri);
  // Tahan selama durasi 'jeda'
  delay(jeda);
}

// Fungsi untuk menyalakan semua LED dalam satu grup
void nyalakanGrup(int pins[]) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins[i], HIGH);
  }
}

// Fungsi untuk mematikan semua LED dalam satu grup
void matikanGrup(int pins[]) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins[i], LOW);
  }
}
