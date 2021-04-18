/*
    Program Travelling Salesman Problem
    Kelompok : B1
    Nama Anggota ( NIM ) :
        Agape D'sky (13219010)
        .... isi

    Deskripsi Program :
    ................
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distance.h"               //Library untuk menghandle jarak 2 kota

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


/*
    main
*/
int main(){
    //Ekstraksi file input
    FILE* stream;                   //Variabel untuk file
    char namafile[1000];            //Nama file input
    char content[1000];             //Variabel isi file keseluruhan
    char* token;                     //Variabel token untuk isi file
    Data data[100];                 //Array penyimpan informasi

    //Buka file
    printf("Masukkan nama file input: ");
    scanf("%s", &namafile);
    stream = fopen(namafile, "r");

    //Periksa validitas file
    if (stream == NULL) {           //Kondisi kosong
        printf("file is empty!");
    }
    else {                          //Kondisi tidak kosong
        int i = 0;                  //Inisialisasi loop
        char* token_2;              //Variabel untuk validasi token
        int token_int;              //Variabel konversi token ke integer
        while(fgets(content, 1000, stream) != NULL) {
            //Ambil informasi nama kota
            token = strtok(content, ",");
            strcpy(data[i].kota, token);
            //Ambil informasi latitude
            token = strtok(NULL, ",");
            token_int = atoi(token);
            itoa(token_int, token_2, 10);
            if(!strcmp(token, token_2)) { //Periksa validitas latitude
                printf("Error: file invalid!");
                return 0;
            }
            data[i].latitude = token_int;
            //Ambil informasi longitude
            token = strtok(NULL, ",");
            token_int = atoi(token);
            itoa(token_int, token_2, 10);
            if(!strcmp(token, token_2)) { //Periksa validitas latitude
                printf("Error: file invalid!");
                return 0;
            }
            data[i].longitude = token_int;
            
            ++i;
        }
        
        /*
            File sudah kosong, seluruh informasi yang valid sudah masuk ke dalam array
            Array sudah bisa diproses untuk keperluan pengolahan data
        */

    }

    //Return value
    return 0;
}

