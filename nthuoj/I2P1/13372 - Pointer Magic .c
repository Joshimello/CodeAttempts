#include<stdio.h>
#include <stdlib.h>

// header.h
void Swap(int* A, int* B){
  char a, b, t1, t2; int n, m;
  scanf(" %c %c %d %d", &a, &b, &n, &m);
  t1 = (a == 'A') ? A[n] : B[n];
  t2 = (b == 'A') ? A[m] : B[m];
  if(a == 'A') A[n] = t2; else B[n] = t2;
  if(b == 'A') A[m] = t1; else B[m] = t1;
}

void Replace(int* A, int* B){
  char a; int n, m;
  scanf(" %c %d %d", &a, &n, &m);
  if(a == 'A') A[n] = m; else B[n] = m;
}

void Switch(int** A, int** B){
  int *T = *A;
  *A = *B;
  *B = T;
}

// main.c
void PrintArrays(int *A, int *B, int size){
    for(int i = 0; i < size; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");

    for(int j = 0; j < size; j++){
        if(j != 0) printf(" ");
        printf("%d", B[j]);
    }
    printf("\n");
    return;
}

int main(){
    char str[10];
    int size;
    scanf("%d", &size);

    int *A = (int*)malloc(sizeof(int)*size);
    int *B = (int*)malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        int num;
        scanf("%d", &num);
        A[i] = num;
    }

    for(int j = 0; j < size; j++){
        int num;
        scanf("%d", &num);
        B[j] = num;
    }

    while(1){
        scanf("%s", str);
        if(str[2] == 'A') Swap(A, B);//Swap
        else if(str[2] == 'I') Switch(&A, &B);//Switch
        else if(str[2] == 'P') Replace(A, B);//Replace
        else if(str[2] == 'O') break;//Stop
    }

    PrintArrays(A, B, size);

    return 0;
}