#include <stdio.h>
int main(){
  int i, j, s, d, n;
  scanf("%d", &n);
	for (i = 0, s = 1; i < n; i++, s *= 3);
	for (i = 0; i < s; i++){
		for (j = 0; j < s; j++){
			for (d = s / 3; d > 0; d /= 3)
				if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1) break;
			printf(d ? "#" : ".");
		}
		printf("\n");
	}
}