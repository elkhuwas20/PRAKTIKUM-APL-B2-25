# 🎮 GACHA HERO - MOBILE LEGENDS
## Sistem Manajemen Hero dengan User-Defined Library

---

## 📋 Daftar Isi
1. [Deskripsi Program](#deskripsi-program)
2. [Fitur Utama](#fitur-utama)
3. [Struktur File](#struktur-file)
4. [Cara Mengkompilasi](#cara-mengkompilasi)
5. [Cara Menggunakan](#cara-menggunakan)
6. [Teknologi yang Digunakan](#teknologi-yang-digunakan)
7. [Detail Implementasi](#detail-implementasi)

---

## 📖 Deskripsi Program

**Gacha Hero ML** adalah sistem manajemen hero untuk game Mobile Legends yang dikembangkan menggunakan C++ dengan **user-defined library**. Program ini menyediakan fitur lengkap untuk mengelola data hero, user authentication, searching, dan sorting dengan interface yang menarik menggunakan **colored console output**.

**Author:** Nuril Akmal (2509106074)  
**Dibuat untuk:** PRAKTIKUM APL POSTTEST 7

---

## ⭐ Fitur Utama

### 1. **User Authentication** 🔐
- **Login** dengan sistem validasi username dan password
- **Registrasi** akun pengguna baru
- **Role-based Access**: Admin dan User
- Maksimal 3 kali kesempatan login
- Exception handling untuk validasi input

### 2. **Hero Management** 🦸
- **CRUD Operations** (Create, Read, Update, Delete)
- Menambah hero baru dengan validasi data
- Menampilkan daftar hero dengan tabel terformat
- Mengupdate informasi hero
- Menghapus hero dengan konfirmasi

### 3. **Searching Algorithms** 🔍
- **Linear Search (Sequential Search)** - Cari hero berdasarkan nama dengan substring matching
- **Interpolation Search** - Cari hero berdasarkan harga dengan optimasi posisi
- **Recursive Search** - Cari hero secara rekursif
- Menampilkan trace/langkah-langkah pencarian

### 4. **Sorting Algorithms** 🔄
- **Bubble Sort** - Urutkan hero berdasarkan nama (Z-A)
- **Selection Sort** - Urutkan hero berdasarkan harga (Kecil-Besar)
- **Insertion Sort** - Urutkan hero berdasarkan win rate (Tinggi-Rendah)
- Menampilkan proses dan hasil sorting

### 5. **Exception Handling** ⚠️
- **HeroException** - Error terkait hero
- **UserException** - Error terkait user
- **InputException** - Error validasi input
- Try-catch di setiap operasi penting

### 6. **Colored Console Output** 🌈
- **Windows API** (windows.h) untuk manipulasi warna console
- 15 warna berbeda untuk UX yang menarik
- Clear screen dan pause screen functions
- Unicode support untuk karakter special (✓, ✗, ☆, dll)

---

## 📁 Struktur File

```
POSTTEST-7/
│
├── 2509106074_NurilAkmal_PT-7_main.cpp    ← Main program (entry point)
├── GachaHeroLib.h                          ← Header file library (deklarasi)
├── GachaHeroLib.cpp                        ← Implementation file library
├── build.bat                               ← Script untuk kompilasi
├── README.md                               ← Dokumentasi ini
└── GachaHeroML.exe                         ← Executable (output setelah compile)
```

### Penjelasan File:

#### **GachaHeroLib.h** (880 lines)
Header file yang berisi:
- Deklarasi struct (Hero, User, HeroStats)
- Deklarasi exception classes
- Deklarasi static methods dalam class GachaHeroLib
- Enum untuk console colors

#### **GachaHeroLib.cpp** (1100+ lines)
File implementasi library yang berisi:
- Implementasi semua fungsi library
- Console color management
- Formatting functions dengan warna
- CRUD operations untuk hero dan user
- Authentication system
- Searching algorithms dengan trace
- Sorting algorithms
- Menu functions

#### **2509106074_NurilAkmal_PT-7_main.cpp** (50 lines)
File main yang berisi:
- Global data (hero array, user array)
- Main function sederhana
- Inisialisasi program
- Memanggil library functions

---

## 🛠️ Cara Mengkompilasi

### Metode 1: Menggunakan build.bat (Recommended)
```bash
cd "POSTTEST-7"
build.bat
```

### Metode 2: Menggunakan Command Line
```bash
cd "POSTTEST-7"
g++.exe -std=c++17 -o GachaHeroML.exe GachaHeroLib.cpp 2509106074_NurilAkmal_PT-7_main.cpp
GachaHeroML.exe
```

### Metode 3: Menggunakan VS Code Build Task
- Tekan `Ctrl+Shift+B` atau gunakan menu Terminal > Run Build Task

**Requirements:**
- MinGW (g++ compiler)
- Windows OS (karena menggunakan windows.h)
- C++17 standard

---

## 📱 Cara Menggunakan

### Login Admin
1. Jalankan program
2. Pilih menu "1. Login"
3. Username: `Akmal`, Password: `074`
4. Anda akan masuk ke Admin Menu

### Login User
1. Jalankan program
2. Pilih menu "1. Login"
3. Username: `Nuril`, Password: `123` (atau user lain)
4. Anda akan masuk ke User Menu

### Default Users:
| Username | Password | Role  |
|----------|----------|-------|
| Akmal    | 074      | Admin |
| Nuril    | 123      | User  |
| Triya    | 321      | User  |
| Pernanda | 111      | User  |

### Admin Menu Operations:
- ✅ Tambah Hero Baru
- 📋 Lihat Daftar Hero
- ✏️ Update Data Hero
- ❌ Hapus Hero
- ➕ Tambah User Baru
- 📋 Lihat Daftar User
- ✏️ Update Data User
- ❌ Hapus User
- 🔍 Cari Hero (Demo Recursive)
- 🔄 Sort Hero (3 algoritma berbeda)

### User Menu Operations:
- 📋 Lihat Daftar Hero
- 🔍 Cari Hero by Nama (Linear Search)
- 🔍 Cari Hero by Harga (Interpolation Search)

### Guest Menu:
- 👁️ Melihat daftar hero tanpa login

---

## 💻 Teknologi yang Digunakan

### Libraries/Headers:
1. **windows.h** - Console color manipulation (Windows API)
2. **stdio.h** - C standard input/output
3. **string.h** - String manipulation
4. **stdlib.h** - Standard utilities
5. **ctype.h** - Character type checking
6. **stdexcept** - Exception handling

### Features:
- **Object-Oriented Programming** - Static class methods
- **Exception Handling** - Try-catch blocks
- **Custom Data Structures** - Struct untuk Hero, User, HeroStats
- **Algorithms** - Sorting, Searching, Recursive functions
- **Dynamic Memory Management** - Array-based data storage

---

## 🔧 Detail Implementasi

### 1. Console Colors (Windows API)
```cpp
void GachaHeroLib::setConsoleColor(ConsoleColor foreground, ConsoleColor background) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (background << 4) | foreground);
}
```

### 2. Sorting Algorithms

#### Bubble Sort (Nama - Descending)
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Best for: Small dataset yang hampir terurut

#### Selection Sort (Harga - Ascending)
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Best for: Minimizing writes

#### Insertion Sort (Win Rate - Descending)
- Time Complexity: O(n²) worst case, O(n) best case
- Space Complexity: O(1)
- Best for: Online sorting

### 3. Searching Algorithms

#### Linear Search (Nama)
- Time Complexity: O(n)
- Space Complexity: O(1)
- Fitur: Substring matching, case-insensitive

#### Interpolation Search (Harga)
- Time Complexity: O(log log n) average, O(n) worst
- Space Complexity: O(1)
- Fitur: Auto-sorting jika data belum urut

#### Recursive Search
- Time Complexity: O(n)
- Space Complexity: O(n) - call stack
- Fitur: Demo recursive implementation

### 4. Exception Handling
- **Custom Exception Classes** - Derived dari std::exception
- **Three-tier validation** - HeroException, UserException, InputException
- **Graceful error messages** - User-friendly error output

### 5. CRUD Operations
- **Create (C)** - Tambah hero/user dengan validasi
- **Read (R)** - Tampilkan semua data dengan format tabel
- **Update (U)** - Update field tertentu dengan optional input
- **Delete (D)** - Hapus dengan konfirmasi

---

## 🎨 Output Examples

### Admin Menu
```
════════════════════════════════════════════════════════════
  ★ ADMIN MENU ★  |  Logged as: Akmal
════════════════════════════════════════════════════════════
  ▶ HERO MANAGEMENT
  1. ➕ Tambah Hero
  2. 📋 Lihat Semua Hero
  3. ✏️  Update Hero
  4. ❌ Hapus Hero
  ...
```

### Searching Trace
```
════════════════════════════════════════════════════════════
  🔍 LINEAR SEARCH: Mencari Hero berdasarkan Nama (Substring)
════════════════════════════════════════════════════════════
Pencarian: 'ka'

  [Cek 0] Nama = Layla
  [Cek 1] Nama = Tigreal
  [Cek 2] Nama = Kagura ✓
  [Cek 3] Nama = Hayabusa ✓
  [Cek 4] Nama = Odette

✓ Ditemukan 2 hero yang mengandung 'ka'
```

---

## 🚀 Keunggulan Program

1. **Modular Architecture** - Semua fungsi dipisah ke library
2. **User-Friendly Interface** - Colored output yang menarik
3. **Comprehensive Documentation** - Inline comments dan README lengkap
4. **Error Handling** - Exception handling di setiap operasi
5. **Multiple Algorithms** - 3 sorting + 3 searching algorithms
6. **Data Validation** - Input validation untuk semua operasi
7. **Role-Based Access** - Different menu untuk admin dan user
8. **Scalable Design** - Mudah untuk extend dengan fitur baru

---

## 📝 Notes

- Program menggunakan Windows-specific libraries (windows.h)
- Compile dengan flag `-std=c++17` untuk C++17 features
- Maximum hero: 50 unit
- Maximum users: 10 unit
- Default data includes 5 heroes dari Mobile Legends

---

## 👨‍💻 Author

**Nuril Akma**  
NIM: 2509106074  
Universitas Mulawarman
---

## 📄 License

Dibuat untuk keperluan akademis - PRAKTIKUM APL POSTTEST 7

---

**Terima kasih telah menggunakan Gacha Hero ML! 🎮✨**
