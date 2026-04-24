#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi membuat node baru
Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = nullptr;
    return baru;
}

// Fungsi tambah node di belakang (untuk inisialisasi)
void tambahBelakang(Node*& head, Node*& tail, int nilai) {
    Node* baru = buatNode(nilai);
    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// ============================================
// A. PENYISIPAN SETELAH HEAD
// ============================================
void sisipSetelahHead(Node*& head, int nilai) {
    if (head == nullptr) {
        cout << "List kosong! Node baru menjadi head." << endl;
        head = buatNode(nilai);
        return;
    }
    
    Node* baru = buatNode(nilai);
    
    // Langkah 1: Sambungkan node baru ke node kedua (head->next)
    baru->next = head->next;
    
    // Langkah 2: Sambungkan head ke node baru
    head->next = baru;
    
    cout << "Node " << nilai << " berhasil disisipkan setelah head (" 
         << head->data << ")" << endl;
}

// ============================================
// B. PENYISIPAN SEBELUM TAIL
// ============================================
void sisipSebelumTail(Node*& head, Node*& tail, int nilai) {
    if (head == nullptr) {
        cout << "List kosong! Node baru menjadi head dan tail." << endl;
        head = tail = buatNode(nilai);
        return;
    }
    
    if (head == tail) {
        // Hanya ada 1 node, sisip setelah head
        sisipSetelahHead(head, nilai);
        tail = head->next;
        return;
    }
    
    Node* baru = buatNode(nilai);
    Node* bantu = head;
    
    // Cari node sebelum tail
    while (bantu->next != tail) {
        bantu = bantu->next;
    }
    
    // Sambungkan node baru ke tail
    baru->next = tail;
    
    // Sambungkan node sebelum tail ke node baru
    bantu->next = baru;
    
    cout << "Node " << nilai << " berhasil disisipkan sebelum tail (" 
         << tail->data << ")" << endl;
}

// Fungsi cetak linked list
void cetakList(Node* head) {
    if (head == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }
    
    Node* bantu = head;
    cout << "Head -> ";
    while (bantu != nullptr) {
        cout << "[" << bantu->data << "]";
        if (bantu->next != nullptr) cout << " -> ";
        bantu = bantu->next;
    }
    cout << " -> NULL" << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    cout << "========================================" << endl;
    cout << "   SINGLE LINKED LIST - PENYISIPAN" << endl;
    cout << "========================================" << endl;
    
    // Buat list awal: 5 -> 9 -> 15
    cout << "\n[1] Membuat List Awal: 5 -> 9 -> 15" << endl;
    tambahBelakang(head, tail, 5);
    tambahBelakang(head, tail, 9);
    tambahBelakang(head, tail, 15);
    cetakList(head);
    cout << "Head: " << head->data << ", Tail: " << tail->data << endl;
    
    // A. Sisip setelah head
    cout << "\n[2] Penyisipan Setelah Head (sisip 7 setelah 5):" << endl;
    cout << "    Sebelum: ";
    cetakList(head);
    sisipSetelahHead(head, 7);
    cout << "    Sesudah: ";
    cetakList(head);
    
    // Reset list
    head = tail = nullptr;
    tambahBelakang(head, tail, 5);
    tambahBelakang(head, tail, 9);
    tambahBelakang(head, tail, 15);
    
    // B. Sisip sebelum tail
    cout << "\n[3] Penyisipan Sebelum Tail (sisip 12 sebelum 15):" << endl;
    cout << "    Sebelum: ";
    cetakList(head);
    sisipSebelumTail(head, tail, 12);
    cout << "    Sesudah: ";
    cetakList(head);
    cout << "    Head: " << head->data << ", Tail: " << tail->data << endl;
    
    // Demonstrasi kasus khusus
    cout << "\n[4] Kasus Khusus - List hanya 1 node:" << endl;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    tambahBelakang(head2, tail2, 100);
    cout << "    List awal: ";
    cetakList(head2);
    sisipSebelumTail(head2, tail2, 50);
    cout << "    Sesudah sisip sebelum tail: ";
    cetakList(head2);
    
    cout << "\n========================================" << endl;
    cout << "   PROGRAM SELESAI" << endl;
    cout << "========================================" << endl;
    
    return 0;
}