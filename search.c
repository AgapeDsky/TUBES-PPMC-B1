/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa 20 April 2021
* Asisten (NIM) : Joshua Adi Chandra (18317032)
* Nama File : search.c
* Deskripsi : modul untuk mencari lintasan dengan jarak terpendek
*/

#include "search.h"

double search (double mat[100][100], int* arr, int n, int start) {
    /*
        mat[100][100] : adjacency matrix dari kota-kota
        Ekspektasi isi Array : 0,1,2,3,...., n dengan n adalah vertice akhir 
        Ekspektasi n : jumlah kota
        Ekspektasi start = 0 (vertice 0 menjadi vertice awal)
    */
    //Kondisi tidak ada vertice selain vertice-0 lagi
    if (n == 1) {
        return mat[arr[0]][0];
    }
    //Kondisi kondisi ada 1 vertice selain vertice-0
    else if (n == 2) {
        int arr_new[1];
        if (arr[0] == start) {
            arr_new[0] = arr[1];
        }
        else {
            arr_new[0] = arr[0];
        }

        return (mat[start][arr_new[0]] + search(mat, arr_new, n-1, arr_new[0]));
    }
    //Kondisi rekurens
    else {
        int arr_new[n-1];
        int k = 0;
        //Cari elemen yang sama dalam array
        for (int i = 0; i<n; ++i) {
            if (start == arr[i]) {
                //do nothing
                //Elemen yang sama dari start akan dibuang
            }
            else {
                arr_new[k] = arr[i];
                ++k;
            }
        }
        //Cari nilai minimum dari masing-masing jalur
        double min = INT_MAX;
        for (int i = 0; i<n-1; ++i) {
            double temp = mat[start][arr_new[i]] + search(mat, arr_new, n-1, arr_new[i]);
            if (temp<min) {
                min = temp;
            }
        }
        return min;
    }

}
