/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok 			: B1
* Hari dan Tanggal 	:
* Asisten (NIM) 	: Joshua Adi Chandra (18317032)
* Nama File 		: search.c
* Deskripsi 		:
*/

#include "search.h"
#include "limits.h"
#include <stdlib.h>

double search (double** mat, int* arr, int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return mat[arr[0]][arr[1]];
    }
    else{
        double min = INT_MAX;
        for (int i = 0; i<n ; ++i) {
            int* arr_new = (int*)malloc((n-1)*sizeof(int));
            int j = 0; int k = 0;
            while (j<n) {
                if (j == i) {
                    //do nothing
                }
                else {
                    arr_new[k] = j;
                    ++k; 
                }
                ++j;
            }
            if (search(mat, arr_new, n-1) < min) {
                min = search(mat, arr_new, n-1);
            }
        }
    }
}
