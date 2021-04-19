/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa 20 April 2021
* Asisten (NIM) : Joshua Adi Chandra (18317032)
* Nama File : isValidKoor.c
* Deskripsi : modul untuk memeriksa validitas koordinat yang diinput
*/

#include "isValidKoor.h"

int isValidKoor(char* koor){
    const int length = strlen(koor); //panjang array of char
    int i = 1;
    int koma = 0; //menghitung banyaknya koma
    int invalid = 0; //menghitung banyak kesalahan

    //mengecek apakah karakter pertama valid atau tidak
    if(koor[0]=='-' || isdigit(koor[0])){
        invalid = 0;
    }
    else if(koor[0]=='.'){
        invalid = 0;
        koma++;
    }
    else{
        invalid = 1;
    }

    //mengecek apakah karakter kedua sampai habis valid atau tidak
    while(invalid==0 && koma < 2 && i<length){
        if(koor[i]=='.'){
            koma++;
        }
        if(koor[i]!='.' && !isdigit(koor[i])){
            invalid++;
        }
        i++;
    }

    if(invalid==0 && koma<2){
        return 1;
    }
    else{
        return 0;
    }
}
