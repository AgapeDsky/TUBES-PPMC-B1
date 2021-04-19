/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa 20 April 2021
* Asisten (NIM) : Joshua Adi Chandra (18317032)
* Nama File : isValidKoor.h
* Deskripsi : header file untuk isValidKoor.c
*/

#include "math.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
    *Fungsi untuk mengecek apakah format latitude dan longitude valid.
    *Mengeluarkan output 1 bila valid dan 0 bila tidak valid
    
    *@param koor token koordinat

**/
int isValidKoor (char* koor);
