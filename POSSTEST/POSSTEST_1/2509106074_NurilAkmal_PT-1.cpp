#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama_input;
    string pwd_input;
    string nama_benar = "Nuril Akmal";
    string pwd_benar = "074"; 
    int percobaan = 1;
    int max_percobaan = 3;
    bool login_berhasil = false;
    
    cout << "=====================================\n";
    cout << "         SELAMAT DATANG\n";
    cout << "    PROGRAM KONVERSI JARAK\n";
    cout << "=====================================\n\n";
    
    while (percobaan <= max_percobaan && !login_berhasil) {
        cout << "\n--- PERCOBAAN LOGIN KE-" << percobaan << " ---\n";
        cout << "Masukkan Nama: ";
        getline(cin, nama_input);  
        
        cout << "Masukkan Password (3 digit): ";
        getline(cin, pwd_input); 
        
        if (nama_input == nama_benar && pwd_input == pwd_benar) {
            cout << "\nLogin Berhasil! Selamat Datang, " << nama_input << "!\n";
            login_berhasil = true;
        } else {
            cout << "\nLogin Gagal!\n";
            
            if (percobaan < max_percobaan) {
                cout << "Sisa percobaan: " << max_percobaan - percobaan << " kali\n";
                cout << "Silahkan coba lagi...\n";
                percobaan++;
            } else {
                cout << "\nANDA TELAH MENCAPAI BATAS PERCOBAAN LOGIN!\n";
                percobaan++;
            }
        }
    }
    
    if (!login_berhasil) {
        cout << "\n=====================================\n";
        cout << "  ANDA TELAH 3 KALI GAGAL LOGIN!\n";
        cout << "          PROGRAM BERHENTI\n";
        cout << "=====================================\n";
        return 0;  
    }
    
    int pilihan;
    double meter, kilometer, centimeter;
    
    do {
        cout << "\n=====================================\n";
        cout << "           MENU UTAMA\n";
        cout << "=====================================\n";
        cout << "1. Konversi Meter -> Kilometer & Centimeter\n";
        cout << "2. Konversi Kilometer -> Meter & Centimeter\n";
        cout << "3. Konversi Centimeter -> Meter & Kilometer\n";
        cout << "4. Keluar\n";
        cout << "=====================================\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                cout << "\n--- KONVERSI METER ---\n";
                cout << "Masukkan nilai Meter: ";
                cin >> meter;
                
                kilometer = meter / 1000;
                centimeter = meter * 100;
                
                cout << "\nHASIL KONVERSI:\n";
                cout << meter << " Meter\n";
                cout << "  = " << kilometer << " Kilometer\n";
                cout << "  = " << centimeter << " Centimeter\n";
                break;
            }
            
            case 2: {
                cout << "\n--- KONVERSI KILOMETER ---\n";
                cout << "Masukkan nilai Kilometer: ";
                cin >> kilometer;
                
                meter = kilometer * 1000;
                centimeter = kilometer * 100000;
                
                cout << "\nHASIL KONVERSI:\n";
                cout << kilometer << " Kilometer\n";
                cout << "  = " << meter << " Meter\n";
                cout << "  = " << centimeter << " Centimeter\n";
                break;
            }
            
            case 3: {
                cout << "\n--- KONVERSI CENTIMETER ---\n";
                cout << "Masukkan nilai Centimeter: ";
                cin >> centimeter;
                
                meter = centimeter / 100;
                kilometer = centimeter / 100000;
                
                cout << "\nHASIL KONVERSI:\n";
                cout << centimeter << " Centimeter\n";
                cout << "  = " << meter << " Meter\n";
                cout << "  = " << kilometer << " Kilometer\n";
                break;
            }
            
            case 4: {
                cout << "\n=====================================\n";
                cout << "     TERIMA KASIH " << nama_input << "!\n";
                cout << "     Sampai jumpa lagi\n";
                cout << "=====================================\n";
                break;
            }
            
            default: {
                cout << "\nPilihan tidak valid!\n";
                cout << "Silakan pilih antara 1-4.\n";
                break;
            }
        }
        
        if (pilihan != 4) {
            cout << "\nTekan Enter untuk lanjut...";
            cin.ignore();
            cin.get();
        }
        
    } while (pilihan != 4);
    
    return 0;
}