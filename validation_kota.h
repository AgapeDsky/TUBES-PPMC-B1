/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa 20 April 2021
* Asisten (NIM) : Joshua Adi Chandra (18317032)
* Nama File : validation_kota.h
* Deskripsi : header file dari validation_kota.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
    *Fungsi untuk mengecek apakah suatu character bagian dari alfabet
    *@param c karakter yang diperiksa
**/
bool isalphabet(char c);

/**
    *Fungsi untuk mengecek apakah suatu string nama kota valid
    *@param kota kata yang diperiksa
    *Nama kota valid berarti hanya terdiri atas alfabet dan spasi
**/
bool isvalid(char* kota);
