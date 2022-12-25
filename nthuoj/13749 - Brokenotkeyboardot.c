#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char p[10];
char s[500];

// header.h
char **split_(char* str, char* pattern, int* split_num){
    char **result = malloc(sizeof(char *));
    char *tmp = str;
    int i = 0;

    while ((tmp = strstr(tmp, pattern))) {
        if (tmp - str > 0) {
            result[i] = strndup(str, tmp - str);
            i++;
            result = realloc(result, (i + 1) * sizeof(char *));
        }
        tmp += strlen(pattern);
        str = tmp;
    }

    result[i] = strdup(str);
    if (strlen(result[i]) == 0) {
        free(result[i]);
        i--;
    }

    *split_num = i + 1;
    return result;
}

void free_(char **result, int split_num) {
    for (int i = 0; i < split_num; i++)
      free(result[i]);
    free(result);
}

// main.c
int main(){
    int i, split_num;
    char **result;
    scanf("%s",s);
    scanf("%s",p);
    result = split_(s, p, &split_num);
    for(i=0; i<split_num; ++i) printf("%s\n",result[i]);
    free_(result, split_num);
    return 0;
}