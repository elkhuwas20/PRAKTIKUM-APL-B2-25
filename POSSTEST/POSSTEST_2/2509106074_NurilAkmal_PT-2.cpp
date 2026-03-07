#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main() {

    jumlahHero = 5;

    daftarHero[0].id = 1;
    strcpy(daftarHero[0].nama,        "Layla");
    strcpy(daftarHero[0].lane,        "Gold Lane");
    daftarHero[0].harga              = 150;
    strcpy(daftarHero[0].rarity,      "Epic");
    strcpy(daftarHero[0].stats.role,  "Marksman");
    strcpy(daftarHero[0].stats.tier,  "B");
    daftarHero[0].stats.winRate      = 51;

    daftarHero[1].id = 2;
    strcpy(daftarHero[1].nama,        "Tigreal");
    strcpy(daftarHero[1].lane,        "EXP Lane");
    daftarHero[1].harga              = 200;
    strcpy(daftarHero[1].rarity,      "Epic");
    strcpy(daftarHero[1].stats.role,  "Tank");
    strcpy(daftarHero[1].stats.tier,  "A");
    daftarHero[1].stats.winRate      = 54;

    daftarHero[2].id = 3;
    strcpy(daftarHero[2].nama,        "Kagura");
    strcpy(daftarHero[2].lane,        "Mid Lane");
    daftarHero[2].harga              = 600;
    strcpy(daftarHero[2].rarity,      "Legend");
    strcpy(daftarHero[2].stats.role,  "Mage");
    strcpy(daftarHero[2].stats.tier,  "S");
    daftarHero[2].stats.winRate      = 57;

    daftarHero[3].id = 4;
    strcpy(daftarHero[3].nama,        "Hayabusa");
    strcpy(daftarHero[3].lane,        "Jungle");
    daftarHero[3].harga              = 500;
    strcpy(daftarHero[3].rarity,      "Legend");
    strcpy(daftarHero[3].stats.role,  "Assassin");
    strcpy(daftarHero[3].stats.tier,  "S");
    daftarHero[3].stats.winRate      = 55;

    daftarHero[4].id = 5;
    strcpy(daftarHero[4].nama,        "Odette");
    strcpy(daftarHero[4].lane,        "Mid Lane");
    daftarHero[4].harga              = 300;
    strcpy(daftarHero[4].rarity,      "Epic");
    strcpy(daftarHero[4].stats.role,  "Mage");
    strcpy(daftarHero[4].stats.tier,  "A");
    daftarHero[4].stats.winRate      = 52;

    char username[30], password[20];
    int  kesempatan, loginBerhasil, isAdmin, userLogin;
    int  i, idx, pilihan, pilihanAwal, pilihanTamu, sudahAda;
    char buf[50], konfirm;
    char namaHapus[30];

    pilihanAwal = 0;
    while (pilihanAwal != 4) {

        printf("\n==================================================\n");
        printf("        GACHA HERO - MOBILE LEGENDS\n");
        printf("==================================================\n");
        printf("  1. Login\n");
        printf("  2. Registrasi\n");
        printf("  3. Lihat Hero (Tamu)\n");
        printf("  4. Keluar\n");
        printf("==================================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihanAwal);

        switch (pilihanAwal) {

            case 1:
                kesempatan    = 3;
                loginBerhasil = 0;
                isAdmin       = 0;
                userLogin     = 0;

                while (kesempatan > 0) {
                    printf("\nMasukkan Username : "); scanf("%s", username);
                    printf("Masukkan Password : "); scanf("%s", password);

                    for (i = 0; i < jumlahUser; i++) {
                        if (strcmp(daftarUser[i].username, username) == 0 &&
                            strcmp(daftarUser[i].password, password) == 0) {
                            loginBerhasil = 1;
                            userLogin     = i;
                            if (strcmp(daftarUser[i].role, "admin") == 0)
                                isAdmin = 1;
                            break;
                        }
                    }

                    if (loginBerhasil) {
                        printf("Login berhasil! Selamat datang, %s!\n", username);
                        break;
                    }

                    kesempatan--;
                    printf("Login gagal! Kesempatan tersisa: %d\n", kesempatan);
                }

                if (!loginBerhasil) {
                    printf("Anda telah gagal login 3 kali. Program berhenti.\n");
                    return 0;
                }

                do {
                    printf("\n==================================================\n");
                    if (isAdmin) {
                        printf("  Menu Admin  |  Login: %s\n", daftarUser[userLogin].username);
                        printf("==================================================\n");
                        printf("  1. Tambah Hero\n");
                        printf("  2. Lihat Hero\n");
                        printf("  3. Update Hero\n");
                        printf("  4. Hapus Hero\n");
                        printf("  5. Tambah Pengguna\n");
                        printf("  6. Lihat Pengguna\n");
                        printf("  7. Update Pengguna\n");
                        printf("  8. Hapus Pengguna\n");
                        printf("  0. Logout\n");
                    } else {
                        printf("  Menu User  |  Login: %s\n", daftarUser[userLogin].username);
                        printf("==================================================\n");
                        printf("  1. Lihat Hero\n");
                        printf("  0. Logout\n");
                    }
                    printf("==================================================\n");
                    printf("Pilih menu: ");
                    scanf("%d", &pilihan);

                    if (isAdmin) {
                        switch (pilihan) {

                            case 1:
                                if (jumlahHero >= MAX_HERO) {
                                    printf("Data hero sudah penuh!\n");
                                } else {
                                    printf("\n--- Tambah Hero ---\n");
                                    daftarHero[jumlahHero].id = jumlahHero + 1;
                                    printf("Nama Hero              : "); scanf(" %[^\n]", daftarHero[jumlahHero].nama);
                                    printf("Lane                   : "); scanf(" %[^\n]", daftarHero[jumlahHero].lane);
                                    printf("Rarity (Epic/Legend/Mythic): "); scanf(" %[^\n]", daftarHero[jumlahHero].rarity);
                                    printf("Harga (diamond)        : "); scanf("%d", &daftarHero[jumlahHero].harga);
                                    printf("Role (Tank/Mage/dll)   : "); scanf(" %[^\n]", daftarHero[jumlahHero].stats.role);
                                    printf("Tier (S/A/B/C)         : "); scanf(" %[^\n]", daftarHero[jumlahHero].stats.tier);
                                    printf("Win Rate (%%)           : "); scanf("%d", &daftarHero[jumlahHero].stats.winRate);
                                    jumlahHero++;
                                    printf("Hero berhasil ditambahkan!\n");
                                }
                                break;

                            case 2:
                                printf("\nDaftar Hero:\n");
                                printf("------------------------------------------------------------------------\n");
                                printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
                                       "ID", "Nama", "Lane", "Rarity", "Harga", "Role", "Tier", "Win%");
                                printf("------------------------------------------------------------------------\n");
                                for (i = 0; i < jumlahHero; i++) {
                                    printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                                           daftarHero[i].id, daftarHero[i].nama, daftarHero[i].lane,
                                           daftarHero[i].rarity, daftarHero[i].harga,
                                           daftarHero[i].stats.role, daftarHero[i].stats.tier,
                                           daftarHero[i].stats.winRate);
                                }
                                printf("------------------------------------------------------------------------\n");
                                printf("Total Hero: %d\n", jumlahHero);
                                break;

                            case 3:
                                printf("\nDaftar Hero:\n");
                                printf("------------------------------------------------------------------------\n");
                                printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
                                       "ID", "Nama", "Lane", "Rarity", "Harga", "Role", "Tier", "Win%");
                                printf("------------------------------------------------------------------------\n");
                                for (i = 0; i < jumlahHero; i++) {
                                    printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                                           daftarHero[i].id, daftarHero[i].nama, daftarHero[i].lane,
                                           daftarHero[i].rarity, daftarHero[i].harga,
                                           daftarHero[i].stats.role, daftarHero[i].stats.tier,
                                           daftarHero[i].stats.winRate);
                                }
                                printf("------------------------------------------------------------------------\n");
                                printf("Masukkan ID hero yang ingin diupdate: ");
                                scanf("%d", &idx);
                                idx = idx - 1;
                                if (idx < 0 || idx >= jumlahHero) {
                                    printf("ID tidak valid!\n");
                                } else {
                                    printf("(Tekan ENTER untuk tidak mengubah)\n");
                                    printf("Nama  [%s]: ", daftarHero[idx].nama);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarHero[idx].nama, buf);

                                    printf("Lane  [%s]: ", daftarHero[idx].lane);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarHero[idx].lane, buf);

                                    printf("Rarity[%s]: ", daftarHero[idx].rarity);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarHero[idx].rarity, buf);

                                    printf("Harga [%d]: ", daftarHero[idx].harga);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) daftarHero[idx].harga = atoi(buf);

                                    printf("Role  [%s]: ", daftarHero[idx].stats.role);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarHero[idx].stats.role, buf);

                                    printf("Tier  [%s]: ", daftarHero[idx].stats.tier);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarHero[idx].stats.tier, buf);

                                    printf("WinRate[%d]: ", daftarHero[idx].stats.winRate);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) daftarHero[idx].stats.winRate = atoi(buf);

                                    printf("Hero berhasil diupdate!\n");
                                }
                                break;

                            case 4:
                                printf("\nDaftar Hero:\n");
                                printf("------------------------------------------------------------------------\n");
                                printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
                                       "ID", "Nama", "Lane", "Rarity", "Harga", "Role", "Tier", "Win%");
                                printf("------------------------------------------------------------------------\n");
                                for (i = 0; i < jumlahHero; i++) {
                                    printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                                           daftarHero[i].id, daftarHero[i].nama, daftarHero[i].lane,
                                           daftarHero[i].rarity, daftarHero[i].harga,
                                           daftarHero[i].stats.role, daftarHero[i].stats.tier,
                                           daftarHero[i].stats.winRate);
                                }
                                printf("------------------------------------------------------------------------\n");
                                printf("Masukkan ID hero yang ingin dihapus: ");
                                scanf("%d", &idx);
                                idx = idx - 1;
                                if (idx < 0 || idx >= jumlahHero) {
                                    printf("ID tidak valid!\n");
                                } else {
                                    printf("Yakin hapus '%s'? (y/n): ", daftarHero[idx].nama);
                                    scanf(" %c", &konfirm);
                                    if (konfirm == 'y' || konfirm == 'Y') {
                                        for (i = idx; i < jumlahHero - 1; i++) {
                                            daftarHero[i]    = daftarHero[i + 1];
                                            daftarHero[i].id = i + 1;
                                        }
                                        jumlahHero--;
                                        printf("Hero berhasil dihapus!\n");
                                    } else {
                                        printf("Dibatalkan.\n");
                                    }
                                }
                                break;

                            case 5:
                                if (jumlahUser >= MAX_USER) {
                                    printf("Data pengguna sudah penuh!\n");
                                } else {
                                    printf("\n--- Tambah Pengguna ---\n");
                                    printf("Username baru     : "); scanf("%s", daftarUser[jumlahUser].username);
                                    printf("Password          : "); scanf("%s", daftarUser[jumlahUser].password);
                                    printf("Role (admin/user) : "); scanf("%s", daftarUser[jumlahUser].role);

                                    sudahAda = 0;
                                    for (i = 0; i < jumlahUser; i++) {
                                        if (strcmp(daftarUser[i].username, daftarUser[jumlahUser].username) == 0) {
                                            sudahAda = 1;
                                            break;
                                        }
                                    }
                                    if (sudahAda) {
                                        printf("Username sudah ada!\n");
                                    } else {
                                        jumlahUser++;
                                        printf("Pengguna berhasil ditambahkan!\n");
                                    }
                                }
                                break;

                            case 6:
                                printf("\nDaftar Pengguna:\n");
                                printf("------------------------------------------\n");
                                printf("%-4s %-20s %-15s %s\n", "No", "Username", "Password", "Role");
                                printf("------------------------------------------\n");
                                for (i = 0; i < jumlahUser; i++) {
                                    printf("%-4d %-20s %-15s %s\n",
                                           i + 1,
                                           daftarUser[i].username,
                                           daftarUser[i].password,
                                           daftarUser[i].role);
                                }
                                printf("------------------------------------------\n");
                                printf("Total Pengguna: %d\n", jumlahUser);
                                break;

                            case 7:
                                printf("\nDaftar Pengguna:\n");
                                printf("------------------------------------------\n");
                                printf("%-4s %-20s %-15s %s\n", "No", "Username", "Password", "Role");
                                printf("------------------------------------------\n");
                                for (i = 0; i < jumlahUser; i++) {
                                    printf("%-4d %-20s %-15s %s\n",
                                           i + 1,
                                           daftarUser[i].username,
                                           daftarUser[i].password,
                                           daftarUser[i].role);
                                }
                                printf("------------------------------------------\n");
                                printf("Masukkan No pengguna yang ingin diupdate: ");
                                scanf("%d", &idx);
                                idx = idx - 1;
                                if (idx < 0 || idx >= jumlahUser) {
                                    printf("Nomor tidak valid!\n");
                                } else if (strcmp(daftarUser[idx].username, "Akmal") == 0) {
                                    printf("Tidak bisa mengubah admin utama!\n");
                                } else {
                                    printf("(Tekan ENTER untuk tidak mengubah)\n");
                                    printf("Username [%s]: ", daftarUser[idx].username);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarUser[idx].username, buf);

                                    printf("Password [%s]: ", daftarUser[idx].password);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarUser[idx].password, buf);

                                    printf("Role     [%s]: ", daftarUser[idx].role);
                                    scanf(" %[^\n]", buf);
                                    if (strlen(buf) > 0) strcpy(daftarUser[idx].role, buf);

                                    printf("Pengguna berhasil diupdate!\n");
                                }
                                break;

                            case 8:
                                printf("\nDaftar Pengguna:\n");
                                printf("------------------------------------------\n");
                                printf("%-4s %-20s %-15s %s\n", "No", "Username", "Password", "Role");
                                printf("------------------------------------------\n");
                                for (i = 0; i < jumlahUser; i++) {
                                    printf("%-4d %-20s %-15s %s\n",
                                           i + 1,
                                           daftarUser[i].username,
                                           daftarUser[i].password,
                                           daftarUser[i].role);
                                }
                                printf("------------------------------------------\n");
                                printf("Masukkan username yang dihapus: ");
                                scanf("%s", namaHapus);
                                if (strcmp(namaHapus, "Akmal") == 0) {
                                    printf("Tidak bisa menghapus admin utama!\n");
                                } else {
                                    idx = -1;
                                    for (i = 0; i < jumlahUser; i++) {
                                        if (strcmp(daftarUser[i].username, namaHapus) == 0) {
                                            idx = i;
                                            break;
                                        }
                                    }
                                    if (idx == -1) {
                                        printf("Username tidak ditemukan!\n");
                                    } else {
                                        for (i = idx; i < jumlahUser - 1; i++) {
                                            daftarUser[i] = daftarUser[i + 1];
                                        }
                                        jumlahUser--;
                                        printf("Pengguna '%s' berhasil dihapus!\n", namaHapus);
                                    }
                                }
                                break;

                            case 0:
                                printf("Logout berhasil! Kembali ke menu utama...\n");
                                break;

                            default:
                                printf("Pilihan tidak valid!\n");
                                break;
                        }

                    } else {
                        switch (pilihan) {

                            case 1:
                                printf("\nDaftar Hero:\n");
                                printf("------------------------------------------------------------------------\n");
                                printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
                                       "ID", "Nama", "Lane", "Rarity", "Harga", "Role", "Tier", "Win%");
                                printf("------------------------------------------------------------------------\n");
                                for (i = 0; i < jumlahHero; i++) {
                                    printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                                           daftarHero[i].id, daftarHero[i].nama, daftarHero[i].lane,
                                           daftarHero[i].rarity, daftarHero[i].harga,
                                           daftarHero[i].stats.role, daftarHero[i].stats.tier,
                                           daftarHero[i].stats.winRate);
                                }
                                printf("------------------------------------------------------------------------\n");
                                printf("Total Hero: %d\n", jumlahHero);
                                break;

                            case 0:
                                printf("Logout berhasil! Kembali ke menu utama...\n");
                                break;

                            default:
                                printf("Pilihan tidak valid!\n");
                                break;
                        }
                    }

                } while (pilihan != 0);
                break;

            case 2:
                if (jumlahUser >= MAX_USER) {
                    printf("Kapasitas pengguna penuh!\n");
                } else {
                    printf("\n--- Registrasi Akun Baru ---\n");
                    printf("Username baru : "); scanf("%s", daftarUser[jumlahUser].username);
                    printf("Password      : "); scanf("%s", daftarUser[jumlahUser].password);
                    strcpy(daftarUser[jumlahUser].role, "user");

                    sudahAda = 0;
                    for (i = 0; i < jumlahUser; i++) {
                        if (strcmp(daftarUser[i].username, daftarUser[jumlahUser].username) == 0) {
                            sudahAda = 1;
                            break;
                        }
                    }
                    if (sudahAda) {
                        printf("Username sudah ada! Silakan pilih username lain.\n");
                    } else {
                        jumlahUser++;
                        printf("Registrasi berhasil! Silakan login.\n");
                    }
                }
                break;

            case 3:
                pilihanTamu = 0;
                do {
                    printf("\n==================================================\n");
                    printf("        DAFTAR HERO GACHA (TAMU)\n");
                    printf("==================================================\n");
                    printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
                           "ID", "Nama", "Lane", "Rarity", "Harga", "Role", "Tier", "Win%");
                    printf("------------------------------------------------------------------------\n");
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
                    if (pilihanTamu != 0) {
                        printf("Pilihan tidak valid!\n");
                    }
                } while (pilihanTamu != 0);
                break;

            case 4:
                printf("Terima kasih telah menggunakan Gacha Hero ML!\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    }

    return 0;
}