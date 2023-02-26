#include <stdio.h>
#include <string.h>
int main(){
  int a[10][10000] = {};

  while(1){
    char cmd[10];
    scanf("%s", &cmd);

    if(!strcmp(cmd, "print")){
      for(int i = 0; i < 10; i++){
        printf("%d:", i);
        if(!a[i][0])
          printf(" No card");
        else
          for(int j = 0; a[i][j] != 0; j++)
            printf(" %d", a[i][j]);
        printf("\n");
      }
    }

    if(!strcmp(cmd, "all")){
      int x, y;
      scanf("%d %d", &x, &y);
      for(int i = 0; i < 10; i++)
        for(int j = 0; a[i][j] != 0; j++)
          a[i][j] = 0;
      for(int i = 0; i < 10; i++)
        for(int j = 0; j < y; j++)
          a[i][j] = x;
    }
    
    if(!strcmp(cmd, "place")){
      int x, y;
      scanf("%d %d", &x, &y);
      for(int i = 0; a[x][i] != 0; i++)
        a[x][i] = 0;
      for(int i = 0; i < y; i++){
        int t;
        scanf("%d", &t);
        a[x][i] = t;
      }
    }

    if(!strcmp(cmd, "swap")){
      int x, y, t[10000] = {};
      scanf("%d %d", &x, &y);
      for(int i = 0; a[x][i] != 0; i++)
        t[i] = a[x][i], a[x][i] = 0;
      for(int i = 0; a[y][i] != 0; i++)
        a[x][i] = a[y][i], a[y][i] = 0;
      for(int i = 0; t[i] != 0; i++)
        a[y][i] = t[i];
    }

    if(!strcmp(cmd, "clear")){
      for(int i = 0; i < 10; i++)
        for(int j = 0; a[i][j] != 0; j++)
          a[i][j] = 0;
    }

    if(!strcmp(cmd, "exit")){
      return 0;
    }

    if(!strcmp(cmd, "shiftleft")){
      int t[10000] = {};
      for(int i = 0; a[0][i] != 0; i++)
        t[i] = a[0][i], a[0][i] = 0;
      
      for(int i = 0; i < 9; i++)
        for(int j = 0; a[i+1][j] != 0; j++)
          a[i][j] = a[i+1][j], a[i+1][j] = 0;

      for(int i = 0; t[i] != 0; i++)
        a[9][i] = t[i];
    }

    if(!strcmp(cmd, "shiftright")){
      int t[10000] = {};
      for(int i = 0; a[9][i] != 0; i++)
        t[i] = a[9][i], a[9][i] = 0;
      
      for(int i = 9; i > 0; i--)
        for(int j = 0; a[i-1][j] != 0; j++)
          a[i][j] = a[i-1][j], a[i-1][j] = 0;

      for(int i = 0; t[i] != 0; i++)
        a[0][i] = t[i];
    }
  }
}