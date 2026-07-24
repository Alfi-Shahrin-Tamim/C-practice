#include <stdio.h>
#include <string.h>

int main(){
    int i,j, c1, c2, r1, r2, x;
    while(1){
         printf("Number of rows for first matrix: ");
         scanf("%d", &r1);
         printf("Number of columns for first matrix: ");
         scanf("%d", &c1);
         printf("Number of rows for second matrix: ");
         scanf("%d", &r2);
         if(r2 != c1) {
            printf("Column 1 and Row 2 must have same value for multiplication.\n");
            continue;
         }
         printf("Number of columns for second matrix: ");
         scanf("%d", &c2);
  
         int arr1[r1][c1], arr2[r2][c2];
         for(i = 0; i < r1; i++){
            for(j = 0; j < c1; j++){
                printf("Give value for A(%d,%d): ", i + 1, j + 1);
                scanf("%d", &arr1[i][j]);
            }
         }
         for(i = 0; i < r2; i++){
            for(j = 0; j < c2; j++){
                printf("Give value for B(%d,%d): ", i + 1, j + 1);
                scanf("%d", &arr2[i][j]);
            }
         }
         int arr3[r1][c2];
         memset(arr3, 0, sizeof(arr3));                  
         
         for(i = 0; i < r1;i++){
            for(j = 0; j < c2; j++){
                for(x = 0; x < c1; x ++){
                    arr3[i][j] += arr1[i][x] * arr2[x][j];
                }
            }
         }
         
         for(i = 0;i < r1; i++){
            for(j = 0;j < c2; j++){
                printf("%d ", arr3[i][j]);
            }
            printf("\n");
         }
    }
}
