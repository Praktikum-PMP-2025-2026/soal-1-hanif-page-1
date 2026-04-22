/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 2 - Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 13 April 2026
 *   Nama (NIM)          : 13224087
 *   Nama File           : soal1.c
 *   Deskripsi           : Kode ini merupakan solusi dari Praktikum EL2008, Modul 1, Soal 1, yaitu Mesin Analisis Pointer. Problem ini mengharuskan kode untuk menerima input jumlah data, lalu menerima sejumlah data sejumlah input jumlah data sebelumnya. Program mengharuskan membuat suatu fungsi yang menerima pointer dari array pertama, jumlah elemen, dan pointer output untuk sum, average, max, dan first index of max. Nilai keluaran adalah nilai sum, average, max, dan first index of max.
 */

#include <stdio.h>
#include <stdlib.h>

void runMainProcess(int *arrayFirstItem, int N, int *sum, float *average, int *max, int *firstIndexOfMax){
    int currentSum = 0;
    int currentMax = *arrayFirstItem;
    *firstIndexOfMax = 0;
    
    for(int i = 0; i < N; i++){
        currentSum += *(arrayFirstItem+i);

        if(*(arrayFirstItem+i) > currentMax){
            currentMax = *(arrayFirstItem+i);
            *firstIndexOfMax = i;
        }
    }

    *sum = currentSum;
    *average = (float)currentSum/N;
    *max = currentMax;
}

int main(void) {
    
    int N;

    scanf("%d", &N);

    int *arr = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    int sum, max, firstIndexOfMax;
    float average;

    runMainProcess(&arr[0], N, &sum, &average, &max, &firstIndexOfMax);

    printf("SUM %d\n", sum);
    printf("AVG %.2f\n", average);
    printf("MAX %d\n", max);
    printf("IDX %d\n", firstIndexOfMax);

    return 0;
 }

//  Used Source
// https://stackoverflow.com/questions/13530209/how-to-convert-int-to-float-in-c
 