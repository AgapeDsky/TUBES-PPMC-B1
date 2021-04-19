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
