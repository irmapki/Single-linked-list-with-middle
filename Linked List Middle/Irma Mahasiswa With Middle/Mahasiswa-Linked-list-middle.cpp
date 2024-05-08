#include <iostream>

using namespace std;

struct Mahasiswa{
    string nama, jurusan;
    int nim;

    Mahasiswa* next;

};

Mahasiswa *kepala, *ekor, *saat_ini, *node_baru, *hapus, *sebelum;

void createSingleLinkedList(string nama, string jurusan, int nim){
  kepala = new Mahasiswa();
  kepala->nama = nama;
  kepala->jurusan = jurusan;
  kepala->nim = nim;
  kepala->next = NULL;
  ekor = kepala;
}

// print single linked list
int countSingleLinkedList(){
  saat_ini = kepala;
  int jumlah = 0;
  while( saat_ini != NULL ){
    jumlah++;
    saat_ini = saat_ini->next;
  }
  return jumlah;
}

// tambahAwal Single linked list
void addFirst(string nama, string jurusan, int nim){
  node_baru = new Mahasiswa();
  node_baru->nama = nama;
  node_baru->jurusan = jurusan;
  node_baru->nim = nim;
  node_baru->next = kepala;
  kepala = node_baru;
}

// tambahAkhir Single linked list
void addLast(string nama, string jurusan, int nim){
  node_baru = new Mahasiswa();
  node_baru->nama = nama;
  node_baru->jurusan = jurusan;
  node_baru->nim = nim;
  node_baru->next = NULL;
  ekor->next = node_baru;
  ekor = node_baru;
}

// tambah tengah single linked list
void addMiddle(string nama, string jurusan, int nim, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    node_baru = new Mahasiswa();
    node_baru->nama = nama;
    node_baru->jurusan = jurusan;
    node_baru->nim = nim;

    // tranversing
    saat_ini = kepala;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      saat_ini = saat_ini->next;
      nomor++;
    }
    node_baru->next = saat_ini->next;
    saat_ini->next = node_baru;
  }
}


// Remove First
void removeFirst(){
  hapus = kepala;
  kepala = kepala->next;
  delete hapus;
}

// Remove Last
void removeLast(){
  hapus = ekor;
  saat_ini = kepala;
  while( saat_ini->next != ekor ){
    saat_ini = saat_ini->next;
  }
  ekor = saat_ini;
  ekor->next = NULL;
  delete hapus;
}

// remove middle
void removeMiddle(int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    saat_ini = kepala;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        sebelum = saat_ini;
      }
      if( nomor == posisi ){
        hapus = saat_ini;
      }
      saat_ini = saat_ini->next;
      nomor++;
    }
    sebelum->next = saat_ini;
    delete hapus;
  }
}

// ubahAwal Single linked list
void changeFirst(string nama, string jurusan, int nim){
  kepala->nama = nama;
  kepala->jurusan = jurusan;
  kepala->nim = nim;
}

// ubahAkhir Single linked list
void changeLast(string nama, string jurusan, int nim){
  ekor->nama = nama;
  ekor->jurusan = jurusan;
  ekor->nim = nim;
}

// ubah Tengah Single linked list
void changeMiddle(string nama, string jurusan, int nim, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1 || posisi == countSingleLinkedList() ){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    saat_ini = kepala;
    int nomor = 1;
    while( nomor < posisi ){
      saat_ini = saat_ini->next;
      nomor++;
    }
    saat_ini->nama = nama;
    saat_ini->jurusan = jurusan;
    saat_ini->nim = nim;
  }
}

// print single linked list
void printSingleLinkedList(){
cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
  saat_ini = kepala;
  while( saat_ini != NULL ){
    cout << "Nama Mahasiswa : " << saat_ini->nama << endl;
    cout << "Jurusan Mahasiswa : " << saat_ini->jurusan << endl;
    cout << "NIM Mahasiswa : " << saat_ini->nim << endl;

    saat_ini = saat_ini->next;
  }
}

int main() {
    createSingleLinkedList("Irma", "DKV", 11111);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    addFirst("Suroso", "Psikologi", 2222);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    addLast("Sulhan", "Kesehatan Masyarakat", 3333);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    removeFirst();
    printSingleLinkedList();
    cout << "\n\n" << endl;

    addLast("Wibowo", "Informatika", 4444);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    removeLast();
    printSingleLinkedList();
    cout << "\n\n" << endl;

    changeFirst("Nopeliah", "Manajemen", 5555);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    addMiddle("Rizky", "Bahasa", 9999, 2);
    printSingleLinkedList();
    cout << "\n\n" << endl;
    
    addMiddle("Nugroho", "Eletro", 2089, 2);
    printSingleLinkedList();
    cout << "\n\n" << endl;

    return 0;

}