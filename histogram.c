#include <stdio.h>
#include <string.h>

int main(){
    int n, i, j, unique, count;
    printf("Number of integers: ");
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n - 1; i++){
        for(j= 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    unique = 0;
    for (i = 0; i < n ; i++){
        for(j = i ;j < n; j++){
            if(arr[i] == arr[j]){
              i = j;  
            }
        }
        unique += 1;
    }
    int arr2[unique], k;
    k = 0;
    for (i = 0; i < n ; i++){
        arr2[k] = arr[i];
        k++;
        for(j = i ;j < n; j++){
            if(arr[i] == arr[j]){
              i = j ;  
            }
        }       
    } 
    int arr3[unique];
    memset(arr3, 0, sizeof(arr3));
    for (i = 0; i < unique ; i++){
        for(j = i;j < n; j++){
            if(arr2[i] == arr[j]){
                arr3[i] += 1;
            }
        }
    }
    for(i = 0; i < unique; i++){
        printf("%d: ", arr2[i]);
        for(j = 0; j < arr3[i]; j++) printf("*");
        printf("\n");
    }      


}
