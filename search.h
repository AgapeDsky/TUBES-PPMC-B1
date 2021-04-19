/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa 20 April 2021
* Asisten (NIM) : Joshua Adi Chandra (18317032)
* Nama File : search.h
* Deskripsi : header file dari search.c
*/

#include "limits.h"
#include <stdlib.h>
#include <stdio.h>

/**
    *Fungsi untuk mencari jalur terbaik untuk bisa menghemat waktu
    *Merupakan algoritma untuk Travelling Salesman Problem
    
    *@param mat matriks yang berisi weight dari setiap edge
    *@param n jumlah vertice dalam masalah yang diberikan
    *@param arr matriks enumerasi dari data
    *@param start starting point dari algoritma (kota pertama)
**/
double search (double mat[100][100], int* arr, int n, int start);