#include "validation_kota.h"

bool isalphabet(char c){
    return ((c >= 'a' && c <= 'z') || (c <= 'A' && c >= 'Z') || (&c == NULL));
}

bool isvalid(char* kota){
    for(int i=0; strlen(kota); i++){
        if(!isalphabet(kota[i])){
            return 0;
        }
    }
    return 1;
}
