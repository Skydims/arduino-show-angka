// Deklarasi pin segmen (A-G)
const int segA = 13;
const int segB = 12;
const int segC = 11;
const int segD = 10;
const int segE = 9;
const int segF = 8;
const int segG = 7;

// Deklarasi pin common cathode untuk dua display
const int digit1 = 3; // Display pertama (puluhan)
const int digit2 = 2; // Display kedua (satuan)

// Pola angka untuk common cathode 7-segment
const byte numbers[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

// Fungsi untuk menampilkan pola segmen pada display
void displayDigit(byte value) {
  digitalWrite(segA, value & 0b00000001);
  digitalWrite(segB, value & 0b00000010);
  digitalWrite(segC, value & 0b00000100);
  digitalWrite(segD, value & 0b00001000);
  digitalWrite(segE, value & 0b00010000);
  digitalWrite(segF, value & 0b00100000);
  digitalWrite(segG, value & 0b01000000);
}

void setup() {
  // Atur semua pin segmen sebagai output
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  // Atur pin common cathode sebagai output
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);

  // Matikan semua segmen dan digit di awal
  digitalWrite(digit1, HIGH); // Common cathode LOW = aktif
  digitalWrite(digit2, HIGH); 
}

void loop() {
  for (int i = 1; i <= 45; i++) { // Loop angka 1-45
    int tens = i / 10;  // Angka puluhan
    int ones = i % 10;  // Angka satuan

    // Multiplexing kedua digit
    for (int j = 0; j < 50; j++) { // Ulang untuk membuat angka terlihat stabil
      // Tampilkan digit puluhan
      digitalWrite(digit1, LOW); // Aktifkan digit 1
      displayDigit(numbers[tens]);
      delay(5);
      digitalWrite(digit1, HIGH); // Nonaktifkan digit 1

      // Tampilkan digit satuan
      digitalWrite(digit2, LOW); // Aktifkan digit 2
      displayDigit(numbers[ones]);
      delay(5);
      digitalWrite(digit2, HIGH); // Nonaktifkan digit 2
    }
  }
}

