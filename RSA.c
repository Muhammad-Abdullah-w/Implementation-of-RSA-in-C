#include <stdio.h>
#include <math.h>
#include <string.h>
#include "RSA.h"

#include <gmp.h>
#include "fileopr.h"

void readNumber(int arr[], int size);

int main(){

    // Module RSA.h
    int modCo = 0;

    printf("Choose Module for Encryption\n1 For RSA: ");
    scanf("%d", &modCo);

    if (modCo == 1){
        printf("\t\tModule RSA.h\n");

        int keys[4];
        genKeys(65537, 5741, keys);

        int e = keys[0];
        int n = keys[1];
        int phin = keys[2];
        int d = keys[3];
        int dec;

        printKeys(e, n, phin, d);

        // change input size here if encrypting long messages
        char word[100];
        int enc[100];

        printf("Enter Text (For encryption): ");
        scanf("%*[\n]%[^\n]]*", word);

        // Encryption text can be seen in encrypted.txt file
        for (int i = 0; i < strlen(word); i++){
            enc[i] = powMod(word[i], e, n);
            printf("Encrypted: %d\n", enc[i]);
        }
        
        writeFile(enc, strlen(word));
        writeBinFile(enc, strlen(word));

        int data[100];
        readFile(data);

        printf("Decrypted: ");
        for (int i = 0; i < strlen(word); i++){
            dec = powMod(data[i], d, n);
            printf("%c", dec);
        }

        printf("\n");
    } else {
        printf("Wrong Input\n");
    }

    return 0;
}
