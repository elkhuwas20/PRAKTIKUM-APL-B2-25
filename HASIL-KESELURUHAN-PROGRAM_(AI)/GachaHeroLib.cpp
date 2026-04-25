#include "GachaHeroLib.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void GachaHeroLib::setConsoleColor(ConsoleColor foreground, ConsoleColor background) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (background << 4) | foreground);
}

void GachaHeroLib::resetConsoleColor() {
    setConsoleColor(LIGHT_GRAY, BLACK);
}

void GachaHeroLib::clearScreen() {
    system("cls");
}

void GachaHeroLib::pauseScreen() {
    system("pause");
}

void GachaHeroLib::cetakGaris(int panjang) {
    setConsoleColor(CYAN);
    for (int i = 0; i < panjang; i++) printf("═");
    printf("\n");
    resetConsoleColor();
}

void GachaHeroLib::cetakGarisDua(int panjang) {
    setConsoleColor(YELLOW);
    for (int i = 0; i < panjang; i++) printf("─");
    printf("\n");
    resetConsoleColor();
}

void GachaHeroLib::cetakHeaderHero() {
    setConsoleColor(LIGHT_GRAY);
    printf("%-4s %-18s %-12s %-10s %-7s %-10s %-5s %s\n",
           "ID","Nama","Lane","Rarity","Harga","Role","Tier","Win%");
    setConsoleColor(CYAN);
    printf("────────────────────────────────────────────────────────────────────────\n");
    resetConsoleColor();
}

void GachaHeroLib::cetakHeaderUser() {
    setConsoleColor(LIGHT_GRAY);
    printf("%-4s %-20s %-15s %s\n","No","Username","Password","Role");
    setConsoleColor(CYAN);
    printf("──────────────────────────────────────────────\n");
    resetConsoleColor();
}

void GachaHeroLib::cetakBarisTamu() {
    printf("\n");
    cetakGaris(60);
    setConsoleColor(MAGENTA, BLACK);
    printf("        ☆ DAFTAR HERO GACHA (TAMU) ☆\n");
    resetConsoleColor();
    cetakGaris(60);
}

void GachaHeroLib::cetakInfo_int(const char *label, int nilai) {
    setConsoleColor(GREEN);
    printf("%-12s : ", label);
    setConsoleColor(YELLOW);
    printf("%d\n", nilai);
    resetConsoleColor();
}

void GachaHeroLib::cetakInfo_str(const char *label, const char *nilai) {
    setConsoleColor(GREEN);
    printf("%-12s : ", label);
    setConsoleColor(YELLOW);
    printf("%s\n", nilai);
    resetConsoleColor();
}

void GachaHeroLib::cetakInfo_float(const char *label, float nilai) {
    setConsoleColor(GREEN);
    printf("%-12s : ", label);
    setConsoleColor(YELLOW);
    printf("%.2f\n", nilai);
    resetConsoleColor();
}

void GachaHeroLib::inisialisasiHero(Hero daftar[], int &jumlah) {
    jumlah = 5;

    daftar[0].id = 1;
    strcpy(daftar[0].nama, "Layla");
    strcpy(daftar[0].lane, "Gold Lane");
    daftar[0].harga = 150;
    strcpy(daftar[0].rarity, "Epic");
    strcpy(daftar[0].stats.role, "Marksman");
    strcpy(daftar[0].stats.tier, "B");
    daftar[0].stats.winRate = 51;

    daftar[1].id = 2;
    strcpy(daftar[1].nama, "Tigreal");
    strcpy(daftar[1].lane, "EXP Lane");
    daftar[1].harga = 200;
    strcpy(daftar[1].rarity, "Epic");
    strcpy(daftar[1].stats.role, "Tank");
    strcpy(daftar[1].stats.tier, "A");
    daftar[1].stats.winRate = 54;

    daftar[2].id = 3;
    strcpy(daftar[2].nama, "Kagura");
    strcpy(daftar[2].lane, "Mid Lane");
    daftar[2].harga = 600;
    strcpy(daftar[2].rarity, "Legend");
    strcpy(daftar[2].stats.role, "Mage");
    strcpy(daftar[2].stats.tier, "S");
    daftar[2].stats.winRate = 57;

    daftar[3].id = 4;
    strcpy(daftar[3].nama, "Hayabusa");
    strcpy(daftar[3].lane, "Jungle");
    daftar[3].harga = 500;
    strcpy(daftar[3].rarity, "Legend");
    strcpy(daftar[3].stats.role, "Assassin");
    strcpy(daftar[3].stats.tier, "S");
    daftar[3].stats.winRate = 55;

    daftar[4].id = 5;
    strcpy(daftar[4].nama, "Odette");
    strcpy(daftar[4].lane, "Mid Lane");
    daftar[4].harga = 300;
    strcpy(daftar[4].rarity, "Epic");
    strcpy(daftar[4].stats.role, "Mage");
    strcpy(daftar[4].stats.tier, "A");
    daftar[4].stats.winRate = 52;
}

void GachaHeroLib::tampilkanSemuaHero(Hero daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw HeroException("Belum ada hero dalam daftar!");

        printf("\n");
        cetakGaris(70);
        setConsoleColor(CYAN, BLACK);
        printf("  ★ DAFTAR HERO ★\n");
        resetConsoleColor();
        cetakGaris(70);
        
        cetakHeaderHero();
        for (int i = 0; i < jumlah; i++) {
            setConsoleColor(LIGHT_GRAY);
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   daftar[i].id, daftar[i].nama, daftar[i].lane,
                   daftar[i].rarity, daftar[i].harga,
                   daftar[i].stats.role, daftar[i].stats.tier,
                   daftar[i].stats.winRate);
        }
        resetConsoleColor();
        cetakGaris(70);
        
        setConsoleColor(YELLOW);
        printf("Total Hero: %d\n", jumlah);
        int jumlahMage = hitungHeroDenganRole(daftar, 0, jumlah, "Mage");
        printf("Jumlah hero Mage (Recursive): %d\n", jumlahMage);
        resetConsoleColor();
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::tambahHero(Hero daftar[], int &jumlah) {
    try {
        if (jumlah >= MAX_HERO)
            throw HeroException("Data hero sudah penuh! Tidak bisa menambah hero baru.");

        printf("\n");
        cetakGaris(50);
        setConsoleColor(GREEN, BLACK);
        printf("  ✚ TAMBAH HERO BARU ✚\n");
        resetConsoleColor();
        cetakGaris(50);

        Hero *h = &daftar[jumlah];
        h->id = jumlah + 1;
        
        setConsoleColor(LIGHT_GRAY);
        printf("Nama Hero              : ");
        setConsoleColor(WHITE);
        scanf(" %[^\n]", h->nama);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Lane                   : ");
        setConsoleColor(WHITE);
        scanf(" %[^\n]", h->lane);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Rarity (Epic/Legend/Mythic): ");
        setConsoleColor(WHITE);
        scanf(" %[^\n]", h->rarity);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Harga (diamond)        : ");
        setConsoleColor(WHITE);
        scanf("%d", &h->harga);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Role (Tank/Mage/dll)   : ");
        setConsoleColor(WHITE);
        scanf(" %[^\n]", h->stats.role);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Tier (S/A/B/C)         : ");
        setConsoleColor(WHITE);
        scanf(" %[^\n]", h->stats.tier);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Win Rate (%%)           : ");
        setConsoleColor(WHITE);
        scanf("%d", &h->stats.winRate);
        resetConsoleColor();

        if (strlen(h->nama) == 0)
            throw InputException("Nama hero tidak boleh kosong!");
        if (h->harga <= 0)
            throw InputException("Harga hero harus lebih dari 0!");
        if (h->stats.winRate < 0 || h->stats.winRate > 100)
            throw InputException("Win rate harus berada di antara 0 dan 100!");

        jumlah++;
        
        setConsoleColor(GREEN);
        printf("\n✓ Hero berhasil ditambahkan!\n");
        resetConsoleColor();

        printf("\n");
        setConsoleColor(CYAN);
        printf("  [Info Hero Baru]\n");
        resetConsoleColor();
        cetakInfo_str("Nama", h->nama);
        cetakInfo_str("Role", h->stats.role);
        cetakInfo_int("Harga", h->harga);
        cetakInfo_int("WinRate", h->stats.winRate);
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::updateHero(Hero daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw HeroException("Tidak ada hero yang bisa diupdate!");

        tampilkanSemuaHero(daftar, jumlah);
        setConsoleColor(LIGHT_GRAY);
        printf("Masukkan ID hero yang ingin diupdate: ");
        setConsoleColor(WHITE);
        int idx;
        scanf("%d", &idx);
        resetConsoleColor();
        idx--;

        if (idx < 0 || idx >= jumlah)
            throw HeroException("ID hero tidak valid! Masukkan ID yang ada dalam daftar.");

        Hero *h = &daftar[idx];
        char buf[50];
        
        setConsoleColor(YELLOW);
        printf("\n(Tekan ENTER untuk tidak mengubah)\n");
        resetConsoleColor();

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
        if (strlen(buf) > 0) {
            int hargaBaru = atoi(buf);
            if (hargaBaru <= 0)
                throw InputException("Harga harus lebih dari 0!");
            h->harga = hargaBaru;
        }

        printf("Role  [%s]: ", h->stats.role);
        scanf(" %[^\n]", buf);
        if (strlen(buf) > 0) strcpy(h->stats.role, buf);

        printf("Tier  [%s]: ", h->stats.tier);
        scanf(" %[^\n]", buf);
        if (strlen(buf) > 0) strcpy(h->stats.tier, buf);

        printf("WinRate[%d]: ", h->stats.winRate);
        scanf(" %[^\n]", buf);
        if (strlen(buf) > 0) {
            int wrBaru = atoi(buf);
            if (wrBaru < 0 || wrBaru > 100)
                throw InputException("Win rate harus berada di antara 0 dan 100!");
            h->stats.winRate = wrBaru;
        }

        setConsoleColor(GREEN);
        printf("\n✓ Hero berhasil diupdate!\n");
        resetConsoleColor();
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::hapusHero(Hero daftar[], int &jumlah) {
    try {
        if (jumlah == 0)
            throw HeroException("Tidak ada hero yang bisa dihapus!");

        tampilkanSemuaHero(daftar, jumlah);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Masukkan ID hero yang ingin dihapus: ");
        setConsoleColor(WHITE);
        int idx;
        scanf("%d", &idx);
        resetConsoleColor();
        idx--;

        if (idx < 0 || idx >= jumlah)
            throw HeroException("ID hero tidak valid! Masukkan ID yang ada dalam daftar.");

        Hero *h = &daftar[idx];
        char konfirm;
        
        setConsoleColor(RED);
        printf("Yakin hapus '%s'? (y/n): ", h->nama);
        setConsoleColor(WHITE);
        scanf(" %c", &konfirm);
        resetConsoleColor();

        if (konfirm == 'y' || konfirm == 'Y') {
            for (int i = idx; i < jumlah - 1; i++) {
                daftar[i] = daftar[i + 1];
                daftar[i].id = i + 1;
            }
            jumlah--;
            setConsoleColor(GREEN);
            printf("✓ Hero berhasil dihapus!\n");
            resetConsoleColor();
        } else {
            setConsoleColor(YELLOW);
            printf("Dibatalkan.\n");
            resetConsoleColor();
        }
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::tampilkanSemuaUser(User daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw UserException("Tidak ada pengguna dalam daftar!");

        printf("\n");
        cetakGaris(50);
        setConsoleColor(CYAN, BLACK);
        printf("  ★ DAFTAR PENGGUNA ★\n");
        resetConsoleColor();
        cetakGaris(50);
        
        cetakHeaderUser();
        for (int i = 0; i < jumlah; i++) {
            setConsoleColor(LIGHT_GRAY);
            printf("%-4d %-20s %-15s %s\n",
                   i + 1, daftar[i].username, daftar[i].password, daftar[i].role);
        }
        resetConsoleColor();
        cetakGaris(50);
        
        setConsoleColor(YELLOW);
        printf("Total Pengguna: %d\n", jumlah);
        resetConsoleColor();
    }
    catch (const UserException &e) {
        setConsoleColor(RED);
        printf("[UserException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::tambahUser(User daftar[], int *jumlah) {
    try {
        if (*jumlah >= MAX_USER)
            throw UserException("Data pengguna sudah penuh!");

        printf("\n");
        cetakGaris(50);
        setConsoleColor(GREEN, BLACK);
        printf("  ✚ TAMBAH PENGGUNA ✚\n");
        resetConsoleColor();
        cetakGaris(50);

        User *u = &daftar[*jumlah];
        
        setConsoleColor(LIGHT_GRAY);
        printf("Username baru     : ");
        setConsoleColor(WHITE);
        scanf("%s", u->username);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Password          : ");
        setConsoleColor(WHITE);
        scanf("%s", u->password);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Role (admin/user) : ");
        setConsoleColor(WHITE);
        scanf("%s", u->role);
        resetConsoleColor();

        if (strlen(u->username) == 0)
            throw InputException("Username tidak boleh kosong!");
        if (strlen(u->password) == 0)
            throw InputException("Password tidak boleh kosong!");
        if (strcmp(u->role, "admin") != 0 && strcmp(u->role, "user") != 0)
            throw InputException("Role tidak valid! Harus 'admin' atau 'user'.");

        for (int i = 0; i < *jumlah; i++) {
            if (strcmp(daftar[i].username, u->username) == 0)
                throw UserException("Username sudah ada!");
        }

        (*jumlah)++;
        setConsoleColor(GREEN);
        printf("\n✓ Pengguna berhasil ditambahkan!\n");
        resetConsoleColor();
    }
    catch (const UserException &e) {
        setConsoleColor(RED);
        printf("[UserException] %s\n", e.what());
        resetConsoleColor();
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::updateUser(User daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw UserException("Tidak ada pengguna yang bisa diupdate!");

        tampilkanSemuaUser(daftar, jumlah);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Masukkan No pengguna yang ingin diupdate: ");
        setConsoleColor(WHITE);
        int idx;
        scanf("%d", &idx);
        resetConsoleColor();
        idx--;

        if (idx < 0 || idx >= jumlah)
            throw UserException("Nomor pengguna tidak valid!");

        User *u = &daftar[idx];
        if (strcmp(u->username, "Akmal") == 0)
            throw UserException("Tidak bisa mengubah admin utama!");

        char buf[50];
        setConsoleColor(YELLOW);
        printf("\n(Tekan ENTER untuk tidak mengubah)\n");
        resetConsoleColor();

        printf("Username [%s]: ", u->username);
        scanf(" %[^\n]", buf);
        if (strlen(buf) > 0) strcpy(u->username, buf);

        printf("Password [%s]: ", u->password);
        scanf(" %[^\n]", buf);
        if (strlen(buf) > 0) strcpy(u->password, buf);

        printf("Role     [%s]: ", u->role);
        scanf(" %[^\n]", buf);
        if (strlen(buf) > 0) {
            if (strcmp(buf, "admin") != 0 && strcmp(buf, "user") != 0)
                throw InputException("Role tidak valid! Harus 'admin' atau 'user'.");
            strcpy(u->role, buf);
        }

        setConsoleColor(GREEN);
        printf("\n✓ Pengguna berhasil diupdate!\n");
        resetConsoleColor();
    }
    catch (const UserException &e) {
        setConsoleColor(RED);
        printf("[UserException] %s\n", e.what());
        resetConsoleColor();
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::hapusUser(User daftar[], int *jumlah) {
    try {
        if (*jumlah == 0)
            throw UserException("Tidak ada pengguna yang bisa dihapus!");

        tampilkanSemuaUser(daftar, *jumlah);
        
        char namaHapus[30];
        setConsoleColor(LIGHT_GRAY);
        printf("Masukkan username yang dihapus: ");
        setConsoleColor(WHITE);
        scanf("%s", namaHapus);
        resetConsoleColor();

        if (strlen(namaHapus) == 0)
            throw InputException("Username yang akan dihapus tidak boleh kosong!");
        if (strcmp(namaHapus, "Akmal") == 0)
            throw UserException("Tidak bisa menghapus admin utama!");

        int idx = -1;
        for (int i = 0; i < *jumlah; i++) {
            if (strcmp(daftar[i].username, namaHapus) == 0) { idx = i; break; }
        }

        if (idx == -1)
            throw UserException("Username tidak ditemukan dalam daftar!");

        for (int i = idx; i < *jumlah - 1; i++)
            daftar[i] = daftar[i + 1];
        (*jumlah)--;
        
        setConsoleColor(GREEN);
        printf("✓ Pengguna '%s' berhasil dihapus!\n", namaHapus);
        resetConsoleColor();
    }
    catch (const UserException &e) {
        setConsoleColor(RED);
        printf("[UserException] %s\n", e.what());
        resetConsoleColor();
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::registrasi(User daftar[], int *jumlah) {
    try {
        if (*jumlah >= MAX_USER)
            throw UserException("Kapasitas pengguna penuh! Tidak bisa mendaftar.");

        printf("\n");
        cetakGaris(50);
        setConsoleColor(BLUE, BLACK);
        printf("  ★ REGISTRASI AKUN BARU ★\n");
        resetConsoleColor();
        cetakGaris(50);

        setConsoleColor(LIGHT_GRAY);
        printf("Username baru : ");
        setConsoleColor(WHITE);
        scanf("%s", daftar[*jumlah].username);
        
        setConsoleColor(LIGHT_GRAY);
        printf("Password      : ");
        setConsoleColor(WHITE);
        scanf("%s", daftar[*jumlah].password);
        resetConsoleColor();

        if (strlen(daftar[*jumlah].username) == 0)
            throw InputException("Username tidak boleh kosong!");
        if (strlen(daftar[*jumlah].password) == 0)
            throw InputException("Password tidak boleh kosong!");

        strcpy(daftar[*jumlah].role, "user");

        for (int i = 0; i < *jumlah; i++) {
            if (strcmp(daftar[i].username, daftar[*jumlah].username) == 0)
                throw UserException("Username sudah ada! Silakan pilih username lain.");
        }

        (*jumlah)++;
        setConsoleColor(GREEN);
        printf("\n✓ Registrasi berhasil! Silakan login.\n");
        resetConsoleColor();
    }
    catch (const UserException &e) {
        setConsoleColor(RED);
        printf("[UserException] %s\n", e.what());
        resetConsoleColor();
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
    }
}

int GachaHeroLib::login(User daftar[], int jumlah, int *isAdmin) {
    char username[30], password[20];
    int kesempatan = 3;

    while (kesempatan > 0) {
        try {
            printf("\n");
            cetakGaris(50);
            setConsoleColor(BLUE, BLACK);
            printf("  ★ LOGIN ★\n");
            resetConsoleColor();
            cetakGaris(50);

            setConsoleColor(LIGHT_GRAY);
            printf("Masukkan Username : ");
            setConsoleColor(WHITE);
            scanf("%s", username);
            
            setConsoleColor(LIGHT_GRAY);
            printf("Masukkan Password : ");
            setConsoleColor(WHITE);
            scanf("%s", password);
            resetConsoleColor();

            if (strlen(username) == 0)
                throw InputException("Username tidak boleh kosong!");
            if (strlen(password) == 0)
                throw InputException("Password tidak boleh kosong!");

            for (int i = 0; i < jumlah; i++) {
                if (strcmp(daftar[i].username, username) == 0 &&
                    strcmp(daftar[i].password, password) == 0) {
                    setConsoleColor(GREEN);
                    printf("\n✓ Login berhasil! Selamat datang, %s!\n", username);
                    resetConsoleColor();
                    *isAdmin = (strcmp(daftar[i].role, "admin") == 0) ? 1 : 0;
                    return i;
                }
            }

            kesempatan--;
            throw UserException("Username atau password salah!");
        }
        catch (const InputException &e) {
            setConsoleColor(RED);
            printf("[InputException] %s\n", e.what());
            resetConsoleColor();
            kesempatan--;
        }
        catch (const UserException &e) {
            setConsoleColor(RED);
            printf("[UserException] %s ", e.what());
            setConsoleColor(YELLOW);
            printf("Kesempatan tersisa: %d\n", kesempatan);
            resetConsoleColor();
        }
    }
    return -1;
}

// ============================================================
//  SEARCHING
// ============================================================
int GachaHeroLib::cariHeroRekursif(Hero daftar[], int idx, int jumlah, const char *nama) {
    if (idx >= jumlah) return -1;
    if (strcmp(daftar[idx].nama, nama) == 0) return idx;
    return cariHeroRekursif(daftar, idx + 1, jumlah, nama);
}

int GachaHeroLib::hitungHeroDenganRole(Hero daftar[], int idx, int jumlah, const char *role) {
    if (idx >= jumlah) return 0;
    int tambah = (strcmp(daftar[idx].stats.role, role) == 0) ? 1 : 0;
    return tambah + hitungHeroDenganRole(daftar, idx + 1, jumlah, role);
}

int GachaHeroLib::cariHeroByNama(Hero *daftar, int jumlah, const char *targetNama) {
    try {
        if (jumlah == 0)
            throw HeroException("Daftar hero masih kosong, tidak bisa mencari!");
        if (strlen(targetNama) == 0)
            throw InputException("Nama yang dicari tidak boleh kosong!");

        printf("\n");
        cetakGaris(70);
        setConsoleColor(CYAN);
        printf("  🔍 LINEAR SEARCH: Mencari Hero berdasarkan Nama (Substring)\n");
        resetConsoleColor();
        cetakGaris(70);
        
        setConsoleColor(YELLOW);
        printf("Pencarian: '%s'\n\n", targetNama);
        resetConsoleColor();

        int ditemukan = 0;
        int hasil[MAX_HERO];
        int totalHasil = 0;

        char cariLower[40];
        strcpy(cariLower, targetNama);
        for (int k = 0; cariLower[k]; k++)
            cariLower[k] = tolower(cariLower[k]);

        for (int i = 0; i < jumlah; i++) {
            char namaLower[40];
            strcpy(namaLower, (daftar + i)->nama);
            for (int k = 0; namaLower[k]; k++)
                namaLower[k] = tolower(namaLower[k]);

            printf("  [Cek %d] Nama = %s", i, (daftar + i)->nama);

            if (strstr(namaLower, cariLower) != NULL) {
                setConsoleColor(GREEN);
                printf(" ✓\n");
                resetConsoleColor();
                hasil[totalHasil] = i;
                totalHasil++;
                ditemukan = 1;
            } else {
                printf("\n");
            }
        }

        if (ditemukan) {
            printf("\n");
            setConsoleColor(GREEN);
            printf("✓ Ditemukan %d hero yang mengandung '%s'\n\n", totalHasil, targetNama);
            resetConsoleColor();
            
            cetakGaris(70);
            cetakHeaderHero();
            for (int i = 0; i < totalHasil; i++) {
                int idx = hasil[i];
                setConsoleColor(LIGHT_GRAY);
                printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                       (daftar + idx)->id, (daftar + idx)->nama, (daftar + idx)->lane,
                       (daftar + idx)->rarity, (daftar + idx)->harga,
                       (daftar + idx)->stats.role, (daftar + idx)->stats.tier,
                       (daftar + idx)->stats.winRate);
                resetConsoleColor();
            }
            cetakGaris(70);
            return hasil[0];
        }

        setConsoleColor(RED);
        printf("\n✗ Hero dengan nama yang mengandung '%s' tidak ditemukan.\n", targetNama);
        resetConsoleColor();
        return -1;
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
        return -1;
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
        return -1;
    }
}

int GachaHeroLib::cariHeroByHarga(Hero *daftar, int jumlah, int targetHarga) {
    try {
        if (jumlah == 0)
            throw HeroException("Daftar hero masih kosong, tidak bisa mencari!");
        if (targetHarga <= 0)
            throw InputException("Harga yang dicari harus lebih dari 0!");

        printf("\n");
        cetakGaris(70);
        setConsoleColor(CYAN);
        printf("  🔍 INTERPOLATION SEARCH: Mencari Hero berdasarkan Harga\n");
        resetConsoleColor();
        cetakGaris(70);
        
        setConsoleColor(YELLOW);
        printf("Pencarian Harga: %d Diamond\n\n", targetHarga);
        resetConsoleColor();

        int isSorted = 1;
        for (int i = 0; i < jumlah - 1; i++) {
            if ((daftar + i)->harga > (daftar + i + 1)->harga) {
                isSorted = 0;
                break;
            }
        }

        if (!isSorted) {
            setConsoleColor(YELLOW);
            printf("⚠ Array harga tidak terurut. Melakukan Sorting terlebih dahulu...\n\n");
            resetConsoleColor();

            int i, j, minIdx;
            Hero temp;
            for (i = 0; i < jumlah - 1; i++) {
                minIdx = i;
                for (j = i + 1; j < jumlah; j++) {
                    if ((daftar + j)->harga < (daftar + minIdx)->harga)
                        minIdx = j;
                }
                if (minIdx != i) {
                    temp = *(daftar + i);
                    *(daftar + i) = *(daftar + minIdx);
                    *(daftar + minIdx) = temp;
                }
            }

            cetakGaris(70);
            cetakHeaderHero();
            for (i = 0; i < jumlah; i++) {
                setConsoleColor(LIGHT_GRAY);
                printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                       (daftar + i)->id, (daftar + i)->nama, (daftar + i)->lane,
                       (daftar + i)->rarity, (daftar + i)->harga,
                       (daftar + i)->stats.role, (daftar + i)->stats.tier,
                       (daftar + i)->stats.winRate);
                resetConsoleColor();
            }
            cetakGaris(70);
            printf("\n");
        }

        int low = 0, high = jumlah - 1;
        while (low <= high && targetHarga >= (daftar + low)->harga &&
               targetHarga <= (daftar + high)->harga) {

            int pos = low + ((high - low) / ((daftar + high)->harga - (daftar + low)->harga)) *
                           (targetHarga - (daftar + low)->harga);

            setConsoleColor(LIGHT_GRAY);
            printf("  [Cek indeks %d] Harga = %d", pos, (daftar + pos)->harga);

            if ((daftar + pos)->harga == targetHarga) {
                setConsoleColor(GREEN);
                printf(" ✓ DITEMUKAN!\n\n");
                resetConsoleColor();
                setConsoleColor(GREEN);
                printf("✓ Hero ditemukan pada indeks: %d\n", pos);
                resetConsoleColor();
                return pos;
            }

            if ((daftar + pos)->harga < targetHarga) {
                printf(" (terlalu kecil)\n");
                low = pos + 1;
            } else {
                printf(" (terlalu besar)\n");
                high = pos - 1;
            }
        }

        setConsoleColor(RED);
        printf("\n✗ Hero dengan harga %d tidak ditemukan.\n", targetHarga);
        resetConsoleColor();
        return -1;
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
        return -1;
    }
    catch (const InputException &e) {
        setConsoleColor(RED);
        printf("[InputException] %s\n", e.what());
        resetConsoleColor();
        return -1;
    }
}

// ============================================================
//  SORTING
// ============================================================
void GachaHeroLib::sortNamaDescending(Hero daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw HeroException("Tidak ada hero untuk diurutkan!");

        printf("\n");
        cetakGaris(70);
        setConsoleColor(MAGENTA);
        printf("  🔄 BUBBLE SORT: Urutkan Hero Nama (Z-A)\n");
        resetConsoleColor();
        cetakGaris(70);

        int i, j;
        Hero temp;

        for (i = 0; i < jumlah - 1; i++) {
            for (j = 0; j < jumlah - i - 1; j++) {
                if (strcmp(daftar[j].nama, daftar[j + 1].nama) < 0) {
                    temp = daftar[j];
                    daftar[j] = daftar[j + 1];
                    daftar[j + 1] = temp;
                }
            }
        }

        printf("\n");
        cetakGaris(70);
        cetakHeaderHero();
        for (i = 0; i < jumlah; i++) {
            setConsoleColor(LIGHT_GRAY);
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   daftar[i].id, daftar[i].nama, daftar[i].lane,
                   daftar[i].rarity, daftar[i].harga,
                   daftar[i].stats.role, daftar[i].stats.tier,
                   daftar[i].stats.winRate);
            resetConsoleColor();
        }
        cetakGaris(70);
        
        setConsoleColor(GREEN);
        printf("✓ Sorting berhasil!\n");
        resetConsoleColor();
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::sortHargaAscending(Hero daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw HeroException("Tidak ada hero untuk diurutkan!");

        printf("\n");
        cetakGaris(70);
        setConsoleColor(MAGENTA);
        printf("  🔄 SELECTION SORT: Urutkan Hero Harga (Kecil-Besar)\n");
        resetConsoleColor();
        cetakGaris(70);

        int i, j, minIdx;
        Hero temp;

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

        printf("\n");
        cetakGaris(70);
        cetakHeaderHero();
        for (i = 0; i < jumlah; i++) {
            setConsoleColor(LIGHT_GRAY);
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   daftar[i].id, daftar[i].nama, daftar[i].lane,
                   daftar[i].rarity, daftar[i].harga,
                   daftar[i].stats.role, daftar[i].stats.tier,
                   daftar[i].stats.winRate);
            resetConsoleColor();
        }
        cetakGaris(70);
        
        setConsoleColor(GREEN);
        printf("✓ Sorting berhasil!\n");
        resetConsoleColor();
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::sortWinRateDescending(Hero daftar[], int jumlah) {
    try {
        if (jumlah == 0)
            throw HeroException("Tidak ada hero untuk diurutkan!");

        printf("\n");
        cetakGaris(70);
        setConsoleColor(MAGENTA);
        printf("  🔄 INSERTION SORT: Urutkan Hero Win Rate (Tinggi-Rendah)\n");
        resetConsoleColor();
        cetakGaris(70);

        int i, j;
        Hero temp;

        for (i = 1; i < jumlah; i++) {
            temp = daftar[i];
            j = i - 1;
            while (j >= 0 && daftar[j].stats.winRate < temp.stats.winRate) {
                daftar[j + 1] = daftar[j];
                j--;
            }
            daftar[j + 1] = temp;
        }

        printf("\n");
        cetakGaris(70);
        cetakHeaderHero();
        for (i = 0; i < jumlah; i++) {
            setConsoleColor(LIGHT_GRAY);
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   daftar[i].id, daftar[i].nama, daftar[i].lane,
                   daftar[i].rarity, daftar[i].harga,
                   daftar[i].stats.role, daftar[i].stats.tier,
                   daftar[i].stats.winRate);
            resetConsoleColor();
        }
        cetakGaris(70);
        
        setConsoleColor(GREEN);
        printf("✓ Sorting berhasil!\n");
        resetConsoleColor();
    }
    catch (const HeroException &e) {
        setConsoleColor(RED);
        printf("[HeroException] %s\n", e.what());
        resetConsoleColor();
    }
}

void GachaHeroLib::menuAdmin(User daftar[], Hero heroDaftar[], int &jumlahHero, int *jumlahUser, int userLogin) {
    int pilihan;
    do {
        printf("\n");
        cetakGaris(60);
        setConsoleColor(MAGENTA, BLACK);
        printf("  ★ ADMIN MENU ★  |  Logged as: %s\n", daftar[userLogin].username);
        resetConsoleColor();
        cetakGaris(60);
        
        setConsoleColor(CYAN);
        printf("  ▶ HERO MANAGEMENT\n");
        resetConsoleColor();
        printf("  1. ➕ Tambah Hero\n");
        printf("  2. 📋 Lihat Semua Hero\n");
        printf("  3. ✏️  Update Hero\n");
        printf("  4. ❌ Hapus Hero\n");
        
        setConsoleColor(CYAN);
        printf("  ▶ USER MANAGEMENT\n");
        resetConsoleColor();
        printf("  5. ➕ Tambah Pengguna\n");
        printf("  6. 📋 Lihat Semua Pengguna\n");
        printf("  7. ✏️  Update Pengguna\n");
        printf("  8. ❌ Hapus Pengguna\n");
        
        setConsoleColor(CYAN);
        printf("  ▶ ADVANCED OPERATIONS\n");
        resetConsoleColor();
        printf("  9. 🔍 Cari Hero (Recursive Demo)\n");
        printf("  10. 🔄 Sort Nama (Bubble Sort)\n");
        printf("  11. 🔄 Sort Harga (Selection Sort)\n");
        printf("  12. 🔄 Sort Win Rate (Insertion Sort)\n");
        printf("  0. 🚪 Logout\n");
        
        cetakGaris(60);
        setConsoleColor(YELLOW);
        printf("Pilih menu: ");
        setConsoleColor(WHITE);
        scanf("%d", &pilihan);
        resetConsoleColor();

        switch (pilihan) {
            case 1: tambahHero(heroDaftar, jumlahHero); break;
            case 2: tampilkanSemuaHero(heroDaftar, jumlahHero); break;
            case 3: updateHero(heroDaftar, jumlahHero); break;
            case 4: hapusHero(heroDaftar, jumlahHero); break;
            case 5: tambahUser(daftar, jumlahUser); break;
            case 6: tampilkanSemuaUser(daftar, *jumlahUser); break;
            case 7: updateUser(daftar, *jumlahUser); break;
            case 8: hapusUser(daftar, jumlahUser); break;
            case 9: {
                try {
                    char namaCari[40];
                    setConsoleColor(LIGHT_GRAY);
                    printf("Masukkan nama hero yang dicari: ");
                    setConsoleColor(WHITE);
                    scanf(" %[^\n]", namaCari);
                    resetConsoleColor();

                    if (strlen(namaCari) == 0)
                        throw InputException("Nama hero tidak boleh kosong!");

                    int hasil = cariHeroRekursif(heroDaftar, 0, jumlahHero, namaCari);
                    if (hasil == -1) {
                        setConsoleColor(RED);
                        printf("✗ Hero '%s' tidak ditemukan.\n", namaCari);
                        resetConsoleColor();
                    } else {
                        printf("\n");
                        cetakGaris(50);
                        setConsoleColor(GREEN);
                        printf("✓ Hero ditemukan di indeks %d:\n", hasil);
                        resetConsoleColor();
                        cetakInfo_str("Nama", heroDaftar[hasil].nama);
                        cetakInfo_str("Lane", heroDaftar[hasil].lane);
                        cetakInfo_str("Role", heroDaftar[hasil].stats.role);
                        cetakInfo_str("Tier", heroDaftar[hasil].stats.tier);
                        cetakInfo_int("Harga", heroDaftar[hasil].harga);
                        cetakInfo_int("WinRate", heroDaftar[hasil].stats.winRate);
                        cetakGaris(50);
                    }
                }
                catch (const InputException &e) {
                    setConsoleColor(RED);
                    printf("[InputException] %s\n", e.what());
                    resetConsoleColor();
                }
                break;
            }
            case 10: sortNamaDescending(heroDaftar, jumlahHero); break;
            case 11: sortHargaAscending(heroDaftar, jumlahHero); break;
            case 12: sortWinRateDescending(heroDaftar, jumlahHero); break;
            case 0:
                setConsoleColor(YELLOW);
                printf("🚪 Logout berhasil! Kembali ke menu utama...\n");
                resetConsoleColor();
                break;
            default:
                setConsoleColor(RED);
                printf("✗ Pilihan tidak valid!\n");
                resetConsoleColor();
        }
    } while (pilihan != 0);
}

void GachaHeroLib::menuUser(User daftar[], Hero heroDaftar[], int jumlahHero, int userLogin) {
    int pilihan;
    do {
        printf("\n");
        cetakGaris(60);
        setConsoleColor(BLUE, BLACK);
        printf("  ★ USER MENU ★  |  Logged as: %s\n", daftar[userLogin].username);
        resetConsoleColor();
        cetakGaris(60);
        
        printf("  1. 📋 Lihat Semua Hero\n");
        printf("  2. 🔍 Cari Hero by Nama (Linear Search)\n");
        printf("  3. 🔍 Cari Hero by Harga (Interpolation Search)\n");
        printf("  0. 🚪 Logout\n");
        
        cetakGaris(60);
        setConsoleColor(YELLOW);
        printf("Pilih menu: ");
        setConsoleColor(WHITE);
        scanf("%d", &pilihan);
        resetConsoleColor();

        switch (pilihan) {
            case 1:
                tampilkanSemuaHero(heroDaftar, jumlahHero);
                break;
            case 2: {
                try {
                    tampilkanSemuaHero(heroDaftar, jumlahHero);
                    char cariNama[40];
                    setConsoleColor(LIGHT_GRAY);
                    printf("\nMasukkan nama atau huruf hero yang dicari: ");
                    setConsoleColor(WHITE);
                    scanf(" %[^\n]", cariNama);
                    resetConsoleColor();

                    if (strlen(cariNama) == 0)
                        throw InputException("Input pencarian tidak boleh kosong!");

                    cariHeroByNama(heroDaftar, jumlahHero, cariNama);
                }
                catch (const InputException &e) {
                    setConsoleColor(RED);
                    printf("[InputException] %s\n", e.what());
                    resetConsoleColor();
                }
                break;
            }
            case 3: {
                try {
                    tampilkanSemuaHero(heroDaftar, jumlahHero);
                    int cariHarga;
                    setConsoleColor(LIGHT_GRAY);
                    printf("\nMasukkan harga hero yang dicari: ");
                    setConsoleColor(WHITE);
                    scanf("%d", &cariHarga);
                    resetConsoleColor();

                    if (cariHarga <= 0)
                        throw InputException("Harga yang dicari harus lebih dari 0!");

                    int hasil = cariHeroByHarga(heroDaftar, jumlahHero, cariHarga);
                    if (hasil != -1) {
                        printf("\n");
                        setConsoleColor(CYAN);
                        printf("  [Informasi Hero]\n");
                        resetConsoleColor();
                        cetakInfo_str("Nama", heroDaftar[hasil].nama);
                        cetakInfo_str("Lane", heroDaftar[hasil].lane);
                        cetakInfo_str("Rarity", heroDaftar[hasil].rarity);
                        cetakInfo_int("Harga", heroDaftar[hasil].harga);
                        cetakInfo_str("Role", heroDaftar[hasil].stats.role);
                        cetakInfo_str("Tier", heroDaftar[hasil].stats.tier);
                        cetakInfo_int("WinRate", heroDaftar[hasil].stats.winRate);
                    }
                }
                catch (const InputException &e) {
                    setConsoleColor(RED);
                    printf("[InputException] %s\n", e.what());
                    resetConsoleColor();
                }
                break;
            }
            case 0:
                setConsoleColor(YELLOW);
                printf("🚪 Logout berhasil! Kembali ke menu utama...\n");
                resetConsoleColor();
                break;
            default:
                setConsoleColor(RED);
                printf("✗ Pilihan tidak valid!\n");
                resetConsoleColor();
        }
    } while (pilihan != 0);
}

void GachaHeroLib::menuTamu(Hero heroDaftar[], int jumlahHero) {
    int pilihanTamu;
    do {
        cetakBarisTamu();
        cetakHeaderHero();
        for (int i = 0; i < jumlahHero; i++) {
            setConsoleColor(LIGHT_GRAY);
            printf("%-4d %-18s %-12s %-10s %-7d %-10s %-5s %d%%\n",
                   heroDaftar[i].id, heroDaftar[i].nama, heroDaftar[i].lane,
                   heroDaftar[i].rarity, heroDaftar[i].harga,
                   heroDaftar[i].stats.role, heroDaftar[i].stats.tier,
                   heroDaftar[i].stats.winRate);
        }
        resetConsoleColor();
        cetakGaris(60);
        
        setConsoleColor(YELLOW);
        printf("Total Hero: %d\n", jumlahHero);
        resetConsoleColor();
        
        printf("\n  0. 🔙 Kembali ke Menu Utama\n");
        setConsoleColor(YELLOW);
        printf("Pilih menu: ");
        setConsoleColor(WHITE);
        scanf("%d", &pilihanTamu);
        resetConsoleColor();
        
        if (pilihanTamu != 0) {
            setConsoleColor(RED);
            printf("✗ Pilihan tidak valid!\n");
            resetConsoleColor();
        }
    } while (pilihanTamu != 0);
}

void GachaHeroLib::menuUtama(User daftar[], int *jumlahUser, Hero heroDaftar[], int *jumlahHero) {
    int pilihanAwal = 0;
    while (pilihanAwal != 4) {
        printf("\n");
        cetakGaris(60);
        
        setConsoleColor(MAGENTA, BLACK);
        printf("╔════════════════════════════════════════════════════════════╗\n");
        printf("║          🎮 GACHA HERO - MOBILE LEGENDS 🎮                 ║\n");
        printf("║              ★ Sistem Manajemen Hero ★                     ║\n");
        printf("╚════════════════════════════════════════════════════════════╝\n");
        resetConsoleColor();
        
        cetakGaris(60);
        printf("  1. 🔐 Login\n");
        printf("  2. ✍️  Registrasi\n");
        printf("  3. 👁️  Lihat Hero (Tamu)\n");
        printf("  4. 🚪 Keluar\n");
        cetakGaris(60);
        
        setConsoleColor(YELLOW);
        printf("Pilih menu: ");
        setConsoleColor(WHITE);
        scanf("%d", &pilihanAwal);
        resetConsoleColor();

        switch (pilihanAwal) {
            case 1: {
                try {
                    int isAdmin = 0;
                    int userLogin = login(daftar, *jumlahUser, &isAdmin);
                    if (userLogin == -1) {
                        throw UserException("Anda telah gagal login 3 kali. Program berhenti.");
                    }
                    if (isAdmin)
                        menuAdmin(daftar, heroDaftar, *jumlahHero, jumlahUser, userLogin);
                    else
                        menuUser(daftar, heroDaftar, *jumlahHero, userLogin);
                }
                catch (const UserException &e) {
                    setConsoleColor(RED);
                    printf("[UserException] %s\n", e.what());
                    resetConsoleColor();
                    return;
                }
                catch (...) {
                    setConsoleColor(RED);
                    printf("[Error] Terjadi kesalahan saat login.\n");
                    resetConsoleColor();
                }
                break;
            }
            case 2:
                try {
                    registrasi(daftar, jumlahUser);
                }
                catch (const UserException &e) {
                    setConsoleColor(RED);
                    printf("[UserException] %s\n", e.what());
                    resetConsoleColor();
                }
                catch (...) {
                    setConsoleColor(RED);
                    printf("[Error] Terjadi kesalahan saat registrasi.\n");
                    resetConsoleColor();
                }
                break;
            case 3:
                menuTamu(heroDaftar, *jumlahHero);
                break;
            case 4:
                setConsoleColor(GREEN);
                printf("\n✓ Terima kasih telah menggunakan Gacha Hero ML!\n");
                printf("  Sampai jumpa lagi! 👋\n");
                resetConsoleColor();
                break;
            default:
                setConsoleColor(RED);
                printf("✗ Pilihan tidak valid!\n");
                resetConsoleColor();
        }
    }
}
