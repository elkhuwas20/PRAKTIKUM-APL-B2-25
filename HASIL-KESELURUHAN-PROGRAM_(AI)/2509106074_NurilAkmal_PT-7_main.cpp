#include "GachaHeroLib.h"
#include <iostream>
#include <windows.h>

using namespace std;

Hero daftarHero[MAX_HERO];
int jumlahHero = 0;

User daftarUser[MAX_USER] = {
    {"Akmal",    "074", "admin"},
    {"Nuril",    "123", "user"},
    {"Triya",    "321", "user"},
    {"Pernanda", "111", "user"}
};
int jumlahUser = 4;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    SetConsoleTitleW(L"⭐ GACHA HERO - MOBILE LEGENDS ⭐");

    GachaHeroLib::inisialisasiHero(daftarHero, jumlahHero);

    GachaHeroLib::menuUtama(daftarUser, &jumlahUser, daftarHero, &jumlahHero);

    GachaHeroLib::pauseScreen();
    return 0;
}