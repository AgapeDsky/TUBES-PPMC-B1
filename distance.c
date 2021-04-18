/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
* MODUL 9 – TUGAS BESAR
* Kelompok 			: B1
* Hari dan Tanggal 	:
* Asisten (NIM) 	: Joshua Adi Chandra (18317032)
* Nama File 		: distance.c
* Deskripsi 		:
*/

#include "distance.h"

double distance (double lat1, double lat2, double long1, double long2) {
    double res;

    //Konversi nilai ke dalam radian
    double lat1_rad = lat1*M_PI/(float)180; double lat2_rad = lat2*M_PI/(float)180;
    double long1_rad = long1*M_PI/(float)180; double long2_rad = long2*M_PI/(float)180;

    //Penghitungan
    res = 2*6371*asin(sqrt(     (sin(0.5*(lat2_rad-lat1_rad)))*(sin(0.5*(lat2_rad-lat1_rad)))
                                + 
                                cos(lat1_rad)*cos(lat2_rad)*(sin(0.5*(long2_rad-long1_rad)))*(sin(0.5*(long2_rad-long1_rad)))   ));
    
    //Return value
    return res;
}
