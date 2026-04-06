#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ===== BUBBLE SORT =====
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ===== SELECTION SORT =====
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// ===== INSERTION SORT =====
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ===== MERGE SORT =====
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    printf("=====================================================\n");
    printf("        PROGRAM SORTING - PERBANDINGAN ALGORITMA       \n");
    printf("=====================================================\n\n");

    int n;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    printf("\nPilih metode sorting:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("Masukkan pilihan (1-4): ");

    int choice;
    scanf("%d", &choice);

    int arr[n];
    printf("\nMasukkan %d elemen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Buat copy array untuk ditampilkan
    int arrCopy[n];
    for (int i = 0; i < n; i++) {
        arrCopy[i] = arr[i];
    }

    printf("\n===== HASIL SORTING =====\n\n");
    printf("Sebelum sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arrCopy[i]);
    }
    printf("\n\n");

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Hasil Bubble Sort: ");
            break;
        case 2:
            selectionSort(arr, n);
            printf("Hasil Selection Sort: ");
            break;
        case 3:
            insertionSort(arr, n);
            printf("Hasil Insertion Sort: ");
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            printf("Hasil Merge Sort: ");
            break;
        case 5:
            quickSort(arr, 0, n - 1);
            printf("Hasil Quick Sort: ");
            break;
        default:
            printf("Pilihan tidak valid!\n");
            return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    printf("=====================================================\n");

    return 0;
}

