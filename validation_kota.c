/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok          : B1
* Hari dan Tanggal 	:
* Asisten (NIM) 	: Joshua Adi Chandra (18317032)
* Nama File 		: validation_kota.c
* Deskripsi 		:
*/
#include "validation_kota.h"

bool isalphabet(char c){
    return ((c >= 'a' && c <= 'z') || (c <= 'A' && c >= 'Z') || (&c == NULL));
}

bool isvalid(char* kota){
    for(int i=0; strlen(kota); i++){
        if(!isalphabet(kota[i])){
            return 0;
        }
    }
    return 1;
}
