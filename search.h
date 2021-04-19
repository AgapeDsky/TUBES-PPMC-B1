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