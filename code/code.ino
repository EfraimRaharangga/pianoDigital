#include <LiquidCrystal.h>

// Inisialisasi pin untuk LCD
LiquidCrystal lcd(6, 7, 8, 9, 10, 11, 12, 13, A0, A1);

// Pin untuk LED
const int greenLED = 4;
const int yellowLED = 3;
const int redLED = 2;

// Pin untuk buzzer
const int buzzer = A3;

// Pin untuk sensor ultrasonik
const int trigPin = A4;
const int echoPin = A5;

// Variabel untuk kedalaman
float distance = 0;

void setup() {
  // Inisialisasi pin
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Inisialisasi LCD
  lcd.begin(16, 2);
  lcd.print("Depth: ");
}

void loop() {
  // Mengukur kedalaman dengan sensor ultrasonik
  distance = measureDistance();

  // Menampilkan kedalaman pada LCD
  lcd.setCursor(7, 0);
  lcd.print(distance);
  lcd.print(" cm   ");

  // Logika untuk LED dan buzzer
  if (distance < 100) { // Di bawah 1 meter
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    playBuzzer(1); // Bunyi pendek
  } else if (distance < 200) { // Di bawah 2 meter
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    playBuzzer(2); // Bunyi panjang
  } else { // Di atas 2 meter
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    playBuzzer(3); // Bunyi sangat panjang
  }

  delay(500); // Delay 500ms sebelum loop berikutnya
}

// Fungsi untuk mengukur jarak
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2; // Konversi durasi ke jarak dalam cm
  return distance;
}

// Fungsi untuk memutar buzzer
void playBuzzer(int mode) {
  if (mode == 1) { // Bunyi pendek
    ; // 1000Hz selama 200ms
    delay(300);
  } else if (mode == 2) { // Bunyi panjang
   ; // 1000Hz selama 500ms
    delay(600);
  } else if (mode == 3) { // Bunyi sangat panjang
    tone(buzzer, 1000, 1000); // 1000Hz selama 1000ms
    delay(1100);
  }
}
