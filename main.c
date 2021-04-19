/*
    Program Travelling Salesman Problem
    Kelompok : B1
    Nama Anggota ( NIM ) :
        Nurhayati Marqoh Sirfefa (13217022)
        Agape D'sky (13219010)
        Richard (13219011)
        Faris Jabar Nugrahadi (13219020)
        Kelvin Angga Yumawan (13219025)

    Deskripsi Program :
    ................
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distance.h"               //Library untuk menghandle jarak 2 kota
#include "isValidKoor.h"            //Library memeriksa apakah data koordinat valid
#include "validation_kota.h"        //Library memeriksa apakah data kota valid
#include "search.h"                 //Library algoritma pencarian jalan
#include <time.h>                   //Untuk menghitung waktu yang digunakan program

/*
    Deklarasi struktur bentukan yang digunakan dalam program
*/
typedef struct Data {
    //Tipe bentukan untuk informasi kota
    //Berisi nama kota, latitude, dan longitude
    char kota[20];
    double latitude;
    double longitude;
} Data;

/*
    Deklarasi fungsi-fungsi yang digunakan dalam program
*/
void jarak_antarkota (double matrix[100][100], Data* data, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            matrix[i][j]= (distance(data[i].latitude, data[j].latitude, data[i].longitude, data[j].longitude));
        }
    }
}
/*
    main
*/
int main(){
    //Ekstraksi file input
    FILE* stream;                   //Variabel untuk file
    char namafile[1000];            //Nama file input
    char content[1000];             //Variabel isi file keseluruhan
    char* token;                    //Variabel token untuk isi file
    Data data[100];                 //Array penyimpan informasi
    int i = 0;                      //Penyimpan informasi panjang array

    //Input nama file
    printf("Masukkan nama file input: ");
    scanf("%s", &namafile);

    //Mulai hitung waktu eksekusi program
    clock_t t; t = clock();

    //Buka file
    stream = fopen(namafile, "r");

    //Periksa validitas file
    if (stream == NULL) {           //Kondisi kosong
        printf("file is empty!");
        return 0;
    }
    else {                               //Kondisi tidak kosong
        char* token_2;                   //Variabel untuk validasi token
        double token_float;              //Variabel konversi token ke integer
        while(fgets(content, 1000, stream) != NULL) {
            //Ambil informasi nama kota
            token = strtok(content, ",");
            //Validasi kota
            if(isvalid(token)) {
                return 0;
            }
            strcpy(data[i].kota, token);
            //Ambil informasi latitude
            token = strtok(NULL, ",");
            //Validasi latitude
            if (!isValidKoor(token)) {
                return 0;
            }
            token_float = atof(token);
            data[i].latitude = token_float;
            //Ambil informasi longitude
            token = strtok(NULL, "\n");
            //Validasi longitude
            if (!isValidKoor(token)) {
                return 0;
            }
            token_float = atof(token);
            data[i].longitude = token_float;
            
            ++i;
        }
        fclose(stream);
        /*
            File sudah kosong, seluruh informasi yang valid sudah masuk ke dalam array
            Array sudah bisa diproses untuk keperluan pengolahan data
        */

        //Membuat Adjacency Matrix
        double mat[100][100];           //matriks adjacency
        jarak_antarkota (mat, data, i); //Isi matriks dengan informasi distance
        int arr[i];                     //Matriks handler vertice
        for (int a = 0; a<i; ++a) {     //Pengisian matriks handler vertice dengan enumerasi
            arr[a] = a;
        }

        //Cari jarak tersingkat untuk melakukan perjalanan
        double result = search(mat, arr, i, 0);
        printf("Result = %lf\n", result);
    }
    
    //Hitung waktu yang sudah berjalan selama program
    t = clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time elapsed = %lf", time_taken);
    
    //Return value
    return 0;
}