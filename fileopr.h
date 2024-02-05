#include <stdio.h>
#include <gmp.h>

void writeBinFile(int data[], int size);
void readBinFile(int data[], int size);
void readFile(int data[]);
void writeFile(int data[], int size);
void readNumberFile(int arr[], int size);

void readNumberFile(int arr[], int size){
    FILE *myFile;
    myFile = fopen("temp.txt", "r");

    for (int i = 0; i < size; i++){
        fscanf(myFile, "%d", &arr[i]);
    }

    for (int i = 0; i < size; i++){
        printf("%c", arr[i]);
    }
    fclose(myFile);
}

void readFile(int data[]){
    FILE * fpointer;

    fpointer = fopen("encrypted.txt", "r");
    int i=0;
    int num;
    while(fscanf(fpointer, "%d", &num) > 0) {
        data[i] = num;
        i++;
    }
    fclose(fpointer);
}

void writeFile(int data[], int size){

    FILE * fpointer;
    fpointer = fopen("encrypted.txt", "w");
    
    for (int i = 0; i < size;i++){
        fprintf(fpointer, "%d\n",data[i]);
    }

    fclose(fpointer);
}

void writeBinFile(int data[], int size){

    FILE * fpointer;
    fpointer = fopen("encrypted.bin", "wb");

    for (int i = 0; i < size; i++){
        fwrite(&data[i], size, 1, fpointer);
    }
    fclose(fpointer);
}

void readBinFile(int data[], int size){
    
    FILE * fpointer;
    fpointer = fopen("encrypted.bin", "wr");

    int i = 0;
    int num;
    while (fread(&num, size, 1, fpointer)>0){
        data[i] = num;
        i++;
    }
    fclose(fpointer);
}


