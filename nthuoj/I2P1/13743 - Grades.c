#include <stdio.h>

// header.h
#include <string.h>

typedef struct {
	int grade; 
	char* name;
} Student;

Student* Create_(int n){
	return (Student*)malloc(sizeof(Student) * n);
}

void SetVal_(Student* arr, int i, int num, char name[]){
  arr[i].grade = num;
  arr[i].name = strdup(name);
}

int Compare_(Student* arr, int id1, int id2){
  if(arr[id1].grade > arr[id2].grade) return 0;
  if(arr[id1].grade < arr[id2].grade) return 1;
  if(arr[id1].grade == arr[id2].grade) return strcmp(arr[id2].name, arr[id1].name);
}

void Swap_(Student* arr, int id1, int id2){
  Student t = arr[id1];
  arr[id1] = arr[id2];
  arr[id2] = t;
}

void Free_(Student* arr, int n){
  free(arr);
}

// main.c
int main() {
	int n; scanf("%d\n", &n);
	Student* arr = Create_(n);
	for(int i = 0; i < n; i++) {
		int num;
		char c[51];
		scanf("%d %s", &num, c);
		SetVal_(arr, i, num, c);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(Compare_(arr, i, j) > 0) {
				Swap_(arr, i, j);
			} 
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].grade, arr[i].name);
	}
	Free_(arr, n);
}
