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
        double token_float;              //Variabel konversi token ke integer
        while(fgets(content, 1000, stream) != NULL) {
            //Ambil informasi nama kota
            token = strtok(content, ",");
            strcpy(data[i].kota, token);
            //Ambil informasi latitude
            token = strtok(NULL, ",");
            token_float = atof(token);
            //Validasi latitude
            //...
            data[i].latitude = token_float;
            //Ambil informasi longitude
            token = strtok(NULL, "\n");
            token_float = atof(token);
            //Validasi longitude
            //...
            data[i].longitude = token_float;
            
            ++i;
        }
        fclose(stream);
        /*
            File sudah kosong, seluruh informasi yang valid sudah masuk ke dalam array
            Array sudah bisa diproses untuk keperluan pengolahan data
        */

    }
    //Return value
    return 0;
}
