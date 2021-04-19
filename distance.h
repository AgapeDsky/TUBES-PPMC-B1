/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa 20 April 2021
* Asisten (NIM) : Joshua Adi Chandra (18317032)
* Nama File : distance.h
* Deskripsi : header file untuk distance.c
*/

#include "math.h"

/**
    *Fungsi untuk menghitung jarak berdasarkan input latitude dan longitude
    *dari 2 buah titik. Mengeluarkan hasil jarak dalam tipe data double
    
    *@param lat1 latitude titik 1
    *@param lat2 latitude titik 2
    *@param long1 longitude tiitk 1
    *@param long2 longitude titik 2
**/
double distance (double lat1, double lat2, double long1, double long2);