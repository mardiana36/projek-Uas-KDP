#include "opp.h"
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;
int hitung(data_user data) {
  int bantu;
  if (data.tipeTiket == 'A') {
    bantu = 225000;
  } else if (data.tipeTiket == 'B') {
    bantu = 160000;
  }else if (data.tipeTiket == 'C') {
    bantu = 100000;
  }
  return bantu;
}
int main() {
  data_user myData;
  priorityQueue p;
  stack b;
  char pilih, pilih2, terminal;
  int key;
  do {
    system("cls");
     cout << "\t\t                  <(^)>"                    << endl;
     cout << "\t\t                <{(mwm)}>"                  << endl;
     cout << "\t\t              <{(mwmwmwm)}>"                << endl;
     cout << "\t\t            <{(wmwm U mwmw)}>"              << endl;
     cout << "\t\t          <{(mwmwmw A wmwmwm)}>"            << endl;
     cout << "\t\t        <{(wmwmwmwm S mwmwmwmw)}>"          << endl;
     cout << "\t\t     <{(mwmwmwmwm K D P mwmwmwmwm)}>"       << endl;
     cout << "\t\t<<{(wmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmw)}>>"  << endl;
      cout << "\t\t   |||||| SISTEM ADMIN TIKET BUS|||||"
         << "\n\t\t   wmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwm"
         << "\n\t\t   |mwmwmwm|   PILIH MENU   |mwmwmwm|"
         << "\n\t\t   wmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwm"
         << "\n\t\t   |x 1. Pembelian tiket           x|"
         << "\n\t\t   |  2. Cek nomor antrian          |"
         << "\n\t\t   |  3. Tampilkan semua antrian    |"
         << "\n\t\t   |  4. Panggil antrian            |"
         << "\n\t\t   |  5. Tampilkan data penumpang   |"
         << "\n\t\t   |  6. Hapus semua data penumpang |"
         << "\n\t\t   |x 7. Exit                      x|"
         << "\n\t\t   =================================="
         << "\n\t\t   |==>>> PILIH: ";
    cin >> pilih;
    switch (pilih) {
    case '1':
      if (p.isFull()==false) {
      system("cls");
      cin.ignore();
      cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
      cout << "|xxxPEMBELIAN TIKET BUSxxx|" << endl;
      cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
      cout << " Input Data Pembeli: " << endl;
      cout << " =>>Nama: ";
      getline(cin, myData.nama);
      do {
        system("cls");
        cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
        cout << "|xxxPEMBELIAN TIKET BUSxxx|" << endl;
        cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
        cout << " Input Data Pembeli: " << endl;
        cout << " =>>Nama: " << myData.nama << endl;
        cout << "KETERANGAN KELAS TIKET: "
             << "\n * Kelas A (Rp225.000)"
             << "\n * Kelas B (Rp160.000)"
             << "\n * Kelas C (Rp100.000)"
             << endl;
        cout << "\nklik apa saja untuk lanjut...";
        _getch();
        system("cls");
        cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
        cout << "|xxxPEMBELIAN TIKET BUSxxx|" << endl;
        cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
        cout << " Input Data Pembeli: " << endl;
        cout << " =>>Nama: " << myData.nama << endl;
        cout << " =>>Kelas Tiket[A/B/C]: ";
        cin >> myData.tipeTiket;
        if (myData.tipeTiket != 'A' && myData.tipeTiket != 'B' &&
            myData.tipeTiket != 'C') {
          cout << "Pastikan anda memasukan A/B/C !" << endl;
          Sleep(3000);
        }
        cin.ignore();
      } while (myData.tipeTiket != 'A' && myData.tipeTiket != 'B' &&
               myData.tipeTiket != 'C');
      do {
        system("cls");
        cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
        cout << "|xxxPEMBELIAN TIKET BUSxxx|" << endl;
        cout << "mwmwmwmwmwmwmwmwmwmwmwmwmwm" << endl;
        cout << " Input Data Pembeli: " << endl;
        cout << " =>>Nama: " << myData.nama << endl;
        cout << " =>>Kelas Tiket[A/B/C]: " << myData.tipeTiket <<endl;
        cout << "|===================================|" << endl;
        cout << "| TUJUAN TERMINAL BUS DENPASAR BALI |"
             << "\n| 1. Terminal Ubung                 |"
             << "\n| 2. Terminal Terminal Tegal Sari   |"
             << "\n|===================================|"
             << "\n =>>Pilih Terminal[1/2]: ";
        cin >> terminal;
        if (terminal != '1' && terminal != '2') {
          cout << "Pastikan anda memasukan 1/2 !" << endl;
          Sleep(3000);
        }
        cin.ignore();
      } while (terminal != '1' && terminal != '2');

      if (terminal == '1') {
        myData.terminalTujuan = "Terminal Ubung Denpasar, Bali";
      } else if (terminal == '2') {
         myData.terminalTujuan = "Terminal Tegal Sari Denpasar, Bali";
      }
      myData.kodeTiket = p.kodeTiket();
      cout << "\nSilhakan melakukan pembayaran sebesar Rp" << hitung(myData) << endl;
       cout << "\nklik apa saja untuk lanjut...";
      _getch();
      p.enqueue(myData);
      } else {
      cout << "\nAntrian BUS sudah mencapai kapasitas maksimal!" <<endl;
      }
      _getch();
      break;
    case '2':
      cout << "\n =>>Kode Tiket: ";
      cin >> key;
      p.sequentialSearch(key);
      _getch();
      break;
    case '3':
      cout << "\nAntrian: " << endl;
      cout << "========" << endl;
      p.displayAll();
      _getch();
      break;
    case '4':
      p.dequeue(b);
      _getch();
      break;
    case '5':
      do {
        system("cls");
        cout << "MWMmwmwmwmwmwmwmwmwmwmwmwmwmwmMWM" << endl;
        cout << "|    TAMPILKAN DATA PENUMPANG   |" << endl;
        cout << "WMWmwmwmwmwmwmwmwmwmwmwmwmwmwmWMW" 
             << "\n | Pilih Menu:                 |"
             << "\n |  1. BUS 1                   |"
             << "\n |  2. BUS 2                   |"
             << "\n |  3. Exit                    |"
             << "\nWMWmwmwmwmwmwmwmwmwmwmwmwmwmwmWMW" 
             << "\n|=>> Pilih: ";
        cin >> pilih2;
        if (pilih2 == '1') {
          key = 0;
          cout << "\nData penumpang di BUS " << key + 1 << endl;
          b.display_stack(key);
          _getch();
        } else if (pilih2 == '2') {
          key = 1;
          cout << "\nData penumpang di BUS " << key + 1 << endl;
          b.display_stack(key);
          _getch();
        }
      } while (pilih2 != '3');
      break;
    case '6':
      do {
        system("cls");
        cout << "MWMmwmwmwmwmwmwmwmwmwmwmwmwmwmMWM" << endl;
        cout << "|      HAPUS DATA PENUMPANG     |" << endl;
        cout << "WMWmwmwmwmwmwmwmwmwmwmwmwmwmwmWMW" 
             << "\n | Pilih Menu:                 |"
             << "\n |  1. BUS 1                   |"
             << "\n |  2. BUS 2                   |"
             << "\n |  3. Exit                    |"
             << "\nWMWmwmwmwmwmwmwmwmwmwmwmwmwmwmWMW" 
             << "\n|=>> Pilih: ";
        cin >> pilih2;
        if (pilih2 == '1') {
          key = 0;
          cout << "\nBUS " << key + 1 << endl;
          b.pop(key);
          _getch();
        } else if (pilih2 == '2') {
          key = 1;
          cout << "\nBUS " << key + 1 << endl;
          b.pop(key);
          _getch();
        }
      } while (pilih2 != '3');
      break;
    }
  } while (pilih != '7');

  return 0;
}