#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <vector>
#include <numeric>

using namespace std;

// Kelas Utama
class resto {
public:
    string nama_menu, nama_kasir, nama_pelanggan;
    int harga_menu;

    resto* next;
};

resto* head, * tail, * cursor, * newnode;

class info_resto : public resto {
public:
    void info() {
        cout << "Selamat Datang di Restoran Sederhana" << endl;
    }
};

class info_kasir : public resto {
public:
    void info() {
        cout << "Masukkan Nama Kasir : ";
        cin >> nama_kasir;
    }
};

class info_pelanggan : public resto {
public:

    void info() {
        cout << "Masukkan Nama Pelanggan : ";
        cin >> nama_pelanggan;
    }
};

//membuat linked list
void buat_menu(string nama_menu, int harga_menu) {
    head = new resto();
    head->nama_menu = nama_menu;
    head->harga_menu = harga_menu;
    head->next = NULL;
    tail = head;
}

void tambah_menu(string nama_menu, int harga_menu) {
    newnode = new resto();
    newnode->nama_menu = nama_menu;
    newnode->harga_menu = harga_menu;
    newnode->next = NULL;
    tail->next = newnode;
    tail = newnode;
}

//menghitung data linked list
int hitung_data() {
    cursor = head;
    int jumlah = 0;
    while (cursor != NULL) {
        jumlah++;
        cursor = cursor->next;
    }
    return jumlah;
}

//menampilkan list menu
void tampil_menu() {
    int i = 1;
    if (hitung_data() == 0) {
        cout << "Menu Tidak Ada!!" << endl;
    }
    else {
        system("cls");
        cursor = head;
        while (cursor != NULL) {
            cout << i << "." << cursor->nama_menu << "\t\t" << cursor->harga_menu << endl;
            cursor = cursor->next;
            i++;
        }
    }
}

class pesan : public resto {
public:
    string tambah;
    int opsi, pilih, jumlah_menu, total_harga, tagihan;
    vector <int> vtr;

    //overloading operator
    void operator +() {
        cout << "\nTerima Kasih Telah Berkunjung! Silakan Datang Kembali" << endl;
    }

    void menu_utama() {
    menu:
        system("cls");
        cout << "+====================+" << endl;
        cout << "|  1. Pesan Menu     |" << endl;
        cout << "|  2. Bayar Tagihan  |" << endl;
        cout << "|  3. Keluar         |" << endl;
        cout << "+====================+" << endl;
        cout << endl;
        cout << "Pilih Opsi : ";
        cin >> opsi;

        if (opsi == 1) {
            tampil_menu();
        pesan:
            cout << "\nPilih Menu : ";
            cin >> pilih;
            cout << "Jumlah Menu : ";
            cin >> jumlah_menu;

            int index = 1;

            cursor = head;

            while (index != pilih) {
                cursor = cursor->next;
                index++;
            }

            cout << "\nMenu yang Dipesan : " << endl;
            cout << index << "." << cursor->nama_menu << "x" << jumlah_menu << "\t\tHarga : " << jumlah_menu * cursor->harga_menu << endl;
            vtr.push_back(jumlah_menu * cursor->harga_menu);

            cout << "\nApakah Anda Ingin Menambah Menu Pesanan (y/n) ? ";
            cin >> tambah;
            if (tambah == "y" || tambah == "Y") {
                goto pesan;
            }
            else if (tambah == "n" || tambah == "N") {
                goto menu;
            }

            menu_utama();
        }
        else if (opsi == 2) {
            total_harga = accumulate(vtr.begin(), vtr.end(), 0);
        bayar:
            cout << "\nTotal Tagihan : \t" << total_harga << endl;
            cout << "\nMasukkan Jumlah Uang Anda : ";
            cin >> tagihan;

            if (tagihan < total_harga) {
                cout << "\nUang Anda Tidak Mencukupi!! Silahkan Bayar Ulang." << endl;
                goto bayar;
            }
            else {
                cout << "\nUang Kembalian : \t\t" << (tagihan - total_harga) << endl;
            }
            operator +();
        }
        else if (opsi == 3) {
            operator +();
        }
        else {
            cout << "\nOpsi Salah!! Silakan Masukkan Kembali." << endl;

            menu_utama();
        }
    }
};

int main() {
    //deklarasai kelas = (nama kelas) (nama variabel)
    resto r;
    info_resto info_r;
    info_kasir info_k;
    info_pelanggan info_p;
    pesan p;

    //menjalankan program
    cout << "+==========================+" << endl;
    cout << "|  Nama Kelompok           |" << endl;
    cout << "+==========================+" << endl;
    cout << "|  Muhammad Hakam Fardana  |" << endl;
    cout << "|  Aji Prayoga             |" << endl;
    cout << "+==========================+" << endl;
    cout << endl;

    info_r.info();
    info_k.info();
    info_p.info();

    buat_menu("Nasi Goreng", 20000);
    tambah_menu("Mie Goreng", 15000);
    tambah_menu("Es Teh", 4000);
    tambah_menu("Es Jeruk", 5000);

    p.menu_utama();
}