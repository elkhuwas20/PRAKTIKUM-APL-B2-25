#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int linear() {
    int data[] = {12, 45, 7, 23, 56, 10, 34};
    int n = sizeof(data) / sizeof(data[0]);

    int cari;
    bool found = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < n; i++) {
        if (data[i] == cari) {
            cout << "Angka ditemukan pada indeks: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Angka tidak ditemukan" << endl;
    }

    return 0;
}

int jumpsearch() {
    int data[] = {12, 45, 7, 23, 56, 10, 34};
    int n = sizeof(data) / sizeof(data[0]);

    int cari;
    bool found = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int step = sqrt(n);
    int prev = 0;

    while (data[min(step, n) - 1] < cari) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Angka tidak ditemukan" << endl;
            return 0;
        }
    }

    while (data[prev] < cari) {
        prev++;
        if (prev == min(step, n)) {
            cout << "Angka tidak ditemukan" << endl;
            return 0;
        }
    }

    if (data[prev] == cari) {
        cout << "Angka ditemukan pada indeks: " << prev << endl;
    } else {
        cout << "Angka tidak ditemukan" << endl;
    }

    return 0;
}

int interpolationSearch() {
    int data[] = {12, 45, 7, 23, 56, 10, 34};
    int n = sizeof(data) / sizeof(data[0]);

    int cari;
    bool found = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int low = 0;
    int high = n - 1;

    while (low <= high && cari >= data[low] && cari <= data[high]) {
        if (low == high) {
            if (data[low] == cari) {
                cout << "Angka ditemukan pada indeks: " << low << endl;
                return 0;
            }
            break;
        }

        int pos = low + ((high - low) / (data[high] - data[low]) * (cari - data[low]));

        if (data[pos] == cari) {
            cout << "Angka ditemukan pada indeks: " << pos << endl;
            return 0;
        }

        if (data[pos] < cari) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    cout << "Angka tidak ditemukan" << endl;
    return 0;
}

int main() {
    int pilihan;
    cout << "Pilih metode pencarian:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "3. Jump Search" << endl;
    cout << "4. Interpolation Search" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            linear();
            break;
        case 2: {
            // Create a sorted array for binary search
            int data[] = {12, 45, 7, 23, 56, 10, 34};
            int n = sizeof(data) / sizeof(data[0]);
            sort(data, data + n);
            vector<int> sortedData(data, data + n);
            int cari;
            cout << "Masukkan angka yang ingin dicari: ";
            cin >> cari;
            int index = binarySearch(sortedData, cari);
            if (index != -1) {
                cout << "Angka ditemukan pada indeks: " << index << endl;
            } else {
                cout << "Angka tidak ditemukan" << endl;
            }
            break;
        }
        case 3:
            jumpsearch();
            break;
        case 4:
            interpolationSearch();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}