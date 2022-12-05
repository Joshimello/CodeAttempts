#include <stdio.h>
#include <string.h>
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    char a[50][5000], b[50][5000];
  
    char ta[5000];
    scanf("%s", &ta);
    char * wa = strtok(ta, "/");
    int ia = 0;
    for(ia = 0; wa != NULL; ia++){
      strcpy(a[ia], wa);
      wa = strtok(NULL, "/");
    }
  
    char tb[5000];
    scanf("%s", &tb);
    char * wb = strtok(tb, "/");
    int ib = 0;
    for(ib = 0; wb != NULL; ib++){
      strcpy(b[ib], wb);
      wb = strtok(NULL, "/");
    }
  
    for(int i = 0; i < ib; i++){
      for(int j = 0; j < ia; j++)
        if(strcmp(b[i], a[j]) == 0) goto cont;
      printf("not valid\n");
      goto end;
      cont:;
    }
    printf("valid\n");
    end:;
  }
}