#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

#define MAX_HERO 50
#define MAX_USER 10

struct HeroStats {
    char role[20];
    char tier[5];
    int  winRate;
};

struct Hero {
    int  id;
    char nama[40];
    char lane[20];
    int  harga;
    char rarity[15];
    struct HeroStats stats;
};

struct User {
    char username[30];
    char password[20];
    char role[10];
};

struct Hero daftarHero[MAX_HERO];
int jumlahHero = 0;

struct User daftarUser[MAX_USER] = {
    {"Akmal",    "074", "admin"},
    {"Nuril",    "123", "user"},
    {"Triya",    "321", "user"},
    {"Pernanda", "111", "user"}
};
int jumlahUser = 4;

void cetakGaris(int panjang);
void cetakHeaderHero();
void cetakBarisTamu();
void cetakHeaderUser();
void inisialisasiHero();

void tampilkanSemuaHero(struct Hero daftar[], int jumlah);
void tambahHero(struct Hero daftar[], int &jumlah);
void updateHero(struct Hero daftar[], int jumlah);
void hapusHero(struct Hero daftar[], int &jumlah);

void tampilkanSemuaUser(struct User daftar[], int jumlah);
void tambahUser(struct User daftar[], int *jumlah);
void updateUser(struct User daftar[], int jumlah);
void hapusUser(struct User daftar[], int *jumlah);
void registrasi(struct User daftar[], int *jumlah);

int  login(struct User daftar[], int jumlah, int *isAdmin);
int  cariHeroRekursif(struct Hero daftar[], int idx, int jumlah, const char *nama);
int  hitungHeroDenganRole(struct Hero daftar[], int idx, int jumlah, const char *role);

int  cariHeroByNama(struct Hero *daftar, int jumlah, const char *targetNama);
int  cariHeroByHarga(struct Hero *daftar, int jumlah, int targetHarga);

void sortNamaDescending(struct Hero daftar[], int jumlah);
void sortHargaAscending(struct Hero daftar[], int jumlah);
void sortWinRateDescending(struct Hero daftar[], int jumlah);

void cetakInfo_int(const char *label, int nilai);
void cetakInfo_str(const char *label, const char *nilai);
void cetakInfo_float(const char *label, float nilai);
void menuAdmin(int userLogin);
void menuUser(int userLogin);
void menuTamu();

int main() {
    inisialisasiHero();

    int pilihanAwal = 0;
    while (pilihanAwal != 4) {
        printf("\n");
        cetakGaris(50);
        printf("        GACHA HERO - MOBILE LEGENDS\n");
        cetakGaris(50);
        printf("  1. Login\n");
        printf("  2. Registrasi\n");
        printf("  3. Lihat Hero (Tamu)\n");
        printf("  4. Keluar\n");
        cetakGaris(50);
        printf("Pilih menu: ");
        scanf("%d", &pilihanAwal);

        switch (pilihanAwal) {
            case 1: {
                int isAdmin   = 0;
                int userLogin = login(daftarUser, jumlahUser, &isAdmin);
                if (userLogin == -1) {
                    printf("Anda telah gagal login 3 kali. Program berhenti.\n");
                    return 0;
                }
                if (isAdmin)
                    menuAdmin(userLogin);
                else
                    menuUser(userLogin);
                break;
            }
            case 2:
                registrasi(daftarUser, &jumlahUser);
                break;
            case 3:
                menuTamu();
                break;
            case 4:
                printf("Terima kasih telah menggunakan Gacha Hero ML!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
    return 0;
}

void inisialisasiHero() {
    jumlahHero = 5;

    daftarHero[0].id = 1;
    strcpy(daftarHero[0].nama,       "Layla");
    strcpy(daftarHero[0].lane,       "Gold Lane");
    daftarHero[0].harga            = 150;
    strcpy(daftarHero[0].rarity,    "Epic");
    strcpy(daftarHero[0].stats.role,"Marksman");
    strcpy(daftarHero[0].stats.tier,"B");
    daftarHero[0].stats.winRate    = 51;

    daftarHero[1].id = 2;
    strcpy(daftarHero[1].nama,       "Tigreal");
    strcpy(daftarHero[1].lane,       "EXP Lane");
    daftarHero[1].harga            = 200;
    strcpy(daftarHero[1].rarity,    "Epic");
    strcpy(daftarHero[1].stats.role,"Tank");
    strcpy(daftarHero[1].stats.tier,"A");
    daftarHero[1].stats.winRate    = 54;

    daftarHero[2].id = 3;
    strcpy(daftarHero[2].nama,       "Kagura");
    strcpy(daftarHero[2].lane,       "Mid Lane");
    daftarHero[2].harga            = 600;
    strcpy(daftarHero[2].rarity,    "Legend");
    strcpy(daftarHero[2].stats.role,"Mage");
    strcpy(daftarHero[2].stats.tier,"S");
    daftarHero[2].stats.winRate    = 57;

    daftarHero[3].id = 4;
    strcpy(daftarHero[3].nama,       "Hayabusa");
    strcpy(daftarHero[3].lane,       "Jungle");
    daftarHero[3].harga            = 500;
    strcpy(daftarHero[3].rarity,    "Legend");
    strcpy(daftarHero[3].stats.role,"Assassin");
    strcpy(daftarHero[3].stats.tier,"S");
    daftarHero[3].stats.winRate    = 55;

    daftarHero[4].id = 5;
    strcpy(daftarHero[4].nama,       "Odette");
    strcpy(daftarHero[4].lane,       "Mid Lane");
    daftarHero[4].harga            = 300;
    strcpy(daftarHero[4].rarity,    "Epic");
    strcpy(daftarHero[4].stats.role,"Mage");
    strcpy(daftarHero[4].stats.tier,"A");
    daftarHero[4].stats.winRate    = 52;
}

void cetakGaris(int panjang) {
    int i;
    for (i = 0; i < panjang; i++) printf("=");
    printf("\n");
}

void cetakHeaderHero() {
    printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
           "ID","Nama","Lane","Rarity","Harga","Role","Tier","Win%");
    printf("------------------------------------------------------------------------\n");
}

void cetakBarisTamu() {
    printf("\n");
    cetakGaris(50);
    printf("        DAFTAR HERO GACHA (TAMU)\n");
    cetakGaris(50);
}

void cetakHeaderUser() {
    printf("%-4s %-20s %-15s %s\n","No","Username","Password","Role");
    printf("------------------------------------------\n");
}

void cetakInfo_int(const char *label, int nilai) {
    printf("%-12s : %d\n", label, nilai);
}
void cetakInfo_str(const char *label, const char *nilai) {
    printf("%-12s : %s\n", label, nilai);
}
void cetakInfo_float(const char *label, float nilai) {
    printf("%-12s : %.2f\n", label, nilai);
}

void sortNamaDescending(struct Hero daftar[], int jumlah) {
    int i, j;
    struct Hero temp;
    
    printf("\n--- Sorting Hero berdasarkan Nama (Descending Z-A) ---\n");
    printf("Menggunakan Metode: Bubble Sort\n\n");
    
    for (i = 0; i < jumlah - 1; i++) {
        for (j = 0; j < jumlah - i - 1; j++) {
            if (strcmp(daftar[j].nama, daftar[j + 1].nama) < 0) {
                temp = daftar[j];
                daftar[j] = daftar[j + 1];
                daftar[j + 1] = temp;
            }
        }
    }
    
    printf("Hasil Sorting berdasarkan Nama (Descending):\n");
    printf("------------------------------------------------------------------------\n");
    cetakHeaderHero();
    for (i = 0; i < jumlah; i++) {
        printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
               daftar[i].id, daftar[i].nama, daftar[i].lane,
               daftar[i].rarity, daftar[i].harga,
               daftar[i].stats.role, daftar[i].stats.tier,
               daftar[i].stats.winRate);
    }
    printf("------------------------------------------------------------------------\n");
}
void sortHargaAscending(struct Hero daftar[], int jumlah) {
    int i, j, minIdx;
    struct Hero temp;
    
    printf("\n--- Sorting Hero berdasarkan Harga (Ascending) ---\n");
    printf("Menggunakan Metode: Selection Sort\n\n");
    
    for (i = 0; i < jumlah - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < jumlah; j++) {
            if (daftar[j].harga < daftar[minIdx].harga) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = daftar[i];
            daftar[i] = daftar[minIdx];
            daftar[minIdx] = temp;
        }
    }
    
    printf("Hasil Sorting berdasarkan Harga (Ascending):\n");
    printf("------------------------------------------------------------------------\n");
    cetakHeaderHero();
    for (i = 0; i < jumlah; i++) {
        printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
               daftar[i].id, daftar[i].nama, daftar[i].lane,
               daftar[i].rarity, daftar[i].harga,
               daftar[i].stats.role, daftar[i].stats.tier,
               daftar[i].stats.winRate);
    }
    printf("------------------------------------------------------------------------\n");
}
void sortWinRateDescending(struct Hero daftar[], int jumlah) {
    int i, j;
    struct Hero temp;
    
    printf("\n--- Sorting Hero berdasarkan Win Rate (Descending) ---\n");
    printf("Menggunakan Metode: Insertion Sort\n\n");
    
    for (i = 1; i < jumlah; i++) {
        temp = daftar[i];
        j = i - 1;
        
        while (j >= 0 && daftar[j].stats.winRate < temp.stats.winRate) {
            daftar[j + 1] = daftar[j];
            j--;
        }
        daftar[j + 1] = temp;
    }
    
    printf("Hasil Sorting berdasarkan Win Rate (Descending):\n");
    printf("------------------------------------------------------------------------\n");
    cetakHeaderHero();
    for (i = 0; i < jumlah; i++) {
        printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
               daftar[i].id, daftar[i].nama, daftar[i].lane,
               daftar[i].rarity, daftar[i].harga,
               daftar[i].stats.role, daftar[i].stats.tier,
               daftar[i].stats.winRate);
    }
    printf("------------------------------------------------------------------------\n");
}

int cariHeroRekursif(struct Hero daftar[], int idx, int jumlah, const char *nama) {
    if (idx >= jumlah) return -1;                       
    if (strcmp(daftar[idx].nama, nama) == 0) return idx;
    return cariHeroRekursif(daftar, idx + 1, jumlah, nama); 
}
int hitungHeroDenganRole(struct Hero daftar[], int idx, int jumlah, const char *role) {
    if (idx >= jumlah) return 0;
    int tambah = (strcmp(daftar[idx].stats.role, role) == 0) ? 1 : 0;
    return tambah + hitungHeroDenganRole(daftar, idx + 1, jumlah, role);
}

int cariHeroByNama(struct Hero *daftar, int jumlah, const char *targetNama) {
    printf("\n--- Linear Search: Mencari Hero berdasarkan Nama (Substring) ---\n");
    printf("Metode: Linear Search (Sequential Search)\n");
    printf("Deskripsi: Mencari elemen dengan cara membandingkan satu per satu dari awal.\n");
    printf("Pencarian: '%s'\n\n", targetNama);
    
    int ditemukan = 0;
    int hasil[MAX_HERO];
    int totalHasil = 0;
    
    char cariLower[40];
    strcpy(cariLower, targetNama);
    for (int k = 0; cariLower[k]; k++) {
        cariLower[k] = tolower(cariLower[k]);
    }
    
    for (int i = 0; i < jumlah; i++) {
        char namaLower[40];
        strcpy(namaLower, (daftar + i)->nama);
        for (int k = 0; namaLower[k]; k++) {
            namaLower[k] = tolower(namaLower[k]);
        }
        
        printf("  Cek indeks %d: Nama = %s", i, (daftar + i)->nama);
        
        if (strstr(namaLower, cariLower) != NULL) {
            printf(" ✓\n");
            hasil[totalHasil] = i;
            totalHasil++;
            ditemukan = 1;
        } else {
            printf("\n");
        }
    }
    
    if (ditemukan) {
        printf("\n✓ Ditemukan %d hero yang mengandung '%s'\n\n", totalHasil, targetNama);
        printf("------------------------------------------------------------------------\n");
        printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
               "ID","Nama","Lane","Rarity","Harga","Role","Tier","Win%");
        printf("------------------------------------------------------------------------\n");
        
        for (int i = 0; i < totalHasil; i++) {
            int idx = hasil[i];
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   (daftar + idx)->id, (daftar + idx)->nama, (daftar + idx)->lane,
                   (daftar + idx)->rarity, (daftar + idx)->harga,
                   (daftar + idx)->stats.role, (daftar + idx)->stats.tier,
                   (daftar + idx)->stats.winRate);
        }
        printf("------------------------------------------------------------------------\n");
        return hasil[0];
    }
    
    printf("\n✗ Hero dengan nama yang mengandung '%s' tidak ditemukan.\n", targetNama);
    return -1;
}

int cariHeroByHarga(struct Hero *daftar, int jumlah, int targetHarga) {
    printf("\n--- Interpolation Search: Mencari Hero berdasarkan Harga ---\n");
    printf("Metode: Interpolation Search\n");
    printf("Deskripsi: Pencarian dengan interpolasi/tebakan posisi pada array terurut.\n");
    printf("Pencarian Harga: %d\n\n", targetHarga);
    
    int low = 0, high = jumlah - 1;
    
    int isSorted = 1;
    for (int i = 0; i < jumlah - 1; i++) {
        if ((daftar + i)->harga > (daftar + i + 1)->harga) {
            isSorted = 0;
            break;
        }
    }
    
    if (!isSorted) {
        printf("⚠ Array harga tidak terurut. Melakukan Sorting terlebih dahulu...\n");
        printf("\n--- Sorting Hero berdasarkan Harga (Ascending) ---\n");
        printf("Menggunakan Metode: Selection Sort\n\n");
        
        int i, j, minIdx;
        struct Hero temp;
        for (i = 0; i < jumlah - 1; i++) {
            minIdx = i;
            for (j = i + 1; j < jumlah; j++) {
                if ((daftar + j)->harga < (daftar + minIdx)->harga) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                temp = *(daftar + i);
                *(daftar + i) = *(daftar + minIdx);
                *(daftar + minIdx) = temp;
            }
        }
        
        printf("Hasil Sorting berdasarkan Harga (Ascending):\n");
        printf("------------------------------------------------------------------------\n");
        printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
               "ID","Nama","Lane","Rarity","Harga","Role","Tier","Win%");
        printf("------------------------------------------------------------------------\n");
        for (i = 0; i < jumlah; i++) {
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   (daftar + i)->id, (daftar + i)->nama, (daftar + i)->lane,
                   (daftar + i)->rarity, (daftar + i)->harga,
                   (daftar + i)->stats.role, (daftar + i)->stats.tier,
                   (daftar + i)->stats.winRate);
        }
        printf("------------------------------------------------------------------------\n\n");
    }
    
    while (low <= high && targetHarga >= (daftar + low)->harga && 
           targetHarga <= (daftar + high)->harga) {
        
        int pos = low + ((high - low) / ((daftar + high)->harga - (daftar + low)->harga)) * 
                       (targetHarga - (daftar + low)->harga);
        
        printf("  Cek indeks %d: Harga = %d\n", pos, (daftar + pos)->harga);
        
        if ((daftar + pos)->harga == targetHarga) {
            printf("\n✓ Hero ditemukan pada indeks: %d\n", pos);
            return pos;
        }
        
        if ((daftar + pos)->harga < targetHarga) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    printf("\n✗ Hero dengan harga %d tidak ditemukan.\n", targetHarga);
    return -1;
}

int login(struct User daftar[], int jumlah, int *isAdmin) {
    char username[30], password[20];
    int kesempatan = 3, i;

    while (kesempatan > 0) {
        printf("\nMasukkan Username : "); scanf("%s", username);
        printf("Masukkan Password : "); scanf("%s", password);

        for (i = 0; i < jumlah; i++) {
            if (strcmp(daftar[i].username, username) == 0 &&
                strcmp(daftar[i].password, password) == 0) {
                printf("Login berhasil! Selamat datang, %s!\n", username);
                *isAdmin = (strcmp(daftar[i].role, "admin") == 0) ? 1 : 0;
                return i;
            }
        }
        kesempatan--;
        printf("Login gagal! Kesempatan tersisa: %d\n", kesempatan);
    }
    return -1;
}

void registrasi(struct User daftar[], int *jumlah) {
    if (*jumlah >= MAX_USER) {
        printf("Kapasitas pengguna penuh!\n");
        return;
    }
    printf("\n--- Registrasi Akun Baru ---\n");
    printf("Username baru : "); scanf("%s", daftar[*jumlah].username);
    printf("Password      : "); scanf("%s", daftar[*jumlah].password);
    strcpy(daftar[*jumlah].role, "user");

    int i;
    for (i = 0; i < *jumlah; i++) {
        if (strcmp(daftar[i].username, daftar[*jumlah].username) == 0) {
            printf("Username sudah ada! Silakan pilih username lain.\n");
            return;
        }
    }
    (*jumlah)++;
    printf("Registrasi berhasil! Silakan login.\n");
}

void tampilkanSemuaHero(struct Hero daftar[], int jumlah) {
    int i;
    printf("\nDaftar Hero:\n");
    printf("------------------------------------------------------------------------\n");
    cetakHeaderHero();
    for (i = 0; i < jumlah; i++) {
        printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
               daftar[i].id, daftar[i].nama, daftar[i].lane,
               daftar[i].rarity, daftar[i].harga,
               daftar[i].stats.role, daftar[i].stats.tier,
               daftar[i].stats.winRate);
    }
    printf("------------------------------------------------------------------------\n");
    printf("Total Hero: %d\n", jumlah);

    int jumlahMage = hitungHeroDenganRole(daftar, 0, jumlah, "Mage");
    printf("Jumlah hero Mage (rekursif): %d\n", jumlahMage);
}

void tambahHero(struct Hero daftar[], int &jumlah) {
    if (jumlah >= MAX_HERO) {
        printf("Data hero sudah penuh!\n");
        return;
    }
    printf("\n--- Tambah Hero ---\n");

    struct Hero *h = &daftar[jumlah];
    h->id = jumlah + 1;
    printf("Nama Hero              : "); scanf(" %[^\n]", h->nama);
    printf("Lane                   : "); scanf(" %[^\n]", h->lane);
    printf("Rarity (Epic/Legend/Mythic): "); scanf(" %[^\n]", h->rarity);
    printf("Harga (diamond)        : "); scanf("%d", &h->harga);
    printf("Role (Tank/Mage/dll)   : "); scanf(" %[^\n]", h->stats.role);
    printf("Tier (S/A/B/C)         : "); scanf(" %[^\n]", h->stats.tier);
    printf("Win Rate (%%)           : "); scanf("%d", &h->stats.winRate);

    jumlah++;
    printf("Hero berhasil ditambahkan!\n");

    printf("\n[Info Hero Baru]\n");
    cetakInfo_str("Nama",   h->nama);
    cetakInfo_str("Role",   h->stats.role);
    cetakInfo_int("Harga",  h->harga);
    cetakInfo_int("WinRate",h->stats.winRate);
    cetakInfo_float("WR (%)", (float)h->stats.winRate);
}

void updateHero(struct Hero daftar[], int jumlah) {
    tampilkanSemuaHero(daftar, jumlah);
    printf("Masukkan ID hero yang ingin diupdate: ");
    int idx; scanf("%d", &idx);
    idx--;
    if (idx < 0 || idx >= jumlah) {
        printf("ID tidak valid!\n");
        return;
    }

    struct Hero *h = &daftar[idx];
    char buf[50];
    printf("(Tekan ENTER untuk tidak mengubah)\n");

    printf("Nama  [%s]: ", h->nama);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(h->nama, buf);

    printf("Lane  [%s]: ", h->lane);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(h->lane, buf);

    printf("Rarity[%s]: ", h->rarity);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(h->rarity, buf);

    printf("Harga [%d]: ", h->harga);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) h->harga = atoi(buf);

    printf("Role  [%s]: ", h->stats.role);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(h->stats.role, buf);

    printf("Tier  [%s]: ", h->stats.tier);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(h->stats.tier, buf);

    printf("WinRate[%d]: ", h->stats.winRate);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) h->stats.winRate = atoi(buf);

    printf("Hero berhasil diupdate!\n");
}

void hapusHero(struct Hero daftar[], int &jumlah) {
    tampilkanSemuaHero(daftar, jumlah);
    printf("Masukkan ID hero yang ingin dihapus: ");
    int idx; scanf("%d", &idx);
    idx--;
    if (idx < 0 || idx >= jumlah) {
        printf("ID tidak valid!\n");
        return;
    }

    struct Hero *h = &daftar[idx];
    char konfirm;
    printf("Yakin hapus '%s'? (y/n): ", h->nama);
    scanf(" %c", &konfirm);
    if (konfirm == 'y' || konfirm == 'Y') {
        int i;
        for (i = idx; i < jumlah - 1; i++) {
            daftar[i]    = daftar[i + 1];
            daftar[i].id = i + 1;
        }
        jumlah--;
        printf("Hero berhasil dihapus!\n");
    } else {
        printf("Dibatalkan.\n");
    }
}

void tampilkanSemuaUser(struct User daftar[], int jumlah) {
    int i;
    printf("\nDaftar Pengguna:\n");
    printf("------------------------------------------\n");
    cetakHeaderUser();
    for (i = 0; i < jumlah; i++) {
        printf("%-4d %-20s %-15s %s\n",
               i + 1, daftar[i].username, daftar[i].password, daftar[i].role);
    }
    printf("------------------------------------------\n");
    printf("Total Pengguna: %d\n", jumlah);
}

void tambahUser(struct User daftar[], int *jumlah) {
    if (*jumlah >= MAX_USER) {
        printf("Data pengguna sudah penuh!\n");
        return;
    }
    printf("\n--- Tambah Pengguna ---\n");

    struct User *u = &daftar[*jumlah];
    printf("Username baru     : "); scanf("%s", u->username);
    printf("Password          : "); scanf("%s", u->password);
    printf("Role (admin/user) : "); scanf("%s", u->role);

    int i;
    for (i = 0; i < *jumlah; i++) {
        if (strcmp(daftar[i].username, u->username) == 0) {
            printf("Username sudah ada!\n");
            return;
        }
    }
    (*jumlah)++;
    printf("Pengguna berhasil ditambahkan!\n");
}

void updateUser(struct User daftar[], int jumlah) {
    tampilkanSemuaUser(daftar, jumlah);
    printf("Masukkan No pengguna yang ingin diupdate: ");
    int idx; scanf("%d", &idx);
    idx--;
    if (idx < 0 || idx >= jumlah) {
        printf("Nomor tidak valid!\n");
        return;
    }

    struct User *u = &daftar[idx];
    if (strcmp(u->username, "Akmal") == 0) {
        printf("Tidak bisa mengubah admin utama!\n");
        return;
    }

    char buf[50];
    printf("(Tekan ENTER untuk tidak mengubah)\n");

    printf("Username [%s]: ", u->username);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(u->username, buf);

    printf("Password [%s]: ", u->password);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(u->password, buf);

    printf("Role     [%s]: ", u->role);
    scanf(" %[^\n]", buf);
    if (strlen(buf) > 0) strcpy(u->role, buf);

    printf("Pengguna berhasil diupdate!\n");
}

void hapusUser(struct User daftar[], int *jumlah) {
    tampilkanSemuaUser(daftar, *jumlah);
    char namaHapus[30];
    printf("Masukkan username yang dihapus: ");
    scanf("%s", namaHapus);

    if (strcmp(namaHapus, "Akmal") == 0) {
        printf("Tidak bisa menghapus admin utama!\n");
        return;
    }

    int idx = -1, i;
    for (i = 0; i < *jumlah; i++) {
        if (strcmp(daftar[i].username, namaHapus) == 0) { idx = i; break; }
    }

    if (idx == -1) {
        printf("Username tidak ditemukan!\n");
        return;
    }

    struct User *u = &daftar[idx];
    for (i = idx; i < *jumlah - 1; i++)
        daftar[i] = daftar[i + 1];
    (*jumlah)--;
    printf("Pengguna '%s' berhasil dihapus!\n", namaHapus);
}

void menuAdmin(int userLogin) {
    int pilihan;
    do {
        printf("\n");
        cetakGaris(50);
        printf("  Menu Admin  |  Login: %s\n", daftarUser[userLogin].username);
        cetakGaris(50);
        printf("  1. Tambah Hero\n");
        printf("  2. Lihat Hero\n");
        printf("  3. Update Hero\n");
        printf("  4. Hapus Hero\n");
        printf("  5. Tambah Pengguna\n");
        printf("  6. Lihat Pengguna\n");
        printf("  7. Update Pengguna\n");
        printf("  8. Hapus Pengguna\n");
        printf("  9. Cari Hero (Rekursif Demo)\n");
        printf("  10. Sort Nama (Descending - Bubble Sort)\n");
        printf("  11. Sort Harga (Ascending - Selection Sort)\n");
        printf("  12. Sort Win Rate (Descending - Insertion Sort)\n");
        printf("  0. Logout\n");
        cetakGaris(50);
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tambahHero(daftarHero, jumlahHero);          break;
            case 2: tampilkanSemuaHero(daftarHero, jumlahHero);    break;
            case 3: updateHero(daftarHero, jumlahHero);            break;
            case 4: hapusHero(daftarHero, jumlahHero);             break;
            case 5: tambahUser(daftarUser, &jumlahUser);           break;
            case 6: tampilkanSemuaUser(daftarUser, jumlahUser);    break;
            case 7: updateUser(daftarUser, jumlahUser);            break;
            case 8: hapusUser(daftarUser, &jumlahUser);            break;
            case 9: {
                char namaCari[40];
                printf("Masukkan nama hero yang dicari: ");
                scanf(" %[^\n]", namaCari);
                int hasil = cariHeroRekursif(daftarHero, 0, jumlahHero, namaCari);
                if (hasil == -1)
                    printf("Hero '%s' tidak ditemukan.\n", namaCari);
                else {
                    printf("Hero ditemukan di indeks %d:\n", hasil);
                    cetakInfo_str("Nama",   daftarHero[hasil].nama);
                    cetakInfo_str("Lane",   daftarHero[hasil].lane);
                    cetakInfo_str("Role",   daftarHero[hasil].stats.role);
                    cetakInfo_str("Tier",   daftarHero[hasil].stats.tier);
                    cetakInfo_int("Harga",  daftarHero[hasil].harga);
                    cetakInfo_int("WinRate",daftarHero[hasil].stats.winRate);
                    cetakInfo_float("WR (%)",(float)daftarHero[hasil].stats.winRate);
                }
                break;
            }
            case 10: sortNamaDescending(daftarHero, jumlahHero);   break;
            case 11: sortHargaAscending(daftarHero, jumlahHero);   break;
            case 12: sortWinRateDescending(daftarHero, jumlahHero); break;
            case 0:
                printf("Logout berhasil! Kembali ke menu utama...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}

void menuUser(int userLogin) {
    int pilihan;
    do {
        printf("\n");
        cetakGaris(50);
        printf("  Menu User  |  Login: %s\n", daftarUser[userLogin].username);
        cetakGaris(50);
        printf("  1. Lihat Hero\n");
        printf("  2. [SEARCHING] Cari Hero by Nama (Linear Search)\n");
        printf("  3. [SEARCHING] Cari Hero by Harga (Interpolation Search)\n");
        printf("  0. Logout\n");
        cetakGaris(50);
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tampilkanSemuaHero(daftarHero, jumlahHero); break;
            
            case 2: {
                tampilkanSemuaHero(daftarHero, jumlahHero);
                char cariNama[40];
                printf("\nMasukkan nama atau huruf hero yang dicari: ");
                scanf(" %[^\n]", cariNama);
                int hasil = cariHeroByNama(daftarHero, jumlahHero, cariNama);
                break;
            }
            
            case 3: {
                tampilkanSemuaHero(daftarHero, jumlahHero);
                int cariHarga;
                printf("\nMasukkan harga hero yang dicari: ");
                scanf("%d", &cariHarga);
                int hasil = cariHeroByHarga(daftarHero, jumlahHero, cariHarga);
                if (hasil != -1) {
                    printf("\n[Informasi Hero]\n");
                    cetakInfo_str("Nama",   daftarHero[hasil].nama);
                    cetakInfo_str("Lane",   daftarHero[hasil].lane);
                    cetakInfo_str("Rarity", daftarHero[hasil].rarity);
                    cetakInfo_int("Harga",  daftarHero[hasil].harga);
                    cetakInfo_str("Role",   daftarHero[hasil].stats.role);
                    cetakInfo_str("Tier",   daftarHero[hasil].stats.tier);
                    cetakInfo_int("WinRate",daftarHero[hasil].stats.winRate);
                }
                break;
            }
            
            case 0: printf("Logout berhasil! Kembali ke menu utama...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}

void menuTamu() {
    int pilihanTamu;
    do {
        cetakBarisTamu();
        cetakHeaderHero();
        int i;
        for (i = 0; i < jumlahHero; i++) {
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   daftarHero[i].id, daftarHero[i].nama, daftarHero[i].lane,
                   daftarHero[i].rarity, daftarHero[i].harga,
                   daftarHero[i].stats.role, daftarHero[i].stats.tier,
                   daftarHero[i].stats.winRate);
        }
        printf("------------------------------------------------------------------------\n");
        printf("Total Hero: %d\n", jumlahHero);
        printf("\n  0. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihanTamu);
        if (pilihanTamu != 0) printf("Pilihan tidak valid!\n");
    } while (pilihanTamu != 0);
}