#include <iostream>
using namespace std;
struct Mahasiswa {
string nama;
int nim;
};
int main() {
Mahasiswa mhs1;
Mahasiswa *mhsPtr = &mhs1;
mhs1.nama = "Yunjin";
mhs1.nim = 321;
cout << mhs1.nama << " - " << mhs1.nim << endl;
mhsPtr->nama = "Chaewon";
mhsPtr->nim = 123;
cout << mhs1.nama << " - " << mhs1.nim << endl;
cout << mhsPtr->nama << " - " << mhsPtr->nim << endl;
return 0;
}