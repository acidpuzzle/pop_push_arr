//
// Created by acidpuzzle on 6/27/22.
//
#include <stdio.h>

#define N 11

void printArray(const int* a) {
    for(int i = 0; i < N; ++i) {
        printf("%4d ", a[i]);
    }
    printf("\n");
}

void copyArray(const int* a1, int* a2) {
    for(int i = 0; i < N; ++i) {
        a2[i] = a1[i];
    }
}

void reverseCopyArray(const int* a1, int* a2) {
    for(int i = 0; i < N; ++i) {
        a2[N-i-1] = a1[i];
    }
}

void reverseArray(int* a) {
    for(int i = 0; i < N/2; ++i) {
        int tmp = a[i];
        a[i] = a[N-i-1];
        a[N-i-1] = tmp;
    }
}

void leftShiftArray(int* a) {
    int tmp = a[0];
    for(int i = 0; i < N-1; ++i) {
        a[i] = a[i+1];
    }
    a[N-1] = tmp;
}

void rightShiftArray(int* a) {
    int tmp = a[N-1];
    for(int i = N-1; i > 0; --i) {
        a[i] = a[i-1];
    }
    a[0] = tmp;
}

int main() {
    int a[N] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[N] = {0};

    printArray(a);
    rightShiftArray(a);
    rightShiftArray(a);
    rightShiftArray(a);
    printArray(a);

    return 0;
}