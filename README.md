# Proyek Piano Digital

Proyek ini merupakan implementasi piano digital menggunakan Arduino Nano. Piano ini menghasilkan nada berdasarkan tombol yang ditekan dan memainkannya melalui buzzer.

## Fitur
- 17 tombol yang merepresentasikan nada musik (C4 hingga E5).
- Penggunaan fungsi `tone()` Arduino untuk menghasilkan nada secara real-time.
- Desain yang ringkas dengan antarmuka berbasis tombol yang intuitif.

## Komponen
1. **Arduino Nano** (atau mikrokontroler yang kompatibel)
2. **Buzzer** (untuk output suara)
3. **Push Button** (17 buah sebagai tombol)
4. **Resistor** (10kΩ untuk konfigurasi pull-up)
5. Kabel jumper
6. Breadboard

## Diagram Rangkaian
1. Hubungkan setiap tombol ke pin yang telah ditentukan: 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5.
2. Sambungkan satu sisi tombol ke pin dan sisi lainnya ke ground.
3. Gunakan resistor internal pull-up dengan mengatur pin sebagai `INPUT_PULLUP`.
4. Hubungkan pin positif buzzer ke pin digital 3 dan pin negatif ke ground.

## Penjelasan Kode
Kode Arduino disusun untuk:
1. Mendefinisikan pin tombol dan frekuensi nada yang sesuai.
2. Memantau keadaan semua tombol secara kontinu.
3. Memainkan nada ketika tombol ditekan dan menghentikan nada ketika tidak ada tombol yang ditekan.

### Pemetaan Tombol
| Pin Tombol | Nada  | Frekuensi (Hz) |
|------------|-------|----------------|
| 2          | C4    | 262            |
| 4          | C#4   | 277            |
| 5          | D4    | 294            |
| ...        | ...   | ...            |
| A5         | E5    | 659            |

## Cara Menggunakan
1. Download repositori ini
2. Buka file rangkaian di simulide
3. Buka file code.ino di simulide
4. Lakukan compiling lalu upload.
5. Tekan Start Simulation
6. Tekan tombol untuk memainkan nada yang sesuai.

## Pemecahan Masalah
- **Tidak Ada Suara**: Periksa sambungan buzzer dan pastikan pin yang benar digunakan.
- **Nada Tidak Konsisten**: Pastikan tombol telah didebounce dengan baik.

## Lisensi
Proyek ini bersifat open-source dan dapat dimodifikasi serta digunakan untuk tujuan pendidikan.

