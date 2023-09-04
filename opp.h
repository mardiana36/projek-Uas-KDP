#include <conio.h>
#include <iostream>
#include <string>
#define maxBus 2
#define maxPenumpang 3
using namespace std;
struct data_user {
  string nama, terminalTujuan;
  char tipeTiket;
  int kodeTiket;
};

struct tnode {
  data_user data;
  tnode *next;
};

class stack {
private:
  data_user containerBus[maxBus][maxPenumpang];
  int top[maxBus];
public:
  stack() {
    for (int i = 0; i < maxBus; i++) {
      top[i] = -1;
    }
  }
  
  bool isFull_bus(int index) { return top[index] == maxPenumpang - 1; }

  bool isEmpty_bus(int index) { return top[index] == -1; }

  void push(data_user data, int index) {
    top[index]++;
    containerBus[index][top[index]] = data;
    cout << "Slahkan menuju ke BUS " << index + 1 << endl;
  }
  void pop(int index) {
    if (isEmpty_bus(index) == false) {
      for (int i = top[index]; i >= 0; i--) {
        cout << "Penumpang dengan [Kode Tiket: "<< containerBus[index][i].kodeTiket << "] atas Nama: "<< containerBus[index][i].nama << endl;
        top[index]--;
      }
      cout << "Berhasil di hapus!" << endl;
    } else {
      cout << "Tidak ada penumpang!" << endl;
    }
  }

  void display_stack(int index) {
    if (isEmpty_bus(index) == false) {
      cout << "Jumlah Penumpang: " << top[index]+1 << endl;
      cout << "=================" << endl;
    for (int i = top[index]; i >= 0; i--) {
        cout << "\nDetail Data: ";
        cout << "\nNama           : " << containerBus[index][i].nama;
        cout << "\nKode Tiket     : " << containerBus[index][i].kodeTiket;
        cout << "\nTipe Tiket     : " << containerBus[index][i].tipeTiket;
        cout << "\nTujuan Terminal: " << containerBus[index][i].terminalTujuan;
        cout << endl;
      }
    } else {
      cout << "Tidak ada penumpang!" << endl;
    }
  }
};

class priorityQueue {
private:
  tnode *head;
  int kode = 100;
  int maxAntrian= (maxPenumpang * maxBus);
public:
  
  priorityQueue() { head = NULL; }

  bool isEmpty() { return head == NULL; }
  int isFull() {
    int  count= 0;
    tnode *bantu;
    bantu = head;
    while (bantu != NULL) {
      count++;
      bantu = bantu->next;
    }
    return count >= maxAntrian;
  }
 
  int kodeTiket() { return ++kode; }

  void enqueue(data_user myData) {
    tnode *baru;
    baru = new tnode;
    baru->data = myData;
    baru->next = NULL;
    if (isEmpty() == true) {
      head = baru;
      head->next = NULL;
    } else {
      if (head->data.tipeTiket > baru->data.tipeTiket) {
        baru->next = head;
        head = baru;
      } else {
        tnode *bantu = head;
        while (bantu->next != NULL &&
               bantu->next->data.tipeTiket <= baru->data.tipeTiket) {
          bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
      }
    }
    cout << "\n|Data berhasil di masuk ke antrian." << endl;
    cout << "|===>>>KODE TIKET: " << myData.kodeTiket;
  }
  
  void dequeue(stack &bus) {
    tnode *panggil;
    data_user myData;
    for (int i = 0; i < maxBus; i++) {
      if (bus.isFull_bus(i) == false) {
        if (isEmpty() == false) {
          if (head->next != NULL) {
            panggil = head;
            head = head->next;
            myData = panggil->data;
            // awal percobaan
            delete panggil;
             cout << "Panggilan kepada antrian dengan:"
                 << "\n========================================================"
                 << "\n NAMA           : " << myData.nama
                 << "\n KODE TIKET     : " << myData.kodeTiket
                 << "\n KELAS TIKET    : " << myData.tipeTiket
                 << "\n TUJUAN TERMINAL: " << myData.terminalTujuan 
                 << "\n========================================================" << endl;
            bus.push(myData, i);
            break;
          } else {
            myData = head->data;
            head = NULL;
            cout << "Panggilan kepada antrian dengan:"
                 << "\n========================================================"
                 << "\n NAMA           : " << myData.nama
                 << "\n KODE TIKET     : " << myData.kodeTiket
                 << "\n KELAS TIKET    : " << myData.tipeTiket
                 << "\n TUJUAN TERMINAL: " << myData.terminalTujuan 
                 << "\n========================================================" << endl;
            bus.push(myData, i);
            break;
          }
        } else {
          cout << "Antrian masih kosong!" << endl;
          break;
        }
      } else {
        cout << "BUS " << i + 1 << "Penuh!" << endl;
      }
    }
  }

  void displayAll() {
    tnode *bantu;
    bantu = head;
    int b = 1;
    if (isEmpty() == false) {
      while (bantu != NULL) {
        cout << "\n|=============|" << endl;
        cout << "|Antrian ke-" << b << " |"
             << "\n|_____________|___|"
             << "\n| KODE TIKET: " << bantu->data.kodeTiket << " |"
             << "\n| KELAS TIKET: " << bantu->data.tipeTiket << "  |";
        cout << "\n|=================|" << endl;
        cout << "\n|------------------------------>>>" << endl;
        bantu = bantu->next;
        b++;
      }
    } else {
      cout << "Antrian Masih Kosong!" << endl;
    }
  }

  void sequentialSearch(int key) {
    tnode *bantu;
    bantu = head;
    int b = 1;
    bool ketemu = false;
    if (isEmpty() == false) {
      while (bantu != NULL) {
        if (key == bantu->data.kodeTiket) {
          ketemu = true;
          break;
        }
        b++;
        bantu = bantu->next;
      }
      if (ketemu == true) {
        cout << "\nData Dengan [KODE TIKET: " << key << "] Ditemukan!"
             << "\n=>> Pada Antrian [ke-" << b << "] Dengan " << b - 1
             << " Antrian Didepannya."
             << "\n======================================================"
             << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
             << "\n|| Detail Data: "
             << "\n||   NAMA           : " << bantu->data.nama
             << "\n||   KODE TIKET     : " << bantu->data.kodeTiket
             << "\n||   KELAS TIKET    : " << bantu->data.tipeTiket
             << "\n||   TUJUAN TERMINAL: " << bantu->data.terminalTujuan
             << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
      } else {
        cout << "\nData Dengan [KODE TIKET: " << key << "] Tidak Ditemukan."
             << "\n=>> Pastikan anda memasukan KODE TIKET dengan benar!"
             << "\n======================================================="
             << endl;
      }
    } else {
      cout << "Antrian Masih Kosong!" << endl;
    }
  }
};