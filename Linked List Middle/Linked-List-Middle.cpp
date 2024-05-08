#include <iostream>

using namespace std;

// deklarasi single linked list
struct Buku{

  // komponen / member
  string judul, pengarang;
  int tahunTerbit;

  Buku *next;

};

Buku *kepala, *ekor, *saat_ini, *node_baru, *hapus, *sebelum;

// create single linked list
void createSingleLinkedList(string judul, string pengarang, int tB){
  kepala = new Buku();
  kepala->judul = judul;
  kepala->pengarang = pengarang;
  kepala->tahunTerbit = tB;
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
void addFirst(string judul, string pengarang, int tB){
  node_baru = new Buku();
  node_baru->judul = judul;
  node_baru->pengarang = pengarang;
  node_baru->tahunTerbit = tB;
  node_baru->next = kepala;
  kepala = node_baru;
}

// tambahAkhir Single linked list
void addLast(string judul, string pengarang, int tB){
  node_baru = new Buku();
  node_baru->judul = judul;
  node_baru->pengarang = pengarang;
  node_baru->tahunTerbit = tB;
  node_baru->next = NULL;
  ekor->next = node_baru;
  ekor = node_baru;
}

// tambah tengah single linked list
void addMiddle(string judul, string pengarang, int tB, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    node_baru = new Buku();
    node_baru->judul = judul;
    node_baru->pengarang = pengarang;
    node_baru->tahunTerbit = tB;

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
void changeFirst(string judul, string pengarang, int tB){
  kepala->judul = judul;
  kepala->pengarang = pengarang;
  kepala->tahunTerbit = tB;
}

// ubahAkhir Single linked list
void changeLast(string judul, string pengarang, int tB){
  ekor->judul = judul;
  ekor->pengarang = pengarang;
  ekor->tahunTerbit = tB;
}

// ubah Tengah Single linked list
void changeMiddle(string judul, string pengarang, int tB, int posisi){
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
    saat_ini->judul = judul;
    saat_ini->pengarang = pengarang;
    saat_ini->tahunTerbit = tB;
  }
}

// print single linked list
void printSingleLinkedList(){
  cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
  saat_ini = kepala;
  while( saat_ini != NULL ){
    cout << "Judul Buku : " << saat_ini->judul << endl;
    cout << "Pengarang Buku : " << saat_ini->pengarang << endl;
    cout << "Tahun Terbit Buku : " << saat_ini->tahunTerbit << endl;

    saat_ini = saat_ini->next;
  }
}

int main(){

  createSingleLinkedList("Pusing", "Giska", 2003);

  printSingleLinkedList();

  cout << "\n\n" << endl;

  addFirst("Bapakku Adalah Aji", "Adil", 2004);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addLast("Aroma Bapakku", "Jimet", 2005);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  removeFirst();

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addLast("Terima", "Suroso", 2090);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  removeLast();

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  changeFirst("Berhentuy", "Gia Mubarak", 2056);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addMiddle("Bumi dan Kasur", "Prisitry", 2090, 2);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

  addMiddle("Negeri 500", "Ahmad Susanto", 2089, 2);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;

}