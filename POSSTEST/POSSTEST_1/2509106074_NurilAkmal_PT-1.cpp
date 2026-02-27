/// Nama : Nuril Akmal
/// NIM  : 2509106074   

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
    
} 