#ifndef GACHA_HERO_LIB_H
#define GACHA_HERO_LIB_H

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdexcept>

#define MAX_HERO 50
#define MAX_USER 10

enum ConsoleColor {
    BLACK = 0,
    DARK_BLUE = 1,
    DARK_GREEN = 2,
    DARK_CYAN = 3,
    DARK_RED = 4,
    DARK_MAGENTA = 5,
    DARK_YELLOW = 6,
    LIGHT_GRAY = 7,
    DARK_GRAY = 8,
    BLUE = 9,
    GREEN = 10,
    CYAN = 11,
    RED = 12,
    MAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};

class HeroException : public std::exception {
    char msg[200];
public:
    HeroException(const char *m) { strncpy(msg, m, 199); msg[199] = '\0'; }
    const char* what() const noexcept override { return msg; }
};

class UserException : public std::exception {
    char msg[200];
public:
    UserException(const char *m) { strncpy(msg, m, 199); msg[199] = '\0'; }
    const char* what() const noexcept override { return msg; }
};

class InputException : public std::exception {
    char msg[200];
public:
    InputException(const char *m) { strncpy(msg, m, 199); msg[199] = '\0'; }
    const char* what() const noexcept override { return msg; }
};

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

class GachaHeroLib {
public:
   
    static void setConsoleColor(ConsoleColor foreground, ConsoleColor background = BLACK);
    static void resetConsoleColor();
    
    
    static void cetakGaris(int panjang);
    static void cetakGarisDua(int panjang);
    static void cetakHeaderHero();
    static void cetakHeaderUser();
    static void cetakBarisTamu();
    static void cetakInfo_int(const char *label, int nilai);
    static void cetakInfo_str(const char *label, const char *nilai);
    static void cetakInfo_float(const char *label, float nilai);
    static void clearScreen();
    static void pauseScreen();
    
    static void inisialisasiHero(Hero daftar[], int &jumlah);
    static void tampilkanSemuaHero(Hero daftar[], int jumlah);
    static void tambahHero(Hero daftar[], int &jumlah);
    static void updateHero(Hero daftar[], int jumlah);
    static void hapusHero(Hero daftar[], int &jumlah);
    
   
    static void tampilkanSemuaUser(User daftar[], int jumlah);
    static void tambahUser(User daftar[], int *jumlah);
    static void updateUser(User daftar[], int jumlah);
    static void hapusUser(User daftar[], int *jumlah);
    static void registrasi(User daftar[], int *jumlah);
    
    
    static int login(User daftar[], int jumlah, int *isAdmin);
    
   
    static int cariHeroRekursif(Hero daftar[], int idx, int jumlah, const char *nama);
    static int hitungHeroDenganRole(Hero daftar[], int idx, int jumlah, const char *role);
    static int cariHeroByNama(Hero *daftar, int jumlah, const char *targetNama);
    static int cariHeroByHarga(Hero *daftar, int jumlah, int targetHarga);
    
    static void sortNamaDescending(Hero daftar[], int jumlah);
    static void sortHargaAscending(Hero daftar[], int jumlah);
    static void sortWinRateDescending(Hero daftar[], int jumlah);
    
    static void menuAdmin(User daftar[], Hero heroDaftar[], int &jumlahHero, int *jumlahUser, int userLogin);
    static void menuUser(User daftar[], Hero heroDaftar[], int jumlahHero, int userLogin);
    static void menuTamu(Hero heroDaftar[], int jumlahHero);
    static void menuUtama(User daftar[], int *jumlahUser, Hero heroDaftar[], int *jumlahHero);
};

#endif 